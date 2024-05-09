/**
 * Subject: in Swap-Nodes-In-Pairs
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 * You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
 */

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode
{
	int val;
	struct ListNode *next;
};

// Function to create a new node
struct ListNode*	createNode(int value)
{
	struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
	newNode->val = value;
	newNode->next = NULL;
	return (newNode);
}

struct ListNode	*swapPairs(struct ListNode *head)
{
	if (head == NULL || head->next == NULL)
		return (head);

	struct ListNode *newHead = head->next;
	struct ListNode *nextPair = newHead->next;
	newHead->next = head;
	head->next = swapPairs(nextPair);

	return (newHead);
}

void	print_list(struct ListNode *head)
{
	while (head != NULL)
	{
		printf("%d", head->val);
		head = head->next;
	}
	// printf("\n");
}

	int main(void)
	{
		struct ListNode *head = NULL;
		head = createNode(1);
		head->next = createNode(2);
		head->next->next = createNode(3);
		head->next->next->next = createNode(4);
	
		printf("Original: ");
		print_list(head);
		printf("\n");
	
		head = swapPairs(head);
		printf("Swap Pairs: ");
		print_list(head);
		printf("\n");
	
		return (0);
	}
