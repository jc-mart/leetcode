/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    // Moving down the linked list, multiply number by 10
    unsigned long long int l1_sum = 0, l2_sum = 0, multiplier = 1, end = 0;
    struct ListNode *ptr1 = l1, *ptr2 = l2;

    while (!end) {
        l1_sum += ptr1->val * multiplier;
        multiplier *= 10;

        if ((ptr1 = ptr1->next) == NULL)
            end = 1;
    }

    multiplier = 1, end = 0;

    while (!end) {
        l2_sum += ptr2->val * multiplier;
        multiplier *= 10;

        if ((ptr2 = ptr2->next) == NULL)
            end = 1;
    }

    end = 0;

    l1_sum += l2_sum; // l1_sum carries the answer, l2_will get the pieces
    // Putting it back into a linked list, do the opposite and mod to get the remainder
    struct ListNode *ans = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *next = ans;

    while (!end) {
        l2_sum = l1_sum % 10;
        l1_sum /= 10;
        next->val = l2_sum;

        if (l1_sum != 0) {
            struct ListNode *following = (struct ListNode *)malloc(sizeof(struct ListNode));
            next->next = following;
            next = next->next;
        }
        else {
            next->next = NULL;
            end = 1;
        }
    }

    return ans;
}
