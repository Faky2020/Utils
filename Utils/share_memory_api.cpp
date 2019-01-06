#include "share_memory_api.h"

#include <errno.h>

#ifndef WIN32
#include <sys/ipc.h> 
#include <sys/shm.h> 
#endif

namespace ShareMemApi
{
	//���������ڴ�
	SMHandle CreateShareMem(SM_KEY key, SM_SIZE size)
	{
		SMHandle hd = shmget(key, size, IPC_CREAT | 0666);
		return hd;
	}

	//�򿪴����Ĺ����ڴ�
	SMHandle OpenShareMem(SM_KEY key, SM_SIZE Size)
	{

		SMHandle hd = shmget(key, Size, 0);
		printf("handle = %d ,key = %d ,error: %d \r\n", hd, key, errno);

		return hd;
	}

	//�����Ըù����ڴ�ķ��ʣ�
	void* MapShareMem(SMHandle handle)
	{
		return shmat(handle, 0, 0);
	}

	int UnMapShareMem(const void* MemoryPtr)
	{
		return shmdt(MemoryPtr);
	}

	int CloseShareMem(SMHandle handle)
	{
		return shmctl(handle, IPC_RMID, 0);
	}

	int set_semvalue(int sem_id)
	{
		//���ڳ�ʼ���ź�������ʹ���ź���ǰ����������
		union semun sem_union;

		sem_union.val = 1;
		if (-1 == semctl(sem_id, 0, SETVAL, sem_union))
			return RET_ERROR_FAIL;

		return RET_ERROR_OK;
	}

	void del_semvalue(int sem_id)
	{
		//ɾ���ź���
		union semun sem_union;
		if (-1 == semctl(sem_id, 0, IPC_RMID, sem_union))
		{
			printf("Failed to delete semaphore func name = %s line num = %d\n", __FUNCTION__, __LINE__);
			//     std::cout << "Failed to delete semaphore, " << __FUNCTION__ << "\t"<< __LINE__ << std::endl;
		}
	}

	int semaphore_p(int sem_id)
	{
		//���ź�������1���������ȴ�P��sv��
		struct sembuf sem_b;
		sem_b.sem_num = 0;
		sem_b.sem_op = -1;//P()
		sem_b.sem_flg = SEM_UNDO;
		if (semop(sem_id, &sem_b, 1) == -1)
		{
			printf("semaphore_p failed func name = %s line num = %d\n", __FUNCTION__, __LINE__);
			// std::cout << "semaphore_p failed, " << __FUNCTION__ << "\t"<< __LINE__ << std::endl;
			return RET_ERROR_FAIL;
		}

		return RET_ERROR_OK;
	}


	int semaphore_p_no_wait(int sem_id)
	{
		//���ź�������1���������ȴ�P��sv��
		struct sembuf sem_b;
		sem_b.sem_num = 0;
		sem_b.sem_op = -1;//P()
		sem_b.sem_flg = IPC_NOWAIT;
		if (-1 == semop(sem_id, &sem_b, 1))
		{
			return RET_ERROR_FAIL;
		}
		return RET_ERROR_OK;
	}

	int semaphore_v(int sem_id)
	{
		//����һ���ͷŲ�������ʹ�ź�����Ϊ���ã��������ź�V��sv��
		struct sembuf sem_b;
		sem_b.sem_num = 0;
		sem_b.sem_op = 1;//V()
		sem_b.sem_flg = SEM_UNDO;
		if (-1 == semop(sem_id, &sem_b, 1))
		{
			// std::cout << "semaphore_v failed, " << __FUNCTION__ << "\t"<< __LINE__ << std::endl;
			return RET_ERROR_FAIL;
		}

		return RET_ERROR_OK;
	}

}
