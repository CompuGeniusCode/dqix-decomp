#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct ByteHeader0204693c;
extern void ResetByteHeader(ByteHeader0204693c* p);

struct Struct021a9bc4 {
	unsigned char byte0;
	unsigned char pad1[7];
	unsigned char byte8;
	unsigned char pad2[0x26c - 0x9];
	unsigned char byte26c;
};

// USA: func_ov017_021a9bc4  (semantic: InitStructAndSetBattleField_021a9bc4)
extern "C" ARM void func_ov017_021a9bc4(Struct021a9bc4* self, unsigned char value) {
	ResetByteHeader((ByteHeader0204693c*)self);
	self->byte0 = 0x3b;
	self->byte8 = 0;
	self->byte26c = 0;
	BattleStruct* bs = GetBattleStruct();
	*((unsigned char*)bs + 0x6000 + 0x4de) = value;
}
