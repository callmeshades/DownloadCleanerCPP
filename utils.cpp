#include "utils.h"

void prevent_close() {
    std::cout << "Enter a character and press enter to continue..." << std::endl;
    char a;
    std::cin >> a;
}

void tokenize(std::string const& str, std::string const& delim, std::vector<std::string>& out) {
    size_t start;
    size_t end = 0;

    while ((start = str.find_first_not_of(delim, end)) != std::string::npos) {
        end = str.find(delim, start);
        out.push_back(str.substr(start, end - start));
    }
}

void remove_char(std::string& str, const char character) {
    str.erase(remove(str.begin(), str.end(), character), str.end());
}

/* Converts all letters in a string to lowercase */
void to_lowercase(std::string& string) {
    std::transform(string.begin(), string.end(), string.begin(), [](unsigned char c) {
        return std::tolower(c);
    });
}

/* Imports and loads the JSON file into memory */
std::string read_json_file() {
    std::fstream file;
    std::string lines;
    file.open("filetypes.json", std::ios::in);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            lines += line;
        }
        file.close();
        return lines;
    }
    else {
        file.close();
        throw std::invalid_argument("Could not open the file!");
    }
}