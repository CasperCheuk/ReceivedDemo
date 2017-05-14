#ifndef TASKQUEUE_H
#define TASKQUEUE_H

#pragma once
#include "Task.h"
#include <queue>
#include <mutex>
#include <thread>

//用法示例例
//CTaskQueue *mQueue = new CTaskQueue();
//mQueue->Start();
//CTask *newTask = new CTask(50, &SocketConnection, &data, length);//可看Task.cpp
//mQueue->Push(newTask);

class CTaskQueue{
public:
	CTaskQueue();
	~CTaskQueue();

private:
	std::queue<CTask*> m_taskQueue;//TaskQueue
	std::thread m_thread;
	std::mutex m_mutex;
	bool m_bIsStart = false;//线程是否开启

public:
	void WorkThread();

	bool Push(CTask* task);
	
	CTask* Pop();
	bool Start();
	void Stop();
};



#endif

