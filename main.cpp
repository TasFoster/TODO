#include "mainwindow.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QFont>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFont appFont("Segoe UI", 10);
    a.setFont(appFont);

    // Глобальные стили (только то, что не задано в .ui)
    a.setStyleSheet(R"(
        QToolTip {
            background-color: #252535;
            color: #e2e8f0;
            border: 1px solid #3d3d55;
            border-radius: 4px;
            padding: 4px 8px;
        }
    )");

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Todo_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    MainWindow w;
    w.show();
    return a.exec();
}
