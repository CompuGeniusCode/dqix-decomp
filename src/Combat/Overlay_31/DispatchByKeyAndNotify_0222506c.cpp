#include <globaldefs.h>

struct Elem8_0222506c { int a; int b; };
struct ElemArray_0222506c { int pad0, pad1; Elem8_0222506c* arr; };
extern "C" Elem8_0222506c* func_ov031_0223baa0(ElemArray_0222506c* obj, int idx);
extern "C" int func_ov031_0223bdb0(int a, int b, int c);

struct Entry0223bcc8 { unsigned int pad0; unsigned short h4; unsigned short pad6; };
struct Obj0223bcc8 { unsigned char pad0[8]; Entry0223bcc8* list; unsigned char count; };
void SetEntryHalfword4Bits_0223bcc8(Obj0223bcc8* obj, int idx, int val);

extern "C" void func_ov031_0223bbd8(void* a, int b, int c, int d);

extern unsigned short data_ov031_02248ac8[];
extern unsigned short data_ov031_02248aca[];

struct EntityStruct0222506c { unsigned char pad[0x114]; ElemArray_0222506c* field114; unsigned char pad2[0x121 - 0x118]; signed char field121; };
extern EntityStruct0222506c* data_ov031_02250bfc;

// USA: func_ov031_0222506c  (semantic: DispatchByKeyAndNotify_0222506c)
extern "C" ARM void func_ov031_0222506c(void) {
	EntityStruct0222506c* obj = data_ov031_02250bfc;
	signed char key = obj->field121;
	char code;
	switch (key) {
	case 0x2f: code = 'B'; break;
	case 0x30: code = 'A'; break;
	case 0x31: code = 'C'; break;
	case 0x32: code = 'A'; break;
	case 0x33:
	case 0x34: code = 'E'; break;
	default: code = '@'; break;
	}

	Elem8_0222506c* elem = func_ov031_0223baa0(obj->field114, 0);
	func_ov031_0223bdb0(0, code, (int)elem);

	SetEntryHalfword4Bits_0223bcc8((Obj0223bcc8*)data_ov031_02250bfc->field114, -1, 2);

	int idx = data_ov031_02250bfc->field121 * 2;
	unsigned short a = data_ov031_02248ac8[idx];
	unsigned short b = data_ov031_02248aca[idx];
	func_ov031_0223bbd8(data_ov031_02250bfc->field114, -1, a, b);
}
