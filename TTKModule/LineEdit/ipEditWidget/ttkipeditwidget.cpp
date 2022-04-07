#include "ttkipeditwidget.h"

#include <QPainter>
#include <QApplication>
#include <QKeyEvent>
#include <QClipboard>
#if TTK_QT_VERSION_CHECK(6,0,0)
#  include <QRegularExpressionValidator>
#else
#  include <QRegExpValidator>
#endif
#include <QStyleOptionButton>

TTKIpEditWidget::TTKIpEditWidget(QWidget *parent)
    : QWidget(parent)
{
    m_layout = new QHBoxLayout(this);
    m_layout->setSpacing(3);
    m_layout->setContentsMargins(2, 0, 2, 0);

    m_input_f = new QLineEdit(this);
    m_input_s = new QLineEdit(this);
    m_input_t = new QLineEdit(this);
    m_input_l = new QLineEdit(this);

    initialize(m_input_f);
    initialize(m_input_s);
    initialize(m_input_t);
    initialize(m_input_l);

    m_dot_f = new QLabel(".", this);
    m_dot_s = new QLabel(".", this);
    m_dot_t = new QLabel(".", this);

    m_layout->addWidget(m_input_f, 1);
    m_layout->addWidget(m_dot_f);
    m_layout->addWidget(m_input_s, 1);
    m_layout->addWidget(m_dot_s);
    m_layout->addWidget(m_input_t, 1);
    m_layout->addWidget(m_dot_t);
    m_layout->addWidget(m_input_l, 1);

    setFixedSize(165, 25);
}

void TTKIpEditWidget::initialize(QLineEdit *edit)
{
    edit->setFrame(false);
    edit->setAlignment(Qt::AlignCenter);
    edit->installEventFilter(this);

    const QString regx("^(2[0-4]\\d|25[0-5]|[01]?\\d\\d?)$");
#if TTK_QT_VERSION_CHECK(6,0,0)
    QRegularExpressionValidator *validator = new QRegularExpressionValidator(QRegularExpression(regx), this);
#else
    QRegExpValidator *validator = new QRegExpValidator(QRegExp(regx), this);
#endif
    edit->setValidator(validator);

    connect(edit, SIGNAL(textChanged(QString)), SLOT(editTextChanged(QString)));
}

QLineEdit *TTKIpEditWidget::nextEdit(QLineEdit *edit)
{
    if(edit == m_input_f)
    {
        return m_input_s;
    }
    else if(edit == m_input_s)
    {
        return m_input_t;
    }
    else if(edit == m_input_t)
    {
        return m_input_l;
    }
    else
    {
        return nullptr;
    }
}

bool TTKIpEditWidget::isEdit(QObject *object)
{
    return (object == m_input_f || object == m_input_s || object == m_input_t || object == m_input_l);
}

QString TTKIpEditWidget::text() const
{
    const QString &text_f = m_input_f->text().isEmpty() ? "0" : m_input_f->text();
    const QString &text_s = m_input_s->text().isEmpty() ? "0" : m_input_s->text();
    const QString &text_t = m_input_t->text().isEmpty() ? "0" : m_input_t->text();
    const QString &text_l = m_input_l->text().isEmpty() ? "0" : m_input_l->text();
    return QString("%1.%2.%3.%4").arg(text_f, text_s, text_t, text_l);
}

void TTKIpEditWidget::setText(const QString &text)
{
    const QString pattern("^((2[0-4]\\d|25[0-5]|[01]?\\d\\d?)\\.){3}(2[0-4]\\d|25[0-5]|[01]?\\d\\d?)$");
#if TTK_QT_VERSION_CHECK(6,0,0)
    QRegularExpression regx(pattern);
    if(!regx.match(text).hasMatch())
#else
    QRegExp regx(pattern);
    if(!regx.exactMatch(text))
#endif
    {
        return;
    }

    const QStringList &value = text.split(".");
    m_input_f->setText(value.at(0));
    m_input_s->setText(value.at(1));
    m_input_t->setText(value.at(2));
    m_input_l->setText(value.at(3));
    update();
}

QSize TTKIpEditWidget::sizeHint() const
{
    return QSize(165, 25);
}

void TTKIpEditWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    QStyleOptionFrame option;
    option.initFrom(this);
    option.lineWidth = 1;
    style()->drawPrimitive(QStyle::PE_PanelLineEdit, &option, &painter, this);

    QWidget::paintEvent(event);
}

bool TTKIpEditWidget::eventFilter(QObject *object, QEvent *event)
{
    if(isEdit(object))
    {
        if(event->type() == QEvent::KeyPress)
        {
            QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
            if(keyEvent->key() == Qt::Key_Period)
            {
                QLineEdit *next = nextEdit(qobject_cast<QLineEdit*>(object));
                if(next)
                {
                    next->setFocus();
                    next->selectAll();
                }
            }
            else if(keyEvent->matches(QKeySequence::Paste))
            {
                const QString &clip = QApplication::clipboard()->text(QClipboard::Clipboard);
                if(clip.split(".").count() == 4)
                {
                    setText(clip);
                    return true;
                }
            }
        }
    }

    return QWidget::eventFilter(object, event);
}

void TTKIpEditWidget::editTextChanged(const QString& text)
{
    QLineEdit* curEdit = qobject_cast<QLineEdit*>(sender());
    if(text.length() == 3)
    {
        QLineEdit* next = nextEdit(curEdit);
        if(next)
        {
            next->setFocus();
            next->selectAll();
        }
    }
}
