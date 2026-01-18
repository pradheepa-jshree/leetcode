class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, 
            function<bool(ListNode*, ListNode*)>> pq(
            [](auto a, auto b){ return a->val > b->val; });

        for (auto l : lists)
            if (l) pq.push(l);

        ListNode dummy, *tail = &dummy;

        while (!pq.empty()) {
            auto node = pq.top(); pq.pop();
            tail->next = node;
            tail = node;
            if (node->next) pq.push(node->next);
        }
        return dummy.next;
    }
};
