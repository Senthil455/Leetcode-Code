/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int count_nodes(struct ListNode* head, int left, int right)
{
    int i;
    int len;
    struct ListNode* node;

    node = head;
    i = 0;
    len = 1;
    while (node)
    {
        if (len >= left && len <= right)
            i++;
        node = node->next;
        len++;
    }
    return (i);
}

int *memory_allocation(struct ListNode* head, int left, int right)
{
    struct ListNode* node;
    int *total;
    int i;
    int len;

    len = 1;
    node = head;
    i = 0;
    total = malloc(count_nodes(head, left, right) * sizeof(int));
    if (!total)
        return (0);
    while (node)
    {
        if (len >= left && len <= right)
        {
            total[i] = node->val;
            i++;
        }
        node = node->next;
        len++;
    }
    return (total);
}

struct ListNode* switching(struct ListNode* head, int left, int right, int *total)
{
    struct ListNode* node;
    int count;
    int index;

    node = head;
    count = (count_nodes(head, left, right) - 1);
    index = 0;
    while (node)
    {
        if (left - 1 == index)
        {
            while(count >= 0)
            {
                node->val = total[count];
                count--;
                node = node->next;
            }
        }
        else
            node = node->next;
        index++;
    }
    return (head);
}

struct ListNode* reverseBetween(struct ListNode* head, int left, int right)
{
    if (!head)
        return (NULL);
    if (left == right)
        return (head);
    return (switching(head, left, right, memory_allocation(head, left, right)));
}