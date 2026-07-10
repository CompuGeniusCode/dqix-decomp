#include <globaldefs.h>

struct S_cc758;
void InitStructField0x10To0xE(struct S_cc758*);
int TryOpenPath020cca38(void*, void*);
struct Action020cca80;
int SetupEffectType8(struct Action020cca80*);

struct Inner020afd0c { char pad[0x64]; int f64; };
struct Buf020afd0c { int words[0x12]; };

// USA: func_020afd0c
ARM int OpenPathAndGetImageOffset(void* path) {
    struct Buf020afd0c buf;
    int result = 0;
    InitStructField0x10To0xE((struct S_cc758*)&buf);
    if (TryOpenPath020cca38(&buf, path)) {
        result = ((struct Inner020afd0c*)buf.words[2])->f64 + buf.words[9];
        SetupEffectType8((struct Action020cca80*)&buf);
    }
    return result;
}
