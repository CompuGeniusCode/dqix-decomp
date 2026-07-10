#include <globaldefs.h>

struct Variant02030b0c;
int GetIntFromVariant02030b0c(Variant02030b0c* p);
extern "C" void func_02027b10(void* obj, int value);
extern int data_020fdc4c;

// USA: func_0201f390
ARM int StoreDecodedIntViaHandler0201f390(Variant02030b0c* arg) {
    int value = GetIntFromVariant02030b0c(arg);
    func_02027b10(*(char**)((char*)&data_020fdc4c + 0x10), value);
    return 1;
}
