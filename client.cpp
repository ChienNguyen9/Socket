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

  const int MAXHOSTNAME = 9;
  string tempName, chatting = "";
  string terminate = "";
  int portNumber, sock;
  int bufferSize = 1048;
  char chat[bufferSize];
  char myName[MAXHOSTNAME+1];

  struct sockaddr_in sa;
  struct hostent *hp;

  memset(&sa, 0, sizeof(struct sockaddr_in));

  // Prompt user for server's user name
  cout << "Enter a server host name: ";
  cin >> myName;
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
  if(connect(sock, (struct sockaddr*)&sa, sizeof(sa)) == 0) {
    // Send the user name to the server
    while(terminate != "Terminate.") {
      cout << "Enter a user name: ";
      cin >> chat;
      send(sock, chat, bufferSize, 0);

      terminate = "";
      for(int i = 0; i < strlen(chat); i++) {
        terminate += chat[i];
      }

      do{
        // Wait for the user's private key
        recv(sock, chat, bufferSize, 0);

        for(int i = 0; i < strlen(chat); i++) {
          chatting += chat[i];
        }
        if(chatting == "NOT FOUND") {
          cout << "NOT FOUND" << endl;
        }else{
          // Print out the key it got from the server
          cout << "The public key for user " << terminate << " is " << chatting << ". \n\n";
        }
      }while(chatting == "");
      chatting = "";
    }
  }else{
    cout << "Could not connect to server..." << endl;
    return (-1);
  }

  // Close the socket
  close(sock);

  return 0;
}
