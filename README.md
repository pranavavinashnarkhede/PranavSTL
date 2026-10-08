````markdown
# PranavSTL

PranavSTL is a custom C++ template-based data structure library inspired by the C++ Standard Template Library (STL).

The project is developed from scratch to understand how fundamental data structures and reusable C++ library components are designed and implemented.

## Features

Currently implemented:

- Singly Linked List
- Singly Circular Linked List
- Doubly Linked List
- Doubly Circular Linked List

All data structures are implemented using C++ templates, allowing them to work with different data types.

## Project Structure

```text
PranavSTL/
│
├── include/
│   └── pstl/
│       ├── node.hpp
│       ├── SinglyLL.hpp
│       ├── SinglyCL.hpp
│       ├── DoublyLL.hpp
│       ├── DoublyCL.hpp
│       └── pstl.hpp
│
├── example/
│   ├── SinglyLL.cpp
│   ├── SinglyCL.cpp
│   ├── DoublyLL.cpp
│   └── DoublyCL.cpp
│
└── README.md
````

## Data Structures

### Singly Linked List

Implemented in `SinglyLL.hpp`.

Supported operations:

* `InsertFirst()`
* `InsertLast()`
* `InsertAtPos()`
* `DeleteFirst()`
* `DeleteLast()`
* `DeleteAtPos()`
* `Display()`
* `Count()`

### Singly Circular Linked List

Implemented in `SinglyCL.hpp`.

Supported operations:

* `InsertFirst()`
* `InsertLast()`
* `InsertAtPos()`
* `DeleteFirst()`
* `DeleteLast()`
* `DeleteAtPos()`
* `Display()`
* `Count()`

### Doubly Linked List

Implemented in `DoublyLL.hpp`.

Supported operations:

* `InsertFirst()`
* `InsertLast()`
* `InsertAtPos()`
* `DeleteFirst()`
* `DeleteLast()`
* `DeleteAtPos()`
* `Display()`
* `Count()`

### Doubly Circular Linked List

Implemented in `DoublyCL.hpp`.

Supported operations:

* `InsertFirst()`
* `InsertLast()`
* `InsertAtPos()`
* `DeleteFirst()`
* `DeleteLast()`
* `DeleteAtPos()`
* `Display()`
* `Count()`

## Common Node

`node.hpp` contains the common template node structure used by the linked-list implementations.

```cpp
template <class T>
struct node
{
    T data;
    struct node<T> *next;
    struct node<T> *prev;
};
```

## Common Header

`pstl.hpp` acts as the main library header and includes all currently implemented data structures.

```cpp
#include "../include/pstl/pstl.hpp"
```

This allows the user to access the complete library through a single header.

## Namespace

All library components are organized inside the:

```cpp
namespace pstl
```

namespace.

Example:

```cpp
pstl::SinglyLL<int> list;
pstl::SinglyCL<int> circularList;
pstl::DoublyLL<int> doublyList;
pstl::DoublyCL<int> doublyCircularList;
```

## Templates

PranavSTL uses C++ templates so the same data structure can work with different data types.

Example:

```cpp
pstl::SinglyLL<int> intList;
pstl::SinglyLL<double> doubleList;
```

## Example

```cpp
#include <iostream>
#include "../include/pstl/pstl.hpp"

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

## Compilation

Navigate to the `example` directory:

```cmd
cd example
```

Compile the examples individually:

```cmd
g++ SinglyLL.cpp -o SinglyLL
```

```cmd
g++ SinglyCL.cpp -o SinglyCL
```

```cmd
g++ DoublyLL.cpp -o DoublyLL
```

```cmd
g++ DoublyCL.cpp -o DoublyCL
```

Run the required example:

```cmd
SinglyLL
```

```cmd
SinglyCL
```

```cmd
DoublyLL
```

```cmd
DoublyCL
```

## Development Status

| Component                   | Status    |
| --------------------------- | --------- |
| Singly Linked List          | Completed |
| Singly Circular Linked List | Completed |
| Doubly Linked List          | Completed |
| Doubly Circular Linked List | Completed |
| Common `node.hpp`           | Completed |
| Common `pstl.hpp`           | Completed |
| Example/Test Programs       | Completed |

## Learning Objectives

The project focuses on understanding:

* C++ Templates
* Data Structures
* Pointers
* Dynamic Memory Management
* Linked Lists
* Circular Linked Lists
* Doubly Linked Lists
* Object-Oriented Programming
* Header-only C++ library design
* Namespace organization
* Reusable C++ components
* Library project structure

## Author

**Pranav Avinash Narkhede**

## Language

**C++**

```
```
