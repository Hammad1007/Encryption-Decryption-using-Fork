#include <iostream>
#include <sys/wait.h>>
#include <unistd.h>
#include <string.h>
#include <cstring>

using namespace std;

int main() {
  string s;
  cout << "Enter the string: ";
  getline(cin, s);
  cout << "The original string entered is: " << s << "\n";
  int size = s.length();
  pid_t pid;   // process id variable
  pid = fork();
  if(pid == 0) {
    // means child created
    for(int i = 0; i < size; i++) {
       s[i] = s[i] + 5;  // the encryption is set to 5 
    }
    cout << "The encrypted string is: " << s << "\n";
    
    for(int i = 0; i < size; i++) {
       s[i] = s[i] - 5;  // the decryption is set to 5  
    }
    cout << "The decrypted message is: " << s << "\n";
  }
  else {
    // parent process
    wait(NULL);
  }
}
