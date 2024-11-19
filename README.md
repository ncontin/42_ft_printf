# 42_ft_printf

## Overview

`42_ft_printf` is an implementation of the standard C library function `printf`. This project is part of the 42 curriculum and aims to deepen understanding of variadic functions, formatted output, and overall C programming skills.

## Features

- Supports a variety of format specifiers:
  - `%c` - Character
  - `%s` - String
  - `%p` - Pointer address
  - `%d` / `%i` - Signed decimal integer
  - `%u` - Unsigned decimal integer
  - `%x` / `%X` - Unsigned hexadecimal integer
  - `%%` - Percent sign

## Installation

To use `42_ft_printf` in your project, clone the repository and compile it with your code:

```sh
git clone https://github.com/ncontin/42_ft_printf.git
cd 42_ft_printf
make
```

## Usage

Include the header file and use `ft_printf` as you would use `printf`:

```c
#include "ft_printf.h"

int main() {
  ft_printf("Hello, %s!\n", "world");
  return 0;
}
```
