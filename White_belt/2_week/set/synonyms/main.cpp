#include <iostream>
#include <set>
#include <map>

using namespace std;

int main() {
    int Q;
    string command;
    map<string, set<string>> synonyms;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> command;
        if (command == "ADD") {
            string word1, word2;
            cin >> word1 >> word2;
            synonyms[word1].insert(word2);
            synonyms[word2].insert(word1);
        } else if (command == "COUNT") {
            string word;
            cin >> word;
            cout << synonyms[word].size() << endl;
        } else if (command == "CHECK") {
            string word1, word2;
            cin >> word1 >> word2;
            if (synonyms[word1].count(word2) == 1) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
