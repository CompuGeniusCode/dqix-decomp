#include <globaldefs.h>

struct AxisFloats0203b5f8;
int IsAxisIntZero(struct AxisFloats0203b5f8* s, int axis);
extern "C" struct AxisFloats0203b5f8* func_ov017_0218b5b0(void);
int GetGlobalField0x1c020421a0(void);
extern char* data_ov004_02171010;
void SetByteFieldAt0x765(unsigned char* obj, unsigned char value);
struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
extern struct Obj0205eaa0 data_02108760;
int ToggleFlag8OnTwoObjs_021651c8(void* a1);

// USA: func_ov004_021652e8
ARM int UpdateAxisFlagAndDispatch_021652e8(void* a1) {
    struct AxisFloats0203b5f8* axis = func_ov017_0218b5b0();
    if (IsAxisIntZero(axis, 0) == 0) goto ret0;
    if (IsAxisIntZero(axis, 1) != 0) goto mainlogic;
ret0:
    return 0;

mainlogic:
    if (*(void**)((char*)GetGlobalField0x1c020421a0() + 0x998) != NULL) return 0;

    {
        char* base = data_ov004_02171010;
        unsigned char v = *(unsigned char*)(base + 0x1000 + 0x8f4);
        if (v == 0) return 0;

        unsigned char* target = (unsigned char*)(base + 0xfc + 0x1800);
        v = *(unsigned char*)(base + 0x1000 + 0x8fc);
        if (v == 0) {
            *target = 1;
        } else if (v == 1) {
            *target = 0;
        }

        unsigned char* fieldObj = *(unsigned char**)((char*)func_ov017_0218b5b0() + 0x3000 + 0x6d0);
        unsigned char v2 = *(unsigned char*)(data_ov004_02171010 + 0x1000 + 0x8fc);
        if (v2 == 1) {
            SetByteFieldAt0x765(fieldObj, 0);
        } else if (v2 == 0) {
            SetByteFieldAt0x765(fieldObj, 1);
        }

        ToggleFlag8OnTwoObjs_021651c8(a1);
        DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
        return 0;
    }
}
