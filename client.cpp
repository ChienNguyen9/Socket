// Chien Nguyen
// PS# 1328764

// CLIENT

#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <stdio.h>

using namespace std;

int main() {

  const int MAXHOSTNAME = 17;
  string tempName;
  int portNumber, sock;
  int bufferSize = 2046;
  string userName[bufferSize];
  char myName[MAXHOSTNAME+1];

  struct sockaddr_in sa;
  struct hostent *hp;

  memset(&sa, 0, sizeof(struct sockaddr_in));

  // Prompt user for server's user name
  cout << "Enter a server host name: ";
  gethostbyname(myName, MAXHOSTNAME);
  hp = gethostbyname(myName);
  if(hp == NULL) {
    cout << "Could not get server's host name..." << endl;
    return (-1);
  }

  // Prompt user for server's port number
  cout << "Enter server port number: ";
  cin >> portNumber;

  // Create a socket
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if(sock < 0) {
    cout << "Could not create socket..." << endl;
    return (-1);
  }

  sa.sin_family = AF_INET;
  sa.sin_port = htons(portNumber);

  // Connect it to server
  if(connect(sock, (struct sockaddr*)&sa, sizeof(sa)) != 0) {
    cout << "Could not connect to server..." << endl;;
    return (-1);
  }

  // Send the user name to the server
  do{
    cout << "Enter a user name: ";
    cin >> userName;
    send(sock, userName, bufferSize, 0);

    recv(sock, tempName, bufferSize, 0);
    if() {

    }
  }while(while((userName != "Terminate.") || (userName != "Terminate") || (userName != "terminate"));

  // Wait for the user's private key

  // Close the socket
  close(sock);

  // Print out the key it got from the server

  return 0;
}
