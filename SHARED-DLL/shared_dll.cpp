#include "shared_dll.h"

// 多进程共享数据
#pragma data_seg("shared")
int SharedNum = 0;
#pragma data_seg()
#pragma comment(linker, "/SECTION:shared,RWS")

EXPORT int __stdcall sharedAdd(int num1, int num2) {
	return num1 + num2 + SharedNum;
}

EXPORT int __stdcall sharedAddCallBack(sharedCallBackFun fun, int num1, int num2) {
	return fun(num1, num2) + SharedNum;
}

EXPORT void __stdcall updateSharedNum() {
	++SharedNum;
}
