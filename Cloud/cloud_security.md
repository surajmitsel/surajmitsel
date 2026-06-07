# Core Cloud Security Features

Major cloud providers (AWS, Azure, Google Cloud) utilize a **Shared Responsibility Model** to secure data and infrastructure. Below are the primary security features they implement.

### 1. Identity and Access Management (IAM)
*   **Granular Access Control:** Define specific roles and permissions to ensure the "principle of least privilege."
*   **Multi-Factor Authentication (MFA):** Requires extra verification (codes, biometrics) beyond just a password.
*   **Single Sign-On (SSO):** Securely manage one set of credentials for multiple cloud applications.

### 2. Data Protection & Encryption
*   **Encryption at Rest:** Protects stored data (disks, databases) using algorithms like AES-256.
*   **Encryption in Transit:** Secures data moving between users and the cloud using TLS/SSL protocols.
*   **Key Management Services (KMS):** Tools to create, rotate, and control the cryptographic keys used for encryption.

### 3. Network Security
*   **Virtual Private Clouds (VPC):** Creates logically isolated network sections to host private resources.
*   **Cloud-Native Firewalls:** Built-in tools (like Security Groups) to filter incoming and outgoing traffic.
*   **DDoS Protection:** Automated mitigation systems to prevent service disruptions from large-scale attacks.

### 4. Threat Detection & Monitoring
*   **Continuous Logging:** Records all API calls and account activity for auditing (e.g., AWS CloudTrail).
*   **Intrusion Detection/Prevention (IDS/IPS):** Uses AI to scan for suspicious activity or known malware patterns in real-time.

### 5. Compliance and Governance
*   **Cloud Security Posture Management (CSPM):** Automated scanning to find and fix security misconfigurations.
*   **Compliance Frameworks:** Pre-built templates to help meet regulatory standards like HIPAA, GDPR, or PCI-DSS.
