#include <globaldefs.h>

struct Entry6_021550c8 {
	short id;
	char pad[4];
};

// USA: func_ov004_021550c8
ARM void* FindEntryByShort2_021550c8(Entry6_021550c8* arr, int key) {
	unsigned char i;
	for (i = 0; i < 2; i++) {
		short v = arr[i].id;
		if (v == key) return &arr[i];
	}
	return NULL;
}
