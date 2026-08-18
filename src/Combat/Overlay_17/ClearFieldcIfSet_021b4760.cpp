#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


struct Obj021b4760 {
	char pad[0xc];
	int fieldc;
};

// USA: func_ov017_021b4760
ARM void ClearFieldcIfSet_021b4760(struct Obj021b4760* self) {
	int x = (int)BackgroundLoader::GetInstance();
	if (self->fieldc <= -1) {
		return;
	}
	((BackgroundLoader*)(x))->RemoveTask((int)(self->fieldc));
	self->fieldc = -1;
}
