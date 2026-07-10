#include <globaldefs.h>

extern int data_020e8de4[];

// USA: func_02098284
ARM int GetTableValueMod100(int unused, int value) {
    return data_020e8de4[value % 100];
}
