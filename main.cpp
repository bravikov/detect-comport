#include <QApplication>
#include <QSystemTrayIcon>
#include "qextserialenumerator.h"
#include <QString>
#include <QMenu>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString messageTitle("Обнаружение COM-портов");

    QSystemTrayIcon tray(QIcon(":/detect-comport.ico"), &a);
    tray.setToolTip(messageTitle);

    QMenu menu(messageTitle);
    auto exitAction = menu.addAction("Выйти");

    a.connect(exitAction, &QAction::triggered, [&a](bool){
        a.quit();
    });

    tray.setContextMenu(&menu);

    QextSerialEnumerator en;
    en.setUpNotifications();

    a.connect(&en, &QextSerialEnumerator::deviceDiscovered,
              [&](const QextPortInfo & info){
        tray.showMessage(messageTitle, "Подключен " + info.portName);
    });

    a.connect(&en, &QextSerialEnumerator::deviceRemoved,
              [&](const QextPortInfo & info){
        tray.showMessage(messageTitle, "Отключен " + info.portName);
    });

    tray.show();

    return a.exec();
}
