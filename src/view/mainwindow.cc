#include "mainwindow.h"

#include <QMessageBox>

#include "../controller/controller.h"
#include "../model/model.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  setWindowTitle("SmartCalc");
  setWindowOpacity(0.993);
  button_flag = 1;

  ui->widget->xAxis->setRange(-5, 5);
  ui->widget->yAxis->setRange(-5, 5);
  resize(0, 0);
  //  ui->widget->xAxis->setLabel("x");
  //  ui->widget->yAxis->setLabel("y");
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_size_clicked() {
  if (button_flag > 0)
    resize(1200, 1200);
  else
    resize(0, 0);

  button_flag *= -1;
}

void MainWindow::on_pushButton_eq_clicked() {
  std::string input = ui->lineEdit->text().toUtf8().constData();
  Controller controller;
  double x = ui->line_X->text().toDouble();
  ui->lineEdit->setText(QString::fromStdString(controller.proccess(input, x)));
}

void MainWindow::on_pushButton_graph_clicked() {
  std::string input = ui->lineEdit->text().toUtf8().constData();
  double xmin = ui->lineEdit_xmin->text().toDouble();
  double xmax = ui->lineEdit_xmax->text().toDouble();
  double ymin = ui->lineEdit_ymin->text().toDouble();
  double ymax = ui->lineEdit_ymax->text().toDouble();
  Controller controller;
  if (controller.checkString(input)) {
    ui->widget->clearGraphs();
    ui->widget->addGraph();
    ui->widget->graph(0)->setPen(QPen(Qt::blue));
    ui->widget->xAxis->setRange(xmin, xmax);
    ui->widget->yAxis->setRange(ymin, ymax);
    ui->widget->xAxis->setLabel("x");
    ui->widget->yAxis->setLabel("y");
    ui->widget->replot();
    double h =
        xmax - xmin > ymax - ymin ? (xmax - xmin) / 500 : (ymax - ymin) / 500;
    double xBegin = xmin;
    double xEnd = xmax + h;
    QVector<double> x, y;
    for (double i = xBegin; i < xEnd; i += h) {
      x.push_back(i);
      y.push_back(controller.proccessGraph(i));
    }
    ui->widget->graph(0)->setData(x, y);
    ui->widget->replot();
  } else {
    ui->lineEdit->setText("error");
  }
}

void MainWindow::on_pushButton_clicked() { ui->lineEdit->insert("4"); }

void MainWindow::on_pushButton_8_clicked() { ui->lineEdit->insert("1"); }

void MainWindow::on_pushButton_7_clicked() { ui->lineEdit->insert("2"); }

void MainWindow::on_pushButton_2_clicked() { ui->lineEdit->insert("3"); }

void MainWindow::on_pushButton_9_clicked() { ui->lineEdit->insert("5"); }

void MainWindow::on_pushButton_5_clicked() { ui->lineEdit->insert("6"); }

void MainWindow::on_pushButton_3_clicked() { ui->lineEdit->insert("7"); }

void MainWindow::on_pushButton_6_clicked() { ui->lineEdit->insert("8"); }

void MainWindow::on_pushButton_4_clicked() { ui->lineEdit->insert("9"); }

void MainWindow::on_pushButton_10_clicked() { ui->lineEdit->insert("0"); }

void MainWindow::on_pushButton_14_clicked() { ui->lineEdit->insert("+"); }

void MainWindow::on_pushButton_13_clicked() { ui->lineEdit->insert("-"); }

void MainWindow::on_pushButton_12_clicked() { ui->lineEdit->insert("*"); }

void MainWindow::on_pushButton_div_clicked() { ui->lineEdit->insert("/"); }

void MainWindow::on_pushButton_18_clicked() {
  ui->lineEdit->setText("");
  ui->lineEdit->setPlaceholderText("0");
}

void MainWindow::on_pushButton_16_clicked() { ui->lineEdit->insert("."); }

void MainWindow::on_pushButton_log_clicked() { ui->lineEdit->insert("log("); }

void MainWindow::on_pushButton_ln_clicked() { ui->lineEdit->insert("ln("); }

void MainWindow::on_pushButton_tan_clicked() { ui->lineEdit->insert("tan("); }

void MainWindow::on_pushButton_atan_clicked() { ui->lineEdit->insert("atan("); }

void MainWindow::on_pushButton_acos_clicked() { ui->lineEdit->insert("acos("); }

void MainWindow::on_pushButton_cos_clicked() { ui->lineEdit->insert("cos("); }

void MainWindow::on_pushButton_sin_clicked() { ui->lineEdit->insert("sin("); }

void MainWindow::on_pushButton_asin_clicked() { ui->lineEdit->insert("asin("); }

void MainWindow::on_pushButton_sqrt_clicked() { ui->lineEdit->insert("sqrt("); }

void MainWindow::on_pushButton_mod_clicked() { ui->lineEdit->insert("%"); }

void MainWindow::on_pushButton_bracket_open_clicked() {
  ui->lineEdit->insert("(");
}

void MainWindow::on_pushButton_bracket_close_clicked() {
  ui->lineEdit->insert(")");
}

void MainWindow::on_pushButton_exp_clicked() { ui->lineEdit->insert("^"); }

void MainWindow::on_pushButton_x_clicked() { ui->lineEdit->insert("x"); }
