#include <iostream>
#include <shared_dll.h>
#include <static_lib.h>

using namespace std;

int __stdcall MyCallBackDll(int num1, int num2) {
    return num1 + num2;
}

int MyCallBackLib(int num1, int num2) {
    return num1 + num2;
}

int main() {
    char buf[1]{ 0 };

    // 常规调用 Shared DLL 函数
    cout << sharedAdd(13000, 520) << endl;

    // 测试 Shared DLL 的多进程共享数据
    // cout << "请输入任意字符串继续程序" << endl;
    // cin.read(buf, sizeof(buf));
    // updateSharedNum();

    // 回调 Shared DLL 函数
    cout << sharedAddCallBack(MyCallBackDll, 13000, 520) << endl;

    // 常规调用 Static Lib 函数
    cout << staticAdd(13000, 520) << endl;

    // 回调 Static Lib 函数
    cout << staticAddCallBack(MyCallBackLib, 13000, 520) << endl;

    cout << "请输入任意字符串退出程序" << endl;
    cin.read(buf, sizeof(buf));
}
