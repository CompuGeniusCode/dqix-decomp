#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" int func_02010220(struct BattleStruct*);

struct Selector02034e38 {
    unsigned int sel : 1;
};

struct Self02034e38 {
    char pad0[0x10];
    Selector02034e38* field_10;   // 0x10
};

typedef void (Self02034e38::*PMF02034e38)();
extern PMF02034e38 data_020efae8[];

// USA: func_02034e38
ARM void DispatchSelectedMember02034e38(Self02034e38* self) {
    func_02010220(GetBattleStruct());
    if (self->field_10 == NULL) return;
    (self->*data_020efae8[self->field_10->sel])();
}
