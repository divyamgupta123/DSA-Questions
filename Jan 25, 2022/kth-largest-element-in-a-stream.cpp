//Problem Name:- Leetcode 703. Kth Largest Element in a Stream
//Problem Link:- https://leetcode.com/problems/kth-largest-element-in-a-stream/

class KthLargest {
private:
    priority_queue<int,vector<int>,greater<int>> pq;
    int k;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int i:nums){
            pq.push(i);
            if(pq.size()>k) pq.pop();
        }
    }

    int add(int val) {
        pq.push(val);
        if(pq.size()>k) pq.pop();
        return pq.top();
    }
};
