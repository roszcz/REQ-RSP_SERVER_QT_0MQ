#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QThread>
#include <zmq.hpp>

class client : public QObject
{
    Q_OBJECT
    zmq::context_t c_context;
    zmq::socket_t c_socket;

public:
    explicit client(QObject *parent = 0);

signals:

public slots:
    void goConnect();
    void sendMsg();

};

#endif // CLIENT_H
