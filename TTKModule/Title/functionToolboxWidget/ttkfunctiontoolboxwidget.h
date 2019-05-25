#ifndef TTKFUNCTIONTOOLBOXWIDGET_H
#define TTKFUNCTIONTOOLBOXWIDGET_H

/* =================================================
 * This file is part of the TTK Widget Tools project
 * Copyright (C) 2015 - 2019 Greedysky Studio

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
#include "ttkglobal.h"
#include "ttkglobaldefine.h"

/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_CORE_EXPORT TTKFunctionToolBoxTopWidget : public QWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKFunctionToolBoxTopWidget)
public:
    explicit TTKFunctionToolBoxTopWidget(int index, const QString &text, QWidget *parent = nullptr);
    virtual ~TTKFunctionToolBoxTopWidget();

    inline void setItemIndex(int index) { m_index = index; }
    inline int getItemIndex() const { return m_index; }

    void setItemExpand(bool expand);
    bool isItemExpand() const;

    void setTitle(const QString &text);
    QString getTitle(bool suffix = false);

Q_SIGNALS:
    void mousePressAt(int index);

protected:
    bool isItemEnable() const;

    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void paintEvent(QPaintEvent *event) override;

    int m_index;
    QString m_suffixString;
    QLabel *m_labelIcon, *m_labelText;

};



/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_CORE_EXPORT TTKFunctionToolBoxWidgetItem : public QWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKFunctionToolBoxWidgetItem)
public:
    explicit TTKFunctionToolBoxWidgetItem(int index, const QString &text, QWidget *parent = nullptr);
    virtual ~TTKFunctionToolBoxWidgetItem();

    QWidget *item(int index);

    void addItem(QWidget *item);
    void removeItem(QWidget *item);

    void setTitle(const QString &text);
    QString getTitle() const;

    void setItemExpand(bool expand);
    bool itemExpand() const;

    int count() const;

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
typedef struct TTK_CORE_EXPORT TTKFunctionToolBoxUnionItem
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
class TTK_CORE_EXPORT TTKFunctionToolBoxWidget : public QWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKFunctionToolBoxWidget)
public:
    explicit TTKFunctionToolBoxWidget(QWidget *parent = nullptr);
    virtual ~TTKFunctionToolBoxWidget();

    void addItem(QWidget *item, const QString &text);
    void removeItem(QWidget *item);

    void swapItem(int before, int after);

    void setTitle(QWidget *item, const QString &text);
    QString getTitle(QWidget *item) const;

    void resizeScrollIndex(int index) const;

    int currentIndex() const;

    int count() const;

    void setSingleExpand(bool single);
    bool getSingleExpand() const;

    virtual QSize sizeHint() const override;

public Q_SLOTS:
    void setCurrentIndex(int index);
    void mousePressAt(int index);
    void setTransparent(int alpha);

protected:
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void contextMenuEvent(QContextMenuEvent *event) override;

    int foundMappingIndex(int index);

    bool m_singleExpand;
    int m_currentIndex, m_itemIndexRaise;
    QVBoxLayout *m_layout;
    QScrollArea *m_scrollArea;
    QWidget *m_contentsWidget;
    QList<TTKFunctionToolBoxUnionItem> m_itemList;

};

#endif // TTKFUNCTIONTOOLBOXWIDGET_H
