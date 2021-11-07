#include <stdio.h>
#include "kmp_test.h"
#include "kmp.h"

bool TestKMP(void)
{
    int pos;
    char *str = "my name is red!";
    char *substr = "red";
    bool found = KMPFindString(str, substr, 0, &pos);
    printf("test kmp: %d %d %s\n", found, pos, str+0+pos);

    str = "saoigvhieoraboaenbkeuirghregklxchvbiueqabngl;iewrhbiodftsibhidahrfnbiurewliubnfaibnuiaerbniuerabhur";
    substr = "hur";
    found = KMPFindString(str, substr, 0, &pos);
    printf("test kmp: %d %d %s\n", found, pos, str+0+pos);

    str = "aaaaaaaaaaaaaaaaaaaaaaaaaaababababaaabbbfffcccccccbababdsdsdsdsdsdsdsdbbbbbbaaaaaaaaauuuuuuuuuuu";
    substr = "aaabb";
    found = KMPFindString(str, substr, 0, &pos);
    printf("test kmp: %d %d %s\n", found, pos, str+0+pos);

    return true;
}