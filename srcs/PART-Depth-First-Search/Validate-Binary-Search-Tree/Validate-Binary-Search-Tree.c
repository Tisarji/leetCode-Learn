/** FILE: Validate-Binary-Search-Tree.c
 * Subject: VALIDATE-BINARY-SEARCH-TREE
 * Given the root of a binary tree, determine if it is a valid binary search tree (BST).
 * 
 * A valid BST is defined as follows:
 * 
 * | The left subtree of a node contains only nodes with keys less than the node's key.
 * | The right subtree of a node contains only nodes with keys greater than the node's key.
 * | Both the left and right subtrees must also be binary search trees.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [2,1,3]
 * Output: true
 * Example 2:
 * 
 * 
 * Input: root = [5,1,4,null,null,3,6]
 * Output: false
 * Explanation: The root node's value is 5 but its right child's value is 4.
 * 
 * 
 * Constraints:
 * 
 * The number of nodes in the tree is in the range [1, 104].
 * -231 <= Node.val <= 231 - 1
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

/** Definition for a binary tree node. */
struct TreeNode {
	int				val;
	struct TreeNode	*left;
	struct TreeNode	*right;
};

bool	validate(struct TreeNode *node, long minVal, long maxVal)
{
	if (node == NULL)
		return (true);
	if (node->val <= minVal || node->val >= maxVal)
		return (false);
	return (validate(node->left, minVal, node->val) \
			&& validate(node->right, node->val, maxVal));
}

bool	isValidBST(struct TreeNode *root)
{
	return (validate(root, LONG_MIN, LONG_MAX));
}

// Function For testing How's it work

void	freeTree(struct TreeNode* root)
{
	if (root == NULL)
		return ;
	freeTree(root->left);
	freeTree(root->right);
	free(root);
}

struct TreeNode	*createNode(int val)
{
	struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	newNode->val = val;
	newNode->left = NULL;
	newNode->right = NULL;
	return (newNode);
}

int	main(void)
{
	// Example 1: root = [2,1,3]
	struct TreeNode* root1 = createNode(2);
	root1->left = createNode(1);
	root1->right = createNode(3);

	if (isValidBST(root1))
		printf("Tree 1 is a valid BST.\n");
	else
		printf("Tree 1 is not a valid BST.\n");

	// Example 2: root = [5,1,4,null,null,3,6]
	struct TreeNode* root2 = createNode(5);
	root2->left = createNode(1);
	root2->right = createNode(4);
	root2->right->left = createNode(3);
	root2->right->right = createNode(6);

	if (isValidBST(root2))
		printf("Tree 2 is a valid BST.\n");
	else
		printf("Tree 2 is not a valid BST.\n");
	freeTree(root1);
	freeTree(root2);

	return (0);
}
