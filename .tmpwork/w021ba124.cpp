#include <globaldefs.h>

struct Variant02030b0c_021ba124 {
    int tag;
    union {
        int i;
        float f;
    } u;
};

struct DataD438_021ba124 {
    unsigned char flag0;
    unsigned char flag1;
    unsigned char flag2;
    unsigned char pad3;
    int limit;
    char pad2[8];
    int active;
};

struct DataD7c54_021ba124 {
    signed char b0;
    signed char b1;
};

extern struct DataD438_021ba124 data_ov017_021d8438;
extern struct DataD7c54_021ba124 data_ov017_021d7c54;

extern "C" void* GetBattleStructv(void);
extern "C" void* func_0202ae18(void);
extern "C" int func_ov017_021b9bcc(int a);

extern int CheckField0NonZero(int* obj);
extern signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);
struct SearchStruct0202c1a4;
extern int GetIntFromVariant02030b0c(struct Variant02030b0c_021ba124* p);
extern int IsField3dcSet(void* obj);
extern void* GetField4IfField0Zero(void* s);

// USA: func_ov017_021ba124
#pragma optimize_for_size off
ARM int CheckThresholdAndDispatch_021ba124(struct Variant02030b0c_021ba124* obj, int minLevel) {
    if (data_ov017_021d8438.active != 0) return 1;
    if (data_ov017_021d7c54.b0 > -1) return 1;
    if (data_ov017_021d8438.flag1 != 0) return 1;
    if (data_ov017_021d7c54.b1 > -1) return 1;

    void* battle = GetBattleStructv();
    void* search = func_0202ae18();
    if (!CheckField0NonZero((int*)search)) return 1;
    if (GetSearchStructCurrentArrEntry((struct SearchStruct0202c1a4*)search) != 0) return 1;

    int a = GetIntFromVariant02030b0c(obj);
    struct Variant02030b0c_021ba124* p2 = (struct Variant02030b0c_021ba124*)((char*)obj + 8);
    obj = (struct Variant02030b0c_021ba124*)((char*)obj + 0x10);
    int b = GetIntFromVariant02030b0c(p2);

    if (a < 0) goto skipRange;
    {
        int limit = data_ov017_021d8438.limit;
        if (limit < a || b < limit) return 1;
    }
skipRange:

    if (minLevel >= 5) {
        struct Variant02030b0c_021ba124* p3 = obj;
        int c = GetIntFromVariant02030b0c(p3);
        obj = (struct Variant02030b0c_021ba124*)((char*)obj + 8);
        if (c != 0) {
            void* bs = GetBattleStructv();
            if (IsField3dcSet(bs) != 0) return 1;
            data_ov017_021d8438.flag2 = 1;
        }
    } else {
        if (data_ov017_021d8438.flag2 != 0) return 1;
    }

    int d = GetIntFromVariant02030b0c(obj);
    void* e = GetField4IfField0Zero((char*)obj + 8);
    if (e == (void*)0) return 0;

    if (func_ov017_021b9bcc(d) != 0) {
        data_ov017_021d8438.flag0 = 1;
    }
    return 1;
}
