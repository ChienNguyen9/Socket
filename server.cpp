// Chien Nguyen
// PS# 1328764

// SERVER

#include <iostream>
#include <fstream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>

using namespace std;

struct serverTable{
  string userID;
  string publicKey;
};

int main() {

  serverTable table[1024];
  int count = 0, foundCount = 0;
  string fileName, tempID, tempKey, terminate = "";
  string chatting = "", notfound = "NOT FOUND";
  bool running = true;
  int sock, portNumber, server;
  int bufferSize = 1048;
  char chat[bufferSize];

  struct sockaddr_in sa;
  socklen_t size;

  memset(&sa, 0, sizeof(struct sockaddr_in));

  // Prompt user for file name
  cout << "Enter a file name: ";
  cin >> fileName;

  // Gets all the info from the file and puts it in table
  ifstream file;
  file.open(fileName.c_str());
  while(file >> tempID >> tempKey) {
    table[count].userID = tempID;
    table[count].publicKey = tempKey;
    count++;
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

  // Bind an address to that socket
  sa.sin_family = AF_INET;
  sa.sin_port = htons(portNumber);
  if (bind(sock, (struct sockaddr*)&sa , sizeof(sa)) < 0) {
    cout << "Could not bind socket..." << endl;
    return (-1);
  }

  // Set up the buffer size for the socket
  size = sizeof(sa);
  listen(sock, 3);

  // Wait for incoming calls - Accept()
  server = accept(sock, (struct sockaddr*)&sa, &size);
  if(server < 0) {
    cout << "Could not accept server..." << endl;
    return (-1);
  }

  cout << "\nType \"Terminate.\" to exit. \n" << endl;

  // Accept incoming calls (and get a new socket) - client says
  while(terminate != "Terminate.") {
    cout << "Server connected..." << endl;

    do {
      recv(server, chat, bufferSize, 0);
      terminate = "";
      for(int i = 0; i < strlen(chat); i++) {
        terminate += chat[i];
        chatting += chat[i];
      }

      for(int i = 0; i <= count; i++) {
        // Reply with the requested public key
        if(chatting == table[i].userID) {
          tempKey = table[i].publicKey;
          for(int k = 0; k < tempKey.length(); k++) {
            chat[k] = tempKey[k];
          }
          send(server, chat, bufferSize, 0);
          break;
        }
        chatting = "";
        if(count == foundCount) {
          for(int r = 0; r < notFound.length(); i++) {
            chat[r] = notFound[r];
          }
          send(server, chat, bufferSize, 0);
          break;
        }
        foundCount++;
      }
    }while(chatting == "");
  }

  // Hang up
  close(sock);
  file.close();

  return 0;
}
