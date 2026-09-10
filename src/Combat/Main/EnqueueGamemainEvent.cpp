#include <globaldefs.h>

extern "C" void SuspendVCountMatchIrq(void);
extern "C" void func_020d84e4(void);
extern "C" void func_020d84e8(void);
extern "C" void* GetMultiplayerState(void);
extern "C" void PopVCountInterruptState(void);
extern "C" void FatalHalt(void);
extern "C" int IsMultiplayerActive(int* obj);

struct QNode0205e1e4 {
    char pad[0x18];
    struct QNode0205e1e4* next;
};
struct QList0205e1e4 {
    struct QNode0205e1e4* head;
    struct QNode0205e1e4* tail;
    int count;
};
extern "C" struct QNode0205e1e4* func_0205e1e4(struct QList0205e1e4* list);

struct QNode0205e18c {
    char pad[0x18];
    struct QNode0205e18c* next;
};
struct QList0205e18c {
    struct QNode0205e18c* head;
    struct QNode0205e18c* tail;
    int count;
};
extern "C" void func_0205e18c(struct QList0205e18c* list, struct QNode0205e18c* node);

struct Inner0205e3ec { unsigned int v[4]; };
struct Struct0205e3ec { unsigned char a; unsigned char b; unsigned char pad[2]; struct Inner0205e3ec mid; };
extern "C" struct Struct0205e3ec* func_0205e3ec(struct Struct0205e3ec* dst, struct Struct0205e3ec* src);

struct EnqueuedNode_0205e330 {
    char pad[0x16];
    short field16;
};

struct SpinBlock_0205e330 {
    char pad0[0x508];
    volatile int c508;
    char pad1[0x514 - 0x508 - 4];
    volatile int c514;
    char pad2[0x520 - 0x514 - 4];
    volatile int c520;
};

// Posts one record to the global event queue at data_02100044: 192 records of 0x1c bytes with a
// free list at +0x1500, pending at +0x150c and finished at +0x1518. Byte 0 is the event tag, and
// func_ov017_021d48f0 calls data_ov017_021d7f98[tag] only when tag < 0xbc and the bit for it is set
// in the array at +0x1524. The short at +0x16 is a flag word the pump func_0205e57c reads; bit 0
// makes it wait for all five slots to be idle, and it re-emits the record once per channel with
// the channel index at +0x14, so one post fans out. Running out of free records is fatal.
extern "C" ARM void EnqueueGamemainEvent(unsigned char* obj, struct Struct0205e3ec* arg1, short arg2) {
    struct QNode0205e1e4* node;

    SuspendVCountMatchIrq();
    func_020d84e4();

    if (IsMultiplayerActive((int*)GetMultiplayerState())) {
        node = func_0205e1e4((struct QList0205e1e4*)(obj + 0x1500));
        if (node != NULL) {
            func_0205e3ec((struct Struct0205e3ec*)node, arg1);
            ((struct EnqueuedNode_0205e330*)node)->field16 = arg2;
            func_0205e18c((struct QList0205e18c*)(obj + 0x150c), (struct QNode0205e18c*)node);
        } else {
            for (int i0 = 0; i0 < ((struct SpinBlock_0205e330*)(obj + 0x1000))->c508; i0++);

            for (int i1 = 0; i1 < ((struct SpinBlock_0205e330*)(obj + 0x1000))->c514; i1++);

            for (int i2 = 0; i2 < ((struct SpinBlock_0205e330*)(obj + 0x1000))->c520; i2++);

            FatalHalt();
        }
    }

    func_020d84e8();
    PopVCountInterruptState();
}
