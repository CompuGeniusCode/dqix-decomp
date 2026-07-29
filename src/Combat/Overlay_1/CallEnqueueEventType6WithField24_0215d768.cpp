#include <globaldefs.h>

struct Data24_0215d768 { char pad[0x24]; void* field24; };
extern struct Data24_0215d768 data_ov001_02165880;
void* EnqueueEventType6_02159044(void* ctx);

// USA: func_ov001_0215d768  (semantic: CallEnqueueEventType6WithField24_0215d768)
extern "C" ARM int func_ov001_0215d768(void) {
	EnqueueEventType6_02159044(data_ov001_02165880.field24);
	return 1;
}
