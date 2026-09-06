#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

struct Variant02030b0c;
int GetIntFromVariant02030b0c(struct Variant02030b0c* p);
struct Struct02030b7c;
void* GetField4IfField0Zero(struct Struct02030b7c* s);

struct Elem_021536fc { int value; char* str; };
struct DataStruct_021536fc {
	int idx;
	SafeAllocator* allocator;
	Elem_021536fc** arrPtr;
};
extern struct DataStruct_021536fc data_ov001_02165800;

// USA: func_ov001_021536fc
ARM int StoreVariantIntAndString_021536fc(char* self) {
	int val = GetIntFromVariant02030b0c((struct Variant02030b0c*)self);
	(*data_ov001_02165800.arrPtr)[data_ov001_02165800.idx].value = val;
	char* str = (char*)GetField4IfField0Zero((struct Struct02030b7c*)(self + 0x8));
	if (str == 0) return 0;
	int len = strlen(str);
	char* buf = (char*)data_ov001_02165800.allocator->Allocate(len + 1);
	(*data_ov001_02165800.arrPtr)[data_ov001_02165800.idx].str = buf;
	{
		int idx2 = data_ov001_02165800.idx;
		Elem_021536fc* arr2 = *data_ov001_02165800.arrPtr;
		buf = arr2[idx2].str;
	}
	if (buf == 0) return 0;
	strcpy(buf, str);
	data_ov001_02165800.idx++;
	return 1;
}
