#pragma once

#ifndef _NACOSCLIENT_H_
#define _NACOSCLIENT_H_

#include <string>
using namespace std;

#ifdef USE_NACOS
#include "nacos/Nacos.h"
using namespace nacos;
#endif
#include "yaml-cpp/yaml.h"

/**
 * ����һ��Nacos�ͻ��ˣ����ڷ�װNacos���ò���
 * ע�⣺NacosĿǰ��֧��Windows�汾��
 * ������Windows����ʹ��Nacos������ʵ���Ƕ�ȡ���������ļ������Ҳ�֧��Windows����ע�Ṧ��
 */
class NacosClient
{
private:
	//��������ַ
	string m_address;
	//�����ռ�
	string m_namespace;

#ifdef USE_NACOS
	//��ǰ��������
	NamingService* namingSvc;
	//ע��ʵ��ID
	std::string instanceId;
#endif
public:
	//************************************
	// Method:    NacosClient
	// FullName:  NacosClient::NacosClient
	// Access:    public 
	// Returns:   
	// Qualifier: �����ʼ��
	// Parameter: const string& address ��������ַ���磺39.99.114.126:8848
	// Parameter: const string& namespaceId �����ռ䣬�磺1653f775-4782-46ad-9cd2-b60155a574c6
	//************************************
	NacosClient(const string& address, const string& namespaceId);
	
	// �����ͷ���Դ
	~NacosClient();

	//************************************
	// Method:    getConfig
	// FullName:  NacosClient::getConfig
	// Access:    public 
	// Returns:   std::string
	// Qualifier: ��ȡyaml����
	// Parameter: const string& dataId ����ID
	// Parameter: const string& groupName �������ƣ�Ĭ��ֵ��DEFAULT_GROUP
	//************************************
	YAML::Node getConfig(const string& dataId, const string& groupName = "DEFAULT_GROUP");

	//************************************
	// Method:    getConfigText
	// FullName:  NacosClient::getConfigText
	// Access:    public 
	// Returns:   std::string
	// Qualifier: ��ȡ�ı�����
	// Parameter: const string & dataId ����ID
	// Parameter: const string & groupName �������ƣ�Ĭ��ֵ��DEFAULT_GROUP
	//************************************
	std::string getConfigText(const string& dataId, const string& groupName = "DEFAULT_GROUP");

	//************************************
	// Method:    registerInstance
	// FullName:  NacosClient::registerInstance
	// Access:    public 
	// Returns:   bool ע��ɹ�����true
	// Qualifier: ע�����
	// Parameter: const string & ip ע�����IP��ַ
	// Parameter: int port ע�����˿�
	// Parameter: const string & serviceName ע���������
	// Parameter: const string & groupName �������ƣ�Ĭ��ֵ��DEFAULT_GROUP
	// Parameter: const string & clusterName ��Ⱥ���ƣ�Ĭ��ֵ��DEFAULT
	//************************************
	bool registerInstance(const string& ip, int port, const string& serviceName, const string& groupName = "DEFAULT_GROUP", const string& clusterName = "DEFAULT");
	
	//************************************
	// Method:    deregisterInstance
	// FullName:  NacosClient::deregisterInstance
	// Access:    public 
	// Returns:   bool ��ע��ɹ�����true
	// Qualifier: ��ע�����
	// Parameter: const string & ip ע�����IP��ַ
	// Parameter: int port ע�����˿�
	// Parameter: const string & serviceName ע���������
	// Parameter: const string & groupName �������ƣ�Ĭ��ֵ��DEFAULT_GROUP
	// Parameter: const string & clusterName ��Ⱥ���ƣ�Ĭ��ֵ��DEFAULT
	//************************************
	bool deregisterInstance(const string& ip, int port, const string& serviceName, const string& groupName = "DEFAULT_GROUP", const string& clusterName = "DEFAULT");
};
#endif // _NACOSCLIENT_H_
