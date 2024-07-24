#ifdef USE_REDIS

#include "pch.h"
#include "../include/RedisClient.h"

RedisClient::RedisClient(const string& host, int port, const string& password /*= ""*/, int db /*= 0*/, int max /*= 10*/)
{
	// ����������Ϣ
	ConnectionOptions co;
	co.host = host;
	co.port = port;
	co.db = db;
	if (password != "")
		co.password = password;

	// �������ӳ���Ϣ
	ConnectionPoolOptions po;
	po.size = max;
	po.wait_timeout = std::chrono::milliseconds(12);

	// �������Ӷ���
	m_redis = make_shared<Redis>(co, po);
}

#endif // USE_REDIS