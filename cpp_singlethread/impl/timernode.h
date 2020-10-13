#pragma once

#include "../timer_def.h"

class ListTimer
{
public:
	ListTimer* pPrev;
	ListTimer* pNext;
};

class TimerNode
{
public:
	ListTimer listTimer;
	TimerMsType expireMS;   // ��ʱ������ʱ��
	TimerMsType periodMS;    // ��ʱ���������ٴδ����ļ��ʱ�������Ϊ 0����ʾ�ö�ʱ��Ϊһ���Ե�
	void (*OnTimer)(TimerIdType, void*); // ��ʱ���ص�����
	void* pParam;           // �ص������Ĳ���
	TimerIdType id;
	bool thisFrameKilled;
};
