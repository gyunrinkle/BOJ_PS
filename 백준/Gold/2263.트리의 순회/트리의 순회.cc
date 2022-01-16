#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000;
int n;
int inorder[MAX + 1], postorder[MAX + 1], idx[MAX + 1];
map<int, pair<int, int>> tree;

void Input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> inorder[i];
        idx[inorder[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> postorder[i];
    }
}

void DivideAndConquer(int in_low, int in_high, int post_start, int post_end) {
    if (in_low > in_high || post_start > post_end) {
        return;
    }

    int left_tree_size, right_tree_size, left_child, right_child, root, root_idx;

    root = postorder[post_end];
    root_idx = idx[root];

    if (in_low == in_high || post_start == post_end) {
        tree[root] = {0, 0};
        return;
    }

    left_tree_size = root_idx - in_low;
    right_tree_size = in_high - root_idx;

    left_child = postorder[post_start + left_tree_size - 1];
    right_child = postorder[post_end - 1];

    if (left_child == right_child) {
        tree[root] = {0, right_child};
    }
    else {
        tree[root] = {left_child, right_child};
    }
    

    DivideAndConquer(in_low, root_idx - 1, post_start, post_start + left_tree_size - 1);
    DivideAndConquer(root_idx + 1, in_high, post_end - right_tree_size, post_end - 1);
    return;
}

void preorder(int root) {
    if (root == 0) {
        return;
    }
    cout << root << ' ';
    preorder(tree[root].first);
    preorder(tree[root].second);
}

void Solve() {
    Input();
    DivideAndConquer(1, n, 1, n);
    preorder(postorder[n]);
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    Solve();
    return 0;
}