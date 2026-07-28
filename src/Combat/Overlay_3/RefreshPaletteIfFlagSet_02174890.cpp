#include <globaldefs.h>

struct Cont0207fd88;
void CallFunc0204b088OverList0x2c(struct Cont0207fd88* obj);
struct SelfState020e2834;
void SetYesNoButtonPalette020e2834(struct SelfState020e2834* self);

// USA: func_ov003_02174890  (semantic: RefreshPaletteIfFlagSet_02174890)
extern "C" ARM void func_ov003_02174890(char* obj) {
    if (*(unsigned char*)(obj + 0x1000 + 0x3e) == 0) return;
    struct Cont0207fd88* p = *(struct Cont0207fd88**)(obj + 0x89c);
    CallFunc0204b088OverList0x2c(p);
    struct SelfState020e2834* self = *(struct SelfState020e2834**)obj;
    if (self == NULL) return;
    SetYesNoButtonPalette020e2834(self);
}
