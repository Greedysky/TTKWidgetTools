#include "ttkpicturebannerwidget.h"

#include <QTimer>
#include <QPainter>
#include <QBoxLayout>
#include <QMouseEvent>
#include <QPropertyAnimation>

const QColor frontColor = QColor(220, 0, 0);
const QColor backColor = QColor(200, 200, 200);

TTKPictureBannerArrowWidget::TTKPictureBannerArrowWidget(ArrowType type, QWidget *parent)
    : QWidget(parent)
{
    m_bMouseHover = false;
    m_bMousePress = false;
    m_type = type;
    setFixedSize(12, 20);
}

#if TTK_QT_VERSION_CHECK(6,0,0)
void TTKPictureBannerArrowWidget::enterEvent(QEnterEvent *event)
#else
void TTKPictureBannerArrowWidget::enterEvent(QEvent *event)
#endif
{
    Q_UNUSED(event);
    m_bMouseHover = true;
    update();
}

void TTKPictureBannerArrowWidget::leaveEvent(QEvent *event)
{
    Q_UNUSED(event);
    m_bMouseHover = false;
    update();
}

void TTKPictureBannerArrowWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        m_bMousePress = true;
        emit clicked();
    }
}

void TTKPictureBannerArrowWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        m_bMousePress = false;
    }
}

void TTKPictureBannerArrowWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QPen pen;
    pen.setWidth(3);
    pen.setBrush(m_bMouseHover ? QColor(255, 255, 255) : QColor(150, 150, 150));
    painter.setPen(pen);

    int margin = 2;
    switch(m_type)
    {
        case Right:
        {
            painter.drawLine(QPointF(margin, margin), QPointF(width()-margin, height()/2));
            painter.drawLine(QPointF(margin, height()-margin), QPointF(width()-margin, height()/2));
            break;
        }
        case Left:
        {
            painter.drawLine(QPointF(width()-margin, margin), QPointF(margin, height()/2));
            painter.drawLine(QPointF(width()-margin, height()-margin), QPointF(margin, height()/2));
            break;
        }
        default: break;
    }
}



TTKPictureBannerIndicator::TTKPictureBannerIndicator(QWidget *parent)
    : QWidget(parent)
{
    m_selected = false;
}

void TTKPictureBannerIndicator::select(bool selected)
{
    m_selected = selected;
    update();
}

#if TTK_QT_VERSION_CHECK(6,0,0)
void TTKPictureBannerIndicator::enterEvent(QEnterEvent *event)
#else
void TTKPictureBannerIndicator::enterEvent(QEvent *event)
#endif
{
    Q_UNUSED(event);
    emit entered();
}

void TTKPictureBannerIndicator::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setPen(Qt::NoPen);
    painter.setBrush(QBrush(m_selected ? frontColor : backColor));
    painter.drawRect(rect());
}



TTKPictureBannerPage::TTKPictureBannerPage(QWidget *parent)
    : QLabel(parent)
{
    m_bActive = false;
}

void TTKPictureBannerPage::setActive(bool active)
{
    m_bActive = active;
}

void TTKPictureBannerPage::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        emit clicked();
    }
}

void TTKPictureBannerPage::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QLabel::paintEvent(event);

    if(!m_bActive)
    {
        QPainter painter(this);
        painter.setPen(Qt::NoPen);
        painter.setBrush(QColor(10,10,10, 100));
        painter.drawRect(rect());
    }
}



TTKPictureBannerView::TTKPictureBannerView(QWidget *parent)
    : QWidget(parent)
{
    m_size = QSize(540, 200);

    m_leftPage = new TTKPictureBannerPage(this);
    m_centerPage = new TTKPictureBannerPage(this);
    m_centerPage->setActive(true);
    m_rightPage = new TTKPictureBannerPage(this);

    connect(m_leftPage, SIGNAL(clicked()), this, SLOT(slotPageClicked()));
    connect(m_centerPage, SIGNAL(clicked()), this, SLOT(slotPageClicked()));
    connect(m_rightPage, SIGNAL(clicked()), this, SLOT(slotPageClicked()));

    m_leftAnimation = new QPropertyAnimation(m_leftPage, "geometry");
    m_leftAnimation->setDuration(200);
    m_leftAnimation->setEasingCurve(QEasingCurve::Linear);

    m_centerAnimation = new QPropertyAnimation(m_centerPage, "geometry");
    m_centerAnimation->setDuration(200);
    m_centerAnimation->setEasingCurve(QEasingCurve::Linear);

    m_rightAnimation = new QPropertyAnimation(m_rightPage, "geometry");
    m_rightAnimation->setDuration(200);
    m_rightAnimation->setEasingCurve(QEasingCurve::Linear);

    m_centerPage->setFixedSize(m_size);
    m_leftPage->setMinimumWidth(m_size.width() / 4);
    m_leftPage->setMaximumWidth(m_size.width() * 2 / 3);
    m_leftPage->setFixedHeight(m_size.height() - 12);
    m_rightPage->setMinimumWidth(m_size.width() / 4);
    m_rightPage->setMaximumWidth(m_size.width() * 2 / 3);
    m_rightPage->setFixedHeight(m_size.height() - 12);

    m_leftArrow = new TTKPictureBannerArrowWidget(TTKPictureBannerArrowWidget::Left, this);
    m_rightArrow = new TTKPictureBannerArrowWidget(TTKPictureBannerArrowWidget::Right, this);
    setArrowHidden(true);
    connect(m_leftArrow, SIGNAL(clicked()), this, SLOT(slotArrowClicked()));
    connect(m_rightArrow, SIGNAL(clicked()), this, SLOT(slotArrowClicked()));

    QHBoxLayout *layout = new QHBoxLayout();
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addStretch(1);
    layout->addWidget(m_leftPage, 0, Qt::AlignBottom);
    layout->addWidget(m_centerPage, 0, Qt::AlignBottom);
    layout->addWidget(m_rightPage, 0, Qt::AlignBottom);
    layout->addStretch(1);
    setLayout(layout);
}

