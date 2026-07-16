#include <globaldefs.h>

struct ClearFields021dae1cStruct {
	unsigned char pad[0x25];
	unsigned char a;
	unsigned char b;
	unsigned char c;
	unsigned char d;
	unsigned char e;
};

extern ClearFields021dae1cStruct data_ov027_021dd940;

// USA: func_ov027_021dae1c
ARM void ClearFlagsTo_021dae1c_021dae1c(void) {
	data_ov027_021dd940.a = 0;
	data_ov027_021dd940.b = 0;
	data_ov027_021dd940.c = 0;
	data_ov027_021dd940.d = 0;
	data_ov027_021dd940.e = 0;
}
