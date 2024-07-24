#pragma once

#ifndef _REDISCLIENT_H_
#define _REDISCLIENT_H_
#include <string>
#include <memory>
#include <iostream>
#include <functional>
#include "sw/redis++/redis++.h"
using namespace std;
using namespace sw::redis;

/**
 * Redis�ͻ���
 */
class RedisClient
{
private:
	// Redis���Ӷ���
	shared_ptr<Redis> m_redis;
public:
	//************************************
	// Method:    RedisClient
	// FullName:  RedisClient::RedisClient
	// Access:    public 
	// Returns:   
	// Qualifier: �����ʼ��
	// Parameter: const string & host Redis������ַ
	// Parameter: int port Redis�������˿�
	// Parameter: const string & password Redis����������,Ĭ��û������
	// Parameter: int db ѡ������ݿ⣬Ĭ��ֵ0
	// Parameter: int max ���ݿ������������Ĭ��Ϊ10
	//************************************
	RedisClient(const string& host, int port, const string& password = "", int db = 0, int max = 10);
	//************************************
	// Method:    execute
	// FullName:  RedisClient::execute
	// Access:    public 
	// Returns:   T ����ֵ����
	// Qualifier: ִ��Redis����
	// Parameter: std::function<T<Redis*>> callfun �����߼����������в����߼�����������д
	//************************************
	template<class T>
	T execute(std::function<T(Redis*)> callfun)
	{
		try
		{
			return callfun(m_redis.get());
		}
		catch (const std::exception& e)
		{
			cerr << e.what() << endl;
		}
		return {};
	}
};

#endif // _REDISCLIENT_H_