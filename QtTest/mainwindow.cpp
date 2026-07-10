//
// Copyright(c) 2026 ZGTeam233.
//

#include <QMessageBox>
#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this); // 执行 UI 翻译过来的 C++ 代码

    // 逻辑层：绑定信号与槽 (Android 里的 setOnClickListener)
    // 当 myButton 被点击时，弹出一个提示框
    connect(ui->myButton, &QPushButton::clicked, this, [this]() {
        QMessageBox::information(this, "提示", "Hello from Android dev!\nUI 和逻辑分离真爽！");
    });
}

MainWindow::~MainWindow() {
    delete ui;
}
