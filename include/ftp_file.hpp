// Copyright 2018 Your Name <your_email>

#ifndef INCLUDE_FTP_FILE_HPP_
#define INCLUDE_FTP_FILE_HPP_

#include <boost/filesystem.hpp>
#include <iostream>
#include <string>
#include <vector>

using boost::filesystem::path;
using boost::filesystem::directory_iterator;
using boost::filesystem::directory_entry;

struct File {
    std::string _broker;
    std::string _account;
    size_t _count;
    std::string _last_date;

    File(std::string broker_name, std::string filename);
};

std::ostream& operator<<(std::ostream& out, const File& file);

void scan_dir(const path& p, std::vector<File>& vec);

int main_function(int argc, char* argv[]);

#endif // INCLUDE_FTP_FILE_HPP_
