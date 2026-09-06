#include <globaldefs.h>

struct ElementObj0203f0fc;
ARM int FindNamedEntryInElement0203f0fc(struct ElementObj0203f0fc* obj, const char* name);
extern "C" int func_0203f138(struct ElementObj0203f0fc* obj, int entry);

struct Obj0203f1e4 {
    char pad[0x28];
    short field28;
};

// USA: func_0203f1e4
ARM void SelectNamedEntry0203f1e4(struct Obj0203f1e4* obj, const char* name) {
    if (obj->field28 < 0) {
        return;
    }
    func_0203f138((struct ElementObj0203f0fc*)obj,
                  FindNamedEntryInElement0203f0fc((struct ElementObj0203f0fc*)obj, name));
}
