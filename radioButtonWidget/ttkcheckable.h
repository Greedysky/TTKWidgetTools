#ifndef TTKCHECKABLE_H
#define TTKCHECKABLE_H

#include <QObject>

class TTKCheckable : public QObject
{
    Q_OBJECT
public:
    explicit TTKCheckable(QObject *parent = nullptr);

signals:

public slots:
};

#endif // TTKCHECKABLE_H