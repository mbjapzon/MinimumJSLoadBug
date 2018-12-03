#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QWebChannel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFile file(":/templates/sample.html");

    if (!file.open(QIODevice::ReadOnly))
         return;

    QString content = QString::fromUtf8(file.readAll());

    m_guideView = new QWebEngineView(this);
    m_guideView->setHtml(content, QUrl("qrc:/"));

    m_guideView->resize(1024, 750);
    m_guideView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_guideView;
}

