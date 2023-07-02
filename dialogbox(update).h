#ifndef DIALOGBOX_H
#define DIALOGBOX_H

#include <QDialog>
#include <QLabel>
#include <QMessageBox>
#include <QJsonDocument>
#include <QSignalMapper>
#include <QTimer>

class DialogBox : public QDialog
{
    Q_OBJECT

public:
    explicit DialogBox(QWidget *parent = 0);
    ~DialogBox();

    // 加载和解析一个json文件
    void loadJson(const QString &fileName);

    // 显示一个内容
    void showContent();

    // 设置背景图像
    void setPixmap(const QPixmap& m);

private slots:
    // 根据选项更新场景
    void updateScene(const QString &option);

    // 更新消息框的文本
    void updateText();

private:
    QMessageBox *messageBox; // 消息框对象
    QLabel *leftCharacter; // 左边角色标签对象
    QLabel *rightCharacter; // 右边角色标签对象
    QSignalMapper *signalMapper; // 信号映射器对象
    QJsonDocument jsonDoc; // json文档对象
    QMap<QString, QString> backgroundMap; // 背景图像映射
    QMap<QString, QString> backpackMap; // backpack内容映射
    QTimer *timer; // QTimer对象，用来控制文字的逐字显示
    QString textBuffer; // QString对象，用来存储文本内容
};

#endif // DIALOGBOX_H
