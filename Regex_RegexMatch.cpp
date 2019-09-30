/**
 * Demonstrate usage of regex capability in c++ in <regex>.
 *
 * Include
 *  - std::regex_match
 *
 */

#include <iostream>
#include <regex>

int main()
{
    // it's better to try to apply regex against a single line of string due to
    // regex syntax mostly operates on the basis excluding newline character i.e. .* to match any character onwards
    std::string inputStr = "Hello world, +123.456 and 34.56 This is a book! [blah blah 1234]";

    // to receive result back from regex algorithms
    // std::smatch is std::match_results<std::string::const_iterator>
    std::smatch matchResult;

    {
        std::string rgxStr = "Hello world.*";
        std::regex rgx(rgxStr);

        // std::regex_match
        // note: std::regex is typedef-ed from std::basic_regex<char>
        if (std::regex_match(inputStr, matchResult, rgx))
        {
            std::cout << "Match '" << rgxStr << "'\n"
                      << "match result\n"
                      << "  size() : " << matchResult.size() << '\n'
                      << "  ready() : " << matchResult.ready() << '\n'
                      << "  prefix() : " << matchResult.prefix() << '\n'
                      << "  suffix() : " << matchResult.suffix() << '\n'
                      << "  1st group : " << matchResult[0] << '\n'
                      << "  2nd group : " << matchResult[1] << '\n';        // this will return empty unmatched string
        }
    }

    std::cout << '\n';

    {
        // there are 2 capturing group "Hello world" and "This.*book!" (or per se 'This ... book!')
        // use raw string to help us not worry about escaping characters
        std::string rgxStr = R"((Hello world).*(This.*book!).*)";
        std::regex rgx(rgxStr);

        // std::regex_match
        // note: std::regex is typedef-ed from std::basic_regex<char>
        if (std::regex_match(inputStr, matchResult, rgx))
        {
            std::cout << "Match '" << rgxStr << "'\n"
                      << "match result\n"
                      << "  size() : " << matchResult.size() << '\n'
                      << "  ready() : " << matchResult.ready() << '\n'
                      << "  prefix() : " << matchResult.prefix() << '\n'
                      << "  suffix() : " << matchResult.suffix() << '\n'
                      << "  1st group : " << matchResult[0] << '\n'
                      << "  2nd group : " << matchResult[1] << '\n'
                      << "  3rd group : " << matchResult[2] << '\n';
        }
    }

    std::cout << '\n';

    {
        // try to capture group digits with optional of sign, and [blah blah ...]
        // note: notice that we can only capture the first occurrence of capture group, we cannot
        //       get 34.56 as part of our result, it's limitation for capture group
        std::string rgxStr = R"([^\d]*?([\+]?[\d]+\.[\d]+).*(\[blah blah.*\]).*)";
        std::regex rgx(rgxStr);

        // std::regex_match
        // note: std::regex is typedef-ed from std::basic_regex<char>
        if (std::regex_match(inputStr, matchResult, rgx))
        {
            std::cout << "Match '" << rgxStr << "'\n"
                      << "match result\n"
                      << "  size() : " << matchResult.size() << '\n'
                      << "  ready() : " << matchResult.ready() << '\n'
                      << "  prefix() : " << matchResult.prefix() << '\n'
                      << "  suffix() : " << matchResult.suffix() << '\n'
                      << "  1st group : " << matchResult[0] << '\n'
                      << "  2nd group : " << matchResult[1] << '\n'
                      << "  3rd group : " << matchResult[2] << '\n'
                      << "  4th group : " << matchResult[3] << '\n';
        }
    }

    std::cout << '\n';

    std::cout.flush();

    return 0;
}
