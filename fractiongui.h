#ifndef FRACTIONGUI_H
#define FRACTIONGUI_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class FractionGUI; }
QT_END_NAMESPACE

class FractionGUI : public QMainWindow
{
    Q_OBJECT

public:
    FractionGUI(QWidget *parent = nullptr);
    ~FractionGUI();
    void keyPressEvent(QKeyEvent *event);
    void clearAnswer();

private slots:
    void on_EqualsButton_clicked();
    void on_addButton_clicked();
    void on_subtractButton_clicked();
    void on_multiplyButton_clicked();
    void on_devideButton_clicked();



private:
    Ui::FractionGUI *ui;
};
#endif // FRACTIONGUI_H
