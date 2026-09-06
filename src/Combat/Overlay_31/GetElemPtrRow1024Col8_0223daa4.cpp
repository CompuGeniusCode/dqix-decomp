#include <globaldefs.h>

extern char* data_ov031_02290d60;

// USA: func_ov031_0223daa4
ARM void* GetElemPtrRow1024Col8_0223daa4(int row, int col) {
	return data_ov031_02290d60 + (row << 0xa) + (col << 0x3);
}
