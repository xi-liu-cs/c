typedef struct TreeNode node;

int ** postorder(node * root, int ** ret, int * return_size, int * cur_size)
{
    if(!root)
        return ret;
    postorder(root->left, ret, return_size, cur_size);
    postorder(root->right, ret, return_size, cur_size);
    if(*return_size >= *cur_size)
    {
        *cur_size = *return_size + 10;
        *ret = realloc(*ret, *cur_size * sizeof(int));
    }
    (*ret)[(*return_size)++] = root->val;
    return ret;
}

int * postorderTraversal(node * root, int * return_size)
{
    int cur_size = 10;
    int * ret = malloc(cur_size * sizeof(int));
    *return_size = 0;
    return *postorder(root, &ret, return_size, &cur_size);
}
