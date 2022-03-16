typedef struct TreeNode node;

int ** preorder(node * root, int ** ret, int * return_size, int * cur_size)
{
    if(!root)
        return ret;
    if(*return_size >= *cur_size)
    {
        *cur_size = *return_size + 10;
        *ret = realloc(*ret, *cur_size * sizeof(int));
    }
    (*ret)[(*return_size)++] = root->val;
    preorder(root->left, ret, return_size, cur_size);
    preorder(root->right, ret, return_size, cur_size);
    return ret;
}

int * preorderTraversal(node * root, int * return_size)
{
    int cur_size = 10;
    int * ret = malloc(cur_size * sizeof(int));
    *return_size = 0;
    return *preorder(root, &ret, return_size, &cur_size);
}
