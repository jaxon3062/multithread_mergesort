# Multithread Mergesort Implementation

This is a small project that implements mergesort and its multithread version by `<pthread.h>`.

## Usage

`gen.py`:
```
./gen.py
Testcase No. ? : /* the index no. of the following generated testcase */
How many ints? : /* the number in the generated testcase you want */
How wide the value range is? : /* the numbers range between -value ~ value */
```

`main`:
```
./main [normal/mt/mix] [threshold] < *testcase path*
```
- normal(default): common mergesort
- mt: full multithreading mergesort
- mix: multithreading above *threshold*, normal below it

