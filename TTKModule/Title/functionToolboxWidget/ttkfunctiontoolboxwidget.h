#ifndef TTKFUNCTIONTOOLBOXWIDGET_H
#define TTKFUNCTIONTOOLBOXWIDGET_H

/***************************************************************************
 * This file is part of the TTK Widget Tools project
 * Copyright (C) 2015 - 2026 Greedysky Studio

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public License along
 * with this program; If not, see <http://www.gnu.org/licenses/>.
 ***************************************************************************/

#include <QLabel>
#include <QBoxLayout>
#include "ttkmoduleexport.h"

/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_MODULE_EXPORT TTKFunctionToolBoxTopWidget : public QWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKFunctionToolBoxTopWidget)
public:
    explicit TTKFunctionToolBoxTopWidget(int index, const QString &text, QWidget *parent = nullptr);
    ~TTKFunctionToolBoxTopWidget();

    inline void setIndex(int index) { m_index = index; }
    inline int index() const { return m_index; }

    void setExpand(bool expand);
    bool isExpand() const;

    void setTitle(const QString &text);
    QString title(bool suffix);

Q_SIGNALS:
    void itemIndexChanged(int index);

private:
    virtual void mousePressEvent(QMouseEvent *event) override final;
    virtual void paintEvent(QPaintEvent *event) override final;

    bool isItemEnabled() const;

    int m_index;
    QLabel *m_labelIcon, *m_labelText;

};



/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_MODULE_EXPORT TTKFunctionToolBoxWidgetItem : public QWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKFunctionToolBoxWidgetItem)
public:
    explicit TTKFunctionToolBoxWidgetItem(int index, const QString &text, QWidget *parent = nullptr);
    ~TTKFunctionToolBoxWidgetItem();

    QWidget *item(int index);

    void addItem(QWidget *item);
    void removeItem(QWidget *item);

    void setTitle(const QString &text);
    QString title() const;

    void setExpand(bool expand);
    bool isExpand() const;

    int count() const;

private:
    virtual void mousePressEvent(QMouseEvent *event) override final;
    virtual void contextMenuEvent(QContextMenuEvent *event) override final;

    QVBoxLayout *m_layout;
    QWidgetList m_items;
    TTKFunctionToolBoxTopWidget *m_topWidget;

};


class QScrollArea;

/*!
 * @author Greedysky <greedysky@163.com>
 */
struct TTK_MODULE_EXPORT TTKFunctionToolBoxUnionItem
{
    int m_itemIndex;
    TTKFunctionToolBoxWidgetItem *m_itemWidget;

    TTKFunctionToolBoxUnionItem() noexcept
        : m_itemIndex(-1),
          m_itemWidget(nullptr)
    {

    }
};


/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_MODULE_EXPORT TTKFunctionToolBoxWidget : public QWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKFunctionToolBoxWidget)
public:
    explicit TTKFunctionToolBoxWidget(QWidget *parent = nullptr);
    ~TTKFunctionToolBoxWidget();

    void addItem(QWidget *item, const QString &text);
    void removeItem(QWidget *item);

    void swapItem(int before, int after);

    void setTitle(QWidget *item, const QString &text);
    QString title(QWidget *item) const;

    void resizeScrollIndex(int index) const;

    int currentIndex() const;

    int count() const;

    void setSingleExpand(bool single);
    bool singleExpand() const;

    virtual QSize sizeHint() const override final;

public Q_SLOTS:
    void setCurrentIndex(int index);
    void itemIndexChanged(int index);
    void setTransparent(int alpha);

private:
    virtual void mousePressEvent(QMouseEvent *event) override final;
    virtual void contextMenuEvent(QContextMenuEvent *event) override final;

    int foundMappingIndex(int index);

    bool m_singleExpand;
    int m_currentIndex, m_itemIndexRaise;
    QVBoxLayout *m_layout;
    QScrollArea *m_scrollArea;
    QWidget *m_contentsWidget;
    QList<TTKFunctionToolBoxUnionItem> m_items;

};

#endif // TTKFUNCTIONTOOLBOXWIDGET_H
