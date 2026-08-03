struct Node* copyRandomList(struct Node* head) {
	struct Node *newHead = NULL;
    struct Node *tail = NULL;
    struct Node *curr;
    
    for (curr = head; curr; curr = curr->next->next){
        struct Node *new = malloc(sizeof(struct Node));
        new->next = curr->next;
        new->val = curr->val;
        curr->next = new;
    }
    
    for (curr = head; curr; curr = curr->next->next){
        if (curr->random == NULL){
            curr->next->random = NULL;
        } else {
            curr->next->random = curr->random->next;
        }
    }
    
    curr = head;
    
    while (curr){
        struct Node *newList = curr->next;
        curr->next = newList->next;
        newList->next = NULL;
        if (!newHead){
            newHead = newList;
        } else {
            tail->next = newList;
        }
        tail = newList;
        curr = curr->next;
    }
    
    
    return newHead;
    
}