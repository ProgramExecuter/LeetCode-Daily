///////////////////////
///   Solution 1   ///
/////////////////////

// Time Complexity - O(N)
// Space Complexity - O(N)

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