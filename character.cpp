#include "character.h"

// 构造函数，初始化属性
Character::Character(int speed, int dir, int x, QString& name)

{
    this->speed = speed;
    this->dir=dir;
    this->interact = false;
    // 设置初始位置
    setPos(x, 400);
    pic=QPixmap(":/resources/image/"+name+".png");
    setPixmap(pic);
    // QSoundEffect对象，设置要播放的音频文件的源和音量
    sound = new QSoundEffect();
    sound->setSource(QUrl(":/resources/audio/walk.wav"));
    sound->setVolume(0.5f);

    // QGraphicsItemAnimation对象，指定要动画的对象和时间线，设置时间线的持续时间为0.5秒
    animation = new QGraphicsItemAnimation();
    timeline = new QTimeLine(500);
    animation->setItem(this);
    animation->setTimeLine(timeline);
}

// 绘图函数
void Character::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    // 绘制一个简单的圆形代表角色
    painter->setBrush(Qt::blue);
    painter->drawEllipse(-10, -10, 20, 20);
}

// 边界函数
QRectF Character::boundingRect() const
{
    return QRectF(-10, -10, 20, 20);
}

// 碰撞检测函数
bool Character::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode);

    // 判断两个圆形的距离是否小于半径之和
    qreal dx = other->x() - x();
    qreal dy = other->y() - y();
    qreal distance = qSqrt(dx * dx + dy * dy);

    return distance < 20;
}

// 按键事件处理函数
// 按键事件处理函数
void Character::keyPressEvent(QKeyEvent *event)
{

    switch (event->key()) {
    case Qt::Key_Left:
        // 向左移动，注意边界检查
        if (x() > -250) {
            // 清除动画的所有关键帧
            animation->clear();
            // 设置动画的起始值为当前位置
            animation->setPosAt(0, pos());
            // 设置动画的结束值为左移speed个单位后的位置
            animation->setPosAt(1, pos() + QPoint(-speed, 0));
            // 开始时间线
            timeline->start();
            // 播放音效
            sound->play();
        }
        break;
    case Qt::Key_Right:
        // 向右移动，注意边界检查
        if (x() < 250) {
            // 清除动画的所有关键帧
            animation->clear();
            // 设置动画的起始值为当前位置
            animation->setPosAt(0, pos());
            // 设置动画的结束值为右移speed个单位后的位置
            animation->setPosAt(1, pos() + QPoint(speed, 0));
            // 开始时间线
            timeline->start();
            // 播放音效
            sound->play();
        }
        break;
    case Qt::Key_Space:
        // 设置交互标志为真，表示可以进行交互操作，比如攻击或对话等
        interact = true;
        break;
    default:
        break;
    }
}

// 获取和设置生命值
int Character::getHp() const
{
    return hp;
}

void Character::setHp(int value)
{
    hp = value;
}

// 获取和设置攻击力
int Character::getAtk() const
{
    return atk;
}

void Character::setAtk(int value)
{
    atk = value;
}
bool Character::getInteract(){return interact;}
void Character::setInteract(bool b){interact=b;}
void Character::setSpeed(int s){speed=s;}
