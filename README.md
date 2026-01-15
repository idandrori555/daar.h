# daar.h

A tiny header-only dynamic array for C, implemented with macros.

Simple, explicit, and easy to understand. No hidden magic.

## Features

* Header-only
* Type-safe via macros
* Automatic capacity growth
* Bounds checking with `assert`
* No dependencies beyond the C standard library

## Usage

```c
#include "darr.h"

DARR_INIT(int, arr, 4);

DARR_PUSH(int, arr, 10);
DARR_PUSH(int, arr, 20);

int x = DARR_GET(arr, 0);
int y = DARR_POP(arr);

DARR_PRINT_INT(arr);
DARR_FREE(arr);
```

## Notes

* `DARR_GET` and `DARR_POP` assert on invalid usage
* Capacity doubles automatically when full
* Printing is provided for `int` arrays only
* All allocations are checked with `assert`

Compile with `NDEBUG` to disable assertions.

## License

Public domain. Use it however you want.

