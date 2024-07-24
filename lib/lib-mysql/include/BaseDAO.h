#pragma once

#ifndef _ABSTRACT_DAO_
#define _ABSTRACT_DAO_
#include "SqlSession.h"

/**
 * ����һ��������DAO�࣬���������������DAO����Ҫ�̳���
 */
class BaseDAO
{
private:
	// �Ƿ��Զ��ͷ�SQLSession
	bool isAutoRelease;
protected:
	// ����һ��SqlSession
	SqlSession* sqlSession;
public:
	BaseDAO();
	virtual ~BaseDAO();
	// ��ȡSqlSession
	SqlSession* getSqlSession();
	// ����SqlSession
	void setSqlSession(SqlSession* session);
	// �����Ƿ��Զ��ͷ�SqlSession
	void setAutoRelease(bool release);
};

#endif // !_ABSTRACT_DAO_
