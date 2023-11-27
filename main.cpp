#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

int main() {
    string src_str = "bal北太";
//    cout << src_str;
    int len = MultiByteToWideChar(CP_UTF8, 0, src_str.c_str(), -1, nullptr, 0); // 获取字符数
    auto wszGBK = new wchar_t[len + 1];
    memset(wszGBK, 0, len * 2 + 2);
    MultiByteToWideChar(CP_UTF8, 0, src_str.c_str(), -1, wszGBK, len); // 填充 wszGBK

    int len1 = WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, nullptr, 0, nullptr, nullptr); // 返回 将 wszGBK 转换为 CP_ACP 编码后的字节数

    char *szGBK = new char[len1 + 1];
    memset(szGBK, 0, len1 + 1);
    WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, szGBK, len1, nullptr, nullptr); // 填充 szGBK
    string str(szGBK);
//    cout << str;
    return 0;
}
