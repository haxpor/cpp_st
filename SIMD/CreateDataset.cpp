/**
 * Companion file to create dataset for FindMaxSIMD.cpp
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));

    std::ofstream outfile("dataset.txt");

    outfile << "1000000\n";
    for (int i=0; i<1000000; ++i)
    {
        const float factor = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        const unsigned int num = static_cast<int>(rand()) % 9999999;
        outfile << std::fixed << (num * factor) << '\n';
    }

    outfile.close();
    return 0;
}
