#include <globaldefs.h>

int DispatchNodeIfType7_02156e2c(void* a, int key);
void* GetEntryFor_021570a4(void* obj, int index);
extern "C" void* func_ov004_02156f38(void*, int);
extern "C" void* func_ov004_02156f6c(void*, int);
extern "C" int func_ov023_021f809c(void*, void*);

struct Struct021707d8_02159384 { char pad[8]; unsigned char* ptr; };
extern Struct021707d8_02159384 data_ov004_021707d8;

// Real virtual call: vtable index 0xe0/4 = 56.
class VObj02159384 {
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
	virtual void NotifyCount(int n);
};

// USA: func_ov004_02159384
ARM int NotifyCountedEvents_02159384(void* self) {
	int b = DispatchNodeIfType7_02156e2c(self, 0x5b);
	if (b < 0) return 0;
	void* entry = GetEntryFor_021570a4(self, (unsigned char)b);
	if (!entry) return 0;

	VObj02159384* node1 = (VObj02159384*)func_ov004_02156f38(self, 0x25a);
	if (node1) {
		node1->NotifyCount(data_ov004_021707d8.ptr[0x11]);
	}

	VObj02159384* node2 = (VObj02159384*)func_ov004_02156f38(self, 0x2bd);
	if (node2) {
		unsigned int field4 = *(unsigned int*)((char*)entry + 4);
		node2->NotifyCount(data_ov004_021707d8.ptr[0x11] * (field4 >> 7));
	}

	void* node3 = func_ov004_02156f6c(self, 0x19);
	if (node3) func_ov023_021f809c(node3, self);

	void* node4 = func_ov004_02156f6c(self, 0x1a);
	if (node4) func_ov023_021f809c(node4, self);

	return 0;
}
