#pragma once

#include <vector>
#include <stdexcept>

using std::vector; using std::logic_error;

template<class T>
class Stack
{
	private:
		
		vector<T> stack;

	public:

		void push(const T& pushValue) 
		{
			stack.push_back(pushValue);
		}

		T pop()
		{
			if (this->isEmpty())
			{
				throw logic_error("Stack is empty. Cannot pop empty stack.");
			}
			else
			{
				T poppedElement = stack.back();
				stack.pop_back();
				return poppedElement;
			}
		}
		
		bool isEmpty() const
		{
			return stack.empty();
		}

		T top() const
		{
			if (this->isEmpty())
			{
				throw logic_error("Stack is empty. Cannot retrieve top element of empty stack.");
			}
			else
			{
				return stack.back();
			}
		}

		void clearStack()
		{
			stack.clear();
		}
};