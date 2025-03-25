#ifndef AUDIOPLAYBACK_HPP
#define AUDIOPLAYBACK_HPP

#include <QObject>
#include <QAudioOutput>
#include <QUdpSocket>

class AudioPlayback : public QObject {
    Q_OBJECT

public:
    explicit AudioPlayback(QObject* parent = nullptr);
    ~AudioPlayback();

    void start();
    void stop();

public slots:
    void processAudioData();

private:
    QAudioOutput* audioOutput;
    QUdpSocket* udpSocket;
    QIODevice* audioDevice;
};

#endif // AUDIOPLAYBACK_HPP
