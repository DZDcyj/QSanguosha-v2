#ifndef _MAGATAMAS_ITEM_H
#define _MAGATAMAS_ITEM_H

//#include "skin-bank.h"

class MagatamasBoxItem : public QGraphicsObject
{
    Q_OBJECT

public:
    MagatamasBoxItem();
    MagatamasBoxItem(QGraphicsItem *parent);
    inline int getHp() const
    {
        return m_hp;
    }
    void setHp(int hp);
    inline int getMaxHp() const
    {
        return m_maxHp;
    }
    void setMaxHp(int maxHp);
    void setOrientation(Qt::Orientation orientation);
    inline Qt::Orientation getOrientation() const
    {
        return m_orientation;
    }
    inline void setBackgroundVisible(bool visible)
    {
        m_showBackground = visible;
    }
    inline bool isBackgroundVisible() const
    {
        return m_showBackground;
    }
    void setAnchor(QPoint anchor, Qt::Alignment align);
    inline void setAnchorEnable(bool enabled)
    {
        anchorEnabled = enabled;
    }
    inline bool isAnchorEnable()
    {
        return anchorEnabled;
    }
    void setIconSize(QSize size);
    inline void setImageArea(QRect rect)
    {
        m_imageArea = rect;
    }
    inline QSize getIconSize() const
    {
        return m_iconSize;
    }
    virtual QRectF boundingRect() const;
    virtual void update();
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

protected:
    void _autoAdjustPos();
    void _updateLayout();
    void _doHpChangeAnimation(int newHp);
    QPoint m_anchor;
    Qt::Alignment m_align;
    bool anchorEnabled;
    int m_hp = 0;
    int m_maxHp = 0;
    Qt::Orientation m_orientation = Qt::Vertical;
    bool m_showBackground;
    QSize m_iconSize;
    QRect m_imageArea;
    QPixmap _icons[6];
    QPixmap _bgImages[6];
};
#endif

