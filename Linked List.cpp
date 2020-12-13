//Robert Colburn
#include <iostream>
using namespace std;
typedef struct Node Node;
Node* createNode(int);
void addNode(Node*, int);
void addNodeBeginning(Node*);
void freeNode(Node*);
void addNodeEnd(Node*);
void removeNode(int);
void removeFromBeginning();
void removeFromEnd();
void print();
void displayNode(int);
struct Node
{
	int number;
	Node* nextNode;
};
Node* firstNode = nullptr;
int main()
{
	int choice, newNumber, position;
	//Creates the first node, which keeps track of the number of nodes in the list.
	firstNode = createNode(0);
	do
	{
		cout << "Please enter an option:\n";
		cout << "1.\tAdd an element at the kth position\n";
		cout << "2.\tAdd an element at the beginning\n";
		cout << "3.\tAdd an element at the end\n";
		cout << "4.\tRemove an element from the kth position\n";
		cout << "5.\tRemove an element from the beginning\n";
		cout << "6.\tRemove an element from the end\n";
		cout << "7.\tPrint all the elements\n";
		cout << "8.\tDisplay the value of an element at the kth Position\n";
		cout << "9.\tExit\n";
		cin >> choice;
		cout << endl;
		switch (choice)
		{
		case 1:
			cout << "Enter the new value:\n";
			cin >> newNumber;
			cout << "Enter the position:\n";
			cin >> position;
			if (position < 0 || position > firstNode->number + 1)
			{
				cout << "Invalid position number. Enter a position within the bounds of the list.\n";
			}
			else
			{
				addNode(createNode(newNumber), position);
			}
			cout << endl;
			break;
		case 2:
			cout << "Enter the new value:\n";
			cin >> newNumber;
			addNodeBeginning(createNode(newNumber));
			cout << endl;
			break;
		case 3:
			cout << "Enter the new value:\n";
			cin >> newNumber;
			addNodeEnd(createNode(newNumber));
			cout << endl;
			break;
		case 4:
			if (firstNode->number == 0)
			{
				cout << "Error: The list is empty.\n\n";
				break;
			}
			cout << "Enter the position:\n";
			cin >> position;
			if (position < 0 || position > firstNode->number)
			{
				cout << "Error: Invalid position number. Enter a position within the bounds of the list.\n";
			}
			else
			{
				removeNode(position);
			}
			cout << endl;
			break;
		case 5:
			if (firstNode->number == 0)
				cout << "Error: Cannot remove an element from an empty list.\n";
			else
			{
				removeFromBeginning();
				cout << "The element at the beginning has been removed.\n";
			}
			cout << endl;
			break;
		case 6:
			if (firstNode->number == 0)
				cout << "Error: Cannot remove an element from an empty list.\n";
			else
			{
				removeFromEnd();
				cout << "The element at the end has been removed.\n";
			}
			cout << endl;
			break;
		case 7:
			if (firstNode->number == 0)
				cout << "Error: The list is empty.\n";
			else
				print();
			break;
		case 8:
			cout << "Enter a position:\n";
			cin >> position;
			if (position < 0 || position > firstNode->number)
			{
				cout << "Error: Invalid position number. Enter a position within the bounds of the list.\n";
			}
			else
			{
				displayNode(position);
			}
			cout << endl;
			break;
		}
	} while (choice != 9);
	return 0;
}
//Creates a node.
Node* createNode(int number)
{
	Node* newNode = new Node;
	newNode->number = number;
	newNode->nextNode = nullptr;
	return newNode;
}
//Deletes a node from memory.
void freeNode(Node* node)
{
	delete node;
}
//Adds a new node to the list to the specified position.
void addNode(Node* newNode, int position)
{
	Node* ptr = firstNode;
	for (int counter = 1; counter < position; counter++)
	{
		ptr = ptr->nextNode;
	}
	if (position <= firstNode->number)
	{
		newNode->nextNode = ptr->nextNode;
	}
	ptr->nextNode = newNode;
	firstNode->number++;
}
//Adds a node to the beginning of the list.
void addNodeBeginning(Node* newNode)
{
	addNode(newNode, 1);
}
//Adds a node to the end of the list.
void addNodeEnd(Node* newNode)
{
	addNode(newNode, firstNode->number + 1);
}
//Removes a node at a specified position from the list.
void removeNode(int position)
{
	Node* ptr = firstNode;
	Node* tempNode;
	for (int counter = 1; counter < position; counter++)
	{
		ptr = ptr->nextNode;
	}
	tempNode = ptr->nextNode;
	ptr->nextNode = (ptr->nextNode)->nextNode;
	firstNode->number--;
	freeNode(tempNode);
}
//Removes the node at the beginning of the list.
void removeFromBeginning()
{
	removeNode(1);
}
//Removes the node at the end of the list.
void removeFromEnd()
{
	removeNode(firstNode->number);
}
//Displays all of the elements in the list.
void print()
{
	Node* ptr = firstNode;
	cout << "The number of elements in the list is: " << ptr->number << endl;
	ptr = firstNode->nextNode;
	cout << "List:\n";
	while (ptr != nullptr)
	{
		cout << ptr->number << endl;
		ptr = ptr->nextNode;
	}
	cout << endl;
}
//Displays a specific node at a certain position.
void displayNode(int position)
{
	Node* ptr = firstNode;
	for (int counter = 0; counter < position; counter++)
	{
		ptr = ptr->nextNode;
	}
	cout << "The element at position " << position << " is " << ptr->number << endl;
}