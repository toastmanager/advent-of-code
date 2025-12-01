#include <bits/stdc++.h>

using namespace std;

int main() {
    // string filePath = "1.example.txt";  // correct answer: 3
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

        curPos += direction * step;
        while (curPos < 0) curPos = 100 + curPos;
        while (curPos > 99) curPos = curPos - 100;
        if (curPos == 0) ++res;
    }

    cout << res;

    InputFile.close();
}