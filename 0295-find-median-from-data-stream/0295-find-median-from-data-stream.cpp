class MedianFinder {
public:
    priority_queue <int, vector<int>, greater<int>> minHeap;
    priority_queue <int> maxHeap;
    MedianFinder() {
    }
    
    void addNum(int num) {
        // push the first element in maxHeap
        if (maxHeap.empty() || maxHeap.top() > num){
            maxHeap.push(num);
        }
        else{
            minHeap.push(num);
        }
        // if maxHeap contains 2 more element than the minHeap, push the top element of maxHeap in minHeap then pop it from the maxHeap
        if (maxHeap.size() > minHeap.size() + 1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        // if minHeap contains 2 more element than the maxHeap, push the top element of minHeap in maxHeap then pop it from the minHeap
        else if (minHeap.size() > maxHeap.size() + 1){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        // median when both heaps contain equal number of elements
        if (maxHeap.size() == minHeap.size()){
            // when maxHeap is empty
            if (maxHeap.empty()){
                return 0;
            }
            // calculating the median
            else{
                double median =(maxHeap.top() + minHeap.top()) / 2.0;
                return median; 
            }
        }
        else{
            // if maxHeap contains more elements than minHeap then maxHeap.top() is the ans
            if (maxHeap.size() > minHeap.size()){
                return maxHeap.top();
            }
            // if minHeap contains more elements than maxHeap then minHeap.top() is the ans
            else {
                return minHeap.top();
            }
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */