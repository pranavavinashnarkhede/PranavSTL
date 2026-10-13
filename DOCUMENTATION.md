# PranavSTL Documentation

## 1. Overview

PranavSTL is a custom C++ data structure and algorithm library inspired by the C++ Standard Template Library (STL). It is developed to practise templates, pointers, dynamic memory management, object-oriented programming, and reusable C++ components.

The library headers are located in `include/pstl/`, and example programs are located in `example/`.

## 2. Project Structure

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
├── README.md
└── DOCUMENTATION.md
```

## 3. Common Header and Namespace

The library components are organized in the `pstl` namespace. The common header, `pstl.hpp`, is intended to include the library's component headers.

Include it from a source file in the project root:

```cpp
#include "include/pstl/pstl.hpp"
```

Example:

```cpp
#include "include/pstl/pstl.hpp"
#include <iostream>

int main()
{
    pstl::SinglyLL<int> list;

    list.InsertFirst(10);
    list.InsertLast(20);
    list.Display();

    std::cout << "Count: " << list.Count() << std::endl;
    return 0;
}
```

If you only need one component, include its individual header instead.

## 4. Shared Node

`node.hpp` defines a templated node structure used by linked-list-based components.

```cpp
template <class T>
struct node
{
    T data;
    node<T>* next;
    node<T>* prev;
};
```

The `data` field stores an element. `next` points to the next node, and `prev` is used by doubly linked structures.

## 5. Data Structures

### 5.1 Singly Linked List — `SinglyLL.hpp`

A singly linked list stores elements in nodes connected through `next` pointers.

Main operations:

| Method | Purpose |
|---|---|
| `InsertFirst(value)` | Insert an element at the beginning |
| `InsertLast(value)` | Insert an element at the end |
| `InsertAtPos(value, position)` | Insert at a 1-based position |
| `DeleteFirst()` | Remove the first element |
| `DeleteLast()` | Remove the last element |
| `DeleteAtPos(position)` | Remove the element at a 1-based position |
| `Display()` | Display the elements |
| `Count()` | Return the element count |

### 5.2 Singly Circular Linked List — `SinglyCL.hpp`

A singly circular linked list connects the final node back to the first node.

It supports `InsertFirst()`, `InsertLast()`, `InsertAtPos()`, `DeleteFirst()`, `DeleteLast()`, `DeleteAtPos()`, `Display()`, and `Count()`.

### 5.3 Doubly Linked List — `DoublyLL.hpp`

A doubly linked list uses both `next` and `prev` links.

It supports `InsertFirst()`, `InsertLast()`, `InsertAtPos()`, `DeleteFirst()`, `DeleteLast()`, `DeleteAtPos()`, `Display()`, and `Count()`.

### 5.4 Doubly Circular Linked List — `DoublyCL.hpp`

A doubly circular linked list connects the last node to the first node and the first node back to the last node.

It supports `InsertFirst()`, `InsertLast()`, `InsertAtPos()`, `DeleteFirst()`, `DeleteLast()`, `DeleteAtPos()`, `Display()`, and `Count()`.

### 5.5 Stack — `Stack.hpp`

The stack follows **LIFO** (Last In, First Out).

| Method | Purpose |
|---|---|
| `Push(value)` | Add an element to the top |
| `Pop()` | Remove the top element |
| `Peep()` | Inspect the top element |
| `Display()` | Display stack elements |
| `Count()` | Return the number of elements |

The implementation uses a linked-list node structure.

### 5.6 Queue — `Queue.hpp`

The queue follows **FIFO** (First In, First Out).

| Method | Purpose |
|---|---|
| `Enqueue(value)` | Add an element to the rear |
| `Dequeue()` | Remove an element from the front |
| `Display()` | Display queue elements |
| `Count()` | Return the number of elements |

The implementation uses a linked-list node structure.

### 5.7 Binary Search Tree — `Tree.hpp`

The BST stores integer values while following the binary-search-tree ordering rule: values smaller than a node are placed in its left subtree, and larger values are placed in its right subtree.

Operations included in the current implementation:

- `Insert(value)` — insert a value
- `Inorder(root)` — traverse left subtree, node, right subtree
- `Preorder(root)` — traverse node, left subtree, right subtree
- `Postorder(root)` — traverse left subtree, right subtree, node
- `Search(root, value)` — search for a value
- `Count(root)` — count all nodes
- `CountLeaf(root)` — count leaf nodes
- `CountParent(root)` — count nodes with children
- `GetRoot()` — provide access to the root pointer for traversal and query methods

The tree implementation uses a separate tree-node type to avoid conflicting with the linked-list `node<T>`.

## 6. Algorithms

### 6.1 Searching — `Searching.hpp`

The `Searching` class manages an integer array.

- `Accept()` — read array elements from standard input.
- `Display()` — display the array.
- `LinearSearch(value)` — check elements sequentially.
- `BiDirectionalSearch(value)` — compare from both ends, moving toward the centre.

`BiDirectionalSearch()` is a bidirectional scan; it does not require the array to be sorted.

### 6.2 Sorting — `Sorting.hpp`

The `Sorting` class inherits from `ArrayX`, which stores and accepts an integer array. The class provides these ascending-order sorting algorithms:

- `BubbleSort()` — repeatedly compares and swaps adjacent elements.
- `BubbleSortEfficient()` — stops early when a pass performs no swaps.
- `SelectionSort()` — selects the smallest remaining element for each position.
- `InsertionSort()` — inserts each element into its correct position in the sorted portion.

The current `IsSorted` flag prevents another sorting call after a sort has completed. If new values are accepted after sorting, ensure the flag is reset appropriately in the class design.

## 7. Example Programs

Each file in `example/` demonstrates an individual component:

- `SinglyLL.cpp`
- `SinglyCL.cpp`
- `DoublyLL.cpp`
- `DoublyCL.cpp`
- `Stack.cpp`
- `Queue.cpp`
- `Tree.cpp`
- `Searching.cpp`
- `Sorting.cpp`

Each example has its own `main()` function, so compile examples separately rather than linking all example files into one executable.

## 8. Build and Run

Run commands from the project root with a C++ compiler such as `g++`.

Compile the integration test:

```bash
g++ -std=c++17 TestAll.cpp -o TestAll.exe
```

Run it in Windows Command Prompt:

```cmd
TestAll.exe
```

Compile an individual example:

```bash
g++ -std=c++17 example/Sorting.cpp -o Sorting.exe
```

Run it:

```cmd
Sorting.exe
```

Use the same pattern for other example files, changing the source filename and output executable name.

## 9. Integration Testing

`TestAll.cpp` exercises the components together through `pstl.hpp`. It is an integration test, not a complete automated unit-test suite.

Additional tests should cover:

- Empty structures
- Structures containing one element
- Duplicate values
- Invalid insertion and deletion positions
- Searching for both present and absent values
- Already sorted and reverse-sorted arrays
- Correct element counts after insertions and deletions

## 10. Learning Goals

PranavSTL provides practice with:

- C++ templates and generic programming
- Pointers and dynamic memory allocation
- Linked-list operations
- Stack and queue behaviour
- Binary search trees and tree traversal
- Searching and sorting algorithms
- Namespaces and header-only implementation
- Organizing and testing a multi-file C++ project

## 11. Author

**Pranav Avinash Narkhede**

## 12. Language

**C++**
