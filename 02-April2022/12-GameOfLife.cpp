// Time Complexity - O(m * n)
// Space Complexity - O(m * n)

class Solution {
public:
    int inRangeAndLive(vector<vector<int>>& board, int rowIdx, int colIdx) {
        int rows = board.size();
        int cols = board[0].size();
        
        int firstRowIdx = 0;
        int lastRowIdx  = rows-1;
        
        int firstColIdx = 0;
        int lastColIdx  = cols - 1;
        
        if(!( rowIdx >= firstRowIdx && rowIdx <= lastRowIdx &&
              colIdx >= firstColIdx && colIdx <= lastColIdx
            )
          )
            return -1;
        
        // Return value of board IDX
        return board[rowIdx][colIdx];
    }
    bool isLive(vector<vector<int>>& board, int rowIdx, int colIdx) {
        int rows =    board.size();
        int cols = board[0].size();
        
        int upperRowIdx = rowIdx - 1;
        int lowerRowIdx = rowIdx + 1;
        int backColIdx  = colIdx - 1;
        int nextColIdx  = colIdx + 1;
        
        // Neighbours of the given IDX
        int neighbourArray[8][2] = {
            {upperRowIdx, backColIdx},  // Top Left
            {upperRowIdx, colIdx},      // Top
            {upperRowIdx, nextColIdx},  // Top Right
            {rowIdx, nextColIdx},       // Right
            {lowerRowIdx, nextColIdx},  // Bottom Right
            {lowerRowIdx, colIdx},      // Bottom
            {lowerRowIdx, backColIdx},  // Bottom Left
            {rowIdx, backColIdx}        // Left
        };
        
        int firstNeighbour = 0;
        int lastNeighbour = 7;
        
        int neighbour = 0;
        
        // Counting Neighbours
        for(int itr = firstNeighbour; itr <= lastNeighbour; ++itr) {
            int x = neighbourArray[itr][0];
            int y = neighbourArray[itr][1];
            
            if(inRangeAndLive(board, x, y) == 1)
                neighbour++;
        }
        
        // For Reproduction
        if(board[rowIdx][colIdx] == 0) {
            if(neighbour == 3)
                return true;
            return false;
        }        
        if(neighbour < 2 || neighbour > 3) {
            return false;
        }
        else {
            return true;
        }
    }
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        
        vector<vector<int>> tmpBoard(rows , vector<int> (cols, 0));
        
        int firstRowIdx = 0;
        int lastRowIdx  = rows-1;
        
        int firstColIdx = 0;
        int lastColIdx  = cols - 1;
        
        // Assignment of LIVE/DEAD
        for(int rowNo = firstRowIdx; rowNo <= lastRowIdx; ++rowNo) {
            for(int colNo = firstColIdx; colNo <= lastColIdx; ++colNo) {
                if(isLive(board, rowNo, colNo))
                    tmpBoard[rowNo][colNo] = 1;
                else
                    tmpBoard[rowNo][colNo] = 0;
            }
        }
        
        // Assigning to Board
        for(int rowNo = firstRowIdx; rowNo <= lastRowIdx; ++rowNo) {
            for(int colNo = firstColIdx; colNo <= lastColIdx; ++colNo) {
                board[rowNo][colNo] = tmpBoard[rowNo][colNo];
            }
        }
    }
};