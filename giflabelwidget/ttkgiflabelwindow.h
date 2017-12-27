#ifndef TTKGIFLABELWINDOW_H
#define TTKGIFLABELWINDOW_H

#include <QMainWindow>

namespace Ui {
class TTKGifLabelWindow;
}

class TTKGifLabelWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit TTKGifLabelWindow(QWidget *parent = nullptr);
    ~TTKGifLabelWindow();

private:
    Ui::TTKGifLabelWindow *ui;

};

#endif // TTKGIFLABELWINDOW_H
