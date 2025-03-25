#include "AudioPlayback.hpp"
#include <QAudioFormat>

AudioPlayback::AudioPlayback(QObject* parent)
    : QObject(parent), audioOutput(nullptr), udpSocket(new QUdpSocket(this)) {
    QAudioFormat format;
    format.setSampleRate(44100);
    format.setChannelCount(1);
    format.setSampleSize(16);
    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::SignedInt);

    QAudioDeviceInfo deviceInfo = QAudioDeviceInfo::defaultOutputDevice();
    if (!deviceInfo.isFormatSupported(format)) {
        qWarning() << "Default format not supported, trying to use the nearest.";
        format = deviceInfo.nearestFormat(format);
    }

    audioOutput = new QAudioOutput(format, this);
}

AudioPlayback::~AudioPlayback() {
    delete audioOutput;
}

void AudioPlayback::start() {
    audioDevice = audioOutput->start();
}

void AudioPlayback::stop() {
    audioOutput->stop();
}

void AudioPlayback::processAudioData() {
    while (udpSocket->hasPendingDatagrams()) {
        QByteArray data;
        data.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(data.data(), data.size());
        audioDevice->write(data);
    }
}
