#include <globaldefs.h>

struct ByteHeader0204693c;
extern void ResetByteHeader(ByteHeader0204693c* p);

struct Obj02046e08;
void InitBattleContext02046e08(struct Obj02046e08* obj);

struct Struct021b61e4 {
	unsigned char byte0;
	unsigned char pad1[0xfb];
	unsigned char byte_fc;
	unsigned char byte_fd;
	unsigned short half_fe;
	unsigned short half_100;
};

// USA: func_ov017_021b61e4
ARM void InitBattleObj_021b61e4(struct Struct021b61e4* p) {
	ResetByteHeader((ByteHeader0204693c*)p);
	p->byte0 = 0x16;
	InitBattleContext02046e08((struct Obj02046e08*)((char*)p + 0xc));
	p->byte_fc = 0;
	p->half_fe = 0;
	p->half_100 = 0;
	p->byte_fd = 0;
}
