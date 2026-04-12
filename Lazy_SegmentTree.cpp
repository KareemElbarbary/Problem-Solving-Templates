//
// Note : Right (r) in this Segment Not Including
//

#define int int64_t

struct Node {
    int val, lazy = 0;
    bool islazy = 0;
    Node() {
        val = 0;
    }
    Node(int value) {
        val = value;
    }
    void update(int x, int lx, int rx) {
        val += (rx - lx) * x;
        islazy = 1;
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
        ans.val = l.val + r.val;
        return ans;
    }

    void init(vector<int> &arr, int node, int lx, int rx) {  // rx not included
        if (rx - lx == 1) {
            if (lx < arr.size()) {
                SegData[node] = Node(arr[lx]);
            }
            return;
        }
        int mid = (rx + lx) / 2;
        init(arr, node * 2 + 1, lx, mid);
        init(arr, node * 2 + 2, mid, rx);
        SegData[node] = merge(SegData[node * 2 + 1], SegData[node * 2 + 2]);
    }

    void init(vector<int> &arr) {
        init(arr, 0, 0, tree_size);
    }

    void propagate(int node, int lx, int rx) {  // rx not included
        if (rx - lx == 1 || SegData[node].islazy == 0) return;

        int mid = (rx + lx) / 2;
        SegData[node * 2 + 1].update(SegData[node].lazy, lx, mid);
        SegData[node * 2 + 2].update(SegData[node].lazy, mid, rx);

        SegData[node].lazy = SegData[node].islazy = 0;
    }

    void update(int l, int r, int val, int node, int lx, int rx) {   // rx not included
        propagate(node, lx, rx);
        if (lx >= r || rx <= l) return;
        if (lx >= l && rx <= r) {
            SegData[node].update(val, l, r);
            return;
        }
        int mid = (rx + lx) / 2;
        update(l, r, val, node * 2 + 1, lx, mid);
        update(l, r, val, node * 2 + 2, mid, rx);
        SegData[node] = merge(SegData[node * 2 + 1], SegData[node * 2 + 2]);
    }

    void update(int l, int r, int val) {    // rx not included
        update(l, r, val, 0, 0, tree_size);
    }

    Node get(int l, int r, int node, int lx, int rx) { // rx not included
        propagate(node, lx, rx);
        if (lx >= l && rx <= r) return SegData[node];
        if (lx >= r || rx <= l) return Node();
        int mid = (rx + lx) / 2;
        Node lf = get(l, r, node * 2 + 1, lx, mid);
        Node ri = get(l, r, node * 2 + 2, mid, rx);
        return merge(lf, ri);
    }

    Node get(int l, int r) {
        return get(l, r, 0, 0, tree_size);
    }
};