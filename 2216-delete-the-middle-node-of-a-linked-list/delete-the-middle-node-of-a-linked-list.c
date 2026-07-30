/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteMiddle(struct ListNode* head) {
    struct ListNode* temp=head, *pre=head;
    int count=0;
    if(head->next==NULL) return NULL;
    while(temp){
        count++;
        temp=temp->next;
    }
    int del=count/2;
    del--;
    pre=head;
    temp=pre->next;
    while(del!=0){
        temp=temp->next;
        pre=pre->next;
        del--;
    }
    pre->next=temp->next;
    free(temp);
    return head;
}