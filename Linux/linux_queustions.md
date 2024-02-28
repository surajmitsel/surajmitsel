## Linux Queustions
https://www.geeksforgeeks.org/linux-interview-questions/

### Hard link vs soft link
The primary difference between these links is that a hard link directly references the file. In contrast, a soft link is a name-based reference to a file.

- `Hard Link:`A hard link is an additional name for the original file that references to the target file through inode.
A hard link remains valid even if the target file is deleted. 
- `Soft Link or Symbolic links:` It is different from the original file and is an alternative for it, but it does not use inode. Soft link becomes invalid when the originating file is deleted 
![](image/linux_hard_soft.png)

### create soft link
Symbolic links, symlink, or soft links are shortcuts to files and directories. Users can create the symbolic link in Linux through the’ ln’ command. The general command to create a symbolic link is as follows:

`ln -s <existing_source file> <optional_symbolic link>`


### LILO
LILO, i.e., Linux Loader and is a Linux Boot loader. It loads the Linux operating system into memory and starts the execution. Most operating systems like Windows and macOS come with a bootloader. While in Linux, you need to install a separate boot loader, and LILO is one of the Linux boot loaders.
- It can boot operating systems from floppy disks, hard disks, and it does not depend on a specific file system. 
- Lilo handles some tasks such as locate the kernel, identify other supporting programs, load memory and starts the kernel. - The configuration file of lilo is located at “/etc/lilo.conf”. Lilo reads this configuration file and it tells Lilo where it should place the bootloader.

### GRUB VS LILO

1) Lilo stands for Linux Loader and GRUB stands for Grand Unified Bootloader.

2) LILO has no interactive command interface, whereas GRUB has a more powerful command interface.

3) LILO does not support booting from a network, whereas GRUB does.

4) GRUB is a boot loader which can be used in Linux, DOS, and other operating systems whereas Lilo is a boot loader for Linux.

5) Lilo has a simpler interface so it is easy to use whereas GRUB is more complicated to use.

6) Lilo is the old default bootloader and GRUB is the new default boot loader.

### Linux shell
In Linux, five Shells are used:

- `csh (C Shell)`: This shell offers job control and spell checking and is similar to C syntax.
- `ksh (Korn Shell)`: A high-level shell for programmi  ng languages.
- `ssh (Z Shell)`: This shell has a unique nature, such as closing comments, startup files, file name generating, and observing logout/login watching.
- `bash (Bourne Again Shell)`: This is the default shell for Linux.
- `Fish (Friendly Interactive Shell)`: This shell provides auto-suggestion, web-based configuration, etc.

### Linux Inodes
- The inode (index node) is a data structure in a Unix-style file system that describes a file-system object such as a file or a directory. 
- An Inode number is a uniquely existing number for all the files in Linux and all Unix type systems.
- When a file is created on a system, a file name and Inode number is assigned to it.
- Generally, to access a file, a user uses the file name but internally file name is first mapped with respective Inode number stored in a table.
- Inode doesn't contain the file name. Reason for this is to maintain hard-links for the files. When all the other information is separated from the file name then only we can have various file names pointing to the same Inode.

### Linux process 
In Linux, there are mainly three common kinds of processes which are as follows:

- Batch : The batch process is submitted through a processes queue and is not related to the command line. These processes are well suited to perform recurring operations if the usage of the system is low.
- Interactive: The interactive process is interactively executed by the user on the command line.
- Daemon: The daemon is identified by a system like those processes whose parent process contains a PID of one.

### Inode Contents
An Inode is a data structure containing metadata about the files.

Following contents are stored in the Inode from a file:

- User ID of file
- Group ID of file
- Device ID
- File size
- Date of creation
- Permission
- Owner of the file
- File protection flag
- Link counter to determine number of hard links

![](image/linux_inode.png)

### Difference between a process and a daemon in Linux
- A process is an executing instance of a program. It can be a foreground process that interacts with the user or a background process started by a user or another process.
- A daemon is a background process that runs independently of user sessions. It is typically started at system boot time and performs system tasks or provides services. Daemons often have no user interaction and continue running even when users log out.

