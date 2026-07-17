#include <globaldefs.h>

struct ResetStruct;
int ResetFieldsReturnTrue(struct ResetStruct* s);

struct StreamState;
struct StreamHeader;
int InitBufferReader(struct StreamState* s, struct StreamHeader* buffer, int length);

struct Struct02030774;
int RunLoopIfValid02030774(struct Struct02030774* p);

extern "C" void func_0203066c(struct ResetStruct*, int*);

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
	ResetFieldsReturnTrue((struct ResetStruct*)local);
	func_0203066c((struct ResetStruct*)local, &data_ov017_021d7900);
	InitBufferReader((struct StreamState*)local, param1, param2);
	RunLoopIfValid02030774((struct Struct02030774*)local);
}
