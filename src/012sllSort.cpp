/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes 
will be followed by ones and then twos.


INPUTS:  SLL head pointer

OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2


ERROR CASES:

NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};

// Total two methods

// NORMAL SORTING (Method 1)
/*
void sll_012_sort(struct node *head)
{
	struct node *i, *j;
	int temp;

	for (i = head; i != NULL; i = i->next)
	{
		for (j = i->next; j != NULL; j = j->next)
		{
			if (i->data > j->data)
			{
				temp = i->data; 
				i->data = j->data;
				j->data = temp;
			}
		}
	}

}
*/

// Above method has loop in loop, this method has no loop inside a loop. 

// 012 SORTING (Method 2)

void sll_012_sort(struct node *head)
{
	struct node *i, *j;
	int temp;

	for (i = head, j = head; i != NULL; i = i->next)
	{
		if (i->data == 0)
		{
			temp = i->data;
			i->data = j->data;
			j->data = temp;
			j = j->next;
		}
	}
	
	i = j;
	
	while (i != NULL)
	{
		if (i->data == 1)
		{
			temp = i->data;
			i->data = j->data;
			j->data = temp;
			j = j->next;
		}
		i = i->next;
	}

}