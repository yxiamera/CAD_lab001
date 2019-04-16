#pragma once
#include <iostream>

using namespace std;

class boxwood
{	
public:
	unsigned short age;
	double height;

	boxwood()
	{
		age = 0;
		height = 0.0;
	}

	~boxwood() {}

	friend istream& operator >> (istream &s, boxwood &bwIn)
	{
		cout << "Age: ";
		cin >> bwIn.age;
		cout << "Height: ";
		cin >> bwIn.height;
		return s;
	}

	friend ostream& operator << (ostream &s, const boxwood &bwOut)
	{
		s << "Age: " << bwOut.age << " y.\nHeight: " << bwOut.height << " m\n";
		return s;
	}
};