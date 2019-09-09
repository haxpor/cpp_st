/**
 * Demonstrate usage of std::stringstream.
 * Use input test case from res/attrigute-parser-input.txt.
 *
 * Read line by line via std::getline() first, then operate on temporary std::string through
 * std::stringstream to get each next token of such line.
 */

#include <iostream>
#include <sstream>
#include <iomanip>

int main()
{
    // limit the scope of variable in use
    for (std::string line; std::getline(std::cin, line);)
    {
        std::cout << line << std::endl;

        // tokenize each line
        std::stringstream ss(line);
        std::string tmpToken;

        while (ss >> tmpToken)
        {
            std::cout << ": " << tmpToken << std::endl;
        }
        std::cout << std::endl;
    }
    return 0;
}
