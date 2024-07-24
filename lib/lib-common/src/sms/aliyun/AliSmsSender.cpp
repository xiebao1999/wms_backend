#include "pch.h"
#include "../../../include/sms/aliyun/AliSmsSender.h"
#include "../../../include/sms/aliyun/AliKeyConfig.h"

#ifdef USE_ALISMS
#include "alibabacloud/core/AlibabaCloud.h"
#include "alibabacloud/core/ClientConfiguration.h"
#include "alibabacloud/dysmsapi/DysmsapiClient.h"
using namespace AlibabaCloud;
using namespace AlibabaCloud::Dysmsapi;
#endif

#include <iostream>

AliSmsSender::AliSmsSender(const std::string& keyfilename /*= "key-config.yaml"*/, const std::string& prefix /*= "aliyun.sms"*/)
{
#ifdef USE_ALISMS
	// 初始化SDK
	AlibabaCloud::InitializeSdk();
	// 初始化key配置
	AliKeyConfig::init(keyfilename, prefix);
#endif
}

AliSmsSender::~AliSmsSender()
{
#ifdef USE_ALISMS
	// 关闭SDK
	AlibabaCloud::ShutdownSdk();
#endif
}

std::shared_ptr<AliSmsResult> AliSmsSender::sendSms(const std::string& phoneNumber, const std::string& signName, const std::string& templateCode, const std::string& templateParams)
{
#ifdef USE_ALISMS
	// 配置实例
	ClientConfiguration configuration(AliKeyConfig::region);
	DysmsapiClient client(AliKeyConfig::ak, AliKeyConfig::sk, configuration);
	// 创建API请求并设置参数
	Model::SendSmsRequest request;
	request.setPhoneNumbers(phoneNumber);
	request.setSignName(signName);
	request.setTemplateCode(templateCode);
	request.setTemplateParam(templateParams);
	// 发送短信
	auto outcome = client.sendSms(request);
	// 发送异常
	auto result = std::make_shared<AliSmsResult>();
	if (!outcome.isSuccess())
	{
		// 异常处理
		std::cout << outcome.error().errorCode() << std::endl;
		result->Code(outcome.error().errorCode());
		result->Message(outcome.error().errorMessage());
		return result;
	}
	// 发送正常，处理对应返回结果
	result->Code(outcome.result().getCode());
	result->Message(outcome.result().getMessage());
	result->BizId(outcome.result().getBizId());
	result->RequestId(outcome.result().requestId());
	return result;
#else
	auto result = std::make_shared<AliSmsResult>();
	result->Code("Fail");
	result->Message("system not support aliyun sms.");
	return result;
#endif
}

std::shared_ptr<AliSmsResult> AliSmsSender::sendSmsBatch(const std::string& phoneNumbers, const std::string& signNames, const std::string& templateCode, const std::string& templateParams)
{
#ifdef USE_ALISMS
	// 配置实例
	ClientConfiguration configuration(AliKeyConfig::region);
	DysmsapiClient client(AliKeyConfig::ak, AliKeyConfig::sk, configuration);
	// 创建API请求并设置参数
	Model::SendBatchSmsRequest request;
	request.setPhoneNumberJson(phoneNumbers);
	request.setSignNameJson(signNames);
	request.setTemplateCode(templateCode);
	request.setTemplateParamJson(templateParams);
	// 发送短信
	auto outcome = client.sendBatchSms(request);
	// 发送异常
	auto result = std::make_shared<AliSmsResult>();
	if (!outcome.isSuccess())
	{
		// 异常处理
		std::cout << outcome.error().errorCode() << std::endl;
		result->Code(outcome.error().errorCode());
		result->Message(outcome.error().errorMessage());
		return result;
	}
	// 发送正常，处理对应返回结果
	result->Code(outcome.result().getCode());
	result->Message(outcome.result().getMessage());
	result->BizId(outcome.result().getBizId());
	result->RequestId(outcome.result().requestId());
	return result;
#else
	auto result = std::make_shared<AliSmsResult>();
	result->Code("Fail");
	result->Message("system not support aliyun sms.");
	return result;
#endif
}
