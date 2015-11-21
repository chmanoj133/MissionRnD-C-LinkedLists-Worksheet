/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int num;
	struct node *next;
};

/*
struct node * removeEveryKthNode(struct node *head, int K) 
{
	struct node *i, *temp, *first, *copy = head;
	int j;
	if (K <= 0 || K == 1 || head == NULL)
		return NULL;
	else
	{
		
		for (i = head, j = 1; i != NULL; j++, i = i->next)
		{
			if (j%K != 0)
			{
				temp = (struct node*)malloc(sizeof(struct node));
				temp->num = i->num;
				if (j == 1)
				{
					first = temp;
					copy = temp;
				}
				else
				{
					copy->next = temp;
					copy = temp;
				}
			}
			
		}
		copy->next = NULL;
		return first;
	}
}


*/

struct node * removeEveryKthNode(struct node *head, int K)
{
	struct node *i, *prev;
	int j;
	if (K <= 0 || K == 1 || head == NULL)
		return NULL;
	else
	{
		i = head;
		j = 1;
		//for (i = head, j = 1; i != NULL; j++, i = i->next)
		while (i != NULL)
		{
			if (j == 2)
				prev = head;

			

			if (j % K == 0)
			{
				prev->next = i->next;
				i = prev->next;
				j++;
			}
			if (j != 1)
				prev = prev->next;

			j++;
			if (i != NULL)
				i = i->next;
		}
		
		return head;
	}
	
}

