#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <QObject>
#include <QUdpSocket>
#include "AudioCapture.hpp"
#include "AudioPlayback.hpp"

class Client : public QObject {
    Q_OBJECT

public:
    explicit Client(QObject* parent = nullptr);
    ~Client();

    void connectToServer(const QString& serverAddress, quint16 port);
    void disconnectFromServer();

private:
    QUdpSocket* udpSocket;
    AudioCapture* audioCapture;
    AudioPlayback* audioPlayback;

private slots:
    void sendAudioData(const QByteArray& data);
    void receiveAudioData();
};

#endif // CLIENT_HPP
