#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "std_library_functions.h"

extern "C" void* func_ov000_02160f20(void* obj);
extern "C" void* GetActionDataTables(void);
extern "C" void* FindActdtEntryById(char* p, int key);
extern "C" void func_ov025_021e88d8(void* obj);
extern "C" void func_ov025_021e8a40(char* obj, int a, int b);
extern "C" void func_ov025_021e8a4c(char* obj, int v);
extern "C" void func_ov025_021e8d20(void* obj, int v);
extern "C" void func_ov025_021db8d8(void* obj);
extern "C" void* func_ov000_02169a58(char* node, int value);

struct StreamHeader;
extern "C" ARM void func_ov000_0216d1c4(int arg0, struct StreamHeader* buffer, int length, int* out);

extern int data_ov025_021ef404;
extern char strSpNumBact[];
extern char data_ov025_021ef974[];

struct ActionRecord {
    char unknown0[4];
    unsigned int key : 12;
    char unknown8[0x18 - 0x8];
    unsigned int : 5;
    unsigned int classField : 7;
};

// Finishes the pending act-archive read and runs the action script for the move the slot names. The
// slot's first halfword is looked up in the pair of tables at data_02108e10, and the record's 12-bit
// id becomes "sp%03d.bact" inside the loaded narc; data/skill/actspl.nsarc, actskl.nsarc and
// actetc.nsarc hold 84, 160 and 67 such members between them, sp009.bact through sp920.bact, and
// data/bin/defaultaction.bact is what says .bact is an action script. Whether the script ran or not,
// a state word at +0xeac outside 3, 2 and 6 then sends it to the registered action nodes at +0x5724,
// with 0x158 standing in for the id when the record's seven-bit class field is 0xc; if that search
// misses too the state word goes to 5. Nothing null-checks the record on that path. Once the task
// has completed it is always freed and data_ov025_021ef404 reset to -1. What "sp" abbreviates is
// not established.
extern "C" ARM void RunBattleActionScript(void* battleWork) {
    char* obj = (char*)battleWork;
    void* actionSlot = func_ov000_02160f20(obj);
    BackgroundLoader* loader = BackgroundLoader::GetInstance();

    if (loader->GetTaskStatus(data_ov025_021ef404) == 0) {
        return;
    }

    void* archiveData = 0;
    unsigned int archiveLength = 0;
    loader->GetLoadedFileByID(data_ov025_021ef404, &archiveData, &archiveLength);

    void* actionTable = GetActionDataTables();
    struct ActionRecord* actionRecord = (struct ActionRecord*)FindActdtEntryById((char*)actionTable, *(short*)actionSlot);

    if (archiveData != 0 && archiveLength != 0 && actionRecord != 0) {
        char bactName[0x50];
        sprintf(bactName, strSpNumBact, actionRecord->key);

        const void* scriptData = 0;
        unsigned int scriptLength = 0;
        if (GetFileInNarc(archiveData, bactName, &scriptData, &scriptLength, 0)) {
            int scriptResult = 0;
            func_ov000_0216d1c4((int)(obj + 0x30), (struct StreamHeader*)scriptData, scriptLength, &scriptResult);
            if (scriptResult != 0) {
                func_ov025_021e88d8(obj + 0x2a8);
                func_ov025_021e8a40(obj + 0x2a8, (int)(obj + 0x30), (int)(obj + 0x14c));
                func_ov025_021e8a4c(obj + 0x2a8, *(int*)(obj + 0x29c));
                func_ov025_021e8d20(obj + 0x2a8, scriptResult);
                func_ov025_021db8d8(obj);
            }
        }
    }

    int actionState = *(int*)(obj + 0xeac);
    if (actionState != 3 && actionState != 2 && actionState != 6) {
        int classField = actionRecord->classField;
        int lookupActionId = actionRecord->key;
        if (classField == 0xc) {
            lookupActionId = 0x158;
        }
        char* node = *(char**)(obj + 0x5724);
        int actionNode = (int)func_ov000_02169a58(node, lookupActionId);
        if (actionNode != 0) {
            func_ov025_021e88d8(obj + 0x2a8);
            func_ov025_021e8a40(obj + 0x2a8, (int)(obj + 0x30), (int)(obj + 0x14c));
            func_ov025_021e8a4c(obj + 0x2a8, *(int*)(obj + 0x29c));
            func_ov025_021e8d20(obj + 0x2a8, actionNode);
            func_ov025_021db8d8(obj);
        } else {
            *(int*)(obj + 0xeac) = 5;
            *(int*)(data_ov025_021ef974 + 0x10) = 0;
            *(int*)(data_ov025_021ef974 + 8) = 0;
        }
    }

    loader->RemoveTask(data_ov025_021ef404);
    data_ov025_021ef404 = -1;
}
