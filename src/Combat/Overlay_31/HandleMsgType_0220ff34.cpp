#include <globaldefs.h>

extern void* data_ov031_0224e580;

// USA: func_ov031_0220ff34
ARM int HandleMsgType_0220ff34(int* obj) {
	int type = *(int*)((char*)obj + 8);
	switch (type) {
	case 0xc9: {
		void* val = *(void**)((char*)data_ov031_0224e580 + 0x24);
		*(int*)((char*)val + 0x24) = *(int*)((char*)obj + 0xc);
		val = *(void**)((char*)data_ov031_0224e580 + 0x24);
		*(int*)((char*)val + 0x20) = 1;
		break;
	}
	case 0xca:
		break;
	}
	return 1;
}
