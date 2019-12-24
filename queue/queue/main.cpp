#include"queue-list.h"
#include<conio.h>
#include<iostream>
using namespace std;
int main()
{
	TQueue<int> q;
	int el;
	bool b;
	cin >> el;
	b = q.IsEmpty();
	cout<< b<<endl;
	q.Push(el);
	b = q.IsEmpty();
	cout<<b<<endl;
	q.Pop();
	for (int i = 0; i <10; i++)
	{
		cin >> el;
		q.Push(el);
	}
	b=q.IsFull();
	cout << b<<endl;
	el = q.Pop();
	cout << el<<endl;
	_getch();
}