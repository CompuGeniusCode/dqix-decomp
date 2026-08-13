#include <globaldefs.h>

struct Struct02159108 {
	unsigned char pad0[0x48];
	short** arr48;
	unsigned char** arr4c;
	unsigned short* arr50;
	unsigned char pad1[0x372 - 0x54];
	unsigned short fieldA[3];
	short fieldB[3];
	unsigned char pad2[0x38c - 0x37e];
	unsigned char fieldC[3];
};

// USA: func_ov006_02159108  (semantic: AddStatusSlot02159108)
extern "C" ARM void func_ov006_02159108(struct Struct02159108* obj, int idx1, int val2, int val3) {
	short* arrA = obj->arr48[idx1];
	unsigned char* arrB = obj->arr4c[idx1];
	unsigned short count = obj->arr50[idx1];
	unsigned short i;
	unsigned char j;
	for (i = 0; i < count; i++) {
		if (val2 == arrA[i]) {
			arrB[i] -= val3;
		}
	}
	for (j = 0; j < 3; j++) {
		if (obj->fieldB[j] <= 0) {
			obj->fieldA[j] = idx1;
			obj->fieldB[j] = val2;
			obj->fieldC[j] = val3;
			return;
		}
	}
}
