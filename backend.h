#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QString>
#include <QtQuick/QQuickPaintedItem>
#include <QColor>

#include "Game.h"

class BackEnd : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qint32 clickedColumn READ clickedColumn WRITE setClickedColumn NOTIFY clickedColumnChanged)
    Q_PROPERTY(qint32 clickedRow READ clickedRow WRITE setClickedRow NOTIFY clickedRowChanged)
    Q_PROPERTY(qint32 clickedColumnOponent READ clickedColumnOponent WRITE setClickedColumnOponent NOTIFY clickedColumnOponentChanged)
    Q_PROPERTY(qint32 clickedRowOponent READ clickedRowOponent WRITE setClickedRowOponent NOTIFY clickedRowOponentChanged)
    Q_PROPERTY(qint32 situation READ situation WRITE setSituation NOTIFY situationChanged)

public:
    explicit BackEnd(QObject *parent = nullptr);

    qint32 clickedColumn();
    void setClickedColumn(const qint32 &clickedColumn);
    qint32 clickedRow();
    void setClickedRow(const qint32 &clickedColumn);

    qint32 clickedColumnOponent();
    void setClickedColumnOponent(const qint32 &clickedColumn);
    qint32 clickedRowOponent();
    void setClickedRowOponent(const qint32 &clickedColumn);

    qint32 situation();
    void setSituation(const qint32 &clickedColumn);

signals:
    void clickedColumnChanged();
    void clickedRowChanged();

    void clickedColumnOponentChanged();
    void clickedRowOponentChanged();

    void situationChanged();

private:
    qint32 m_clickedColumn;
    qint32 m_clickedRow;

    qint32 m_clickedColumnOponent;
    qint32 m_clickedRowOponent;

    qint32 m_situation;

    Game *game;
};

#endif // BACKEND_H
