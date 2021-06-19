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
#include "downloads.h"

using json = nlohmann::json;

int main() {
    Files files;
    auto directories = files.get_all_directories();
    auto my_files = files.get_all_files();
    std::string download_path = files.get_download_path();

    std::string lines = read_json_file();
    auto j = json::parse(lines);

    Downloads downloads;
    downloads.set_download_path(download_path);
    std::vector<std::string> required_directories;
    downloads.get_directories(required_directories, j);
    downloads.create_directories(required_directories, download_path);
    downloads.move_files(my_files, j);

    prevent_close();
    return 0;
}
