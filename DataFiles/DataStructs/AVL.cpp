#include "AVL.h"
using namespace std;

template <class T>
AVLtree<T>::AVLtree()
{
	root = nullptr;
	count = 0;
}

template <class T>
int AVLtree<T>::Height(Node<T>*& subRoot)
{

}

template <class T>
int AVLtree<T>::Balance(Node<T>* subRoot)
{

}

template <class T>
int AVLtree<T>::leafs(Node<T>* subRoot)
{

}

template <class T>
void AVLtree<T>::midpoints(vector<Node<T>*>& list, int front, int end)
{

}

template <class T>
void AVLtree<T>::delSubRoot(Node<T>*& subRoot)
{

}

template <class T>
Node<T>* AVLtree<T>::insertAssist(Node<T>*& subRoot, Node<T>*& newRoot)
{

}

template <class T>
Node<T>* AVLtree<T>::insertItemAssist(Node<T>*& subRoot, Node<T>*& newRoot)
{

}

template <class T>
Node<T>* AVLtree<T>::delAssist(Node<T>*& subRoot, T value)
{

}

template <class T>
Node<T>* AVLtree<T>::delItemAssist(Node<T>*& subRoot, T value, T item)
{

}

template <class T>
Node<T>* AVLtree<T>::searchAssist(T val, Node<T>* subRoot)
{

}

template <class T>
void AVLtree<T>::displaySystemAdmins(Node<T>* subRoot)
{

}

template <class T>
void AVLtree<T>::displayOfficials(Node<T>* subRoot)
{

}

template <class T>
void AVLtree<T>::displayMembers(Node<T>* subRoot)
{

}

template <class T>
void AVLtree<T>::displayItems(Node<T>* subRoot)
{

}

template <class T>
void AVLtree<T>::rotate(Node<T>*& subRoot)
{

}

template <class T>
Node<T>* AVLtree<T>::rotateRight(Node<T>*& R)
{

}

template <class T>
Node<T>* AVLtree<T>::rotateLeft(Node<T>*& L)
{

}

template <class T>
void AVLtree<T>::saveAVL(Node<T>* startNode, ofstream& outFile)
{

}

template <class T>
Node<T>* AVLtree<T>::constructorAssist(string nodes)
{

}

template <class T>
AVLtree<T>::~AVLtree()
{
	delSubRoot(root);
}

template <class T>
int AVLtree<T>::getHeight()
{

}

template <class T>
bool AVLtree<T>::getBalance()
{

}

template <class T>
int AVLtree<T>::getLeafCount()
{

}

template <class T>
int AVLtree<T>::getCount()
{

}

template <class T>
void AVLtree<T>::insert(T value)
{

}

template <class T>
void AVLtree<T>::insertItem(T value, T item)
{

}

template <class T>
void AVLtree<T>::insertList(T value, vector<T> items)
{

}

template <class T>
void AVLtree<T>::del(T value)
{

}

template <class T>
void AVLtree<T>::delItem(T value, T item)
{

}

template <class T>
vector<T> AVLtree<T>::returnItems(T value)
{

}

template <class T>
void AVLtree<T>::search(T value)
{

}

template <class T>
void AVLtree<T>::display(int option)
{

}

template <class T>
void AVLtree<T>::saveData(string fileID)
{

}

template <class T>
void AVLtree<T>::contstructTree(string fileID)
{

}