/**
 * Testbed in properly opening, and loop reading line by line with std::istringstream.
 * Inspired to make a test from https://github.com/ssloy/tinyrenderer/blob/f6fecb7ad493264ecd15e230411bfb1cca539a12/model.cpp
 *
 * Notice
 *  - std::ifstream::fail(), std::ifstream::eof()
 *  - std::string::compare()
 *  - std::ifstream::operator>> against various different type to read in or discard data
 */
#include <sstream>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

int main()
{
    std::vector<int> idxs;
    std::ifstream filein;
    filein.open("dragon.obj", std::ifstream::in);
    if (filein.fail())
    {
        std::cerr << "failed to read dragon.obj" << std::endl;
        exit(1);
    }

    std::string line;
    while (!filein.eof())
    {
        std::getline(filein, line);
        std::istringstream iss(line);
        char trash;         // will tell istringstream to read in one character at a time
        if (!line.compare(0, 2, "f "))
        {
            int idx;
            int itrash;     // target type we'd like to read in i.e. as integer
            iss >> trash;
            while (iss >> idx >> trash >> itrash >> trash >> itrash)        // notice we read expected target type, discard by one character for '/' and discard integer type, and so on
            {
                --idx;
                idxs.push_back(idx);
            }
        }
    }   
    filein.close();

    for (int i:idxs)
    {
        std::cout << i << std::endl;
    }

    return 0;
}
