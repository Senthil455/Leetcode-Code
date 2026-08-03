/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* head, *temp;
    head = temp =NULL;
    if (!list1) return list2;
    if (!list2) return list1;

    if(list1->val <= list2-> val){ 
        head=list1;
        list1= list1->next;
    }
    else{
        head=list2;
        list2= list2->next;
    }
    temp = head;
    while(list1 !=NULL && list2 !=NULL){
        if(list1->val <= list2->val){
            temp->next= list1;
            list1= list1->next;
        }
        else if(list2->val < list1->val){
            temp->next = list2;
            list2= list2->next;
        }
        temp=temp->next;
    }
    if(list1 == NULL)
        temp->next= list2;
    else
        temp->next= list1;
    return head;
}