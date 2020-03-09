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
  if(location < 5 && location >= 0)//test array length and location of variable
  {
    if(length < 5)
    {
      elemType temp = list[location];//original value pushed into temp holder
      list[location] = insertItem;//new value pushed into spot
      for(int i = location + 1; i < length + 1; i++)//loop through array starting at new value location
      {
        elemType newTemp = list[i];//insert in a new temp
        list[i] = temp;//move old temp to list
        temp = newTemp;//replace old temp to new temp
      }
      length++;//increase length of array
    }
    else
      cout << "Array is Full" << endl;
  }
  else
    cout << "Position is out of range. The list does not change." << endl;
}

// removeAt function definition
template <class elemType> void arrayListType<elemType>::removeAt(int location){
  if(location < length && location >= 0)//test location
  {
  for(int i = location; i < length; i++)//move through the array moving all items
  {
    elemType temp = list[i];//insert into temp
    list[i] = list[i + 1];//move next element into current element
    list[i+ 1] = temp;//insert into next array element
  }
  length--;//decrease array size
  cout << "After removing the element at position " << location << ", the list is: ";
  print();
  }
  else
    cout << "The location of the item to be removed is out of range. The list does not change.";
} 
//end removeAt function

// find minimum value of the list
template <class elemType>elemType arrayListType<elemType>::min() const{
  if(length > 0)
  {
 elemType min = list[0];//set current to min
 for(int i = 1; i < length; i++)//loop through array starting at second location
 {
   if(min > list[i])//if min is smaller than current, assign new min
   {
     min = list[i];
   }
 }
 return min;
}
 return 0;//return min
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