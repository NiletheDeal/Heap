#include <iostream>
#include <cstring>
/*
Resources
  https://www.plus2net.com/c-tutorial/string-strncpy.php#:~:text=We%20can%20use%20string%20function,Source%20string%20is%20not%20affected
 */

using namespace std;

void print(int index, int count, int end, int heap[]);
void HEAP(int values[], int heap[], int size);
int max(int arr[]);
int REMOVEROOT(int heap[], int size);
void childCheck(int heap[], int parent);

int main() {
  bool running = true;
  char command[10];
  char input [10000];
  char fileName[30];
  int values[101];
  int heap[101];
  int totalNum = 0;
  for (int i = 0; i < 100; i++) {
    values[i] = 0;
    heap[i] = 0;
  }
  int count = 0;
  cout << "Looping" << endl;
  while (running == true) {
    for (int i = 0; i < 100; i++) {
      values[i] = 0;
    }
    count = 0;
    cout << "FILE, MANUAL, REMOVEROOT, REMOVEALL, PRINT, QUIT" << endl;
    cin.get(command, 10);
    cin.clear();
    cin.ignore(10000, '\n');
    if(strcmp(command, "MANUAL") == 0) {
      int inputNum;
      bool sizecheck = true;
      while(sizecheck == true) {
	cout << "How many numbers are you gonna input?" << endl;
	cin >> inputNum;
	cin.clear();
	cin.ignore(1000, '\n');
	cout << inputNum << endl;
	if (inputNum < 0 && inputNum > 101) {
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
	cout << values[i] << endl;
      }
      cin.clear();
      cin.ignore(10000, '\n');
      totalNum += inputNum;
      HEAP(values, heap, totalNum);
    }
    else if(strcmp(command, "REMOVEROOT") == 0) {
      cout << "Removing Root" << endl;
      totalNum = REMOVEROOT(heap, totalNum);
    }
    else if(strcmp(command, "REMOVEALL") == 0) {
      cout << "Removing All" << endl;
      int current = 1;
      while(current < totalNum) {
	totalNum = REMOVEROOT(heap, totalNum);
      }
    }
    else if(strcmp(command, "PRINT") == 0) {
      int index = 1;
      int count = 0;
      print(index, count, totalNum, heap);
    }
    else if(strcmp(command, "QUIT") == 0) {
      running = false;
    }
    else {
      cout <<"That is not a command!" << endl;
    }
  }
}
void print(int index, int count, int end, int heap[]) {
  if(index*2 + 1 < end) {
    print(index*2 +1, count+1, end, heap);
  }
  for(int i = 0; i < count; i++) {
    cout << '\t';
  }
  cout << heap[index] << endl;
  //left side
  if(index*2 < end) {
    print(index*2, count+1, end, heap);
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
void HEAP(int values[], int heap[], int size) {//Take the biggest put it in slot 1 then you tak enext biggest put in left and then right and when both are full
  int current = 1;
  heap[current] = values[max(values)];
  values[max(values)] = 0;
  while(current <= size) {
    if(heap[2*current] == 0) {//if the node has no children
      heap[2*current] = values[max(values)];//left child
      values[max(values)] = 0;//setting to zero lets max function return the next biggest number
      heap[2*current + 1] = values[max(values)];//right child
      values[max(values)] = 0;
    }
    current++;
  }
}

int max(int arr[]) {
  int maxIndex = 0;
  for(int i = 0; i < 101; i++) {
    if(arr[maxIndex] < arr[i]) {
      maxIndex = i;
    }
  }
  return maxIndex;
}
int REMOVEROOT(int heap[], int size) {
  cout << heap[1] << " ";
  heap[1] = heap[size];
  size--;
  childCheck(heap, 1);
  return size;
}
void childCheck(int heap[], int parent) {
  int temp = 0;
  if(heap[parent] <heap[parent*2] || heap[parent] < heap[(parent*2) + 1]) { // one of the children is bigger
      if(heap[parent*2] >= heap[parent*2 + 1]) {//left child is bigger or equal
	temp = heap[parent*2];
	heap[parent*2] = heap[parent];
	heap[parent] = heap[temp];
	childCheck(heap, parent*2);
      }
      else if(heap[parent*2] < heap[parent*2 + 1]) {//right child bigger
	temp = heap[parent*2 +1];
	heap[parent*2 +1] = heap[parent];
	heap[parent] = temp;
	childCheck(heap, parent*2+1);
      }
  }
}

