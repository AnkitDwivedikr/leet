class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to act as the anchor for the new list
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        // Traverse both lists until one is fully processed
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        
        // Append the remaining elements of the non-empty list
        tail->next = (list1 != nullptr) ? list1 : list2;
        
        // Return the actual head of the merged list
        return dummy.next;
    }
};