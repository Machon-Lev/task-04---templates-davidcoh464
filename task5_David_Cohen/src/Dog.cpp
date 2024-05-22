#include "Dog.h"

Dog::Dog(int age, int weight, string name) :
	m_age(age), m_weight(weight), m_name(name) {}



ostream& operator<< (ostream& os, Dog d)
{
	return os <<"name = "<< d.getName() << " age = " << d.getAge() << ", weight = " << d.getWeight();
}

Dog operator-(const Dog& lhs, const Dog& rhs)
{
	return Dog(lhs.getAge(), (lhs.getWeight() - rhs.getWeight()), lhs.getName());
}

bool operator<(const Dog& lhs, const int rhs)
{
	return lhs.getWeight() < rhs;
}