#include "backend.h"

BackEnd::BackEnd(QObject *parent) :
    QObject(parent)
{
    game = new Game();
}

qint32 BackEnd::clickedColumn()
{
    return m_clickedColumn;
}

qint32 BackEnd::clickedColumnOponent()
{
    return m_clickedColumnOponent;
}

qint32 BackEnd::clickedRow()
{
    return m_clickedRow;
}

qint32 BackEnd::clickedRowOponent()
{
    return m_clickedRowOponent;
}

qint32 BackEnd::situation()
{
    return m_situation;
}


void BackEnd::setClickedColumn(const qint32 &clickedColumn)
{
    int finalX = clickedColumn;
    m_clickedColumn = clickedColumn;
    emit clickedColumnChanged();
        if(game->board[finalX][0]==0)
        {
            m_clickedRow = game->start(finalX);
            emit clickedRowChanged();
            if(game->testSituation()==0)
            {
                m_clickedColumnOponent = game->oponent();
                emit clickedColumnOponentChanged();
                m_clickedRowOponent = game->oponent2(m_clickedColumnOponent);
                emit clickedRowOponentChanged();
                if(game->testSituation()==0)
                {}
                else if(game->testSituation()==1)
                {
                   m_situation = 13;
                   emit situationChanged();
                }
                else
                {
                    m_situation = 10;
                    emit situationChanged();
                }
            }
            else if(game->testSituation()==1)
            {
                m_situation = 7;
                emit situationChanged();
            }
            else
            {
                m_situation = 10;
                emit situationChanged();
            }
        }
}


void BackEnd::setClickedColumnOponent(const qint32 &clickedColumnOponent)
{

}

void BackEnd::setClickedRow(const qint32 &clickedRow)
{

}

void BackEnd::setClickedRowOponent(const qint32 &clickedRowOponent)
{

}

void BackEnd::setSituation(const qint32 &situation)
{

}
