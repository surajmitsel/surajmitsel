# SAN Communication: Initiator and Target

In a **Storage Area Network (SAN)**, communication happens between two main components:

- **Initiator:** The client or host (usually a server) that requests storage access.
- **Target:** The storage device or array that provides storage resources.

---

## How Initiator and Target Communicate: Step-by-Step

1. **Discovery:**  
   - The initiator discovers available targets on the SAN network.  
   - This can be done via protocols like **Fibre Channel (FC)** or **iSCSI**.

2. **Login/Session Establishment:**  
   - The initiator logs into the target to establish a session.  
   - Authentication may occur (e.g., CHAP for iSCSI).

3. **LUN Discovery:**  
   - The target presents a list of available **LUNs (Logical Unit Numbers)** to the initiator.  
   - LUNs represent logical storage volumes on the target.

4. **LUN Mapping:**  
   - The storage administrator maps LUNs to specific initiators or groups of initiators.  
   - This controls which servers can access which storage volumes.

5. **I/O Operations:**  
   - The initiator sends SCSI commands (read/write) encapsulated in the SAN protocol to the target.  
   - The target processes these commands and accesses the physical storage.

6. **Data Transfer:**  
   - Data is transferred between initiator and target over the SAN fabric (Fibre Channel or IP network).

7. **Session Termination:**  
   - When done, the initiator logs out and closes the session.

---

## What is a LUN in SAN?

- **LUN (Logical Unit Number)** is a unique identifier for a logical storage volume on a SAN target.  
- It represents a portion of the physical storage (like a partition or volume) that the initiator can access.  
- LUNs allow the storage system to present multiple separate storage volumes to different hosts.

---

## How Are LUNs Mapped for Communication?

- **LUN Mapping** is the process of assigning LUNs to specific initiators or host groups.  
- This is done on the storage array or SAN controller.  
- Mapping ensures that only authorized servers can see and access certain LUNs.  
- It provides **access control** and **security** in SAN environments.

---

## Summary Table

| Term          | Explanation                                      |
|---------------|-------------------------------------------------|
| **Initiator** | The client/server requesting storage access.    |
| **Target**    | The storage device providing storage resources. |
| **LUN**       | Logical storage volume identified by a number.  |
| **LUN Mapping** | Assigning LUNs to initiators to control access. |

---

## Example Flow

1. Server (initiator) discovers storage array (target).  
2. Server logs into the storage array.  
3. Storage array presents LUNs to the server.  
4. Storage admin maps LUN 10 to Server A.  
5. Server A sends read/write commands to LUN 10.  
6. Storage array processes commands and returns data.  

---

# SAN Communication Diagram

```plaintext
+------------------+                     +---------------------+
|     Initiator    |                     |       Target        |
|  (Server/Host)   |                     | (Storage Array/ SAN)|
|                  |                     |                     |
|  - Sends SCSI    | <---- SAN Fabric -->|  - Presents LUNs    |
|    commands      |                     |  - Maps LUNs to     |
|  - Reads/Writes  |                     |    initiators       |
+------------------+                     +---------------------+
```
