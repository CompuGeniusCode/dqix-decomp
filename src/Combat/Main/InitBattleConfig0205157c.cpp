#include <globaldefs.h>
#include "System/Memory.h"

void PackTriple10BitField020b38b0(int, int, int, int);
void StoreWordWithIndexTag(int, unsigned int);

// USA: func_0205157c  (semantic: InitBattleConfig0205157c)
extern "C" ARM void func_0205157c(char* obj) {
    VectorizedMemset(obj, 0, 0x9c);
    *(int*)(obj + 0x90) = 0;
    *(int*)(obj + 0x4c) = 0;
    *(int*)(obj + 0x50) = 0;
    *(int*)(obj + 0x54) = 1;
    *(int*)(obj + 0x58) = 0x5800;
    *(unsigned short*)(obj + 0x5c) = 0x7fff;
    *(int*)(obj + 0x60) = 0xf;
    for (int i = 0; i < 0x20; i++) {
        char* p = obj + i;
        p[0x64] = (unsigned char)(i * 2);
    }
    obj[0x84] = 1;
    obj[0x85] = 1;
    PackTriple10BitField020b38b0(0, 0, 0, 0);
    PackTriple10BitField020b38b0(1, 0, 0, 0);
    PackTriple10BitField020b38b0(2, 0, 0, 0);
    PackTriple10BitField020b38b0(3, 0, 0, 0);
    StoreWordWithIndexTag(0, 0);
    StoreWordWithIndexTag(1, 0);
    StoreWordWithIndexTag(2, 0);
    StoreWordWithIndexTag(3, 0);
    *(unsigned short*)(obj + 0x20) = 0x1000;
    *(unsigned short*)(obj + 0x22) = 0x1000;
    *(unsigned short*)(obj + 0x24) = 0x1000;
    *(unsigned short*)(obj + 0x26) = 0;
    *(unsigned short*)(obj + 0x28) = 0;
}
