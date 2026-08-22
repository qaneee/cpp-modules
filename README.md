# cpp-modules

C++ modules from the 42 School curriculum (CPP00–CPP09), covering the transition from C to C++: OOP fundamentals, memory management, polymorphism, inheritance, templates, and STL usage — all implemented under strict C++98 constraints unless noted otherwise.

## Overview

Each `CPPXX` directory is a self-contained module with its own `Makefile`, exercises (`ex00`, `ex01`, ...), and any provided base files. The exercises build in complexity from basic class design to full STL container/algorithm/iterator work, mirroring the official 42 progression.

## Project Structure

```
cpp-modules/
├── CPP00/                  # Namespaces, classes, member functions, static, const
│   ├── ex00/
│   ├── ex01/
│   └── ex02/
├── CPP01/                  # Memory allocation, references, pointers to members
│   ├── ex00/
│   ├── ...
├── CPP02/                  # Ad-hoc polymorphism, operator overloading, Orthodox Canonical Form
├── CPP03/                  # Inheritance
├── CPP04/                  # Subtype polymorphism, abstract classes, interfaces
├── CPP05/                  # Repetition, exceptions
├── CPP06/                  # Type casting (static/dynamic/reinterpret/const)
├── CPP07/                  # Templates
├── CPP08/                  # Templated containers, iterators, algorithms
├── CPP09/                  # STL — containers, algorithms in a full mini-project
└── README.md
```

## Technology Stack

- **Language**: C++ (C++98, per 42 subject constraints unless a module explicitly allows later standards)
- **Build System**: GNU Make
- **Compiler flags**: `-Wall -Wextra -Werror -std=c++98` (adjust per module Makefile)

## Prerequisites

- A C++98-capable compiler
- GNU Make

## Building

Each module builds independently:

```bash
cd CPP00
make
```

Or, if the top-level Makefile supports it, build everything at once:

```bash
make        # builds all modules
make fclean # cleans all modules
```

## Usage

Each exercise produces its own binary inside its `exXX` directory. Run it directly after building.

## Module Summary

| Module | Focus |
|--------|-------|
| CPP00 | Namespaces, classes, member functions, stdio streams, initialization lists, static/const |
| CPP01 | Memory allocation (stack vs heap), pointers to members, references, switch statements |
| CPP02 | Ad-hoc polymorphism, operator overloading, Orthodox Canonical Form (OCF) |
| CPP03 | Inheritance |
| CPP04 | Subtype polymorphism, abstract classes, interfaces |
| CPP05 | Repetition, exception handling |
| CPP06 | Casting: static_cast, dynamic_cast, reinterpret_cast, const_cast |
| CPP07 | Templates and template functions |
| CPP08 | Templated containers, STL iterators, STL algorithms |
| CPP09 | STL — final integration project |
