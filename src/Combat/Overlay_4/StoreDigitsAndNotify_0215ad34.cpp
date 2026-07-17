#include <globaldefs.h>

struct Struct021707d8_0215ad34 { char pad[8]; char* ptr; };
extern Struct021707d8_0215ad34 data_ov004_021707d8;

struct Container020dedd0;
struct Element020de650;
extern "C" struct Container020dedd0* func_ov004_02156fd4(void* obj, int key);
struct Element020de650* FindElementByKey020dedd0(struct Container020dedd0* c, int key);
extern "C" void* func_ov004_02156fa0(void* obj, int key);
extern "C" void func_ov023_021fb27c(void* node, int val);

// USA: func_ov004_0215ad34
ARM int StoreDigitsAndNotify_0215ad34(void* obj) {
    struct Element020de650* elem = FindElementByKey020dedd0(func_ov004_02156fd4(obj, 5), *(short*)(data_ov004_021707d8.ptr + 0x6c));
    int val;
    int i;
    if (elem == NULL) return 0;
    val = *(int*)(data_ov004_021707d8.ptr + 0x78);
    for (i = 0; i < 7; i++) {
        signed char digit = val % 10;
        *(signed char*)(data_ov004_021707d8.ptr + i + 0x3f) = digit;
        val = val / 10;
        void* node = func_ov004_02156fa0(obj, i + 0x2d);
        if (node != NULL) {
            signed char d = *(signed char*)(data_ov004_021707d8.ptr + i + 0x3f);
            func_ov023_021fb27c(node, (unsigned short)(d + 0x1a));
        }
    }
    *(signed char*)(data_ov004_021707d8.ptr + 0x3e) = 0;
    return 0;
}
