#include <stdio.h>
#include "linked_list_test.h"

int main(void)
{
    /* testing list */
    if (TestList()) {
        printf("list tested successfully\n");
    } else {
        printf("list tested failed\n");
    }
}
