# iSCSI Protocol Design: End-to-End Overview

## 1. Components of iSCSI

### Initiator
- **Description:** The iSCSI initiator is a client device (usually a server) that sends SCSI commands to storage devices over an IP network.
- **Types:** Software initiators (implemented in the operating system) and hardware initiators (dedicated iSCSI HBAs).

### Target
- **Description:** The iSCSI target is a storage device (such as a disk array) that receives and processes SCSI commands from the initiator.
- **Types:** Physical storage devices or software-based targets running on a server.

### Network
- **Description:** The IP network that connects initiators and targets. This can be a local area network (LAN) or a wide area network (WAN).
- **Components:** Ethernet switches, routers, and network interface cards (NICs).

## 2. iSCSI Protocol Stack

iSCSI operates on top of the TCP/IP stack, encapsulating SCSI commands into TCP packets for transmission over IP networks.

- **Application Layer (Layer 7):** iSCSI protocol.
- **Transport Layer (Layer 4):** TCP (Transmission Control Protocol).
- **Network Layer (Layer 3):** IP (Internet Protocol).
- **Data Link Layer (Layer 2):** Ethernet.
- **Physical Layer (Layer 1):** Physical network infrastructure (cables, switches, NICs).

## 3. iSCSI Session and Connection

### Session
- **Description:** An iSCSI session is established between an initiator and a target. It consists of one or more connections.
- **Identifiers:** Each session is identified by a unique session identifier (ISID).

### Connection
- **Description:** A connection is a TCP/IP connection between an initiator and a target within a session.
- **Identifiers:** Each connection is identified by a connection identifier (CID).

## 4. iSCSI Frame Format

An iSCSI frame, also known as an iSCSI Protocol Data Unit (PDU), encapsulates SCSI commands, data, and status information. The basic structure of an iSCSI PDU includes:

- **Basic Header Segment (BHS):** 48 bytes
  - **Opcode:** 1 byte (indicates the type of PDU, e.g., command, data, response).
  - **Flags:** 1 byte (various control flags).
  - **TotalAHSLength:** 1 byte (length of the Additional Header Segment).
  - **DataSegmentLength:** 3 bytes (length of the data segment).
  - **LUN:** 8 bytes (Logical Unit Number).
  - **InitiatorTaskTag:** 4 bytes (unique identifier for the task).
  - **Other fields:** Various fields depending on the PDU type.

- **Additional Header Segment (AHS):** Variable length (optional, used for extended headers).
- **Data Segment:** Variable length (contains the actual SCSI command, data, or status information).

## 5. iSCSI Commands

iSCSI commands are encapsulated within PDUs and include various types of operations. Some common iSCSI commands are:

### SCSI Command (0x01)
- **Description:** Encapsulates a SCSI command to be sent from the initiator to the target.
- **Fields:** Opcode, flags, LUN, task tag, command descriptor block (CDB), etc.

### SCSI Data-Out (0x05)
- **Description:** Sends data from the initiator to the target.
- **Fields:** Opcode, flags, LUN, task tag, data segment, etc.

### SCSI Data-In (0x06)
- **Description:** Sends data from the target to the initiator.
- **Fields:** Opcode, flags, LUN, task tag, data segment, etc.

### SCSI Response (0x03)
- **Description:** Sends a response from the target to the initiator, indicating the status of a SCSI command.
- **Fields:** Opcode, flags, LUN, task tag, status, etc.

### Login Request (0x03)
- **Description:** Initiates an iSCSI session between an initiator and a target.
- **Fields:** Opcode, flags, ISID, CID, etc.

### Login Response (0x23)
- **Description:** Responds to a login request, establishing an iSCSI session.
- **Fields:** Opcode, flags, ISID, CID, status, etc.

## Summary

iSCSI is a protocol that encapsulates SCSI commands into TCP packets for transmission over IP networks, enabling the creation of SANs using existing Ethernet infrastructure. The key components of iSCSI include initiators, targets, and the IP network. iSCSI operates on top of the TCP/IP stack and uses PDUs to encapsulate commands, data, and status information. Common iSCSI commands include SCSI Command, SCSI Data-Out, SCSI Data-In, SCSI Response, Login Request, and Login Response.