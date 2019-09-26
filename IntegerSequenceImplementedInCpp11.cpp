/**
 * Implementation of std::integer_sequence and std::make_integer_sequence in C++11
 * to make a function call with input parameter of std::tuple.
 *
 * I followed along from this blog post https://blog.galowicz.de/2016/06/24/integer_sequences_at_compile_time/
 * by Jacek as a way to understand what is std::integer_sequence and how to use it.
 *
 * No credits taken. Thanks for the writeup!
 *
 * Self analysis
 *  - this takes advantage of template parameter packs taking benefit of its indices' value to specify into std::tuple to get specific component value
 *  - it cleverly takes benefit of recursive (like in normal recursive implementation) to define complex solution as template
 */

#include <iostream>
#include <tuple>

// type which hold sequences
template <int ... Ns> struct sequence {};

// Define the template signature
template <int ... Ns> struct seq_gen;
// Recursive case
template <int I, int ... Ns>
struct seq_gen<I, Ns...>
{
    using type = typename seq_gen<I-1, I-1, Ns...>::type;
};

// Recursive abort
template <int ...Ns>
struct seq_gen<0, Ns...>
{
    using type = sequence<Ns...>;
};

template <int N>
using sequence_t = typename seq_gen<N>::type;

static void func(double d, float f, int i)
{
    // this section of code makes me dig deeper to find out that it's cheaper to use '<character>'
    // as input to operator<< of std::cout because if it's string type, it has to call data() to get
    // into its underlying array of character data thus 1 more hop of method call.
    std::cout << d << ", "
              << f << ", "
              << i << '\n';
}

template <typename F, typename TUP, int ... INDICES>
static void tuple_call_(F f, TUP tup, sequence<INDICES...>)
{
    f(std::get<INDICES>(tup) ...);
}

template <typename F, typename ... Ts>
static void tuple_call(F f, std::tuple<Ts...> tup)
{
    tuple_call_(f, tup, sequence_t<sizeof...(Ts)>{});
}

int main()
{
    // call style version 1
    func(1.0, 2.0, 3);

    // call style version 2
    std::tuple<double, float, int> tup {1.0, 2.0, 3};
    tuple_call(func, tup);
    return 0;
}
