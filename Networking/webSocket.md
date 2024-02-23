### Web Socket

- WebSockets are a protocol for bi-directional, real-time communication between a client and a server over a single, long-lived connection. 
- Unlike traditional HTTP requests, which are unidirectional and require a new connection for each request, WebSockets allow for continuous communication between the client and server.
- WebSockets are part of the HTML5 specification and are supported by all modern web browsers. They are typically implemented using JavaScript on the client side and a server-side technology such as Node.js or Java on the server side.
- WebSockets work by establishing a persistent connection between the client and server over a single TCP socket. Once the connection is established, data can be sent and received in real-time between the client and server.
- The WebSocket protocol consists of two parts: an initial HTTP handshake and the Web Socket protocol itself.

#### HTTP Handshake
The initial HTTP handshake is used to establish the WebSocket connection. The client sends an HTTP request to the server, specifying the WebSocket protocol in the Upgrade header. The server responds with an HTTP response that includes an Upgrade header indicating that it is switching to the WebSocket protocol.

#### WebSocket Protocol
- Once the HTTP handshake is complete, the client and server can communicate using the WebSocket protocol. The WebSocket protocol is a simple, message-based protocol that allows for bi-directional communication between the client and server.
- Messages are sent in frames, which consist of a header and a payload. The header contains information about the frame, such as the message type, length, and whether it is the final frame in a message. The payload contains the actual message data.

#### Use Cases for WebSockets
- `Chat Applications`: WebSockets are commonly used in chat applications to provide real-time messaging between users. With WebSockets, messages can be sent and received in real-time, providing a fast and responsive chat experience.

- `Online Gaming`: WebSockets are also used in online gaming to provide real-time communication between players and the game server. With WebSockets, game events can be sent and received in real-time, allowing for a more immersive and interactive gaming experience.

- `Real-time Dashboards` WebSockets can also be used to create real-time dashboards that display real-time data updates. With WebSockets, data can be pushed to the dashboard in real-time, allowing users to see the latest updates as they happen.

- `Financial Trading`WebSockets are commonly used in financial trading applications to provide real-time updates on stock prices and other financial data. With WebSockets, data can be sent and received in real-time, allowing traders to make informed decisions based on the latest market information.

#### Conclusion
WebSockets are a powerful protocol for real-time communication between a client and server in web applications. 
They allow for low-latency, bi-directional communication over a single, long-lived connection, making them ideal for real-time applications such as chat, gaming, dashboards, and financial trading. With the widespread adoption of WebSockets in modern web browsers, they have become an essential tool for building real-time web applications.