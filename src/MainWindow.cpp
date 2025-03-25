#include "MainWindow.hpp"
#include <QVBoxLayout>

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

MainWindow::~MainWindow() {
    delete client;
}

void MainWindow::toggleConnection() {
    if (isConnected) {
        client->disconnectFromServer();
        connectButton->setText("Connect");
        statusLabel->setText("Disconnected");
        isConnected = false;
    } else {
        client->connectToServer("239.255.43.21", 45454); // Example multicast address
        connectButton->setText("Disconnect");
        statusLabel->setText("Connected");
        isConnected = true;
    }
}

void MainWindow::toggleMute() {
    isMuted = !isMuted;
    muteButton->setText(isMuted ? "Unmute" : "Mute");
}

void MainWindow::adjustVolume(int value) {
    // Adjust playback volume here
    qDebug() << "Volume:" << value;
}
