#include "TaskQueue.h"

CTaskQueue::CTaskQueue()
{
}

CTaskQueue::~CTaskQueue()
{

}

//�����̵߳�����
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

//�������б��������
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

//��������л�ȡ����
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
	m_thread.join();//�ȴ�ʣ�����Ϣ�����ͳ�ȥ
}





