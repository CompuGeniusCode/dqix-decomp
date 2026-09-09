#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct Node02187a58 {
    short id;
    unsigned short pad : 2;
    unsigned short level : 7;
    unsigned short kind : 6;
    unsigned short high : 1;
    int field4;
    struct Node02187a58* next;
};

struct List0208e024;
struct List0208e06c;
struct TableA68;

extern "C" ARM struct Node02187a58* _Z25FindNthNodeByKind0208e024P12List0208e024ii(struct List0208e024* list, int kind, int index);
extern "C" ARM struct Node02187a58* _Z20FindNodeById0208e06cP12List0208e06ci(struct List0208e06c* list, int id);
ARM void* FindEntryByKey(struct TableA68* table, int key);
extern "C" ARM int _Z20GetTableByte020dd11cjj(unsigned int a, unsigned int b);
int GetFieldAt0x150(unsigned char* obj);
extern "C" void* _Z26GetGlobalField0x1c020421a0v(void);

extern "C" void* memset(void* dst, int value, int n);
extern "C" void __clear(void* buf, int n);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern "C" float _ffltu(unsigned int v);
extern "C" int func_020420e8(void* p, int flag);
extern "C" void func_0204f41c(void* ctx, short x, short y, void* str, int size,
                              unsigned char palette, short* outA, short* outB, int flag);
extern "C" void func_020749ac(void* arr, int lo, int hi, int mode);
extern "C" void func_02046608(void* g, int a, int b, void* dst, int cap, int e, int f);
extern "C" void func_020e4864(void* src, void* dst, int a, int b, int c, int d);

extern signed char data_ov013_02187dc8[];
extern char data_ov013_02187ec3;

struct Entry02187a58 {
    int id;
    float weight;
};

// USA: func_ov013_02187a58
extern "C" ARM void func_ov013_02187a58(void* self, void* ctx) {
    unsigned char* obj = (unsigned char*)self;
    if (ctx == 0) {
        return;
    }

    struct CombatantStruct* combatant =
        GetCombatantWithFlag0x100(GetBattleStruct(), *(signed char*)(obj + 0x67));
    if (combatant == 0) {
        return;
    }

    int palette;
    unsigned char* field = (unsigned char*)GetFieldAt0x150((unsigned char*)combatant);
    if (field == 0) {
        return;
    }

    int kind = _Z20GetTableByte020dd11cjj(*(unsigned int*)(field + 0x950) & 0xff, obj[0x68]);
    int cap = (field + kind)[0x464];
    int y = 0x1e;
    void* label = FindEntryByKey((struct TableA68*)(obj + 4), kind);

    short outA;
    short outB;
    char text[0x20];
    struct Entry02187a58 entries[10];
    char rawBuf[0x100];
    char nameBuf[0x100];

    func_0204f41c(ctx, (short)((0x100 - func_020420e8(label, 0)) >> 1), 0xc, label,
                  0xa, 0xf, &outA, &outB, 0);

    memset(entries, 0, 0x50);
    for (unsigned char i = 0; i < 10; i++) {
        struct Entry02187a58* e = &entries[i];
        struct Node02187a58* n = _Z25FindNthNodeByKind0208e024P12List0208e024ii((struct List0208e024*)(obj + 0xc), kind, i);
        if (n != 0) {
            e->id = n->id;
            e->weight = _ffltu(n->level);
        }
    }
    func_020749ac(entries, 0, 9, 0);

    struct Node02187a58* first =
        _Z20FindNodeById0208e06cP12List0208e06ci((struct List0208e06c*)(obj + 0xc), (short)entries[0].id);
    int k = 0;
    while (data_ov013_02187dc8[k] >= 0) {
        if (data_ov013_02187dc8[k] == first->kind) {
            obj[0x6a] = (unsigned char)k;
            break;
        }
        k++;
    }

    for (unsigned char j = 0; j < 10; j++) {
        palette = 3;
        struct Node02187a58* n =
            _Z20FindNodeById0208e06cP12List0208e06ci((struct List0208e06c*)(obj + 0xc), (short)entries[j].id);
        if (n != 0) {
            int level = n->level;
            if (cap >= level) {
                palette = 0xf;
            }
            __clear(text, 0x20);
            sprintf(text, &data_ov013_02187ec3, level);
            func_0204f41c(ctx, (short)(0x22 - func_020420e8(text, 0)), (short)y, text,
                          0xa, (unsigned char)palette, &outA, &outB, 0);

            __clear(rawBuf, 0x100);
            __clear(nameBuf, 0x100);
            func_02046608(_Z26GetGlobalField0x1c020421a0v(), 0xa, n->field4, rawBuf, 0x100, 0, 0);
            func_020e4864(rawBuf, nameBuf, 1, 0, 0, 0);

            if (n->high != 0 && *(signed char*)(obj + 0x6a) >= 0) {
                (*(short**)(obj + 0x50))[j] = (short)(func_020420e8(nameBuf, 0) + 0x2e);
                (*(short**)(obj + 0x54))[j] = (short)(y - 2);
                if (palette == 0xf) {
                    (*(unsigned char**)(obj + 0x58))[j] = 1;
                }
            }

            func_0204f41c(ctx, 0x2e, (short)y, nameBuf, 0xa, (unsigned char)palette, &outA, &outB, 0);
            y += 0xf;
        }
    }
}
