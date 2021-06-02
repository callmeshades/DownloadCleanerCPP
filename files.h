//
// Created by Brandon on 6/1/2021.
//
#pragma once
#include <iostream>
#include <vector>
#include <windows.h>
#include <Lmcons.h>
#include <filesystem>
#include "utils.h"

class Files {
public:
    Files();
    std::vector<std::string> get_all_files();
    std::vector<std::string> get_all_directories();
    std::string get_download_path();

private:
    std::string download_path;

    static std::string get_username();
    static std::string build_download_path();
    static std::string get_filename(const std::filesystem::directory_entry &entry);
    void add_all_files(std::vector<std::string> &files, bool include_files=false);
};
