#pragma once

#ifndef _EMAILSENDER_H_
#define _EMAILSENDER_H_

#include <string>
#include <vector>

/**
 * ��дһ���ʼ����͹�����
 */
class EmailSender
{
public:
	//************************************
	// Method:    EmailSender
	// FullName:  EmailSender::EmailSender
	// Access:    public 
	// Returns:   
	// Qualifier: �����ʼ��
	// Parameter: const std::string& smtp_server �ʼ�����������smtp.163.com
	// Parameter: const int smtp_port �������˿ڣ���25
	// Parameter: const std::string& password ��Ȩ����
	// Parameter: const std::string& from_email �ʼ������������ַ
	// Parameter: const std::string& from_name  �ʼ����������ƣ�Ĭ��ֵNo-Reply
	// Parameter: const std::string& charset ���ݱ��룬Ĭ��ֵgb2312
	//************************************
	EmailSender(
		const std::string& smtp_server,
		const int smtp_port,
		const std::string& password,
		const std::string& from_email,
		const std::string& from_name = "No-Reply",
		const std::string& charset = "gb2312");
	~EmailSender();
	// �����ʼ���������ݣ�������HTML��ʽ���ı�
	void setEmailContent(const std::string& subject = "", const std::string& body = "");
	// ����ʼ�������
	void addRecvEmailAddr(const std::string& email_addr, const std::string& name = "");
	// ����ʼ�������
	void addCcEmailAddr(const std::string& email_addr, const std::string& name = "");
	// ��Ӹ���
	void addAttachment(const std::string& filename);
	// ִ�з���
	bool send();
	// ��ȡ����
	std::string getCharset() const;
	// ���ñ���
	void setCharset(std::string val);
	// ����SSLЭ��
	void enableSSL();
	// ����SSLЭ��
	void disableSSL();
private:
	// smtp������
	std::string m_smtp_url;
	// ���ݱ��룬Ĭ��gb2312
	std::string m_charset;
	// �ʼ������� key �ʼ���ַ val ����������
	std::pair<std::string, std::string> m_from;
	// �ʼ���������Ȩ����
	std::string m_password;
	// �ʼ������� key �ʼ���ַ val ����������
	std::vector<std::pair<std::string, std::string>> m_recvs;
	// �ʼ������� key �ʼ���ַ val ����������
	std::vector<std::pair<std::string, std::string>> m_ccs;
	// �ʼ�����
	std::string m_email_subject;
	// �ʼ�����
	std::string m_email_body;
	// �ʼ������ļ��б��ļ��ľ��Ի����·����
	std::vector<std::string> m_attachments;
	// �ص���������MIMEЭ���ƴ�ӵ��ַ�����libcurl����
	static size_t payloadSource(void* ptr, size_t size, size_t nmemb, void* stream);
	// �����ʼ�MIME����
	std::string generateMimeMessage();
	// ��ȡ�����ļ���
	void getFileName(const std::string& path, std::string& filename);
	// ��ȡ�����ļ�����  
	void getFileContentType(const std::string& path, std::string& contentType);
};

#endif // !_EMAILSENDER_H_