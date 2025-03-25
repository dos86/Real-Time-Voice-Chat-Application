#include "Client.hpp"

Client::Client(QObject* parent)
    : QObject(parent), udpSocket(new QUdpSocket(this)), audioCapture(new AudioCapture(this)), audioPlayback(new AudioPlayback(this)) {
    connect(audioCapture, &AudioCapture::audioDataReady, this, &Client::sendAudioData);
    connect(udpSocket, &QUdpSocket::readyRead, this, &Client::receiveAudioData);
}

Client::~Client() {
    delete udpSocket;
    delete audioCapture;
    delete audioPlayback;
}

void Client::connectToServer(const QString& serverAddress, quint16 port) {
    udpSocket->bind(port, QUdpSocket::ShareAddress);
    udpSocket->joinMulticastGroup(QHostAddress(serverAddress));
    audioCapture->start();
    audioPlayback->start();
}

void Client::disconnectFromServer() {
    audioCapture->stop();
    audioPlayback->stop();
    udpSocket->leaveMulticastGroup(udpSocket->localAddress());
}

void Client::sendAudioData(const QByteArray& data) {
    udpSocket->writeDatagram(data, udpSocket->peerAddress(), udpSocket->peerPort());
}

void Client::receiveAudioData() {
    while (udpSocket->hasPendingDatagrams()) {
        QByteArray data;
        data.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(data.data(), data.size());
        emit audioPlayback->processAudioData();
    }
}
