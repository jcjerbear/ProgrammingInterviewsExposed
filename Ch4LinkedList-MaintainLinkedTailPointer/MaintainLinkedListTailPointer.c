//Ch4 Linked List - Maintain Linked List Tail Pointer

//This linked list initially contains integers from 0 to 10, 0 as the head/root of the list
//This linked list was implemented without using a dummy headnode
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Element{
	struct Element *next;
	int data;
}Element;

//head and tail pointers are global pointers to the first and last element
Element *head;
Element *tail;

bool createList(int data);
void deleteList(); //delete the entire linked list
bool delete(Element *elem);
bool insertAfter(Element *elem, int data);
//bool insertInFront(Element *elem, int data); already covered in insertAfter()
//bool deleteElement(Element **head, Element *deleteMe); used only when the head and tail pointers are not declared globally
void printList();

int main(int argc, char* argv[])
{
	int value = 1;

	if( createList(0) == false)
	{
		perror("createList");
		return -1;
	}
	
	//initialize the linked list with values from 1-10
	while(value<=10)
	{
		if( insertAfter(tail, value) == false)
		{
			perror("insertAfter");
			return -1;
		}
		value++;
	}
	printList();

	//now test to delete the head of the linked list
	if( delete(head) == false)
	{
		perror("delete");
		return -1;
	}
	printList();

	//now test to delete the tail of the linked list
	if( delete(tail) == false)
	{
		perror("delete");
		return -1;
	}
	printList();

	//now test to delete the third element of the linked list
	if( delete(head->next->next) == false)
	{
		perror("delete");
		return -1;
	}
	printList();

	//eventually delete the entire list
	deleteList();
	printList();
	return 0;
}

bool createList(int data)
{
	head = (Element*)malloc(sizeof(Element));
	if(!head) return false;
	head->next = NULL;
	head->data = data;
	tail = head;
	return true;
}

void deleteList()
{
	Element *curPos = head;
	Element *next;
	while(curPos)
	{
		next = curPos->next;
		free(curPos);
		curPos = next;
	}
	head = tail = NULL;
}

bool delete(Element *elem)
{
	Element *curPos = head;

	//if elem is NULL
	if(!elem) return false;

	//if elem is the head
	if(elem == head)
	{
		head = elem->next;
		free(elem);
		//case when only 1 element left in the list and the deleted one was that single one
		if(!head) tail = head;
		return true;
	}

	//if elem is not the head
	while(curPos)
	{
		if(curPos->next == elem)
		{
			curPos->next = elem->next;
			free(elem);
			//case when elem is the last element of the linked list
			if(curPos->next == NULL) tail = curPos;
			return true;
		}
		curPos = curPos->next;
	}
	return false;
}

bool insertAfter(Element *elem, int data)
{
	Element *curPos = head;
	Element *newElem = (Element*)malloc(sizeof(Element));
	if(!newElem) return false;
	newElem->data = data;

	//insert at the beginning of the list
	if(!elem)
	{
		newElem->next = head;
		head = newElem;
		//case when the linked list is empty
		if(!tail) tail = newElem;
		return true;
	}

	while(curPos)
	{
		if(curPos == elem)
		{
			newElem->next = curPos->next;
			curPos->next = newElem;
			//case when there is only 1 element in the linked list, so inserting at the end of the list
			if(!(newElem->next)) tail = newElem;
			return true;
		}
		curPos = curPos->next;
	}

	//insert position not found. free newElem and return false
	free(newElem);
	return false;
}

/*
bool insertInFront(int data)
{

}
*/
/*
bool deleteElement(Element **head, Element *deleteMe)
{
}
*/

void printList()
{
	Element *curPos = head;
	if(!curPos) printf("NULL");
	while(curPos)
	{
		if(!(curPos->next)) printf("%d", curPos->data);
		else printf("%d->", curPos->data);
		curPos = curPos->next;
	}
	printf("\n");
}

