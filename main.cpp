#include <iostream>
/*
Resources
  https://www.plus2net.com/c-tutorial/string-strncpy.php#:~:text=We%20can%20use%20string%20function,Source%20string%20is%20not%20affected
 */

using namespace std;

int main() {
  bool running = true;
  char command[10];
  char input [10000];
  char fileName[30];
  int modify[100];
  for (int i = 0; i < 100; i++) {
    modify[i] = 0;
  }
  int count = 0;
  cout << "Looping" << endl;
  while (running == true) {
    for (int i = 0; i < 100; i++) {
      modify[i] = 0;
    }
    count = 0;
    cout << "FILE or MANUAL" << endl;
    cin.get(command, 10);
    cin.clear();
    cin.ignore(10000, '\n');
    if(strcmp(command, "MANUAL") == 0) {
      cout << "Enter each number followed by a space: " << endl;
      cin.get(input, 10000);
      cin.clear();
      cin.ignore(10000, 'n');
      PARSE(input, modify, count);
    }
  }
}
void PARSE(char* in, int* modify, int& count) {
  int x = 0;
  for(int i = 0; i <strlen(in); i++) {
    if(in[i] == ' ') {
      if (x == 1) {
	int temp = 0;
	temp = in[i - 1] - '0';//if single digit go back one space and then 
    }
    else {
      x++;
      

}
