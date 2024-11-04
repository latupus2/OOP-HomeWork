#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    vector<std::string> words;
    string word;

    while (getline(cin, word) && !word.empty()) {
        words.push_back(word);
    }

    set<char> common_letters;
    if (!words.empty()) {
        for (char ch : words[0]) {
            common_letters.insert(ch);
        }

        for (size_t i = 1; i < words.size(); ++i) {
            set<char> current_letters;
            for (char ch : words[i]) {
                current_letters.insert(ch);
            }


            set<char> intersection;
            for (char ch : common_letters) {
                if (current_letters.count(ch)) {
                    intersection.insert(ch);
                }
            }
            common_letters = intersection;
        }
    }

    for (char ch : common_letters) {
        cout << ch;
    }

    return 0;
}
