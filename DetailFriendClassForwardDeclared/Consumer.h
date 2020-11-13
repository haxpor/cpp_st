#pragma once

// this line is only necessary to forward declare for older version of compiler
namespace Detail { struct Widget; }

struct Consumer
{
    friend struct Widget;

    void SetNum(int n)
    {
        num = n;
    }

private:
    int num;
};
