#pragma once
#include <string>
#include "ArxTools.h"

namespace GL
{

	//转换函数
	// out : 返回转化
	// pIn : 输入
	// tocode : 目标编码(查看win_iconv.c文件)
	// fromcode : 源编码(查看win_iconv.c文件)
	ARXTOOLS_API bool Convert(std::string &out, const char *pIn, const char *tocode, const char *fromcode);
	ARXTOOLS_API std::string Convert(const char *pIn, const char *tocode, const char *fromcode);

	//unicode 转为 ansi
	ARXTOOLS_API bool WideByte2Ansi(std::string &out, const wchar_t* wstrcode, const char* locale = "");
	ARXTOOLS_API std::string WideByte2Ansi(const wchar_t* wstrcode, const char* locale = "");

	//ansi 转 Unicode
	ARXTOOLS_API bool Ansi2WideByte(std::wstring& out, const char* strAnsi, const char* locale = "");
	ARXTOOLS_API std::wstring Ansi2WideByte(const char* strAnsi, const char* locale = "");

	//Unicode 转 UTF8
	ARXTOOLS_API bool WideByte2Utf8(std::string& out, const wchar_t* src, const char* locale = "");
	ARXTOOLS_API std::string WideByte2Utf8(const wchar_t* src, const char* locale = "");

	//UTF8 转 Unicode
	ARXTOOLS_API bool Utf82WideByte(std::wstring& out, const char* src, const char* locale = "");
	ARXTOOLS_API std::wstring Utf82WideByte(const char* src, const char* locale = "");

	//ansi转UTF8
	ARXTOOLS_API bool Ansi2Utf8(std::string& out, const char* strAnsi, const char* locale = "");
	ARXTOOLS_API std::string Ansi2Utf8(const char* strAnsi, const char* locale = "");

	//UTF8转ansi
	ARXTOOLS_API bool Utf82Ansi(std::string& out, const char* strUtf8, const char* locale = "");
	ARXTOOLS_API std::string Utf82Ansi(const char* strUtf8, const char* locale = "");

	ARXTOOLS_API std::string StrToHex(const char* strData);
	ARXTOOLS_API std::string HexToStr(const char* strHex);
	ARXTOOLS_API std::wstring StrToHex(const wchar_t* strData);
	ARXTOOLS_API std::wstring HexToStr(const wchar_t* strHex);

}
