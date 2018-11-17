#include <iostream>
#include <iterator>
#include <algorithm>
#include <cstring>


using namespace std;

template <typename T> class Queue;

template <typename T>
class Queue {
public:
	Queue(int queueCapacity = 10);
	bool IsEmpty()const { return front == rear; }
	T Front()const {
		if (IsEmpty())
			return -1;
		return queue[(front + 1) % capacity];

	}
	T Pop() {
		int buf;
		if (IsEmpty())
			return -1;
		buf = queue[(front + 1) % capacity];
		front++;
		sz--;
		return buf;

	}
	T Rear()const {
		if (IsEmpty())
			return -1;
		return queue[rear];
	}
	int Size() { return sz; }
	void Push(const T& item);
private:
	T *queue;
	int front, rear, capacity, sz;
};

template <typename T>
Queue<T>::Queue(int queueCapacity) :
	capacity(queueCapacity) {
	queue = new T[capacity];
	front = rear = sz = 0;
}

template <typename T>
void Queue<T>::Push(const T& x) {
	if ((rear + 1) % capacity == front) {
		T *newQueue = new T[2 * capacity];
		int start = (front + 1) % capacity;
		if (start < 2)
			copy(queue + start, queue + start + capacity - 1, newQueue);
		else {
			copy(queue + start, queue + capacity, newQueue);
			copy(queue, queue + rear + 1, newQueue + capacity - start);
		}

		front = 2 * capacity - 1;
		rear = capacity - 2;
		capacity *= 2;
		delete[] queue;
		queue = newQueue;
	}
	rear = (rear + 1) % capacity;
	queue[rear] = x;
	sz++;
}

int main(void) {

	Queue<int> *a,*b;
	int input,T,index,buf=0,it,count=0,k;

	cin >> input;
	for (int i = 0; i < input; i++) {
		a = new Queue<int>;
		b = new Queue<int>;
		cin >> T;
		cin >> index;
		for (int m = 0; m < T; m++) {
			cin >> buf;
			a->Push(buf);
			b->Push(m);
		}
		while (a->Size() > 0) {
			buf = 0;
			for (int m = 0; m < a->Size(); m++) {
				if (buf < a->Front())
					buf = a->Front();
				it = a->Pop();
				a->Push(it);
			}
			while(a->Front() < buf) {
				k = a->Pop();
				a->Push(k);
				k = b->Pop();
				b->Push(k);
			}
			a->Pop();
			if (b->Pop() == index)
				break;
			count++;
		}
		cout << count+1<<'\n';
		count = 0;
		delete a;
		delete b;
	}
}