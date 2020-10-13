#pragma once

#include "../timer_def.h"

class ListTimer
{
public:
	ListTimer* pPrev;
	ListTimer* pNext;
};

enum ETimerState
{
	ETimerStateInvalid = 0,
	ETimerStateRunning = 1,
	ETimerStateKilled = 2,
	ETimerStateReleased = 3,
};

class TimerNode
{
public:
	ListTimer ltTimer;
	TimerMsType uExpires;   // ��ʱ������ʱ��
	TimerMsType uPeriod;    // ��ʱ���������ٴδ����ļ��ʱ�������Ϊ 0����ʾ�ö�ʱ��Ϊһ���Ե�
	void (*timerFn)(TimerIdType, void*); // ��ʱ���ص�����
	void* pParam;           // �ص������Ĳ���
	TimerIdType id;
	ETimerState state;
	bool FrameKilled;
};
