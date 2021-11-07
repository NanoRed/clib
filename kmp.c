#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "kmp.h"

static const int INITIAL_LENGTH = 8;

bool make_arr(int **arr, int len)
{
    if (*arr == NULL) {
        if (!(*arr = (int *)malloc(sizeof(int) * len))) {
            return false;
        }
    } else {
        if (!realloc(*arr, sizeof(int) * len)) {
            free(*arr);
            return false;
        }
    }
    return true;
}

bool get_next(const char *substr, int **next)
{
    if (!*substr) {
        return false;
    }
    int i = 0;
    int j = -1;
    int iLen = INITIAL_LENGTH;
    int *tmpNext = NULL;
    if (!make_arr(&tmpNext, iLen)) {
        return false;
    }
    tmpNext[0] = j;
    while (substr[i+1]) {
        if (j == -1 || substr[i] == substr[j]) {
            i++;
            j++;
            if (i == iLen) {
                iLen *= 2;
                if (!make_arr(&tmpNext, iLen)) {
                    return false;
                }
            }
            if (substr[i] == substr[j]) {
                tmpNext[i] = tmpNext[j];
            } else {
                tmpNext[i] = j;
            }
        } else {
            j = tmpNext[j];
        }
    }
    *next = tmpNext;
    return true;
}

bool KMPFindString(const char *str, const char *substr, int start, int *pos)
{
    if (!*str) {
        return false;
    }
    int i = start;
    int j = 0;
    int *next;
    if (!get_next(substr, &next)) {
        *pos = -1;
        return false;
    }
    while (str[i]) {
        if (j == -1 || str[i] == substr[j]) {
            i++;
            j++;
            if (!substr[j]) {
                *pos = i - j;
                free(next);
                return true;
            }
        } else {
            j = next[j];
        }
    }
    *pos = -1;
    free(next);
    return false;
}

