#ifndef LISTSWIDGET_H
#define LISTSWIDGET_H
#include <QWidget>
#include <QPushButton>
#include <QListWidget>
#include <QLabel>

class ListsWidget : public QWidget
{
    Q_OBJECT
public:
    ListsWidget(QWidget *parent = nullptr);
    ~ListsWidget();
private slots:
    void fromLeftToRight();
    void fromRightToLeft();
    void leftSort();
    void rightSort();
    void leftSelectItem();
    void rightSelectItem();
private:
    QListWidget *lw;
    QListWidget *rw;
    QPushButton *toRight;
    QPushButton *toLeft;
    QPushButton *leftSortButton;
    QPushButton *rightSortButton;

    bool emptyCheck(QListWidget* l);
};
#endif // LISTSWIDGET_H
