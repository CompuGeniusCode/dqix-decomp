#include <globaldefs.h>

struct TailList020469b4;
struct TailNode020469b4;
struct Obj021ac2ec;
struct SetField8Struct_021aca14;

void InitState30_021ac2ec(Obj021ac2ec* p);
void SetField8_021aca14(SetField8Struct_021aca14* obj, int val);
void AppendNodeToTail(TailList020469b4* list, TailNode020469b4* node);

// USA: func_ov017_0219931c
ARM void InitAndAppendState30_0219931c(char* obj) {
	if (*(unsigned char*)(obj + 0x3000 + 0x6b8) == 0) {
		return;
	}
	char* base = obj + 0x3000;
	Obj021ac2ec* node = *(Obj021ac2ec**)(base + 0xb18);
	InitState30_021ac2ec(node);
	SetField8_021aca14(*(SetField8Struct_021aca14**)(obj + 0x3000 + 0xb18), *(int*)(obj + 0x3000 + 0x6bc));
	AppendNodeToTail(*(TailList020469b4**)(obj + 0x3000 + 0x6fc), *(TailNode020469b4**)(obj + 0x3000 + 0xb18));
}
