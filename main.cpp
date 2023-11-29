#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

int byteCount(char ch) {
    if ((ch & 0x80) == 0) { return 1; } // 单字节字符
    else if ((ch & 0xE0) == 0xC0) { return 2; } // 双字节字符
    else if ((ch & 0xF0) == 0xE0) { return 3; } // 三字节字符
    else if ((ch & 0xF8) == 0xF0) { return 4; } // 四字节字符
    else { return -1; } // 不支持的编码
}

std::vector<std::string> StdString2Utf8Char(const std::string& str) {
    size_t i = 0;
    std::vector<std::string> utf8CharVec;
    while (i < str.size()) {
        int len = byteCount(str[i]);
        if (len < 0 || i + len > str.size()) {
            throw std::invalid_argument("internal::StdString2Utf8Char 函数: 不支持的 UTF-8 编码!");
        }
        utf8CharVec.emplace_back(str.substr(i, len));
        i += len;
    }
    return utf8CharVec;
}

int main() {
    string src_str = "bal北太"; // clion 设置为 UTF-8
//    cout << src_str;
    int len = MultiByteToWideChar(CP_UTF8, 0, src_str.c_str(), -1, nullptr, 0); // 获取字符数
//    auto vecStr = StdString2Utf8Char(src_str); // 用vector<string> 存储 UTF-8 string 中的字符(vec.size() 即 UTF-8 string 中的字符数)
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