TTKPictureBannerView::~TTKPictureBannerView()
{
    delete m_leftPage;
    delete m_centerPage;
    delete m_rightPage;
    delete m_leftArrow;
    delete m_rightArrow;
    delete m_leftAnimation;
    delete m_centerAnimation;
    delete m_rightAnimation;
}

void TTKPictureBannerView::setLeftPixmap(const QPixmap &pixmap)
{
    setPagePixmap(m_leftPage, pixmap);
}

void TTKPictureBannerView::setCenterPixmap(const QPixmap &pixmap)
{
    setPagePixmap(m_centerPage, pixmap);
}

void TTKPictureBannerView::setRightPixmap(const QPixmap &pixmap)
{
    setPagePixmap(m_rightPage, pixmap);
}

void TTKPictureBannerView::startAnimation(int direction)
{
    const QRect &leftRect = m_leftPage->geometry();
    const QRect &centerRect = m_centerPage->geometry();
    const QRect &rightRect = m_rightPage->geometry();
    const QRect &tmpRect = QRect(centerRect.x(), centerRect.y() + 12, centerRect.width(), centerRect.height() - 12);

    if(direction < 0)
    {
        m_leftAnimation->setStartValue(rightRect);
        m_leftAnimation->setEndValue(leftRect);
        m_centerAnimation->setStartValue(leftRect);
        m_centerAnimation->setEndValue(centerRect);
        m_rightAnimation->setStartValue(tmpRect);
        m_rightAnimation->setEndValue(rightRect);

    }
    else if(direction > 0)
    {
        m_leftAnimation->setStartValue(tmpRect);
        m_leftAnimation->setEndValue(leftRect);
        m_centerAnimation->setStartValue(rightRect);
        m_centerAnimation->setEndValue(centerRect);
        m_rightAnimation->setStartValue(leftRect);
        m_rightAnimation->setEndValue(rightRect);
    }

    m_rightAnimation->start();
    m_centerAnimation->start();
    m_leftAnimation->start();
}

void TTKPictureBannerView::slotPageClicked()
{
    TTKPictureBannerPage *page = qobject_cast<TTKPictureBannerPage*>(sender());
    if(page == nullptr)
    {
        return;
    }

    int flag = 0;
    if(page == m_leftPage)
    {
        flag = -1;
    }
    else if(page == m_rightPage)
    {
        flag = 1;
    }
    emit clicked(flag);
}

void TTKPictureBannerView::slotArrowClicked()
{
    TTKPictureBannerArrowWidget *arrow = qobject_cast<TTKPictureBannerArrowWidget*>(sender());
    if(arrow == nullptr)
    {
        return;
    }

    if(arrow == m_leftArrow)
    {
        emit clicked(-1);
    }
    else if(arrow == m_rightArrow)
    {
        emit clicked(1);
    }
}

#if TTK_QT_VERSION_CHECK(6,0,0)
void TTKPictureBannerView::enterEvent(QEnterEvent *event)
#else
void TTKPictureBannerView::enterEvent(QEvent *event)
#endif
{
    Q_UNUSED(event);
    setArrowHidden(false);
}

void TTKPictureBannerView::leaveEvent(QEvent *event)
{
    Q_UNUSED(event);
    setArrowHidden(true);
}

void TTKPictureBannerView::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QWidget::paintEvent(event);
}

