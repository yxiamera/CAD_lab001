#include "templList.h"
#include "boxwood.h"
#include <iostream>

using namespace std;

template <class T>
void menu(myList <T> list);

int main()
{
	myList <boxwood> List;

	menu(List);
	system("pause");
	return 0;
}

template <class T>
void menu(myList <T> list)
{
	int answer = -1;
	T incData;
	size_t position = 0;

	cout << "Welcome!\nHere you can work with template double-linked list.\n"
	<< "Commands and methods:\n1 - push_back\n2 - push_front\n3 - pop_back\n4 - pop_front\n5 - insert\n6 - at\n7 - remove\n8 - get_size\n9 - clear\n10 - set\n11 - isEmpty\n12 - EXIT\n"
	<< "Your answer: ";
	cin >> answer;

	while (answer != 12)
	{
		switch (answer)
			{
				case 1:
				{
					cout << "Enter object's data:\n";
					cin >> incData;
					cout << "Pushing entered data back...\n";
					list.push_back(incData);
					cout << "New list:\n" << list << endl;
					cout << "Your answer: ";
					cin >> answer;
					break;
				}
				case 2:
				{
					cin >> incData;
					cout << "Pushing entered data front...\n";
					list.push_front(incData);
					cout << "New list:\n" << list << endl;
					cout << "Your answer: ";
					cin >> answer;
					break;
				}
				case 3:
				{
					cout << "Popping edge data back...\n";
					list.pop_back();
					cout << "New list:\n" << list << endl;
					cout << "Your answer: ";
					cin >> answer;
					break;
				}
				case 4:
				{
					cout << "Popping edge data front...\n";
					list.pop_front();
					cout << "New list:\n" << list << endl;
					cout << "Your answer: ";
					cin >> answer;
					break;
				}
				case 5:
				{
					cout << "Enter inserting position: ";
					cin >> position;
					cout << "Enter object's data:\n";
					cin >> incData;
					cout << "Inserting data at " << position << " position...\n";
					try
					{
						list.insert(position, incData);
					}
					catch (out_of_range)
					{
						cout << "INSERT: Entered index is out of range!\n";
						break;
					}
					cout << "New list:\n" << list << endl;
					cout << "Your answer: ";
					cin >> answer;
					break;
				}
				case 6:
				{
					cout << "Enter seeking position: ";
					cin >> position;
					cout << "Searching data...\n";
					try
					{
						list.at(position);
					}
					catch (out_of_range)
					{
						cout << "AT: Seeking out nonexisting object!\n";
						break;
					}
					cout << "Your answer: ";
					cin >> answer;
					break;
				}
				case 7:
				{
					cout << "Enter position to remove: ";
					cin >> position;
					cout << "Removing data...\n";
					try
					{
						list.remove(position);
					}
					catch (out_of_range)
					{
						cout << "REMOVE: Entered index is out of range!\n";
						break;
					}
					cout << "New list:\n" << list << endl;
					cout << "Your answer: ";
					cin >> answer;
					break;
				}
				case 8:
				{
					cout << "\nSize: " << list.get_size();
					cout << "Your answer: ";
					cin >> answer;
					break;
				}	
				case 9:
				{
					cout << "Clearing the whole list...\n";
					list.clear();
					cout << "Complete!\n";
					cout << "Your answer: ";
					cin >> answer;
					break;
				}
				case 10:
				{
					cout << "Enter position to edit: ";
					cin >> position;
					cout << "Enter new object's data:\n";
					cin >> incData;
					cout << "Saving changes...\n";
					try
					{
						list.set(position, incData);
					}
					catch (out_of_range)
					{
						cout << "SET: Trying to edit nonexisting object!\n";
						break;
					}
					cout << "New list:\n" << list << endl;
					cout << "Your answer: ";
					cin >> answer;
					break;
				}
				case 11:
				{
					cout << "Emptyness: " << list.isEmpty() << endl;
					cout << "Your answer: ";
					cin >> answer;
					break;
				}
				case 12:
				{
					list.~myList();
					break;
				}
				default:
				{
					cout << "Input error! Please check list of commands.\n"
						<< "Commands and methods:\n1 - push_back\n2 - push_back\n3 - pop_back\n4 - pop_front\n5 - insert\n6 - at\n7 - remove\n8 - get_size\n9 - clear\n10 - set\n11 - isEmpty\n12 - EXIT\n"
						<< "Your answer: ";
					cin >> answer;
					break;
				}
			}
	}
}