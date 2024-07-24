#pragma once

#ifndef __CONNECTION_POOL_H__
#define __CONNECTION_POOL_H__

#include "./mysql/jdbc.h"
#include <list>
#include <string>
#include <mutex>

using namespace std;
using namespace sql;
/**
 * ����һ�����ݿ����ӳ���
 */
class ConnPool final
{
public:
	// �����ʼ��
	ConnPool(string url, string user, string password, int maxSize);
	// �����ͷ��ڴ�
	~ConnPool();
	// ��ȡ���ݿ�����
	Connection* GetConnection();
	// �����ݿ����ӷŻص����ӳص�������
	void ReleaseConnection(Connection* conn);
	// ��ȡ��ǰ���ӳش�С
	int getPoolSize();
private:
	// ��ǰ�ѽ��������ݿ���������
	int curSize;
	// ���ӳض����������ݿ�������
	int maxSize;
	// �û���
	string username;
	// ����
	string password;
	// ���ӵ�ַ����tcp://localhost:3306/db
	string url;
	// ������������
	Driver* driver;
	// ���ӳ�����
	list<Connection*> connList;
	// �߳���
	mutex lock;
	
	// ����һ������
	Connection* CreateConnection();
	// ��ʼ�����ݿ����ӳ�
	void InitConnection(int iInitialSize);
	// �������ݿ����Ӷ���
	void DestoryConnection(Connection* conn);
	// �������ݿ����ӳ�
	void DestoryConnPool();
};

#endif /*_CONNECTION_POOL_H */
