#pragma once

#ifndef _TRANSACTION_MANAGER_
#define _TRANSACTION_MANAGER_
#include "BaseDAO.h"

/**
 * ����һ�����������
 */
class TransactionManager final
{
private:
	// ��¼һ�����ڹ��������DAO����
	BaseDAO* transDao;
	// ����Sqlsession
	void settingSqlsession(BaseDAO* transDao, BaseDAO* changeDao) {
		changeDao->setSqlSession(transDao->getSqlSession());
		changeDao->setAutoRelease(false);
	}
public:
	//************************************
	// Method:    TransactionManager
	// FullName:  TransactionManager::TransactionManager
	// Access:    public 
	// Returns:   
	// Qualifier: �����ʼ��,ʹ�ø������������ʱ�򣬾��Ѿ�����������
	// Parameter: BaseDAO * first ���������DAO����
	// Parameter: DAO ... args �����������DAO����
	//************************************
	template <class ... DAO>
	TransactionManager(BaseDAO* transDao, DAO ... args) {
		// �޸ı��й�DAO��sqlsession
		initializer_list<int>{(settingSqlsession(transDao, std::forward<DAO>(args)), 0)...};
		// ��������
		this->transDao = transDao;
		this->transDao->getSqlSession()->beginTransaction();
	}
	// �ύ����
	void commit() {
		this->transDao->getSqlSession()->commitTransaction();
	}
	// �ع�����
	void rollback() {
		this->transDao->getSqlSession()->rollbackTransaction();
	}
};
#endif // !_TRANSACTION_MANAGER_

