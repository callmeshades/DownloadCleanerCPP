#include "downloads.h"

void Downloads::set_download_path(std::string& download_path) {
    this->download_path = download_path;
}

/* Creates all directories from a provided list */
void Downloads::create_directories(std::vector<std::string>& directories, std::string& download_path) {
    for (const auto& dir : directories)
    {
        if (std::find(directories.begin(), directories.end(), dir) == directories.end())
        {
            std::cout << "Creating directory: " << dir << std::endl;
            std::filesystem::create_directory(download_path + dir);
        }
    }
}

void Downloads::move_file(std::string& folder, std::string& filename) {
    std::string old_location = this->download_path + "\\" + filename;
    std::string new_location = this->download_path + folder + "\\" + filename;
    std::cout << "Moving \"" << filename << "\" to " << new_location << std::endl;
    try {
        std::filesystem::rename(old_location, new_location);
    }
    catch (std::exception const& ex) {
        std::cout << "[ERROR] An exception occurred!" << std::endl;
        std::cout << ex.what() << std::endl;
        prevent_close();
        exit(0);
    }
}