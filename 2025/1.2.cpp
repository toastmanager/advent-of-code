/*
    This code gives incorrect answers
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    // string filePath = "1.example.txt";  // correct answer: 6
    string filePath = "1.txt";
    string input;
    ifstream InputFile(filePath);
    int step, direction, res = 0, curPos = 50;

    while (getline(InputFile, input)) {
        if (input[0] == 'L')
            direction = -1;
        else
            direction = 1;

        input[0] = '0';
        step = stoi(input);

        bool isZeroInitially = curPos == 0;
        bool flag = false;
        curPos += direction * step;
        while (curPos < 0) {
            curPos = 100 + curPos;
            if (!isZeroInitially || flag) ++res;
            flag = true;
        };
        while (curPos > 99) {
            curPos = curPos - 100;
            if (!isZeroInitially || flag) ++res;
            flag = true;
        }
        if (curPos == 0 && !flag) ++res;
    }

    cout << res;

    InputFile.close();
}