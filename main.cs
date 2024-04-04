using System;
using System.Net;
using System.Threading.Tasks;
using System.IO;
using System.Text;

class Program {
    static HttpListener? listener;

  //Listen on All Interfaces: Ensure your server is configured to listen on all network interfaces
  //in your C# HttpListener, you've set the prefix to "http://localhost:8080/". Try changing
  //this to "http://*:8080/" or "http://0.0.0.0:8080/" to make your server listen to all 
  //incoming requests regardless of the hostname.
    const string PREFIX = "http://*:8080/"; //


    static async Task HandleIncomingConnections() {
        while (true) {
            var ctx = await listener.GetContextAsync();
            string json;
            using (var reader = new StreamReader(ctx.Request.InputStream, ctx.Request.ContentEncoding)) {
                json = await reader.ReadToEndAsync();
            }
            Console.WriteLine("Received data: " + json);
            // Process the received data here
            // You can deserialize JSON, save it to a database, etc.
            ctx.Response.StatusCode = 200;
            ctx.Response.Close();
        }
    }

    static void Main(string[] args) {
        listener = new HttpListener();
        listener.Prefixes.Add(PREFIX);
        listener.Start();
        Console.WriteLine("Listening for connections on " + PREFIX);

        Task listenTask = HandleIncomingConnections();
        listenTask.GetAwaiter().GetResult();

       listener.Close();
    }
}
