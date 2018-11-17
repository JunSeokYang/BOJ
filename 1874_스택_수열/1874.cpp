#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <cstring>

using namespace std;

class Stack;
void ChangeSize1D(int*& a, const int oldSize, const int newSize);

class Stack {
public:
	Stack(int stackCapacity = 10);
	int IsEmpty() const;
	inline int Size() { return top + 1; }
	int Top()const;
	void Push(const int& item);
	int Pop();
private:
	int *stack;
	int top;
	int capacity;
};

Stack::Stack(int stackCapacity) :
	capacity(stackCapacity) {
	try {
		if (capacity < 1)
			throw "Stack capacity must be>0";
	}
	catch (const string e) {
		cout << e.data() << endl;
	}
	stack = new int[capacity];
	top = -1;
}

inline int Stack::IsEmpty()const { return top == -1; }

inline int Stack::Top()const {
	if (IsEmpty())
		return -1;
	return stack[top];
}

void Stack::Push(const int& x) {
	if (top == capacity - 1) {
		ChangeSize1D(stack, capacity, 2 * capacity);
		capacity *= 2;
	}
	stack[++top] = x;
}

int Stack::Pop() {
	if (IsEmpty())
		return -1;
	return stack[top--];
}

void ChangeSize1D(int*& a, const int oldSize, const int newSize) {
	try {
		if (newSize < 0)
			throw "New length must be >= 0";
		int* temp = new int[newSize];
		int number = min(oldSize, newSize);
		copy(a, a + number,  temp );
		delete[] a;
		a = temp;
	}
	catch (char *e) {
		cout << e << endl;
	}
}

int main(void) {
	
	int l, count = 1, flag = 0;
	int buf;
	Stack a;
	string p, q;
	cin >> l;
	getchar();
	for (int i = 1; i <= l; i++) {
		cin >> buf;
		while (a.Top() < buf) {
			a.Push(count++);
			p.append("+");
		}
		if (a.Top() == buf) {
			a.Pop();
			p.append("-");
		}
		else
			flag = 1;
	}
	if (flag == 0)
		for (int i = 0; i < p.length(); i++)
			cout << p.at(i) << '\n';
	else
		cout << "NO\n";



	return 0;
}