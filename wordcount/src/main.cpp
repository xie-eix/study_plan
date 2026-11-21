#include "word_counter.h"

#include <fstream>
#include <iostream>

int main(int argc, char* argv[]) {
    std::ifstream file;
    std::istream* in = &std::cin;

    if (argc > 1) {
        file.open(argv[1]);
        if (!file) {
            std::cerr << "cannot open " << argv[1] << "\n";
            return 1;
        }
        in = &file;
    }

    auto cnt   = countWords(*in);
    auto items = sortedByCount(cnt);
    printCounts(items, 20);
    return 0;
}