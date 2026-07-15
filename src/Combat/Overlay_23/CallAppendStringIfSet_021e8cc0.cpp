#include <globaldefs.h>

int AppendString02042058(char* dst, const char* src);

struct Container021e8cc0 { char pad1[0x5d8]; char* field5d8; char pad2[0x5fc - 0x5dc]; char* field5fc; };

// USA: func_ov023_021e8cc0
ARM void CallAppendStringIfSet_021e8cc0(struct Container021e8cc0* obj) {
	if (obj->field5fc == 0) return;
	AppendString02042058(obj->field5d8, obj->field5fc);
}
