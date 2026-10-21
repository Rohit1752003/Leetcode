class MedianFinder {
    priority_queue<int> left ; 
    priority_queue<int , vector<int> , greater<int>> right;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        left.push(num);
        int top = left.top();
        left.pop();
        right.push(top);
        if(right.size() > left.size()){
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if(left.size() != right.size())return left.top();
        else{
         return double((left.top() + right.top())/2.0);
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */