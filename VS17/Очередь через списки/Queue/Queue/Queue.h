#pragma once
#include <iostream>

template <class T>
struct TLink
{
	T val;				// значение
	TLink <T> *pNext;   // указательна следующий элемент
};

template <class T>
class TQueue 
{
private:
	TLink <T> *pFirst;		// указатель на первое звено
	TLink <T> *pLast;		//указатель на последнее звено
public:
	TQueue();			//конструктор по умолчанию
	TQueue(const TQueue <T> &q); // конструктор копирования
	~TQueue();			//Деструктор
	bool IsEmpty();		//Проверка на пустоту
	void PushLast(const T &elem);	//Вставить в очередь элемент
	T PopFirst();			//Вытащить первый элемент из очереди
	T WhoIsFirst();		//Посмотреть, что находится в начале очереди
	T WhoIsLast();		//Посмотреть, что находится в конце очереди
	int Count();		//Количество элементов в очереди

};


template <class T>
TQueue<T>::TQueue() 
{
	pFirst = NULL;
	pLast = NULL;
	pLast->pNext = NULL;
}

template <class T>
TQueue<T>::TQueue(const TQueue <T> &q) 
{
	TLink <T> *tmp = q.pFirst;
	pFirst = NULL;
	while (tmp != NULL)
	{
		TLink <T>  *p = new TLink <T>;
		if (pFirst == 0) 
		{
			pFirst = p; 
			pLast = p;
		}
		else 
		{
			pLast->pNext = p;
			pLast = p;
		}
		p->val = tmp->val;
		tmp = tmp->pNext;
	}
	pLast->pNext = 0;
}



template <class T>
TQueue<T>::~TQueue() 
{
	TLink <T> *tmp = pFirst;
	while (pFirst != NULL)
	{
		pFirst = pFirst->pNext;
		delete tmp;
		tmp = pFirst;
	}
}
template <class T>
bool TQueue <T>::IsEmpty() 
{
	return (pFirst == NULL);
}

template <class T>
void TQueue <T>  ::PushLast(const T &elem) 
{
	TLink <T> *tmp = new TLink <T>;
	tmp->val = elem;	
	tmp->pNext = NULL;
	pLast->pNext = tmp;
	pLast = tmp;
}

template <class T>
T TQueue <T> ::PopFirst() 
{
	if (IsEmpty())
		throw - 1;
	TLink <T> *tmp = pFirst;
	pFirst = pFirst->pNext;
	T elem = tmp->val;
	delete tmp;
	return elem;
}

template <class T>
T TQueue <T>::WhoIsFirst() 
{
	if (IsEmpty())
		throw - 1;
	return (pFirst->val);
}

template <class T>
T TQueue <T>::WhoIsLast()
{
	if (IsEmpty())
		throw - 1;
	return (pLast->val);
}

template <class T>
int TQueue <T>::Count() 
{
	int count = 0;
	while (pFirst != NULL) 
	{
		count++;
		pFirst = pFirst->pNext;
	}
	return count;
}