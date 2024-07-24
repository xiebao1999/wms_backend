#include "pch.h"
#include "../include/SimpleDateTimeFormat.h"
#include <chrono>
#include <sstream>
#include <iomanip>

std::string SimpleDateTimeFormat::format(const std::string& fmt /*= "%Y-%m-%d %H:%M:%S"*/)
{
	// ��ȡ��ǰʱ��
	auto now = std::chrono::system_clock::now();
	
	// ��ʽʱ��
	std::stringstream ss;
	auto tNow = std::chrono::system_clock::to_time_t(now);
	ss << std::put_time(std::localtime(&tNow), fmt.c_str());
	return ss.str();
}

std::string SimpleDateTimeFormat::formatWithMilli(const std::string& fmt /*= "%Y-%m-%d %H:%M:%S"*/, const std::string msDelim /*= " "*/)
{
	// ��ȡ��ǰʱ��
	auto now = std::chrono::system_clock::now();
	
	// ��ʽ��ʱ��
	std::stringstream ss;
	auto tNow = std::chrono::system_clock::to_time_t(now);
	ss << std::put_time(std::localtime(&tNow), fmt.c_str());

	// ��ȡ��ǰʱ�������
	auto tSeconds = std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch());
	// ��ȡ��ǰʱ��ĺ���
	auto tMilli = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch());
	// �������������
	auto ms = tMilli - tSeconds;
	ss << msDelim << std::setfill('0') << std::setw(3) << ms.count();
	return ss.str();
}
