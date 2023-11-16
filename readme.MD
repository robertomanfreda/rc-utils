# RC-Utils

## Overview

RC-Utils is a comprehensive C11 utility library designed to enhance the standard C programming experience.
It offers a variety of functionalities including advanced collections, memory management tools, and a robust logging
system.   
Tailored for developers seeking to streamline their C development process, RC-Utils encapsulates complex tasks in an
intuitive and efficient manner.

## Features

- **Collections:** Implementations of various data structures like lists, queues, and stacks with optimized performance
  and memory usage.
- **Memory Management:** Custom memory allocation and deallocation wrappers for improved tracking and management of
  memory usage.
- **Logging System:** A versatile logging system that supports different levels of log messages for effective debugging
  and monitoring.
- **More Utilities:** Additional helper functions and utilities to facilitate common programming tasks in C.

## Getting Started

### Prerequisites

- CMake version 3.26 or higher
- A C11-compatible compiler

Certainly! Here's a revised version of the "Building the Project" section with an added subsection for executing tests:

---

### Building the Project

1. **Clone the Repository:**
   Clone the `rc-utils` repository and navigate into the project directory:
   ```sh
   git clone https://github.com/robertomanfreda/rc-utils.git
   cd rc-utils
   ```

2. **Create and Navigate to the Build Directory:**
   Create a separate build directory (this keeps build files separate from source files) and navigate into it:
   ```sh
   mkdir build && cd build
   ```

3. **Configure the Project with CMake:**
   Use CMake to configure the project and generate necessary build files:
   ```sh
   cmake ..
   ```
   This command prepares the build system based on the configuration specified in `CMakeLists.txt`.

4. **Build the Project:**
   Compile the project using CMake. This command builds all targets defined in your CMake configuration, including your
   main application and any libraries:
   ```sh
   cmake --build .
   ```

---

### Executing Tests

Running tests is an essential step to validate the functionality and reliability of your code. If your project includes
unit tests, follow these steps to compile and run them after building the project:

1. **Build the Project with Tests:**
   First, ensure your project, including the tests, is built. Follow the "Building the Project" steps above to complete
   this. The tests should be compiled along with the project if they are correctly configured in your CMakeLists.txt.

2. **Run the Tests:**
   After building the project, use the `make test` command in the build directory to run the tests:
   ```sh
   make test
   ```
   This command executes all tests that have been added to the project with CMake's `add_test()` command.

3. **Detailed Test Output:**
   If you need more detailed output for the tests (such as individual test case results), you can run the tests with
   additional verbosity:
   ```sh
   make test ARGS="-V"
   ```
   The `-V` flag tells `make` to run the tests in verbose mode, showing more detailed information.

4. **Running Specific Tests:**
   If your testing setup allows it, you can run specific tests by specifying a test target. This requires the tests to
   be set up as individual targets in your CMake configuration. For example, to run a test named `MyTest`, use:
   ```sh
   make test_rc_memory
   ```

---

This revised documentation provides clear instructions for both building the project and running the unit tests,
ensuring that users and developers can easily compile and verify the project.

### Usage

Include the desired headers from the `rc-utils` library in your C project and link against the `rc-utils` library.

Example:

```c
#include "rc_list.h"
#include "rc_memory.h"

int main() {
    long long foo = 8;
    long long bar = 9;
    long long baz = 7;

    List *list = list_create(TYPE_LONGLONG);
    
    list_append(list, &foo);
    list_append(list, &bar);
    list_prepend(list, &baz);
    
    list_print(list);
    
    list_destroy(list);
    
    memory_print_usage("END");

    return 0;
}
```

that will return something like this

```
{7, 8, 9}

-------------- Memory Report: END --------------
 + Total Allocated Memory: 88 bytes
 + Total Freed Memory: 88 bytes
 + Net Memory Usage: 0 bytes
------------------------------------------------

Process finished with exit code 0
```

## Documentation

For detailed documentation on each module and function, refer to the `docs` directory in the repository.

## License

RC-Utils is licensed under the [GNU GPLv3](https://www.gnu.org/licenses/gpl-3.0.html).  
See the [LICENSE](LICENSE) file for more details.