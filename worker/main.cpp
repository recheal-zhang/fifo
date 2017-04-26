#include <unistd.h>

#include <iostream>
#include <string>

#include "Util.h"
#include "Define.h"
#include "Fifo.h"
#include "Epoll.h"

using namespace std;

int main(){
    cout << "hello worker" << endl;


    std::string fifoClientName =
        CUtil::getFifoName(WORKER_1_KEY);

    CFifo fifoSend(fifoClientName.c_str());

    int fd = open(fifoClientName.c_str(),
                    O_WRONLY,
                    0);

    char msg[5] = "1234";
    CUtil::writeMsgToFifo(fd, msg, 5);

    Epoll workerEpoll;

    std::string fifoServerName =
        CUtil::getFifoName(MASTER_1_KEY);
    workerEpoll.addFifoWriteFdInfo(fd);
    workerEpoll.addFifoFdFromServer(
            CUtil::openfileReadonlyNonblock(
                fifoServerName.c_str()));

    workerEpoll.monitor();
    return 0;
}
