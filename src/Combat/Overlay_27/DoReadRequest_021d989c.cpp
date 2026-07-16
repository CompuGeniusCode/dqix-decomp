#include <globaldefs.h>
#include "Filesystem/NitroVM.h"
#include "Filesystem/LowNitroHandle.h"
#include "Filesystem/FileAccessor.h"

struct ReadReq_021d989c {
    unsigned int start;
    unsigned int len;
    void* dst;
    int status;
};

struct HandleInfo_021d989c {
    char pad0[0x10];
    char sig[4];
    int sigLen;
    unsigned int fallbackHandle;
};

struct Base_021d989c {
    char pad0[0x10];
    ReadReq_021d989c* req;
    HandleInfo_021d989c* handleInfo;
};

#pragma optimize_for_size off

// USA: func_ov027_021d989c
ARM void DoReadRequest_021d989c(Base_021d989c* p)
{
    HandleInfo_021d989c* hi = p->handleInfo;
    ReadReq_021d989c* req = p->req;

    NitroHandle* handle = NitroHandle_FindBySignature(hi->sig, hi->sigLen);
    if (handle == NULL)
        handle = (NitroHandle*)hi->fallbackHandle;

    NitroVM vm;
    NitroVM_Initialize(&vm);

    unsigned int start = req->start;
    unsigned int end = start + req->len;
    if (NitroVM_PrepareRead(&vm, handle, start, end, 0xFFFFFFFF))
    {
        int n = NitroVM_ReadSync(&vm, req->dst, req->len);
        if (req->len == (unsigned int)n)
            req->status = 2;
        NitroVM_FinishRead(&vm);
    }

    if (req->status != 2)
    {
        req->start = 0;
        req->status = 2;
    }
}
