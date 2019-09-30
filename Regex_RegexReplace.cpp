/**
 * Demonstrate usage of regex capability in c++ in <regex>.
 *
 * Include
 *  - std::regex_replace
 *
 */

#include <iostream>
#include <regex>
#include <iterator>

int main()
{
    // it's better to try to apply regex against a single line of string due to
    // regex syntax mostly operates on the basis excluding newline character i.e. .* to match any character onwards
    std::string inputStr = "Hello world, +123.456 and 34.56 This is a book! [blah blah 1234]";

    // to receive result back from regex algorithms
    // std::smatch is std::match_results<std::string::const_iterator>
    std::smatch matchResult;

    {
        std::string outputStr;
        std::regex rgx("Hello world");

        // we need std::back_inserter created with input std::string for us to fill in result at the
        // back one character at a time, and let it handles increment the iterator for us
        std::regex_replace(std::back_inserter(outputStr), inputStr.begin(), inputStr.end(), rgx, "*");
        std::cout << outputStr << '\n';
        // use $& to get the original replaced character, other character is for decoration in printing
        std::cout << std::regex_replace(inputStr, rgx, "[$&]");
    }

    std::cout << "\n\n";

    {
        std::string outputStr;
        std::regex rgx("(Hello world)");

        // we need std::back_inserter created with input std::string for us to fill in result at the
        // back one character at a time, and let it handles increment the iterator for us
        std::regex_replace(std::back_inserter(outputStr), inputStr.begin(), inputStr.end(), rgx, "*");
        std::cout << outputStr << '\n';
        // use $1 to refer to the first capture group
        std::cout << std::regex_replace(inputStr, rgx, "[$1]");
    }

    std::cout << "\n\n";

    {
        std::string outputStr;
        std::regex rgx("1|3|4|6");

        // we need std::back_inserter created with input std::string for us to fill in result at the
        // back one character at a time, and let it handles increment the iterator for us
        std::regex_replace(std::back_inserter(outputStr), inputStr.begin(), inputStr.end(), rgx, "*");
        std::cout << outputStr << '\n';
        std::cout << std::regex_replace(inputStr, rgx, "[$&]");
    }

    std::cout << '\n';

    std::cout.flush();

    return 0;
}
