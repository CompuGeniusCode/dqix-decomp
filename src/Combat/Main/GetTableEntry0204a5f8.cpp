#include <globaldefs.h>

extern int data_020f0218[][4];

// USA: func_0204a5f8
ARM int GetTableEntry0204a5f8(int a, int b) {
    return data_020f0218[a][b];
}
