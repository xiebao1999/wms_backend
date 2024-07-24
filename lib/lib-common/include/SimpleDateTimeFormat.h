#pragma once

#ifndef _SIMPLEDATETIMEFORMAT_H_
#define _SIMPLEDATETIMEFORMAT_H_
#include <string>

/**
 * 定义一个简单的时间格式工具类
 * 参考：https://zh.cppreference.com/w/cpp/io/manip/put_time
 */
class SimpleDateTimeFormat final
{
public:
	//************************************
	// Method:    format
	// FullName:  SimpleDateTimeFormat::format
	// Access:    public static 
	// Returns:   std::string 返回格式化后的字符串
	// Qualifier: 获取当前时间格式字符串
	// Parameter: const std::string & fmt 格式字符串，默认值%Y-%m-%d %H:%M:%S（对应格式如：2023-01-01 01:01:01）
	//************************************
	static std::string format(const std::string& fmt = "%Y-%m-%d %H:%M:%S");

	//************************************
	// Method:    formatWithMilli
	// FullName:  SimpleDateTimeFormat::formatWithMilli
	// Access:    public static 
	// Returns:   std::string 返回格式化后的字符串
	// Qualifier: 获取当前时间格式字符串，带毫秒时间获取
	// Parameter: const std::string & fmt 格式字符串，默认值%Y-%m-%d %H:%M:%S（对应格式如：2023-01-01 01:01:01）
	// Parameter: const std::string msDelim 毫秒与前部分的分割符，默认是空格
	//************************************
	static std::string formatWithMilli(const std::string& fmt = "%Y-%m-%d %H:%M:%S", const std::string msDelim = " ");
};

#endif // !_SIMPLEDATETIMEFORMAT_H_