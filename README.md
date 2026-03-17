*This project has been created as part of the 42 curriculum by oharoon.*

# ft_printf

## Description
`ft_printf` is a 42 project where the goal is to reimplement the core behavior of C's `printf` using variadic arguments.

Prototype:

```c
int ft_printf(const char *format, ...);
```

In this implementation, the following mandatory conversions are supported:
- `%c` character
- `%s` string
- `%p` pointer (hexadecimal with `0x`, `(nil)` for null)
- `%d` signed decimal
- `%i` signed integer
- `%u` unsigned decimal
- `%x` unsigned hexadecimal (lowercase)
- `%X` unsigned hexadecimal (uppercase)
- `%%` literal percent sign

## Project Structure
- `ft_printf/ft_printf.c`: main parser loop and variadic entry point.
- `ft_printf/string_handle.c`: dispatches each conversion specifier.
- `ft_printf/converter.c`: recursive base conversion helpers for numbers.
- `ft_printf/pointerhandle.c`: pointer formatting logic.
- `ft_printf/ft_putchar.c`: character and string output helpers.
- `ft_printf/ft_strlen.c`: local utility length function.
- `ft_printf/ft_printf.h`: public API and helper prototypes.
- `ft_printf/Makefile`: builds `libftprintf.a`.

## Instructions
### Build the library
From the project root:

```bash
make -C ft_printf
```

This generates:
- `ft_printf/libftprintf.a`

### Clean objects / full clean / rebuild

```bash
make -C ft_printf clean
make -C ft_printf fclean
make -C ft_printf re
```

### Use the library in a test program
Example compile command (from project root):

```bash
cc -Wall -Wextra -Werror main.c -Lft_printf -lftprintf -Ift_printf -o printf_test
```

## Algorithm and Data Structure (Detailed and Justified)
### 1. Format string linear scan
`ft_printf` iterates once over the `format` string. For each character:
- If it is a normal character, it writes directly to `stdout`.
- If it is `%`, it reads the next character as the conversion specifier and delegates handling to `string_handle`.

Why this is chosen:
- It mirrors how `printf` is naturally interpreted.
- It keeps time complexity linear in the format length (excluding digit output cost).
- It is easy to extend for additional flags in the future.

### 2. Dispatcher per conversion
`string_handle` receives the conversion character and the active `va_list`.
It maps each conversion to a dedicated helper:
- `%c` -> `ft_putchar`
- `%s` -> `ft_putstr`
- `%p` -> `pointerhandle`
- `%d`/`%i`/`%u`/`%x`/`%X` -> `converter` with different bases
- `%%` -> direct `%` write

Why this is chosen:
- Centralized conversion routing keeps `ft_printf` small and readable.
- Behavior per specifier stays isolated and easier to test.

### 3. Recursive numeric conversion
`converter` and `converter_ptr` print digits recursively in the requested base.
The base is represented as a string (for example `"0123456789abcdef"`).

How it works:
- Recurse on `nbr / base_size` until the highest digit is reached.
- Print current digit via `base[nbr % base_size]` while the stack unwinds.
- Return the total number of written characters.

Why this is chosen:
- Avoids temporary buffers and reverse operations.
- Reuses one generic mechanism for decimal and hexadecimal outputs.
- Keeps implementation compact and understandable for mandatory scope.

### 4. Pointer handling
`pointerhandle` prints `(nil)` for null pointers, otherwise prints `0x` + lowercase hexadecimal address via `converter_ptr`.

Data structure choice:
- The implementation uses no custom container.
- Main data flow relies on:
  - the format string (`const char *`),
  - the variadic argument cursor (`va_list`),
  - base strings used as lookup tables for digit rendering.

This is appropriate for `ft_printf` mandatory scope because parsing is sequential and stateless apart from the `va_list` position.

## Notes on Subject Constraints
- Mandatory external functions allowed by the subject: `malloc`, `free`, `write`, `va_start`, `va_arg`, `va_copy`, `va_end`.
- This repository includes a Makefile using `ar` to build `libftprintf.a`.
- Bonus flags (`-0.`, width, `# +` and space) are not implemented in this mandatory version.

## Resources
- 42 subject: `en.subject.pdf`
- Variadic functions: `man 3 stdarg`
- Output syscall: `man 2 write`
- Standard printf reference: `man 3 printf`
- C number systems and integer formatting references (decimal/hexadecimal)

AI usage for this repository:
- AI was used to draft and structure this `README.md`.
- The final content was aligned with the local source code and the 42 `ft_printf` subject requirements.
