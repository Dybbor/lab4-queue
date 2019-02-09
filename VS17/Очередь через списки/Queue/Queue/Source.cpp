#include  <iostream>
#include "Queue.h"
using namespace std;

void main() 
{
	cout << "Hello, world" << endl;
	TQueue <int> a;
	cout << a.IsEmpty() << endl;
	a.PushLast(5);
	cout << a.WhoIsLast();
	system("pause");
}

