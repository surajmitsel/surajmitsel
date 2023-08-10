## UDP ##
Source: https://www.geeksforgeeks.org/user-datagram-protocol-udp/
- User Datagram Protocol (UDP) is a Transport Layer protocol. 
- UDP is a part of the Internet Protocol suite, referred to as UDP/IP suite. 
- Unlike TCP, it is an unreliable and connectionless protocol. So, there is no need to establish a connection prior to data transfer. 
- UDP comes into the picture. For real-time services like computer gaming, voice or video communication, live conferences; we need UDP. Since high performance is needed, UDP permits packets to be dropped instead of processing delayed packets. There is no error checking in UDP, so it also saves bandwidth. 
- User Datagram Protocol (UDP) is more efficient in terms of both latency and bandwidth. 
- `Notes` – Unlike TCP, the Checksum calculation is not mandatory in UDP. No Error control or flow control is provided by UDP. Hence UDP depends on IP and ICMP for error reporting. Also UDP provides port numbers so that is can differentiate between users requests.

### UDP Header ###

- UDP header is an 8-bytes fixed and simple header, while for TCP it may vary from 20 bytes to 60 bytes. 
- The first 8 Bytes contains all necessary header information and the remaining part consist of data. 
- UDP port number fields are each 16 bits long, therefore the range for port numbers is defined from 0 to 65535; port number 0 is reserved. 
![udp-header](image/UDP_header.png)
- `Source Port`: Source Port is a 2 Byte long field used to identify the port number of the source.
- `Destination Port`: It is a 2 Byte long field, used to identify the port of the destined packet.
- `Length`: Length is the length of UDP including the header and the data. It is a 16-bits field.
- `Checksum`: Checksum is 2 Bytes long field. It is the 16-bit one’s complement of the one’s complement sum of the UDP header, the pseudo-header of information from the IP header, and the data, padded with zero octets at the end (if necessary) to make a multiple of two octets.


### transport layer protocol using UDP 
- NTP (Network Time Protocol)
- DNS (Domain Name Service)
- BOOTP, DHCP.
- NNP (Network News Protocol)
- Quote of the day protocol
- TFTP, RTSP, RIP.

### Advantages:
1. Speed
2. Lower latency 
3. Simplicity
4. Broadcast support 
5. Smaller packet size

### Disadvantages:
1. No reliability
2. No congestion control
3. No flow control
4. Vulnerable to attacks
5. Limited use cases