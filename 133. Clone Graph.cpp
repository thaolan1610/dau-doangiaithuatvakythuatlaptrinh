class Solution {
public:
    unordered_map<Node*, Node*> mp;

    Node* dfs(Node* node) {
        if (!node) return nullptr;

        if (mp.count(node)) return mp[node];

        Node* copy = new Node(node->val);
        mp[node] = copy;

        for (Node* nei : node->neighbors) {
            copy->neighbors.push_back(dfs(nei));
        }

        return copy;
    }

    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
};