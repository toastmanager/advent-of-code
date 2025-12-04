#include <fstream>
#include <iostream>
#include <vector>

#define uint unsigned int

using namespace std;

class Solution {
   public:
    size_t rows, cols;
    vector<vector<char>> matrix;
    bool isAccessible(size_t row, size_t col);
    int accessibleRollsCount();
};

bool Solution::isAccessible(size_t row, size_t col) {
    uint paperRolls = 0;
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1},
                                         {0, -1}, {1, 1}, {-1, -1},
                                         {1, -1}, {-1, 1}};  // {row, col}

    for (auto [dr, dc] : directions) {
        int nr = row + dr, nc = col + dc;
        if (nr < 0 or nr >= rows or nc < 0 or nc >= cols) {
            continue;
        }
        if (matrix[nr][nc] == '@') ++paperRolls;
    }

    return paperRolls < 4;
}

int Solution::accessibleRollsCount() {
    uint res = 0;
    for (auto row = 0; row < rows; ++row) {
        for (auto col = 0; col < cols; ++col) {
            if (matrix[row][col] == '@' && isAccessible(row, col)) ++res;
        }
    }
    return res;
};

int main() {
    // string filePath = "4.example.txt";  // Correct answer: 13
    string filePath = "4.txt";
    string row;
    ifstream InputFile(filePath);
    auto solution = Solution();

    while (getline(InputFile, row)) {
        vector<char> rowVector;
        for (auto c : row) {
            rowVector.push_back(c);
        }
        solution.matrix.push_back(rowVector);
    }

    solution.rows = solution.matrix.size();
    solution.cols = solution.matrix[0].size();

    cout << solution.accessibleRollsCount();

    InputFile.close();
}