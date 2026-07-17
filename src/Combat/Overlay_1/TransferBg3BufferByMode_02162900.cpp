#include <globaldefs.h>
#include "System/Memory.h"

int TransferBg3ScreenData(int arg0, int arg1, unsigned int arg2);
int TransferSubBg3ScreenData(int arg0, int arg1, unsigned int arg2);
int TransferToBg3Char(int arg0, int arg1, unsigned int arg2);
int TransferToSubBg3Char(int arg0, int arg1, unsigned int arg2);
extern "C" int func_ov017_021d60f4(void* a);

// USA: func_ov001_02162900
ARM int TransferBg3BufferByMode_02162900(void* param) {
	unsigned char buf1[0x20];
	unsigned char buf2[0x600];
	int mode = func_ov017_021d60f4(param);
	VectorizedMemset(buf1, 0, sizeof(buf1));
	VectorizedMemset(buf2, 0, sizeof(buf2));
	if (mode == 0) {
		TransferToBg3Char((int)buf1, 0, sizeof(buf1));
		TransferBg3ScreenData((int)buf2, 0, sizeof(buf2));
	} else {
		TransferToSubBg3Char((int)buf1, 0, sizeof(buf1));
		TransferSubBg3ScreenData((int)buf2, 0, sizeof(buf2));
	}
	return 1;
}
