#include "arrayListType.h"
#include <iostream>
#include <string>
#include <sstream>
int main() {
  stringstream ss, ss1;
  arrayListType<int> t;
  string temp;
  int found[5];
  int temp1;

  std::cout << "Please enter 5 variables: " << std::endl;
  getline(cin, temp);
  ss << temp;
  int i = 0;
  while(!ss.eof()) {
    ss >> temp;
    stringstream(temp) >> found[i];
    temp = "";
    i++;
  }

  for(int i = 0; i < 5; i++)
  {
   t.insertAt(i, found[i]);
  }
  cout << "\nThe list you entered is: ";
  t.print();
  cout << "\nEnter the position of item to be deleted: ";
  cin >> temp1;
  t.removeAt(temp1);
  cout << "\nAfter removing the element at position " << temp1 << ", the list is: ";
  t.print();
  cin.ignore();
  cout << "\nEnter the position and an integer to be inserted: ";
  getline(cin, temp);
  ss1 << temp;
  i = 0;
  while(!ss1.eof()) {
    ss1 >> temp;
    stringstream(temp) >> found[i];
    temp = "";
    i++;
  }
  int position = found[0];
  int integer1 = found[1];
   
  
 
  t.insertAt(position, integer1);
  
  cout << "Final list: ";
  t.print();
  cout << "The smallest element: " << t.min();
  return 0;
}