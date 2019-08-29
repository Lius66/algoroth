#include<iostream>
#include<vector>
#include<time.h>
#include<algorithm>
using namespace std;
vector<int> nums(30, 0);
void init_nums();
void out_put();

void quick_sort(vector<int>& A, const int& p, const int& q);
int partition(vector<int>&A, const int& p, const int& q);

void insert_sort(vector<int>&A);

void merge_sort(vector<int>&A, const int& p, const int& q);
void merge(vector<int>&A, const int&p, const int&q, const int&r);

int left(const int& i);
int right(const int& i);
int parent(const int& i);
void max_heapify(vector<int>&A, const int & i,const int& n);
void build_max_heap(vector<int>&A);

int main1() {

	init_nums();
	out_put();
	build_max_heap(nums);
	//merge_sort(nums, 0, nums.size() - 1);
	//insert_sort(nums);
	//quick_sort(nums, 0, nums.size() - 1);
	out_put();
	system("pause");
	return 0;
}

void init_nums()
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < 30; i++) {
		nums[i] = rand() % 1000;
	}
}

void quick_sort(vector<int>& A, const int & p, const int & q)
{
	if (p < q)
	{
		int r = partition(A, p, q);
		quick_sort(A, p, r - 1);
		quick_sort(A, r + 1, q);
	}
}

int partition(vector<int>& A, const int & p, const int & q)
{
	int x = A[q];
	int i = p - 1;
	for (int j = p; j < q; j++) {
		if (A[j] <= x) {
			i++;
			swap(A[i], A[j]);
		}
	}
	i++;
	swap(A[q], A[i]);
	return i;
}

void insert_sort(vector<int>& A)
{
	int n = A.size();
	for (int j = 1; j < n; j++) {
		int key = A[j];
		int i = j - 1;
		while (i > -1 && A[i] > key) {
			A[i + 1] = A[i];
			i--;
		}
		A[i + 1] = key;
	}
}

void out_put()
{
	for (auto mem : nums) {
		cout << mem << " ";
	}
	cout << endl;
}

void merge_sort(vector<int>& A, const int & p, const int & q)
{
	if (p < q) {
		int r = (p + q) / 2;
		merge_sort(A, p, r);
		merge_sort(A, r + 1, q);
		merge(A, p, q, r);
	}
}

void merge(vector<int>& A, const int & p, const int & q, const int & r)
{
	int n1 = r - p + 1;
	int n2 = q - r;
	vector<int>L(n1, 0);
	vector<int>R(n2, 0);
	for (int i = 0; i < n1; i++)
		L[i] = A[p + i];
	for (int i = 0; i < n2; i++)
		R[i] = A[r + 1 + i];
	int a = 0, b = 0, c = p;
	while ( a < n1&&b < n2) {
		if (L[a] <= R[b])
			A[c++] = L[a++];
		else
			A[c++] = R[b++];
	}
	while (a < n1) {
		A[c++] = L[a++];
	}
	while (b < n2) {
		A[c++] = R[b++];
	}
}
int left(const int& i) {
	return 2*(i+1)-1;
}
int right(const int& i) {
	return 2 * (i + 1);
}
int parent(const int& i) {
	return (i - 1) / 2;
}
void max_heapify(vector<int>& A, const int & i,const int& n)
{
	//int n = A.size();
	int l = left(i);
	int r = right(i);
	int largest = i;
	if (l<n&&A[l]>A[i]) {
		largest = l;
	}
	if (r<n&&A[r]>A[largest]) {
		largest = r;
	}
	if (largest != i) {
		swap(A[i], A[largest]);
		max_heapify(A, largest,n);
	}
}

void build_max_heap(vector<int>& A)
{
	for (int i = (A.size() / 2 - 1); i > -1; i--) {
		max_heapify(A, i,A.size());
	}
	int n = A.size();
	for (int i = A.size() - 1; i > 0; i--) {
		swap(A[i], A[0]);
		n--;
		max_heapify(A, 0, n);
	}
}


