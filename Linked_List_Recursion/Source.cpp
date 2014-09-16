#include <iostream>

using std::cout;
using std::endl;
struct node
{
	int data;
	node* next;
};

// Recursively searches a linked list
void search_linked_list(node* ptr, int search_value)
{
	if (ptr == NULL)
	{
		cout << search_value << " was not found in the list." << endl;
	}
	else if (ptr->data == search_value)
	{
		cout << search_value << " was found in the list." << endl;
	}
	else
	{
		search_linked_list(ptr->next, search_value);
	}
}

int main(int argc, char *argv[])
{
	// Create head node and add a value to it
	node* n = new node;
	node* head = n;
	node* tn = n; // temp node
	n->data = 1;

	// Create a few nodes and add data to them
	for (int i = 2; i < 10; i++)
	{
		n = new node;
		n->data = i;
		tn->next = n;
		tn = n;
	}
	n->next = NULL;
	tn = head;

	// Print linked list
	cout << "Linked List:" << endl;
	while (tn != NULL)
	{
		cout << tn->data << " ";
		tn = tn->next;
	}
	cout << "\n" << endl;

	// Search linked list recursively
	cout << "Searching for 5 in linked list... ";
	search_linked_list(head, 5);
	cout << "Searching for 100 in linked list... ";
	search_linked_list(head, 100);
	return 0;
}