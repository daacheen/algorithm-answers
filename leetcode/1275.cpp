#include "cppincludes.h"



class Solution {
  public:
    string tictactoe(vector<vector<int>> &moves) {
        vector<vector<string>> map(3, vector<string>(3, ""));

        bool aMove = true;
        // simulate
        for (auto &move : moves) {
            string placed = aMove ? "X" : "O";
            map[move[0]][move[1]] = placed;

            // judge winner

            // row
            if (map[move[0]][0] == map[move[0]][1] &&
                map[move[0]][1] == map[move[0]][2]) {
                return map[move[0]][0] == "X" ? "A" : "B";
            }

            // column
            if (map[0][move[1]] == map[1][move[1]] &&
                map[1][move[1]] == map[2][move[1]]) {
                return map[0][move[1]] == "X" ? "A" : "B";
            }

            // diagonal
            if (map[1][1] != "" && map[0][0] == map[1][1] &&
                map[1][1] == map[2][2]) {
                return map[1][1] == "X" ? "A" : "B";
            }

            if (map[1][1] != "" && map[2][0] == map[1][1] &&
                map[1][1] == map[0][2]) {
                return map[1][1] == "X" ? "A" : "B";
            }

            aMove = !aMove;
        }

        // no winner now, if there is empty block, the game is not over
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (map[i][j] == "") {
                    return "Pending";
                }
            }
        }

        return "Draw";
    }
};