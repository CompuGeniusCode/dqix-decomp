#include <globaldefs.h>

struct FlagByte02214854 {
	unsigned char lowBits : 7;
	unsigned char topBit : 1;
};

// USA: func_ov031_02214854  (semantic: UpdateFlagBitsFromMax_02214854)
#pragma optimize_for_size off
extern "C" ARM int func_ov031_02214854(void* obj) {
	int count = *(unsigned char*)((char*)obj + 0xd12);
	int i, result;
	result = 0;
	i = 0;
	if (i < count) {
		FlagByte02214854* smallPtr = (FlagByte02214854*)((char*)obj + 0x447);
		char* bigPtr = (char*)obj;
		do {
			unsigned char gate = *(unsigned char*)((char*)obj + i * 4 + 0x444);
			if (gate != 0) goto setHigh02214854;
			{
				unsigned short maxVal = *(unsigned short*)(bigPtr + 0x4a6);
				if (maxVal - 1 == smallPtr->lowBits) goto setHigh02214854;
				smallPtr->topBit = 0;
				result = (result + 1) & 0xff;
				goto cont02214854;
			}
		setHigh02214854:
			smallPtr->topBit = 1;
		cont02214854:
			count = *(unsigned char*)((char*)obj + 0xd12);
			i++;
			smallPtr = (FlagByte02214854*)((char*)smallPtr + 4);
			bigPtr += 0xc0;
		} while (i < count);
	}
	return result;
}
