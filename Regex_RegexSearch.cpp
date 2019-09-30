/**
 * Demonstrate usage of regex capability in c++ in <regex>.
 *
 * Include
 *  - std::regex_search
 *
 * Note:
 *  - std::regex_search is more suitable to be used to search for multiple occurrences of string as
 *    it will also return prefix(), and suffix() in which they hold beginning, and last position for
 *    iterator to be able to progress forward if needed (see regex of "123" below).
 *
 *    Anyway in case of capture group, there will be no such information returned. It is still
 *    ok to be used to search for stricted regex with capture group, but it's pretty much the same
 *    effect as if done with std::regex_match.
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
        // syntax for regex string can be more relax
        std::string rgxStr = "world";
        std::regex rgx(rgxStr);

        // note: std::regex is typedef-ed from std::basic_regex<char>
        if (std::regex_search(inputStr, matchResult, rgx))
        {
            // notice the result of prefix() and suffix() in which they are shown for std::regex_search
            // as compared to std::regex_match which don't
            //
            // std::regex_search is more suitable for substring searching in relaxing constraints to
            // get as much result, and context back
            std::cout << "Search '" << rgxStr << "'\n"
                      << "search result\n"
                      << "  size() : " << matchResult.size() << '\n'
                      << "  ready() : " << matchResult.ready() << '\n'
                      << "  prefix() : " << matchResult.prefix() << '\n'
                      << "  suffix() : " << matchResult.suffix() << '\n'
                      << "  1st group : " << matchResult[0] << '\n'
                      << "  2nd group : " << matchResult[1] << '\n';        // this will return empty unmatched string
        }
    }

    std::cout << '\n';
    std::cout << "---\n";

    {
        // try to capture all occurrences of 123
        std::string rgxStr = "123";
        std::regex rgx(rgxStr);

        // note: std::regex is typedef-ed from std::basic_regex<char>
        auto searchBegin = inputStr.cbegin();
        int iterCount = 1;
        while (std::regex_search(searchBegin, inputStr.cend(), matchResult, rgx))
        {
            // notice the result of prefix() and suffix() in which they are shown for std::regex_search
            // as compared to std::regex_match which don't
            //
            // std::regex_search is more suitable for substring searching in relaxing constraints to
            // get as much result, and context back
            std::cout << "Search (iteration: " << (iterCount++) << ")  '" << rgxStr << "'\n"
                      << "search result\n"
                      << "  size() : " << matchResult.size() << '\n'
                      << "  ready() : " << matchResult.ready() << '\n'
                      << "  prefix() : " << matchResult.prefix() << '\n'
                      << "  suffix() : " << matchResult.suffix() << '\n'
                      << "  1st group : " << matchResult[0] << '\n'
                      << "  2nd group : " << matchResult[1] << '\n';        // this will return empty unmatched string

            // suffix() is std::pair in which hold iteration type for its first, and second
            // first is the beginning position, and second is the last position of input string
            searchBegin = matchResult.suffix().first;
        }
    }

    std::cout << "---\n";
    std::cout << '\n';

    {
        // -- demonstrate that it has similar effect when done with std::regex_match --
        // -- the following is the same as seen in Regex_RegexMatch.cpp --

        // there are 2 capturing group "Hello world" and "This.*book!" (or per se 'This ... book!')
        // use raw string to help us not worry about escaping characters
        std::string rgxStr = R"((Hello world).*(This.*book!).*)";
        std::regex rgx(rgxStr);

        // note: std::regex is typedef-ed from std::basic_regex<char>
        if (std::regex_search(inputStr, matchResult, rgx))
        {
            std::cout << "Search '" << rgxStr << "'\n"
                      << "search result\n"
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

        // -- demonstrate that it has similar effect when done with std::regex_match --
        // -- the following is the same as seen in Regex_RegexMatch.cpp --

        // try to capture group digits with optional of sign, and [blah blah ...]
        // note: notice that we can only capture the first occurrence of capture group, we cannot
        //       get 34.56 as part of our result, it's limitation for capture group
        std::string rgxStr = R"([^\d]*?([\+]?[\d]+\.[\d]+).*(\[blah blah.*\]).*)";
        std::regex rgx(rgxStr);

        // note: std::regex is typedef-ed from std::basic_regex<char>
        if (std::regex_search(inputStr, matchResult, rgx))
        {
            std::cout << "Search '" << rgxStr << "'\n"
                      << "search result\n"
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
