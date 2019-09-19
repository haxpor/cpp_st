/**
 * Checking the algorithm in split_string.
 * The algorithm of split_string is found at https://www.hackerrank.com/challenges/ctci-array-left-rotation/problem?h_l=interview&h_r=next-challenge&h_v=zen&isFullScreen=true&playlist_slugs%5B%5D%5B%5D%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D%5B%5D%5B%5D=arrays. Added with comment to narrate what's happening in notable lines.
 * No credits taken, this is for purpose of studying.
 *
 * Also an extra: demonstrate the use of std::unique.
 * It is usually followed by container's erase() (and optional shrink_to_fit() to actually reduce physical
 * size to fit the logical size). Note that man page of std::unique mentions that followed-up call to
 * container's erase() will also reduce its physical size but it doesn't mention anything about this
 * in specific container's erase() man page. Thus to be safe, if it provides shrink_to_fit(), then use it
 * when needed.
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> split_string(string input_string) {
    // use std::unique to eliminate duplicates of space
    // the content of such elements is shifted and is overwritten
    // values of elements past the end location are indeterminate
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });
    // erase duplicated elements past the end of marked location 'new_end'
    // erase with intention to reduce physical size of container down, but better use shrink_to_fit
    // for making sure it actually reduces
    input_string.erase(new_end, input_string.end());

    // remove trailing spaces
    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    // find the position of delimiter in order to split the string
    size_t pos = input_string.find(delimiter);

    // find() return npos if no substring is found
    while (pos != string::npos) {
        // split string token separated by ' ' space from start til
        // cannot find such space character anymore
        // pos - i => is the length of character to get
        splits.push_back(input_string.substr(i, pos - i));

        // progress through the whole string by jump pass the delimiter location
        i = pos + 1;
        // next next space ' ' character location again
        // then repeat the process
        pos = input_string.find(delimiter, i);
    }

    // add the last (left out) string token into the splits vector
    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

int main()
{
    string line("1 2 3 4 5 1");
    vector<string> tokens = split_string(line);
    for (const string& str: tokens)
    {
        cout << str << endl;
    }

    // demonstrate use of std::unique
    // the following section is following what split_string() function does
    string line2("1 2 3   1");
    auto lastIt = unique(line2.begin(), line2.end(), [](const char& x, const char& y){
            return x == y && x == ' ';
            });
    line2.erase(lastIt, line2.end());
    while (line2[line2.length() - 1] == ' ')
    {
       line2.pop_back(); 
    }
    cout << line2 << endl;
    return 0;
}
