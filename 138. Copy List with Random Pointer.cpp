class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        unordered_map<Node*, Node*> mp;

        Node* cur = head;

        // 1. clone node (chưa nối)
        while (cur) {
            mp[cur] = new Node(cur->val);
            cur = cur->next;
        }

        cur = head;

        // 2. gán next và random
        while (cur) {
            mp[cur]->next = mp[cur->next];
            mp[cur]->random = mp[cur->random];
            cur = cur->next;
        }

        return mp[head];
    }
};