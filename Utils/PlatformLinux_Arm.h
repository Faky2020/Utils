#ifndef ZHY_UTILS_PLATFORMLINUX_ARM_H
#define ZHY_UTILS_PLATFORMLINUX_ARM_H

#ifndef WIN32
#include <unistd.h>
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <stdint.h>

/** The thread static declarator (using TLS). */
#define ZHY_THREAD_STATIC	__thread
/**
* __thread��GCC���õ��ֲ߳̾��洢��ʩ����ȡЧ�ʿ��Ժ�ȫ�ֱ�����ȡ�__thread����ÿһ���߳���һ�ݶ���ʵ�壬
* �����̵߳�ֵ�������š���������������Щ����ȫ������ֵ���ܱ䣬�����ֲ�ֵ����ȫ�ֱ��������ı�����
* __threadʹ�ù���ֻ������POD����(��������ָ��ı����������Զ���Ĺ��졢��������ֵ�����������ͣ�������
* ���ݿ������⸴��memset,memcpy,�����ݿ��Ը�ԭ)����������class���ͣ���Ϊ�޷��Զ����ù��캯��������������
* ������������ȫ�ֱ����������ڵľ�̬�������������κ����ľֲ���������class����ͨ��Ա��������__thread����ֵ
* ֻ�ܳ�ʼ��Ϊ����������(ֵ�ڱ������Ϳ���ȷ��const int i=5,�����ڳ��������г�ʼ�����ٸı�const int i=rand()).
*
#include<iostream>
#include<pthread.h>
#include<unistd.h>

using namespace std;
const int i=5;
__thread int var=i;//���ַ�ʽЧ��һ��
//__thread int var=5;//

void* worker1(void* arg);
void* worker2(void* arg);

int main()
{
pthread_t pid1,pid2;
//__thread int temp=5;
static __thread  int temp=10;//���κ����ڵ�static����

pthread_create(&pid1,NULL,worker1,NULL);
pthread_create(&pid2,NULL,worker2,NULL);

pthread_join(pid1,NULL);
pthread_join(pid2,NULL);

cout<<temp<<endl;//���10
return 0;
}

void* worker1(void* arg)
{
cout<<++var<<endl;//��� 6
}

void* worker2(void* arg)
{
sleep(1);//�ȴ��߳�1�ı�varֵ����֤�Ƿ�Ӱ���߳�2
cout<<++var<<endl;//���6
}
*/

//---------------------------------------------------------------------------
// Files
//---------------------------------------------------------------------------
/** The maximum allowed file path size (in bytes). */
#define ZHY_FILE_MAX_PATH	256

//---------------------------------------------------------------------------
// Call back
//---------------------------------------------------------------------------
/** The std call type. */
#define ZHY_STDCALL			__stdcall

/** The call back calling convention. */
#define ZHY_CALLBACK_TYPE 

/** The C and C++ calling convension. */
#define ZHY_C_DECL

//---------------------------------------------------------------------------
// API Export/Import Macros
//---------------------------------------------------------------------------
/** Indicates an exported shared library function. */
#define ZHY_API_EXPORT				__attribute__ ((visibility("default")))

/** Indicates an imported shared library function. */
#define ZHY_API_IMPORT 

/** Indicates a deprecated function */
#define ZHY_API_DEPRECATED(msg)		__attribute__((warning("This function is deprecated: " msg)))

#define ZHY_PLATFORM_LINUX_NO_POSIX_MEMALIGN
#endif//ZHY_UTILS_PLATFORMLINUX_ARM_H