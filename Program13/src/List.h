#pragma once

#include "Node.h"
#include <stdexcept>
#include <iostream>

using std::logic_error;

template<class T>
class List
{
	template<class U>
	friend void displayList(const List<U>& list);
private:

	Node<T>* headptr{ nullptr };
	Node<T>* lastptr{ nullptr };
	int nodeCounter = 0;

	Node<T>* getNewNode(const T& data)
	{
		Node<T>* newNode = new Node<T>(data);
		return newNode;
	}


public:

	void insertFront(const T& data)
	{
		Node<T>* newNode = getNewNode(data);

		if(this->isEmpty())
		{
			headptr = newNode;
			lastptr = newNode;
		}
		else
		{
			newNode->next = headptr;
			headptr = newNode;
		}
		nodeCounter++;
	}

	void insertEnd(const T& data)
	{
		Node<T>* newNode = getNewNode(data);
		if (this->isEmpty())
		{
			headptr = newNode;
			lastptr = newNode;
		}
		else
		{
			lastptr->next = newNode;
			lastptr = newNode;
		}
		nodeCounter++;
	}

	void deleteFront()
	{
		if (this->isEmpty())
		{
			throw logic_error("\nCan't delete element from empty list.\n");
		}
		else
		{
			Node<T>* tempptr = headptr;
			headptr = headptr->next;
			if (headptr == nullptr)
			{
				lastptr = nullptr;
			}
			delete tempptr;
			tempptr = nullptr;
			nodeCounter--;
		}
	}

	void deleteEnd()
	{
		if (this->isEmpty())
		{
			throw logic_error("\nCan't delete element from empty list.\n");
		}
		else
		{
			if (headptr != lastptr)
			{
				Node<T>* curptr = headptr;
				while (curptr->next != lastptr)
				{
					curptr = curptr->next;
				}
				Node<T>* tempptr = lastptr;
				lastptr = curptr;
				lastptr->next = nullptr;
				delete tempptr;
				tempptr = nullptr;
			}
			else
			{
				delete lastptr;
				headptr = lastptr = nullptr;
			}
			nodeCounter--;
		}
		
	}

	void insertIndexValue(const int val, const T& data)
	{
		if (val == 1)
		{
			insertFront(data);
		}
		else if (val > nodeCounter)
		{
			throw logic_error("\nIndex value entered is not within range of number of nodes in the list.\n");
		}
		else
		{
			int idxCounter = 1;
			Node<T>* curptr = headptr;

			while (idxCounter < val - 1)
			{
				curptr = curptr->next;
				idxCounter++;
			}
			Node<T>* newNode = getNewNode(data);
			newNode->next = curptr->next;
			curptr->next = newNode;
			nodeCounter++;
		}
		
	}

	void deleteNodeByVal(const T& val)
	{
		Node<T>* curptr = headptr;
		Node<T>* tempptr = nullptr;
		if (val == headptr->getData())
		{
			deleteFront();
		}
		else if (val == lastptr->getData())
		{
			deleteEnd();
		}
		else
		{
			while (curptr->next->getData() != val)
			{
				curptr = curptr->next;
				if (curptr == lastptr)
				{
					throw logic_error("\nValue not found in the list.\n");
				}
			}
			tempptr = curptr->next;
			curptr->next = tempptr->next;
			delete tempptr;
			tempptr = nullptr;
			nodeCounter--;
		}
	}

	bool isEmpty() const
	{
		bool isEmpty = false;
		if (headptr == nullptr && lastptr == nullptr)
		{
			isEmpty = true;
		}
		return isEmpty;
	}

};

template<class U>
void displayList(const List<U>& list)
{
	Node<U>* curptr = list.headptr;
	while (curptr != nullptr)
	{
		std::cout << curptr->getData() << " ";
		curptr = curptr->next;
	}
	std::cout << "\n";
}