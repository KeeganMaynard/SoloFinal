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
	int count;
	int itemCount;
};
#endif