## Terraform
- Terraform is an open-source Infrastructure as Code (IaC) tool created by HashiCorp that allows DevOps teams to define, provision, and version cloud and on-premises resources using a declarative configuration language.
- Instead of manually clicking through cloud consoles or writing fragile bash scripts, you write human-readable code describing your target environment. Terraform calculates the dependencies and builds it for you automatically.
------------------------------
## Core Terraform Use Cases

* `Multi-Cloud Deployments`: Deploying and managing components spread across [Amazon Web Services (AWS)](https://aws.amazon.com/), [Google Cloud (GCP)](https://cloud.google.com/), and [Microsoft Azure](https://azure.microsoft.com/) using a unified workflow. 
* `Environment Replication`: Creating identical, repeatable environments for Development, Staging, and Production to eliminate the "works on my machine" problem.
* `Self-Service Clusters`: Enabling software engineering teams to safely spin up pre-approved infrastructure templates on demand.
* `Automated CI/CD Workflows`: Committing your infrastructure code to GitHub/GitLab, and letting automation software review, plan, and apply the infrastructure updates.

------------------------------
## Deploying a NetApp Storage Cluster in AWS using HCL
When deploying enterprise NetApp storage on AWS, there are two common approaches:

   1. Using Amazon FSx for NetApp ONTAP (a native, fully managed AWS service) via the hashicorp/aws provider.
   2. Using NetApp's self-managed Cloud Volumes ONTAP (CVO) via the NetApp/netapp-cloudmanager provider.

Below is an HCL example implementing the Amazon FSx for NetApp ONTAP approach, which deploys a high-availability clustered storage environment.

## 1. Define Providers and Versions (providers.tf)
This block registers the official AWS provider and locks the version for stability.
```code
terraform {
  required_version = ">= 1.5.0"
  required_providers {
    aws = {
      source  = "hashicorp/aws"
      version = "~> 5.0"
    }
  }
}


provider "aws" {
  region = "us-east-1" # The AWS deployment region
}
```

## 2. Deploy the NetApp ONTAP Clustered File System (main.tf)
This block provisions the actual NetApp cluster across multi-AZ setups. It connects to your existing network infrastructure (VPC and Subnets). 
```code
# 1. Create the base clustered storage system

resource "aws_fsx_ontap_file_system" "netapp_cluster" {
  storage_capacity    = 1024 # Capacity in GiB
  subnet_ids          = ["subnet-0123456789abcdef0", "subnet-abcdef0123456789a"] # Preferred and Standby Subnets for HA
  deployment_type     = "MULTI_AZ_1"
  throughput_capacity = 128 # Throughput speed in MB/s
  preferred_subnet_id = "subnet-0123456789abcdef0"
  
  # Admin credentials for managing ONTAP nodes
  automatic_backup_retention_days = 7
  fsx_admin_password              = "SuperSecurePassword123!"

  tags = {
    Environment = "Production"
    Name        = "netapp-storage-cluster"
  }
}

# 2. Create a Storage Virtual Machine (SVM) inside the cluster

resource "aws_fsx_ontap_storage_virtual_machine" "netapp_svm" {
  file_system_id = aws_fsx_ontap_file_system.netapp_cluster.id
  name           = "production-svm"
  
  # Associates an admin password specific to this SVM partition
  svm_admin_password = "SVMSecurePassword123!"
}

# 3. Provision a data volume inside the SVM for clients to mount

resource "aws_fsx_ontap_volume" "netapp_volume" {
  name                       = "marketing_data"
  junction_path              = "/marketing"
  size_in_megabytes          = 102400 # 100 GB volume
  storage_virtual_machine_id = aws_fsx_ontap_storage_virtual_machine.netapp_svm.id
  
  ontap_volume_type = "RW" # Read-Write Volume
  tiering_policy {
    name           = "AUTO" # Automatically move cold data to lower-cost S3 pools
    cooling_period = 31
  }
}
```
## 3. Capture Important Details (outputs.tf)
Once applied, you need to know where your client machines (like EC2 instances) can mount the file system via NFS or SMB protocols.
```code
output "netapp_cluster_management_endpoint" {
  value       = aws_fsx_ontap_file_system.netapp_cluster.endpoints[0].management[0].dns_name
  description = "The DNS name used to manage the NetApp Cluster via ONTAP CLI or System Manager."
}

output "netapp_nfs_mount_ip" {
  value       = aws_fsx_ontap_storage_virtual_machine.netapp_svm.endpoints[0].nfs[0].ip_addresses
  description = "The target IP address to mount this NFS volume onto Linux instances."
}
```

------------------------------
## Step-by-Step Execution Lifecycle
To run this HCL code against your AWS environment, you run four standard terminal commands:

   1. aws configure: Setup your local session with appropriate AWS access keys.
   2. terraform init: Reads the code and fetches the compiled AWS provider plugin binary from the internet registry.
   3. terraform plan: Evaluates the network conditions and creates a blueprint showing exactly what it will provision.
   4. terraform apply: Calls the AWS API, establishes the cluster, initializes the internal virtual machines, segments the volume, and returns your final mountable IPs. 

Would you like to know how to connect an EC2 Linux instance to this newly deployed NetApp volume using HCL, or would you like to see how to use the native NetApp BlueXP provider instead? 
