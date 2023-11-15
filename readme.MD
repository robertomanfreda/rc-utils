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

### Building the Project

1. Clone the repository:
   ```sh
   git clone https://github.com/robertomanfreda/rc-utils.git
   cd rc-utils
   ```

2. Create a build directory and navigate into it:
   ```sh
   mkdir build && cd build
   ```

3. Configure the project with CMake:
   ```sh
   cmake ..
   ```

4. Build the project:
   ```sh
   cmake --build .
   ```

### Usage

Include the desired headers from the `rc-utils` library in your C project and link against the `rc-utils` library.

Example:

```c
#include "rc_list.h"
#include "rc_memory.h"

int main() {
    List *list = list_create();
    
    list_append(list, 10);
    list_prepend(list, 9);

    list_print(list);

    printf("List is not empty - true: %s\n", list_is_not_empty(list) ? "true" : "false");

    List *listCopy = list_deep_copy(list);
    list_print(listCopy);

    memory_print_usage("END");
    
    return 0;
}
```

## Documentation

For detailed documentation on each module and function, refer to the `docs` directory in the repository.

## License

RC-Utils is licensed under the [GNU GPLv3](https://www.gnu.org/licenses/gpl-3.0.html). See the [LICENSE](LICENSE) file
for more details.