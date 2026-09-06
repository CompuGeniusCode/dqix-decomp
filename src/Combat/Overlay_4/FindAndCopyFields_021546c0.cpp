#include <globaldefs.h>

struct Entry6_021546c0 {
	short id;
	short id2;
	unsigned char field4;
	unsigned char field5;
};

// USA: func_ov004_021546c0
ARM void FindAndCopyFields_021546c0(Entry6_021546c0* arr, int key1, int key2, unsigned char* out1, unsigned char* out2) {
	unsigned char i;
	for (i = 0; i < 20; i++) {
		Entry6_021546c0* e = &arr[i];
		short v = e->id;
		if (v == key1 && e->id2 == key2) {
			*out1 = e->field4;
			*out2 = e->field5;
			return;
		}
	}
}
