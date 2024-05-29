#pragma once
#include <string>
#include "iconv.h"

#define USE_WINDOWS 1

namespace GL
{
	//ת������
	// out : ����ת��
	// pIn : ����
	// tocode : Ŀ�����(�鿴win_iconv.c�ļ�)
	// fromcode : Դ����(�鿴win_iconv.c�ļ�)
	bool Convert(std::string& out, const std::string& in, const char* tocode, const char* fromcode);

	//unicode תΪ ansi
	bool Unicode2Ansi(std::string &out, const std::wstring& in, const char* locale = "");

	//ansi ת Unicode
	bool Ansi2Unicode(std::wstring& out, const std::string& in, const char* locale = "");

	//Unicode ת UTF8
	bool Unicode2Utf8(std::string& out, const std::wstring& in, const char* locale = "");

	//UTF8 ת Unicode
	bool Utf82Unicode(std::wstring& out, const std::string& in, const char* locale = "");

	//ansiתUTF8
	bool Ansi2Utf8(std::string& out, const std::string& in, const char* locale = "");

	//UTF8תansi
	bool Utf82Ansi(std::string& out, const std::string& in, const char* locale = "");

	bool StrToHex(std::string& out, const std::string& in);

	bool HexToStr(std::string& out, const std::string& in);

	bool StrToHex(std::wstring& out, const std::wstring& in);

	bool HexToStr(std::wstring& out, const std::wstring& in);

}
