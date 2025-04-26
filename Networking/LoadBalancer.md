## What is Load Balancing
- Load balancing is the process of distributing network traffic across multiple servers. This ensures no single server bears too much demand. 
- By spreading the work evenly, load balancing improves application responsiveness. 
- It also increases availability of applications and websites for users.
- When one application server becomes unavailable, the load balancer directs all new application requests to other available servers.


## Type of load balancer
- hardware load balancers and software load balancers. `Hardware load balancers`: are dedicated physical devices, while `software load balancers` are applications that run on servers or virtual machines. 
- Additionally, load balancers can be classified by the layer of the OSI model they operate on (e.g., Layer 4 for network load balancers, Layer 7 for application load balancers) and by their intended use (e.g., cloud-based load balancers, gateway load balancers). 

### Hardware Load Balancers:
- These are physical devices that are designed to handle high traffic loads.
- They often offer advanced features like SSL offloading, content caching, and health monitoring.
- Hardware load balancers can be more expensive and less flexible than software solutions. 

### Software Load Balancers:
- These are software applications that can be installed on servers or virtual machines.
- They offer more flexibility and scalability than hardware load balancers.
- Software load balancers can be commercial or open-source. 


## Other Classifications:
- `Layer 4 (Network) Load Balancers`:
These operate at the transport layer (TCP/UDP) and focus on routing traffic based on IP addresses and port numbers. 
- `Layer 7 (Application) Load Balancers`:
These operate at the application layer and can inspect and manipulate application-layer data (e.g., HTTP headers, URLs). 
- `Cloud Load Balancers`:
These are load balancers that are deployed in the cloud and can be used to distribute traffic across multiple cloud environments. 
- `Gateway Load Balancers`:
These act as a single entry and exit point for traffic and are used to manage the availability of virtual appliances. 


