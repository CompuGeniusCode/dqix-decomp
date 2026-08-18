#include <globaldefs.h>
#include "std_library_functions.h"

extern int data_ov014_02189800;

struct HandleState_02188bd0;
ARM int InitHandleState_02188bd0(struct HandleState_02188bd0* s);
struct ResetFieldsStruct021845d4 {
	int a;
	short b;
	unsigned short c;
};
ARM void ResetFields_021845d4(struct ResetFieldsStruct021845d4* s);
ARM void Clear0x10Bytes02096fb0(void* p);

struct BitFlags021844c4 {
	unsigned char bit0 : 1;
	unsigned char bit1 : 1;
	unsigned char bit2 : 1;
	unsigned char bit3 : 1;
	unsigned char upper : 4;
};

struct State021844c4 {
	int f0;
	int f4;
	int f8;
	char clr10[0x10];
	char handleState[0x1e];
	char pad3a[2];
	int f3c;
	int f40;
	int f44;
	int f48;
	int f4c;
	int f50;
	int f54;
	int f58;
	int f5c;
	int f60;
	int f64;
	int f68;
	int f6c;
	int f70;
	int f74;
	int f78;
	unsigned char f7c;
	unsigned char f7d;
	unsigned char f7e;
	unsigned char f7f;
	unsigned char f80;
	unsigned char f81;
	struct BitFlags021844c4 flags82;
	char pad83[3];
	short arr86[5];
	char pad90[8];
	int f98;
	struct ResetFieldsStruct021845d4 f9c;
};

// USA: func_ov014_021844c4  (semantic: InitState_021844c4)
extern "C" ARM void func_ov014_021844c4(struct State021844c4* obj) {
	*(int*)((char*)&data_ov014_02189800 + 0xc) = 0;
	obj->f0 = 0;
	obj->f4 = 0;
	obj->f8 = 0;
	Clear0x10Bytes02096fb0(obj->clr10);
	InitHandleState_02188bd0((struct HandleState_02188bd0*)obj->handleState);
	obj->f3c = 0;
	obj->f40 = 0;
	obj->f44 = 0;
	obj->f48 = 0;
	obj->f4c = 0;
	obj->f50 = 0;
	obj->f54 = 0;
	obj->f58 = 0;
	obj->f5c = 0;
	obj->f60 = 0;
	obj->f64 = 0;
	obj->f68 = 0;
	obj->f6c = -1;
	obj->f70 = -1;
	obj->f78 = -1;
	obj->f74 = 0;
	obj->f7c = 0;
	obj->f7d = 0;
	obj->f7e = 0;
	obj->f7f = 0;
	obj->f80 = 0;
	obj->f81 = 0;
	obj->flags82.bit0 = 0;
	obj->flags82.bit1 = 0;
	obj->flags82.bit2 = 0;
	obj->flags82.upper = 0;
	obj->flags82.bit3 = 0;
	for (int i = 0; i < 5; i++) {
		obj->arr86[i] = -1;
	}
	obj->f98 = 0;
	ResetFields_021845d4(&obj->f9c);
	memset((char*)obj + 0x90, 0, 3);
	((unsigned char*)obj)[0x93] = 0;
	((unsigned char*)obj)[0x94] = 0;
}
