# cc-console-sketch
A C++ application skeleton of console program to show how to use `getopt_long(..)` function.

## Build
```bash
mkdir build && cd build && cmake ..
# or
mkdir build && cd build && cmake .. -DCMAKE_BUILD_TYPE="Debug"
```


## Running

Passing some arguments
```bash
# on build directory
./target/nsc --integer 29 --float 15.5 --beep

# It will generate
Integer value set to: 29
Float value set to: 15.5
Beep is set to true
```

Getting help
```bash
# on build directory
./target/nsc --help

# It will generate
nsc (Node System Console) 1.0-0
Copyright(C) 2020-PresentTime : Marcos Freitas de Morais, FI

-i, --integer <value>:      Pass number to program
-b, --beep:                 Beep activate
-f, --float <value>:        Set sigma value to program
-w, --write-to-file <name>: File to write to
-h, --help:                 Show help
```

Passing a text argument
```bash
# on build directory
./target/nsc -w save_into_me.txt

# It will generate
File to write: save_into_me.txt
```