### Zombie process
- https://www.tutorialspoint.com/what-is-zombie-process-in-linux
- https://www.geeksforgeeks.org/zombie-processes-prevention/
- https://www.javatpoint.com/what-is-zombie-process
- A zombie process is a process whose execution is completed but it still has an entry in the process table. 
- Zombie processes usually occur for child processes, as the parent process still needs to read its child’s exit status. Once this is done using the `wait` system call, the zombie process is eliminated from the process table. This is known as reaping the zombie process.
![](image/linux_zombie.png)

### Orphan Process
- Zombie processes should not be confused with orphan processes. An orphan process is a process that is still executing, but whose parent has died. When the parent dies, the orphaned child process is adopted by init (process ID 1). 
- When orphan processes die, they do not remain as zombie processes; instead, they are waited on by init. The result is that a process that is both a zombie and an orphan will be reaped automatically.

### Daemon Process
- A daemon process is a background process that is not under the direct control of the user. This process is usually started when the system is bootstrapped and it terminated with the system shut down.

- Usually the parent process of the daemon process is the init process. This is because the init process usually adopts the daemon process after the parent process forks the daemon process and terminates.

- `int becomeDeamon(int flags)` that perfoms the seteps in order to turn the caller process into a deamon.

- `service --status-all` OR `systemctl | grep daemon`command can list all running deamon process in system. 

The daemon process names normally end with a d. Some of the examples of daemon processes in Unix are −

- `crond`
This is a job scheduler that runs jobs in the background.

- `syslogd`
This is the system logger that implements the system logging facility and collects system messages.

- `httpd`
This is the web server daemon process that handles the Hypertext Transfer Protocol.

- `dhcpd`
This daemon configures the TCP/IP information for users dynamically.


#### advantage of IPv6 over ipV4

IPv6 offers several advantages over IPv4, addressing many limitations of the older protocol. Some key advantages of IPv6 include:
- `less size of routing table`: The IPv6 sender may perform fragmentation at source because an IPv6 router cannot perform a fragmentation, so if packet is too large for next hop, router will generate an ICMP packet to let the source know that packet is too large in size

- `Larger Address Space:` IPv6 uses 128-bit addresses compared to the 32-bit addresses used by IPv4. This significantly increases the address space, allowing for an almost unlimited number of unique addresses. With IPv6, the address space is large enough to accommodate the growing number of internet-connected devices.

- `Address Autoconfiguration`: IPv6 includes built-in support for stateless address autoconfiguration (SLAAC) and DHCPv6, simplifying the process of assigning and configuring IP addresses. Devices can automatically generate their IPv6 addresses based on the network prefix, reducing the need for manual configuration.

- `Efficient Routing and Addressing`: IPv6 simplifies routing and reduces the size of routing tables compared to IPv4. The hierarchical addressing structure of IPv6 allows for more efficient routing and aggregation of prefixes, improving scalability and reducing routing overhead.

- `Enhanced Security`: IPv6 includes built-in support for IPsec (Internet Protocol Security), providing end-to-end encryption, authentication, and integrity protection for network communications. IPsec is optional in IPv4 but mandatory in IPv6, enhancing security for internet traffic.

- `Improved Quality of Service (QoS)`: IPv6 includes support for flow labeling, allowing packets belonging to specific traffic flows to be identified and treated differently based on QoS policies. This enables better traffic management, prioritization, and quality of service for different types of traffic.

- `Simplified Network Management`: IPv6 simplifies network management by eliminating the need for features like Network Address Translation (NAT) used in IPv4 to conserve address space. With IPv6, each device can have a globally unique address, making it easier to manage and troubleshoot network configurations.

- `Future-Proofing`: As the successor to IPv4, IPv6 is designed to meet the long-term addressing needs of the internet. By adopting IPv6, organizations can future-proof their networks and ensure scalability and compatibility with emerging technologies and services.

Overall, IPv6 offers numerous advantages over IPv4, including a larger address space, simplified network management, enhanced security, and improved support for modern networking requirements. As the adoption of IPv6 continues to grow, it will play a crucial role in enabling the continued growth and evolution of the internet.


#### does ipv6 uses NAT table

- IPv6 (Internet Protocol version 6) does not use Network Address Translation (NAT) tables in the same way as IPv4. NAT is primarily used in IPv4 networks to map private IP addresses to public IP addresses to allow devices within a private network to communicate with devices outside the network.

- IPv6, on the other hand, has a significantly larger address space than IPv4, which eliminates the need for NAT in most cases. With IPv6, every device can have a globally unique address, allowing for end-to-end connectivity without the need for address translation.

