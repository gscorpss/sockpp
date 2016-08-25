#ifndef EPOLLER.h
#define EPOLLER.h

class Epoller
{
public:
    Epoller();
    ~Epoller();
    int poll(int timeout);
private:
    int epollHndl;
};

#endif //EPOLLER.h