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
	if (subRoot == nullptr)
	{
		return newRoot;
	}
	else if (newRoot->value > subRoot->value)
	{
		subRoot->right = insertItemAssist(subRoot->right, newRoot);
	}
	else if (newRoot->value < subRoot->value)
	{
		subRoot->left = insertItemAssist(subRoot->left, newRoot);
	}
	else
	{
		bool valid = true;
		//check if the newRoot is already in the list
		for (int i = 0; i < subRoot->list.size(); i++)
		{
			if (newRoot->list[0] == subRoot->list[i])
			{
				cout << "Error: invalid input.\nDuplicate entries are not allowed." << endl;
				valid = false;
				break;
			}
		}
		if (valid)
		{
			subRoot->list.push_back(newRoot->list[0]);
			itemCount++;
		}

		count--;
		subRoot->height = max(Height(subRoot->left), Height(subRoot->right)) + 1;
		rotate(subRoot);

		return subRoot;
	}
}

template <class T>
Node<T>* AVLtree<T>::delAssist(Node<T>*& subRoot, T value)
{
	if (value > subRoot->value)
	{
		if (subRoot->right != nullptr)
		{
			subRoot->right = delAssist(subRoot->right, value);
		}
		else
		{
			count++;
		}
	}
	else if (value < subRoot->right)
	{
		if (subRoot->left != nullptr)
		{
			subRoot->left = delAssist(subRoot->left, value);
		}
		else
		{
			count++;
		}
	}
	else
	{
		itemCount -= subRoot->list.size();

		//if there are two child nodes
		if ((subRoot->left != nullptr) && (subRoot->right != nullptr))
		{
			Node<T>* largestChild = rightMost(subRoot->left);
			subRoot->value = largestChild->value;
			subRoot->list = largestChild->list;
			itemCount -= largestChild->list.size();
			subRoot->left = delAssist(subRoot->left, largestChild->value);
		}
		else if ((subRoot->left == nullptr) && (subRoot->right == nullptr))
		{
			//if its a leaf node
			delete subRoot;
			subRoot = nullptr;
			return subRoot;
		}
		else
		{
			//only one child node
			Node<T>* onlyChild = (subRoot->left != nullptr) ? subRoot->left : subRoot->right;
			delete subRoot;
			subRoot = onlyChild;
		}
	}
	subRoot->height = max(Height(subRoot->left), Height(subRoot->right)) + 1;
	rotate(subRoot);

	return subRoot;
}

template <class T>
Node<T>* AVLtree<T>::delItemAssist(Node<T>*& subRoot, T value, T item)
{
	//similar to the delAssist function
	if (value > subRoot->value)
	{
		if (subRoot->right != nullptr)
		{
			subRoot->right = delItemAssist(subRoot->right, value, item);
		}
		else
		{
			count++;
		}
	}
	else if (value < subRoot->value)
	{
		if (subRoot->left != nullptr)
		{
			subRoot->left = delItemAssist(subRoot->left, value, item);
		}
		else
		{
			count++;
		}
	}
	else
	{
		bool present = false;
		int index = 0;

		for (int i = 0; i < subRoot->list.size(); i++)
		{
			if (item = subRoot->list[i])
			{
				present = true;
				index = i;
				break;
			}
		}

		if (present)
		{
			if (subRoot->list.size() == 1)
			{
				//if there are two child nodes
				if ((subRoot->left != nullptr) && (subRoot->right != nullptr))
				{
					Node<T>* largestChild = rightMost(subRoot->left);
					subRoot->value = largestChild->value;
					subRoot->list = largestChild->list;
					itemCount -= largestChild->list.size();
					subRoot->left = delAssist(subRoot->left, largestChild->value);
				}
				else if ((subRoot->left == nullptr) && (subRoot->right == nullptr))
				{
					//if its a leaf node
					delete subRoot;
					subRoot = nullptr;
					return subRoot;
				}
				else
				{
					//only one child node
					Node<T>* onlyChild = (subRoot->left != nullptr) ? subRoot->left : subRoot->right;
					delete subRoot;
					subRoot = onlyChild;
				}
			}
			else
			{
				subRoot->list.erase(subRoot->list.begin() + index);			//index tracts the location of item
				count++;
			}
			itemCount--;
		}
		else
		{
			cout << "Error: invalid input.\nPlease try again." << endl;
			count++;
		}
	}

	subRoot->height = max(Height(subRoot->left), Height(subRoot->right)) + 1;
	rotate(subRoot);
	return subRoot;
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
	int bal = Balance(subRoot);
	int left = Balance(subRoot->left);
	int right = Balance(subRoot->right);

	if ((left >= 0) && (bal > 1))
	{
		subRoot = rotateRight(subRoot);
	}
	else if ((left < 0) && (bal > 1))
	{
		//double rotation
		subRoot->left = rotateLeft(subRoot->left);
		subRoot = rotateRight(subRoot);
	}
	else if ((right > 0) && (bal < -1))
	{
		//double rotation
		subRoot->right = rotateRight(subRoot->right);
		subRoot = rotateLeft(subRoot);
	}
	else if ((right <= 0) && (bal < -1))
	{
		subRoot = rotateLeft(subRoot);
	}
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
Node<T>* AVLtree<T>::rightMost(Node<T>*& subRoot)
{
	while (subRoot->right != nullptr)
	{
		subRoot = subRoot->right;
	}

	return subRoot;
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
	int getbal = Balance(root);
	bool bal = ((getbal <= 1) && (getbal >= -1)) ? true : false;
	return bal;
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
	Node<T>* newRoot = new Node<T>(value, item);
	root = insertItemAssist(root, newRoot);
	count++;
}

template <class T>
void AVLtree<T>::insertList(T value, vector<T> items)
{

}

template <class T>
void AVLtree<T>::del(T value)
{
	if (root != nullptr)
	{
		root = delAssist(root, value);
		count--;
	}
}

template <class T>
void AVLtree<T>::delItem(T value, T item)
{
	root = delItemAssist(root, value, item);
	count--;
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