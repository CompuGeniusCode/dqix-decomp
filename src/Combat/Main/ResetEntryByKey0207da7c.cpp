#include <globaldefs.h>

struct Entry0207d9bc { unsigned short id; unsigned short pad; unsigned int a; unsigned int b; };
struct Init0207d7c0;
struct Entry0207d9bc* FindEntryByHalfword(struct Entry0207d9bc* arr, unsigned short key);
void InitStruct0207d7c0(struct Init0207d7c0* o);

// USA: func_0207da7c
ARM void ResetEntryByKey0207da7c(struct Entry0207d9bc* arr, unsigned short key) {
    struct Entry0207d9bc* e = FindEntryByHalfword(arr, key);
    if (e != NULL) {
        InitStruct0207d7c0((struct Init0207d7c0*)e);
    }
}
