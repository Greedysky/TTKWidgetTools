#ifndef TTKFUNCTIONTOOLBOXWIDGET_H
#define TTKFUNCTIONTOOLBOXWIDGET_H

/* =================================================
 * This file is part of the TTK WidgetTools project
 * Copyright (C) 2015 - 2018 Greedysky Studio

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along
 * with this program; If not, see <http://www.gnu.org/licenses/>.
 ================================================= */

#include <QLabel>
#include <QBoxLayout>
#include "ttkglobaldefine.h"

/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_EXTRAS_EXPORT TTKFunctionToolBoxTopWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TTKFunctionToolBoxTopWidget(int index, const QString &text, QWidget *parent = 0);
    ~TTKFunctionToolBoxTopWidget();

    inline void setItemIndex(int index) { m_index = index; }
    inline int getItemIndex() const { return m_index; }

    void setItemExpand(bool expand);
    bool isItemExpand() const;

    void setTitle(const QString &text);
    QString getTitle(bool suffix = false);

Q_SIGNALS:
    void mousePressAt(int index);
    void swapDragItemIndex(int before, int after);

protected:
    bool isItemEnable() const;

    virtual void dragLeaveEvent(QDragLeaveEvent *event) override;
    virtual void dragMoveEvent(QDragMoveEvent *event) override;
    virtual void dragEnterEvent(QDragEnterEvent *event) override;
    virtual void dropEvent(QDropEvent *event) override;
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseMoveEvent(QMouseEvent *event) override;
    virtual void paintEvent(QPaintEvent *event) override;

    int m_index;
    QString m_suffixString;
    QLabel *m_labelIcon, *m_labelText;

    bool m_isDrawTopState, m_isDrawMoveState;
    bool m_isBlockMoveExpand;
    QPoint m_pressPosAt;

};



/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_EXTRAS_EXPORT TTKFunctionToolBoxWidgetItem : public QWidget
{
    Q_OBJECT
public:
    explicit TTKFunctionToolBoxWidgetItem(int index, const QString &text, QWidget *parent = 0);
    ~TTKFunctionToolBoxWidgetItem();

    QWidget *item(int index);

    void addItem(QWidget *item);
    void removeItem(QWidget *item);

    void setTitle(const QString &text);
    QString getTitle() const;

    void setItemExpand(bool expand);
    bool itemExpand() const;

    int count() const;

Q_SIGNALS:
    void swapDragItemIndex(int before, int after);

protected:
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void contextMenuEvent(QContextMenuEvent *event) override;

    QVBoxLayout *m_layout;
    QList<QWidget*> m_itemList;
    TTKFunctionToolBoxTopWidget *m_topWidget;

};


class QScrollArea;

/*!
 * @author Greedysky <greedysky@163.com>
 */
typedef struct TTK_EXTRAS_EXPORT TTKFunctionToolBoxUnionItem
{
    int m_itemIndex;
    TTKFunctionToolBoxWidgetItem* m_widgetItem;

    TTKFunctionToolBoxUnionItem()
    {
        m_itemIndex = -1;
        m_widgetItem = nullptr;
    }
}TTKFunctionToolBoxUnionItem;


/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_EXTRAS_EXPORT TTKFunctionToolBoxWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TTKFunctionToolBoxWidget(QWidget *parent = 0);
    ~TTKFunctionToolBoxWidget();

    void addItem(QWidget *item, const QString &text);
    void removeItem(QWidget *item);

    void swapItem(int before, int after);

    void setTitle(QWidget *item, const QString &text);
    QString getTitle(QWidget *item) const;

    void resizeScrollIndex(int index) const;

    int currentIndex() const;

    int count() const;

public Q_SLOTS:
    void setCurrentIndex(int index);
    void mousePressAt(int index);
    void setTransparent(int alpha);

protected:
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void contextMenuEvent(QContextMenuEvent *event) override;

    int foundMappingIndex(int index);

    int m_currentIndex, m_itemIndexRaise;
    QVBoxLayout *m_layout;
    QScrollArea *m_scrollArea;
    QWidget *m_contentsWidget;
    QList<TTKFunctionToolBoxUnionItem> m_itemList;

};

#endif // TTKFUNCTIONTOOLBOXWIDGET_H
