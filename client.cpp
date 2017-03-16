// Chien Nguyen
// PS# 1328764

// CLIENT

#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

using namespace std;

int main() {

  string hostName;
  int portNumber, sock;
  const int bufferSize = 1024;
  char buffer[bufferSize];

  struct sockaddr_in sa;

  // Prompt uesr for user name
  cout << "Enter a server host name: ";
  cin >> hostName;

  // Prompt user for server's port number
  cout << "Enter server port number: ";
  cin >> portNumber;

  // Create a socket
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if(sock < 0) {
    cout << "Could not create socket..." << endl;
    return;
  }

  sa.sin_family = AF_INET;
  sa.sin_port = htons(portNumber);
  if (bind(s, &sa, sizeof(struct sockaddr_in)) < 0) {
    cout << "Could not bind socket..." << endl;
    return;
  }

  // Connect it to server
  if(connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) != 0) {
    cout << "Could not connect to server..." << endl;;
    return;
  }

  // Send the user name to the server


  // Wait for the user's private key

  // Close the socket
  close(sock);

  // Print out the key it got from the server


  return 0;
}
