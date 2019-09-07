/**
 * Desmonstrate the use of piping into program.
 *
 * program.out < input.txt
 *
 * This is another of CinRedirection.cpp.
 *
 * Note: There are 2 concepts to accept parameters from external to program
 *  1. Program's argument via argc, and argv
 *  2. Piping into the program, accept it via scanf or std::cin
 *
 * Use res/sample_input2.txt as input for piping into this program.
 * Execution usage:
 *  ./a.out < res/sample_input2.txt // for parameters sent in as oneline
 *  ./a.out < res/sample_input3.txt // for parameters sent in each separated by newline
 */

#include <cstdio>
#include <iostream>
#include <iomanip>

int main(void)
{
    // the two buffers manage its own streaming buffer, thus we can do it twice one for each
    // as it won't interfere one another buffer without a need to reset states/modifiers, and read-position
    // of each buffer.

    {
        int input1;
        char input2;
        long input3;
        float input4;
        double input5;

        // c style
        std::scanf("%d %c %ld %f %lf", &input1, &input2, &input3, &input4, &input5);

        printf("%d\n%c\n%ld\n%.3f\n%.9lf\n", input1, input2, input3, input4, input5);
    }

    std::cout << "\n";

    {
        int input1;
        char input2;
        long input3;
        float input4;
        double input5;

        // c++ style
        std::cin >> input1 >> input2 >> input3 >> input4 >> input5;
        std::cout << input1 << "\n" << input2 << "\n" << input3 << "\n";
        std::cout << std::fixed << std::setprecision(3) << input4 << "\n";
        std::cout << std::fixed << std::setprecision(9) << input5 << std::endl;
    }
    
    return 0;
}
