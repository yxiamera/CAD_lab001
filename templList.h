#pragma once
#include <iostream>

using namespace std;

//node description
template <class T>
class myNode
{
public:
	//links for list
	myNode *next = nullptr, *prev = nullptr;

	//template data
	T data;
};

//doubly linked list description
template <class T>
class myList
{
private:
	//integer containing size of the list
	unsigned int listSize;
	//links for list's head and tail
	myNode <T> *first, *last;
	//overloading operator for output
	template <class T> friend ostream& operator << (ostream &s, const myList <T> &list);
public:
	//default constructor
	myList()
	{
		first = nullptr;
		last = nullptr;
		listSize = 0;
	}

	//default destructor
	~myList();

	//methods for the dll
	void push_back(T value);				//pushes back one element
	void push_front(T value);				//pushes front one element
	void pop_back();						//pops back one element
	void pop_front();						//pops front one element
	void insert(size_t index, T value);		//inserts one element at index set
	T at(size_t index);						//shows element's data at index set
	void remove(size_t index);				//removes element at index set
	unsigned int get_size();				//returns dll's size
	void clear();							//clears the whole dll
	void set(size_t index, T value);		//changes element's information at index set
	bool isEmpty();							//returns true if dll is empty and false if not
};

template<class T>
inline myList<T>::~myList()
{
	//calling clear() function to delete the dll
	this->clear();
}

template<class T>
inline void myList<T>::push_back(T value)
{
	//adding new pointer
	myNode <T> *newNode = new myNode <T>;
	//assigning input value to field "data"
	newNode->data = value;

	if (first == nullptr) //if dll is empty, added pointer becomes first and last member
		first = last = newNode;
	else
	{
		newNode->prev = last; //else it is added at the end of dll
		last->next = newNode;
		last = newNode;
	}
	listSize++; //increase list size
}

template<class T>
inline void myList<T>::push_front(T value)
{
	myNode <T> *newNode = new myNode <T>;
	newNode->data = value;

	if (first == nullptr) //if dll is empty, added pointer becomes first and last member
		first = last = newNode;
	else
	{
		first->prev = newNode; //else it is added at the beginning of dll
		newNode->next = first;
		first = newNode;
	}
	listSize++; //increase list size
}

template<class T>
inline void myList<T>::pop_back()
{
	if (last != nullptr) //if dll is not empty
	{
		myNode <T> *delNode = last; //create pointer of deleting member
		if (last != first) //if last member is not the only member
		{
			last = last->prev; //make previous member last
			delete delNode; //delete deleting
			last->next = nullptr; //and clear the tail
		}
		else
		{
			delete last;
			first = last = nullptr;
			delNode = nullptr;
		}
	}
	listSize--; //decrease list size
}

template<class T>
inline void myList<T>::pop_front()
{
	if (first != nullptr) //if dll is not empty
	{
		myNode <T> *delNode = first; //create pointer of deleting member
		if (first == last) //if first member is not the only member
		{
			delete first; //delete the only member
			first = last = nullptr; //clear dll's pointers
			delNode = nullptr;
		}
		else
		{
			first = first->next; //make next member first
			delete delNode; //delete deleting
			delNode->next = nullptr; //and clear the head
		}	
	}
	listSize--; //decrease list size
}

