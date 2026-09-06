#include <globaldefs.h>

struct InnerStruct02239e68 {
	unsigned char pad0[0x40];
	int field40;
	unsigned char pad1[0x18];
	unsigned short field5c;
	unsigned char pad2[2];
	unsigned short field60;
};

typedef void (*Callback02239e68)(int, void*, unsigned short);

struct OuterStruct02239e68 {
	Callback02239e68 field0;
	InnerStruct02239e68* field4;
};

extern OuterStruct02239e68 data_ov031_02290d18;
extern "C" ARM void func_020c9be0(void);
extern "C" ARM void func_ov031_02239368(int v);
extern "C" ARM unsigned short func_ov031_02239ee0(unsigned short v);
extern void* data_ov031_0224c464;

// USA: func_ov031_02239e68  (semantic: RefreshField5c_02239e68)
extern "C" ARM unsigned short func_ov031_02239e68(void) {
	if (data_ov031_02290d18.field4->field40 != 7) {
		func_020c9be0();
	}

	func_ov031_02239368(1);

	unsigned short r = func_ov031_02239ee0(data_ov031_02290d18.field4->field60);
	data_ov031_02290d18.field4->field5c = r;

	if (data_ov031_02290d18.field0) {
		data_ov031_02290d18.field0(0x8000000, &data_ov031_0224c464, data_ov031_02290d18.field4->field5c);
	}

	return data_ov031_02290d18.field4->field5c;
}
