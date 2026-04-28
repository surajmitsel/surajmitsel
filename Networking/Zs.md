# Zscaler Internet Access (ZIA) Architecture & Forwarding Overview

This document summarizes the high-level components and traffic forwarding methods used by the Zscaler cloud.

---

## 1. High-Level Components (The Three Planes)
Zscaler uses a multi-tenant, distributed architecture that separates management, data processing, and logging.


| Component | Plane | Function |
| :--- | :--- | :--- |
| **Central Authority (CA)** | **Control Plane** | The "brain." Manages user identities, policy configs, and global threat intelligence. |
| **Public Service Edge (PSE)** | **Data Plane** | The "muscle." Real-time gateways that inspect traffic, enforce policies, and block threats in memory. |
| **Nanolog Clusters** | **Logging Plane** | The "memory." Specialized storage that compresses and stores metadata for reporting and forensics. |

---

## 2. Traffic Forwarding Methods
ZIA provides multiple ways to route traffic to the cloud depending on the user's location and device type.

### A. Zscaler Client Connector (ZCC)
*   **Target:** Windows, macOS, Linux, iOS, Android.
*   **Method:** A lightweight agent that creates a secure tunnel (Z-Tunnel 1.0 or 2.0) to the nearest PSE.
*   **Benefit:** Provides per-user/per-device visibility even when users are off-network (home/cafe).

### B. Network Tunneling (GRE or IPsec)
*   **Target:** Branch offices and Headquarters.
*   **GRE:** Highest performance (up to 1 Gbps), lowest overhead. Requires static IP.
*   **IPsec:** Securely connects sites with dynamic IPs or routers that don't support GRE.
*   **Redundancy:** Standard practice involves a Primary and Secondary tunnel to different Zscaler data centers.

### C. PAC Files (Proxy Auto-Configuration)
*   **Target:** Browsers, legacy servers, and IoT devices.
*   **Method:** JavaScript-based routing that tells applications which proxy to use.
*   **Variables:** Uses `${GATEWAY}` and `${SECONDARY_GATEWAY}` to dynamically find the closest PSE.

### D. Specialized Connectors
*   **Cloud Connector:** Secures workloads in AWS/Azure.
*   **Branch Connector:** A virtual appliance for simplified branch office connectivity.

---

## 3. Best Practice Summary Table


| Scenario | Recommended Method | Reason |
| :--- | :--- | :--- |
| **Headquarters** | GRE + ZCC + PAC | Max throughput + granular user visibility. |
| **Remote Workers** | ZCC Only | Consistent security anywhere in the world. |
| **Branch Offices** | IPsec / SD-WAN | Easy to manage with existing networking gear. |
| **Legacy Servers** | PAC File | Secure traffic for devices that can't run ZCC. |

---
