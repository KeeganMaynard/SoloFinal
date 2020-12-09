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
	if (subRoot == nullptr)
	{
		return 0;
	}
	else
	{
		return subRoot->height;
	}
}

template <class T>
int AVLtree<T>::Balance(Node<T>* subRoot)
{
	if (subRoot == nullptr)
	{
		return 0;
	}
	else
	{
		return Height(subRoot->left) - Height(subRoot->right);
	}
}

template <class T>
int AVLtree<T>::leafs(Node<T>* subRoot)
{

}

template <class T>
void AVLtree<T>::midpoints(vector<Node<T>*>& list, int front, int end)
{
	if (end - front >= 0)    //stop finding midpoints
	{
		int midpoint = front + ((end - front) / 2);
		root = insertAssist(root, list[midpoint]);
		count++;

		midpoints(list, front, midpoint - 1);
		midpoints(list, midpoint + 1, end);
	}
}

template <class T>
void AVLtree<T>::delSubRoot(Node<T>*& subRoot)
{
	Node<T>* left = subRoot->left;
	Node<T>* right = subRoot->right;
	delete subRoot;

	if (left != nullptr)
	{
		delSubRoot(left);
	}

	if (right != nullptr)
	{
		delSubRoot(right);
	}
}

template <class T>
Node<T>* AVLtree<T>::insertAssist(Node<T>*& subRoot, Node<T>*& newRoot)
{
	if (subRoot == nullptr)
	{
		itemCount += newRoot->list.size();
		return newRoot;
	}
	else if (newRoot->value > subRoot->value)
	{
		subRoot->right = insertAssist(subRoot->right, newRoot);
	}
	else if (newRoot->value < subRoot->value)
	{
		subRoot->left = insertAssist(subRoot->left, newRoot);
	}
	else
	{
		count--;
		cout << "Error: invalid input.\nDuplicate entries are not allowed." << endl;
	}

	subRoot->height = max(Height(subRoot->left), Height(subRoot->right)) + 1;
	rotate(subRoot);

	return subRoot;
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
	if (subRoot)
	{
		displaySystemAdmins(subRoot->left);
		if (subRoot->list == "system admin")
		{
			cout << subRoot->value << endl;
		}
		displaySystemAdmins(subRoot->right);
	}
}

template <class T>
void AVLtree<T>::displayOfficials(Node<T>* subRoot)
{
	if (subRoot)
	{
		displayOfficials(subRoot->left);
		if (subRoot->list == "official")
		{
			cout << subRoot->value << endl;
		}
		displayOfficials(subRoot->right);
	}
}

template <class T>
void AVLtree<T>::displayMembers(Node<T>* subRoot)
{
	if (subRoot)
	{
		displayMembers(subRoot->left);
		if (subRoot->list == "member")
		{
			cout << subRoot->value << endl;
		}
		displayMembers(subRoot->right);
	}
}

template <class T>
void AVLtree<T>::displayItems(Node<T>* subRoot)
{
	if (subRoot)
	{
		displayItems(subRoot->left);
		cout << "Key: " << subRoot->value << " Value: ";
		for (int i = 0; i < subRoot->list.size(); i++)
		{
			cout << subRoot->list[i] << endl;
		}
		displayItems(subRoot->right);
	}
}

template <class T>
void AVLtree<T>::rotate(Node<T>*& subRoot)
{

}

template <class T>
Node<T>* AVLtree<T>::rotateRight(Node<T>*& R)
{
	Node<T>* kid = R->left;
	Node <T>* gKid = kid->right;

	kid->right = R;
	R->left = gKid;

	kid->height = max(Height(kid->left), Height(kid->right)) + 1;
	R->height = max(Height(R->left), Height(R->right)) + 1;

	return kid;
}

template <class T>
Node<T>* AVLtree<T>::rotateLeft(Node<T>*& L)
{
	Node<T>* kid = L->right;
	Node<T>* gKid = kid->left;

	L->right = gKid;
	kid->left = L;

	kid->height = max(Height(kid->left), Height(kid->right)) + 1;
	L->height = max(Height(L->left), Height(L->right)) + 1;

	return kid;
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
	Node<T>* newRoot = new Node<T>(value);
	root = insertAssist(root, newRoot);
	count++;
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
	string input;
	cout << "[1] Display System Admins\n[2] Display Bank Officials\n[3] Display Bank Members\n[4] Display By Values" << endl;
	getline(cin, input);

	if (input.length() > 1)
	{
		cout << "Error: invalid input.\nPlease Try Again." << endl;
	}
	else
	{
		int option = stoi(input);
	}

	switch (option)
	{
	case 1:
	{
		displaySystemAdmins(root);
		break;
	}
	case 2:
	{
		displayOfficials(root);
		break;
	}
	case 3:
	{
		displayMembers(root);
		break;
	}
	case 4:
	{
		displayItems(root);
		break;
	}
	default:
	{
		cout << "Error: invalid input.\nPlease try again." << endl;
		break;
	}
	}
}

template <class T>
void AVLtree<T>::saveData(string fileID)
{

}

template <class T>
void AVLtree<T>::contstructTree(string fileID)
{

}