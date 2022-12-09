#include "static_lib.h"

int staticAdd(int num1, int num2) {
	return num1 + num2;
}

int staticAddCallBack(staticCallBackFun fun, int num1, int num2) {
	return fun(num1, num2);
}
