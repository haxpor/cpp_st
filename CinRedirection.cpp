/**
 * Demonstrate usage of redirection of std::cin.
 * Inspiration from playing around with hackerrank.com platform by solving some problems then
 * curiousity arises as of how the its system (or whatever backend solution they might be building)
 * is able to supply program's arguments (probably and highly) in run-time.
 *
 * Normally we use
 *
 * int main(int argc, char* argc[])
 * { ... }
 *
 * to recevive program's arugments, but that's not what hackerrank.com seems to use as it
 * relies on std::cin all the time.
 *
 * Thus simple question is "How hackerrank.com able to supply program's argument in run-time?"
 *
 * What I'm thinking is that the system might inject redirection of std::cin to read from pure string or file
 * (file is much better) into the submitted source file from users before compilation.
 * File should be highly the possibility as it requires no re-compilation, and system can response
 * in due time.
 *
 * I might be wrong, but this os one of possible ways.
 */
#include <iostream>
#include <string>
#include <fstream>

static void ReadLines()
{
    std::string line;
    while (std::getline(std::cin, line))
    {
        std::cout << line << "\n";
    }
}

static void ResetCinStates()
{
    // reset the states / modifiers
    std::cin.clear();
    // reset the position of read buffer
    std::cin.seekg(0);
}

int main()
{
    std::ifstream fileIn("res/sample_input.txt");

    // save pointer to stream buffer of std::cout
    auto coutSBuf = std::cin.rdbuf();

    // substitute internal std::cout buffer with buffer of fileIn
    std::cin.rdbuf(fileIn.rdbuf());
    
    std::string readString;
    // input from fileIn to readString
    // note: this will only read just oneline
    std::cin >> readString;
    std::cout << readString << std::endl;

    ResetCinStates();

    // this will read the whole lines inside the file
    ReadLines();

    std::cout.flush();

    return 0;
}
