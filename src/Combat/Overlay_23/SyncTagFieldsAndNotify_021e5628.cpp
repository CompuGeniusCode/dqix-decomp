#include <globaldefs.h>

unsigned short (*GetVariantShortTable02109928(void))[2];
int CallWithAddr4000330(int a);
extern "C" void func_02034d20(void* obj);
struct S1a0;
void ShiftField0x1cInto0x20(struct S1a0* obj, unsigned int v);
extern "C" void func_02035a2c(void* obj, int flag);
struct Struct0207ea38;
int CopyStringToField0207ea38(struct Struct0207ea38* obj, char* str);
int GetBitsAndDispatch020b6c3c(void* a0, void* a1, void* a2, unsigned int a3);
struct S02035d44;
int SyncFieldA2AndDispatch02035d44(struct S02035d44* obj, int arg);
void WriteVectorsAndProcess02035fe0(void* obj);
void BuildAndIssueRotationMatrixY(int angle);
extern "C" void func_02035554(void* obj, void* child);

extern char data_ov023_021fdcef;
extern char data_ov023_021fdcf4;
extern char data_ov023_021fdcfa;
extern char data_ov023_021fdd00;
extern char data_ov023_021fdd08;
extern char data_ov023_021fdd10;

struct TagObj021e5628 {
    unsigned char pad0[0x2];
    short field2;
    unsigned char pad1[0x8 - 0x4];
    void* field8;
    unsigned char pad2[0x1c - 0xc];
    unsigned int field1c;
    unsigned char pad3[0xc10 - 0x20];
    unsigned char field_c10;
    unsigned char pad4[0xc12 - 0xc11];
    unsigned char field_c12;
    unsigned char pad5[0xc14 - 0xc13];
    unsigned char field_c14;
};

struct CtxObj021e5628 {
    void* field0;
    void* field4;
};

struct FlagObjA8_021e5628 {
    unsigned char pad[0xa8];
    int flagA8 : 1;
};

// USA: func_ov023_021e5628  (semantic: SyncTagFieldsAndNotify_021e5628)
extern "C" ARM void func_ov023_021e5628(TagObj021e5628* obj, CtxObj021e5628* ctx) {
    if (obj->field_c12 != 0) return;
    if (obj->field_c14 == 0) return;

    unsigned short (*table)[2] = GetVariantShortTable02109928();
    if (table == 0) return;

    unsigned short v = *(unsigned short*)((char*)table + 0x128);
    unsigned short buf[8] = {v, v, v, v, v, v, v, v};
    CallWithAddr4000330((int)buf);

    if (obj->field2 >= 0) {
        func_02034d20(obj);
        unsigned int f1c = obj->field1c;
        ShiftField0x1cInto0x20((struct S1a0*)((char*)obj + 0x408), f1c);
        ShiftField0x1cInto0x20((struct S1a0*)((char*)obj + 0xac), f1c);
        ShiftField0x1cInto0x20((struct S1a0*)((char*)obj + 0x35c), f1c);
    }
    if (obj->field2 <= -1) return;

    func_02035a2c(obj, 1);

    struct Struct0207ea38* strObj;
    void* p = *(void**)((char*)obj + 8);
    if (p == 0) goto skipMessages;
    if (!((struct FlagObjA8_021e5628*)p)->flagA8) p = 0;
    if (p == 0) goto skipMessages;

    {
        strObj = (struct Struct0207ea38*)obj->field8;
        if (strObj == 0) return;

        int r = CopyStringToField0207ea38(strObj, &data_ov023_021fdcef);
        if (r > -1) {
            GetBitsAndDispatch020b6c3c(p, 0, 0, r);
            if (ctx != 0 && ctx->field4 != 0) {
                SyncFieldA2AndDispatch02035d44((struct S02035d44*)ctx->field4, 0);
            }
            WriteVectorsAndProcess02035fe0((char*)obj + 0x158);
            SyncFieldA2AndDispatch02035d44((struct S02035d44*)((char*)obj + 0x158), 0);
            SyncFieldA2AndDispatch02035d44((struct S02035d44*)((char*)obj + 0x204), 0);
            SyncFieldA2AndDispatch02035d44((struct S02035d44*)((char*)obj + 0x4b4), 0);

            if (obj->field_c10 != 0) {
                int r2 = CopyStringToField0207ea38(strObj, &data_ov023_021fdcf4);
                if (r2 > -1 && *(short*)((char*)obj + 0x562) > -1) {
                    GetBitsAndDispatch020b6c3c(p, 0, 0, r2);
                    SyncFieldA2AndDispatch02035d44((struct S02035d44*)((char*)obj + 0x560), 0);
                }
                int r3 = CopyStringToField0207ea38(strObj, &data_ov023_021fdcfa);
                if (r3 > -1 && *(short*)((char*)obj + 0x562) > -1) {
                    GetBitsAndDispatch020b6c3c(p, 0, 0, r3);
                    BuildAndIssueRotationMatrixY(0x3244);
                    SyncFieldA2AndDispatch02035d44((struct S02035d44*)((char*)obj + 0x560), 0);
                }
            } else {
                int r4 = CopyStringToField0207ea38(strObj, &data_ov023_021fdd00);
                if (r4 > -1 && *(short*)((char*)obj + 0x562) > -1) {
                    GetBitsAndDispatch020b6c3c(p, 0, 0, r4);
                    SyncFieldA2AndDispatch02035d44((struct S02035d44*)((char*)obj + 0x560), 0);
                }
            }

            int r5 = CopyStringToField0207ea38(strObj, &data_ov023_021fdd08);
            if (r5 > -1 && *(short*)((char*)obj + 0x60e) > -1) {
                GetBitsAndDispatch020b6c3c(p, 0, 0, r5);
                SyncFieldA2AndDispatch02035d44((struct S02035d44*)((char*)obj + 0x60c), 0);
            }

            if (ctx != 0 && ctx->field0 != 0) {
                int r6 = CopyStringToField0207ea38(strObj, &data_ov023_021fdd10);
                if (r6 > -1) {
                    GetBitsAndDispatch020b6c3c(p, 0, 0, r6);
                    SyncFieldA2AndDispatch02035d44((struct S02035d44*)ctx->field0, 0);
                }
            }
        }
    }

skipMessages:
    func_02035554(obj, (char*)obj + 0x408);
    func_02035a2c((char*)obj + 0x408, 1);
    func_02035554(obj, (char*)obj + 0xac);
    func_02035a2c((char*)obj + 0xac, 1);
    func_02035554(obj, (char*)obj + 0x35c);
    func_02035a2c((char*)obj + 0x35c, 1);
}
