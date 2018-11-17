#include <iostream>
#include <vector>
using namespace std;

template <typename T> class Tree;
template <typename T> class TreeNode;

template <typename T>
class TreeNode {
public:
	friend class Tree<T>;
	TreeNode(T a = 0);
	inline void Set(T a) { data = a; }
	inline int size() { return child.size(); }
private:
	T data;
	TreeNode<T> *parent;
	vector<TreeNode<T>*> child;
/*	vector<int> weight;*/
	int pweight;
};

template <typename T>
TreeNode<T>::TreeNode(T a) :
	data{ a }, parent{ NULL }, pweight{ 0 } {}

template <typename T>
class Tree {
public:
	Tree(TreeNode<T> *a=0);
	void Insert(TreeNode<T> *parent, TreeNode<T> *son, int weight);
	int Level(TreeNode<T> *son);
	int Between(TreeNode<T> *a, TreeNode<T> *b);
private:
	TreeNode<T> *root;
	int Level(TreeNode<T> *root, TreeNode<T> *son);
};

template <typename T>
Tree<T>::Tree(TreeNode<T> *a) :
	root{ a } {}

template <typename T>
void Tree<T>::Insert(TreeNode<T> *parent, TreeNode<T> *son, int weight) {
	son->parent = parent;
	son->pweight = weight;
	parent->child.push_back(son);
/*	parent->weight.push_back(weight);*/
}

template <typename T>
int Tree<T>::Level(TreeNode<T> *son) {
	return Level(root, son);
}

template <typename T>
int Tree<T>::Level(TreeNode<T> *root, TreeNode<T> *son) {
	if (root == son)
		return 0;
	else
		return 1 + Level(root, son->parent);
}

template <typename T>
int Tree<T>::Between(TreeNode<T> *a, TreeNode<T> *b) {
	TreeNode<T> *it1 = a, *it2 = b;
	int sum = 0;
	while (Level(it1) > Level(it2)) {
		sum += it1->pweight;
		it1 = it1->parent;
	}
	while (Level(it1) < Level(it2)) {
		sum += it2->pweight;
		it2 = it2->parent;
	}
	while (it1 != it2) {
		sum += it1->pweight;
		sum += it2->pweight;
		it1 = it1->parent;
		it2 = it2->parent;
	}
	return sum;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, buf, max = 0;
	int d, l, r;
	int *leaf;
	TreeNode<int> *Nodelist;
	cin >> n;
	Nodelist = new TreeNode<int>[n];
	leaf = new int[n];
	fill_n(leaf, n, 1);
	for (int i = 0; i < n; i++)
		Nodelist[i].Set(i + 1);
	Tree<int> MyTree(Nodelist);
	for (int i = 0; i < n - 1; i++) {
		cin >> d >> l >> r;
		MyTree.Insert(&Nodelist[d - 1], &Nodelist[l - 1], r);
		leaf[d - 1] = 0;
	}

	leaf[0] = (Nodelist[0].size() < 2);

	for (int i = 0; i < n - 1; i++)
		for (int m = i + 1; m < n; m++)
			if (leaf[i] && leaf[m]) {
				buf = MyTree.Between(&Nodelist[i], &Nodelist[m]);
				if (max < buf)
					max = buf;
			}
	cout << max << endl;
	return 0;
}