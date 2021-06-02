#include "utils.h"

void tokenize(std::string const &str, std::string const &delim, std::vector<std::string> &out) {
    size_t start;
    size_t end = 0;

    while ((start = str.find_first_not_of(delim, end)) != std::string::npos) {
        end = str.find(delim, start);
        out.push_back(str.substr(start, end - start));
    }
}

void remove_char(std::string &str, const char character) {
    str.erase(remove(str.begin(), str.end(), character), str.end());
}