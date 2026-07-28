#include <globaldefs.h>

extern "C" int func_ov004_0215513c(void* obj, short* pB, short* pC, short* pD);
extern "C" void func_ov023_021f645c(void* a, int b, unsigned short c, int d);
extern unsigned char* data_ov004_021707c4;
extern unsigned short data_ov004_0216fadc[];
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
void ClearElements_021e1518(void* obj);
void BuildChain_021e1814(void* a, void* b, int c, int d, int e);
void BuildChain_021e1870(void* a, void* b, int c, int d, int e);

class VObj02155a3c {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void v56(); virtual void v57(); virtual void v58();
    virtual void* MethodEc();
};

// USA: func_ov004_02155a3c
extern "C" ARM int func_ov004_02155a3c(void* self) {
    short b, c, d;
    func_ov004_0215513c(self, &b, &c, &d);

    unsigned short mode = 7;
    if (b != 0 && c >= 0) {
        if (c == 8) mode = 5;
        if (c == 9) mode = 6;
    }

    func_ov023_021f645c(self, 0x34, mode, 0xf);

    unsigned char idx = data_ov004_021707c4[0x10];
    unsigned short val = data_ov004_0216fadc[idx];
    func_ov023_021f645c(self, 0x35, val, 0xf);

    int flag = (data_ov004_021707c4[0x10] == 0) ? 1 : 0;

    VObj02155a3c* node = (VObj02155a3c*)func_ov023_021f6880(func_ov011_021849c8(self), 0x39);
    if (node) {
        short d3, d2, d1;
        func_ov004_0215513c(self, &d1, &d2, &d3);

        void* result = node->MethodEc();
        if (result) {
            ClearElements_021e1518(result);
            if (flag) {
                BuildChain_021e1814(result, (void*)(int)d1, d2, d3, 1);
            } else {
                BuildChain_021e1870(result, (void*)(int)d1, d2, d3, 1);
            }
        }
    }
    return 0;
}
