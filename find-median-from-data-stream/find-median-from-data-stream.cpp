class MedianFinder {
public:
    priority_queue<int,vector<int>,greater<int>> minheap;
    priority_queue<int> maxheap;
    
    /** initialize your data structure here. */
    MedianFinder() 
    {
    }
    
    void addNum(int num) 
    {
        if(maxheap.empty())  
            maxheap.push(num);
        else
        {
            if(minheap.size() == maxheap.size())
            {
                if(num <= minheap.top())
                    maxheap.push(num);
                else
                {
                    maxheap.push(minheap.top());
                    minheap.pop();
                    minheap.push(num);
                }
            }
            else
            {
                if(num >= maxheap.top())
                    minheap.push(num);
                else
                {
                    minheap.push(maxheap.top());
                    maxheap.pop();
                    maxheap.push(num);
                }
            }
        }
    }
    
    double findMedian() 
    {
        double ans;
        
        if(minheap.size() == maxheap.size())
            ans = (minheap.top() + maxheap.top()) / 2.0;
        else
            ans = maxheap.top();
        
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */