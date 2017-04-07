//============================================================================
// Name        : HackerRank.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct Node {
	int data; //value of the node
	struct Node *next; //stores the value of the next note of the linked list
};

void Print(Node *head)
{
		if(head == NULL)
		{
			cout << "LinkedList is empty" << endl;
		}
		Node *temp = head;
		while(temp != NULL)
		{
			cout << temp->data << " " << endl;
			temp = temp->next;

		}
}

Node* InsertAtTail(Node *head,int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->next = NULL;

    if(head == NULL)
    {
       head = temp;
       return head;
    }

    Node *traverse = head;
    while(traverse->next != NULL)

    {
        traverse = traverse->next;
    }

    traverse->next = temp;
    return head;
}

Node* InsertBeginning(Node *head,int data)
{
  Node *temp = new Node();
  temp->data = data;
  if(head == NULL)
  {
      temp->next = NULL;
      head = temp;
  }
  else
  {
      temp->next = head->next;
      head = temp;
  }
  delete[] temp; //to avoid memory leakage delete the pointer
  return head;

}

Node* InsertNth(Node *head, int data, int position)
{
	//A pointer p that points to head of the linked list
    Node** p = &head;

    //run a for loop to move pointer p to the 'position' in the Linked list
    for(int i = 0; i < position; ++i)
        p = &(*p)->next;

    //Right side of the list is a new node with data is the value, and current node *p as the next node
    *p = new Node {data, *p};

    //return head of the list
    return head;
}

Node* Delete(Node *head, int position)
{
	//Using recursion
    if(position == 0) {
    	//if position is zero, return next element
    	return head->next;}
    //else recursion for next element of the list and position = position - 1
    else
        head->next = Delete(head->next,position-1);
    return head;

}


int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	Node *head = new Node();
	head = InsertAtTail(head, 2);
	Print(head);
	head = InsertAtTail(head, 3);
	Print(head);
	return 0;
}
