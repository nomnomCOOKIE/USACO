#include <bits/stdc++.h>
#This is the code for the USACO 2017 Bronze Contest of December Problem 3
using namespace std;

int main() {
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    int N;
    cin >> N;
    map <int, string> day_name;
    map <int, int> day_change;
    int counting = 0;
    int dummy1;
    string dummy2, dummy3;
    int dummy4;
    for (int i = 0; i < N; i++) {
        cin >> dummy1 >> dummy2 >> dummy3;
        if (dummy3[0] == '+') {
            dummy4 = dummy3[1] - '0';
        } else {
            dummy4 = dummy3[1] - '0';
            dummy4 *= -1;
        }
        day_name[dummy1] = dummy2;
        day_change[dummy1] = dummy4;
    }

    int mildred, bessie, elsie;
    mildred = 7;
    bessie = 7;
    elsie = 7;
    int leaderboard = 0;
    vector<string> new_winners;
    vector<string> previous_winners;
    previous_winners.push_back("Bobby");
    previous_winners.push_back("Bobby");
    previous_winners.push_back("Bobby");
    for (int i = 1; i <= 100; i++) {
        if (day_change[i] != 0) {
            if (day_name[i] == "Mildred") {
                mildred += day_change[i];
            } else if (day_name[i] == "Bessie") {
                bessie += day_change[i];
            } else {
                elsie += day_change[i];
            }
            //put greatest of values in list previous winners
            //if new value not in the list, update leaderboard and previous winners list
            if (max({mildred, bessie, elsie}) == mildred) {
                new_winners.push_back("Mildred");
            }
            if (max({mildred, bessie, elsie}) == bessie) {
                new_winners.push_back("Bessie");
            }
            if (max({mildred, bessie, elsie}) == elsie) {
                new_winners.push_back("Elsie");
            }

            //comparisons
            if (new_winners.size() != previous_winners.size()) {
                previous_winners.clear();
                for (int j = 0; j < new_winners.size(); j++) {
                    previous_winners.push_back(new_winners[j]);
                }
                leaderboard += 1;
            } else {
                for (int k = 0; k < new_winners.size(); k++) {
                    for (int p = 0; p < previous_winners.size(); p++) {
                        if (new_winners[k] == previous_winners[p]) {
                            counting += 1;
                        }
                    }
                }
                if (counting != new_winners.size()) {
                    for (int j = 0; j < new_winners.size(); j++) {
                        previous_winners.push_back(new_winners[j]);
                    }
                    leaderboard += 1;
                }
            }
            previous_winners.clear();
            for (int z = 0; z < new_winners.size(); z++) {
                previous_winners.push_back(new_winners[z]);
            }
            new_winners.clear();
            counting = 0;

        }
    }
    cout << leaderboard;
    return 0;
}
