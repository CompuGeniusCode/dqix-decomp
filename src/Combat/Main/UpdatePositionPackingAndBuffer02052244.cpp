#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void* func_ov017_0218b5b0(void);
void PackFieldsAt0x94(unsigned int a, unsigned int b, int flag);
void PackTriple10BitField020b38b0(int idx, int x, int y, int z);
void StoreWordWithIndexTag(int index, unsigned int value);
int CallWithAddr4000330(int a);

struct Obj02052244 {
    struct BattleStruct* battleStruct;
    int x1;
    int y1;
    int z1;
    int x2;
    int y2;
    int z2;
    unsigned short s1c;
    unsigned short s1e;
    char pad2[0x46 - 0x20];
    unsigned short u46;
    unsigned short s48;
};

// USA: func_02052244
ARM void UpdatePositionPackingAndBuffer02052244(struct Obj02052244* obj) {
    struct BattleStruct* battleStruct = obj->battleStruct;
    if (battleStruct == NULL) return;
    func_ov017_0218b5b0();
    PackFieldsAt0x94(obj->u46, 0, 0);
    if (*(int*)((char*)battleStruct + 0x410) != 2) return;
    PackTriple10BitField020b38b0(0, (short)obj->x1, (short)obj->y1, (short)obj->z1);
    StoreWordWithIndexTag(0, obj->s1c);
    PackTriple10BitField020b38b0(1, (short)obj->x2, (short)obj->y2, (short)obj->z2);
    StoreWordWithIndexTag(1, obj->s1e);
    unsigned short buf[8];
    buf[0] = obj->s48;
    buf[1] = obj->s48;
    buf[2] = obj->s48;
    buf[3] = obj->s48;
    buf[4] = obj->s48;
    buf[5] = obj->s48;
    buf[6] = obj->s48;
    buf[7] = obj->s48;
    CallWithAddr4000330((int)buf);
}
