#include <globaldefs.h>

extern "C" int func_ov000_0215e9fc(void* obj, void* buf, int count, int flag);
extern "C" void func_ov024_021ed8c0(void* wrapper, int p1, int p2, int* outVal, short* ptr5);

struct Wrapper_021ee378 {
    void* field0;
};

// USA: func_ov024_021ee378
ARM int SearchAndValidate_021ee378(struct Wrapper_021ee378* wrapper, int p1, int p2, int* outVal, short* ptr5) {
    int r = func_ov000_0215e9fc(wrapper->field0, ptr5, 4, 1);
    *outVal = r;
    if (r <= 0) {
        return 0;
    }
    func_ov024_021ed8c0(wrapper, p1, p2, outVal, ptr5);
    return *ptr5 >= 0 ? 1 : 0;
}
