//
// Copyright(c) 2026 ZGTeam233.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>

class MainWindow : public QMainWindow {
    Q_OBJECT // 必须有， 为了信号槽

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override = default;

private:
    QLabel *label;
    QPushButton *button;

}; // MainWindow

#endif // MAINWINDOW_H
