/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nodesBetweenCriticalPoints(struct ListNode* head, int* returnSize) {
    int cp1 = -1, cp2 = -1, cp3 = -1, a, b, c, i=1;
    int *ans = (int*) malloc(2 * sizeof(int));
    ans[0] = -1; ans[1] = -1;
    *returnSize = 2;
    if (head->next == NULL) return ans;
    a = head->val;
    b = head->next->val;
    head = head->next->next;
    while (head != NULL) {
        c = head->val;
        if ((b > a && b > c) || (b < a && b < c)) {
            if (cp1 < 0) {
                cp1 = i;
            } else if (cp2 < 0) {
                cp2 = i;
                ans[0] = cp2 - cp1;
                ans[1] = ans[0];
            } else {
                if (cp3 > 0) cp2 = cp3;
                cp3 = i;
                if (cp3 - cp2 < ans[0]) ans[0] = cp3 - cp2;
                ans[1] = cp3 - cp1;
            }
        }
        a = b;
        b = c;
        ++i;
        head = head->next;
    }
    return ans;
}