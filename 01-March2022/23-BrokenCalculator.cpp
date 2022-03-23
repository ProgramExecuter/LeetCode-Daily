class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int noOfMoves = 0;
        
        while(startValue != target) {
            if(target%2 == 0  &&  startValue < target) {
                target /= 2;
            }
            else {
                ++target;
            }
            ++noOfMoves;
        }
        
        return noOfMoves;
    }
};