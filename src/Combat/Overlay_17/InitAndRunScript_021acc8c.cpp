#include <globaldefs.h>

struct ResetStruct;
extern "C" int _ZN6Script10InitializeEv(struct ResetStruct* s);

struct StreamState;
struct StreamHeader;
extern "C" int _ZN6Script4LoadEPKvj(struct StreamState* s, struct StreamHeader* buffer, int length);

struct Struct02030774;
extern "C" int _ZN6Script7ExecuteEv(struct Struct02030774* p);

extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(struct ResetStruct*, int*);

struct Data_ov017_021d83cc {
	void* field0;
	int field4;
};
extern struct Data_ov017_021d83cc data_ov017_021d83cc;
extern int data_ov017_021d7900;

// USA: func_ov017_021acc8c
ARM void InitAndRunScript_021acc8c(void* param0, struct StreamHeader* param1, int param2, int param3) {
	char local[0x430];
	data_ov017_021d83cc.field0 = param0;
	data_ov017_021d83cc.field4 = param3;
	_ZN6Script10InitializeEv((struct ResetStruct*)local);
	_ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE((struct ResetStruct*)local, &data_ov017_021d7900);
	_ZN6Script4LoadEPKvj((struct StreamState*)local, param1, param2);
	_ZN6Script7ExecuteEv((struct Struct02030774*)local);
}
