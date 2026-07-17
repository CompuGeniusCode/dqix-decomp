#include <globaldefs.h>

extern void* data_ov031_0224e580;

// USA: func_ov031_0220ff78
ARM int HandleMsgTypeExt_0220ff78(int* obj) {
	int type = *(int*)((char*)obj + 8);
	switch (type) {
	case 0xc9: {
		void* val = *(void**)((char*)data_ov031_0224e580 + 0x24);
		*(int*)((char*)val + 0x24) = *(int*)((char*)obj + 0xc);
		val = *(void**)((char*)data_ov031_0224e580 + 0x24);
		*(int*)((char*)val + 0x20) = 1;
		break;
	}
	case 0xca: {
		unsigned int payload = *(unsigned int*)((char*)obj + 0xc);
		if (payload - 2 <= 1u) {
			*(int*)((char*)(*(void**)((char*)data_ov031_0224e580 + 0x24)) + 0x24) = 0;
			*(int*)((char*)(*(void**)((char*)data_ov031_0224e580 + 0x24)) + 0x20) = 1;
		}
		break;
	}
	}
	return 1;
}
