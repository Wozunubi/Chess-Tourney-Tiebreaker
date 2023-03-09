#include <bits/stdc++.h>
#include <string>
using namespace std;

int main() {
    //don't judge me jacob i coded this in like 20 minutes during the tournament

    const int gameNum = 50, playerNum = 20;
    string line, val, in[gameNum][4];
    unordered_map<string, double> score, tiebreak;
    ifstream fin("../Pairings Spreadsheet.csv");

    if (fin.is_open()) {
        int i = 0;
        while (getline(fin, line)) {
            stringstream str(line);
            int j = 0;
            while (getline(str, val, ',')) {
                in[i][j] = val;
                j++;
            }
            i++;
        }
    } else {
        cout << "cannot open .csv" << "\n";
    }

    for (int i = 0; i < playerNum/2; i++) {
        score[in[i][0]] = 0.0;
        score[in[i][2]] = 0.0;
        tiebreak[in[i][0]] = 0.0;
        tiebreak[in[i][2]] = 0.0;
    }

    for (auto &i : in) {
        score[i[0]] += stod(i[1]);
        score[i[2]] += stod(i[3]);
    }

    for (auto &i : in) {
        if (i[1] == "1.0") {
            tiebreak[i[0]] += score[i[2]];
        } else if (i[1] == "0.0") {
            tiebreak[i[2]] += score[i[0]];
        } else {
            tiebreak[i[0]] += 0.5*(score[i[2]]-0.5);
            tiebreak[i[2]] += 0.5*(score[i[0]]-0.5);
        }
    }

    for (auto &x : tiebreak) {
        cout << x.first << " " << x.second << endl;
    }

    if (tiebreak.size() != playerNum) {
        cout << "something is broken, probably misspelt name" << endl;
    }

    return 0;
}
