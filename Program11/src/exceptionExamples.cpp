#include "exceptionExamples.h"

void divByZero(int x, int y)
{
	int result; 
	try 
	{
		if (y == 0)
		{
			throw invalid_argument("\nException thrown: Denominator can't be zero\n\n");
		}
		else
		{
			result = x / y;
		}

		cout << x << " / " << y << " = " << result << "\n";
	}
	catch (invalid_argument& e)
	{
		cout << e.what();
	}
}

void rethrowException()
{
	int operand1;
	int operand2;

	try
	{
		cout << "\nEnter values for operand 1: ";
		cin >> operand1;
		cout << "\nEnter values for operand 2: ";
		cin >> operand2;

		cout << operand1 << " * " << operand2 << " = " << rethrowExceptionHelper(operand1, operand2) << "\n";
	}
	catch (invalid_argument& e)
	{
		throw;
	}
}

int rethrowExceptionHelper(int x, int y)
{
	if (x <= 0 || y <= 0)
	{
		throw invalid_argument("\nException thrown: Operands must be greater than 0.\n");
	}
	else
	{
		return x * y;
	}
}

void stackUnwind(int x)
{
	try
	{
		cout << "\nCalling stackHelper function 1...\n";
		stackHelper1(x);


	}
	catch (invalid_argument& e)
	{
		cout << e.what() << "\n";
	}
}

void stackHelper1(int x)
{
	cout << "\nCalling stackHelper function 2...\n";
	stackHelper2(x);

}

void stackHelper2(int x)
{
	if (x <= 0)
	{
		cout << "\nNo try block, stack unwind begins...\n";
		throw invalid_argument("\nInteger must be greater than 0\n");
	}
	else
	{
		cout << "\nValid argument passed.\n";
	}

}

void badAllocException()
{
	try
	{
		int* ptr = new int[1000000000];
		delete[] ptr;
		cout << "\nAllocation successful\n\n";

	}
	catch (bad_alloc& e)
	{
		cout << e.what() << "\n";
	}
}

void setNewHandler()
{
	set_new_handler(customNewHandler);
	
	int* ptr = new int[1000000000];
	delete[] ptr;
	cout << "\nAllocation successful\n\n";

}

void customNewHandler()
{
	cerr << "customNewHandler function is called\n";
	exit(EXIT_FAILURE);
}




