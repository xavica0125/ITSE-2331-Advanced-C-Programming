#pragma once

template<class T> class List;

template<class T>
class Node
{
	friend class List<T>;

	template<class U>
	friend void displayList(const List<U>& list);
private:

	T data;
	Node<T>* next;

public:

	Node(const T& data) : data{ data }, next{ nullptr } {};

	T getData() const { return data; };

};

