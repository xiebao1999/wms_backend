#pragma once

#ifndef _STRINGUTIL_H_
#define _STRINGUTIL_H_
#include <vector>
#include <string>
using namespace std;

/**
 * ×Ö·û´®²Ù×÷¹¤¾ßÀà
 */
class StringUtil final
{
public:
	//************************************
	// Method:    split
	// FullName:  StringUtil::split
	// Access:    public static 
	// Returns:   std::vector<std::string> ²ð·Ö×Ö·û´®ÁÐ±í
	// Qualifier: ×Ö·û´®²ð·Ö
	// Parameter: const string & str ´ý²ð·Ö×Ö·û´®
	// Parameter: const string & delim ·Ö¸î·û
	//************************************
	static vector<string> split(const string& str,const string& delim);

	//************************************
	// Method:    trim
	// FullName:  StringUtil::trim
	// Access:    public static 
	// Returns:   void
	// Qualifier: ×Ö·û´®Çå³ýÁ½¶Ë¿Õ¸ñ
	// Parameter: string * str ´ý´¦Àí×Ö·û´®
	//************************************
	static void trim(string* str);

	//************************************
	// Method:    replace
	// FullName:  StringUtil::replace
	// Access:    public static 
	// Returns:   void
	// Qualifier: ×Ö·û´®Ìæ»»´¦Àí
	// Parameter: string * base ´ýÌæ»»×Ö·û´®
	// Parameter: const string & src Ìæ»»×Ó´®
	// Parameter: const string & dst Ä¿±ê×Ó´®
	//************************************
	static void replace(string* base, const string& src, const string& dst);
};
#endif // _STRINGUTIL_H_
