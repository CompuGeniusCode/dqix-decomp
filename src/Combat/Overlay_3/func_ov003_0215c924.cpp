#include <globaldefs.h>

extern "C" void func_ov003_0215dc20(void* obj);

struct Obj0215e27c;
extern int DecrementFieldClampZero_0215e27c(struct Obj0215e27c* obj, int amount);

struct Self0215e3fc;
extern void ResetAnimStateIfIdle_0215e3fc(struct Self0215e3fc* self);

struct Struct_0205d81c;
struct Elem_0205d81c;
extern struct Elem_0205d81c* FindElementForFieldB0(struct Struct_0205d81c* s);
extern int IsField0x9cEqual3(unsigned char* obj);
extern void SetFieldAt0x30(void* obj, int value);
extern "C" int func_0205d0e0(void* p, int val);

typedef void (*DispatchFn_0217fe94)(void*, int);
struct DispatchEntry_0217fe94 {
    DispatchFn_0217fe94 fn;
    int flags;
};
extern struct DispatchEntry_0217fe94 data_ov003_0217fe94[];

// USA: func_ov003_0215c924
extern "C" ARM int func_ov003_0215c924(unsigned char* self, int amount) {
    if (self[0x3bc] == 5) {
        return 1;
    }

    func_ov003_0215dc20(self);

    if (DecrementFieldClampZero_0215e27c((struct Obj0215e27c*)self, amount) != 0) {
        return 0;
    }

    if (self[0x3f4] != 0 && self[0x3f5] == 0) {
        ResetAnimStateIfIdle_0215e3fc((struct Self0215e3fc*)self);
        return 0;
    }

    if (self[0x3bc] != 0) {
        struct Elem_0205d81c* elem = FindElementForFieldB0((struct Struct_0205d81c*)(self + 0x98));
        if (elem != 0 && IsField0x9cEqual3((unsigned char*)elem) != 0 && (*((unsigned char*)elem + 0xc5) & 2) == 0) {
            SetFieldAt0x30(self + 0x9c, -1);
        }
        self[0x3ba] = (unsigned char)func_0205d0e0(self + 0x98, amount);
    }

    unsigned char idx = self[0x3bc];
    if (data_ov003_0217fe94[idx].fn != 0) {
        struct DispatchEntry_0217fe94* entry = &data_ov003_0217fe94[idx];
        void* obj = self + (entry->flags >> 1);
        DispatchFn_0217fe94 fn;
        if (entry->flags & 1) {
            fn = *(DispatchFn_0217fe94*)(*(int*)obj + (int)*(DispatchFn_0217fe94 volatile*)&entry->fn);
        } else {
            fn = *(DispatchFn_0217fe94 volatile*)&entry->fn;
        }
        fn(obj, amount);
    }
    return 0;
}
