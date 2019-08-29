#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<time.h>
using namespace std;

struct BTree
{
	int val;
	BTree* left;
	BTree* right;
	BTree(int n) :val(n), left(NULL), right(NULL) {}
};

void insert_BTree(BTree* node, const int& v) {
		if (!node->left)
			node->left = new BTree(v);
		else if(!node->right)
			node->right = new BTree(v);
		else
		{
			if (rand() % 10 > 5)
				insert_BTree(node->left, v);
			else
				insert_BTree(node->right, v);
		}
}

void pre_order(BTree* node) {
	if (!node)
		return;
	cout << node->val<<" ";
	pre_order(node->left);
	pre_order(node->right);
}
void pre_order1(BTree* node) {
	if (!node)
		return;
	stack<BTree*> st;
	st.push(node);
	while (!st.empty()) {
		auto key = st.top();
		st.pop();
		cout << key->val << " ";
		if (key->right)
			st.push(key->right);
		if (key->left)
			st.push(key->left);
	}
}
void level_order(BTree* node) {
	if (!node)
		return;
	queue<BTree*>que;
	que.push(node);
	while (!que.empty()) {
		auto key = que.front();
		que.pop();
		cout << key->val<<" ";
		if (key->left)
			que.push(key->left);
		if (key->right)
			que.push(key->right);
	}

}

void in_order(BTree* node) {
	if (!node)
		return;
	in_order(node->left);
	cout << node->val << " ";
	in_order(node->right);
}
void in_order1(BTree* node) {
	if (!node)
		return;
	stack<BTree*> st;
	while (node || !st.empty()) {
		if (node) {
			st.push(node);
			node = node->left;
		}
		else {
			node = st.top();
			cout << node->val << " ";
			st.pop();
			node = node->right;
		}
	}
}
void post_order(BTree* node) {
	if (!node)
		return;
	post_order(node->left);
	post_order(node->right);
	cout << node->val << " ";
}
void post_order1(BTree* node) {
	if (!node)
		return;
	stack<BTree*> st1;
	stack<BTree*> st2;
	st1.push(node);
	while (!st1.empty()) {
		auto key = st1.top();
		st1.pop();
		st2.push(key);
		if (key->left)
			st1.push(key->left);
		if (key->right)
			st1.push(key->right);
	}
	while (!st2.empty()) {
		cout << st2.top()->val << " ";
		st2.pop();
	}
}
int main() {
	int n;
	cin >> n;
	srand((unsigned)time(NULL));
	auto node = new BTree(0);
	for (int i = 0; i < n; i++) {
		int v = rand() % 20;
		insert_BTree(node, v);
	}
	cout << "    层次遍历： ";
	level_order(node);
	cout << endl;
	cout << "递归先序遍历： ";
	pre_order(node);
	cout << endl;
	cout << "    先序遍历： ";
	pre_order1(node);
	cout << endl;
	cout << "递归中序遍历： ";
	in_order(node);
	cout << endl;
	cout << "    中序遍历： ";
	in_order1(node);
	cout << endl;
	cout << "递归后续遍历： ";
	post_order(node);
	cout << endl;
	cout << "    后续遍历： ";
	post_order1(node);
	cout << endl;

	system("pause");
	return 0;
}