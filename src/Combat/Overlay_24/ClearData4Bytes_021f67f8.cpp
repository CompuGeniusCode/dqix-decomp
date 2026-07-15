#include <globaldefs.h>

extern unsigned char data_ov024_02200154[4];

// USA: func_ov024_021f67f8
ARM void ClearData4Bytes_021f67f8(void) {
	for (int i = 0; i < 4; i++) {
		data_ov024_02200154[i] = 0;
	}
}
