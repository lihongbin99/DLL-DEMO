#pragma once

#ifdef __cplusplus
#define EXPORT extern "C" __declspec (dllexport)
#else
#define EXPORT __declspec (dllexport)
#endif

// ���溯��
EXPORT int __stdcall sharedAdd(int num1, int num2);

// �ص�����
typedef int(__stdcall* sharedCallBackFun)(int num1, int num2);
EXPORT int __stdcall sharedAddCallBack(sharedCallBackFun fun, int num1, int num2);

EXPORT void __stdcall updateSharedNum();