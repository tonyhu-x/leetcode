#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <utility>

using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    // first build the dictionary
    unordered_map<string, vector<string>> inters;

    for (string word : wordList) {
        for (int i = 0; i < word.size(); i++) {
            string inter = word;
            inter[i] = '*';
            inters[inter].push_back(word);
        }
    }

    unordered_set<string> visited;
    queue<pair<string, int>> nextq;
    nextq.emplace(beginWord, 1);

    while (!nextq.empty()) {
        string word = nextq.front().first;
        int steps = nextq.front().second;
        nextq.pop();

        if (word == endWord) {
            return steps;
        }

        if (visited.find(word) != visited.end()) {
            continue;
        }
        
        for (int i = 0; i < word.size(); i++) {
            string inter = word;
            inter[i] = '*';
            if (inters.find(inter) != inters.end()) {
                for (string s : inters[inter]) {
                    nextq.emplace(s, steps + 1);
                }
            }
        }
        visited.insert(word);
    }

    return 0;
}

int main() {
    vector<string> wordList {"a", "b", "c"};
    cout << ladderLength("a", "c", wordList) << endl;
}