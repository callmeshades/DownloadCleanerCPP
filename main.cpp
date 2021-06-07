#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <algorithm>
#include <windows.h>
#include <cctype>
#include "json.hpp"
#include "files.h"
#include "utils.h"

using json = nlohmann::json;

void prevent_close() {
    std::cout << "Enter a character and press enter to continue..." << std::endl;
    char a;
    std::cin >> a;
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
    } else {
        file.close();
        throw std::invalid_argument("Could not open the file!");
    }
}

void to_lowercase(std::string &string) {
    std::transform(string.begin(), string.end(), string.begin(), [](unsigned char c) {
        return std::tolower(c);
    });
}

/* Gets all directories required in JSON file */
template <typename T>
void get_directories(std::vector<std::string> &list, T &json) {
    for (const auto& [key, value] : json.items()) {
        list.push_back(key);
    }
}

void move_file(std::string &folder, std::string &filename) {
    std::cout << "Moving \"" << filename << "\" to " << folder << std::endl;
    // std::string new_name = 
    // std::filesystem::rename()
}

/* Checks for an existing match in the JSON file */
template <typename T>
void filetype_matches(T &json, std::string &file) {
    std::string original_filename = file;

    std::vector<std::string> list;
    to_lowercase(file);
    tokenize(file, ".", list);
    std::string filetype = list.back();
    
    for (const auto &[key, value] : json.items()) {
        for (auto &fvalue : json[key]) {
            std::string current_filetype{fvalue}; // TODO: Switch to a better conversion method
            if (current_filetype == filetype) {
                std::string folder_name{key};
                move_file(folder_name, original_filename);
            }
        }
    }
}

/* Creates all directories from a provided list */
void create_directories(std::vector<std::string> &directories, std::string &download_path) {
    for (const auto &dir : directories)
    {
        if (std::find(directories.begin(), directories.end(), dir) == directories.end())
        {
            std::cout << "Creating directory: " << dir << std::endl;
            std::filesystem::create_directory(download_path + dir);
        }
   }
}

/*
 * TODO: Finalize moving files
 * */
template <typename T>
void move_files(std::vector<std::string> &files, T &json) {
    for (auto &file : files) {
        filetype_matches(json, file);
    }
}

int main() {
    Files files;
    auto directories = files.get_all_directories();
    auto my_files = files.get_all_files();
    std::string download_path = files.get_download_path();

    std::string lines = read_json_file();
    auto j = json::parse(lines);

    std::vector<std::string> required_directories;
    get_directories(required_directories, j);
    create_directories(required_directories, download_path);
    move_files(my_files, j);

    prevent_close();
    return 0;
}
