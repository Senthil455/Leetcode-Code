/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int my_len(struct ListNode* head)
{
    int count;

    count = 0;
    while (head)
    {
        count++;
        head = head->next;
    }
    return (count);
}

struct ListNode* my_tail(struct ListNode* head)
{
    while (head->next)
        head = head->next;
    return (head);
}

struct ListNode* oddEvenList(struct ListNode* head)
{
    struct ListNode* prev_node;
    struct ListNode* next_node;
    struct ListNode* node;
    struct ListNode* tail;
    int len;
    int i;
    
    if (!head)
        return (NULL);
    if (!(head->next))
        return (head);
    prev_node = NULL;
    node = head;
    len = my_len(head);
    next_node = node->next;
    if (!(next_node->next))
        return (head);
    tail = my_tail(head);
    i = 0;
    while (i < len)
    {
        if (i % 2 != 0)
        {
            tail->next = node;
            node->next = NULL;
            tail = node;
            prev_node->next = next_node;
            node = next_node;
        }
        else
        {
            prev_node = node;
            node = node->next;
        }
        if (node)
            next_node = node->next;
        i++;
    }
    return (head);
}