#pragma once
#include <string>
#include "iconv.h"

#define USE_WINDOWS 1

namespace GL
{
	//转换函数
	// out : 返回转化
	// pIn : 输入
	// tocode : 目标编码(查看win_iconv.c文件)
	// fromcode : 源编码(查看win_iconv.c文件)
	bool ConvertCharset(std::string& out, const std::string& in, const char* tocode, const char* fromcode);

	//unicode 转为 ansi
	bool Unicode2Ansi(std::string &out, const std::wstring& in, const char* locale = "");

	//ansi 转 Unicode
	bool Ansi2Unicode(std::wstring& out, const std::string& in, const char* locale = "");

	//Unicode 转 UTF8
	bool Unicode2Utf8(std::string& out, const std::wstring& in, const char* locale = "");

	//UTF8 转 Unicode
	bool Utf82Unicode(std::wstring& out, const std::string& in, const char* locale = "");

	//ansi转UTF8
	bool Ansi2Utf8(std::string& out, const std::string& in, const char* locale = "");

	//UTF8转ansi
	bool Utf82Ansi(std::string& out, const std::string& in, const char* locale = "");

	//字符串转hex字符串
	bool Str2Hex(std::string& out, const std::string& in);
	bool Str2Hex(std::wstring& out, const std::wstring& in);

	//hex字符串转字符串
	bool Hex2Str(std::string& out, const std::string& in);
	bool Hex2Str(std::wstring& out, const std::wstring& in);

}
