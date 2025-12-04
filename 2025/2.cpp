/*
    I tried to do a good quality code
    but i understood task not quite right
    so there is some weird code
    */

#include <math.h>

#include <deque>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#define uint unsigned int
#define ll long long

using namespace std;

class Solution {
   public:
    deque<ll> intToDeque(ll num);
    bool isInvalid(ll num);
    vector<ll> findInvalidIdsInRange(ll start, ll end);
    ll findInvalidIdsSumInRange(ll start, ll end);

   private:
    bool checkSeq(deque<ll>& digits, unsigned int seqLen);
};

deque<ll> Solution::intToDeque(ll num) {
    deque<ll> res;
    while (num > 0) {
        res.push_front(num % 10);
        num /= 10;
    }
    return res;
}

bool Solution::checkSeq(deque<ll>& digits, unsigned int seqLen) {
    for (uint i = 0; i < seqLen; ++i) {
        for (uint j = 1; j < digits.size() / seqLen; ++j) {
            if (digits[i + seqLen * j] != digits[i]) {
                return false;
            }
        }
    }
    return true;
}

bool Solution::isInvalid(ll num) {
    auto digits = this->intToDeque(num);
    if (digits.size() % 2 == 0 && this->checkSeq(digits, digits.size() / 2)) {
        return true;
    }
    return false;
}

vector<ll> Solution::findInvalidIdsInRange(ll start, ll end) {
    vector<ll> res = {};
    for (auto num = start; num <= end; ++num) {
        if (this->isInvalid(num)) {
            res.push_back(num);
        }
    }
    return res;
}

ll Solution::findInvalidIdsSumInRange(ll start, ll end) {
    ll res = 0;
    for (auto num = start; num <= end; ++num) {
        if (this->isInvalid(num)) {
            res += num;
        }
    }
    return res;
}

int main() {
    string line, fileName = "2.example.txt";
    ifstream File(fileName);
    ll res = 0;
    while (getline(File, line, ',')) {
        stringstream stream(line);
        string rangeCorner;
        pair<ll, ll> range;

        getline(stream, rangeCorner, '-');
        range.first = stoll(rangeCorner);
        getline(stream, rangeCorner, '-');
        range.second = stoll(rangeCorner);

        res += Solution().findInvalidIdsSumInRange(range.first, range.second);
    }
    cout << res;
    File.close();
}