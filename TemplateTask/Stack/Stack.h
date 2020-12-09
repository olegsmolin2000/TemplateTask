#include<iostream>
using namespace std;
#pragma once

template<typename T>
class Stack;

template<typename T>
Stack<T> StackUnion(const Stack<T>& first, const Stack<T>& second);

template<typename T>
class Stack
{
private:
	int size;
	int head;
	T* array;
public:
	Stack(int maxSize) {
		this->size = maxSize;
		this->head = 0;
		this->array = new T[size];
	}

	//конструктор копирования
	Stack(const Stack<T>& other) {
		this->size = other.size;
		this->head = other.head;
		this->array = new T[size];
		copy(other.array, other.array + other.size, this->array);
	}

	//освобождение памяти при деструкторе
	~Stack() {
		delete[]array;
	}

	void push(T newValue) {
		if (head >= size)
			throw "Stack is full";
		else
			array[head++] = newValue;
	}

	T pop() {
		if (head > 0)
			return array[--head];
		else
			throw "Stack is empty";
	}

	void printStack() {
		for (int i = 0; i < head; i++)
			cout << array[i] << "\t";
		cout << endl;
	}

	friend  Stack StackUnion<T>(const Stack<T>& first, const Stack<T>& second);
};

template<typename T>
Stack<T> StackUnion(const Stack<T>& first, const Stack<T>& second) {
	//создание нового стека где ёмкость это сумма размеров объединяемых стеков
	Stack<T> result = Stack<T>(first.size + second.size);

	//копирование заполненных элементов первого стека
	while (result.head < first.head)
		result.push(first.array[result.head]);
	
	//копирование из второго стека
	while (result.head - first.head < second.head)
		result.push(second.array[result.head - first.head]);

	return result;
}