void TTKPictureBannerView::setPagePixmap(TTKPictureBannerPage *page, const QPixmap &pixmap)
{
    if(page)
    {
        page->setPixmap(pixmap.scaled(m_size, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    }
}

void TTKPictureBannerView::setArrowHidden(bool hidden)
{
    m_leftArrow->setHidden(hidden);
    m_rightArrow->setHidden(hidden);

    if(!hidden)
    {
        m_leftArrow->move(m_leftPage->x() + 8, m_leftPage->y() + (m_leftPage->height() - m_leftArrow->height()) / 2);
        m_rightArrow->move(m_rightPage->x() + m_rightPage->width() - m_rightArrow->width() - 8,
                           m_rightPage->y() + (m_rightPage->height() - m_rightArrow->height()) / 2);
        m_leftArrow->raise();
        m_rightArrow->raise();
    }
}




TTKPictureBannerWidget::TTKPictureBannerWidget(QWidget *parent)
    : QWidget(parent)
{
    m_view = 0;
    m_indLayout = 0;
    m_indicators.clear();
    m_pixmaps.clear();
    m_currentIndex = -1;
    m_timer = 0;
    m_interval = 2000;

    initialize();
}

void TTKPictureBannerWidget::addPage(const QPixmap &pixmap)
{
    m_pixmaps.append(pixmap);

    TTKPictureBannerIndicator *ind = new TTKPictureBannerIndicator();
    ind->setFixedSize(18, 3);
    connect(ind, SIGNAL(entered()), this, SLOT(switchIndicator()));
    m_indicators.append(ind);
    m_indLayout->addWidget(ind);

    if(m_currentIndex == -1)
    {
        m_currentIndex = 0;
        m_indicators.at(m_currentIndex)->select(true);
    }
    play(m_currentIndex);
}

void TTKPictureBannerWidget::addPages(const QList<QPixmap> &pixmaps)
{
    for(const QPixmap &pixmap : qAsConst(pixmaps))
    {
        addPage(pixmap);
    }
}

void TTKPictureBannerWidget::startAutoPlay()
{
    m_timer->start(m_interval);
}

void TTKPictureBannerWidget::stopAutoPlay()
{
    m_timer->stop();
}

void TTKPictureBannerWidget::setDelayTime(int msec, bool start)
{
    if(msec < 500 || msec > 10000)
    {
        return;
    }

    m_interval = msec;
    if(start)
    {
        startAutoPlay();
    }
}

QSize TTKPictureBannerWidget::sizeHint() const
{
    return QSize(600, 180);
}

void TTKPictureBannerWidget::switchIndicator()
{
    TTKPictureBannerIndicator *ind = qobject_cast<TTKPictureBannerIndicator*>(sender());
    if(ind == 0)
    {
        return;
    }

    int index = m_indicators.indexOf(ind);
    if(index == m_currentIndex)
    {
        return;
    }

    if(m_currentIndex != -1)
    {
        m_indicators.at(m_currentIndex)->select(false);
    }

    int flag = 0;
    if(m_currentIndex < index)
    {
        flag = 1;
    }
    else if(m_currentIndex > index)
    {
        flag = -1;
    }

    m_currentIndex = index;
    m_indicators.at(m_currentIndex)->select(true);

    play(m_currentIndex);
    m_view->startAnimation(flag);
}

void TTKPictureBannerWidget::switchPage(int flag)
{
    if(m_currentIndex == -1)
    {
        return;
    }

    if(flag == 0)
    {
        emit currentClicked(m_currentIndex);
        return;
    }

    int count = m_indicators.count();
    if(count < 2)
    {
        return;
    }
    m_indicators.at(m_currentIndex)->select(false);
    m_currentIndex += flag;

    if(m_currentIndex == -1)
    {
        m_currentIndex = count - 1;
    }
    else if(m_currentIndex == count)
    {
        m_currentIndex = 0;
    }

    m_indicators.at(m_currentIndex)->select(true);

    play(m_currentIndex);
    m_view->startAnimation(flag);
}

void TTKPictureBannerWidget::updateRender()
{
    switchPage(1);
}

void TTKPictureBannerWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
}

void TTKPictureBannerWidget::initialize()
{
    m_indLayout = new QHBoxLayout();
    m_indLayout->setSpacing(5);
    m_view = new TTKPictureBannerView();
    connect(m_view, SIGNAL(clicked(int)), this, SLOT(switchPage(int)));

    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), SLOT(updateRender()));

    QHBoxLayout *bottomLayout = new QHBoxLayout();
    bottomLayout->setSpacing(0);
    bottomLayout->setContentsMargins(0, 0, 0, 0);
    bottomLayout->addStretch();
    bottomLayout->addLayout(m_indLayout);
    bottomLayout->addStretch();

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(m_view);
    layout->addLayout(bottomLayout);
    setLayout(layout);
}

void TTKPictureBannerWidget::play(int index)
{
    if(index < 0)
    {
        return;
    }

    int count = m_indicators.count();
    int leftIndex = 0, rightIndex = 0;
    if(count > 1)
    {
        if(index == 0)
        {
            leftIndex = count - 1;
            rightIndex = index + 1;
        }
        else if(index == count -1)
        {
            leftIndex = index - 1;
            rightIndex = 0;
        }
        else
        {
            leftIndex = index - 1;
            rightIndex = index + 1;
        }
    }

    m_view->setLeftPixmap(m_pixmaps.at(leftIndex));
    m_view->setCenterPixmap(m_pixmaps.at(index));
    m_view->setRightPixmap(m_pixmaps.at(rightIndex));
}
