#include <globaldefs.h>

extern "C" ARM void* func_ov031_0223cf4c(unsigned int len, int align);
extern "C" ARM int func_ov031_0223b61c(const char* path, int* outLen, int flag);
extern "C" ARM void func_020bbd14(void);
extern "C" ARM void func_020bd368(void* a, void* b);
extern "C" ARM void func_020be6c4(int flag);
void ClearField0x0_020bc078(int* field);
ARM void SetEntryByte(int index, int value);
ARM void SetEntryHalfword(int index, int value);
ARM void SetTableEntryPointer(int index, void* value);
void* CallWithZeroExtra_0223e218(void*, void*, void*, int);
extern "C" ARM void func_ov031_02236900(void);

extern char data_ov031_0224be60[];

struct Struct0223677c {
	char pad[0x94];
	int field94;
	int field98;
	int field9c;
};

extern struct Struct0223677c* data_ov031_02290d00;

// USA: func_ov031_0223677c
extern "C" ARM void InitStruct0223677c(void) {
	int len;
	data_ov031_02290d00 = (struct Struct0223677c*)func_ov031_0223cf4c(0xa0, 4);
	data_ov031_02290d00->field98 = func_ov031_0223b61c(data_ov031_0224be60, &len, 0x20);
	func_020bbd14();
	func_020bd368(data_ov031_02290d00, (void*)data_ov031_02290d00->field98);
	func_020be6c4(0);
	ClearField0x0_020bc078(&data_ov031_02290d00->field94);
	int i = 0;
	do {
		SetEntryByte(i, 0x7f);
		SetEntryHalfword(i, 1);
		SetTableEntryPointer(i, 0);
	} while (++i < 0x20);
	data_ov031_02290d00->field9c = (int)CallWithZeroExtra_0223e218(0, (void*)func_ov031_02236900, 0, 0xc8);
}
