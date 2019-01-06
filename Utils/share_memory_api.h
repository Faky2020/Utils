

#ifndef CN_VICKY_SHAREMEMAPI_H
#define	CN_VICKY_SHAREMEMAPI_H

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/sem.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <iostream>

typedef int     SMHandle;
typedef key_t   SM_KEY;
typedef size_t  SM_SIZE;
typedef ushort  SMUID_t;

#define INVALID_SM_HANDLE -1

union semun
{
	int val;
	struct semid_ds *buf;
	unsigned short *arry;
};

enum RET_ERROR_CODE
{
	RET_ERROR_FAIL = -1,
	RET_ERROR_OK = 1,
};

namespace ShareMemApi
{

	/*
	*  ����ShareMem �ڴ���
	*  �õ�һ�������ڴ��ʶ���򴴽�һ�������ڴ���󲢷��ع����ڴ��ʶ��
	*	key   ����ShareMem �Ĺؼ�ֵ
	*  Size  ������С
	*	���� ��ӦShareMem����ֵ
	*/
	SMHandle CreateShareMem(SM_KEY key, SM_SIZE size);

	/*
	* ��ShareMem �ڴ���
	* key   ��ShareMem �Ĺؼ�ֵ
	* Size  �򿪴�С
	* ����  ��ӦShareMem ����ֵ
	*/
	SMHandle OpenShareMem(SM_KEY key, SM_SIZE size);

	/*
	*  ӳ��ShareMem �ڴ���
	*  �ѹ����ڴ�������ӳ�䵽���ý��̵ĵ�ַ�ռ䣬���ӹ����ڴ��ʶ��Ϊshmid�Ĺ����ڴ棬����
	*  �ɹ���ѹ����ڴ�������ӳ�䵽���ý��̵ĵ�ַ�ռ䣬�����񱾵ؿռ�һ������
	*	handle ӳ��ShareMem �ı���ֵ
	*  ���� ShareMem ������ָ��
	*/
	void* MapShareMem(SMHandle handle);

	/*
	*  �ر�ӳ��   ShareMem �ڴ���
	*  ��shmat�����෴���������Ͽ��빲���ڴ渽�ӵ�ĵ�ַ����ֹ�����̷��ʴ�Ƭ�����ڴ�
	*	MemoryPtr ShareMem ������ָ��
	*  ���� 0�ɹ� -1ʧ��
	*/
	int UnMapShareMem(const void* MemoryPtr);

	/*
	*  �ر�ShareMem
	*  ��ɶԹ����ڴ�Ŀ���,�رչ����ڴ�(ipcrm -m shmid)��
	* 	handle  ��Ҫ�رյ�ShareMem ����ֵ
	*  ���� 0�ɹ� -1ʧ��
	*/
	int CloseShareMem(SMHandle handle);

	int set_semvalue(int sem_id);

	void del_semvalue(int sem_id);

	int semaphore_p(int sem_id);

	int semaphore_p_no_wait(int sem_id);

	int semaphore_v(int sem_id);

}

#endif//CN_VICKY_SHAREMEMAPI_H
