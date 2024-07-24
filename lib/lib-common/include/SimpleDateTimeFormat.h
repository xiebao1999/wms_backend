#pragma once

#ifndef _SIMPLEDATETIMEFORMAT_H_
#define _SIMPLEDATETIMEFORMAT_H_
#include <string>

/**
 * ����һ���򵥵�ʱ���ʽ������
 * �ο���https://zh.cppreference.com/w/cpp/io/manip/put_time
 */
class SimpleDateTimeFormat final
{
public:
	//************************************
	// Method:    format
	// FullName:  SimpleDateTimeFormat::format
	// Access:    public static 
	// Returns:   std::string ���ظ�ʽ������ַ���
	// Qualifier: ��ȡ��ǰʱ���ʽ�ַ���
	// Parameter: const std::string & fmt ��ʽ�ַ�����Ĭ��ֵ%Y-%m-%d %H:%M:%S����Ӧ��ʽ�磺2023-01-01 01:01:01��
	//************************************
	static std::string format(const std::string& fmt = "%Y-%m-%d %H:%M:%S");

	//************************************
	// Method:    formatWithMilli
	// FullName:  SimpleDateTimeFormat::formatWithMilli
	// Access:    public static 
	// Returns:   std::string ���ظ�ʽ������ַ���
	// Qualifier: ��ȡ��ǰʱ���ʽ�ַ�����������ʱ���ȡ
	// Parameter: const std::string & fmt ��ʽ�ַ�����Ĭ��ֵ%Y-%m-%d %H:%M:%S����Ӧ��ʽ�磺2023-01-01 01:01:01��
	// Parameter: const std::string msDelim ������ǰ���ֵķָ����Ĭ���ǿո�
	//************************************
	static std::string formatWithMilli(const std::string& fmt = "%Y-%m-%d %H:%M:%S", const std::string msDelim = " ");
};

#endif // !_SIMPLEDATETIMEFORMAT_H_