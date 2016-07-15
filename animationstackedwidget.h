#ifndef WIDGET1_H
#define WIDGET1_H

#include <QVariant>
#include <QStackedWidget>
#include <QPropertyAnimation>

class AnimationStackedWidget : public QStackedWidget
{
    Q_OBJECT
public:
    enum AnimationType
    {
        TopToBottom,
        BottomToTop,
        LeftToRight,
        RightToLeft
    };

    explicit AnimationStackedWidget(QWidget *parent = 0);
    virtual ~AnimationStackedWidget();

    void start(int index);
    void setLength(int length, AnimationType type);
    void setDuration(int duration);

signals:

private slots:
    void valueChanged(const QVariant &value);
    void animationFinished();

protected:
    virtual void paintEvent(QPaintEvent *event);

    float m_changeValue;
    bool m_isAnimating;
    int m_curIndex;
    AnimationType m_type;
    QPropertyAnimation *m_animation;

};

#endif // WIDGET1_H
