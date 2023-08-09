## TCP ##
source: https://www.javatpoint.com/tcp
- TCP stands for Transmission Control Protocol. 
- It is a transport layer protocol that facilitates the transmission of packets from source to destination. 
- It is a connection-oriented protocol that means it establishes the connection prior to the communication that occurs between the computing devices in a network. 
- This protocol is used with an IP protocol, so together, they are referred to as a TCP/IP.

- The main functionality of the TCP is to take the data from the application layer. Then it divides the data into a several packets, provides numbering to these packets, and finally transmits these packets to the destination. The TCP, on the other side, will reassemble the packets and transmits them to the application layer. 
- As we know that TCP is a connection-oriented protocol, so the connection will remain established until the communication is not completed between the sender and the receiver.

![data_frame](image/tcp.jpg)
- `Source port`: It defines the port of the application, which is sending the data. So, this field contains the source port address, which is 16 bits.
- `Destination port`: It defines the port of the application on the receiving side. So, this field contains the destination port address, which is 16 bits.
- `Sequence number`: This field contains the sequence number of data bytes in a particular session.
- `Acknowledgment number`: When the ACK flag is set, then this contains the next sequence number of the data byte and works as an acknowledgment for the previous data received. For example, if the receiver receives the segment number 'x', then it responds 'x+1' as an acknowledgment number.
- `HLEN`: It specifies the length of the header indicated by the 4-byte words in the header. The size of the header lies between 20 and 60 bytes. Therefore, the value of this field would lie between 5 and 15.
- `Reserved`: It is a 4-bit field reserved for future use, and by default, all are set to zero.
- `Flags`
There are six control bits or flags:
    - `URG`: It represents an urgent pointer. If it is set, then the data is processed urgently.
    - `ACK`: If the ACK is set to 0, then it means that the data packet does not contain an acknowledgment.
    - `PSH`: If this field is set, then it requests the receiving device to push the data to the receiving application without buffering it.
    - `RST`: If it is set, then it requests to restart a connection.
    - `SYN`: It is used to establish a connection between the hosts.
    - `FIN`: It is used to release a connection, and no further data exchange will happen.
- `Window size`
    It is a 16-bit field. It contains the size of data that the receiver can accept. This field is used for the flow control between the sender and receiver and also determines the amount of buffer allocated by the receiver for a segment. The value of this field is determined by the receiver.
- `Checksum`
    It is a 16-bit field. This field is optional in UDP, but in the case of TCP/IP, this field is mandatory.
- `Urgent pointer`
    It is a pointer that points to the urgent data byte if the URG flag is set to 1. It defines a value that will be added to the sequence number to get the sequence number of the last urgent byte.
- `Options`
    It provides additional options. The optional field is represented in 32-bits. If this field contains the data less than 32-bit, then padding is required to obtain the remaining bits.

### Hnadshake ###
In TCP, the connection is established by using three-way handshaking. 
- The client sends the segment with its sequence number.
- The server, in return, sends its segment with its own sequence number as well as the acknowledgement sequence, which is one more than the client sequence number. 
- When the client receives the acknowledgment of its segment, then it sends the acknowledgment to the server. 
![](image/tcp_handsake.jpg)

### Advantages 
- It provides a connection-oriented reliable service, which means that it guarantees the delivery of data packets. If the data packet is lost across the network, then the TCP will resend the lost packets.
- It provides a flow control mechanism using a sliding window protocol.
- It provides error detection by using checksum and error control by using Go Back or ARP protocol.
- It eliminates the congestion by using a network congestion avoidance algorithm that includes various schemes such as additive increase/multiplicative decrease (AIMD), slow start, and congestion window.
### Disadvantage
- It increases a large amount of overhead as each segment gets its own TCP header, so fragmentation by the router increases the overhead.

### Features
- Transport Layer Protocol
- Reliable
- Order of the data is maintained
- Connection-oriented
- Full duplex
- Stream-oriented