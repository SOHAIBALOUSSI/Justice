# Justice - Simple Garbage Collection in C

## Overview
Justice is a basic garbage collection mechanism implemented in C. It provides a rudimentary form of garbage collection by tracking allocated memory blocks and freeing them all at once when needed.

## Usage
To use Justice in your C program, include the `gc.h` header file and call the `m_alloc` function to allocate memory. When you're done with the allocated memory, call `m_alloc` again with the `FREE` parameter to free all allocated memory blocks.

```c
#include "gc.h"

int main()
{
    // Allocate memory
    int* ptr = (int*)m_alloc(sizeof(int), ALLOC);

    // Use ptr...
    // Code ...
    // Free all allocated memory
    m_alloc(0, FREE);

    return (EXIT_SUCCESS);
}
