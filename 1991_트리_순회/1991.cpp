#include <iostream>

using namespace std;

template <typename T> class BinaryTree;
template <typename T> class TreeNode;

template <typename T>
class TreeNode {
public:
	friend class BinaryTree<T>;
	TreeNode(T a = 0);
	inline void Set(T a) { data = a; }
private:
	T data;
	TreeNode<T> *leftchild;
	TreeNode<T> *rightchild;
};

template <typename T>
TreeNode<T>::TreeNode(T a) :
	data{ a }, leftchild{ NULL }, rightchild{ NULL } {}

template <typename T>
class BinaryTree {
public:
	BinaryTree(TreeNode<T> *a=0);
	inline bool IsEmpty() { return sz == 0; }
	inline BinaryTree<T> LeftSubtree() { return *root->leftchild; }
	inline BinaryTree<T> RightSubtree() { return *root->rightchild;}
	inline T RootData() { return root->data; }
	void Insertleft(TreeNode<T> *parent, TreeNode<T> *son);
	void Insertright(TreeNode<T> *parent, TreeNode<T> *son);
	inline void Inorder() { Inorder(root); }
	inline void Preorder() { Preorder(root); }
	inline void Postorder() { Postorder(root); }
private:
	TreeNode<T> *root;
	int sz;
	void Inorder(TreeNode<T> *currentNode);
	void Preorder(TreeNode<T> *currentNode);
	void Postorder(TreeNode<T> *currentNode);
	inline void Visit(TreeNode<T> *currentNode) { cout << currentNode->data; }
};

template <typename T>
BinaryTree<T>::BinaryTree(TreeNode<T> *a) :
	root{ a }, sz{ a != NULL } {}

/*template <typename T>
BinaryTree<T>::BinaryTree(BinaryTree<T>& bt1, T& item, BinaryTree<T>& bt2) :
{
	root->data = item;
	root->leftchild = &bt1;
	root->rightchild = &bt2;
	sz = bt1->sz + bt2->sz + 1;
}*/

template <typename T>
void BinaryTree<T>::Insertleft(TreeNode<T> *parent, TreeNode<T> *son) {
	son->leftchild = parent->leftchild;
	parent->leftchild = son;
	sz++;
}

template <typename T>
void BinaryTree<T>::Insertright(TreeNode<T> *parent, TreeNode<T> *son) {
	son->rightchild = parent->rightchild;
	parent->rightchild = son;
	sz++;
}

template <typename T>
void BinaryTree<T>::Inorder(TreeNode<T> *currentNode) {
	if (currentNode) {
		Inorder(currentNode->leftchild);
		Visit(currentNode);
		Inorder(currentNode->rightchild);
	}
}
template <typename T>
void BinaryTree<T>::Preorder(TreeNode<T> *currentNode) {
	if (currentNode) {
		Visit(currentNode);
		Preorder(currentNode->leftchild);
		Preorder(currentNode->rightchild);
	}
}
template <typename T>
void BinaryTree<T>::Postorder(TreeNode<T> *currentNode) {
	if (currentNode) {
		Postorder(currentNode->leftchild);
		Postorder(currentNode->rightchild);
		Visit(currentNode);
	}
}

int main(void) {
	int n;
	char d, l, r;
	TreeNode<char> *Nodelist;
	cin >> n;
	Nodelist = new TreeNode<char>[n];
	for (int i = 0; i < n; i++)
		Nodelist[i].Set('A' + i);
	BinaryTree<char> MyTree(Nodelist);
	for (int i = 0; i < n; i++) {
		cin >> d >> l >> r;
		if (l != '.')
			MyTree.Insertleft(&Nodelist[d - 65] ,&Nodelist[l - 65]);
		if( r != '.')
			MyTree.Insertright(&Nodelist[d - 65], &Nodelist[r - 65]);
	}
	MyTree.Preorder();
	cout << endl;
	MyTree.Inorder();
	cout << endl;
	MyTree.Postorder();
	return 0;
}