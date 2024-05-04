### REST
- REST, or Representational State Transfer, is not a protocol but an architectural style for designing networked applications. 
- It relies on a stateless, client-server, cacheable communications protocol — and in virtually all cases, the HTTP protocol is used.

### DESIGN
Designing a RESTful API involves careful consideration of several key factors to ensure that it is efficient, flexible, maintainable, and user-friendly. Here’s a guide to designing a REST API, detailing the steps and best practices:

#### 1. Understand the Domain and Requirements
Before starting, fully understand the domain and the specific data interactions required by your API consumers. This understanding will guide the design and the operations your API needs to support.

#### 2. Define Your Resources
A RESTful API is resource-based. Resources are conceptual entities or objects in your domain. Defining these entities clearly and how they relate to each other is crucial. For example, in an e-commerce system, typical resources might be User, Product, Order, etc.

#### 3. Use Nouns for Resource Names
Resource names should be nouns (not verbs) and should be consistent and meaningful. Use plural nouns for consistency (e.g., /users, /products). This makes it intuitive and enhances the readability and usability of your API.

#### 4. Use HTTP Methods Correctly
Leverage standard HTTP methods to perform operations on resources:

- `GET` for retrieving resources
- `POST` for creating new resources
- `PUT` for updating existing resources or creating them if they do not exist
- `PATCH` for making partial updates to resources
- `DELETE` for deleting resources

#### 5. Resource Nesting
Express relationships and hierarchies through resource nesting carefully. For example, /users/123/orders might represent all orders for user 123. However, avoid deep nesting as it can complicate the API (generally not deeper than three levels).

#### 6. Response Formats
Choose appropriate formats for data exchange. JSON is the most popular due to its readability and support in web technologies. XML is another option, though less commonly used in modern APIs.

#### 7. Error Handling
Provide clear, consistent error messages and HTTP response codes. Use standard HTTP status codes correctly (e.g., 200 OK, 404 Not Found, 500 Internal Server Error). Provide helpful error messages in the body that can guide the consumer on what went wrong and possibly how to fix it.

#### 8. Pagination, Filtering, and Sorting
For large collections, pagination is crucial. Provide ways to filter and sort data to help API consumers find the data they need. For example:

- /products?page=2&limit=20 for pagination
- /orders?status=shipped for filtering
- /products?sort=price_asc for sorting

#### 9. Versioning
APIs evolve over time. Versioning your API helps prevent breaking changes for existing users. You can version your API in the URL (/api/v1/products) or use HTTP headers.

#### 10. Security
Consider security from the start. 
- Use HTTPS to encrypt data in transit. 
- Authenticate users via standard protocols like OAuth2. 
- Ensure you have rate limiting, input validation, and proper access controls in place.

#### 11. Documentation
Provide comprehensive, clear, and up-to-date documentation. Good documentation includes:

- Available endpoints and methods
- Request examples and response examples
- Error codes and messages
- Authentication methods

Documentation tools like Swagger (OpenAPI) or Postman can help automate part of this process and provide interactive documentation where users can try out the API calls in the browser.

#### 12. Rate Limiting
To protect your API from overuse or abuse, implement rate limiting. This controls how many requests a user or a service can make in a given amount of time.

### Conclusion
A well-designed REST API is intuitive to use and understand. Consistency in naming conventions, HTTP method usage, and error handling will make your API robust and user-friendly. Consider the scalability, maintainability, and performance of your API throughout its design and implementation.