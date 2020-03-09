#include "arrayListType.h"
#include <iostream>
#include <string>
#include <sstream>
int main() {
  stringstream ss;//to convert strings to ints
  arrayListType<int> t;//object of class arrayList Type
  string temp;//string for 5 integers 
  int * found;//pointer for array
  found = new int [1];//dynamic array 

  //ask user to enter 5 or less integers
  std::cout << "\nEnter 5 integers: ";
  getline(cin, temp);//get the string
  ss << temp;//push into the stream
  int counter = 0;//count the number of ints
  if(temp != "")//if blank nothing enter into the array
  {
    while(!ss.eof()) {//until the end of the stream
    ss >> temp;
    stringstream(temp) >> found[counter];//load into dynamic array
    temp = "";//insert buffer
    counter++;//keep count
    }
  }
  ss.clear();
  for(int i = 0; i < counter; i++)//if any, load until array
  {
   t.insertAt(i, found[i]);
  }
  cout << "\nThe list you entered is: ";//display list
  t.print();


  cout << "\nEnter the position of item to be deleted: ";//ask user to delete
  getline(cin, temp);//get the string
  ss << temp;//push into the stream
  if(temp != "")//if blank nothing enter into the array
  {
    if(!ss.eof()) {//until the end of the stream
      ss >> temp;
      stringstream(temp) >> found[0];//load into first spot in array
      }
  }
  ss.clear();//clear stream after use
  t.removeAt(found[0]);//remove value at location
  //cin.ignore();


  //ask user to enter new info into the array
  cout << "\nEnter the position and an integer to be inserted: ";
  getline(cin, temp);
  ss << temp;
  int i = 0;
  while(!ss.eof()) {//find each of the users location and integer
    ss >> temp;
    stringstream(temp) >> found[i];
    temp = "";
    i++;
  }
  int position = found[0];//insert first element into position variable
  int integer1 = found[1];//insert second element into integer variable
  t.insertAt(position, integer1);//insert new value into specific location in array
  

  //display list and min element
  cout << "Final list: ";
  t.print();
  cout << "The smallest element: " << t.min();
  return 0;
}