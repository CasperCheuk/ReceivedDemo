#include "TaskQueue.h"

CTaskQueue::CTaskQueue()
{
}

CTaskQueue::~CTaskQueue()
{

}

//工作线程的任务
void CTaskQueue::WorkThread(){

	while (m_bIsStart)
	{
		if (!m_taskQueue.empty()){
			CTask* it = m_taskQueue.front();
			it->DoWork();
			m_taskQueue.pop();
			delete it;
		}
	}
}

//从任务列表添加任务
bool CTaskQueue::Push(CTask* task){

	if (task == nullptr)
	{
		return false;
	}
	m_mutex.lock();
	m_taskQueue.push(task);
	m_mutex.unlock();
	return true;
}

//从任务队列获取任务
CTask* CTaskQueue::Pop(){

	CTask * it = nullptr;

	m_mutex.lock();
	if (!m_taskQueue.empty()){
		it = m_taskQueue.front();
		m_taskQueue.pop();
	}
	m_mutex.unlock();
	return it;
}


bool CTaskQueue::Start(){
if (m_bIsStart)
{
	return false;
}

m_bIsStart = true;
m_thread = std::thread(&CTaskQueue::WorkThread,this);

return true;
}

void CTaskQueue::Stop(){

	m_bIsStart = false;
	m_thread.join();//等待剩余的信息被发送出去
}





