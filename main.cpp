#include <iostream>
#include <cstdio>
#include <sstream>
#include <cstring>
#include <format>
#include <vector>
#include <unistd.h>
#include <dirent.h>

#define MAX_INPUT 1024   // Maximum length of user input
#define MAX_ARGS 64      // Maximum number of arguments


std::string handleCd(std::string input) {
    /**
    * TODO
    **/
    return input;
}

// Function to read users inputs and stores in an array
void readInput(char *input) {
    const char* user = getenv("USER");
    std::cout << user <<  ":~$ " << std::flush;

    if (fgets(input, MAX_INPUT, stdin) == nullptr) {
        std::cout << "\nExiting...\n" << std::endl;
        exit(EXIT_SUCCESS);
    }

    input[strcspn(input, "\n")] = 0;
}

// Function to parse users inputs into cmds + args
std::vector<std::string> parseInput(const char *inputs) {
    char* cmd[MAX_INPUT];

    std::string inputStr(inputs);
    std::istringstream iss(inputStr);
    std::string token;
    std::vector<std::string> tokens;


    while (iss >> token) {
        tokens.push_back(token);
    }

    return tokens;
}


// Function to check if built in command
bool isBuiltInCmds(const std::vector<std::string> &inputs) {
    /**
     * Check if first element of command history is built in
     * If it is call helper function
     * If it isnt return 0
    **/

    // Exit
    // cd
    // help
    if (inputs[0] == "cd" || inputs[0] == "help" || inputs[0] == "exit" || inputs[0] == "pwd" || inputs[0] == "ls") {
        return 1;
    }


    return 0;
}

// Function print help command
void printHelp() {
    std::cout << "Custom Shell - Help\n"
              << "====================\n"
              << "Built-in commands:\n"
              << "  cd [dir]      Change the current directory\n"
              << "  pwd           Print the current working directory\n"
              << "  ls [dir]      List directory contents\n"
              << "  help          Show this help message\n"
              << "  exit          Exit the shell\n"
              << "\n"
              << "External commands:\n"
              << "  Any other command will be executed via fork/execvp,\n"
              << "  e.g. 'echo hello', 'grep foo file.txt'\n"
              << "\n"
              << "Features:\n"
              << "  |             Pipe output between commands\n"
              << "  <, >          Redirect input/output\n"
              << std::endl;
}

void handlePwd() {

    constexpr size_t size = 1024;
    char buffer[size];

    std::cout << std::format("Path\n_____ \n{}\n", getcwd(buffer, size));
}

void handleLs() {
    constexpr size_t size = 1024;
    char buffer[size];

    const char *path = getcwd(buffer, size);

    DIR *dir = opendir(path);

    struct dirent *entry;
    while ((entry = readdir(dir)) != nullptr) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
}

// Function to hand built in commands
void handleBuiltInCmd(std::vector<std::string> &tokens) {

    std::string cmd = tokens[0];

    if (cmd == "cd") {

    }
    else if (cmd == "help") {
        printHelp();
    }
    else if (cmd == "pwd") {
        handlePwd();
    }
    else if (cmd == "ls") {
        handleLs();
    }
    else if (cmd == "exit") {
        std::cout << "\nExiting...\n" << std::endl;
        exit(EXIT_SUCCESS);
    }
}

// Function to print banner
void banner() {
    std::cout << "***********************************************************************************" << std::endl;
    std::cout << std::endl;
    std::cout << "************************************ Custom Shell *********************************" << std::endl;
    std::cout << std::endl;
    std::cout << "***********************************************************************************" << std::endl;
}

int main() {
    char input[MAX_INPUT];
    char *args1[MAX_ARGS], *args2[MAX_ARGS];

    banner();

    while (true) {
        readInput(input);

        std::vector<std::string> tokens = parseInput(input);

        if (isBuiltInCmds(tokens)) {
            handleBuiltInCmd(tokens);
        }
        else {
            // If not built in cmd
            fork();
        }
    }


    return 0;
}