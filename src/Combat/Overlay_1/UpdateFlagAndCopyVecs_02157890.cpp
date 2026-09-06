#include <globaldefs.h>

extern "C" int func_ov001_021570b4(void* p);

struct SrcVec02157570 {
	unsigned char pad0[0x38c];
	int x;
	int y;
	int z;
};
struct DstVec02157570 {
	int x;
	int y;
	int z;
};

void CopyVector3_02157570(struct SrcVec02157570* src, struct DstVec02157570* dst);

// USA: func_ov001_02157890
ARM void UpdateFlagAndCopyVecs_02157890(char* d, struct DstVec02157570* v1, struct DstVec02157570* v2) {
	if (*(int*)(d + 0x8c0) != 0) {
		int flagA = 0;
		int flagB = 0;
		if (func_ov001_021570b4(d + 0x188) != 0) {
			flagA = 1;
		}
		if (func_ov001_021570b4(d + 0x524) != 0) {
			flagB = 1;
		}
		if (flagA != 0 && flagB != 0) {
			*(int*)(d + 0x8c0) = 0;
		}
		CopyVector3_02157570((struct SrcVec02157570*)(d + 0x188), v1);
		CopyVector3_02157570((struct SrcVec02157570*)(d + 0x524), v2);
	}
}
