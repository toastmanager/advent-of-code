/*
    Well, looks like this code
    is not that weird
    */

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
    deque<ll> llToDeque(ll num);
    bool isInvalid(ll num);
    vector<ll> findInvalidIdsInRange(ll start, ll end);
    ll findInvalidIdsSumInRange(ll start, ll end);

   private:
    bool checkSeq(deque<ll>& digits, uint seqLen);
};

deque<ll> Solution::llToDeque(ll num) {
    deque<ll> res;
    while (num > 0) {
        res.push_front(num % 10);
        num /= 10;
    }
    return res;
}

bool Solution::checkSeq(deque<ll>& digits, uint seqLen) {
    if (digits.size() % seqLen != 0) {
        return false;
    }
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
    auto digits = this->llToDeque(num);
    for (auto i = 1; i <= digits.size() / 2; ++i) {
        if (this->checkSeq(digits, i)) {
            return true;
        }
    }
    return false;
}

vector<ll> Solution::findInvalidIdsInRange(ll start, ll end) {
    vector<ll> res = {};
    for (ll num = start; num <= end; ++num) {
        if (this->isInvalid(num)) {
            res.push_back(num);
        }
    }
    return res;
}

ll Solution::findInvalidIdsSumInRange(ll start, ll end) {
    ll res = 0;
    for (ll num = start; num <= end; ++num) {
        if (this->isInvalid(num)) {
            res += num;
        }
    }
    return res;
}

int main() {
    string line, fileName = "2.txt";
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