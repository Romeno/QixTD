#include "stdafx.h"
#include "StringUtils.h"

// просто латиницу из string в wstring 40+ https://stackoverflow.com/questions/2573834/c-convert-string-or-char-to-wstring-or-wchar-t 
// там же 150+ только из utf-8 в utf-16 и обртано
// Надо MultiByteToWideChar или что то подобное  https://msdn.microsoft.com/en-us/library/windows/desktop/dd319072(v=vs.85).aspx
// Ещё советовали iconv, который портирован под винду или похожую виндовую библиотеку работы с кодировками
// длинное полотно и чтиво https://habrahabr.ru/company/xakep/blog/257895/


std::wstring Str2Wstr(std::string& narrow)
{
	// тут простая реализация только для английских букв
	return std::wstring(narrow.begin(), narrow.end());
}


// обратно не работает
//std::string Wstr2Str(std::wstring& wide)
//{
//	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
//	std::string narrow = converter.to_bytes(wide);
//
//	return narrow;
//}