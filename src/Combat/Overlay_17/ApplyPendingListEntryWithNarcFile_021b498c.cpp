#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "Filesystem/FileIO.h"

int GetData02104304Field4();
extern "C" int func_0202fdd0(int list, int key);
struct List0202fe68;
int LookupListValueByKey(struct List0202fe68* obj, int key);
struct List0202fec8;
void GetListEntryValues0202fec8(struct List0202fec8* obj, int id, int* out1, int* out2);
struct InitStruct;
ARM void InitializeStruct(struct InitStruct* s);
struct Struct0202811c;
void ProcessAndCheckPairs02028104(struct Struct0202811c* s, int b, int c, int d);
extern "C" void func_02028214(void* a, int b);
extern "C" void func_020301c8(int list, int key);
int CallFunc0202fa38ZeroPad(int a, int b, int c);

extern char data_ov017_021d7b4f;
extern char data_ov017_021d7b3a;

struct Obj021b498c {
    char pad0[8];
    void* sub;
    int key;
    unsigned char field10;
    char pad1[3];
    int field14;
};

// USA: func_ov017_021b498c  (semantic: ApplyPendingListEntryWithNarcFile_021b498c)
extern "C" ARM void func_ov017_021b498c(struct Obj021b498c* obj) {
    GetBattleStruct();
    int list = GetData02104304Field4();
    if (!func_0202fdd0(list, obj->key)) {
        return;
    }

    if (LookupListValueByKey((struct List0202fe68*)list, obj->key) == 2) {
        int out2, out1;
        GetListEntryValues0202fec8((struct List0202fec8*)list, obj->key, &out1, &out2);
        if (out1 != 0) {
            unsigned int fileSize;
            const void* filePtr;
            FindFilesInNarcBySubstring((const void*)out1, &data_ov017_021d7b4f, &filePtr, &fileSize, 1);
            if (filePtr != 0) {
                char* sub = (char*)obj->sub;
                InitializeStruct((struct InitStruct*)(sub + 0x18));
                ProcessAndCheckPairs02028104((struct Struct0202811c*)(sub + 0x18), *(int*)((char*)obj->sub + 0x10), (int)filePtr, (int)fileSize);
                func_02028214(sub + 0x18, *(int*)((char*)obj->sub + 0x10));
                sub[0xc] = 1;
            }
        }
    }

    func_020301c8(list, obj->key);
    obj->key = -1;
    obj->key = CallFunc0202fa38ZeroPad(list, (int)&data_ov017_021d7b3a, 0);
    obj->field10 = 3;
}
