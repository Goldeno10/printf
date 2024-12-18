# printf Project Documentation

## Overview

The `printf` project is a custom implementation of the standard C library function `printf`. This project aims to replicate the behavior of `printf` by formatting and printing data to the standard output.

## Features

- Supports conversion specifiers for handling various data types.
- Handles edge cases and input errors gracefully.
- Optimized for performance and portability.

## Supported Conversion Specifiers

The custom `printf` implementation supports the following conversion specifiers:

| Specifier | Description                             |
| --------- | --------------------------------------- |
| `%c`      | Prints a single character               |
| `%s`      | Prints a string of characters           |
| `%d`      | Prints a decimal integer                |
| `%i`      | Prints an integer                       |
| `%u`      | Prints an unsigned integer              |
| `%o`      | Prints an octal number                  |
| `%x`      | Prints a hexadecimal number (lowercase) |
| `%X`      | Prints a hexadecimal number (uppercase) |
| `%%`      | Prints a percent sign                   |

## Files

The project consists of the following files:

| File                  | Description                                   |
| --------------------- | --------------------------------------------- |
| `_printf.c`           | Core implementation of the `printf` function  |
| `.0-main.c.swp`       | Swap file (temporary file)                    |
| `.gitignore`          | Specifies files to ignore in the repository   |
| `base_converter.c`    | Helper functions for base conversions         |
| `conversion_funcs.c`  | First set of conversion specifiers            |
| `conversion_funcs2.c` | Second set of conversion specifiers           |
| `conversion_funcs3.c` | Third set of conversion specifiers            |
| `format_func.c`       | Handles formatting of output                  |
| `get_func.c`          | Retrieves appropriate function for specifiers |
| `main.h`              | Header file containing prototypes and macros  |
| `print_number.c`      | Prints numeric data                           |
| `print_string.c`      | Prints string data                            |
| `printf`              | Executable file for the project               |

## Installation

1. Clone this repository to your local machine:
   ```bash
   git clone https://github.com/yourusername/printf.git
   ```
2. Navigate to the project directory:
   ```bash
   cd printf
   ```
3. Compile the code using GCC:
   ```bash
   gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o printf
   ```

## Usage

1. Include the `main.h` header file in your program.
2. Use the `_printf` function as you would use the standard `printf`.

Example:

```c
#include "main.h"

int main(void) {
    _printf("Hello, %s!\n", "World");
    _printf("Number: %d\n", 42);
    return 0;
}
```

3. Compile and run:
   ```bash
   gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o printf
   ./printf
   ```

## Testing

The project includes a suite of test cases:

1. Compile the test file:
   ```bash
   gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o printf_test
   ```
2. Run the tests:
   ```bash
   ./printf_test
   ```

## Contribution Guidelines

We welcome contributions to enhance the functionality and performance of the `printf` project. To contribute:

1. Fork the repository and clone it to your local machine.
2. Create a new branch for your feature or bug fix:
   ```bash
   git checkout -b feature-or-bugfix-name
   ```
3. Commit your changes with clear and concise messages:
   ```bash
   git commit -m "Description of your changes"
   ```
4. Push to your fork and submit a pull request.

## Authors

- [Muhammad Ibrahim](https://github.com/Goldeno10) - Contributor
- [Bayero Abdulkadir](https://github.com/Bayero-abdul) - Contributor

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- The creators of the C programming language.
- Open-source contributors for their valuable tools and documentation.

