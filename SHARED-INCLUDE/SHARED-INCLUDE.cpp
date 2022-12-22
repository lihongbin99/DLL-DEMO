#include <iostream>

// #include <nlohmann/json.hpp>

// #include <openssl/md5.h>

// #include <sqlite3.h>

#include <curl/curl.h>

using namespace std;

wstring CharToWchar_t(string from, UINT characterSet);
string Wchar_tToChar(wstring from, UINT characterSet);
string CharacterSetEncodeing(string from, UINT fromCharacterSet, UINT toCharacterSet);

size_t curlWrite(void* ptr, size_t size, size_t nmemb, void* stream) {
    if (stream == NULL || ptr == NULL || size == 0) {
        return 0;
    }
    size_t realsize = size * nmemb;
    ((std::string*)stream)->append((const char*)ptr, realsize);
    return realsize;
}

int main() {
    // json库 测试
    // nlohmann::json json = {
    //     {"name", "z3"},
    //     {"age", 18},
    // };
    // cout << json << endl;

    // OpenSSL库 测试
    // const unsigned char md5TestMessage[] = "Hello World!";
    // unsigned char md5Result[16];
    // MD5_CTX md5CTX;
    // MD5_Init(&md5CTX);
    // MD5_Update(&md5CTX, md5TestMessage, sizeof(md5TestMessage) - 1);
    // MD5_Final(md5Result, &md5CTX);
    // for (int i = 0; i < sizeof(md5Result); ++i) {
    //     printf("%02X ", md5Result[i]);
    // }
    // cout << endl;

    // sqlcipher库 测试
    // int sqlite3Result;
    // sqlite3* db;
    // const unsigned char password[] = "passowrd";
    // sqlite3_open("sqlite3.db", &db);
    // sqlite3Result = sqlite3_key(db, password, sizeof(password));
    // if (sqlite3Result != SQLITE_OK) {
    //     cout << "sqlite3_key: " << sqlite3Result << endl;
    //     return 0;
    // }
    // cout << "sqlite3_key success" << endl;
    // sqlite3Result = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS test_table(name varchar(20));", NULL, NULL, NULL);
    // if (sqlite3Result != SQLITE_OK) {
    //     cout << "sqlite3_exec: " << sqlite3Result << endl;
    //     return 0;
    // }
    // cout << "create success" << endl;

    // curl库 测试
    CURL* curl = curl_easy_init();
    // 请求路径
    curl_easy_setopt(curl, CURLOPT_URL, "https://www.lhb13520.com");
    // 请求头
    curl_slist* http_headers = NULL;
    http_headers = curl_slist_append(http_headers, "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/108.0.0.0 Safari/537.36 Edg/108.0.1462.46");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, http_headers);
    // 响应体
    string response;
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curlWrite);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)&response);
    curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    // 打印内容
    string responseGBK = CharacterSetEncodeing(response, CP_UTF8, CP_ACP);
    cout << responseGBK << endl;
}

wstring CharToWchar_t(string from, UINT characterSet) {
    int WideCharLen = MultiByteToWideChar(
        characterSet, 0,
        from.c_str(), -1,
        NULL, 0);
    wchar_t* WideChar = new wchar_t[WideCharLen] { 0 };
    MultiByteToWideChar(
        characterSet, 0,
        from.c_str(), -1,
        WideChar, WideCharLen);

    wstring result(WideChar);

    if (WideChar) delete[] WideChar;

    return result;
}

string Wchar_tToChar(wstring from, UINT characterSet) {
    int MultiByteLen = WideCharToMultiByte(
        characterSet, 0,
        from.c_str(), -1,
        NULL, NULL,
        NULL, NULL);
    char* MultiByte = new char[MultiByteLen] { 0 };
    WideCharToMultiByte(
        characterSet, 0,
        from.c_str(), -1,
        MultiByte, MultiByteLen,
        NULL, NULL);

    string result(MultiByte);

    if (MultiByte) delete[] MultiByte;

    return result;
}

string CharacterSetEncodeing(string from, UINT fromCharacterSet, UINT toCharacterSet) {
    return Wchar_tToChar(CharToWchar_t(from, fromCharacterSet), toCharacterSet);
}
