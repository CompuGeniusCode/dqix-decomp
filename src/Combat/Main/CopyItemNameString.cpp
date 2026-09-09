#include <globaldefs.h>

extern char strItemnameLgNat;
extern char strDataPrmItemnameGp2;
extern "C" void func_020e54bc(int, void*, int, int, unsigned char, int);

// USA: func_020dcf7c
// The file paths in this function's literal pool are "data/prm/itemname.gp2" and
// "itemname_<LG>.nat".
extern "C" ARM void CopyItemNameString(int count, void* buf) {
    if (count <= 0) return;
    if (buf == NULL) return;
    func_020e54bc((int)buf, &strItemnameLgNat, count, 0, 1, (int)&strDataPrmItemnameGp2);
}
