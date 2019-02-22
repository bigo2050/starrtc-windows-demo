#include "stdafx.h"
#include "CChatManager.h"
#include "StarIMMessageBuilder.h"

CChatManager::CChatManager(CUserManager* pUserManager, IStarIMC2CListener* pListener)
{
	m_pStarRtcCore = StarRtcCore::getStarRtcCoreInstance(pUserManager);
	m_pStarRtcCore->addC2CListener(this);
	m_pStarIMC2CListener = pListener;
}


CChatManager::~CChatManager()
{
	if (m_pStarRtcCore != NULL)
	{
		m_pStarRtcCore->addC2CListener(NULL);
	}
}

CIMMessage* CChatManager::sendMessage(char* toUserId, char* msgStr)
{
	CIMMessage* pIMMessage = StarIMMessageBuilder::getC2CMessage(m_pStarRtcCore->m_pUserManager->m_ServiceParam.m_strUserId, toUserId, msgStr);
	if (pIMMessage != NULL)
	{
		addMessageToMap(pIMMessage);
		m_pStarRtcCore->sendMessage(pIMMessage);
	}
	return pIMMessage;
}

bool CChatManager::sendOnlineMessage(char* toUserId, char* msgStr)
{
	CIMMessage* pIMMessage = StarIMMessageBuilder::getC2CMessage(m_pStarRtcCore->m_pUserManager->m_ServiceParam.m_strUserId, toUserId, msgStr);
	if (pIMMessage != NULL)
	{
		addMessageToMap(pIMMessage);
		m_pStarRtcCore->sendOnlineMessage(pIMMessage);
	}
	return true;
}

void CChatManager::onNewMessage(CIMMessage* var1)
{
	if (m_pStarIMC2CListener != NULL)
	{
		m_pStarIMC2CListener->onNewMessage(var1);
	}
}
void CChatManager::onSendMessageSuccess(int msgIndex)
{
	if (m_pStarIMC2CListener != NULL)
	{
		removeMessageFromMap(msgIndex);
		m_pStarIMC2CListener->onSendMessageSuccess(msgIndex);
	}
}
void CChatManager::onSendMessageFailed(int msgIndex)
{
	if (m_pStarIMC2CListener != NULL)
	{
		removeMessageFromMap(msgIndex);
		m_pStarIMC2CListener->onSendMessageFailed(msgIndex);
	}
}

void CChatManager::addMessageToMap(CIMMessage* pMsg)
{
	CString strKey = "";
	strKey.Format("sendMessage%d", pMsg->m_nMsgIndex);
	m_MsgMap.insert(pair<string, CIMMessage*>(strKey, pMsg));
}

void CChatManager::removeMessageFromMap(int nIndex)
{
	CString strKey = "";
	strKey.Format("sendMessage%d", nIndex);
	map<string, CIMMessage*>::iterator iter = m_MsgMap.find(strKey.GetBuffer(0));
	if (iter != m_MsgMap.end())
	{
		m_MsgMap.erase(iter);
	}
}
