#pragma once
#include <iostream>
#include <vector>
#include <filesystem>

void tokenize(std::string const &str, std::string const &delim, std::vector<std::string> &out);
void remove_char(std::string &str, const char character);