#include <globaldefs.h>

struct Entry6_021538b4 {
	short id;
	char pad[4];
};

// USA: func_ov004_021538b4
ARM void* FindEntryByShort_021538b4(Entry6_021538b4* arr, int key) {
	unsigned char i;
	for (i = 0; i < 20; i++) {
		short v = arr[i].id;
		if (v == key) return &arr[i];
	}
	return NULL;
}
