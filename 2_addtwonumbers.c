/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    // Moving down the linked list, multiply number by 10
    int l1_val = 0, l2_val = 0, sum = 0, carry = 0, end = 0;
    struct ListNode *ptr1 = l1, *ptr2 = l2;
    struct ListNode *ans = (struct ListNode *)malloc(sizeof(struct ListNode)), *next = ans;

    while (1) {
        l1_val = (ptr1 != NULL) ? ptr1->val : 0;
        l2_val = (ptr2 != NULL) ? ptr2->val : 0;

        sum = l1_val + l2_val + carry;
        carry = sum / 10;
        next->val = sum % 10;

        if (ptr1 == NULL)
            ;
        else if ((ptr1 = ptr1->next) == NULL)
            end++;
        if (ptr2 == NULL)
            ;
        else if ((ptr2 = ptr2->next) == NULL)
            end++;

        if (end >= 2) {
            if (carry) {
                struct ListNode *following = (struct ListNode *)malloc(sizeof(struct ListNode));
                next->next = following;
                next = next->next;
                next->val = carry;
            }
            next->next = NULL;
            break;
        }

        struct ListNode *following = (struct ListNode *)malloc(sizeof(struct ListNode));
        next->next = following;
        next = next->next;
    }

    return ans;
}
