#include <globaldefs.h>
#include "System/Memory.h"

struct S0224e5b4 { void* pad0; void* pField; };
extern S0224e5b4 data_ov031_0224e5b4;

struct T02211bd4 {
	unsigned char pad0[4];
	unsigned short field4;
	unsigned short field6;
	unsigned short field8;
	unsigned short fielda;
	unsigned char fieldc;
	unsigned char pad1[3];
	int field10;
	unsigned char pad2[0x64 - 0x14];
};

void SetGlobal022496fcField4_02207ce0(int v);

// USA: func_ov031_02211bd4
ARM void InitEntry_02211bd4(T02211bd4* entry, int b, int unused, int e) {
	if (data_ov031_0224e5b4.pField != NULL) return;
	VectorizedMemset(entry, 0, 0x64);
	entry->field8 = (unsigned short)b;
	entry->fielda = 1;
	entry->field4 = 1;
	entry->field6 = 0;
	entry->fieldc = 0;
	entry->field10 = 0;
	data_ov031_0224e5b4.pField = entry;
	SetGlobal022496fcField4_02207ce0(e);
}
