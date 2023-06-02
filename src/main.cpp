#include <iostream>
#include <exception>
#include "PriorityQueue.h"
#include "Dog.h" 

using std::cout; 
using std::endl;

using std::exception;

int main()
{
	std::cout << "Hello PriorityQueue.h" << std::endl;

	{
		PriorityQueue<Dog> pq;

		pq.push(Dog(1, 13, "Dog03"));
		pq.push(Dog(2, 11, "Dog05"));
		pq.push(Dog(3, 14, "Dog02"));
		pq.push(Dog(4, 15, "Dog01"));
		pq.push(Dog(5, 12, "Dog04"));
		try
		{
			cout << "pq.poll() = " << pq.poll() << endl;
			cout << "pq.poll() = " << pq.poll() << endl;
			cout << "pq.poll() = " << pq.poll() << endl;
			cout << "pq.poll() = " << pq.poll() << endl;
			cout << "pq.poll() = " << pq.poll() << endl;
			cout << "pq.poll() = " << pq.poll() << endl;
		}
		catch (exception& e)
		{
			cout << e.what() << endl;
		}
	}


	cout << endl << endl; 
	{
		PriorityQueue<float> pq;

		pq.push(2.3);
		pq.push(1.4);
		pq.push(2.2);
		pq.push(6.1);
		pq.push(2.5);
		try
		{
			cout << "pq.poll() = " << pq.poll() << endl;
			cout << "pq.poll() = " << pq.poll() << endl;
			cout << "pq.poll() = " << pq.poll() << endl;
			cout << "pq.poll() = " << pq.poll() << endl;
			cout << "pq.poll() = " << pq.poll() << endl;
			cout << "pq.poll() = " << pq.poll() << endl;
		}
		catch (exception& e)
		{
			cout << e.what() << endl;
		}
	}

	return 0;
}