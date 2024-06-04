#include "Convertor.h"
#include <Windows.h>
#include <clocale>

namespace GL
{

	bool ConvertCharset(std::string& out, const std::string& in,
		const char* fromcode, const char* tocode, bool exact/* = true*/)
	{
		bool bRet = false;

		if (&out == &in)
		{//输出和输入是同一块内存
			std::string sIn = in;
			iconv_t cd = iconv_open(tocode, fromcode);
			if (cd != (iconv_t)-1)
			{
				size_t srcLen = sIn.size();
				size_t destLen = srcLen * 4;
				const char* pInTemp = sIn.c_str();
				out.resize(destLen + 1, '\0');
				char* pOut = &out[0];
				size_t convLen = iconv(cd, &pInTemp, &srcLen, &pOut, &destLen, exact);
				if (convLen != -1)
				{
					out.resize(convLen);
					bRet = true;
				}
				else
				{
					printf("errno=%d (%s)\n", errno, strerror(errno));
				}
				iconv_close(cd);
			}
		}
		else
		{//输出和输入不是同一块内存
			iconv_t cd = iconv_open(tocode, fromcode);
			if (cd != (iconv_t)-1)
			{
				size_t srcLen = in.size();
				size_t destLen = srcLen * 4;
				out.resize(destLen + 1, '\0');
				char* pOut = &out[0];
				const char* pInx = &in[0];//必须的
				size_t convLen = iconv(cd, &pInx, &srcLen, &pOut, &destLen, exact);
				if (convLen != -1)
				{
					out.resize(convLen);
					bRet = true;
				}
				else
				{
					printf("errno=%d (%s)\n", errno, strerror(errno));
				}
				iconv_close(cd);
			}
		}

		return bRet;
	}

	//unicode 转为 ansi
	bool Unicode2Ansi(std::string& out, const std::wstring& in, const char* locale/* = ""*/)
	{
		setlocale(LC_ALL, locale);

		int ansiSize = WideCharToMultiByte(CP_OEMCP, 0, in.c_str(), in.size(), NULL, 0, NULL, NULL);
		if (ansiSize <= 0)
		{
			setlocale(LC_ALL, "");
			return false;
		}

		out.resize(ansiSize);
		int convresult = WideCharToMultiByte(CP_OEMCP, 0, in.c_str(), in.size(), &out[0], ansiSize, NULL, NULL);
		if (convresult <= 0)
		{
			setlocale(LC_ALL, "");
			return false;
		}

		setlocale(LC_ALL, "");
		return true;
	}

	//ansi 转 Unicode
	bool Ansi2Unicode(std::wstring& out, const std::string& in, const char* locale/* = ""*/)
	{
		setlocale(LC_ALL, locale);

		int widesize = MultiByteToWideChar(CP_ACP, 0, in.c_str(), in.size(), NULL, 0);
		if (widesize <= 0)
		{
			//::GetLastError();
			setlocale(LC_ALL, "");
			return false;
		}

		out.resize(widesize);
		int convresult = MultiByteToWideChar(CP_ACP, 0, in.c_str(), in.size(), &out[0], widesize);
		if (convresult <= 0)
		{
			//::GetLastError();
			setlocale(LC_ALL, "");
			return false;
		}

		setlocale(LC_ALL, "");
		return true;
	}

	//Unicode 转 UTF8
	bool Unicode2Utf8(std::string& out, const std::wstring& in, const char* locale/* = ""*/)
	{
		setlocale(LC_ALL, locale);

		int len = WideCharToMultiByte(CP_UTF8, 0, &in[0], in.size(), NULL, 0, NULL, NULL);
		if (len <= 0)
		{
			//::GetLastError();
			setlocale(LC_ALL, "");
			return false;
		}

		out.resize(len);
		len = WideCharToMultiByte(CP_UTF8, 0, &in[0], in.size(), &out[0], len, NULL, NULL);
		if (len <= 0)
		{
			//::GetLastError();
			setlocale(LC_ALL, "");
			return false;
		}

		setlocale(LC_ALL, "");
		return true;
	}

	//UTF8 转 Unicode
	bool Utf82Unicode(std::wstring& out, const std::string& in, const char* locale/* = ""*/)
	{
		setlocale(LC_ALL, locale);

		int len = MultiByteToWideChar(CP_UTF8, 0, &in[0], in.size(), NULL, 0);
		if (len <= 0)
		{
			//::GetLastError();
			setlocale(LC_ALL, "");
			return false;
		}

		out.resize(len);
		len = MultiByteToWideChar(CP_UTF8, 0, &in[0], in.size(), &out[0], out.size());
		if (len <= 0)
		{
			//::GetLastError();
			setlocale(LC_ALL, "");
			return false;
		}

		setlocale(LC_ALL, "");
		return true;
	}

	bool Ansi2Utf8(std::string& out, const std::string& in, const char* locale/* = ""*/)
	{
		std::wstring ws;
		if (!Ansi2Unicode(ws, in, locale))
			return false;
		return Unicode2Utf8(out, ws.c_str(), locale);
	}

	bool Utf82Ansi(std::string& out, const std::string& in, const char* locale/* = ""*/)
	{
		std::wstring ws;
		if (!Utf82Unicode(ws, in, locale))
			return false;
		return Unicode2Ansi(out, ws.c_str(), locale);
	}

	bool Str2Hex(std::string& out, const std::string& in)
	{
		//初始化
		int iLenth = strlen(in.c_str());
		int nNewSize = (iLenth + 1) * 2;
		char* cArrTemp = new char[nNewSize + 1];
		memset(cArrTemp, 0, nNewSize + 1);

		for (int i = 0; i < iLenth; i++)
		{
			if (in[i] == 0)
			{
				break;
			}
			sprintf(cArrTemp + (i * 2), "%02X", (unsigned char)in[i]);
		}

		out = cArrTemp;
		delete[] cArrTemp;

		return true;
	}

	bool Hex2Str(std::string& out, const std::string& in)
	{
		int iLenth = strlen(in.c_str());
		char* cArrTemp = new char[iLenth + 1];
		memset(cArrTemp, 0, iLenth + 1);

		int iOcx;
		for (int i = 0; i < iLenth / 2; i++)
		{
			if (1 != sscanf(&in[i * 2], "%2x", (unsigned int*)&iOcx))
				break;
			cArrTemp[i] = (char)iOcx;
		}

		out = cArrTemp;
		delete[] cArrTemp;

		return true;
	}

	bool Str2Hex(std::wstring& out, const std::wstring& in)
	{
		std::string ansi;
		if (!Unicode2Ansi(ansi, in))
			return false;
		if (!Str2Hex(ansi, ansi))
			return false;
		return Ansi2Unicode(out, ansi);
	}

	bool Hex2Str(std::wstring& out, const std::wstring& in)
	{
		std::string ansi;
		if (!Unicode2Ansi(ansi, in))
			return false;
		if (!Hex2Str(ansi, ansi))
			return false;
		return Ansi2Unicode(out, ansi);
	}

}