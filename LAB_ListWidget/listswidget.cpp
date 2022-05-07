#include "listswidget.h"
#include <QVBoxLayout>
#include <QMessageBox>

ListsWidget::ListsWidget(QWidget *parent)
    : QWidget(parent)
{
    QFrame *lFrame = new QFrame(this);
    lFrame->setFrameShape( QFrame::Box);
    lFrame->setFrameShadow( QFrame::Plain);
    //lFrame->setMidLineWidth(3);
    QHBoxLayout *ff = new QHBoxLayout(this);
    ff->addWidget(lFrame);

    QVBoxLayout *vbox1 = new QVBoxLayout();
    QVBoxLayout *vbox2 = new QVBoxLayout();
    QVBoxLayout *vbox3 = new QVBoxLayout();
    QHBoxLayout *hbox = new QHBoxLayout(lFrame);

    lw = new QListWidget(lFrame);
    rw = new QListWidget(lFrame);

    lw->setFrameStyle(QFrame::Box | QFrame::Plain);
    lw->setMidLineWidth(1);
    rw->setFrameStyle(QFrame::Box | QFrame::Plain);
    rw->setMidLineWidth(1);

    toRight = new QPushButton("&>", lFrame);
    toRight->setMinimumHeight(40);
    //toRight->setStyleSheet("border-style: solid;" "border-width: 2px;");
    toLeft = new QPushButton("&<", lFrame);
    toLeft->setMinimumHeight(40);

    leftSortButton = new QPushButton("&Sort(increase)", lFrame);
    rightSortButton = new QPushButton("&Sort(decrease)", lFrame);

    QLabel *lbl1 = new QLabel("Left List", lFrame);
    QLabel *lbl2 = new QLabel("Right List", lFrame);


    QFont lFont("Calibri", 12, 10);
    lFont.setBold(true);
    lbl1->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    lbl1->setFont(lFont);
    lbl2->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    lbl2->setFont(lFont);

    lFont.setBold(false);
    toRight->setFont(lFont);
    toLeft->setFont(lFont);
    leftSortButton->setFont(lFont);
    rightSortButton->setFont(lFont);

    lw->addItem("aaaaaaa");
    lw->addItem("bbbbbbbb");
    lw->addItem("cccccccc");
    lw->addItem("ddddddddd");
    lw->addItem("eeeeeeeee");
    lw->addItem("fffffffff");
    lw->addItem("ggggggggg");

    rw->addItem("0000000000");
    rw->addItem("11111111111");
    rw->addItem("22222222222");
    rw->addItem("33333333333");
    rw->addItem("44444444444");
    rw->addItem("55555555555");
    rw->addItem("66666666666");

    vbox1->addWidget(lbl1);
    vbox1->addWidget(lw);
    vbox1->addWidget(leftSortButton);

    vbox2->addSpacing(26);
    vbox2->addWidget(toRight);
    vbox2->addStretch(1);
    vbox2->addWidget(toLeft);
    vbox2->addSpacing(35);

    vbox3->addWidget(lbl2);
    vbox3->addWidget(rw);
    vbox3->addWidget(rightSortButton);

    hbox->addLayout(vbox1);
    hbox->addLayout(vbox2);
    hbox->addLayout(vbox3);

    connect(toRight, &QPushButton::clicked, this, &ListsWidget::fromLeftToRight);
    connect(toLeft, &QPushButton::clicked, this, &ListsWidget::fromRightToLeft);
    connect(leftSortButton, &QPushButton::clicked, this, &ListsWidget::leftSort);
    connect(rightSortButton, &QPushButton::clicked, this, &ListsWidget::rightSort);
    connect(lw, &QListWidget::itemClicked, this, &ListsWidget::leftSelectItem);
    connect(rw, &QListWidget::itemClicked, this, &ListsWidget::rightSelectItem);

    lw->setFocusPolicy(Qt::FocusPolicy::NoFocus);
    rw->setFocusPolicy(Qt::FocusPolicy::NoFocus);
}

void ListsWidget::fromLeftToRight()
{
    if(!emptyCheck(lw))
    {
        int r = lw->currentRow();
        if (r != -1)
        {
            QListWidgetItem *item = lw->takeItem(r);
            rw->addItem(item);
        }
    }
    leftSelectItem();
    rightSelectItem();
}

void ListsWidget::fromRightToLeft()
{
    if(!emptyCheck(rw))
    {
        int r = rw->currentRow();
        if (r != -1)
        {
            QListWidgetItem *item = rw->takeItem(r);
            lw->addItem(item);
        }
    }
    leftSelectItem();
    rightSelectItem();
}

void ListsWidget::leftSort()
{
    if(!emptyCheck(lw))
        lw->sortItems(Qt::AscendingOrder);
}

void ListsWidget::rightSort()
{
    if(!emptyCheck(rw))
        rw->sortItems(Qt::DescendingOrder);
}

void ListsWidget::leftSelectItem()
{
    rw->setCurrentRow(-1);
}

void ListsWidget::rightSelectItem()
{
    lw->setCurrentRow(-1);
}

bool ListsWidget::emptyCheck(QListWidget *l)
{
    if(l->count()==0)
    {
        QMessageBox::warning(0, "Ошибка!", "Данный список пуст!");
        return true;
    }
    return false;
}

ListsWidget::~ListsWidget(){}
