#include "PropertyPanel.h"
#include <QFormLayout>
#include <QtMath>

PropertyPanel::PropertyPanel(QWidget* parent) : QWidget(parent) {
    QFormLayout* form = new QFormLayout(this);
    form->setVerticalSpacing(8);

    titleLabel = new QLabel("<b>Select a Shape</b>");
    titleLabel->setAlignment(Qt::AlignCenter);
    form->addRow(titleLabel);

    scaleBox = new QDoubleSpinBox(); 
   
    posX = new QDoubleSpinBox();
    posY = new QDoubleSpinBox(); 
    posZ = new QDoubleSpinBox();

    RposX = new QDoubleSpinBox(); 
    RposY = new QDoubleSpinBox();
    RposZ = new QDoubleSpinBox();

    surfaceAreaField = new QLineEdit("0.0");
    surfaceAreaField->setReadOnly(true);
    volumeField = new QLineEdit("0.0");
    volumeField->setReadOnly(true);

    colorCombo = new QComboBox();
    colorCombo->addItems({ "Blue", "Red", "Green", "Yellow", "White", "Black" });

    visibleBtn = new QPushButton("Visible");
    visibleBtn->setCheckable(true);
    visibleBtn->setChecked(true); 

    lockedBtn = new QPushButton("Locked");
    lockedBtn->setCheckable(true);

    form->addRow(new QLabel("<br><b>Positions</b>"));
    form->addRow("Scale:", scaleBox);
    form->addRow("X:", posX);
    form->addRow("Y:", posY);
    form->addRow("Z:", posZ);

    form->addRow(new QLabel("<br><b>Rotations</b>"));
    form->addRow("RX:", RposX);
    form->addRow("RY:", RposY);
    form->addRow("RZ:", RposZ);


    form->addRow(new QLabel("<br><b>Appearance</b>"));
    form->addRow("Color:", colorCombo);

    form->addRow(new QLabel("<b>State</b>"));
    form->addRow(visibleBtn);
    form->addRow(lockedBtn);

    form->addRow(new QLabel("<br><b>Measurements</b>"));
    form->addRow("Area:", surfaceAreaField);
    form->addRow("Vol:", volumeField);

    setFixedWidth(200);


}

void PropertyPanel::updateName(QString name) {
    titleLabel->setText("<b>Active: " + name + "</b>");
    calculateSurfaceArea();
    calculateVolume();
}

void PropertyPanel::calculateSurfaceArea() {
   
}

void PropertyPanel::calculateVolume() {
    
}