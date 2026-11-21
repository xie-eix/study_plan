#include "word_counter.h"

#include <algorithm>
#include <cctype>
#include <iostream>

std::string normalize(const std::string& raw) {
    std::string out;
    out.reserve(raw.size());
    for (char ch : raw) {
        unsigned char c = static_cast<unsigned char>(ch);
        if (std::isalnum(c)) {
            out.push_back(static_cast<char>(std::tolower(c)));
        }
    }
    return out;
}

std::unordered_map<std::string, int> countWords(std::istream& in) {
    std::unordered_map<std::string, int> cnt;
    std::string w;
    while (in >> w) {
        std::string key = normalize(w);
        if (!key.empty()) {
            ++cnt[key];
        }
    }
    return cnt;
}

std::vector<WordCount>
sortedByCount(const std::unordered_map<std::string, int>& cnt) {
    std::vector<WordCount> items(cnt.begin(), cnt.end());
    std::sort(items.begin(), items.end(),
              [](const WordCount& a, const WordCount& b) {
                  if (a.second != b.second) return a.second > b.second;
                  return a.first < b.first;
              });
    return items;
}

void printCounts(const std::vector<WordCount>& items, std::size_t limit) {
    std::size_t n = std::min(limit, items.size());
    for (std::size_t i = 0; i < n; ++i) {
        std::cout << items[i].first << " " << items[i].second << "\n";
    }
}