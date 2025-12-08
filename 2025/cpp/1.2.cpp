#include <bits/stdc++.h>

using namespace std;

int main() {
    // string filePath = "1.example.txt";  // correct answer: 6
    string filePath = "1.txt";
    string input;
    ifstream InputFile(filePath);
    int move, direction, step, res = 0, curPos = 50;

    while (getline(InputFile, input)) {
        if (input[0] == 'L')
            direction = -1;
        else
            direction = 1;

        input[0] = '0';
        move = stoi(input);

        res += int(move / 100);
        step = direction * (move % 100);

        if (curPos + step < 0) {
            if (curPos != 0) ++res;
            curPos += 100 + step;
        } else if (curPos + step > 99) {
            curPos += step - 100;
            ++res;
        } else if (curPos + step == 0) {
            curPos += step;
            ++res;
        } else {
            curPos += step;
        }
    }

    cout << res;

    InputFile.close();
}