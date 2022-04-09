# mProfiler
mProfiler is a lightweight, header-only C++ tool for measuring execution time of your code.
It features an averaging mechanism and registers min and max values. It can be easily reseted for monitoring of continuous functions. mProfiler's data can be accessed directly, pretty-printed or returned as CSV.


# Examples
There are two examples available:

### - Regular
Showcases a regular - single shot - mode for measuring execution time of a block of code.
```
$ ./regular 
Results: 
[Profiler Internal Loop 1] Average: 5.94ms, Min: 81us, Max: 9.863ms
[Profiler Internal Loop 2] Average: 7.373ms, Min: 5.167ms, Max: 10.97ms
[Profiler External Loop] Average: 1.246998s, Min: 1.246998s, Max: 1.246998s
```
### - Continuous
Designed to measure periodically executed tasks, such as control loops
Example output:
```
$ ./continuous 
[Profiler Loop] Average: 1.233ms, Min: 1.55ms, Max: 1.838ms
[Profiler Loop] Average: 1.231ms, Min: 1.43ms, Max: 1.412ms
[Profiler Loop] Average: 1.230ms, Min: 1.51ms, Max: 1.364ms
[Profiler Loop] Average: 1.227ms, Min: 1.60ms, Max: 1.829ms
[Profiler Loop] Average: 1.231ms, Min: 1.49ms, Max: 1.545ms
[Profiler Loop] Average: 1.231ms, Min: 1.79ms, Max: 1.646ms
[Profiler Loop] Average: 1.235ms, Min: 1.76ms, Max: 1.365ms
[Profiler Loop] Average: 1.230ms, Min: 1.78ms, Max: 1.505ms
[Profiler Loop] Average: 1.229ms, Min: 1.36ms, Max: 1.393ms
[Profiler Loop] Average: 1.234ms, Min: 1.76ms, Max: 2.287ms
[Profiler Loop] Average: 1.232ms, Min: 1.64ms, Max: 1.611ms
[Profiler Loop] Average: 1.229ms, Min: 1.59ms, Max: 1.779ms
[Profiler Loop] Average: 1.226ms, Min: 1.62ms, Max: 1.686ms
```
The profiler simouteniosly relays data to `profiler_log.txt` file in CSV format:
```
$ cat profiler_log.txt
Average, Min, Max
1233, 1055, 1838
1231, 1043, 1412
1230, 1051, 1364
1227, 1060, 1829
1231, 1049, 1545
1231, 1079, 1646
1235, 1076, 1365
1230, 1078, 1505
1229, 1036, 1393
1234, 1076, 2287
1232, 1064, 1611
1229, 1059, 1779
1226, 1062, 1686
```
Which can be then easly plotted:

![mProfiler Log](/assets/plot.png?raw=true "mProfiler Log")
