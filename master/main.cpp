#include <iostream>
#include <string>

#include "Epoll.h"
#include "Util.h"
#include "Define.h"

using namespace std;

int main(){
    cout << "hello master" << endl;

    Epoll epollController;

//    epollController.addFifofdFromClient(
//            CUtil::openfileReadonlyNonblock(
//                (CUtil::getFifoName(WORKER_1_KEY)).c_str()));

    std::string fifoClientName =
        CUtil::getFifoName(WORKER_1_KEY);

    epollController.addFifoFdFromClient(
            CUtil::openfileReadonlyNonblock(
                fifoClientName.c_str()));

    epollController.monitor();

    return 0;
}
