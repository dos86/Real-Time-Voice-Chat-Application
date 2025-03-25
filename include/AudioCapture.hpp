#ifndef AUDIOCAPTURE_HPP
#define AUDIOCAPTURE_HPP

#include <QObject>
#include <QAudioInput>
#include <QUdpSocket>

class AudioCapture : public QObject {
    Q_OBJECT

public:
    explicit AudioCapture(QObject* parent = nullptr);
    ~AudioCapture();

    void start();
    void stop();

signals:
    void audioDataReady(const QByteArray& data);

private:
    QAudioInput* audioInput;
    QUdpSocket* udpSocket;
    QIODevice* audioDevice;
};

#endif // AUDIOCAPTURE_HPP
