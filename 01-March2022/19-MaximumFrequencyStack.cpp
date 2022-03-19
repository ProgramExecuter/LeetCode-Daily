class FreqStack {
    map<int, int> valCnt;
    map<int, stack<int>> cntStack;
    int maxCnt = 0;
public:
    
    void push(int val) {
        int cnt = valCnt[val] + 1;
        valCnt[val] = cnt;                          // new val count
        
        cntStack[cnt].push(val);                    // Push 'val' to stack
        maxCnt = max(maxCnt, cnt);                  // New max count
    }
    
    int pop() {
        int res = cntStack[maxCnt].top();
        cntStack[maxCnt].pop();         // Pop element from stack
        --valCnt[res];                  // Decrease its frequency
        
        // If stack becomes empty, then erase it from MAP
        // and decrement max count
        if(cntStack[maxCnt].empty()) {
            cntStack.erase(maxCnt);
            --maxCnt;
        }
        
        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */