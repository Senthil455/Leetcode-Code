/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

void connect_helper(struct Node *root) 
{
    if (!root)
        return;

    static struct Node dummy;
    dummy.next = 0;

    struct Node *last = &dummy;
    while(root)
    {
        if (root->left)
            last = last->next = root->left;
        if (root->right)
            last = last->next = root->right;

        root = root->next;
    }

    connect_helper(dummy.next);
}


struct Node* connect(struct Node* root) 
{
	connect_helper(root);

    return root;
}