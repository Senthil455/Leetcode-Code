class MedianFinder {
public:
    priority_queue<int> l;
    priority_queue<int, vector<int>, greater<int>> r;
    void addNum(int x) {
        l.push(x);
        r.push(l.top());
        l.pop();
        if (r.size() > l.size()) {
            l.push(r.top());
            r.pop();
        }
    }
    double findMedian() {
        return l.size() > r.size() ? l.top() : (l.top() + r.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */