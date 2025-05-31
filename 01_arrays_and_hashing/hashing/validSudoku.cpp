/*
Link: https://leetcode.com/problems/valid-sudoku/

Have a HT to store freq. Do separate checks for all.

For the 3x3 groups. Create b1 and b2 which will have indices 
(0,0), (0,3), (0,6), (3,0), (3,3), (3,6), (6,0), (6,3), (6,6)

Then for each (b1,b2) combo, check the next 2 indices up and down. 

So there will 4 for loops and complexity will be O(n^4), but it 
still passes in 3ms. You might feel uncomfortable writing 
4 nested for loops after months of facing TLE, but it is what it is.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,int> check;
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] != '.') {
                    check[board[i][j] - '0']++;
                }
            }
            for(auto item:check) {
                if(item.second > 1) {
                    return false;
                }     
            }
            for(auto& item:check) {
                item.second = 0;
            }
        }

        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[j][i] != '.') {
                    check[board[j][i] - '0']++;
                }
            }
            for(auto& item:check) {
                if(item.second > 1) {
                    return false;
                }     
            }
            for(auto& item:check) {
                item.second = 0;
            }
        }

        for(int b1 = 0; b1 < board.size(); b1+=3) {
            for(int b2 = 0; b2 < board.size(); b2+=3) {
                for(int i = b1; i <= b1+2; i++) {
                    for(int j = b2; j <= b2+2; j++) {
                        if(board[i][j] != '.') {
                            check[board[i][j] - '0']++;
                        }
                    }
                }
                for(auto& item:check) {
                    if(item.second > 1) {
                        return false;
                    }     
                }
                for(auto& item:check) {
                    item.second = 0;
                }
            }
        }

        return true;
    }
};