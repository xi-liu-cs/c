typedef struct TreeNode node;

int * post(node * root, int * ret, int * return_size, int * cur_size)
{
    if(!root)
        return;
    if(*return_size + 1 > *cur_size)
    {
        *cur_size += 100;
        ret = realloc(ret, *cur_size * sizeof(int));
    }
    post(root->left, ret, return_size, cur_size);
    post(root->right, ret, return_size, cur_size);
    ret[(*return_size)++] = root->val;
    return ret;
}

int * postorderTraversal(node * root, int * return_size)
{
    int size = 100;
    int * ret = malloc(size * sizeof(int));
    *return_size = 0;
    ret = post(root, ret, return_size, &size);
    return ret;
}
