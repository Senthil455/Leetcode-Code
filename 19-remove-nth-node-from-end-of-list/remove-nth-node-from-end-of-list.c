/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int len=0;
    struct ListNode* temp=head;
    while(temp!=NULL){
        len ++;
        temp=temp->next;
    }
    if(n == len){
        temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    int out=len-n-1;
    if(n==1){
        temp=head;
        while(temp->next->next!= NULL){
            temp=temp->next;
        }
        temp->next=NULL;
        return head;
    }
    struct ListNode* pre=head;
    temp=pre->next;
    while(out!=0){
        pre=pre->next;
        temp=pre->next;
        out--;
    }
    pre->next= temp->next;
    free(temp);
    return head;
}