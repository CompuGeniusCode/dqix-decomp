#include <globaldefs.h>

struct Owner020bec10;
void SetInnerFlag0x4At0x110(struct Owner020bec10* owner);
int LookupRecordAndDispatch020bebb4(void* a, int key, int arg2);

// USA: func_020bec30
ARM int TryApplyRecordAndSetFlag020bec30(void* a, int key, int arg2) {
    if (LookupRecordAndDispatch020bebb4(a, key, arg2) == 0) return 0;
    SetInnerFlag0x4At0x110((struct Owner020bec10*)a);
    return 1;
}
