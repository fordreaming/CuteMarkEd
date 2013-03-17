#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "markdownparser.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    parser(new MarkdownParser())
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete parser;
    delete ui;
}

void MainWindow::fileNew()
{
    ui->plainTextEdit->clear();
}

void MainWindow::plainTextChanged()
{
    QString code = ui->plainTextEdit->toPlainText();

    QString html = parser->renderAsHtml(code);
    ui->webView->setHtml(html);
}
