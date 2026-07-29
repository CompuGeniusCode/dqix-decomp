#include <globaldefs.h>

struct HalfwordRecord02052884;
void RecordValueChangeAt0x20(struct HalfwordRecord02052884* rec, short value, short kind);
extern "C" float GetSomeFloat(void);

// USA: func_ov001_ffffffff
ARM void ShortCallTest_ffffffff(struct HalfwordRecord02052884* d, short kind) {
    float f = GetSomeFloat();
    int ival = (int)(4096.0f * f);
    RecordValueChangeAt0x20(d, ival, kind);
}
