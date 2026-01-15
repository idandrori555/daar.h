#include "darr.h"

int main(void)
{
  DARR_INIT(int, arr, 2);

  DARR_PUSH(int, arr, 1);
  DARR_PUSH(int, arr, 2);
  DARR_PUSH(int, arr, 3);

  DARR_PRINT_INT(arr);
}
