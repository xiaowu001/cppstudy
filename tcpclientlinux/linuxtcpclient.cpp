#include<sys/socket.h>
#include<arpa/inet.h>
#include<iostream>

using namespace std;

int main(){
    int clientsock;
    clientsock = socket(AF_INET,SOCK_STREAM,0);
    
    sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serveraddr.sin_port = htons(atoi("8086"));
    
    if (connect(clientsock, reinterpret_cast<sockaddr*> (&serveraddr), sizeof(serveraddr)) == -1){
        cout<<"connect error"<<endl;
        exit(1);
    }
    
    char pdata[20] = "hello world1111";
    
    send(clientsock,pdata, 20, 0);
    //close(clientsock);
    return 0;
    
    
}