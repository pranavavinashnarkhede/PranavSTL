# PranavSTL

PranavSTL is a custom C++ data structure and algorithm library inspired by the C++ Standard Template Library (STL).

The project is developed from scratch to practise C++ templates, pointers, dynamic memory management, and reusable C++ components.

## Features

### Data Structures
- Singly Linked List
- Singly Circular Linked List
- Doubly Linked List
- Doubly Circular Linked List
- Stack
- Queue
- Binary Search Tree (BST)

### Algorithms
- Linear Search
- Bidirectional Search
- Bubble Sort
- Efficient Bubble Sort
- Selection Sort
- Insertion Sort

## Project Structure

```text
PranavSTL/
├── include/
│   └── pstl/
│       ├── node.hpp
│       ├── SinglyLL.hpp
│       ├── SinglyCL.hpp
│       ├── DoublyLL.hpp
│       ├── DoublyCL.hpp
│       ├── Stack.hpp
│       ├── Queue.hpp
│       ├── Tree.hpp
│       ├── Searching.hpp
│       ├── Sorting.hpp
│       └── pstl.hpp
├── example/
│   ├── SinglyLL.cpp
│   ├── SinglyCL.cpp
│   ├── DoublyLL.cpp
│   ├── DoublyCL.cpp
│   ├── Stack.cpp
│   ├── Queue.cpp
│   ├── Tree.cpp
│   ├── Searching.cpp
│   └── Sorting.cpp
├── TestAll.cpp
└── README.md
```

## Header Overview

| Header | Purpose |
|---|---|
| `node.hpp` | Common node structure used by linked-list-based components |
| `SinglyLL.hpp` | Singly linked list |
| `SinglyCL.hpp` | Singly circular linked list |
| `DoublyLL.hpp` | Doubly linked list |
| `DoublyCL.hpp` | Doubly circular linked list |
| `Stack.hpp` | Stack implementation |
| `Queue.hpp` | Queue implementation |
| `Tree.hpp` | Binary search tree operations |
| `Searching.hpp` | Linear and bidirectional searching |
| `Sorting.hpp` | Bubble, efficient bubble, selection, and insertion sorting |
| `pstl.hpp` | Common header that includes the library components |

## Using the Library

Include the common header from a source file in the project root:

```cpp
#include "include/pstl/pstl.hpp"
#include <iostream>

int main()
{
    pstl::SinglyLL<int> list;

    list.InsertFirst(10);
    list.InsertLast(20);
    list.InsertLast(30);

    list.Display();
    std::cout << "Count: " << list.Count() << std::endl;

    return 0;
}
```

## Build and Run

Compile the integration test from the project root:

```bash
g++ -std=c++17 TestAll.cpp -o TestAll.exe
```

Run it on Windows Command Prompt:

```cmd
TestAll.exe
```

The integration test exercises the components through `pstl.hpp`. It asks for input for the searching and sorting tests.

Compile an individual example from the project root, for example:

```bash
g++ -std=c++17 example/Sorting.cpp -o Sorting.exe
```

Run it:

```cmd
Sorting.exe
```

Other example files can be compiled in the same way.

## Testing

`TestAll.cpp` is an integration test for the library components. Continue checking edge cases such as empty structures, single-element structures, duplicate values, invalid positions, and sorted or reverse-sorted arrays.

## Development Status

| Component | Status |
|---|---|
| Singly Linked List | Implemented |
| Singly Circular Linked List | Implemented |
| Doubly Linked List | Implemented |
| Doubly Circular Linked List | Implemented |
| Stack | Implemented |
| Queue | Implemented |
| Binary Search Tree | Implemented |
| Searching algorithms | Implemented |
| Sorting algorithms | Implemented |
| Common `pstl.hpp` header | Integrated |
| Example programs | Added |
| `TestAll.cpp` integration test | Added |

## Learning Objectives

- C++ templates and generic programming
- Pointers and dynamic memory management
- Linked lists, stacks, and queues
- Binary search trees
- Searching and sorting algorithms
- Object-oriented programming
- Header-only library design
- Namespaces and reusable components

## Author

**Pranav Avinash Narkhede**

## Language

**C++**
