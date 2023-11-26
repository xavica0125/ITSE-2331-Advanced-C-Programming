#pragma once

#include "Node.h"
#include <stdexcept>
#include <iostream>

using std::logic_error; using std::invalid_argument;

template<class T>
class List
{
	template<class U>
	friend void displayList(const List<U>& list);
private:

	Node<T>* headptr{ nullptr };
	Node<T>* lastptr{ nullptr };
	int nodeCounter = 0;
	bool isSorted = false;

	Node<T>* getNewNode(const T& data)
	{
		Node<T>* newNode = new Node<T>(data);
		return newNode;
	}

	Node<T>* getMid(Node<T>* head)
	{
		Node<T>* slow = head;
		Node<T>* fast = head->next;

		while (fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
	}

	Node<T>* merge(Node<T>* left, Node<T>* right)
	{
		Node<T>* dummy = getNewNode(0);
		Node<T>* curptr = dummy;
		while (left && right)
		{
			if (left->getData() < right->getData())
			{
				curptr->next = left;
				left = left->next;
			}
			else
			{
				curptr->next = right;
				right = right->next;
			}
			curptr = curptr->next;
		}
		if (left)
		{
			curptr->next = left;
		}
		if (right)
		{
			curptr->next = right;
		}

		return dummy->next;
	}

	void updateLastPtr()
	{
		Node<T>* curptr = headptr;
		while (curptr->next != nullptr)
		{
			curptr = curptr->next;
		}
		lastptr = curptr;
	}

	Node<T>* getMidBinarySearch(Node<T>* start, Node<T>* end)
	{
		Node<T>* slow = start;
		Node<T>* fast = start->next;

		while (fast != end && fast->next != end)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
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

	bool linearSearch(const T& val)
	{
		updateLastPtr();
		Node<T>* curptr = headptr;
		bool foundValue = false;

		while (curptr->getData() != val)
		{
			if (curptr == lastptr)
			{
				throw invalid_argument("Value not present in list.");
			}
			curptr = curptr->next;
		}
		foundValue = true;
		return foundValue;
	}

	void selectionSort()
	{
		if (this->isEmpty() || nodeCounter == 1)
		{
			throw logic_error("\nCan't sort an empty list or a list with only one node.\n");
		}

		Node<T>* curptr = headptr;

		while (curptr != nullptr)
		{
			Node<T>* innerLoopPtr = curptr;
			Node<T>* smallestVal = curptr;

			while (innerLoopPtr != nullptr)
			{
				if (innerLoopPtr->getData() < smallestVal->getData())
				{
					smallestVal = innerLoopPtr;
				}
				innerLoopPtr = innerLoopPtr->next;
			}

			T temp = curptr->getData();
			curptr->data = smallestVal->getData();
			smallestVal->data = temp;

			curptr = curptr->next;

			isSorted = true;
			updateLastPtr();
		}
	}

	Node<T>* mergeSort(Node<T>* head)
	{
		if (head == nullptr || head->next == nullptr)
		{
			return head;
		}

		Node<T>* left = head;
		Node<T>* right = getMid(head);
		Node<T>* temp = right->next;
		right->next = nullptr;
		right = temp;

		left = mergeSort(left);
		right = mergeSort(right);

		Node<T>* sortedList = merge(left, right);

		headptr = sortedList;

		isSorted = true;
		updateLastPtr();

		return sortedList;
	}

	Node<T>* getHeadPtr() const
	{
		return headptr;
	}

	bool binarySearch(const T& val)
	{
		if (isEmpty())
		{
			throw logic_error("\nCan't search an empty list.\n");
		}
		else if (!isSorted)
		{
			throw logic_error("\nCan't search an unsorted list.\n");
		}
		else
		{
			updateLastPtr();
			bool foundValue = false;

			Node<T>* start = headptr;
			Node<T>* end = lastptr;

			while (!foundValue && start != end)
			{
				Node<T>* mid = getMidBinarySearch(start, end);
				if (start->getData() == val || end->getData() == val)
				{
					foundValue = true;
				}
				else if (mid->getData() == val)
				{
					foundValue = true;
				}
				else if (mid->getData() < val)
				{
					start = mid->next;
				}
				else
				{
					Node<T>* curptr = start;
					while (curptr->next != mid)
					{
						curptr = curptr->next;
					}
					end = curptr;
				}
			}
			return foundValue;
		}
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
