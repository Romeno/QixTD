#include "stdafx.h"
#include "StringUtils.h"

// ������ �������� �� string � wstring 40+ https://stackoverflow.com/questions/2573834/c-convert-string-or-char-to-wstring-or-wchar-t 
// ��� �� 150+ ������ �� utf-8 � utf-16 � �������
// ���� MultiByteToWideChar ��� ��� �� ��������  https://msdn.microsoft.com/en-us/library/windows/desktop/dd319072(v=vs.85).aspx
// ��� ���������� iconv, ������� ���������� ��� ����� ��� ������� �������� ���������� ������ � �����������
// ������� ������� � ����� https://habrahabr.ru/company/xakep/blog/257895/


std::wstring Str2Wstr(std::string& narrow)
{
	// ��� ������� ���������� ������ ��� ���������� ����
	return std::wstring(narrow.begin(), narrow.end());
}


// ������� �� ��������
//std::string Wstr2Str(std::wstring& wide)
//{
//	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
//	std::string narrow = converter.to_bytes(wide);
//
//	return narrow;
//}