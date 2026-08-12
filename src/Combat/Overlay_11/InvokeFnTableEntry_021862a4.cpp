#include <globaldefs.h>

struct TaggedNumber02184c30 {
    int type;
    union { int i; float f; } value;
};
extern int GetTaggedValueAsInt_02184c30(struct TaggedNumber02184c30* v);

typedef int (*Fn5_021862a4)(int, int, int, int, int);
typedef int (*Fn4_021862a4)(int, int, int, int);

struct FnRow_021862a4 { void* fn[4]; };
struct FnTable_021862a4 { struct FnRow_021862a4 row[2]; };
extern struct FnTable_021862a4 data_ov011_02188914;

// USA: func_ov011_021862a4  (semantic: InvokeFnTableEntry_021862a4)
extern "C" ARM int func_ov011_021862a4(struct TaggedNumber02184c30* args) {
    int mode = GetTaggedValueAsInt_02184c30(&args[0]);
    int idx = GetTaggedValueAsInt_02184c30(&args[1]);
    int a = GetTaggedValueAsInt_02184c30(&args[2]);
    int b = GetTaggedValueAsInt_02184c30(&args[3]);
    int c = GetTaggedValueAsInt_02184c30(&args[4]);
    int d = GetTaggedValueAsInt_02184c30(&args[5]);
    int e = GetTaggedValueAsInt_02184c30(&args[6]);

    struct FnTable_021862a4 table = data_ov011_02188914;
    void* fn = table.row[mode].fn[idx];
    if (idx < 2) {
        ((Fn5_021862a4)fn)(a, b, c, d, e);
    } else {
        ((Fn4_021862a4)fn)(a, b, c, d);
    }
    return 1;
}
