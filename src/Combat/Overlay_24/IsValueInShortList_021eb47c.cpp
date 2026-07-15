#include <globaldefs.h>

extern short data_ov024_021fe7aa[];

// USA: func_ov024_021eb47c
ARM int IsValueInShortList_021eb47c(int a0, int value) {
    short* p = data_ov024_021fe7aa;
    while (*p != -1) {
        if (*p == value) return 1;
        p++;
    }
    return 0;
}
