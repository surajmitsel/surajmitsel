### OPC UA
- OPC stands for Open Platform Communications and is one of the most important communication standards for Industry 4.0 and the IoT.
- With OPC, access to machines, devices and other systems in the industrial environment is standardized and enables similar and manufacturer-independent data exchange.
- In this context, the UA in OPC UA stands for “Unified Architecture” and refers to the latest specification of the standard. It differs from its predecessor in that it is platform-independent, moving away from COM/DCOM to purely binary TCP/IP or alternatively SOAP. In addition to many other improvements, OPC UA also supports a semantic data description.

### OPC-UA works
#### Server / Client architecture
The server / client architecture is the traditional communication model in OPC UA. It is based on the idea that there is a passive server component that provides data to other applications that act as clients in the process. The client applications can access data and information from the server via a few standardized services.

The server / client model also includes a subscriber model. In this mechanism, each client can create any number of subscriptions to the server. Through these subscriptions, a client can read data when the server has published a notification.
#### Publish / Subscribe mechanism.
In the PubSub model, there is a Publisher component that defines datasets that contain variables or notifiers. The publisher then publishes a message that contains data changes or notifications. These messages are published to a network where subscribers can listen to them and filter out what they need.

### OPC UA consists of these specifications:

1. Concepts
2. Security Model
3. Address Space Model
4. Services
5. Information Model
6. Mappings
7. Profiles
8. Data Access
9. Alarms and Conditions
10. Programs
11. Historical Access
12. Discovery
13. Aggregates
14. PubSub


### Reference 
https://www.opc-router.com/what-is-opc-ua/
https://opcfoundation.org/about/opc-technologies/opc-ua/ 
https://www.welotec.com/what-is-opc-ua/ 