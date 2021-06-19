#pragma once
#include <iostream>
#include <vector>
#include <filesystem>
#include <fstream>
#include <string>

void prevent_close();
void tokenize(std::string const& str, std::string const& delim, std::vector<std::string>& out);
void remove_char(std::string& str, const char character);
std::string read_json_file();
void to_lowercase(std::string& string);