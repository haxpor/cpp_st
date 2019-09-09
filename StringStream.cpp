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

static void CheckType(const std::string& token)
{
    for (const char& c: token)
    {
        if (std::isalpha(c))
        {
            std::cout << "\t" << c << " is alphabetic";
            if (std::isupper(c))
            {
                std::cout << " (Uppper case)" << std::endl;
            }
            else
            {
                std::cout << " (lower case)" << std::endl;
            }
        }
        else if (std::isdigit(c))
            std::cout << "\t" << c << " is digit" << std::endl;
        else if (std::ispunct(c))
            std::cout << "\t" << c << " is punctuation" << std::endl;
    }
}

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
            CheckType(tmpToken);
        }
        std::cout << std::endl;
    }
    return 0;
}
