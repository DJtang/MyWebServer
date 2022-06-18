//
// Created by 11240 on 2022/1/25.
//

#ifndef MYWEBSERVER_SQLCONNPOOL_H
#define MYWEBSERVER_SQLCONNPOOL_H


#include <mysql/mysql.h>
#include <string>
#include <queue>
#include <mutex>
#include <semaphore.h>
#include <thread>
#include "../log/log.h"

class SqlConnPool {
public:
    static SqlConnPool *Instance();

    MYSQL *GetConn();
    void FreeConn(MYSQL * conn);
    int GetFreeConnCount();

    void Init(const char* host, int port,
              const char* user,const char* pwd,
              const char* dbName, int connSize);
    void ClosePool();

private:
    SqlConnPool();
    ~SqlConnPool();

    int MAX_CONN_;
    int useCount_;
    int freeCount_;

    std::queue<MYSQL *> connQue_;
    std::mutex mtx_;
    sem_t semId_;
};


#endif //MYWEBSERVER_SQLCONNPOOL_H
