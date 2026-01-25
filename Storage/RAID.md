# RAID Levels Summary

RAID (Redundant Array of Independent Disks) is a method of combining multiple physical disks into one logical unit to improve performance, data protection, or both. Different RAID levels define how data and parity are distributed across disks.

---

## Common RAID Levels

| RAID Level | Description                                   | Benefits                         | Drawbacks                      | Minimum Disks Required |
|------------|-----------------------------------------------|---------------------------------|-------------------------------|-----------------------|
| **RAID 0** | Data striped across disks (no redundancy)     | High performance, full capacity  | No fault tolerance (data lost if one disk fails) | 2                     |
| **RAID 1** | Mirroring (duplicate data on two disks)       | High redundancy, simple recovery | Uses 50% capacity (two disks store same data)     | 2                     |
| **RAID 5** | Striping with distributed parity (block-level) | Good balance of performance and redundancy | Can tolerate 1 disk failure, slower writes due to parity calculation | 3                     |
| **RAID 6** | Like RAID 5 but with double parity             | Can tolerate 2 disk failures     | More overhead than RAID 5, slower writes          | 4                     |
| **RAID 10**| Combination of RAID 1 and 0 (mirrored stripes) | High performance and redundancy | Requires at least 4 disks, 50% capacity usable    | 4                     |

---

## Less Common RAID Levels

| RAID Level | Description                                   | Usage Today                     | Reason for Limited Use        | Minimum Disks Required |
|------------|-----------------------------------------------|---------------------------------|------------------------------|-----------------------|
| **RAID 2** | Bit-level striping with Hamming code error correction | Almost never used               | Complex, requires synchronized disks | Multiple (usually 3+)  |
| **RAID 3** | Byte-level striping with dedicated parity disk | Rarely used                    | Parity disk bottleneck        | 3                     |
| **RAID 4** | Block-level striping with dedicated parity disk | Rarely used                    | Parity disk bottleneck, replaced by RAID 5 | 3                     |

---

## How to Choose a RAID Level?

- **Performance Needs:**  
  - RAID 0 for speed (no redundancy).  
  - RAID 10 for high performance with redundancy.

- **Data Protection:**  
  - RAID 1, RAID 6, or RAID 10 for fault tolerance.  
  - RAID 6 protects against two disk failures.

- **Capacity Efficiency:**  
  - RAID 0 and RAID 5 use disk space efficiently.  
  - RAID 1 and RAID 10 use more disks for redundancy.

- **Number of Disks Available:**  
  - RAID 5 requires at least 3 disks.  
  - RAID 6 requires at least 4 disks.

- **Workload Type:**  
  - Write-heavy workloads benefit from RAID 10.  
  - Read-heavy workloads can use RAID 5 or RAID 6.

---

## RAID Application Layer

- RAID is applied at the **storage layer**, either:  
  - **Hardware RAID:** Inside storage arrays or RAID controllers.  
  - **Software RAID:** Inside operating systems or hypervisors.

---

# Summary Table

| RAID Level | Fault Tolerance | Performance | Capacity Efficiency | Typical Use Case               |
|------------|-----------------|-------------|---------------------|-------------------------------|
| RAID 0     | None            | High        | 100%                | Temporary data, scratch disks |
| RAID 1     | 1 disk          | Moderate    | 50%                 | Critical data, OS drives       |
| RAID 5     | 1 disk          | Good        | (N-1)/N             | General purpose storage        |
| RAID 6     | 2 disks         | Moderate    | (N-2)/N             | High availability storage      |
| RAID 10    | 1 disk per mirror| High        | 50%                 | Databases, high I/O workloads  |

---

If you want, I can provide detailed examples or diagrams for any RAID level!