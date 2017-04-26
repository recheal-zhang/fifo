#include <unistd.h>

#include <iostream>
#include <string>

#include "Util.h"
#include "Define.h"
#include "Fifo.h"

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
    while(true){
        CUtil::writeMsgToFifo(fd, msg, 5);
        sleep(1);
    }

    return 0;
}
