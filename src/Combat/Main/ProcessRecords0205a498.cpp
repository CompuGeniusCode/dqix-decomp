#include <globaldefs.h>

struct ActiveEntry02046900;
int CountActiveEntries(struct ActiveEntry02046900* entry);
struct Rec020467f0;
void* FindRecordByIndex(struct Rec020467f0* rec, int index, void** out, int* out44);
extern "C" void func_0205a528(void* a, void* ptr, int val, void* d);

// USA: func_0205a498
ARM int ProcessRecords0205a498(void* a, struct Rec020467f0* b, int flag, void* d) {
    int ret;
    if (flag) {
        int count = CountActiveEntries((struct ActiveEntry02046900*)b);
        for (int i = 0; i < count; i++) {
            void* dummyOut = 0;
            int fieldOut = 0;
            void* result = FindRecordByIndex(b, i, &dummyOut, &fieldOut);
            if (result) {
                func_0205a528(a, result, fieldOut, d);
            }
        }
        ret = 0;
    } else {
        ret = 1;
    }
    return ret;
}
