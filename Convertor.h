#pragma once
#include <string>
#include "iconv.h"

namespace GL
{
	//ת������
	// out : ����ת��
	// pIn : ����
	// tocode : Ŀ�����(�鿴win_iconv.c�ļ�)
	// fromcode : Դ����(�鿴win_iconv.c�ļ�)
	// exact : �Ƿ�ȷת����false=����ת�����ַ���������
	bool ConvertCharset(std::string& out, const std::string& in, 
		const char* fromcode, const char* tocode, bool exact = true);

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

	//�ַ���תhex�ַ���
	bool Str2Hex(std::string& out, const std::string& in);
	bool Str2Hex(std::wstring& out, const std::wstring& in);

	//hex�ַ���ת�ַ���
	bool Hex2Str(std::string& out, const std::string& in);
	bool Hex2Str(std::wstring& out, const std::wstring& in);

}
