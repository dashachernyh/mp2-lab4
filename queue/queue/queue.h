#pragma once
template <class T>
class TQueue
{
	T *mas;
	int MaxSize, Head, Tail,Count;
public:
	TQueue(int _MaxSize = 10);
	TQueue(const TQueue<T> &q);
	TQueue<T>& operator =(const TQueue<T> &q);
	bool IsEmpty();
	bool IsFull();
	void Push(T el);
	T Pop();
	T Front();
	T Back();
	int GetMaxSize();
};
template<class T>
TQueue<T>::TQueue<T>(int _MaxSize)
{
	if (_MaxSize <= 0) throw "can not create";
	MaxSize = _MaxSize;
	mas = new T[MaxSize];
	Head = 0;
	Tail = -1;
	Count = 0;
}
template<class T>
TQueue<T>::TQueue<T>(const TQueue<T> &q)
{
		MaxSize = q.MaxSize;
		mas = new T[MaxSize];
		Head = q.Head;
		Tail = q.Tail;
		Count = q.Count;
		for (int i = 0; i < MaxSize; i++)
			mas[i] = q.mas[i];
}
template<class T>
TQueue<T>& TQueue<T>:: operator=(const TQueue<T> &q)
{
	if (this != &q)
	{
		if (MaxSize != q.MaxSize)
		{
			delete[] mas;
			MaxSize = q.MaxSize;
			mas = new T[MaxSize];
		}
		Head = q.Head;
		Tail = q.Tail;
		Count = q.Count;
		for (int i = 0; i < MaxSize; i++)
			mas[i] = q.mas[i];
	}
	return *this;
}
template<class T>
bool TQueue<T>::IsEmpty()
{
	if (Count == 0) return true;
	else return false;
}
template<class T>
bool TQueue<T>::IsFull()
{
	if (Count == MaxSize) return true;
	else return false;
}
template<class T>
void TQueue<T>::Push(T el)
{
	if (IsFull()) throw "can not push elem";
	if (Tail != MaxSize - 1)
		Tail++;
	else Tail = 0;
	mas[Tail] = el;
	Count++;
}
template<class T>
T TQueue<T>::Pop()
{
	if (IsEmpty()) throw "can not get elem";
	int OldHead = Head;
	if (Head != MaxSize - 1)
		Head++;
	else Head = 0;
	Count--;
	return mas[OldHead];
}
template<class T>
T TQueue<T>::Front()
{
if (IsEmpty()) throw "is empty";
	return mas[Head];
}
template<class T>
T TQueue<T>::Back()
{
	if (IsEmpty()) throw "is empty";
	return mas[Tail];
}
template<class T>
int TQueue<T>::GetMaxSize()
{
	return MaxSize;
}