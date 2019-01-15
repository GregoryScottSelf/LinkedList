//Greg Self 
//CSI 330
//Ch 5 Problem 10 Linked List 
#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
//Input:node_head is used to determine if this list is empty 
//Output:true is returned if the list is empty, false otherwise
bool emptylist(node *head_next)
{
	//if there is nothing in the list true is returned
	if (head_next == NULL)
		return true;
	else
		return false;
}
//Input:head_next and last are used to point to to user input
//Output:none
void add(node *&head_next, node *&last, int input)
{
	//if the list is empty, the integer that is enetered is added as the first node in the list
	//calling emptylist function to see if the list is empty
	if (emptylist(head_next))
	{
		//t is the temporary value
		node* t = new(node);
		t->data = input;
		//nothing else is in the list, so next is set to NULL
		t->next = NULL;
		head_next = t;
		last = t;
	}
	else
	{
		node *t = new(node);
		t->data = input;
		t->next = NULL;
		last->next = t;
		last = t;
	}
}
//Input: head_next is used to point to each node, Temp is used to store temp values to be printed
//Output: contents of the list
void print(node *head_next)
{
	node *temp = head_next;
	//checking if the list is empty
	//calling emptylist function
	if (emptylist(temp))
		cout << "Your list is Empty." << endl;
	else
	{
		cout << "Your list has these values:" << endl;
		while (temp != NULL)
		{
			cout << temp->data << endl;
			temp = temp->next;
		}
	}
}
int main()
{
	int store = 0;
	int input = 0;
	node *head_next = NULL;
	node *last_value = NULL;
	do
	{
		cout << "Enter 1 to add to the list, Enter 2 to print, Enter 3 to quit:" << endl;
		cin >> store;
		//input validataion
		while (store < 1 || store>3 || cin.fail())
		{
			cin.clear();
			cin.ignore(3000, '\n');
			cout << "Input error" << endl;
			cout << "Enter 1 to add to the list, Enter 2 to print, Enter 3 to quit:" << endl;
			cin >> store;
		}
		if (store == 1)
		{
			cout << "Enter a number to add to the list" << endl;
			cin >> input;
			add(head_next, last_value, input);

		}
		else if (store == 2)
		{
			print(head_next);
		}
	} while (store != 3);

	return 0;
}