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


/**
 * The function createNode() dynamically allocates memory for a new ListNode, initializes its value,
 * and sets its next pointer to NULL.
 * 
 * @param value The `value` parameter in the `createNode` function represents the integer value that
 * you want to store in the newly created node. This value will be assigned to the `val` member of the
 * `ListNode` struct.
 * 
 * @return The function `createNode` is returning a pointer to a newly created `ListNode` structure.
 */
struct ListNode*	createNode(int value)
{
	struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
	newNode->val = value;
	newNode->next = NULL;
	return (newNode);
}

/**
 * The function `swapPairs` swaps every pair of adjacent nodes in a linked list.
 * 
 * @param head The `head` parameter in the `swapPairs` function is a pointer to the head of a linked
 * list. The function swaps pairs of nodes in the linked list and returns a pointer to the new head of
 * the modified list.
 * 
 * @return The function `swapPairs` is returning a pointer to the new head of the linked list after
 * swapping pairs of nodes.
 */
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

/**
 * The function `print_list` iterates through a linked list and prints the values of each node.
 * 
 * @param head The `head` parameter in the `print_list` function is a pointer to the head of a linked
 * list. The function iterates through the linked list starting from the head node and prints the value
 * of each node in the list.
 */
void	print_list(struct ListNode *head)
{
	while (head != NULL)
	{
		printf("%d", head->val);
		head = head->next;
	}
	// printf("\n");
}

//TESTING: Main for testing Everting
/**
 *int main(void)
 *{
 *	struct ListNode *head = NULL;
 *	head = createNode(1);
 *	head->next = createNode(2);
 *	head->next->next = createNode(3);
 *	head->next->next->next = createNode(4);
 *
 *	printf("Original: ");
 *	print_list(head);
 *	printf("\n");
 *
 *	head = swapPairs(head);
 *	printf("Swap Pairs: ");
 *	print_list(head);
 *	printf("\n");
 *
 *	return (0);
 *}
*/
