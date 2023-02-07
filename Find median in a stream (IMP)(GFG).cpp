class Solution
{
    public:
    //Function to insert heap.
    
    // need to create two containers
    // one smaller(max heap)
    // another greater (min heap)
    // these both will be implemented through priority queue
    
    // max_heap will contain the extra element (median)
    // if size is eqaul then take median 
    
    priority_queue<int> s;
    priority_queue<int,vector<int>, greater<int>> g; //syntax for min_heap
    int size=0;
    
    
    void insertHeap(int &x)
    {
        // we need to check ki insert kis container me krna hai
        // it's mainly depend upon the size of container
        // [ we want that extra element to be inserted innto the smaller one]
        
        // case 1: size small < greater size
        
        if(size==0){
            s.push(x);
        }else{
        
            if(s.size() > g.size()){
               
                if(x < s.top()){
                    g.push(s.top());
                    s.pop();
                    s.push(x);
                    
                }else{
                    g.push(x);
                    
                }
            }else{
                
                if(x > s.top()){
                    g.push(x);
                    int t= g.top();
                    g.pop();
                    s.push(t);
                    
                    
                }else{
                    s.push(x);
                    
                }
            }
        }
        size++;
        
    }
    
    //Function to balance heaps.
    // void balanceHeaps()
    // {
        
    // }
    
    //Function to return Median.
    double getMedian()
    {
        
        if(size%2!=0){
            return (double)s.top();
        }else{
            return (s.top() + g.top())/2.0;
        }
    }
};
