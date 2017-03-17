// Chien Nguyen
// PS# 1328764

// SERVER

#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;

struct serverTable{
  string userID;
  char publicKey;
}

int main() {

  serverTable table[1024];
  string fileName, terminate = "something";
  int sock, portNumber, server;
  const int bufferSize = 1024;
  char buffer[bufferSize];

  struct sockaddr_in sa;

  // Prompt user for file name
  cout << "Enter a file name: ";
  cin >> fileName;

  // Prompt user for server's port number
  cout << "Enter server port number: ";
  cin >> portNumber;

  // Create a socket
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if(sock < 0) {
    cout << "Could not create socket..." << endl;
    return;
  }

  // Bind an address to that socket
  sa.sin_family = AF_INET;
  sa.sin_port = htons(portNumber);
  if (bind(s, &sa, sizeof(struct sockaddr_in)) < 0) {
    cout << "Could not bind socket..." << endl;
    return;
  }

  // Set up the buffer size for the socket
  size = sizeof(server_addr);
  listen(sock, 3);

  // Wait for incoming calls - Accept()
  server = accept(sock, (struct sockaddr*)&server_addr, &size);
  if(server < 0) {
    cout << "Could not accept server..." << endl;
    return;
  }

  cout << "Type \"Terminate.\" to exit. \t" << endl;

  // Accept incoming calls (and get a new socket) - client says
  /* while((terminate != "Terminate.") || (terminate != "Terminate") || (terminate != "terminate")) {
    send(server, buffer, bufferSize, 0);
  }
  */

  // Reply with the requested public key

  // Hang up
  close(sock);

  // Repeat steps 4 and 7


  return 0;
}
