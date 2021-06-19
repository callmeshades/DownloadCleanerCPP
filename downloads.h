#pragma once
#include <iostream>
#include <vector>
#include <filesystem>
#include "utils.h"
#include "json.hpp"

class Downloads {
public:
    void move_file(std::string& folder, std::string& filename);
	void create_directories(std::vector<std::string>& directories, std::string& download_path);
    void set_download_path(std::string& download_path);

    template <typename T>
    void get_directories(std::vector<std::string>& list, T& json) {
        for (const auto& [key, value] : json.items()) {
            list.push_back(key);
        }
    }

    /* Checks for an existing match in the JSON file */
	template <typename T>
	void filetype_matches(T& json, std::string& file) {
        std::string original_filename = file;

        std::vector<std::string> list;
        to_lowercase(file);
        tokenize(file, ".", list);
        std::string filetype = list.back();

        for (const auto& [key, value] : json.items()) {
            for (auto& fvalue : json[key]) {
                std::string current_filetype{ fvalue }; // TODO: Switch to a better conversion method
                if (current_filetype == filetype) {
                    std::string folder_name{ key };
                    move_file(folder_name, original_filename);
                }
            }
        }
    }

    /*
     * TODO: Finalize moving files
     * */
	template <typename T>
	void move_files(std::vector<std::string>& files, T& json) {
        for (auto& file : files) {
            filetype_matches(json, file);
        }
    };

private:
    std::string download_path;
};
