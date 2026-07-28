#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

int GetData02104304Field4(void);
extern "C" int func_0202fdd0(int a, int b);
struct List0202fe68;
int LookupListValueByKey(struct List0202fe68* obj, int key);
struct List0202fec8;
void GetListEntryValues0202fec8(struct List0202fec8* obj, int id, int* out1, int* out2);
extern "C" void func_020301c8(void* obj, int key);

struct ResetStruct;
int ResetFieldsReturnTrue(struct ResetStruct* s);
struct StreamState;
struct StreamHeader;
int InitBufferReader(struct StreamState* s, struct StreamHeader* buffer, int length);
struct Struct02030774;
int RunLoopIfValid02030774(struct Struct02030774* p);
extern "C" void func_0203066c(struct ResetStruct*, int*);

extern int data_ov031_02291e04;
extern int data_ov031_0224c8dc;

// USA: func_ov031_02243714  (semantic: AllocateAndRunScript_02243714)
extern "C" ARM int func_ov031_02243714(char* ctx) {
	char local[0x430];
	int out1, out2;
	int list = GetData02104304Field4();
	if (!func_0202fdd0(list, *(int*)(ctx + 0x39c)) || !func_0202fdd0(list, *(int*)(ctx + 0x3a0))) {
		return 3;
	}
	if (LookupListValueByKey((struct List0202fe68*)list, *(int*)(ctx + 0x39c)) != 2) {
		func_020301c8((void*)list, *(int*)(ctx + 0x39c));
		return 2;
	}
	if (LookupListValueByKey((struct List0202fe68*)list, *(int*)(ctx + 0x3a0)) != 2) {
		func_020301c8((void*)list, *(int*)(ctx + 0x3a0));
		return 2;
	}
	GetListEntryValues0202fec8((struct List0202fec8*)list, *(int*)(ctx + 0x39c), &out1, &out2);
	*(int*)(ctx + 0x388) = out1;
	*(int*)(ctx + 0x38c) = out2;
	void* allocated = ((SafeAllocator*)ctx)->Allocate(0x38);
	*(void**)((char*)&data_ov031_02291e04 + 0x28) = allocated;
	if (allocated == 0) return 2;
	memset(allocated, 0, 0x38);
	GetListEntryValues0202fec8((struct List0202fec8*)list, *(int*)(ctx + 0x3a0), &out1, &out2);
	ResetFieldsReturnTrue((struct ResetStruct*)local);
	func_0203066c((struct ResetStruct*)local, &data_ov031_0224c8dc);
	InitBufferReader((struct StreamState*)local, (struct StreamHeader*)out1, out2);
	RunLoopIfValid02030774((struct Struct02030774*)local);
	return 1;
}
