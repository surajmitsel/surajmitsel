### what is SSL communication
- In below diagram only one way certificate is exchanged (server to client)
- In Some case 2 way certificate exchange is also supported.x

![](image/ssl_1.png)
![](image/ssl_2.png)

### What is Open SSL
- OpenSSL is an open-source software library that provides cryptographic functions and protocols for secure communication over computer networks. It implements the Secure Sockets Layer (SSL) and Transport Layer Security (TLS) protocols, which are commonly used to secure internet communications, including web browsing, email, instant messaging, and virtual private networks (VPNs).

- OpenSSL offers a wide range of cryptographic functions, including encryption, decryption, digital signatures, certificate management, and random number generation. It is widely used in various software applications, operating systems, and network devices to provide secure communication and data protection.

- Overall, OpenSSL plays a crucial role in ensuring the confidentiality, integrity, and authenticity of sensitive data transmitted over networks.

### HTTPS 
![](image/HTTPS.jpg)

### Why do we need TLS or SSL if IPsec also provide the security
- TLS (Transport Layer Security) and IPsec (Internet Protocol Security) are both protocols used to provide security for network communication, but they operate at different layers of the networking stack and serve different purposes:

- TLS operates at the transport layer (Layer 4) of the OSI model. It is primarily used to secure end-to-end communication between applications running on hosts over the Internet. TLS is commonly used to secure protocols like HTTPS, SMTPS, IMAPS, and others. It provides encryption, authentication, and integrity protection for the data exchanged between client and server applications.

- IPsec operates at the network layer (Layer 3) of the OSI model. It is designed to secure IP packets as they are transmitted over the network. IPsec can be used to secure communication between network devices such as routers, firewalls, and VPN gateways. It provides encryption, authentication, and integrity protection for IP packets at the network layer.

- While TLS is more commonly used for securing application-level communication, IPsec is often used to secure communication between network infrastructure devices or to create secure tunnels between networks. Both TLS and IPsec have their own strengths and use cases, and they can be used together in a complementary manner to provide end-to-end security for network communication.

### PKI
- PKI (Public Key Infrastructure) certificate handling involves the management of digital certificates within a PKI framework. 
- This includes tasks such as issuing, revoking, and validating certificates, as well as managing the associated public and private keys. 
- PKI certificate handling is crucial for ensuring the security and integrity of online communications, as it enables the secure exchange of information over networks by verifying the identities of parties involved and encrypting data transmissions.




