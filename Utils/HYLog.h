# ifndef ZHY_UTILS_HYLOG_H
# define ZHY_UTILS_HYLOG_H
#include <mutex>
#include <fstream>
#include <iostream>
#include <../Utils/HYLogConfig.h>
using namespace std;

namespace HY
{
enum HYLogLevel
{
	HYLOG_LEVEL_DEFAULT = 0, //Ĭ��
	HYLOG_LEVEL_UNKNOW,      //δ֪
	HYLOG_LEVEL_FATAL,       //����
	HYLOG_LEVEL_ERROR,       //����
	HYLOG_LEVEL_WARN,        //����
	HYLOG_LEVEL_INFO,        //��Ϣ
	HYLOG_LEVEL_VERBOSE,     //�߳�
	HYLOG_LEVEL_DEBUG,       //����
};


class HYLog
{
public:
	HYLog();
	~HYLog();

public:
	bool IsFileOverflow(void);
	void SetFileSize(unsigned int fLen = 10);// 10M 
	bool Init(const std::string& logPath, int level);
	inline int GetLevel(void) { return mVerbosity; }

	template<typename T>
	HYLog& operator<<(const T& msg)
	{
		mLog[mCurIndex] << msg;
		return *this;
	}

	HYLog& operator<<(const char* msg)
	{
		mLog[mCurIndex] << msg;
		return *this;
	}

	HYLog& operator<<(std::ostream& (*os)(std::ostream&))
	{
		mLog[mCurIndex] << os;
		return *this;
	}

public:
	std::mutex mLogMutex;

private:
	int mVerbosity = 0;
	int mCurIndex = 0;
	size_t mFileSize = 0;
	ofstream mLog[2];
	string mLogPath[2];
	bool mEnable = false;
};

#define HYLOG_DEBUG(log) unique_lock<mutex> lock(log.mLogMutex); \
                        if(log.GetLevel() < HYLOG_LEVEL_DEBUG) ; \
                        else                                     \
                            log << "[DEBUG] F:" << __FUNCTION__ << " L:" << __LINE__

#define HYLOG_INFO(log) unique_lock<mutex> lock(log.mLogMutex); \
                        if(log.GetLevel() < HYLOG_LEVEL_INFO) ; \
                        else                                    \
                            log << "[INFO] F:" << __FUNCTION__ << " L:" << __LINE__

#define HYLOG_WARN(log) unique_lock<mutex> lock(log.mLogMutex); \
                        if(log.GetLevel() < HYLOG_LEVEL_WARN) ; \
                        else                                    \
                            log << "[WARN] F:" << __FUNCTION__ << " L:" << __LINE__

#define HYLOG_ERROR(log) unique_lock<mutex> lock(log.mLogMutex); \
                        if(log.GetLevel() < HYLOG_LEVEL_ERROR) ; \
                        else                                     \
                            log << "[ERROR] F:" << __FUNCTION__ << " L:" << __LINE__

#define HYLOG_FATAL(log) unique_lock<mutex> lock(log.mLogMutex);  \
                         if(log.GetLevel() < HYLOG_LEVEL_FATAL) ; \
                         else                                     \
                            log << "[FATAL] F:" << __FUNCTION__ << " L:" << __LINE__                                                                                                            

}
}

#endif ZHY_UTILS_HYLOG_H