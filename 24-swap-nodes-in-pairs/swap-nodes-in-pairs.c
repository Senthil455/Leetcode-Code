/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;

    while (head && head->next){
        struct ListNode* first = head;
        struct ListNode* second = head->next;

        prev->next = second;
        first->next = second->next;
        second->next = first;

        prev = first;
        head = first->next;
    }
    return dummy.next;
}