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
  string userName, tempName;
  int portNumber, sock;
  int bufferSize = 2046;
  string chat[bufferSize];
  char myName[MAXHOSTNAME+1];

  struct sockaddr_in sa;
  struct hostent *hp;

  memset(&sa, 0, sizeof(struct sockaddr_in));

  // Prompt user for server's user name
  cout << "Enter a server host name: ";
  hp = gethostbyname(myName, MAXHOSTNAME);
  if(hp != "program.cs.uh.edu") {
    cout << "Wrong server host name..." << endl;
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
  while((userName != "Terminate.") || (userName != "Terminate") || (userName != "terminate")) {

    send(sock, chat, bufferSize, 0);

    recv(sock, chat, bufferSize, 0);
    cin >> tempName;
    if() {

    }
  }

  // Wait for the user's private key

  // Close the socket
  close(sock);

  // Print out the key it got from the server

  return 0;
}
