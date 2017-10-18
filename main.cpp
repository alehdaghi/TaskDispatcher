#include <iostream>
#include <functional>
#include <tr1/memory>
#include <bitset>
#include <zconf.h>
#include "AsyncDispatcher.h"
#include "ThreadDispatcher.h"

using namespace std;

std::string syncTask1(int a){ // calculate binary of int by string in 16 bits
    sleep(2);// simulate time consuming
    return std::bitset<16>(a).to_string();;
}

int syncTask2(std::string str){ // calculate the size of a string
    sleep(3);// simulate time consuming
    return str.size();
}


std::shared_ptr<AsyncDispatcher> dispatcher = std::shared_ptr<AsyncDispatcher>(new AsyncDispatcher);


int main() {


    ThreadDispatcher::pushDispatcher
            (std::shared_ptr<AsyncDispatcher>(new AsyncDispatcher));

    dispatcher->dispatch([]{
        printf("dispatcher1  bin of 150 is : %s\n", syncTask1(150).c_str());
    });

    dispatcher->dispatch([]{
        printf("dispatcher1 bin of 200 is: %s\n", syncTask1(150).c_str());
    });

    ThreadDispatcher::peekDispatcher()->dispatch([]{
        printf("dispatcher2 len of 111: %d\n", syncTask2("111"));
    });

    ThreadDispatcher::peekDispatcher()->dispatch([]{
        printf("dispatcher2 len of 222: %d\n", syncTask2("222"));
    });

    ThreadDispatcher::pushDispatcher
            (std::shared_ptr<AsyncDispatcher>(new AsyncDispatcher));

    ThreadDispatcher::peekDispatcher()->dispatch([]{
        printf("dispatcher3 len of 333: %d\n", syncTask2("333"));
    });

    printf("in main thread\n");

    ThreadDispatcher::popDispatcher(); // main thread waits until all task of dispatcher 3 to be done!

    printf("in main thread, after removing a dispatcher!\n");

    return 0;
}
