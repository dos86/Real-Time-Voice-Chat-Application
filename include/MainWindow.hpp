#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QPushButton>
#include <QSlider>
#include <QLabel>
#include "Client.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void toggleConnection();
    void toggleMute();
    void adjustVolume(int value);

private:
    Ui::MainWindow* ui;
    QPushButton* connectButton;
    QPushButton* muteButton;
    QSlider* volumeSlider;
    QLabel* statusLabel;

    Client* client;
    bool isConnected;
    bool isMuted;
};

#endif // MAINWINDOW_HPP
