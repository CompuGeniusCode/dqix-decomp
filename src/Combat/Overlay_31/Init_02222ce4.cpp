#include <globaldefs.h>

void* AllocateAndZero0223cf4c(unsigned int len, int align);
extern "C" int func_ov031_0223be70(int a, int b, int c);
void SetEntryHalfword4Bits_0223bcc8(int a, int b, int c);
extern "C" void func_ov031_02222eb0(int a);
int Dispatch_02222f44(void);

void* CallWithZeroExtra_0223e218(void*, void*, void*, int);

extern unsigned char data_ov031_02248940[];
extern unsigned char data_ov031_02248924[];

struct Obj02222ce4 {
	int arr[5];
	unsigned char pad14[2];
	signed char field16;
	unsigned char field17;
};

extern Obj02222ce4* data_ov031_02250ba8;

// USA: func_ov031_02222ce4
ARM void Init_02222ce4(int idx) {
	unsigned char count = data_ov031_02248940[idx];
	Obj02222ce4 *obj = (Obj02222ce4*)AllocateAndZero0223cf4c(0x1c, 4);
	data_ov031_02250ba8 = obj;
	obj->field16 = -2;
	obj = data_ov031_02250ba8;
	obj->field17 = (unsigned char)idx;
	int i = 0;
	if (count > 0) {
		int n = i;
		unsigned char *p = data_ov031_02248924 + idx * 2;
		for (; i < count; i++) {
			int b = *p++;
			int v = func_ov031_0223be70(n, b, 1);
			obj = data_ov031_02250ba8;
			obj->arr[i] = v;
			obj = data_ov031_02250ba8;
			SetEntryHalfword4Bits_0223bcc8(obj->arr[i], -1, 1);
		}
	}
	int v2 = func_ov031_0223be70(0, 1, 1);
	obj = data_ov031_02250ba8;
	obj->arr[2] = v2;
	obj = data_ov031_02250ba8;
	SetEntryHalfword4Bits_0223bcc8(obj->arr[2], -1, 1);
	func_ov031_02222eb0(0xc0);
	void *r = CallWithZeroExtra_0223e218((void*)0, (void*)Dispatch_02222f44, (void*)0, 0x78);
	obj = data_ov031_02250ba8;
	obj->arr[3] = (int)r;
}
