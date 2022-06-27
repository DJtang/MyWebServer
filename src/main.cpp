/*
 * @Author       : DJtang
 * @Date         : 2022-01-23
 * @copyleft GPL 2.0
 */

#include <unistd.h>
#include "server/webserver.h"

int main() {
    /* 守护进程 后台运行 */
    //daemon(1, 0);
//    int pid;
//    for(int i=0;i<5;i++){
//        if(pid=fork()){
//            if(i==4) exit(0);
//            continue;
//        }
//        else break;
//    }
    WebServer server(
            55556, 1, 60000, false,             /* 端口 ET模式 timeoutMs 优雅退出  */
            3306, "root", "123456", "mydb", /* Mysql配置 */
            12, 8, true, 0, 1024);             /* 连接池数量 线程池数量 日志开关 日志等级 日志异步队列容量 */
    server.Start();
}

