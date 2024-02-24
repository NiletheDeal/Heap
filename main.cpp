#include <iostream>
#include <cstring>
#include <math.h>
#include "fstream"
/*
Resources
  https://www.plus2net.com/c-tutorial/string-strncpy.php#:~:text=We%20can%20use%20string%20function,Source%20string%20is%20not%20affected
 */

using namespace std;

void print(int index, int count, int end, int heap[]);
void HEAP(int value, int heap[]);
void reORG(int heap[], int cIndex);
int REMOVEROOT(int heap[], int size);
void childCheck(int heap[], int parent);

int main() {
  bool running = true;
  char command[20];
  char input [10000];
  char fileName[30];
  int value = 0;
  int heap[101];
  int totalNum = 0;
  for (int i = 0; i < 100; i++) {
    heap[i] = 0;
  }
  int count = 0;
  cout << "Looping" << endl;
  while (running == true) {//Loop
    count = 0;
    cout << "FILE, MANUAL, REMOVEROOT, REMOVEALL, PRINT, QUIT" << endl;
    cin.get(command, 20);
    cin.clear();
    cin.ignore(10000, '\n');
    if(strcmp(command, "MANUAL") == 0) {//ADD manually
      int inputNum;
      bool sizecheck = true;
      while(sizecheck == true) {//Makes sure all the numbers can be added to the 
	cout << "How many numbers are you gonna input?" << endl;
	cin >> inputNum;
	cin.clear();
	cin.ignore(1000, '\n');
	cout << inputNum << endl;
	if (inputNum +totalNum > 100) {
	  cout << "Number of inputs has to be between 1 and 100" << endl;
	}
	else {
	  sizecheck = false;
	}
      }
      totalNum += inputNum;
      cout << "Enter each number followed by a space: " << endl;
      for(int i = 0; i < inputNum; i++) {//take each number and put it into heap
	cin >> value;
	HEAP(value, heap);
      }
      cin.clear();
      cin.ignore(10000, '\n');
    }
    else if(strcmp(command, "FILE") == 0) {//takes values from a file
      int inputNum;
      bool sizecheck = true;
      while(sizecheck == true) {//makes sure the number of values the user wants to add can fit into the heap
	cout << "How many numbers are you gonna input?" << endl;
	cin >> inputNum;
	cin.clear();
	cin.ignore(1000, '\n');
	cout << inputNum << endl;
	if (inputNum + totalNum > 100) {
	  cout << "Number of total inputs has to be between 1 and 100" << endl;
	}
	else {
	  sizecheck = false;
	}
      }
      ifstream numbers("numbers.txt");
      int numdone = 0;
      while(numbers >> value && numdone < inputNum) {//go through the file and add to heap and then go to the next int until it adds how many the user wanted
	HEAP(value, heap);
	numdone++;
      }
      totalNum += inputNum; 
    }
    else if(strcmp(command, "REMOVEROOT") == 0) {//Removes the root
      cout << "Removing Root" << endl;
      totalNum = REMOVEROOT(heap, totalNum);
    }
    else if(strcmp(command, "REMOVEALL") == 0) {//removes the root again and again until no more numbers left
      cout << "Removing All" << endl;
      while(totalNum >= 1) {//loops till no more numbers
	totalNum = REMOVEROOT(heap, totalNum);
      }
    }
    else if(strcmp(command, "PRINT") == 0) {//print out the tree
      int index = 1;
      print(index, count, totalNum, heap);
    }
    else if(strcmp(command, "QUIT") == 0) {//Close Program
      running = false;
    }
    else {
      cout <<"That is not a command!" << endl;
    }
  }
  return 0;
}
void print(int index, int count, int end, int heap[]) {//print out tree
  if(index*2 + 1 <= end) {//get to the right child 
    print(index*2 +1, count+1, end, heap);
  }
  for(int i = 0; i < count; i++) {//tabs over
    cout << '\t';
  }
  cout << heap[index] << endl;//print out value
  //left side
  if(index*2 <= end) {//get to the left child
    print(index*2, count+1, end, heap);
  }
}
  
void HEAP(int value, int heap[]) {//Take the biggest put it in slot 1 then you tak enext biggest put in left and then right and when both are full
  for(int i = 1; i <=101; i++) {
    if(heap[i] == 0) {
      heap[i] = value;//add to the next free slot
      reORG(heap, i);//reogranize the tree so child is smaller than parent
      return;
    }
  }
}
void reORG(int heap[], int cIndex) {//if parent is smaller swap and check again if next parent is smaller
  int pIndex = floor(cIndex/2);
  if(heap[pIndex] < heap[cIndex] && pIndex !=0) {
    int temp = heap[pIndex];
    heap[pIndex] = heap[cIndex];
    heap[cIndex] = temp;
    //recursion
    reORG(heap, pIndex);
  }
}



int REMOVEROOT(int heap[], int size) {//removes root and swaps with the last value in the tree
  cout << heap[1] << " ";
  heap[1] = heap[size];
  heap[size] = 0;
  size--;
  childCheck(heap, 1);//check if children are larger and if so swap
  cout << endl;
  return size;
}
void childCheck(int heap[], int parent) {//checks if children are larger, swap with which ever child is larger.
  int temp = 0;
  if(heap[parent] < heap[parent*2] || heap[parent] < heap[parent*2 + 1]) { // one of the children is bigger
      if(heap[parent*2] >= heap[parent*2 + 1]) {//left child is bigger or equal
	temp = heap[parent*2];//save left child value
	heap[parent*2] = heap[parent];//replace left child with parent
	heap[parent] = temp;//replace parent with the value of left child
	childCheck(heap, parent*2);//check if the parent is smaller than the child of the child that is larger
      }
      else if(heap[parent*2] < heap[parent*2 + 1]) {//right child bigger
	temp = heap[parent*2 +1];
	heap[parent*2 +1] = heap[parent];
	heap[parent] = temp;
	childCheck(heap, parent*2+1);//check if the parent is smaller than the child of the child that is larger
      }
  }
}

