#include <math.h>

#include <fstream>
#include <iostream>
#include <vector>

#define uint unsigned int
#define ll long long
#define ull unsigned long long

using namespace std;

class Solution {
   public:
    vector<int> stringToIntVector(string& str);
    ull findBiggestJoltage(vector<int>& joltages);
};

vector<int> Solution::stringToIntVector(string& str) {
    vector<int> res;
    for (auto s : str) {
        res.push_back(int(s - '0'));
    }
    return res;
}

ull Solution::findBiggestJoltage(vector<int>& joltages) {
    ull res = 0;
    vector<int> indexes(13, -1);
    for (uint i = 0; i < 12; ++i) {
        uint initIndex = indexes[i] + 1;
        ull resj = initIndex;
        for (ull j = initIndex; j < joltages.size() - 11 + i; ++j) {
            if (joltages[j] > joltages[resj]) resj = j;
        }
        indexes[i + 1] = resj;
        res += joltages[resj] * pow(10, 11 - i);
    }
    return res;
}

int main() {
    // string filePath = "3.example.txt";  // Correct answer: 3121910778619
    string filePath = "3.txt";
    ifstream File(filePath);
    string joltagesString;

    ull res = 0;

    while (getline(File, joltagesString)) {
        auto joltages = Solution().stringToIntVector(joltagesString);
        res += Solution().findBiggestJoltage(joltages);
    }

    cout << res;

    File.close();
}