#include <globaldefs.h>

struct S_cc758;
void InitStructField0x10To0xE(struct S_cc758* p);
extern "C" int func_020cc780(void* work, void* a, void* b, int c);

struct PathWork020cc940 {
    char data[0x48];
};

// USA: func_020cc940
ARM int TryParsePath020cc940(void* arg0, void* arg1) {
    struct PathWork020cc940 work;
    InitStructField0x10To0xE((struct S_cc758*)&work);
    if (func_020cc780(&work, arg1, arg0, 0) != 0) {
        return 1;
    }
    return 0;
}
