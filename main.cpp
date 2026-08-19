#include <iostream>
#include <cstdio>
#include <sstream>
#include <cstring>
#include <format>

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
void parseInput() {

}


// Function to handle built in commands
int builtInCmds(char **args) {
    /**
     * Check if first element of command history is built in
     * If it is call helper function
     * If it isnt return 0
    **/

    // Exit
    // cd
    // help
    return 0;
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

        // if (strlen(input) == 0) continue;
    }


    return 0;
}