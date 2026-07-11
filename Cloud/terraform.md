## Terraform
- Terraform is an open-source Infrastructure as Code (IaC) tool developed by HashiCorp. It allows developers and DevOps teams to automate the provisioning, management, and scaling of cloud infrastructure using human-readable configuration files instead of manual clicks in a web console. 
- Terraform is cloud-agnostic, meaning you can use a single tool to manage resources across different providers like Amazon Web Services (AWS), Microsoft Azure, Google Cloud Platform (GCP), and Kubernetes. 
How Terraform Works 
- Terraform relies on a declarative approach. This means you do not write step-by-step instructions on how to build a server. Instead, you write down the final end state you want. Terraform automatically calculates the dependencies, figures out the order of operations, and handles the actual setup.  

### The 3 Core Pillars of Terraform 
1. HashiCorp Configuration Language (HCL): The easy-to-read syntax used to write your infrastructure files (ending in ). 
2. Providers: Plugins that connect Terraform to specific cloud platforms via their APIs. There are thousands of official Terraform Providers available for everything from AWS to GitHub. 
3. State File (): A JSON database file where Terraform stores a map of your real-world infrastructure. It serves as the single source of truth to check if your actual cloud matches your code. 

### The Standard Terraform Workflow 
Deploying infrastructure with Terraform always follows the same standard cycle: 

```code
[ 1. Write Code ] ──> [ 2. Init Project ] ──> [ 3. Plan Changes ] ──> [ 4. Apply State ]
```

1. Write: You define your resources in a  file using HCL. For example, you specify that you want a Virtual Private Cloud (VPC) and three virtual machine instances. 
2. Initialize (): You run this command in your terminal to initialize the directory. Terraform reads your code and downloads the necessary provider plugins. 
3. Plan (): This executes a dry run. Terraform reviews your cloud environment, compares it to your file, and generates a blueprint showing exactly what it will add, modify, or delete. 
4. Apply (): Upon your approval, Terraform makes the required API calls to your cloud provider and builds the infrastructure.  

### Why Use Terraform? 

• Consistency: Eliminates human error by making sure environments (development, staging, production) are identical replicas. 
• Version Control: Because infrastructure is written as code, you can track every change using Git, review code before deploying it, and roll back if things break. 
• Reusability: You can bundle repeating blocks of infrastructure into packages called Terraform Modules. This lets you redeploy complex application environments with minor input changes. 
• Drift Detection: If someone manually messes up a cloud setting via the web UI, running Terraform will immediately catch the mistake and fix it back to your code standard.  



