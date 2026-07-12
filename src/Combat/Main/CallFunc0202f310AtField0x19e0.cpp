#include <globaldefs.h>
void LoadEightEntriesFromTable(char*, void*);


// USA: func_020440b8
ARM void CallFunc0202f310AtField0x19e0(char* base, int arg) {
    LoadEightEntriesFromTable((char*)(base + 0x19e0), (void*)(arg));
}