- However, there are scenarios where NAT-like functionality may still be required in IPv6 networks, such as in cases where a network administrator wants to hide the internal topology of a network or to conserve address space. In such cases, techniques such as Network Prefix Translation (`NPT`) or Port Address Translation (`PAT`) can be used, but they are not as widely used as in IPv4 networks.

Overall, while IPv6 does not rely on NAT tables in the same way as IPv4, there are alternative mechanisms and techniques available to achieve similar goals if necessary.


#### what is MAC address
- The length of a MAC (Media Access Control) address is typically 48 bits or 6 bytes. This is commonly represented as 12 hexadecimal digits, separated by colons or hyphens, such as 00:1A:2B:3C:4D:5E. Each hexadecimal digit represents 4 bits, so 12 hexadecimal digits correspond to 48 bits in total.

- However, there are also other types of MAC addresses with different lengths, such as EUI-64 addresses, which are 64 bits long. These addresses are commonly used in IPv6 networks and are derived from the device's 48-bit MAC address.

- In summary, while the most common length for a MAC address is 48 bits (6 bytes), there are variations with different lengths depending on the specific requirements and protocols used in the network.

#### can 2 machine have same MAC address
In general, no, two machines cannot have the same MAC (Media Access Control) address on the same network segment. MAC addresses are intended to be globally unique identifiers assigned to network interfaces by the manufacturer. The IEEE assigns blocks of MAC addresses to manufacturers, and each manufacturer is responsible for ensuring that the MAC addresses they assign are unique.

However, it is technically possible for two machines to have the same MAC address if:

- The manufacturer accidentally duplicates MAC addresses.
- A user manually configures the same MAC address on multiple machines, which is against the standard practice and can lead to network issues and conflicts.
- Having two machines with the same MAC address on the same network segment can cause network problems, as switches and routers rely on MAC addresses to forward traffic. This situation can lead to confusion and errors in network communication.

#### Raw Socket
- A raw socket is a type of socket that allows applications to directly access the network layer of the operating system's networking stack. Unlike other types of sockets (such as TCP or UDP sockets), which operate at the transport layer and handle data transmission using specific protocols like TCP or UDP, raw sockets operate at a lower level, typically at the network layer.

- With raw sockets, applications can send and receive packets directly without the need for protocol processing by the operating system. This provides more control over the networking functionalities and allows for the implementation of custom protocols or low-level network operations.

- Here are some key points about raw sockets:

`Access to Network Layer`: Raw sockets provide direct access to the network layer of the networking stack, allowing applications to interact with IP packets directly.

`Custom Protocols: `Applications can implement custom protocols or perform low-level network operations by using raw sockets. This is useful for tasks such as network scanning, packet sniffing, network monitoring, or protocol development.

`Packet Filtering:` Raw sockets enable applications to filter incoming and outgoing packets based on specific criteria, such as source or destination IP addresses, protocol types, or packet contents.

`Administrative Privileges:` Typically, raw socket operations require administrative privileges or special permissions due to their low-level nature and potential security implications. This helps prevent misuse or unauthorized access to network resources.

`Security Implications:` The use of raw sockets can introduce security risks, as it allows applications to bypass certain network security mechanisms implemented by the operating system. Therefore, raw socket functionality may be restricted or disabled in some environments to mitigate potential security vulnerabilities.

Overall, raw sockets provide a powerful mechanism for network programming tasks that require low-level access to network packets and protocols. However, they should be used judiciously and with caution, especially in production environments, to ensure proper network operation and security.

#### Active and Passive socket

- `Active Socket:`
    - Also known as a client socket.
    - An active socket is typically created by a client application when it initiates a connection to a server.
    - The client socket actively attempts to establish a connection with a server socket by sending a connection request.
    - Once the connection is established, the client socket can send data to and receive data from the server socket.

- `Passive Socket:`
    - Also known as a server socket.
    - A passive socket is typically created by a server application to listen for incoming connection requests from clients.
    - The server socket passively waits for incoming connection requests on a specific network address (IP address and port number).
    - When a client socket initiates a connection request, the server socket accepts the connection and establishes a new socket for communication with the client. Once the connection is established, the server socket and the client socket can exchange data.

In summary, active sockets are used by client applications to initiate connections, while passive sockets are used by server applications to listen for incoming connections. Together, they enable bidirectional communication between clients and servers in TCP-based network applications.



