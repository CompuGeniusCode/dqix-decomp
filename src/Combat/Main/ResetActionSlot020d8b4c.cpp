#include <globaldefs.h>

struct Action020cca80;

struct ActionSlot020d8b4c {
    unsigned short state;
    unsigned short field2;
    unsigned char action[0x48];
};

int SetupEffectType8(Action020cca80*);
unsigned int ClearAndInit020d84f8(void*, unsigned int);

// USA: func_020d8b4c
ARM int ResetActionSlot020d8b4c(ActionSlot020d8b4c* slot) {
    int result = 0;
    if (slot->state == 1) {
        result = SetupEffectType8((Action020cca80*)slot->action) != 0;
    }
    ClearAndInit020d84f8(slot, 0x4c);
    slot->state = 0;
    slot->field2 = 0;
    return result;
}
