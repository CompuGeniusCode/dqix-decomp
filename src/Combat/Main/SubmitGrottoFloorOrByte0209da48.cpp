#include <globaldefs.h>
#include "Grotto/Main/ActiveGrottoClass.h"

extern "C" void* func_02012fe4(void);
int IsValueInRange0201b5d8(int x);
extern "C" int func_ov017_021d6134(void*, int);

// USA: func_0209da48
ARM int SubmitGrottoFloorOrByte0209da48(void* self) {
    int r4 = *(signed char*)((char*)func_02012fe4() + 0x2300 + 0xba);
    ActiveGrottoClass* grotto = (ActiveGrottoClass*)((char*)func_02012fe4() + 0x23ec);
    if (grotto == NULL) {
        r4 = 0;
        goto end;
    }
    if (IsValueInRange0201b5d8(*(unsigned short*)func_02012fe4()) == 0) {
        goto end;
    }
    r4 = grotto->GetFloorCount() + 1;
end:
    func_ov017_021d6134(self, r4);
    return 1;
}
