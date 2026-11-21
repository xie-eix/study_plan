#pragma once

#include <cstddef>
#include <istream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using WordCount = std::pair<std::string, int>;

std::string normalize(const std::string& raw);
std::unordered_map<std::string, int> countWords(std::istream& in);
std::vector<WordCount>
sortedByCount(const std::unordered_map<std::string, int>& cnt);
void printCounts(const std::vector<WordCount>& items, std::size_t limit);