#pragma once

#ifdef __cplusplus
#define EXPORT extern "C" __declspec (dllexport)
#else
#define EXPORT __declspec (dllexport)
#endif

// 常规函数
EXPORT int __stdcall sharedAdd(int num1, int num2);

// 回调函数
typedef int(__stdcall* sharedCallBackFun)(int num1, int num2);
EXPORT int __stdcall sharedAddCallBack(sharedCallBackFun fun, int num1, int num2);

EXPORT void __stdcall updateSharedNum();