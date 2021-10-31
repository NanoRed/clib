#include <stdio.h>
#include "list_test.h"

int main(void)
{
    /* testing list */
    if (TestList()) {
        printf("list tested successfully\n");
    } else {
        printf("list tested failed\n");
    }
}
