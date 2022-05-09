///////////////////////
///   Solution 1   ///
/////////////////////

// Time Complexity - O(N)
// Space Complexity - O(N)

//  *** This is PROACTIVE way  =>  where we constructed solution, before any query

class NestedIterator {
public:
    queue<int> nums;
    
    void open(vector<NestedInteger> &nestedList) {
        if(nestedList.empty())    return;
        
        for(auto i : nestedList) {                          // Traverse each 'NestedInteger'
            if(i.isInteger()) {
                nums.push(i.getInteger());                  // If it's integer, then push it to queue
            }
            else {
                open(i.getList());                          // Else, convert it to LIST, and then open that LIST
            }
        }
    }
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        open(nestedList);                                   // Open the nested List
    }
    
    int next() {
        int res = nums.front();                             // Get 'front' number
        nums.pop();
        
        return res;
    }
    
    bool hasNext() {
        return !nums.empty();
    }
};




///////////////////////
///   Solution 2   ///
/////////////////////

// Time Complexity - O(N)
// Space Complexity - O(N)

//  *** This is LAZY way  =>  where we construct solution, when asked for query

class NestedIterator {
public:
    stack<NestedInteger> st;                                    // Used to store the integers and list(which are destructured to integers)
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        if (nestedList.empty())   return;

        for(int i=(nestedList.size()-1); i>=0; i--)             // We put the elements in stack in reverse order, to construct right order result
            st.push(nestedList[i]);
    }
    
    int next() {
        int res = st.top().getInteger();                        // Get number on top of stack
        st.pop();
        
        return res;
    }
    
    bool hasNext() {
        while(!st.empty()  &&  !st.top().isInteger()) {         // If stack's top is not an integer
            vector<NestedInteger> tmp = st.top().getList();     // Get list at top of stack
            st.pop();

            for(int i = tmp.size()-1; i >= 0; i--)              // Put the elements from list to the stack
                st.push(tmp[i]);
        }
        
        return !st.empty();
    }
};
