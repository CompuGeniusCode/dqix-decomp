#include <globaldefs.h>

struct ResetStruct;
int ResetFieldsReturnTrue(struct ResetStruct* s);

struct StreamState;
struct StreamHeader;
int InitBufferReader(struct StreamState* s, struct StreamHeader* buffer, int length);

struct Struct02030774;
int RunLoopIfValid02030774(struct Struct02030774* p);

extern "C" void func_0203066c(struct ResetStruct*, int*);

struct Data_021ffa34 {
	short field0;
	int field4;
	int field8;
	void* fieldC;
};
extern struct Data_021ffa34 data_ov023_021ffa34;
extern int data_ov023_021fdc78;

// USA: func_ov023_021e133c
ARM void InitScriptAndRun_021e133c(void* a, void* b, int c, int d, int e, short f) {
	char local[0x430];
	if (c != 0 && d != 0) {
		data_ov023_021ffa34.fieldC = a;
		data_ov023_021ffa34.field8 = (int)b;
		data_ov023_021ffa34.field4 = e;
		data_ov023_021ffa34.field0 = f;
		ResetFieldsReturnTrue((struct ResetStruct*)local);
		func_0203066c((struct ResetStruct*)local, &data_ov023_021fdc78);
		InitBufferReader((struct StreamState*)local, (struct StreamHeader*)c, d);
		RunLoopIfValid02030774((struct Struct02030774*)local);
	}
}
