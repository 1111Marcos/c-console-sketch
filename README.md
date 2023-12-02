# cc-console-sketch
A C++ application skeleton of console program to show how to use `getopt_long(..)` function.

## Build
```bash
mkdir build && cd build && cmake ..
# or
mkdir build && cd build && cmake .. -DCMAKE_BUILD_TYPE="Debug"
```


## Running 
```bash
# on build directory
./target/nsc --integer 29 --float 15.5 --beep
./target/nsc --help
```
