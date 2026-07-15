#include <globaldefs.h>

struct EntityStruct02225c38 { unsigned char pad[0x66]; unsigned char field66; };
extern EntityStruct02225c38* data_ov031_02250c00;

// USA: func_ov031_02225c38
ARM void SetField66_02225c38(int v) {
    data_ov031_02250c00->field66 = (unsigned char)v;
}
