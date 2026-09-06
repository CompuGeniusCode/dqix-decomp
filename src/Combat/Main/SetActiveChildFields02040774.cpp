#include <globaldefs.h>

struct Fields020407b4;
void SetFields0x44(struct Fields020407b4* dst, int a, int b, int c);

struct FieldsA02040774 {
    char pad4[4];
    int a;
    int b;
    int c;
};
struct Node02040774 {
    char pad[0x14];
    struct FieldsA02040774* f14;
    void* f18;
    void* f1c;
};

// USA: func_02040774
ARM void SetActiveChildFields02040774(struct Node02040774* obj, int a, int b, int c) {
    struct FieldsA02040774* p = obj->f14;
    if (p != NULL) {
        p->a = a;
        p->b = b;
        p->c = c;
        return;
    }
    if (obj->f18 != NULL) {
        SetFields0x44((struct Fields020407b4*)obj->f18, a, b, c);
        return;
    }
    if (obj->f1c != NULL) {
        SetFields0x44((struct Fields020407b4*)obj->f1c, a, b, c);
    }
}
