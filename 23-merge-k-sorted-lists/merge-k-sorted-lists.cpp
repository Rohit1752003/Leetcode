class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        vector<int> arr;

        // flatten all values into arr
        for (ListNode* head : lists) {
            while (head) {
                arr.push_back(head->val);
                head = head->next;
            }
        }
        
        // if empty input
        if (arr.empty()) return nullptr;

        // sort all values
        sort(arr.begin(), arr.end());

        // build a new linked list
        ListNode* head = new ListNode(arr[0]);
        ListNode* curr = head;

        for (int i = 1; i < arr.size(); i++) {
            curr->next = new ListNode(arr[i]);
            curr = curr->next;
        }

        return head;
    }
};
