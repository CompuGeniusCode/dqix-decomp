#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct ByteHeader0204693c;
void ResetByteHeader(struct ByteHeader0204693c* p);

struct Obj021bb088;
void InitTimerObj_021bb088(struct Obj021bb088* p);

extern "C" void* func_ov017_0218b5b0(void);
unsigned int GetBitsInField0(unsigned int* obj, unsigned int mask);

struct BitField0x178_021baedc { unsigned char bit0:1; unsigned char rest:7; };

// USA: func_ov017_021baedc  (semantic: InitLargeStateStruct_021baedc)
extern "C" ARM void func_ov017_021baedc(void* self, int flag) {
	char* base = (char*)self;
	ResetByteHeader((struct ByteHeader0204693c*)base);
	*(signed char*)(base + 0x0) = 4;
	*(short*)(base + 0x8) = 0;
	*(short*)(base + 0xa) = 0;
	*(int*)(base + 0x90) = 0;
	*(unsigned short*)(base + 0x11a) = 0;
	*(short*)(base + 0x14e) = -1;
	*(unsigned char*)(base + 0x9c) = 0;
	*(unsigned char*)(base + 0x98) = 0;
	*(unsigned char*)(base + 0x99) = 0;
	*(unsigned char*)(base + 0x9a) = 0;
	*(unsigned char*)(base + 0x9b) = 0;
	*(unsigned char*)(base + 0xcc) = 0;
	*(unsigned char*)(base + 0xcd) = 0;
	*(signed char*)(base + 0xa0) = -1;
	*(int*)(base + 0x110) = -1;
	*(unsigned char*)(base + 0xfe) = 0;
	*(unsigned char*)(base + 0x100) = 0;
	*(unsigned char*)(base + 0x101) = 0;
	*(unsigned char*)(base + 0x102) = 0;
	*(unsigned char*)(base + 0x103) = 0;
	*(unsigned char*)(base + 0x104) = 0;
	*(unsigned char*)(base + 0x106) = 0;
	*(unsigned char*)(base + 0x107) = 0;
	*(unsigned char*)(base + 0x108) = 0;
	*(unsigned char*)(base + 0x109) = 0;
	*(unsigned char*)(base + 0x10a) = 0;
	*(unsigned char*)(base + 0x10b) = 0;
	*(unsigned char*)(base + 0x10c) = 0;
	if (flag == 0) {
		*(unsigned char*)(base + 0x105) = 0;
	}
	if (flag == 0) {
		*(unsigned short*)(base + 0x11c) = 0;
	}
	memset(base + 0xc, 0, 0x68);
	*(unsigned short*)(base + 0x114) = 0;
	InitTimerObj_021bb088((struct Obj021bb088*)(base + 0xd0));
	if (GetBitsInField0((unsigned int*)func_ov017_0218b5b0(), 0x1000) == 0) {
		((SafeAllocator*)(base + 0x7c))->ResetAllocatorPointer();
	}
	*(int*)(base + 0x120) = 0;
	((SafeAllocator*)(base + 0x124))->ResetAllocatorPointer();
	memset(base + 0x13c, 0, 0x12);
	memset(base + 0x150, 0, 0xa);
	*(int*)(base + 0x15c) = 0;
	*(unsigned char*)(base + 0xfd) = 0;
	*(signed char*)(base + 0x116) = -1;
	*(int*)(base + 0x160) = 0;
	*(unsigned char*)(base + 0x164) = 1;
	*(int*)(base + 0x170) = 0;
	*(int*)(base + 0x168) = 0;
	*(int*)(base + 0x16c) = 0;
	*(int*)(base + 0x138) = 0;
	*(unsigned char*)(base + 0xff) = 0;
	*(unsigned char*)(base + 0x174) = 0;
	*(unsigned char*)(base + 0x175) = 0;
	((BitField0x178_021baedc*)(base + 0x178))->bit0 = 0;
	((BitField0x178_021baedc*)(base + 0x178))->rest = 0;
	*(unsigned char*)(base + 0x179) = 0;
	*(unsigned char*)(base + 0x17a) = 0;
	*(unsigned char*)(base + 0x17b) = 0;
	*(float*)(base + 0x17c) = -1.0f;
	*(unsigned short*)(base + 0x184) = 0;
	memset(base + 0x188, 0, 0x30);
	memset(base + 0x1b8, 0, 0x10);
}
