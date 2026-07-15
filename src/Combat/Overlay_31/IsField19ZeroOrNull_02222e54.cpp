#include <globaldefs.h>

struct EntityStruct02222e54 { unsigned char pad[0x19]; unsigned char field19; };
extern EntityStruct02222e54* data_ov031_02250ba8;

// USA: func_ov031_02222e54
ARM int IsField19ZeroOrNull_02222e54(void) {
    EntityStruct02222e54 *p = data_ov031_02250ba8;
    if (p == NULL) {
        return 1;
    }
    return p->field19 == 0;
}
