#pragma once

#ifndef _STRINGUTIL_H_
#define _STRINGUTIL_H_
#include <vector>
#include <string>
using namespace std;

/**
 * �ַ�������������
 */
class StringUtil final
{
public:
	//************************************
	// Method:    split
	// FullName:  StringUtil::split
	// Access:    public static 
	// Returns:   std::vector<std::string> ����ַ����б�
	// Qualifier: �ַ������
	// Parameter: const string & str ������ַ���
	// Parameter: const string & delim �ָ��
	//************************************
	static vector<string> split(const string& str,const string& delim);

	//************************************
	// Method:    trim
	// FullName:  StringUtil::trim
	// Access:    public static 
	// Returns:   void
	// Qualifier: �ַ���������˿ո�
	// Parameter: string * str �������ַ���
	//************************************
	static void trim(string* str);

	//************************************
	// Method:    replace
	// FullName:  StringUtil::replace
	// Access:    public static 
	// Returns:   void
	// Qualifier: �ַ����滻����
	// Parameter: string * base ���滻�ַ���
	// Parameter: const string & src �滻�Ӵ�
	// Parameter: const string & dst Ŀ���Ӵ�
	//************************************
	static void replace(string* base, const string& src, const string& dst);
};
#endif // _STRINGUTIL_H_
