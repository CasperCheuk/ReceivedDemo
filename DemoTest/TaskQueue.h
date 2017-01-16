#ifndef TASKQUEUE_H
#define TASKQUEUE_H

#pragma once
#include "Task.h"
#include <queue>
#include <mutex>
#include <thread>


class CTaskQueue{
public:
	CTaskQueue();
	~CTaskQueue();

private:
	std::queue<CTask*> m_taskQueue;//TaskQueue
	std::thread m_thread;
	std::mutex m_mutex;
	bool m_bIsStart;//线程是否开启

public:
	void WorkThread();

	bool Push(CTask* task);
	
	CTask* Pop();
	bool Start();
	void Stop();
};



#endif

