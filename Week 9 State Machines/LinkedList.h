#pragma once
#include "iostream"

using namespace std;

template <class T>
class LinkedList {
private:
	T * Get(int i);
	int items;
public:
	T *first;
	LinkedList();
	~LinkedList();
	inline bool IsEmpty();
	inline void Insert(T *);
	void Display()const;
	T *Find(T * key)const;
	T *Delete();
	T *Delete(const int key);
	int Count();
	T * operator[](const int &i);
};


template <class T>
LinkedList<T>::LinkedList(){
	first = 0;
	items = 0;
}

template <class T>
LinkedList<T>::~LinkedList(){
	while (first != 0){
		delete Delete();
		cout << "Deleted" << endl;
	}
}



template <class T>
bool LinkedList<T>::IsEmpty(){
	return (first == 0);
}

template <class T>
void LinkedList<T>::Insert(T * newLink){
	newLink->next = first;
	first = newLink;
	items++;
}

template <class T>
void LinkedList<T>::Display()const {
	T *current = first;
	while (current != 0) {
		current->Display();
		current = current->next;
	}
}



template <class T>
T *LinkedList<T>::Find(T * key)const {
	T *current = first;
	while (*current != *key){
		if (current->next == 0)
			return 0;
		else
			current = current->next;
	}
	return current;
}

template <class T>
T *LinkedList<T>::Delete() {
	T *temp = first;
	first = first->next;
	items--;
	return temp;
}

template <class T>
T * LinkedList<T>::Get(int i){
	int count = 0;
	T *current = first;
	while (current != 0){
		if (count == i) return current;
		count++;
		current = current->next;
	}
	return 0;
}

template <class T>
T * LinkedList<T>::operator[](const int &i){
	return Get(i);
}


template <class T>
int LinkedList<T>::Count(){
	return items;
}