# SendData-ESP32-.Net
This project includes as a very simple API server that can receive JSON data from ESP32 over HTTP 

This code acts as a very simple API server that can receive JSON data over HTTP. It does not explicitly specify how to route different URIs or handle different types of HTTP requests beyond reading the body of incoming POST requests.
For more complex APIs, a framework like ASP.NET Core is typically used, as it offers more features for routing, middleware, security, and other common API requirements.

HttpListener: A class in .NET Framework that listens for HTTP requests from clients. It is used here to set up a basic server that can accept connections.

PREFIX: A constant string defining the URI prefix that the server will listen on. In this case, it listens on all network interfaces (*) on port 8080.

HandleIncomingConnections: An asynchronous method that continuously waits for HTTP requests. Once a request is received, it reads the JSON data from the request's body using a StreamReader and prints it to the console. This demonstrates how the server can process incoming data. The method also sends a simple HTTP response with status code 200 to acknowledge the receipt of the data.

Main: The entry point of the application. It sets up the HttpListener with the specified prefix and starts listening for incoming connections. It then waits for the HandleIncomingConnections task to complete, which, due to the while (true) loop, effectively runs indefinitely until the application is terminated.
