#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern int strDataPrmActmsgGp2;
extern int strActmsgLgNat;

struct Struct0216fd0c {
	int field0;
};

// Asks the background loader for actmsg_<LG>.nat out of data/prm/actmsg.gp2 and keeps the request
// id. <LG> is the language code, so the one archive carries every language on the cart. This lives
// in the battle overlay, and one of its two ov025 callers (func_ov025_021db038) runs it last of
// three setup calls on the same object, so actmsg is presumably the battle action message table,
// but that reading rests on the archive name alone.
extern "C" ARM void QueueLoadActMsgTable(struct Struct0216fd0c* obj) {
	obj->field0 = ((BackgroundLoader*)((int)BackgroundLoader::GetInstance()))->QueueLoadFileInGP2((const char*)((int)&strDataPrmActmsgGp2), (const char*)((int)&strActmsgLgNat), (SafeAllocator*)(0));
}