template<class T>
inline void myList<T>::insert(size_t index, T value)
{
	size_t index_seeker = 0; //iterator for searching position
	myNode <T> *tempNode = first; //pointer at the beginning

	if (listSize < index) //if index is much bigger than list size
	{
		tempNode = nullptr; //clear temporary data
		delete tempNode;
		throw(out_of_range("insert: Seeking index is out of range")); //and throw exception
	}

	while ((tempNode != nullptr) && (index_seeker != index)) //while not end of dll and position is not found
	{
		tempNode = tempNode->next; //going to the next member
		index_seeker++; //and increasing iterator
	}

	myNode <T> *newNode = new myNode <T>; //adding new pointer
	newNode->data = value; //assigning input value to field "data"

	if (tempNode != nullptr) //if it is not the end of dll
	{
		if (tempNode->prev != nullptr) //if previous member exist
			tempNode->prev->next = newNode; //insert new member at current position
		else
			first = newNode; //insert the only member
		//recover links in dll
		newNode->next = tempNode;
		newNode->prev = tempNode->prev;
		tempNode->prev = newNode;
	}
	else
		if ((first == nullptr) && (index == 0)) //if dll is empty and position is the beginning
			first = last = newNode; //add it at the beginning
		else
			if (index_seeker == index) //if position is at the end
			{
				last->next = newNode; //add member at the end
				newNode->prev = last; //make inverse link
				last = newNode;
			}
	listSize++; //increase list size
}

template<class T>
inline T myList<T>::at(size_t index)
{
	size_t index_seeker = 0;

	myNode <T> *tempNode = first;
	while ((tempNode != nullptr) && (index_seeker != index))
	{
		tempNode = tempNode->next;
		index_seeker++;
	}

	if (tempNode != nullptr) //is position is found
		return tempNode->data; //return data of member at this position
	else
		throw(out_of_range("at: Seeking index is out of range")); //else throw exception
}

template<class T>
inline void myList<T>::remove(size_t index)
{
	size_t index_seeker = 0;

	myNode <T> *tempNode = first;

	if (listSize < index) //if index is much bigger than list size
	{
		tempNode = nullptr; //clear temporary data
		delete tempNode;
		throw(out_of_range("remove: Seeking index is out of range")); //and throw exception
	}

	while ((tempNode != nullptr) && (index_seeker != index))
	{
		tempNode = tempNode->next;
		index_seeker++;
	}

	if (tempNode != nullptr)
	{
		if ((tempNode->prev == nullptr) && (tempNode->next != nullptr)) //if beginning of dll
		{
			first = tempNode->next; //making next member first
			first->prev = nullptr; //removing previous first member
		}
		else
			if ((tempNode->prev != nullptr) && (tempNode->next == nullptr)) //if end of dll
			{
				last = tempNode->prev; //making previous member last
				last->next = nullptr; //removing previous last member
			}
			else
				if ((tempNode->next == nullptr) && (tempNode->prev == nullptr)) //if the only member
					first = last = nullptr; //clear pointers
				else
					if ((tempNode->next != nullptr) && (tempNode->prev != nullptr)) //if at the middle
					{
						//rearranging links excluding removing member
						tempNode->next->prev = tempNode->prev;
						tempNode->prev->next = tempNode->next;
					}
		delete tempNode; //delete member
	}
	listSize--; //decrease list size
}

template<class T>
inline unsigned int myList<T>::get_size()
{
	return listSize; //return listSize's value
}

template<class T>
inline void myList<T>::clear()
{
	while (first != nullptr) //while dll exist
		pop_back(); //popping members back
}

template<class T>
inline void myList<T>::set(size_t index, T value)
{
	size_t index_seeker = 0;
	//searching index
	myNode <T> *tempNode = first;
	while ((tempNode != nullptr) && (index_seeker != index))
	{
		tempNode = tempNode->next;
		index_seeker++;
	}
	//changing data or throwing exception
	if (tempNode != nullptr)
		tempNode->data = value;
	else
		throw(out_of_range("set: Seeking index is out of range"));
}

template<class T>
inline bool myList<T>::isEmpty()
{
	//return false if first element exist
	//and true if not
	return (first == nullptr);
}

template<class T>
inline ostream & operator<<(ostream & s, const myList<T>& list)
{
	myNode <T> *tempNode = list.first;
	size_t count = 1;
	//outputting list by element
	while (tempNode != nullptr)
	{
		s << "\nObject #" << count << "\nValue(s):\n" << tempNode->data;
		tempNode = tempNode->next;
		count++;
	}
	return s;
}
