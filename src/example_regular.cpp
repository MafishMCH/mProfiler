#include "mprofiler.hpp"

#include <unistd.h>
#include <iostream>

int main(int argc, const char ** argv)
{
    srand (time(NULL));

    Mprofiler pi1("Internal Loop 1");
    Mprofiler pi2("Internal Loop 2");
    Mprofiler pe("External Loop");

    pe.start();
    for(int i = 0; i < 100; i++)
    {
        pi1.start();
        usleep(rand() % 10000);
        pi1.stop();
        
        pi2.start();
        usleep(rand() % 5000 + 5000);
        pi2.stop();
    }
    pe.stop();

    std::cout << "Results: " << std::endl <<
        pi1 << std::endl <<
        pi2 << std::endl <<
        pe << std::endl;

    return 0;
}