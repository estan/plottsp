#ifndef VIEW_H
#define VIEW_H

#include <iostream>

#include <QtGui>

#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
#include <QtWidgets>
#endif

class View : public QGraphicsView
{
    Q_OBJECT

public:
    explicit View(std::istream& in, QGraphicsScene *scene, QWidget *parent = 0);

protected:
    void wheelEvent(QWheelEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void drawForeground(QPainter *painter, const QRectF& rect);

private:
    QVector<QPointF> m_points;           // Points in the problem.
    QList<QGraphicsLineItem *> m_legs;   // Legs in the solution.

    QPen m_legPen;             // Pen used for legs.
    QPen m_currentLegPen;      // Pen used for current leg.
    int m_currentLeg;          // Index of current leg.
};

#endif // VIEW_H
