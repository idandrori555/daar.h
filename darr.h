/**
 * Dynamic Arrays Implementation In C Using Only Macros
 */

#ifndef DARR_H
#define DARR_H

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define DARR_INIT(T, name, initial_cap)          \
  struct                                         \
  {                                              \
    T *data;                                     \
    size_t len;                                  \
    size_t cap;                                  \
  } name = {                                     \
      .data = malloc(sizeof(T) * (initial_cap)), \
      .len = 0,                                  \
      .cap = (initial_cap)};                     \
  assert(name.data != NULL)

#define DARR_PUSH(T, name, value)                         \
  do                                                      \
  {                                                       \
    if ((name).len >= (name).cap)                         \
    {                                                     \
      size_t new_cap = (name).cap ? (name).cap * 2 : 1;   \
      T *tmp = realloc((name).data, sizeof(T) * new_cap); \
      assert(tmp != NULL);                                \
      (name).data = tmp;                                  \
      (name).cap = new_cap;                               \
    }                                                     \
    (name).data[(name).len++] = (value);                  \
  } while (0)

#define DARR_POP(name)        \
  (                           \
      assert((name).len > 0), \
      (name).data[--(name).len])

#define DARR_GET(name, index)       \
  (                                 \
      assert((index) < (name).len), \
      (name).data[index])

#define DARR_FREE(name) \
  do                    \
  {                     \
    free((name).data);  \
    (name).data = NULL; \
    (name).len = 0;     \
    (name).cap = 0;     \
  } while (0)

// DEBUG FUNCTIONS
#define DARR_PRINT_INT(name)                      \
  do                                              \
  {                                               \
    printf("Length: %zu, Capacity: %zu\nItems: ", \
           (name).len, (name).cap);               \
    for (size_t i = 0; i < (name).len; i++)       \
      printf("%d ", (name).data[i]);              \
    putchar('\n');                                \
  } while (0)

#endif
