#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"


struct List0202fec8;


// USA: func_ov012_02185ea8
ARM void ClearAndCopyEntry_02185ea8(char *self) {
	int id = (int)BackgroundLoader::GetInstance();
	int field = *(int *)(self + 0x1384);
	int out1;
	((BackgroundLoader*)((List0202fec8 *)id))->GetLoadedFileByID((int)(field), (void**)(&out1), (unsigned int*)((int*)(self + 0x13b8)));
	memcpy(*(void**)(self + 0x13b4), (void*)out1, *(int*)(self + 0x13b8));
	((BackgroundLoader*)(id))->RemoveTask((int)(*(int *)(self + 0x1384)));
	*(int *)(self + 0x1384) = -1;
}
