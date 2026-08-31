/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1, -1};

        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return ans;

        ListNode* prev = head;
        ListNode* curr = head->next;

        int index = 1;
        int first = -1;
        int last = -1;
        int mini = INT_MAX;
        int maxi = -1;

        while (curr->next != nullptr) {
            int a = prev->val;
            int b = curr->val;
            int c = curr->next->val;

            bool critical = (b > a && b > c) || (b < a && b < c);

            if (critical) {
                if (first != -1) {
                    mini = min(mini, index - last);
                    maxi = index - first;
                }

                if (first == -1)
                    first = index;

                last = index;
            }

            prev = curr;
            curr = curr->next;
            index++;
        }

        if (mini == INT_MAX)
            return {-1, -1};

        return {mini, maxi};
    }
};//akd