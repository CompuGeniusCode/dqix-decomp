#include <globaldefs.h>

struct Context022383fc {
	unsigned char pad0[0x1c];
	unsigned char ctxByte;
};
extern Context022383fc* data_ov031_02290d10;

struct ElemArray_0223baa0;
struct Elem8_0223baa0;
extern "C" Elem8_0223baa0* func_ov031_0223baa0(ElemArray_0223baa0* obj, int idx);
extern "C" void func_ov031_0223bdb0(int a, int b, void* c);
extern "C" void func_ov031_0223bbd8(void* a, int b, int c, int d);

struct Obj0223bcc8;
ARM void SetEntryHalfword4Bits_0223bcc8(Obj0223bcc8* obj, int idx, int val);

extern unsigned char data_ov031_022492fe[];
extern unsigned char data_ov031_022492ea[];
extern unsigned short data_ov031_02249364[];
extern unsigned short data_ov031_02249366[];

// USA: func_ov031_022383fc  (semantic: DispatchElemEffects_022383fc)
extern "C" ARM void func_ov031_022383fc(int idx) {
	Elem8_0223baa0* elem = func_ov031_0223baa0(
		*(ElemArray_0223baa0**)((char*)data_ov031_02290d10 + 8 + idx * 4), 0);

	unsigned char ctxByte1 = data_ov031_02290d10->ctxByte;
	unsigned char v1 = *((unsigned char*)data_ov031_022492fe + ctxByte1 * 2 + idx);
	func_ov031_0223bdb0(0, v1 + 1, elem);

	unsigned char ctxByte2 = data_ov031_02290d10->ctxByte;
	ElemArray_0223baa0* elem2 = *(ElemArray_0223baa0**)((char*)data_ov031_02290d10 + 8 + idx * 4);
	unsigned char v2 = *((unsigned char*)data_ov031_022492ea + ctxByte2 * 2 + idx);
	unsigned short t3 = *(unsigned short*)((char*)data_ov031_02249364 + ctxByte2 * 8 + v2 * 4);
	unsigned short t4 = *(unsigned short*)((char*)data_ov031_02249366 + ctxByte2 * 8 + v2 * 4);
	func_ov031_0223bbd8(elem2, -1, t3, t4);

	void* elem3 = *(void**)((char*)data_ov031_02290d10 + 8 + idx * 4);
	SetEntryHalfword4Bits_0223bcc8((Obj0223bcc8*)elem3, -1, 0);
}
