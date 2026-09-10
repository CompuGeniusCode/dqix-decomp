#include <globaldefs.h>
extern "C" int func_0206ef40(unsigned char*);

struct BinarySearchByComparatorStruct;
typedef int (*BinarySearchByComparatorFn)(void* elem);
extern "C" extern void* func_0206f470(struct BinarySearchByComparatorStruct* base, int key, BinarySearchByComparatorFn comp);

// Binary-searches a monster record table for the record whose id -- the halfword at +0x8 -- matches
// `id`, with func_0206ef40 as the key extractor. The 0x1C stride is structural: func_0206f0f8
// returns count * 0x1C over the same 12-bit count field the search reads. Only two producers of that
// shape exist: the mon_data_<LG>.nat entry of data/prm/mon_data.gp2 through LoadMonsterDataTable
// and data/prm/fld_mondata.bin through func_0206f230, the only other user of the comparator. The
// table is a parameter, so another of the same shape could be passed; none is known.
extern "C" ARM void* FindMonsterRecordById(struct BinarySearchByComparatorStruct* base, int key) {
    return func_0206f470(base, key, (BinarySearchByComparatorFn)func_0206ef40);
}
