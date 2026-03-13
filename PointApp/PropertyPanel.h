#pragma once
#include <QWidget>
#include <QDoubleSpinBox>
#include <QLineEdit>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>

class QDoubleSpinBox;
class QLineEdit;
class QLabel; 

class PropertyPanel : public QWidget {
    Q_OBJECT
public:
    explicit PropertyPanel(QWidget* parent = nullptr);

    QLabel* titleLabel; 
    QDoubleSpinBox* scaleBox, * posX, * posY, * posZ;
    QDoubleSpinBox* RposX, * RposY, * RposZ;
    QLineEdit* surfaceAreaField, * volumeField;

    QComboBox* colorCombo;
    QPushButton* visibleBtn;
    QPushButton* lockedBtn;

public slots:
    void updateName(QString name); 
    void calculateSurfaceArea();
    void calculateVolume();

};