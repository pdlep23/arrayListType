#ifndef H_arrayListType
#define H_arrayListType
#include <iostream>
#include <cassert>

using namespace std;

template <class elemType>
class arrayListType
{
  public:
  void print() const;
  //Function to output the elements of the list
  //Postcondition: Elements of the list are output on the 
  //   standard output device.

  void insertAt(int location, const elemType& insertItem);
  //Function to insert an item in the list at the 
  //position specified by location. The item to be inserted 
  //is passed as a parameter to the function.
  //Postcondition: Starting at location, the elements of the
  //list are shifted down, list[location] = insertItem;,
  //and length++;. If the list is full or location is
  //out of range, an appropriate message is displayed.
  
  void removeAt(int location);
  //Function to remove the item from the list at the 
  //position specified by location 
  //Postcondition: The list element at list[location] is removed
  //and length is decremented by 1. If location is out of 
  //range,an appropriate message is displayed.

  elemType min() const;
  //find the minimum value of the array
  
  arrayListType(int size = 5);
  //constructor
  //Creates an array of the size specified by the 
  //parameter size. The default array size is 5.
  //Postcondition: The list points to the array, length = 0, 
  //and maxSize = size

  ~arrayListType();
  //destructor

  protected:
  elemType *list;  //array to hold the list elements
  int length;      //to store the length of the list
  int maxSize;     //to store the maximum size of the list
};

template <class elemType> void arrayListType<elemType>::insertAt(int location, const elemType& insertItem)
{
  if(length < 5 && location < 5)
  {
    elemType temp = list[location];//original value pushed into temp holder
    list[location] = insertItem;//new value pushed into spot
    for(int i = location + 1; i < length + 1; i++)
    {
      elemType temp2 = list[i];
      list[i] = temp;
      temp = temp2;
    }
  length++;
  }
  else
    cout << "Position is out of range. The list does not change." << endl;
}

// removeAt function definition
template <class elemType> void arrayListType<elemType>::removeAt(int location){
  if(location < 5)
  {
  for(int i = location; i < length; i++)
  {
    elemType temp = list[i];
    list[i] = list[i + 1];
    list[i+ 1] = temp;
  }
  length--;
  }
  else
    cout << "The location of the item to be removed is out of range. The list does not change.";
} 
//end removeAt function

// find minimum value of the list
template <class elemType>elemType arrayListType<elemType>::min() const{
 elemType min = list[0];
 for(int i = 1; i < length; i++)
 {
   if(min > list[i])
   {
     min = list[i];
   }
 }
 return min;
} 
// end min function 

template <class elemType> void arrayListType<elemType>::print() const{
  for(int i = 0; i < length; i++)
  {
    cout << list[i] << " ";
  }
  cout << endl;
} 
// end print function

  // ++++ You need the two templates below to avoid errors +++++++
// constructor function
template <class elemType> arrayListType<elemType>::arrayListType(int size)
{
  if (size < 0)
  {
    cerr << "The array size must be positive. Creating "<< "an array of size 5. " << endl;
    maxSize = 5;
  }
  else
    maxSize = size;
  length = 0;
  list = new elemType[maxSize];
  assert(list != NULL);
}

// destructor function
template <class elemType> arrayListType <elemType>::~arrayListType()
{
  delete[] list;
}

#endif