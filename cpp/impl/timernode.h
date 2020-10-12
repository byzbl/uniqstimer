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
	ListTimer ltTimer;
	TimerMsType uExpires;   // ��ʱ������ʱ��
	TimerMsType uPeriod;    // ��ʱ���������ٴδ����ļ��ʱ�������Ϊ 0����ʾ�ö�ʱ��Ϊһ���Ե�
	void (*timerFn)(void*); // ��ʱ���ص�����
	void* pParam;           // �ص������Ĳ���
	TimerIdType id;
};
