#include "MainWindow.hpp"
#include <QVBoxLayout>
#include <QSlider>
#include <QPushButton>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), isConnected(false), isMuted(false) {
    QWidget* centralWidget = new QWidget(this);
    QVBoxLayout* layout = new QVBoxLayout(centralWidget);

    connectButton = new QPushButton("Connect", this);
    muteButton = new QPushButton("Mute", this);
    volumeSlider = new QSlider(Qt::Horizontal, this);
    volumeSlider->setRange(0, 100);
    volumeSlider->setValue(50);
    statusLabel = new QLabel("Disconnected", this);

    layout->addWidget(connectButton);
    layout->addWidget(muteButton);
    layout->addWidget(volumeSlider);
    layout->addWidget(statusLabel);

    setCentralWidget(centralWidget);

    client = new Client(this);

    connect(connectButton, &QPushButton::clicked, this, &MainWindow::toggleConnection);
    connect(muteButton, &QPushButton::clicked, this, &MainWindow::toggleMute);
    connect(volumeSlider, &QSlider::valueChanged, this, &MainWindow::adjustVolume);
}

void MainWindow::adjustVolume(int value) {
    client->setVolume(value); // Pass volume value to the client
}
