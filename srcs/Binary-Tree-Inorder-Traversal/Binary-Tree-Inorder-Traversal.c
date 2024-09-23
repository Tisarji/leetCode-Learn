/** FILE: Binary-Tree-Inorder-Traversal.c
 * Subject: BINARY-TREE-INORDER-TRAVERSAL
 * Given the root of a binary tree, return the inorder traversal of its nodes' values.
 * 
 * Example 1:
 * 
 * Input: root = [1,null,2,3]
 * 
 * Output: [1,3,2]
 * 
 * Explanation:
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
 * 
 * Output: [4,2,6,5,7,1,3,9,8]
 * 
 * Explanation:
 * 
 * Example 3:
 * 
 * Input: root = []
 * 
 * Output: []
 * 
 * Example 4:
 * 
 * Input: root = [1]
 * 
 * Output: [1]
 * 
 * 
 * Constraints:
 * 
 * The number of nodes in the tree is in the range [0, 100].
 * -100 <= Node.val <= 100
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
 */

#include <stdio.h>
#include <stdlib.h>

/** Definition for a binary tree node. */
struct TreeNode {
	int				val;
	struct TreeNode	*left;
	struct TreeNode	*right;
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void	add_arr(int **arr, int *rt_size, int val)
{
	(*arr)[(*rt_size)++] = val;
}

int	*inorderTraversal(struct TreeNode *root, int *returnSize)
{
	int				*result;
	int				top;
	struct TreeNode	*stack[100];
	struct TreeNode	*curr;

	*returnSize = 0;
	if (root == NULL)
		return (NULL);
	result = (int *)malloc(100 * sizeof(int));
	top = -1;
	curr = root;
	while (curr != NULL || top >= 0)
	{
		while (curr != NULL)
		{
			stack[++top] = curr;
			curr = curr->left;
		}
		curr = stack[top--];
		add_arr(&result, returnSize, curr->val);
		curr = curr->right;
	}
	return (result);
}

struct TreeNode	*new_node(int val)
{
	struct TreeNode *node;

	node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	node->val = val;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

int	main(void)
{
	struct TreeNode *root = new_node(1);
	root->right = new_node(2);
	root->right->left = new_node(3);

	int rt_size;
	int *result = inorderTraversal(root, &rt_size);

	printf("Inorder Traversal");
	for (int i = 0; i < rt_size; i++)
		printf("\nidx[%d]: %d ", i, result[i]);
	printf("\n");

	free(result);
	free(root->right->left);
	free(root->right);
	free(root);

	return (0);
}
