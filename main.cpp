#include <iostream>
#include <cstring>
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
  int values[101];
  int totalNum = 0;
  for (int i = 0; i < 100; i++) {
    values[i] = 0;
  }
  int count = 0;
  cout << "Looping" << endl;
  while (running == true) {
    for (int i = 0; i < 100; i++) {
      values[i] = 0;
    }
    count = 0;
    cout << "FILE or MANUAL" << endl;
    cin.get(command, 10);
    cin.clear();
    cin.ignore(10000, '\n');
    if(strcmp(command, "MANUAL") == 0) {
      int inputNum;
      bool sizecheck = true;
      while(sizecheck == true) {
	cout << "How many numbers are you gonna input?" << endl;
	cin >> inputNum;
	cin.get();
	cout << inputNum << endl;
	if (inputNum > 0 && inputNum < 101) {
	  cout << "Number of inputs has to be between 1 and 100" << endl;
	  sizecheck = false;
	}
	else {
	  sizecheck = false;
	}
      }
      cout << "Enter each number followed by a space: " << endl;
      for(int i = totalNum; i < (totalNum+inputNum); i++) {
	cin >> values[i];
	//cout << values[i] << endl;
      }
      totalNum += inputNum;
      int heap[101];
      for(int i = 0; i < 101; i++) {
	heap[i] = 0;
      }
      HEAP(values, heap, totalNum);
      
    }
  }
}
/*void PARSE(char* in, int* modify, int& count) {
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
*/
void HEAP(int* values, int* heap, int size) {//Take the biggest put it in slot 1 then you tak enext biggest put in left and then right and when both are full
  int current = 0;
  heap[0] = values[max(values)];
  values[max(values)] = 0;
  while(current <= size) {
    if(heap[2*current + 1] == 0) {//if the node has no children
      heap[2*current + 1] = values[max(values)];//left child
      values[max(values)] = 0;//setting to zero lets max function return the next biggest number
      heap[2*current + 2] = values[max(values)];//right child
      values[max(values)] = 0;
    }
    
  }
}
int max(int* arr) {
  int maxIndex = 0;
  for(int i = 0; i < 101; i++) {
    if(arr[maxIndex] < arr[i]) {
      maxIndex = i;
    }
  }
  return maxIndex
