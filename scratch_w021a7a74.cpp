#include <globaldefs.h>

extern "C" int func_ov017_0218b5b0(void);

struct HeadNode02046b24;
int GetHeadNodeIdOrMinusOne(struct HeadNode02046b24** obj);

struct TailNode020469b4;
struct TailList020469b4;
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);

void InitObj_021a7adc(char* obj);
void CopyRelayoutFields_021a7c28(unsigned char* dst, unsigned char* src);

struct Struct021a7a74 {
	unsigned char pad0[0x64];
	int field64;
};

// USA: func_ov017_021a7a74
ARM void QueueRelayoutNode_021a7a74(int unused0, unsigned char* srcData) {
	int h = func_ov017_0218b5b0();
	HeadNode02046b24** headTable = *(HeadNode02046b24***)((char*)h + 0x3000 + 0x6fc);
	int id = GetHeadNodeIdOrMinusOne(headTable);
	if (id == 0x1a) {
		Struct021a7a74* s = *(Struct021a7a74**)((char*)h + 0x3000 + 0xb0c);
		if (s->field64 != 0) return;
	}
	TailNode020469b4* node = *(TailNode020469b4**)((char*)h + 0x3000 + 0xb98);
	InitObj_021a7adc((char*)node);
	CopyRelayoutFields_021a7c28((unsigned char*)node, srcData);
	AppendNodeToTail((TailList020469b4*)headTable, node);
}
