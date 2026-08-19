#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <stack>
#include <sstream>
#include <string>
#include <format>
#include <dirent.h>


std::string handlePwd() {

    constexpr size_t size = 1024;
    char buffer[size];

    return std::format("Path\n_____ \n{}\n", getcwd(buffer, size));
}

std::string handleCdInput(std::string input) {
    /**
    * TODO
    **/
}

std::string handleLsInput() {
    constexpr size_t size = 1024;
    char buffer[size];

    const char *path = getcwd(buffer, size);

    DIR *dir = opendir(path);

    struct dirent *entry;
    while ((entry = readdir(dir)) != nullptr) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        printf("%s ", entry->d_name);
    }

    closedir(dir);
    return "";
}

std::string commands(std::string input) {

    std::stringstream ss(input);
    std::string command;
    ss >> command;

    std::string cmdStr;

    if (command == "exit") {
        return "exit";
    }

    if (command == "pwd") {
        cmdStr = handlePwd();
    }
    else if (command == "cd") {
        /**
         * Needs to handle different cases
         * relative path (cd path)
         * absolute path (cd /abs/path)
         * cd .. (one up)
         * cd ../.. (multiple levels)
         * cd . (curr path but should succeed
        **/
        cmdStr = handleCdInput(input);
    }
    else if (command == "ls") {
        /**
         * Look at opendir()
        **/

        cmdStr = handleLsInput();
    }

    return cmdStr;
}

std::string inputHandling() {

    std::string input;
    getline(std::cin, input);

    std::string output;

    if (!input.empty()) {
        output = commands(input);
    }

    return output;
}

int main() {

    std::cout << "***********************************************************************************" << std::endl;
    std::cout << std::endl;
    std::cout << "************************************ Custom Shell *********************************" << std::endl;
    std::cout << std::endl;
    std::cout << "***********************************************************************************" << std::endl;

    while (true) {
        std::cout << ">> ";
        std::string line = inputHandling();
        if (line == "exit") break;
        std::cout << line << std::endl;
    }


    return 0;
}