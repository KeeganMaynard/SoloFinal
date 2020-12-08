#ifndef AVL_H
#define AVL_H
#include "Node.h"
#include "Encryption.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;

template <class T>
class AVLtree
{
private:
	Node<T>* root;
	int count;				//tracks the number of nodes in the tree
	int itemCount;

protected:
	//might move these into private later
	int Height(Node<T>*& subRoot);
	int Balance(Node<T>* subRoot);
	int leafs(Node<T>* subRoot);
	void midpoints(vector<Node<T>*>& list, int front, int end);
	void delSubRoot(Node<T>*& subRoot);
	Node<T>* insertAssist(Node<T>*& subRoot, Node<T>*& newRoot);
	Node<T>* insertItemAssist(Node<T>*& subRoot, Node<T>*& newRoot);
	Node<T>* delAssist(Node<T>*& subRoot, T value);
	Node<T>* delItemAssist(Node<T>*& subRoot, T value, T item);
	Node<T>* searchAssist(T val, Node<T>* subRoot);
	void displaySystemAdmins(Node<T>* subRoot);
	void displayOfficials(Node<T>* subRoot);
	void displayMembers(Node<T>* subRoot);
	void displayItems(Node<T>* subRoot);
	void rotate(Node<T>*& subRoot);
	Node<T>* rotateRight(Node<T>*& R);					//R is short for right
	Node<T>* rotateLeft(Node<T>*& L);					//L is short for left
	Node<T>* rightMost(Node<T>*& subRoot);
	void saveAVL(Node<T>* startNode, ofstream& outFile);
	Node<T>* constructorAssist(string nodes);

public:
	AVLtree();
	~AVLtree();

	//function declarations
	int getHeight();
	bool getBalance();
	int getLeafCount();
	int getCount();					//gets count of all nodes
	void insert(T value);
	void insertItem(T value, T item);
	void insertList(T value, vector<T> items);
	void del(T value);
	void delItem(T value, T item);
	vector<T> returnItems(T value);
	void search(T value);
	void display(int option);
	void saveData(string fileID);
	void contstructTree(string fileID);
};
#endif