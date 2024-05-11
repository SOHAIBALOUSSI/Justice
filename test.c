#include "gc.h"
#include <stdio.h>


int main()
{
    char *nums = m_alloc(10 * sizeof(int), 0);
    nums = "batman";
    printf("%s\n", nums);
    char *list = m_alloc(1024 * 2, 0);
    char *list2 = m_alloc(1024, 0);
    list = "hi";
    list2 = "bad";
    m_alloc(0, FREE);
}