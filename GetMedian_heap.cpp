// Add Element O(log(n)) ---- getMedian O(1)
class GetMedian {
    priority_queue<int> L_maxheap;
    priority_queue<int, vector<int>, greater<int>> R_minheap;
    int sz = 0;
public:
    void add(int x) {
        sz++;
        L_maxheap.push(x);
        if (!L_maxheap.empty() && !R_minheap.empty() && L_maxheap.top() > R_minheap.top()) {
            R_minheap.push(L_maxheap.top());
            L_maxheap.pop();
        }
        if (L_maxheap.size() > R_minheap.size() + 1) {
            R_minheap.push(L_maxheap.top());
            L_maxheap.pop();
        }
        if (R_minheap.size() > L_maxheap.size() + 1) {
            L_maxheap.push(R_minheap.top());
            R_minheap.pop();
        }
    }

    int get() {
        if (L_maxheap.size() > R_minheap.size()) return L_maxheap.top();
        if (R_minheap.size() > L_maxheap.size()) return R_minheap.top();
        return (L_maxheap.top() + R_minheap.top()) / 2;
    }

    int getSize() {
        return sz;
    }
};