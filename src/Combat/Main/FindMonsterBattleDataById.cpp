#include <globaldefs.h>

struct Struct020709c8;
extern "C" extern int func_020709c8(struct Struct020709c8* p);

struct Element02070e60;
struct Container02070e60;
typedef int (*CompareCallback02070e60)(struct Element02070e60*);
extern "C" extern struct Element02070e60* func_02070e60(struct Container02070e60* container, int key, CompareCallback02070e60 compare);

// Binary search of the monster battle-data table by monster id. LoadMonsterBattleDataTable is the
// only thing that builds this list, and data/prm/mon_btldata.nat is 57820 bytes: a four-byte header
// whose low twelve bits say 438, then 438 records of 0x84. The low fifteen bits of each record's
// first halfword, which is the key func_020709c8 hands back, run 1, 2, 3 ... 900 strictly ascending,
// so the search is sound. 19 of the 25 callers are in ov000 battle, the rest in ov015, ov023, ov024.
extern "C" ARM struct Element02070e60* FindMonsterBattleDataById(struct Container02070e60* container, int key) {
    return func_02070e60(container, key, (CompareCallback02070e60)func_020709c8);
}
