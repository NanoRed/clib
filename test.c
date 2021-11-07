#include <stdio.h>
#include "linked_list_test.h"
#include "stack_test.h"
#include "queue_test.h"
#include "kmp_test.h"

int main(void)
{
    /* testing list */
    if (TestList()) {
        printf("list test successfully\n");
    } else {
        printf("list test failed\n");
    }

    /* testing stack */
    if (TestStack()) {
        printf("stack test successfully\n");
    } else {
        printf("stack test failed\n");
    }

    /* testing queue */
    if (TestQueue()) {
        printf("queue test successfully\n");
    } else {
        printf("queue test failed\n");
    }

    /* testing kmp */
    if (TestKMP()) {
        printf("kmp test successfully\n");
    } else {
        printf("kmp test failed\n");
    }
}
