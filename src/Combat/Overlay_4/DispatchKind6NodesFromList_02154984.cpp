#include <globaldefs.h>

extern "C" void func_ov004_0215482c(void*);
void* GetNodeIfKind6_02153944(void*, int);
extern "C" int func_ov023_021f809c(void*, void*);
struct Kinds3_02154984 { int v[3]; };
struct KindsWrap_02154984 { Kinds3_02154984 mid; };
extern KindsWrap_02154984 data_ov004_0216fa80;

// USA: func_ov004_02154984  (semantic: DispatchKind6NodesFromList_02154984)
extern "C" ARM int func_ov004_02154984(void* a) {
    func_ov004_0215482c(a);
    KindsWrap_02154984 local;
    local.mid = data_ov004_0216fa80.mid;
    int* kinds = local.mid.v;
    int i = 0;
    while (kinds[i] >= 0) {
        void* node = GetNodeIfKind6_02153944(a, kinds[i]);
        if (node) {
            func_ov023_021f809c(node, a);
            i++;
        }
    }
    return 0;
}
