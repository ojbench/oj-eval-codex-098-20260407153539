#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
    Node(int v): val(v), left(nullptr), right(nullptr) {}
};

Node* insertNode(Node* root, int v) {
    if (!root) return new Node(v);
    if (v < root->val) {
        root->left = insertNode(root->left, v);
    } else if (v > root->val) {
        root->right = insertNode(root->right, v);
    }
    return root;
}

bool kthLargest(Node* root, int k, int &ans) {
    // Reverse inorder: right, root, left
    vector<Node*> st;
    Node* cur = root;
    while (cur || !st.empty()) {
        while (cur) { st.push_back(cur); cur = cur->right; }
        cur = st.back(); st.pop_back();
        if (--k == 0) { ans = cur->val; return true; }
        cur = cur->left;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> nums;
    nums.reserve(8);
    long long x;
    while (nums.size() < 8 && (cin >> x)) {
        nums.push_back(x);
    }

    if (nums.size() != 8) {
        return 0; // invalid input; per spec, not expected
    }

    Node* root = nullptr;
    for (int i = 0; i < 7; ++i) {
        root = insertNode(root, (int)nums[i]);
    }
    int cnt = (int)nums[7];

    int ans = 0;
    if (cnt <= 0) {
        // out of spec, but avoid undefined
        cout << 0;
        return 0;
    }
    bool ok = kthLargest(root, cnt, ans);
    if (ok) {
        cout << ans;
    }
    return 0;
}

