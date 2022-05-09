// Time Complexity =>
//                    Push  - O(N)
//                    Pop   - O(1)
//                    Top   - O(1)
//                    Empty - O(1)
//
// Space Complexity - O(N)

class MyStack {
    queue<int> q;
public:
    MyStack() {}
    
    void push(int x) {
        int n = q.size();
        q.push(x);
        
        while(n--) {                  // Pop all elements from front and put them in back
            int ele = q.front();      // except newly inserted one
            q.pop();
            q.push(ele);
        }
    }
    
    int pop() {                       // Simply pop from front
        int ele = q.front();
        q.pop();
        return ele;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
