#include <globaldefs.h>
extern "C" int GetStringByTextId(struct Container020e0310 *, int);

extern int data_02153694;

// Looks an id up in the standard string table and returns the string. data_02153694 is slot 0 of the
// two-slot table LoadStandardStringAndArticleTables loads, slot 0 from strstd_<LG>.nat in data/bin/strstd.gp2 and slot 1
// from article_<LG>.nat in data/prm/article.gp2; the sibling func_020e51e4 is the same call against
// slot 1 at data_021536ac. It goes through the thunk GetStringByTextId to the binary search in
// func_020e0440, and func_02026470 hands the result to sprintf as the %s of "%s%d", so the value held
// in the table is a char*.
extern "C" ARM int GetStrstdString(int value) {
    return GetStringByTextId((struct Container020e0310 *)(&data_02153694), (int)(value));
}
