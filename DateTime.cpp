/**
 * Demonstrate usage of date time functionality as provided in <ctime>
 * Includes
 *  - std::tm
 *  - std::time_t
 *  - std::mktime
 *  - std::localtime
 *  - std::ctime
 *  - std::asctime
 *  - std::clock
 *  - std::time
 *  - std::difftime
 *
 * Support
 *  - std::chrono::high_resolution_clock::now()
 *
 * Compile with
 *  g++ -std=c++11 DateTime.cpp -lpthread
 */

#include <iostream>
#include <ctime>
#include <string>
#include <thread>
#include <iomanip>
#include <chrono>

static std::string getMonthStr(int month)
{
    switch (month)
    {
        case 0: return "January";
        case 1: return "February";
        case 2: return "March";
        case 3: return "April";
        case 4: return "May";
        case 5: return "June";
        case 6: return "July";
        case 7: return "August";
        case 8: return "September";
        case 9: return "October";
        case 10: return "November";
        case 11: return "December";
        default: return "Unknown";
    }
}

static void threadWorker()
{
    double acc = 0.0;

    // just loop in do some delayed task
    for (int i=0; i<10000; ++i)
    {
        for (int j=0; j<10000; ++j)
        {
            acc += i*j;
        }
    }
}

int main()
{
    // all components are 0-based otherwise noted
    std::tm desireTime = {
        0,              // seconds
        30,             // minutes
        0,              // hours
        1,              // day of month (1-based)
        0,              // months, since January
        2019 - 1900    // years since 1900 (see its man page, it clearly states)
    };

    std::cout << "Target calendar time: " << desireTime.tm_hour << ":" << desireTime.tm_min << ":" << desireTime.tm_sec
              << " " << getMonthStr(desireTime.tm_mon) << ", " << desireTime.tm_mday << ", " << (1900+desireTime.tm_year) 
              << " (days since Sunday: " << desireTime.tm_wday << ", days since January 1: " << desireTime.tm_yday << ")" << std::endl;

    // std::mktime ignores two component in std::tm which are
    // tm_wday, and tm_yday. Also the values are permitted to be outside of its ranges
    //
    // positive of tm_isdst means DST (Daylight saving time is in effect), zero means not,
    // and negative means call site doesn't have information about it thus std::mktime will
    // try to determine for us
    //
    // the result from this call will update all fields of input std::tm
    // especially tm_wday, and tm_yday will be recalculated from other fields giving the information
    // from desire input time
    //
    // t is now in epoch time (with no leap second in consdieration) which is almost always integral
    // value holding number of seconds since 00:00, Jan 1 1970 UTC, corresponding to POSIX time
    std::time_t t = std::mktime(&desireTime);

    // convert input epoch time into calendar time expressed in local time
    // this is not thread-safe call
    const std::tm timeRep = *std::localtime(&t);

    std::cout << "Epoch time: " << t << std::endl;
    std::cout << "Converted calendar time: " << timeRep.tm_hour << ":" << timeRep.tm_min << ":" << timeRep.tm_sec
              << " " << getMonthStr(timeRep.tm_mon) << ", " << timeRep.tm_mday << ", " << (1900+timeRep.tm_year)
              << " (days since Sunday: " << timeRep.tm_wday << ", days since January 1: " << timeRep.tm_yday << ")" << std::endl;

    // std::ctime
    // convert from std::time_t to string representation
    std::cout << "std::ctime() : " << std::ctime(&t);

    // std::asctime
    // both will give the same result as desireTime is updated after a call to std::mktime
    // thus its component values have the same value as of newly created freshly timeRep from std::localtime()
    //
    // note: result format for std::ctime and std::asctime are the same
    std::cout << "std::asctime() (via desireTime): " << std::asctime(&desireTime);
    std::cout << "std::asctime() (via result from std::localtime()): " << std::asctime(&timeRep);

    // std::clock
    // difference between std::clock depensd on resource given to the program. It can advance faster than
    // wall clock if the program is multithreading or per se more CPU time allotted into the program,
    // or advance slower if its CPU time needed to be shared to other processes
    
    std::clock_t processStartTime = std::clock();
    auto wallClockStart = std::chrono::high_resolution_clock::now();
    std::time_t tStart = std::time(nullptr);

    std::thread t1(threadWorker);
    std::thread t2(threadWorker);

    t1.join();
    t2.join();

    std::clock_t processEndTime = std::clock();
    auto wallClockEnd = std::chrono::high_resolution_clock::now();
    std::time_t tEnd = std::time(nullptr);

    std::cout << "CPU Time elapsed: " << std::setprecision(4) << (1000.0 * (processEndTime - processStartTime) / CLOCKS_PER_SEC) << " ms" << std::endl;
    std::cout << "Wall clock elpased (via high resolution chrono): " << std::setprecision(4) << std::chrono::duration<double, std::milli>(wallClockEnd-wallClockStart).count() << " ms" << std::endl;
    // std::difftime is not high resolution as compared to std::chrono::high_resolution_clock
    // although its man page says C and C++ supports fractional time unit, but std::difftime() returns integral time unit
    std::cout << "Wall clock elapsed (via std::time()): " << std::setprecision(4) << 1000.0 * std::difftime(tEnd,tStart) << " ms" << std::endl;

    // std::gmtime
    // return calendar time in tm structure form in UTC (Coordinated Universal Time) which is essentially Greenwich Mean Time (GMT)
    std::time_t tTemp = std::time(nullptr);
    std::tm gmTm = *std::gmtime(&tTemp);
    std::cout << "std::gmtime(): " << std::asctime(&gmTm);

    // printing time representation in localtime zone
    // the input fed by using std::localtime()
    {
        std::tm localTime = *std::localtime(&tTemp);
        std::cout << "std::asctime() (fed by std::localtime()): " << std::asctime(&localTime);
    }

    // also print time presentation in localtime zone
    // the input fed by using std::time()
    // so it's up to users whether they has hold of either one piece of information (std::tm or std::time_t)
    // then we can decide to choose either std::asctime() for std::tm, or std::ctime() for std::time_t
    // to print out time representation
    {
        std::time_t t = std::time(nullptr);
        std::cout << "std::ctime() (fed by std::time()): " << std::ctime(&t);
    }

    return 0;
}
