#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024
using namespace std;
//#define SA struct sockaddr_in;


int main(){
    int server_fd, new_socket;
    struct sockaddr_in addr;
    int opt = 1;
    int addr_len = sizeof(addr);
    char buffer[BUFFER_SIZE] = {0};


    //creating socket file descriptor
    if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("socket failed");
    exit(EXIT_FAILURE);
    }

    // Attach socket to port
    if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
    perror("setsockopt");
    exit(EXIT_FAILURE);
    }

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);

    //Bind the socket
    if(bind(server_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind failure");
        exit(EXIT_FAILURE);
    }

    // Start Listen for incoming connection
    if(listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    cout<<"Server Listening on port : "<<PORT<<endl;}

    //Accept a connection
    if((new_socket = accept(server_fd, (struct sockaddr *)&addr, (socklen_t*)&addr_len)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    // Read data from client
    
    read(new_socket, buffer, BUFFER_SIZE);
    cout<<"Received from the client : "<<buffer<<endl;

    //send a response
    const char *response = "Hello from Server!";
    send(new_socket, response, strlen(response), 0);

    //close the socket
    close(new_socket);
    close(server_fd);
    return 0;
}
