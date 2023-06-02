#pragma once
#include <iostream>
#include <string>

using std::string; 
using std::ostream;

class Dog
{
	
public:
	Dog(int age, int weight, string name);
	
	int getAge() const { return m_age; }
	int getWeight() const { return m_weight; }

	string getName()const { return m_name; } ;

private:
	int m_age;
	int m_weight;
	string m_name;
};

ostream& operator<< (ostream& os, Dog d);

Dog operator-(const Dog& lhs, const Dog& rhs);

bool operator<(const Dog& lhs, const int rhs);
