/**
* Subject in Swap-Nodes-In-Pairs
* 
* Given a linked list, swap every two adjacent nodes and return its head. 
* You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
*/

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct	ListNode {
	int val;
	struct ListNode *next;
};

void	swap_node(struct ListNode *node1, struct ListNode *node2)
{
	int	temp;
	temp = node1->val;
	node1->val = node2->val;
	node2->val = temp;
}

struct ListNode*	swapPairs(struct ListNode* head)
{
	if (!head || !head->next)
		return (head);
	
}

int	main(void)
{
	printf("\n");
	return (0);
}
