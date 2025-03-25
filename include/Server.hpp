#ifndef SERVER_HPP
#define SERVER_HPP

#include <QObject>
#include <QUdpSocket>

class Server : public QObject {
    Q_OBJECT

public:
    explicit Server(QObject* parent = nullptr);
    ~Server();

    void start(quint16 port);
    void stop();

private:
    QUdpSocket* udpSocket;

private slots:
    void processPendingDatagrams();
};

#endif // SERVER_HPP
