#pragma once
#define ZERO_DATA ElemType('0');
struct ElemType {
	char a;
	ElemType(char a);
	ElemType() { a = '0'; };
	ElemType(const ElemType& e) { a = e.a; };
};
template<class T>
struct SequenceStack
{
	T* data;
	size_t capacity;
	SequenceStack<T>(size_t size);
	long top;
	bool pop(T& e);
	bool push(T e);
	bool GetTop(T& e);
	bool IsEmpty();
	bool IsFull();
	bool clean();
	bool initialize(size_t size);
	bool resize(size_t size);
	void printStack();
};

#include "SequenceStack.h"
#include <iostream>
using std::cout;
using std::endl;

template<typename T> SequenceStack<T>::SequenceStack(size_t size)
{
	this->initialize(size);
}

template<typename T> bool SequenceStack<T>::pop(T& e)
{
	if (this->IsEmpty()) return false;
	else e = data[top--];
	return true;
}

template<typename T> bool SequenceStack<T>::push(T e)
{
	if (this->IsFull()) return false;
	else data[++top] = e;
	return true;
}

template<typename T> bool SequenceStack<T>::GetTop(T& e)
{
	if (this->IsEmpty()) return false;
	else e = data[top];
	return true;
}

template<typename T> bool SequenceStack<T>::IsEmpty()
{
	return top == -1;
}

template<typename T> bool SequenceStack<T>::IsFull()
{
	return top == (long)capacity;
}

template<typename T> bool SequenceStack<T>::clean()
{
	delete[] data;
	top = -1;
	return true;
}

template<typename T> bool SequenceStack<T>::initialize(size_t size)
{
	data = new T[size];
	capacity = size;
	top = -1;
	for (size_t i = 0; i < capacity; i++) {
		data[i] = 0;
	}
	return true;
}

template<typename T> bool SequenceStack<T>::resize(size_t size)
{
	size_t i;
	if (capacity >= size) {
		capacity = size;
		if (top > size - 1)top = size - 1;
		return true;
	}
	else {
		capacity = size;
		T* newdata = new T[size];
		for (i = 0; (long)i <= top; i++) {
			newdata[i] = data[i];
		}
		for (; i < size; i++) {
			newdata[i] = 0;
		}
		delete[] data;
		data = newdata;
	}
	return true;
}

template<typename T> void SequenceStack<T>::printStack() {
	cout << "Stack begins:" << endl;
	for (long i = 0; i <= top; i++) {
		cout << data[i].a << endl;
	}
	cout << "Stack ends." << endl;
}

ElemType::ElemType(char a) :a(a)
{
}
