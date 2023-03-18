#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <qcustomplot.h>

#include <QMainWindow>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

/// @brief class MainWindow contains all slots and signals for view
class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  /// @brief default constructor
  MainWindow(QWidget *parent = nullptr);
  /// @brief default destructor
  ~MainWindow();

 private slots:
  void on_pushButton_clicked();

  void on_pushButton_8_clicked();

  void on_pushButton_7_clicked();

  void on_pushButton_2_clicked();

  void on_pushButton_9_clicked();

  void on_pushButton_5_clicked();

  void on_pushButton_3_clicked();

  void on_pushButton_6_clicked();

  void on_pushButton_4_clicked();

  void on_pushButton_10_clicked();

  void on_pushButton_eq_clicked();

  void on_pushButton_14_clicked();

  void on_pushButton_13_clicked();

  void on_pushButton_12_clicked();

  void on_pushButton_div_clicked();

  void on_pushButton_18_clicked();

  void on_pushButton_16_clicked();

  void on_pushButton_log_clicked();

  void on_pushButton_ln_clicked();

  void on_pushButton_tan_clicked();

  void on_pushButton_atan_clicked();

  void on_pushButton_acos_clicked();

  void on_pushButton_cos_clicked();

  void on_pushButton_sin_clicked();

  void on_pushButton_asin_clicked();

  void on_pushButton_sqrt_clicked();

  void on_pushButton_mod_clicked();

  void on_pushButton_bracket_open_clicked();

  void on_pushButton_bracket_close_clicked();

  void on_pushButton_exp_clicked();

  void on_pushButton_graph_clicked();

  void on_pushButton_x_clicked();

  void on_pushButton_size_clicked();

 private:
  Ui::MainWindow *ui;
  double xBegin, xEnd, h, X;
  int button_flag;

  QVector<double> x, y;
};
#endif  // MAINWINDOW_H
