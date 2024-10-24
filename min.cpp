#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


vector<int> getDenominations() {
    vector<int> denominations = {1, 2, 5, 10, 20, 50, 100, 500, 1000, 2000, 5000};
    sort(denominations.rbegin(), denominations.rend());
    return denominations;
}


map<int, int, greater<int>> computeChange(int amount, const vector<int>& denominations) {
    map<int, int, greater<int>> change;
    for (int denom : denominations) {
        int count = amount / denom;
        if (count > 0) {
            change[denom] = count;
            amount %= denom;
        }
    }
    return change;
}


void outputChange(const map<int, int, greater<int>>& change) {
    for (const auto& pair : change) {
        cout << pair.second << "*" << pair.first << endl;
    }
}

int main() {
    int X;
    cin >> X;
    vector<int> denominations = getDenominations();
    map<int, int, greater<int>> change = computeChange(X, denominations);
    outputChange(change);
    return 0;
}
