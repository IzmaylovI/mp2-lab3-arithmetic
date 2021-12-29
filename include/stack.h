#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>
#include <cmath>

using namespace std;

template <typename ValType>
void _swap_(ValType *left, ValType *right) 
{
	ValType *p = left;
	left = right;
	right = p;
}

template <typename ValType>
class Stack {
private:
	int Top; 
	int Size;                            //масимальное допустимое количество элеменитов в стеке                           //
	ValType* pVector;
public:
	Stack();
	Stack(int Size_t);
	Stack(int Size_t, ValType elem);
	Stack(const Stack& st);
	~Stack();
	int getSize() { return Size; };
	int count() { return Top + 1; };
	bool isEmpty();
	bool isFull();
	void push(ValType elem);
	ValType pop();
	ValType peek();
	ValType reverse();

	bool operator==(const Stack& right) const;
	Stack& operator=(Stack &St);
};

template <typename ValType>
Stack<ValType>:: Stack()
	: Size(10)
	, Top(-1)
	, pVector(new ValType[Size])
{}

template <typename ValType>
Stack<ValType>:: Stack(int Size_t)
	: Top(-1)
{
	if (Size_t < 0)
	{
		throw exception("Error: negative size");
	}

	Size = Size_t;
	pVector = new ValType[Size];
}

template <typename ValType>
Stack<ValType>::Stack(const Stack& st)
	: Size(st.Size)
	, Top(st.Top)
{
	pVector = new ValType[Size]{};

	for (int i = 0; i <= Top; i++)
	{
		pVector[i] = st.pVector[i];
	}
}

template<typename ValType>
Stack<ValType>:: ~Stack() 
{
	delete[] pVector;
}

/*
template <typename Valtype>
int count() {
	return Top + 1;
}
*/

template <typename ValType>
bool Stack<ValType>:: isEmpty() {
	return (Top == -1) ? 1 : 0;
}
template <typename ValType>
bool Stack<ValType>:: isFull() 
{
	return (Top == Size - 1) ? 1 : 0;
}

template <typename ValType>
void Stack<ValType>:: push(ValType elem) 
{
	if (!isFull()) 
	{
		pVector[++Top] = elem;
	}
	else 
	{
		ValType* vspom = new ValType[Size * 2]{};
		Size *= 2;
		for (int i = 0; i < Size; i++) {
			vspom[i] = pVector[i];
		}

		vspom[++Top] = elem;
		_swap_(vspom, pVector);
	}
}

template<typename ValType>
ValType Stack<ValType>:: pop()
{
	if (isEmpty())
	{
		throw exception("Error: stack_is_empty");
	}
	
	return pVector[Top--];
}

template <typename ValType>
ValType Stack<ValType>:: peek() 
{
	if (!isEmpty()) 
	{    
		return pVector[Top];
	}
}

template <typename ValType>
bool Stack<ValType>:: operator==(const Stack<ValType>& right) const
{
	bool flag = 1;
	if (Top == right.Top)
	{
		if (Size == right.Size)
		{
			for (int i = 0; i <= Top; i++)
			{
				if (pVector[i] != right.pVector[i])
				{
					flag = 0;
					break;
				}
			}
		}
		else
		{
			flag = 0;
		}
	}
	else
	{
		flag = 0;
	}

	return flag;
}

template <typename ValType>
Stack<ValType>& Stack<ValType>::operator=(Stack<ValType> &St)
{
	if (Size != St.Size)
	{
		delete[] pVector;
		pVector = new ValType[Size]{};
	}
	
	Top = St.Top;

	for (int i = 0; i <= Top; i++)
	{
		pVector[i] = St.pVector[i];
	}

	return *this;
}

#endif