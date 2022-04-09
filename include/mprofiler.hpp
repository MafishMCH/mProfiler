#include <chrono>
#include <string>
#include <ostream>

using namespace std::chrono;

class Mprofiler
{
private:
    std::string name;
    _V2::system_clock::time_point startTimestamp;
    _V2::system_clock::time_point endTimestamp;
    int duration;
    long int durationSum;
    int measurements;
    int averageDuration;
    int min;
    int max;
    static std::string prettyPrint(int us);
public:
    Mprofiler(const char*_name);
    void start();
    void stop();
    void reset();
    int getDuration();
    int getAverage();
    int getMax();
    int getMin();
    friend std::ostream& operator<<(std::ostream& os, const Mprofiler&p);
    std::string printAsCSV();
    static std::string printCsvHeader();
    ~Mprofiler();
};

Mprofiler::Mprofiler(const char*_name)
{
    name = std::string(_name);
    reset();
}

Mprofiler::~Mprofiler()
{
}
void Mprofiler::start()
{
    startTimestamp = high_resolution_clock::now();
}
void Mprofiler::stop()
{
    endTimestamp = high_resolution_clock::now();
    duration = duration_cast<microseconds>(endTimestamp - startTimestamp).count();
    measurements++;
    durationSum += duration;
    averageDuration = durationSum / measurements;

    if(duration > max)
        max = duration;
    if(duration < min)
        min = duration;
}
void Mprofiler::reset()
{
    duration = 0;
    averageDuration = 0;
    measurements = 0;
    durationSum = 0;
    min = INT32_MAX;
    max = 0;
}
int Mprofiler::getDuration()
{
    return duration;
}
int Mprofiler::getAverage()
{
    return averageDuration;
}
int Mprofiler::getMax()
{
    return max;
}
int Mprofiler::getMin()
{
    return min;
}
std::string Mprofiler::printCsvHeader()
{
    return "Average, Min, Max";
}
std::string Mprofiler::prettyPrint(int us)
{
    int s = us / 1000000;
    int ms = us / 1000;
    if(s > 0)
        return std::to_string(s) + "." + std::to_string(us % 1000000) + "s";
    if (ms > 0)
        return std::to_string(ms%1000) + "." + std::to_string(us % 1000) + "ms";
    return std::to_string(us) + "us";
}
std::ostream& operator<<(std::ostream& os, const Mprofiler&p)
{
    os << "[Profiler " << p.name <<"] Average: " << Mprofiler::prettyPrint(p.averageDuration) << ", Min: " << Mprofiler::prettyPrint(p.min) << ", Max: " << Mprofiler::prettyPrint(p.max);
    return os;
}
std::string Mprofiler::printAsCSV()
{
    return std::to_string(averageDuration) + ", " + std::to_string(min) + ", " + std::to_string(max);
}