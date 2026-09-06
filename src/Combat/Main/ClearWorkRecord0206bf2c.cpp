#include <globaldefs.h>
#include "std_library_functions.h"

struct Rec0206bf2c {
    unsigned char field0;      // 0x00
    unsigned char pad1;        // 0x01
    unsigned short field2;     // 0x02
    unsigned char field4;      // 0x04
    unsigned char field5;      // 0x05
    unsigned char pad6;        // 0x06
    unsigned char field7;      // 0x07
    unsigned char field8;      // 0x08
    unsigned char pad9;        // 0x09
    unsigned char flagsA_b0 : 2;  // 0x0a
    unsigned char flagsA_b1 : 1;
    unsigned char flagsA_b2 : 3;
    unsigned char flagsA_b3 : 1;
    unsigned char flagsA_b4 : 1;
    unsigned char fieldB;      // 0x0b
    unsigned int fieldC;       // 0x0c
    unsigned char pad10[0xc];  // 0x10-0x1c
    unsigned short field1c;    // 0x1c
    unsigned char field1e;     // 0x1e
    unsigned char field1f;     // 0x1f
    unsigned short field20;    // 0x20
    unsigned char pad22[2];    // 0x22-0x24
    unsigned char pad24[0x10]; // 0x24-0x34
    unsigned int field34;      // 0x34
    unsigned int field38;      // 0x38
    unsigned int field3c;      // 0x3c
    unsigned int field40;      // 0x40
    unsigned short field44;    // 0x44
    unsigned short field46;    // 0x46
    unsigned char pad48[0xc];  // 0x48-0x54
    unsigned int field54;      // 0x54
    unsigned int field58;      // 0x58
    unsigned int field5c;      // 0x5c
    unsigned int field60;      // 0x60
    unsigned int field64;      // 0x64
    unsigned int field68;      // 0x68
    unsigned int field6c;      // 0x6c
    unsigned int field70;      // 0x70
};

// USA: func_0206bf2c
ARM void ClearWorkRecord0206bf2c(struct Rec0206bf2c* obj) {
    obj->field0 = 0;
    obj->field2 = 0;
    obj->field4 = 0;
    obj->field5 = 0;
    obj->field7 = 0;
    obj->field8 = 0;
    obj->flagsA_b0 = 0;
    obj->flagsA_b1 = 0;
    obj->flagsA_b2 = 0;
    obj->flagsA_b3 = 0;
    obj->flagsA_b4 = 0;
    obj->fieldC = 0;
    obj->fieldB = 0;
    obj->field1e = 0;
    memset(obj->pad24, 0, sizeof(obj->pad24));
    obj->field1f = 0;
    obj->field34 = 0;
    obj->field38 = 0x7a;
    unsigned int tmp46 = obj->field38 - 0x7b;
    obj->field3c = 0;
    obj->field40 = 0;
    obj->field44 = 0;
    obj->field46 = (unsigned short)tmp46;
    memset(obj->pad10, 0, sizeof(obj->pad10));
    obj->field1c = 0;
    memset(obj->pad48, 0, sizeof(obj->pad48));
    obj->field54 = 0;
    obj->field58 = 0;
    obj->field5c = 0;
    obj->field60 = 0;
    obj->field20 = 0;
    obj->field64 = 0;
    obj->field68 = 0;
    obj->field6c = 0;
    obj->field70 = 0;
}
