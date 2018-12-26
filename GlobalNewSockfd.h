//
// Created by daniel on 20/12/18.
//

#ifndef PROJECT_GLOBALNEWSOCKFD_H
#define PROJECT_GLOBALNEWSOCKFD_H


class GlobalNewSockfd {
private:
    int newsockfdServer;
    int sockfdClient;
    static GlobalNewSockfd *newSockfd_instance;

public:
    GlobalNewSockfd();
    int getSockServer()
    {
        return newsockfdServer;
    }
    void setSockServer(int val)
    {
        newsockfdServer = val;
    }
    int getSockClient()
    {
        return sockfdClient;
    }
    void setSockClient(int val)
    {
        sockfdClient = val;
    }

    static GlobalNewSockfd *instance();

};


#endif //PROJECT_GLOBALNEWSOCKFD_H
