#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024
//#define SA struct sockaddr_in;
using namespace std;

int main(){
    int sock_fd = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};

    // Creating socket file descriptor
    if((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        cerr << "Socket Creation error" << endl;
        return -1;
    }


    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <=0 ) {
        cerr<<"Invalid address"<<endl;
        return -1;
    }

    // Connect to the server
    if(connect(sock_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0){
    cerr<<"Connection failed"<<endl;
    return -1;
    }

    // Send a message to the server
    string str;
    cout<<"Enter a Message to send to server"<<endl;
    getline(cin, str);
    const char *message = str.c_str();
    send(sock_fd, message, strlen(message), 0);
    cout<<"Message sent to Server"<<endl;

    //Receive response from server
    read(sock_fd, buffer, BUFFER_SIZE);
    cout<<"Received from server : "<<buffer<<endl;
    
    // Close the socket
    close(sock_fd);
    return 0;
}

