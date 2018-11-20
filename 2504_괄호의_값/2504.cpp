#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <cstring>

using namespace std;

template <typename T> class Stack;
template <typename T> void ChangeSize1D(T*& a, const int oldSize, const int newSize);

template <typename T>
class Stack {
public:
	Stack(int stackCapacity = 10);
	int IsEmpty() const;
	inline int Size() { return top + 1; }
	T Top()const;
	void Push(const T& item);
	T Pop();
private:
	T *stack;
	int top;
	int capacity;
};

template <typename T>
Stack<T>::Stack(int stackCapacity) :
	capacity(stackCapacity) {
	try {
		if (capacity < 1)
			throw "Stack capacity must be>0";
	}
	catch (const string e) {
		cout << e.data() << endl;
	}
	stack = new T[capacity];
	top = -1;
}

template <typename T>
inline int Stack<T>::IsEmpty()const { return top == -1; }

template <typename T>
inline T Stack<T>::Top()const {
	if (IsEmpty())
		return -1;
	return stack[top];
}

template <typename T>
void Stack<T>::Push(const T& x) {
	if (top == capacity - 1) {
		ChangeSize1D(stack, capacity, 2 * capacity);
		capacity *= 2;
	}
	stack[++top] = x;
}

template <typename T>
T Stack<T>::Pop() {
	if (IsEmpty())
		return -1;
	return stack[top--];
}

template <typename T>
void ChangeSize1D(T*& a, const int oldSize, const int newSize) {
	try {
		if (newSize < 0)
			throw "New length must be >= 0";
		T* temp = new T[newSize];
		int number = min(oldSize, newSize);
		copy(a, a + number, temp);
		delete[] a;
		a = temp;
	}
	catch (char *e) {
		cout << e << endl;
	}
}

int main(void) {
	Stack<int> a;
	Stack<char> b;
	char input;
	int buf = 0, size = 0;
	while (input = getchar()) {
		buf = 0;
		if (input == ')') {
			while (b.Top() == 0) {
				b.Pop();
				buf += a.Pop();
			}
			if (b.Pop() == '(') {
				if (buf == 0)
					a.Push(2);
				else
					a.Push(buf * 2);
				b.Push(0);
			}
			else {
				cout << 0 << endl;
				return 0;
			}
		}
		else if (input == ']') {
			while (b.Top() == 0) {
				b.Pop();
				buf += a.Pop();
			}
			if (b.Pop() == '[') {
				if (buf == 0)
					a.Push(3);
				else
					a.Push(buf * 3);
				b.Push(0);
			}
			else {
				cout << 0 << endl;
				return 0;
			}
		}
		else if (input == '\n' || input == EOF || input == '\0')
			break;
		else
			b.Push(input);
		buf = 0;
	}

	while (a.Size()) {
		b.Pop();
		buf += a.Pop();
	}

	if (a.Size() == 0 && b.Size() != 0)
		buf = 0;

	cout << buf << '\n';

	return 0;
}