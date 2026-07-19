#include <globaldefs.h>

struct HolderData0222f3f8 {
	unsigned char idx;
	unsigned char pad[7];
	unsigned char* ptr;
};
extern struct HolderData0222f3f8 data_ov031_02290ca0;
extern char* GetOffset400_02235c70(void);
extern void SetField4f6_02235c98(unsigned char);
extern "C" void func_ov031_0222f9ec(void);

// USA: func_ov031_0222f3f8
extern "C" ARM void func_ov031_0222f3f8(unsigned char id) {
	char* base = GetOffset400_02235c70();
	if ((unsigned char)base[0xf6] == id) return;
	data_ov031_02290ca0.ptr[0x43] = id;
	SetField4f6_02235c98(id);
	func_ov031_0222f9ec();
}
