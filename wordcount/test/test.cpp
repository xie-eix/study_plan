#include "word_counter.h"

#include <cassert>
#include <sstream>

int main() {
    // 用例 1：基本计数
    {
        std::istringstream in("the cat and the dog");
        auto cnt = countWords(in);
        assert(cnt["the"] == 2);
        assert(cnt["cat"] == 1);
        assert(cnt.size() == 4);
    }

    // 用例 2：大小写与标点
    {
        std::istringstream in("Hello, HELLO! hello");
        auto cnt = countWords(in);
        assert(cnt["hello"] == 3);
    }

    // 用例 3：空输入
    {
        std::istringstream in("");
        auto cnt = countWords(in);
        assert(cnt.empty());
    }

    // 用例 4：排序规则
    {
        std::istringstream in("b a c a");
        auto cnt = countWords(in);
        auto items = sortedByCount(cnt);
        assert(items[0].first == "a");
        assert(items[0].second == 2);
        assert(items[1].first == "b");
    }

    return 0;
}