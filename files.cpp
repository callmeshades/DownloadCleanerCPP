//
// Created by Brandon on 6/1/2021.
//

#include "files.h"

void get_file_name(std::vector<std::string>& tokens, std::string& out) {
    out = tokens.back();
}

void path_to_string(std::string& str, const std::filesystem::directory_entry& entry) {
    const std::filesystem::path& path{ entry.path() };
    str = path.u8string();
}

std::string Files::get_download_path() {
    return this->download_path + "\\";
}

std::string Files::get_username() {
    char win_username[UNLEN + 1];
    DWORD user_len = UNLEN + 1;
    GetUserNameA(win_username, &user_len);
    return std::string{ win_username };
}

std::string Files::build_download_path() {
    std::string username = get_username();
    std::string path = R"(C:\Users\)" + username + R"(\Downloads)";
    return path;
}

Files::Files() {
    this->download_path = build_download_path();
}

std::string Files::get_filename(const std::filesystem::directory_entry& entry) {
    // Convert string to c++ string
    std::string filepath;
    path_to_string(filepath, entry);

    std::string filename;
    std::string delimiter = R"(\)";
    std::vector<std::string> split_string;
    tokenize(filepath, delimiter, split_string);
    get_file_name(split_string, filename);
    remove_char(filename, '"');
    return filename;
}

void Files::add_all_files(std::vector<std::string>& files, bool include_files) {
    for (const auto& entry : std::filesystem::directory_iterator(this->download_path)) {
        bool is_directory = entry.is_directory();
        if (!include_files && !is_directory) continue;
        if (include_files && !is_directory) {
            files.push_back(this->get_filename(entry));
            continue;
        }
        if (!include_files) {
            files.push_back(this->get_filename(entry));
        }
    }
}

std::vector<std::string> Files::get_all_files() {
    std::vector<std::string> files;
    this->add_all_files(files, true);
    return files;
}

std::vector<std::string> Files::get_all_directories() {
    std::vector<std::string> files;
    this->add_all_files(files, false);
    return files;
}

