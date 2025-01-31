/**
 * nsc.cc
 * 2020 July 5
 *
 * Copyright (C) 2020-PresentTime : Marcos Freitas de Morais
 *   em Louvor ao Autor de toda a Ciência
 *    e a Divina Presença EU SOU
 *
 * All rights reserved under Apache License 2.0, that it means:
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * 
 */

#include <getopt.h>     // getopt_long
#include <stdlib.h>     // strtof, strtod
#include <iostream>
#include <string>
#include <functional>

static bool beep = false;
static int ivalue = -1;
static float fvalue = 0.0;
static std::string write_file;

static int
show_help() {

	std::string usage = 

R"u(nsc (Node System Console) 1.0-1
Copyright(c) 2020-PresentTime : Marcos Freitas de Morais, FI
Usage: nsc [options]
Short options: 		GNU long options:       Action
	-i <value> 		--integer <value>       Pass number to program
	-b 				--beep                  Beep activate
	-f 	 			--float <value>         Set sigma value to program
	-w				--write-to-file <name>  File to write to
	-h 				--help                  Show help
)u";

	std::cout << usage;
    return 1;
}

static int
process_arguments(int argc, char** argv)
{
    const char* const short_opts = "i:b:f:w:h";
    const option long_opts[] = {
            {"integer", required_argument, nullptr, 'i'},
            {"beep", no_argument, nullptr, 'b'},
            {"float", required_argument, nullptr, 'f'},
            {"write-to-file", required_argument, nullptr, 'w'},
            {"help", no_argument, nullptr, 'h'},
            {nullptr, no_argument, nullptr, 0}
    };

    while (true)
    {
        int option = getopt_long(argc, argv, short_opts, long_opts, nullptr);

        if (-1 == option){
            break;
        }

        switch (option)
        {
        case 'i':   // -i <value> || --integer <value>
            ivalue = std::strtod(optarg, nullptr);
            std::cout << "Integer value set := " << ivalue << std::endl;
            break;

        case 'b':   // -b || --beep
            beep = true;
            std::cout << "Beep is set := true" << std::endl;
            break;

        case 'f':   // -f <value> || --float <value>
            fvalue = std::strtof(optarg, nullptr);
            std::cout << "Float value set := " << fvalue << std::endl;
            break;

        case 'w':   // -w <name> || --write-to-file <name>
            write_file = std::string(optarg);
            std::cout << "File to write := " << write_file << std::endl;
            break;

        case 'h':   // -h || --help
            (void) show_help();
            break;

        default:
            (void) show_help();
            return 1;           // See it on shell with: echo $?
        }
    }

    return 0;
}

int
main(int argc, char **argv)
{
	std::function<int(void)> fn_help = show_help;
    std::function<int(int, char*[])> fn_long_arguments = process_arguments;

    return (1 == argc) ? fn_help() : fn_long_arguments(argc, argv);
}
