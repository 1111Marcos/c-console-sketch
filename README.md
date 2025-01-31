# cc-console-sketch
A C++ application skeleton of console program to show how to use `getopt_long(..)` function.

## Build
```bash
cmake -S . -B ./build && cd build
# and
make
```


## Running

Passing some arguments
```bash
# on build directory
./nsc --integer 29 --float 15.5 --beep

# It will generate
Integer value set := 29
Float value set := 15.5
Beep is set := true
```

Getting help
```bash
# on build directory
./nsc --help

# It will generate
nsc (Node System Console) 1.0-1
Copyright(c) 2020-PresentTime : Marcos Freitas de Morais, FI
Usage: nsc [options]
Short options: 		GNU long options:       Action
	-i <value> 		--integer <value>       Pass number to program
	-b 				--beep                  Beep activate
	-f 	 			--float <value>         Set sigma value to program
	-w				--write-to-file <name>  File to write to
	-h 				--help                  Show help
```

Passing a text argument
```bash
# on build directory
./nsc -w save_into_me.txt

# It will generate
File to write := save_into_me.txt
```
