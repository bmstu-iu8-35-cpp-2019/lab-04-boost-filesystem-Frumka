// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>
#include <ftp_file.hpp>
#include <iostream>

TEST(Example, EmptyTest) {
int argc = 2;
    char p1[] = "PATH";
    char p2[] = "..//misc//ftp";
    char* argv[] = {p1, p2};
    std::cout << std::endl;
    main_function(argc, argv);
    std::cout << std::endl;
}
