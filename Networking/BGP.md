### The Border Gateway Protocol (BGP) 
- It is the core routing protocol of the Internet. 
- It's responsible for exchanging routing and reachability information among autonomous systems (ASes), which are networks managed by a single organization or service provider. 
- BGP operates on the principle of `path vector routing`, where each BGP router maintains a routing table containing the best paths to reach different destination networks.

### Here's a simplified overview of how BGP works:
- `Neighbor Establishment`: BGP routers establish neighbor relationships with other BGP routers in neighboring ASes. This is typically done over `TCP` connections established on port `179`.

- `Exchange of Routing Information`: Once neighbor relationships are established, BGP routers exchange routing information in the form of network reachability information called `prefixes` or `routes`. BGP routers advertise the prefixes they can reach to their neighbors and receive advertisements from their neighbors.

- `Path Selection`: BGP routers use a set of policies and attributes to select the best path among multiple paths to reach a destination network. The selection process takes into account factors such as the shortest AS path length, the preference for certain neighbors or transit providers, and various attributes associated with the routes.

- `Update Messages`: BGP routers exchange update messages to inform their neighbors about changes in the network topology or reachability information. Update messages contain information about newly available routes, withdrawn routes, and updates to existing routes.

- `Policy Enforcement`: BGP routers enforce routing policies defined by the network administrator or service provider. These policies control how routing information is propagated, filtered, and modified as it traverses the network. Policies can be used to implement traffic engineering, route filtering, prefix aggregation, and other routing optimizations.

- `Loop Prevention`: BGP routers employ mechanisms to prevent routing loops and ensure the stability and convergence of the routing system. These mechanisms include the use of loop prevention mechanisms like the AS Path attribute, route dampening, route summarization, and the use of route reflectors and confederations in large-scale networks.

- `Convergence`: BGP ensures that routing information is propagated efficiently and consistently throughout the Internet. BGP routers continuously exchange routing updates and adjust their routing tables to reflect changes in network topology or reachability information.

Overall, BGP plays a critical role in enabling the Internet to function as a global, interconnected network by facilitating the exchange of routing information between autonomous systems and ensuring the efficient and reliable routing of data packets between different networks.

### What is an autonomous system
The Internet is a network of networks. It is broken up into hundreds of thousands of smaller networks known as autonomous systems (ASes). Each of these networks is essentially a large pool of routers run by a single organization.
![](image/bgp_1.png)





