#ifndef TASKQUEUE_H
#define TASKQUEUE_H

#pragma once
#include "Task.h"
#include <queue>
#include <mutex>
#include <thread>

//�÷�ʾ����
//CTaskQueue *mQueue = new CTaskQueue();
//mQueue->Start();
//CTask *newTask = new CTask(50, &SocketConnection, &data, length);//�ɿ�Task.cpp
//mQueue->Push(newTask);

class CTaskQueue{
public:
	CTaskQueue();
	~CTaskQueue();

private:
	std::queue<CTask*> m_taskQueue;//TaskQueue
	std::thread m_thread;
	std::mutex m_mutex;
	bool m_bIsStart = false;//�߳��Ƿ���

public:
	void WorkThread();

	bool Push(CTask* task);
	
	CTask* Pop();
	bool Start();
	void Stop();
};



#endif

