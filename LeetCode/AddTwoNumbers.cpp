#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = l1;
        ListNode* lastValidNode = l1;

        int sum;
        int exceeded = 0;
        while (l1 != NULL && l2 != NULL) {
            sum = l1->val + l2->val + exceeded;
            l1->val = sum % 10;
            exceeded = sum / 10;

            lastValidNode = l1;
            l1 = l1->next;
            l2 = l2->next;
        }

        if (l1 == NULL && l2 == NULL) {
            if (exceeded) {
                lastValidNode->next = new ListNode(exceeded);
            }

            return ans;
        }
        
        if (l1 == NULL) {
            l1 = lastValidNode;
            l1->next = l2;
            l1 = l2;
        }

        while (l1 != NULL) {
            sum = l1->val + exceeded;
            l1->val = sum % 10;
            exceeded = sum / 10;

            lastValidNode = l1;
            l1 = l1->next;
        }

        if (exceeded) {
            lastValidNode->next = new ListNode(exceeded);
        }

        return ans;
    }
};