#include <QMessageBox>
#include <QVBoxLayout>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    // 设置窗口基本属性
    setWindowTitle("纯 C++ Qt6 应用");
    resize(400,300);

    // QMainWindow 需要一个中心部件 (Central Widget) 来承载内容
    QWidget *centralWidget = new QWidget(this); // this 作为 parent
    setCentralWidget(centralWidget);

    // 创建控件 (注意：都要把 centralWidget 作为 parent)
    label = new QLabel("Hello, C++ Qt!", centralWidget);
    label->setAlignment(Qt::AlignCenter); // 文本居中
    label->setStyleSheet("font-size: 20px; color: #2c3e50; font-weight: bold;");

    button = new QPushButton("点我改变文字", centralWidget);
    button->setStyleSheet("font-size: 20px; background-color: #3498db; color: white; border-radius: 5px;");

    // 使用布局管理器排列控件 (告别绝对坐标)
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    layout->addWidget(label);
    layout->addStretch(); // 增加弹性空间，把按钮挤到底部
    layout->addWidget(button);

    // 设置一点边距, 好看些
    layout->setContentsMargins(20,20,20,20);

    // 绑定信号与槽 (Lambda 风格)
    int clickCount = 0;
    connect(button, &QPushButton::clicked, this, [this, clickCount]() mutable {
        // 每次点击, 修改 Label 文字
        label->setText(QString("你点击了 %1 次！").arg(++clickCount));
        // 改变 Label 颜色
        label->setStyleSheet("font-size: 20px; color: #e74c3c; font-weight: bold;");
    });
}