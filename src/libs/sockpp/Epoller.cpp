#include <sys/epoll.h>
#include <unistd.h>
#include <array>
#include "Epoller.h"

const int MaxEvent = 100;

Epoller::Epoller()
: epollHndl(epoll_create1(0))
{
    if (epollHndl < 0)
    {
    }
}

Epoller::~Epoller()
{
    close(epollHndl);
}

int Epoller::poll(int timeout)
{
    std::array<epoll_event, MaxEvent> events;
    int res = epoll_wait(epollHndl, events.data(), events.size(), timeout);
    for(int i = 0; i < res; ++i)
    {
        events[i].
    }

}
