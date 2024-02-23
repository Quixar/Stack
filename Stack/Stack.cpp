#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool check_brakets(string expression) {
	stack<char> brakets;

	for (char c : expression) {
		if (c == '{' || c == '(' || c == '[' || c == '<') {
			brakets.push(c);
		}
		else if (c == '}' || c == ')' || c == ']' || c == '>') {
			if (brakets.empty()) {
				return false;
			}
			char top = brakets.top();

			if ((c == '}' and top != '{') || (c == ']' and top != '[') || (c == ')' and top != '(') || (c == '>' and top != '<')) {
				return false;
			}
			brakets.pop();
		}
	}
	return brakets.empty();
}

int main()
{
	string expression = "{(5-[3+<9>])-4}";

	if (check_brakets(expression)) {
		cout << "ok";
	}
	else {
		cout << "no";
	}
}

class Stack
{
	static const int SIZE = 10; // количество элементов в стеке (при желании можно поменять)

	int ar[SIZE]; // обычно реализуется как статический массив
	int index = 0; // индекс, по которому будет добавляться очередной новый элемент
	// также индекс можно воспринимать как количество элементов, которые были добавлены в стек на данный момент

public:
	void Clear()
	{
		index = 0;
	}

	bool IsEmpty() const
	{
		return index == 0;
	}

	bool IsFull() const
	{
		return index == SIZE;
	}

	int GetCount() const
	{
		return index;
	}

	void Push(int value)
	{
		if (!IsFull())
		{
			ar[index++] = value;
		}
		else
		{
			throw "Stack overflow!";
		}
	}

	int Pop()
	{
		if (!IsEmpty())
		{
			return ar[--index];
		}
		else
		{
			throw "Stack is empty!";
		}
	}

	int Peek()
	{
		if (!IsEmpty())
		{
			return ar[index - 1];
		}
		else
		{
			throw "Stack is empty!";
		}

	}

	bool Contains(int value)
	{
		for (int i = 0; i < index; i++)
		{
			if (ar[i] == value)
			{
				return true;
			}
		}
		return false;
	}

	void PushLessValue(int value)
	{
		if (value <= ar[index - 1])
		{
			Push(value);
		}
	}

	void PushUnique(int value)
	{
		if (Contains(value))  return;
		Push(value);
	}
};