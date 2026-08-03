bool hasCycle(struct ListNode *head) {
    if (!head) return false;
    struct ListNode *slow = head, *fast = head;
    do {
        if (!fast || !fast->next) return false;
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);
    return true;
}
