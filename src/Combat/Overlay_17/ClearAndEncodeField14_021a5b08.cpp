#include <globaldefs.h>

int EncodeStreamValue020dc0c8(int value);

struct Node0x20_021a5ad0 {
	unsigned char pad[0x14];
	int field14;
	unsigned char pad2[8];
};

// USA: func_ov017_021a5b08
ARM void ClearAndEncodeField14_021a5b08(Node0x20_021a5ad0* arr, int count) {
	for (int i = 0; i < count; i++) {
		int old = arr[i].field14;
		arr[i].field14 = 0;
		if (old != 0) {
			EncodeStreamValue020dc0c8(old);
		}
	}
}
