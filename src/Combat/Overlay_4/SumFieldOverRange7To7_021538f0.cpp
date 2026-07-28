#include <globaldefs.h>

struct Entry6_021538b4 { char pad[5]; unsigned char field5; };
Entry6_021538b4* FindEntryByShort_021538b4(Entry6_021538b4* base, int key);
extern Entry6_021538b4* data_ov004_021707c0;

// USA: func_ov004_021538f0  (semantic: SumFieldOverRange7To7_021538f0)
extern "C" ARM short func_ov004_021538f0(void) {
    short total = 0;
    for (short i = 7; i <= 7; i++) {
        Entry6_021538b4* entry = FindEntryByShort_021538b4(data_ov004_021707c0, i);
        if (entry) total = total + entry->field5;
    }
    return total;
}
