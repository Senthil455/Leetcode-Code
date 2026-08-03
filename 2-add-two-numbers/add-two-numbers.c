/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode dummy;
    struct ListNode* temp = &dummy;
    dummy.next = NULL;

    int carry = 0, sum = 0;

    while(l1 || l2 || carry){
        sum = carry;

        if(l1){
            sum += l1->val;
            l1 = l1->next;
        }
        if(l2){
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;

        temp->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp = temp->next;
        temp->val = sum % 10;
        temp->next = NULL;
    }

    return dummy.next;
}