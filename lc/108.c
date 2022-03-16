typedef struct TreeNode node;

node * helper(int * nums, int left, int right)
{
    if(left > right)
        return 0;
    int mid = (left + right) / 2;
    node * root = malloc(sizeof(node));
    root->val = nums[mid];
    root->left = helper(nums, left, mid - 1);
    root->right = helper(nums, mid + 1, right);
    return root;
}

node * sortedArrayToBST(int * nums, int nums_size)
{
    return helper(nums, 0, nums_size - 1);
}
