#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <fstream>

using namespace boost::asio;
using ip::tcp;
using std::cout;
using std::endl;
using std::string;

int main()
{
    io_service io;

    // Create a TCP server and listen on port 3000
    tcp::acceptor acceptor(io, tcp::endpoint(tcp::v4(), 3000));

    while (true)
    {
        // Accept incoming connections
        tcp::socket socket(io);
        acceptor.accept(socket);

        // Read 'index.html' file
        std::ifstream file("index.html");
        if (!file.is_open())
        {
            std::cerr << "Failed to open 'index.html'" << std::endl;
            return 1;
        }

        std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        file.close();

        // Create an HTTP response
        string response = "HTTP/1.1 200 OK\r\n";
        response += "Content-Type: text/html\r\n";
        response += "Content-Length: " + std::to_string(content.length()) + "\r\n";
        response += "Connection: close\r\n\r\n";
        response += content;

        // Send the response to the client
        boost::system::error_code ignored_error;
        write(socket, buffer(response), ignored_error);
    }

    return 0;
}
