#include <iostream>

using namespace std;

template <typename T> class Node;
template <typename T> class Chain;
template <typename T> class ChainIterator;

template <typename T>
class Node {
public:
	friend class Chain<T>;
	friend class ChainIterator<T>;
	Node(T element=0, Node<T> *next=0);
private:
	T data;
	Node *link;
};

template <typename T>
Node<T>::Node(T element, Node<T> *next) :
	data{ element }, link{ next } {}

template <typename T>
class Chain {
public:
	friend class ChainIterator<T>;
	Chain();
	void push(Node<T> *x, Node<T> *y);
	void push_back(const T& e);
	T pop(Node<T> *x, Node<T> *y);
	inline int Size() { return sz; }
	ChainIterator<T>& ITERATOR() { return *it; }
private:
	Node<T> *first, *last;
	Node<T> *av;
	int sz;
	ChainIterator<T> *it;
	Node<T> *GetNode();
};

template <typename T>
Chain<T>::Chain() :
	first{ 0 }, last{ 0 }, av{ 0 }, sz{ 0 }, it{	new ChainIterator<T>(first) } { }

template <typename T>
void Chain<T>::push(Node<T> *x, Node<T> *y) {
	if (first) {
		y->link = x->link;
		x->link = y;
	}
	else {
		first = x;
		y->link = x;
		x->link = y;
		delete it;
		it = new ChainIterator<T>(first);
	}
	if (x == last)
		last = y;
	sz++;
}

template <typename T>
void Chain<T>::push_back(const T& e) {
	Node<T> * buf = this->GetNode();
	buf->data = e;
	if (first) {
		buf->link = last->link;
		last->link = buf;
		last = buf;
	}
	else {
		first = buf;
		last = buf;
		buf->link = buf;
		delete it;
		it = new ChainIterator<T>(first);
	}
	sz++;
}

template <typename T>
T Chain<T>::pop(Node<T> *x, Node<T> *y) {
	T buf;
	buf = y->data;
	x->link = y->link;
	y->link = av;
	av = y;
	sz--;
	return buf;
}

template <typename T>
Node<T>* Chain<T>::GetNode() {
	Node<T> *buf;
	if (av) {
		buf = av;
		av = av->link;
	}
	else
		buf = new Node<T>;

	return buf;

}

template <typename T>
class ChainIterator {
public:
	friend class Chain<T>;
	ChainIterator(Node<T> *start = 0) { current = start; }
	inline T& operator*()const { return current->data; }
	inline T* operator->()const { return &current->data; }
	inline ChainIterator& operator++() { current = current->link; return *this; }
	inline Node<T>* CUR() { return current; }
	ChainIterator operator++(int) {
		ChainIterator old = *this;
		current = current->link;
		return old;
	}
	inline bool operator!=(const ChainIterator right)const { return current != right.current; }
	inline bool operator==(const ChainIterator right)const { return current == right.current; }
private:
	Node<T> *current;
};

int main(void) {
	Chain<int> a;
	Node<int> *buf1,*buf2;
	int n,m;
	cin >> n;
	cin >> m;
	for (int i = 1; i <= n; i++)
		a.push_back(i);
	cout << '<';
	while (a.Size()) {
		for (int i = 0; i < m - 1; i++)
			a.ITERATOR()++;
		buf2 = a.ITERATOR().CUR();
		for (int i = 0; i < a.Size() - 1; i++)
			a.ITERATOR()++;
		buf1 = a.ITERATOR()++.CUR();
		a.ITERATOR()++;
		cout << a.pop(buf1, buf2);
		if (a.Size() != 0)
			cout << ", ";
	}
	cout << ">\n";
	return 0;
}