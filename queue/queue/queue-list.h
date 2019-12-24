#pragma once
#include<iostream>
using namespace std;
template<class T>
struct TNode
{
	T val;
	TNode<T> *pNext;
};
template<class T>
class TQueue
{
	TNode<T> *pFirst, *pLast;
public:
	TQueue();
	TQueue(const TQueue<T> &q);
	TQueue<T>& operator =(const TQueue<T> &q);
	void Push(T el);
	T Pop();
	T Front();
	T Back();
	bool IsFull();
	bool IsEmpty();
	int GetMaxSize();
	~TQueue();
};
template<class T>
TQueue<T>::TQueue<T>()
{
	pFirst = NULL;
	pLast = NULL;
}
template<class T>
TQueue<T>::~TQueue()
{
	TNode<T> *p;
	p = pFirst;
	while (pFirst != NULL)
	{
		p = pFirst->pNext;
		delete pFirst;
		pFirst = p;
	}
}
template<class T>
TQueue<T>::TQueue<T>(const TQueue<T> &q)
{
	TNode<T> *p = q.pFirst;
	if (p == NULL) pFirst = p;
	while (p != NULL)
	{
		Push(p->val);
		p = p->pNext;
	}
	delete p;
}
template<class T>
TQueue<T>& TQueue<T>::operator =(const TQueue<T> &q)
{
	TQueue<T> rez;
	TNode<T> *p = q.pFirst;
	if (p == NULL) rez.pFirst = p;
	while (p != NULL)
	{
		rez.Push(p->val);
		p = p->pNext;
	}
	delete p;
	return rez;
}
template<class T>
void TQueue<T>::Push(T el)
{
	TNode<T> *p;
	p = new TNode<T>;
	p->val =el;
	p->pNext = NULL;
	if (pLast == NULL)
	{
		pFirst = p;
		pLast = p;
	}
	else
	{
		pLast->pNext = p;
		pLast = p;
	}
}
template<class T>
T TQueue<T>::Pop()
{
	if (pFirst == NULL) throw "can not get elem";
	T val1 = pFirst->val;
	TNode<T> *p = pFirst;
	pFirst = pFirst->pNext;
	delete p;
	if (pFirst == NULL) pLast = NULL;
	return val1;
}
template<class T>
T TQueue<T>::Front()
{
	if (pFirst == NULL) throw "can not look on top";
	return pFirst->val;
}
template<class T>
T TQueue<T>::Back()
{
	if (pLast == NULL) throw "can not look on back";
	return pLast->val;
}
template<class T>
bool TQueue<T>::IsEmpty()
{
	if (pFirst == NULL) return true;
	else return false;
}
template<class T>
bool TQueue<T>::IsFull()
{
	TNode<T> *p;
	p = new TNode<T>;
	if (p == NULL) return true;
	else
	{
		delete p;
		return false;
	}
}
template<class T>
int TQueue<T>::GetMaxSize()
{
	int k=0;
	TNode<T> *p = pFirst;
	while (p != NULL)
	{
		k++;
		p = p->pNext;
	}
	return k;
}