#include <bits/stdc++.h>
using namespace std;
#define int int64_t

struct Node {
    int sum;
    Node() {
        sum = 0;
    }
    Node(int val) {
        sum = val;
    }
    void change(int val) {
        sum = val;
    }
};

struct SegTree {
    int tree_size;
    vector<Node> SegData;

    SegTree(int sz) {
        tree_size = 1;
        while (tree_size < sz) tree_size *= 2;
        SegData.assign(2 * tree_size, Node());
    }

    Node merge(Node &l, Node &r) {
        Node ans = Node();
        ans.sum = l.sum + r.sum;
        return ans;
    }

    void init(vector<int> &arr, int node1, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < arr.size()) {
                SegData[node1] = Node(arr[lx]);
            }
            return;
        }
        int mid = (rx + lx) / 2;
        init(arr, node1 * 2 + 1, lx, mid);
        init(arr, node1 * 2 + 2, mid, rx);
        SegData[node1] = merge(SegData[node1 * 2 + 1], SegData[node1 * 2 + 2]);
    }

    void init(vector<int> &arr) {
        init(arr, 0, 0, tree_size);
    }

    void set(int idx, int val, int node1, int lx, int rx) { // rx not included
        if (rx - lx == 1) {
            SegData[node1].change(val);
            return;
        }
        int mid = (lx + rx) / 2;
        if (idx < mid) {
            set(idx, val, node1 * 2 + 1, lx, mid);
        }
        else {
            set(idx, val, node1 * 2 + 2, mid, rx);
        }
        SegData[node1] = merge(SegData[node1 * 2 + 1], SegData[node1 * 2 + 2]);
    }

    void set(int idx, int val) {
        set(idx, val, 0, 0, tree_size);
    }

    Node get(int l, int r, int node1, int lx, int rx) { // rx not included
        if (lx >= l && rx <= r) return SegData[node1];
        if (lx >= r || rx <= l) return Node();
        int mid = (rx + lx) / 2;
        Node lf = get(l, r, node1 * 2 + 1, lx, mid);
        Node ri = get(l, r, node1 * 2 + 2, mid, rx);
        return merge(lf, ri);
    }

    Node get(int l, int r) {
        return get(l, r, 0, 0, tree_size);
    }
};

int32_t main() {
    return 0;
}