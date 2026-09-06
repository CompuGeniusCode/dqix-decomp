#include <globaldefs.h>

extern "C" void func_ov031_022238cc(void);
extern "C" int func_ov031_0223be70(int a, int b, int c);
extern "C" void func_ov031_0223bbd8(void* obj, int a, int b, int c);

struct Entry0223bcc8 { unsigned int pad0; unsigned short h4; unsigned short pad6; };
struct Obj0223bcc8 { unsigned char pad0[8]; Entry0223bcc8* list; unsigned char count; };
void SetEntryHalfword4Bits_0223bcc8(Obj0223bcc8* obj, int idx, int val);

extern unsigned char data_ov031_02248998[];
extern int* data_ov031_02250bf0;

// USA: func_ov031_02223720
extern "C" ARM void func_ov031_02223720(int idx, int a1, int a2, int a3) {
    func_ov031_022238cc();
    unsigned char* p = data_ov031_02248998 + idx * 2;
    int i;
    for (i = 0; i < 2; i++) {
        unsigned char b = *p++;
        int r = func_ov031_0223be70(0, b, 1);
        data_ov031_02250bf0[i] = r;
        SetEntryHalfword4Bits_0223bcc8((Obj0223bcc8*)data_ov031_02250bf0[i], -1, 1);
    }
    func_ov031_0223bbd8((void*)data_ov031_02250bf0[0], -1, a1, a3);
    func_ov031_0223bbd8((void*)data_ov031_02250bf0[1], -1, a2, a3);
}
