#pragma once

#ifndef _DB_INIT_
#define _DB_INIT_

#include "ConnectionPool.h"

/**
 * ���ݿ����ö���
 */
class DBConfig
{
public:
	// �û���
	string user = "";
	// ����
	string pass = "";
	// ���ݿ���
	string db = "";
	// ����IP
	string host = "127.0.0.1";
	// ����˶˿�
	int port = 3306;
	// ���������
	int poolMaxSize = 25;
	DBConfig() {}
	DBConfig(string _user, string _pass, string _db, string _host, int _port, int _maxSize) :user(_user), pass(_pass), db(_db), host(_host), port(_port), poolMaxSize(_maxSize) {}
};

/**
 * ���ݿ��ʼ��
 */
class DbInit final
{
private:
	// ��������
	static ConnPool* connPool;
public:
	//************************************
	// Method:    initDbPool
	// FullName:  DbInit::initDbPool
	// Access:    public static 
	// Returns:   bool �Ƿ��ʼ���ɹ�
	// Qualifier: ��ʼ�����ӳ�
	// Parameter: DBConfig config ���ݿ����ö���
	//************************************
	static bool initDbPool(DBConfig config);

	//************************************
	// Method:    getConnPool
	// FullName:  DbInit::getConnPool
	// Access:    public static 
	// Returns:   ConnPool*
	// Qualifier: ��ȡ���ӳض���
	//************************************
	static ConnPool* getConnPool();

	//************************************
	// Method:    releasePool
	// FullName:  DbInit::releasePool
	// Access:    public static 
	// Returns:   void
	// Qualifier: �ͷ����ӳ�
	//************************************
	static void releasePool();
};

#endif // !DB_INIT_