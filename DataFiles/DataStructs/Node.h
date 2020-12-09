#ifndef NODE_H
#define NODE_H
#include <vector>
using namespace std;

template <class T>
struct Node
{
	T value;
	vector <T> list;
	Node* left;
	Node* right;
	int height;

	Node();
	Node(T val);
	Node(T val, T item);
	Node(T val, vector<T> items);
};

template <class T>
Node<T>::Node(T val)
{
	value = val;
	left = nullptr;
	right = nullptr;
	list = {};
	height = 1;
}

template <class T>
Node<T>::Node(T val, T item)
{
	value = val;
	left = nullptr;
	right = nullptr;
	list = { item };
	height = 1;
}

template <class T>
Node<T>::Node(T val, vector<T> items)
{
	value = val;
	left = nullptr;
	right = nullptr;
	list = items;
	height = 1;
}
#endif