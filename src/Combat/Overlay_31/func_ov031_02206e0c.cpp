#include <globaldefs.h>
#include "System/Memory.h"

void SetField164_02203164(int v);
void ClearField164_02203178(void);
extern "C" int func_ov031_02204c84(int a);

struct VTable02206e0c {
	char pad[0x18];
	void* (*alloc)(int size);
	void (*free)(void* p);
};
extern VTable02206e0c* data_ov031_022496a4;

#pragma optimize_for_size off
// USA: func_ov031_02206e0c  (semantic: AllocAndRunWithTempBlock_02206e0c)
extern "C" ARM int func_ov031_02206e0c(int a) {
	char buf[0x64];
	if (a == 0) return 0;

	void* p = data_ov031_022496a4->alloc(0xfd0);
	if (p == 0) return 0;

	VectorizedMemset(buf, 0, 0x64);
	char* seg = (char*)p + 0x368;
	char* seg2 = seg + 0x800;
	*(int*)(buf + 0x40) = (int)p;
	*(int*)(buf + 0x3c) = 0xb68;
	*(int*)(buf + 0x4c) = (int)seg2;
	*(int*)(buf + 0x48) = 0x466;
	SetField164_02203164((int)buf);

	int result = func_ov031_02204c84(a);
	ClearField164_02203178();
	data_ov031_022496a4->free(p);
	return result;
}
