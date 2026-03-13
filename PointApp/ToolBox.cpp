#include "ToolBox.h"
#include <QVBoxLayout>
#include <QToolButton>
#include <QFrame>
#include <QIcon>

ToolBox::ToolBox(QWidget* parent) : QWidget(parent)
{
    createTools();
}

ToolBox::~ToolBox()
{
}

void ToolBox::createTools()
{
    QVBoxLayout* layout = new QVBoxLayout;
    layout->setContentsMargins(4, 8, 4, 8);
    layout->setSpacing(4);

    // name, icon path
    struct Tool {
        QString name;
        QString icon;
    };

    QList<Tool> group1 = {
        {"Move",  ":/icons/icons/move.svg"},
        {"Rot",   ":/icons/icons/rot.svg"},
        {"Scale", ":/icons/icons/scale.svg"}
    };

    QList<Tool> group2 = {
        {"Cuboid", ":/icons/icons/cuboid.svg"},
        {"Sphere", ":/icons/icons/sphere.svg"},
        {"Cyl",    ":/icons/icons/cyl.svg"},
        {"Cone",   ":/icons/icons/cone.svg"},
        {"Line",   ":/icons/icons/line.svg"}
    };

    QList<Tool> group3 = {
        {"Grp",  ":/icons/icons/grp.svg"},
        {"Lock", ":/icons/icons/lock.svg"},
        {"Del",  ":/icons/icons/del.svg"}
    };

    // Helper lambda to make one button
    auto makeButton = [&](const Tool& tool)
    {
        QToolButton* btn = new QToolButton;
        btn->setText(tool.name.toUpper());
        btn->setIcon(QIcon(tool.icon));
        btn->setIconSize(QSize(24, 24));
        btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btn->setFixedSize(62, 54);
        btn->setCheckable(true);

        connect(btn, &QToolButton::clicked, this, [=]()
        {
            for (QToolButton* other : findChildren<QToolButton*>())
            {
                if (other != btn)
                    other->setChecked(false);
            }
            emit toolSelected(tool.name);
        });

        layout->addWidget(btn, 0, Qt::AlignHCenter);
    };

    auto makeSeparator = [&]() {
        QFrame* line1 = new QFrame;
        line1->setFrameShape(QFrame::HLine);
        line1->setFixedWidth(50);
        line1->setStyleSheet("color: #2a3550;");
        layout->addWidget(line1, 0, Qt::AlignHCenter);
    };

    // Add group 1
    for (auto& t : group1) makeButton(t);    
    makeSeparator();
    // Add group 2
    for (auto& t : group2) makeButton(t);

    makeSeparator();
    // Add group 3
    for (auto& t : group3) makeButton(t);

    layout->addStretch();
    setLayout(layout);

    //// Styling
    setStyleSheet(R"(
    QWidget { background-color: #333336; }
    QToolButton {
        background-color: #2a2a2d;
        color: #a0a0a8;
        border: 1px solid #3a3a3d;
        border-radius: 6px;
        font-size: 8px;
        font-weight: bold;
    }
    QToolButton:hover { background-color: #3a3a3d; color: #ffffff; }
    QToolButton:checked { background-color: #1a1a1d; color: #00cfff; border: 1px solid #00cfff; }
    )");
    
}