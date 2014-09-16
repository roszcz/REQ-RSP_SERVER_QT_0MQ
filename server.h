#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <zmq.hpp>


class server : public QObject
{
    Q_OBJECT
    int clicker;

public:
    explicit server(QObject *parent = 0);

signals:

public slots:
    void runServerRun();

};

#endif // SERVER_H
