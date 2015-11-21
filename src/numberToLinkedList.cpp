/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES: 

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};



/*
struct node * numberToLinkedList(int N)
{
	int i, count = 0, num, ten_power = 1, remainder;
	struct node *head, *temp = NULL, *first;

	if (N < 0)
		N = -N; 
	num = N;

	if (num == 0)
		count++;
	else
		for (count = 0; num > 0; num = num / 10, count++);


	for (i = 0; i < count - 1; i++)
		ten_power = ten_power * 10;	

	for (i = 0; i < count; i++)
	{
		remainder = N / ten_power;
		N = N - (remainder*ten_power);

		head = (struct node*)malloc(sizeof(struct node));

		head->num = remainder;

		if (i == 0)
		{
			first = head;
			temp = head;
		}
		else
		{
			temp->next = head;
			temp = head;
		}

		remainder = N / ten_power;
		N = N - (remainder*ten_power);
		ten_power = ten_power / 10;
	}
	temp->next = NULL;

	return first;
}

*/

struct node * numberToLinkedList(int N)
{
	int rem, flag = 0;
	struct node *temp = (struct node*)malloc(sizeof(struct node)), *head;

	if (N < 0)
		N = -N;
	if (N == 0)
		flag++;
	temp->next = NULL;
	while (N != 0 || flag == 1)
	{
		rem = N % 10;
		temp->num = rem;
		head = (struct node*)malloc(sizeof(struct node));
		head->next = temp;
		temp = head;
		N = N / 10;
		flag++;
	}
	return head->next;
}
