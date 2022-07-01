#include <bits/stdc++.h>
using namespace std;

pair<int, int> afk = make_pair(-1, -1);

class Solution {
public:
    int minimumDistance(string word) {
        unordered_map<char, pair<int, int>> keyboard = createKeyboard();
        unordered_map<string, int> dp;

        pair<int, int> finger1, finger2;
        finger1 = finger2 = afk;

        return findDistance(word, finger1, finger2, keyboard, dp);
    }

    int findDistance(string word, pair<int, int> finger1, pair<int, int> finger2, unordered_map<char, pair<int, int>>& keyboard, unordered_map<string, int>& dp) {
        if (word.size() == 0) {
            return 0;
        }

        string hash = getHash(word, finger1, finger2);
        if (dp.find(hash) != dp.end()) {
            return dp[hash];
        }

        return dp[hash] = min(
            findDistance(&(word[1]), keyboard[word[0]], finger2, keyboard, dp) + distance(keyboard[word[0]], finger1),
            findDistance(&(word[1]), finger1, keyboard[word[0]], keyboard, dp) + distance(keyboard[word[0]], finger2)
        );
    }

    int distance(pair<int, int> a, pair<int, int> b) {
        if (a == afk || b == afk)
            return 0;

        return abs(a.first - b.first) + abs(a.second - b.second);
    }

    unordered_map<char, pair<int, int>> createKeyboard() {
        unordered_map<char, pair<int, int>> keyboard;
        char letter = 'A';

        for (int i = 0; letter <= 'Z'; i++) {
            for (int j = 0; j < 6 && letter <= 'Z'; j++) {
                keyboard[letter] = make_pair(i, j);
                letter++;
            }
        }

        return keyboard;
    }

    string getHash(string word, pair<int, int> f1, pair<int, int> f2) {
        return to_string(f1.first) + to_string(f1.second) + to_string(f2.first) + to_string(f2.second) + word;
    }
};