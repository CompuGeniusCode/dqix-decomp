#include <globaldefs.h>

extern unsigned char data_ov031_02248998[];
extern int* data_ov031_02250bf0;

extern "C" void func_ov031_022238cc(void);
extern "C" int func_ov031_0223be70(int a, int b, int c);
extern "C" void func_ov031_0223bbd8(void* obj, int idx, int a, int b);

struct Obj0223bcc8 { unsigned char pad0[8]; void* list; unsigned char count; };
void SetEntryHalfword4Bits_0223bcc8(Obj0223bcc8* obj, int idx, int val);

// USA: func_ov031_02223720
#pragma optimize_for_size off
extern "C" ARM void func_ov031_02223720(int group, int b, int c, int d) {
	func_ov031_022238cc();
	unsigned char* p = &data_ov031_02248998[group * 2];
	int i = 0;
	int zero = 0;
	int one_a = 1;
	int negOne = -1;
	int one_b = one_a;
	do {
		int val = func_ov031_0223be70(zero, *p++, one_a);
		data_ov031_02250bf0[i] = val;
		SetEntryHalfword4Bits_0223bcc8((Obj0223bcc8*)data_ov031_02250bf0[i], negOne, one_b);
		i++;
	} while (i < 2);
	func_ov031_0223bbd8((void*)data_ov031_02250bf0[0], -1, b, d);
	func_ov031_0223bbd8((void*)data_ov031_02250bf0[1], -1, c, d);
}
