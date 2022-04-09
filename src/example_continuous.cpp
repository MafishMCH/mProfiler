#include "mprofiler.hpp"

#include <iostream>
#include <unistd.h>
#include <fstream>

int main(int argc, const char ** argv)
{
    Mprofiler p("Loop");
    std::fstream logger;
    logger.open("./profiler_log.txt", std::ios::out);
    logger << Mprofiler::printCsvHeader() << std::endl;
    srand (time(NULL));

    int i = 0;
    while(1)
    {
        p.start();
        usleep(rand() % 250 + 1000);
        p.stop();

        if(i++ > 1000)
        {
            i = 0;
            std::cout << p << std::endl;
            logger << p.printAsCSV() << std::endl;
            p.reset();
        }
    }

    return 0;
}