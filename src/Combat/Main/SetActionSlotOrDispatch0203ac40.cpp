#include <globaldefs.h>

int ReturnFalse020d84ec(void);
void* SetGlobalContext02110370(void* value);
int TrySetActionFromListEntry(void* obj, int id, int index);

// USA: func_0203ac40  (semantic: SetActionSlotOrDispatch0203ac40)
extern "C" ARM int func_0203ac40(void* obj, int a, int b, void* c) {
    char* p = (char*)obj;
    if (ReturnFalse020d84ec()) {
        *(unsigned short*)(p + 0xac) = (unsigned short)a;
        *(unsigned short*)(p + 0xae) = (unsigned short)b;
        return 1;
    }
    int result = 0;
    if (*(int*)p != 0) {
        SetGlobalContext02110370(p + 0x4);
        if (c != 0) {
            if (TrySetActionFromListEntry(c, a, b) != 0) result = 1;
        } else {
            if (TrySetActionFromListEntry(p + 0x98, a, b) != 0) result = 1;
        }
    }
    return result;
}
