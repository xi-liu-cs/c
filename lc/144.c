/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct TreeNode node;

void preorder(node * root, int * ret, int * return_size, int * cur_size)
{
    if(!root)
        return;
    if(*return_size + 1 > *cur_size)
    {
        *cur_size += 100;
        ret = realloc(ret, *cur_size * sizeof(int));
    }
    ret[(*return_size)++] = root->val;
    preorder(root->left, ret, return_size, cur_size);
    preorder(root->right, ret, return_size, cur_size);
}

int * preorderTraversal(node * root, int * return_size)
{
    int cur_size = 100;
    int * ret = malloc(cur_size * sizeof(int));
    *return_size = 0;
    preorder(root, ret, return_size, &cur_size);
    return ret;
}
