#pragma once

#ifndef _YAMLHELPER_H_
#define _YAMLHELPER_H_
#include "yaml-cpp/yaml.h"

class YamlHelper final
{
public:
	//************************************
	// Method:    getString
	// FullName:  YamlCpp::getString
	// Access:    public 
	// Returns:   std::string
	// Qualifier: ��Properties����ȡYaml���ö�Ӧ���ַ���
	// Parameter: YAML::Node * node ���ݽڵ�
	// Parameter: const std::string & key ���ݵ�key����spring.datasource.url
	//************************************
	std::string getString(YAML::Node* node, const std::string& key);

	//************************************
	// Method:    parseDbConnUrl
	// FullName:  YamlHelper::parseDbConnUrl
	// Access:    public 
	// Returns:   void
	// Qualifier: �������ݿ������ַ�����ȡ���ݿ������Ϣ
	// Parameter: const std::string& url ���ݿ������ַ���
	// Parameter: std::string * ip ����IP
	// Parameter: int * port ����˿�
	// Parameter: std::string * dbname �������ݿ�����
	//************************************
	void parseDbConnUrl(const std::string& url, std::string* ip, int* port, std::string* dbname);
};
#endif // _YAMLHELPER_H_
