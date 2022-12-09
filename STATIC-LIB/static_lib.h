#pragma once

int staticAdd(int num1, int num2);

typedef int(*staticCallBackFun)(int num1, int num2);
int staticAddCallBack(staticCallBackFun fun, int num1, int num2);
