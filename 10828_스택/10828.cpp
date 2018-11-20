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
		copy(a, a + number, temp);
		delete[] a;
		a = temp;
	}
	catch (char *e) {
		cout << e << endl;
	}
}

int main(void) {
	
	ios::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Stack a;
	int l,buf;
	char s[6] = { 0, };
	cin >> l;
	for (int i = 0; i < l; i++) {
		cin >> s;
		if (!strcmp(s, "push")) {
			cin >> buf;
			a.Push(buf);
		}
		else if (!strcmp(s, "pop"))
			cout << a.Pop() << '\n';
		else if (!strcmp(s, "top"))
			cout << a.Top() << '\n';
		else if (!strcmp(s, "empty"))
			cout << a.IsEmpty() << '\n';
		else if (!strcmp(s, "size"))
			cout << a.Size() << '\n';
	}

	return 0;
}