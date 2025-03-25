#include "AudioCapture.hpp"
#include <QAudioFormat>

AudioCapture::AudioCapture(QObject* parent)
    : QObject(parent), audioInput(nullptr), udpSocket(new QUdpSocket(this)) {
    QAudioFormat format;
    format.setSampleRate(44100);
    format.setChannelCount(1);
    format.setSampleSize(16);
    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::SignedInt);

    QAudioDeviceInfo deviceInfo = QAudioDeviceInfo::defaultInputDevice();
    if (!deviceInfo.isFormatSupported(format)) {
        qWarning() << "Default format not supported, trying to use the nearest.";
        format = deviceInfo.nearestFormat(format);
    }

    audioInput = new QAudioInput(format, this);
}

AudioCapture::~AudioCapture() {
    delete audioInput;
}

void AudioCapture::start() {
    audioDevice = audioInput->start();
    connect(audioDevice, &QIODevice::readyRead, this, [this]() {
        QByteArray data = audioDevice->readAll();
        emit audioDataReady(data);
    });
}

void AudioCapture::stop() {
    audioInput->stop();
}
