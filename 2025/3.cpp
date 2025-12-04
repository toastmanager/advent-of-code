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
    ull resr = 0;
    for (ull r = 0; r < joltages.size() - 1; ++r) {
        if (joltages[r] > joltages[resr]) resr = r;
    }

    ull resl = resr + 1;
    for (ull l = resr + 2; l < joltages.size(); ++l) {
        if (joltages[l] > joltages[resl]) resl = l;
    }

    return joltages[resr] * 10 + joltages[resl];
}

int main() {
    // string filePath = "3.example.txt";  // Correct answer: 357
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