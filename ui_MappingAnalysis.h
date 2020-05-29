/********************************************************************************
** Form generated from reading UI file 'MappingAnalysis.ui'
**
** Created: Thu Jan 12 13:45:18 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPPINGANALYSIS_H
#define UI_MAPPINGANALYSIS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTextBrowser>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MappingAnalysis
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidgetMain;
    QWidget *tabArmMeasurement;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBoxArmMeasureOption;
    QSpacerItem *horizontalSpacer;
    QWidget *gridLayoutWidget_7;
    QGridLayout *gridLayout_10;
    QLabel *label_17;
    QLabel *label_18;
    QTextEdit *textEditForeArmLength;
    QTextEdit *textEditUpperArmLength;
    QPushButton *pushButtonArmMeasureRecord;
    QPushButton *pushButtonArmMeasureStart;
    QLabel *label_34;
    QLabel *label_35;
    QLabel *label_36;
    QLabel *label_37;
    QLabel *label_38;
    QTextEdit *textEditHandThresholdMax1;
    QTextEdit *textEditHandThresholdMin1;
    QTextEdit *textEditElbowThresholdMin1;
    QTextEdit *textEditRollFAThresholdMin;
    QLabel *label_39;
    QLabel *label_40;
    QLabel *label_41;
    QLabel *label_42;
    QPushButton *pushButtonThresholdRecord;
    QLabel *label_50;
    QTextEdit *textEditHandThresholdMin2;
    QLabel *label_51;
    QTextEdit *textEditHandThresholdMax2;
    QLabel *label_52;
    QTextEdit *textEditElbowThresholdMin2;
    QWidget *tabTesting;
    QLabel *label_4;
    QWidget *gridLayoutWidget_5;
    QGridLayout *gridLayout_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_6;
    QTextBrowser *textBrowserIMUTestingUpperArmRoll;
    QTextBrowser *textBrowserIMUTestingForeArmRoll;
    QTextBrowser *textBrowserIMUTestingUpperArmPitch;
    QTextBrowser *textBrowserIMUTestingUpperArmYaw;
    QTextBrowser *textBrowserIMUTestingForeArmPitch;
    QTextBrowser *textBrowserIMUTestingForeArmYaw;
    QLabel *label_15;
    QLabel *label_16;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *checkBoxIMUTestingSaving;
    QPushButton *pushButtontextBrowserIMUTestingRecord;
    QLabel *label_9;
    QWidget *verticalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_10;
    QComboBox *comboBoxVibroTestingAxis;
    QSpacerItem *horizontalSpacer_2;
    QWidget *gridLayoutWidget_6;
    QGridLayout *gridLayout_7;
    QLabel *label_12;
    QTextEdit *textEditVibroTestingStrength;
    QTextEdit *textEditVibroTestingDuration;
    QLabel *label_11;
    QPushButton *pushButtonIMUTestingStop;
    QPushButton *pushButtonIMUTestingTest;
    QComboBox *comboBoxIMUSaving;
    QPushButton *pushButtonVibroTestingStop;
    QPushButton *pushButtonVibroTestingTest;
    QPushButton *pushButtonIMUTestingCalibration;
    QPushButton *pushButtonVibroTestingL2HAmp;
    QPushButton *pushButtonVibroTestingLowAmp;
    QPushButton *pushButtonVibroTestingHighAmp;
    QPushButton *pushButtonVibroTestingMappingPattern;
    QWidget *tabExperiment;
    QWidget *gridLayoutWidget_8;
    QGridLayout *gridLayout_11;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QTextBrowser *textBrowserMasterUpArmRoll;
    QTextBrowser *textBrowserMasterForeArmRoll;
    QTextBrowser *textBrowserMasterUpArmPitch;
    QTextBrowser *textBrowserMasterUpArmYaw;
    QTextBrowser *textBrowserMasterForeArmPitch;
    QTextBrowser *textBrowserMasterForeArmYaw;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_22;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_23;
    QComboBox *comboBoxMasterSelection;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_24;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_25;
    QSpacerItem *horizontalSpacer_4;
    QRadioButton *radioButtonExpVisionON;
    QRadioButton *radioButtonExpVisionOFF;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_26;
    QSpacerItem *horizontalSpacer_5;
    QRadioButton *radioButtonExpVibroON;
    QRadioButton *radioButtonExpVibroOFF;
    QComboBox *comboBoxExpVisionPicVideoSelection;
    QPushButton *pushButtonExpStart;
    QWidget *gridLayoutWidget_9;
    QGridLayout *gridLayout_12;
    QLabel *label_32;
    QTextBrowser *textBrowserStudentUpRoll;
    QTextBrowser *textBrowserStudentUpPitch;
    QTextBrowser *textBrowserStudentUpYaw;
    QLabel *label_33;
    QTextBrowser *textBrowserStudentForeRoll;
    QTextBrowser *textBrowserStudentForePitch;
    QTextBrowser *textBrowserStudentForeYaw;
    QLabel *label_28;
    QLabel *label_31;
    QLabel *label_29;
    QPushButton *pushButtonExpStop;
    QTextBrowser *textBrowserHandCoorDelta;
    QLabel *label_5;
    QLabel *label_13;
    QTextBrowser *textBrowserElbowCoorDelta;
    QLabel *label_14;
    QTextBrowser *textBrowserForeRollAngleDelta;
    QPushButton *pushButtonExpVisionShow;
    QPushButton *pushButtonExpRecord;
    QComboBox *comboBoxExpSimSeqSelection;
    QLabel *label_27;
    QLabel *label_43;
    QLabel *label_44;
    QLabel *label_45;
    QLabel *label_46;
    QTextBrowser *textBrowserHandCoorTargetX;
    QTextBrowser *textBrowserHandCoorTargetY;
    QTextBrowser *textBrowserHandCoorTargetZ;
    QTextBrowser *textBrowserElbowCoorTargetZ;
    QTextBrowser *textBrowserElbowCoorTargetY;
    QTextBrowser *textBrowserElbowCoorTargetX;
    QTextBrowser *textBrowserForeArmRollTarget;
    QTextBrowser *textBrowserForeArmRollActual;
    QTextBrowser *textBrowserElbowCoorActualX;
    QTextBrowser *textBrowserHandCoorActualZ;
    QTextBrowser *textBrowserHandCoorActualY;
    QTextBrowser *textBrowserElbowCoorActualZ;
    QTextBrowser *textBrowserHandCoorActualX;
    QTextBrowser *textBrowserElbowCoorActualY;
    QLabel *label_47;
    QWidget *horizontalLayoutWidget_6;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_30;
    QComboBox *comboBoxCandidateNumber;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_48;
    QPushButton *pushButtonExpCalibration;
    QLabel *labelMappingType;
    QLabel *label_49;
    QComboBox *comboBoxNumberLoop;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MappingAnalysis)
    {
        if (MappingAnalysis->objectName().isEmpty())
            MappingAnalysis->setObjectName(QString::fromUtf8("MappingAnalysis"));
        MappingAnalysis->resize(868, 737);
        centralWidget = new QWidget(MappingAnalysis);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidgetMain = new QTabWidget(centralWidget);
        tabWidgetMain->setObjectName(QString::fromUtf8("tabWidgetMain"));
        tabWidgetMain->setGeometry(QRect(6, -1, 811, 671));
        tabWidgetMain->setIconSize(QSize(16, 16));
        tabWidgetMain->setElideMode(Qt::ElideMiddle);
        tabArmMeasurement = new QWidget();
        tabArmMeasurement->setObjectName(QString::fromUtf8("tabArmMeasurement"));
        horizontalLayoutWidget_2 = new QWidget(tabArmMeasurement);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(50, 50, 221, 22));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        comboBoxArmMeasureOption = new QComboBox(horizontalLayoutWidget_2);
        comboBoxArmMeasureOption->setObjectName(QString::fromUtf8("ComboBoxArmMeasureOption"));

        horizontalLayout->addWidget(comboBoxArmMeasureOption);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        gridLayoutWidget_7 = new QWidget(tabArmMeasurement);
        gridLayoutWidget_7->setObjectName(QString::fromUtf8("gridLayoutWidget_7"));
        gridLayoutWidget_7->setGeometry(QRect(320, 50, 201, 81));
        gridLayout_10 = new QGridLayout(gridLayoutWidget_7);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setContentsMargins(0, 0, 0, 0);
        label_17 = new QLabel(gridLayoutWidget_7);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_10->addWidget(label_17, 1, 0, 1, 1);

        label_18 = new QLabel(gridLayoutWidget_7);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_10->addWidget(label_18, 0, 0, 1, 1);

        textEditForeArmLength = new QTextEdit(gridLayoutWidget_7);
        textEditForeArmLength->setObjectName(QString::fromUtf8("textEditForeArmLength"));

        gridLayout_10->addWidget(textEditForeArmLength, 1, 1, 1, 1);

        textEditUpperArmLength = new QTextEdit(gridLayoutWidget_7);
        textEditUpperArmLength->setObjectName(QString::fromUtf8("textEditUpperArmLength"));

        gridLayout_10->addWidget(textEditUpperArmLength, 0, 1, 1, 1);

        pushButtonArmMeasureRecord = new QPushButton(tabArmMeasurement);
        pushButtonArmMeasureRecord->setObjectName(QString::fromUtf8("pushButtonArmMeasureRecord"));
        pushButtonArmMeasureRecord->setGeometry(QRect(160, 90, 75, 51));
        pushButtonArmMeasureStart = new QPushButton(tabArmMeasurement);
        pushButtonArmMeasureStart->setObjectName(QString::fromUtf8("pushButtonArmMeasureStart"));
        pushButtonArmMeasureStart->setGeometry(QRect(50, 90, 81, 51));
        label_34 = new QLabel(tabArmMeasurement);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setGeometry(QRect(10, 20, 61, 16));
        label_35 = new QLabel(tabArmMeasurement);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setGeometry(QRect(10, 190, 121, 16));
        label_36 = new QLabel(tabArmMeasurement);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setGeometry(QRect(30, 210, 151, 16));
        label_37 = new QLabel(tabArmMeasurement);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setGeometry(QRect(30, 350, 151, 16));
        label_38 = new QLabel(tabArmMeasurement);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setGeometry(QRect(30, 440, 111, 16));
        textEditHandThresholdMax1 = new QTextEdit(tabArmMeasurement);
        textEditHandThresholdMax1->setObjectName(QString::fromUtf8("textEditHandThresholdMax1"));
        textEditHandThresholdMax1->setGeometry(QRect(50, 250, 51, 31));
        textEditHandThresholdMin1 = new QTextEdit(tabArmMeasurement);
        textEditHandThresholdMin1->setObjectName(QString::fromUtf8("textEditHandThresholdMin1"));
        textEditHandThresholdMin1->setGeometry(QRect(130, 250, 51, 31));
        textEditElbowThresholdMin1 = new QTextEdit(tabArmMeasurement);
        textEditElbowThresholdMin1->setObjectName(QString::fromUtf8("textEditElbowThresholdMin1"));
        textEditElbowThresholdMin1->setGeometry(QRect(50, 390, 51, 31));
        textEditRollFAThresholdMin = new QTextEdit(tabArmMeasurement);
        textEditRollFAThresholdMin->setObjectName(QString::fromUtf8("textEditRollFAThresholdMin"));
        textEditRollFAThresholdMin->setGeometry(QRect(50, 480, 51, 31));
        label_39 = new QLabel(tabArmMeasurement);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setGeometry(QRect(50, 230, 61, 16));
        label_40 = new QLabel(tabArmMeasurement);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setGeometry(QRect(130, 230, 51, 16));
        label_41 = new QLabel(tabArmMeasurement);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setGeometry(QRect(50, 460, 71, 16));
        label_42 = new QLabel(tabArmMeasurement);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setGeometry(QRect(50, 370, 51, 16));
        pushButtonThresholdRecord = new QPushButton(tabArmMeasurement);
        pushButtonThresholdRecord->setObjectName(QString::fromUtf8("pushButtonThresholdRecord"));
        pushButtonThresholdRecord->setGeometry(QRect(280, 300, 75, 51));
        label_50 = new QLabel(tabArmMeasurement);
        label_50->setObjectName(QString::fromUtf8("label_50"));
        label_50->setGeometry(QRect(50, 290, 61, 16));
        textEditHandThresholdMin2 = new QTextEdit(tabArmMeasurement);
        textEditHandThresholdMin2->setObjectName(QString::fromUtf8("textEditHandThresholdMin2"));
        textEditHandThresholdMin2->setGeometry(QRect(130, 310, 51, 31));
        label_51 = new QLabel(tabArmMeasurement);
        label_51->setObjectName(QString::fromUtf8("label_51"));
        label_51->setGeometry(QRect(130, 290, 51, 16));
        textEditHandThresholdMax2 = new QTextEdit(tabArmMeasurement);
        textEditHandThresholdMax2->setObjectName(QString::fromUtf8("textEditHandThresholdMax2"));
        textEditHandThresholdMax2->setGeometry(QRect(50, 310, 51, 31));
        label_52 = new QLabel(tabArmMeasurement);
        label_52->setObjectName(QString::fromUtf8("label_52"));
        label_52->setGeometry(QRect(130, 370, 51, 16));
        textEditElbowThresholdMin2 = new QTextEdit(tabArmMeasurement);
        textEditElbowThresholdMin2->setObjectName(QString::fromUtf8("textEditElbowThresholdMin2"));
        textEditElbowThresholdMin2->setGeometry(QRect(130, 390, 51, 31));
        tabWidgetMain->addTab(tabArmMeasurement, QString());
        tabTesting = new QWidget();
        tabTesting->setObjectName(QString::fromUtf8("tabTesting"));
        label_4 = new QLabel(tabTesting);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 10, 61, 16));
        gridLayoutWidget_5 = new QWidget(tabTesting);
        gridLayoutWidget_5->setObjectName(QString::fromUtf8("gridLayoutWidget_5"));
        gridLayoutWidget_5->setGeometry(QRect(30, 30, 295, 91));
        gridLayout_6 = new QGridLayout(gridLayoutWidget_5);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(gridLayoutWidget_5);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_6->addWidget(label_7, 0, 2, 1, 1);

        label_8 = new QLabel(gridLayoutWidget_5);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_6->addWidget(label_8, 0, 3, 1, 1);

        label_6 = new QLabel(gridLayoutWidget_5);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_6->addWidget(label_6, 0, 1, 1, 1);

        textBrowserIMUTestingUpperArmRoll = new QTextBrowser(gridLayoutWidget_5);
        textBrowserIMUTestingUpperArmRoll->setObjectName(QString::fromUtf8("textBrowserIMUTestingUpperArmRoll"));

        gridLayout_6->addWidget(textBrowserIMUTestingUpperArmRoll, 1, 1, 1, 1);

        textBrowserIMUTestingForeArmRoll = new QTextBrowser(gridLayoutWidget_5);
        textBrowserIMUTestingForeArmRoll->setObjectName(QString::fromUtf8("textBrowserIMUTestingForeArmRoll"));

        gridLayout_6->addWidget(textBrowserIMUTestingForeArmRoll, 2, 1, 1, 1);

        textBrowserIMUTestingUpperArmPitch = new QTextBrowser(gridLayoutWidget_5);
        textBrowserIMUTestingUpperArmPitch->setObjectName(QString::fromUtf8("textBrowserIMUTestingUpperArmPitch"));

        gridLayout_6->addWidget(textBrowserIMUTestingUpperArmPitch, 1, 2, 1, 1);

        textBrowserIMUTestingUpperArmYaw = new QTextBrowser(gridLayoutWidget_5);
        textBrowserIMUTestingUpperArmYaw->setObjectName(QString::fromUtf8("textBrowserIMUTestingUpperArmYaw"));

        gridLayout_6->addWidget(textBrowserIMUTestingUpperArmYaw, 1, 3, 1, 1);

        textBrowserIMUTestingForeArmPitch = new QTextBrowser(gridLayoutWidget_5);
        textBrowserIMUTestingForeArmPitch->setObjectName(QString::fromUtf8("textBrowserIMUTestingForeArmPitch"));

        gridLayout_6->addWidget(textBrowserIMUTestingForeArmPitch, 2, 2, 1, 1);

        textBrowserIMUTestingForeArmYaw = new QTextBrowser(gridLayoutWidget_5);
        textBrowserIMUTestingForeArmYaw->setObjectName(QString::fromUtf8("textBrowserIMUTestingForeArmYaw"));

        gridLayout_6->addWidget(textBrowserIMUTestingForeArmYaw, 2, 3, 1, 1);

        label_15 = new QLabel(gridLayoutWidget_5);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_6->addWidget(label_15, 1, 0, 1, 1);

        label_16 = new QLabel(gridLayoutWidget_5);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_6->addWidget(label_16, 2, 0, 1, 1);

        horizontalLayoutWidget = new QWidget(tabTesting);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(360, 30, 151, 22));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        checkBoxIMUTestingSaving = new QCheckBox(horizontalLayoutWidget);
        checkBoxIMUTestingSaving->setObjectName(QString::fromUtf8("checkBoxIMUTestingSaving"));

        horizontalLayout_3->addWidget(checkBoxIMUTestingSaving);

        pushButtontextBrowserIMUTestingRecord = new QPushButton(tabTesting);
        pushButtontextBrowserIMUTestingRecord->setObjectName(QString::fromUtf8("pushButtontextBrowserIMUTestingRecord"));
        pushButtontextBrowserIMUTestingRecord->setGeometry(QRect(600, 20, 101, 41));
        label_9 = new QLabel(tabTesting);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 220, 111, 16));
        verticalLayoutWidget_3 = new QWidget(tabTesting);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(30, 240, 171, 41));
        horizontalLayout_5 = new QHBoxLayout(verticalLayoutWidget_3);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(verticalLayoutWidget_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_5->addWidget(label_10);

        comboBoxVibroTestingAxis = new QComboBox(verticalLayoutWidget_3);
        comboBoxVibroTestingAxis->setObjectName(QString::fromUtf8("ComboBoxVibroTestingAxis"));

        horizontalLayout_5->addWidget(comboBoxVibroTestingAxis);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        gridLayoutWidget_6 = new QWidget(tabTesting);
        gridLayoutWidget_6->setObjectName(QString::fromUtf8("gridLayoutWidget_6"));
        gridLayoutWidget_6->setGeometry(QRect(220, 240, 161, 61));
        gridLayout_7 = new QGridLayout(gridLayoutWidget_6);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(gridLayoutWidget_6);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_7->addWidget(label_12, 1, 0, 1, 1);

        textEditVibroTestingStrength = new QTextEdit(gridLayoutWidget_6);
        textEditVibroTestingStrength->setObjectName(QString::fromUtf8("textEditVibroTestingStrength"));

        gridLayout_7->addWidget(textEditVibroTestingStrength, 0, 1, 1, 1);

        textEditVibroTestingDuration = new QTextEdit(gridLayoutWidget_6);
        textEditVibroTestingDuration->setObjectName(QString::fromUtf8("textEditVibroTestingDuration"));

        gridLayout_7->addWidget(textEditVibroTestingDuration, 1, 1, 1, 1);

        label_11 = new QLabel(gridLayoutWidget_6);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_7->addWidget(label_11, 0, 0, 1, 1);

        pushButtonIMUTestingStop = new QPushButton(tabTesting);
        pushButtonIMUTestingStop->setObjectName(QString::fromUtf8("pushButtonIMUTestingStop"));
        pushButtonIMUTestingStop->setGeometry(QRect(30, 140, 81, 41));
        pushButtonIMUTestingTest = new QPushButton(tabTesting);
        pushButtonIMUTestingTest->setObjectName(QString::fromUtf8("pushButtonIMUTestingTest"));
        pushButtonIMUTestingTest->setGeometry(QRect(120, 140, 81, 41));
        comboBoxIMUSaving = new QComboBox(tabTesting);
        comboBoxIMUSaving->setObjectName(QString::fromUtf8("ComboBoxIMUSaving"));
        comboBoxIMUSaving->setGeometry(QRect(520, 30, 71, 20));
        pushButtonVibroTestingStop = new QPushButton(tabTesting);
        pushButtonVibroTestingStop->setObjectName(QString::fromUtf8("pushButtonVibroTestingStop"));
        pushButtonVibroTestingStop->setGeometry(QRect(30, 340, 81, 41));
        pushButtonVibroTestingTest = new QPushButton(tabTesting);
        pushButtonVibroTestingTest->setObjectName(QString::fromUtf8("pushButtonVibroTestingTest"));
        pushButtonVibroTestingTest->setGeometry(QRect(120, 340, 81, 41));
        pushButtonIMUTestingCalibration = new QPushButton(tabTesting);
        pushButtonIMUTestingCalibration->setObjectName(QString::fromUtf8("pushButtonIMUTestingCalibration"));
        pushButtonIMUTestingCalibration->setGeometry(QRect(220, 140, 81, 41));
        pushButtonVibroTestingL2HAmp = new QPushButton(tabTesting);
        pushButtonVibroTestingL2HAmp->setObjectName(QString::fromUtf8("pushButtonVibroTestingL2HAmp"));
        pushButtonVibroTestingL2HAmp->setGeometry(QRect(410, 240, 101, 31));
        pushButtonVibroTestingLowAmp = new QPushButton(tabTesting);
        pushButtonVibroTestingLowAmp->setObjectName(QString::fromUtf8("pushButtonVibroTestingLowAmp"));
        pushButtonVibroTestingLowAmp->setGeometry(QRect(530, 240, 91, 31));
        pushButtonVibroTestingHighAmp = new QPushButton(tabTesting);
        pushButtonVibroTestingHighAmp->setObjectName(QString::fromUtf8("pushButtonVibroTestingHighAmp"));
        pushButtonVibroTestingHighAmp->setGeometry(QRect(410, 280, 101, 31));
        pushButtonVibroTestingMappingPattern = new QPushButton(tabTesting);
        pushButtonVibroTestingMappingPattern->setObjectName(QString::fromUtf8("pushButtonVibroTestingMappingPattern"));
        pushButtonVibroTestingMappingPattern->setGeometry(QRect(530, 280, 91, 31));
        tabWidgetMain->addTab(tabTesting, QString());
        tabExperiment = new QWidget();
        tabExperiment->setObjectName(QString::fromUtf8("tabExperiment"));
        gridLayoutWidget_8 = new QWidget(tabExperiment);
        gridLayoutWidget_8->setObjectName(QString::fromUtf8("gridLayoutWidget_8"));
        gridLayoutWidget_8->setGeometry(QRect(30, 200, 295, 81));
        gridLayout_11 = new QGridLayout(gridLayoutWidget_8);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_11->setContentsMargins(0, 0, 0, 0);
        label_19 = new QLabel(gridLayoutWidget_8);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout_11->addWidget(label_19, 0, 2, 1, 1);

        label_20 = new QLabel(gridLayoutWidget_8);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout_11->addWidget(label_20, 0, 3, 1, 1);

        label_21 = new QLabel(gridLayoutWidget_8);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        gridLayout_11->addWidget(label_21, 0, 1, 1, 1);

        textBrowserMasterUpArmRoll = new QTextBrowser(gridLayoutWidget_8);
        textBrowserMasterUpArmRoll->setObjectName(QString::fromUtf8("textBrowserMasterUpArmRoll"));

        gridLayout_11->addWidget(textBrowserMasterUpArmRoll, 1, 1, 1, 1);

        textBrowserMasterForeArmRoll = new QTextBrowser(gridLayoutWidget_8);
        textBrowserMasterForeArmRoll->setObjectName(QString::fromUtf8("textBrowserMasterForeArmRoll"));

        gridLayout_11->addWidget(textBrowserMasterForeArmRoll, 2, 1, 1, 1);

        textBrowserMasterUpArmPitch = new QTextBrowser(gridLayoutWidget_8);
        textBrowserMasterUpArmPitch->setObjectName(QString::fromUtf8("textBrowserMasterUpArmPitch"));

        gridLayout_11->addWidget(textBrowserMasterUpArmPitch, 1, 2, 1, 1);

        textBrowserMasterUpArmYaw = new QTextBrowser(gridLayoutWidget_8);
        textBrowserMasterUpArmYaw->setObjectName(QString::fromUtf8("textBrowserMasterUpArmYaw"));

        gridLayout_11->addWidget(textBrowserMasterUpArmYaw, 1, 3, 1, 1);

        textBrowserMasterForeArmPitch = new QTextBrowser(gridLayoutWidget_8);
        textBrowserMasterForeArmPitch->setObjectName(QString::fromUtf8("textBrowserMasterForeArmPitch"));

        gridLayout_11->addWidget(textBrowserMasterForeArmPitch, 2, 2, 1, 1);

        textBrowserMasterForeArmYaw = new QTextBrowser(gridLayoutWidget_8);
        textBrowserMasterForeArmYaw->setObjectName(QString::fromUtf8("textBrowserMasterForeArmYaw"));

        gridLayout_11->addWidget(textBrowserMasterForeArmYaw, 2, 3, 1, 1);

        label_2 = new QLabel(gridLayoutWidget_8);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_11->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget_8);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_11->addWidget(label_3, 2, 0, 1, 1);

        label_22 = new QLabel(tabExperiment);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(10, 80, 111, 16));
        horizontalLayoutWidget_3 = new QWidget(tabExperiment);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(30, 100, 181, 22));
        horizontalLayout_7 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_23 = new QLabel(horizontalLayoutWidget_3);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        horizontalLayout_7->addWidget(label_23);

        comboBoxMasterSelection = new QComboBox(horizontalLayoutWidget_3);
        comboBoxMasterSelection->setObjectName(QString::fromUtf8("ComboBoxMasterSelection"));

        horizontalLayout_7->addWidget(comboBoxMasterSelection);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_3);

        label_24 = new QLabel(tabExperiment);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(310, 80, 141, 16));
        horizontalLayoutWidget_4 = new QWidget(tabExperiment);
        horizontalLayoutWidget_4->setObjectName(QString::fromUtf8("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(330, 100, 211, 22));
        horizontalLayout_8 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_25 = new QLabel(horizontalLayoutWidget_4);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        horizontalLayout_8->addWidget(label_25);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_4);

        radioButtonExpVisionON = new QRadioButton(horizontalLayoutWidget_4);
        radioButtonExpVisionON->setObjectName(QString::fromUtf8("radioButtonExpVisionON"));

        horizontalLayout_8->addWidget(radioButtonExpVisionON);

        radioButtonExpVisionOFF = new QRadioButton(horizontalLayoutWidget_4);
        radioButtonExpVisionOFF->setObjectName(QString::fromUtf8("radioButtonExpVisionOFF"));

        horizontalLayout_8->addWidget(radioButtonExpVisionOFF);

        horizontalLayoutWidget_5 = new QWidget(tabExperiment);
        horizontalLayoutWidget_5->setObjectName(QString::fromUtf8("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(330, 130, 211, 22));
        horizontalLayout_9 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_26 = new QLabel(horizontalLayoutWidget_5);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        horizontalLayout_9->addWidget(label_26);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_5);

        radioButtonExpVibroON = new QRadioButton(horizontalLayoutWidget_5);
        radioButtonExpVibroON->setObjectName(QString::fromUtf8("radioButtonExpVibroON"));

        horizontalLayout_9->addWidget(radioButtonExpVibroON);

        radioButtonExpVibroOFF = new QRadioButton(horizontalLayoutWidget_5);
        radioButtonExpVibroOFF->setObjectName(QString::fromUtf8("radioButtonExpVibroOFF"));

        horizontalLayout_9->addWidget(radioButtonExpVibroOFF);

        comboBoxExpVisionPicVideoSelection = new QComboBox(tabExperiment);
        comboBoxExpVisionPicVideoSelection->setObjectName(QString::fromUtf8("ComboBoxExpVisionPicVideoSelection"));
        comboBoxExpVisionPicVideoSelection->setGeometry(QRect(550, 100, 81, 20));
        pushButtonExpStart = new QPushButton(tabExperiment);
        pushButtonExpStart->setObjectName(QString::fromUtf8("pushButtonExpStart"));
        pushButtonExpStart->setGeometry(QRect(480, 590, 81, 41));
        gridLayoutWidget_9 = new QWidget(tabExperiment);
        gridLayoutWidget_9->setObjectName(QString::fromUtf8("gridLayoutWidget_9"));
        gridLayoutWidget_9->setGeometry(QRect(390, 200, 295, 81));
        gridLayout_12 = new QGridLayout(gridLayoutWidget_9);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        gridLayout_12->setContentsMargins(0, 0, 0, 0);
        label_32 = new QLabel(gridLayoutWidget_9);
        label_32->setObjectName(QString::fromUtf8("label_32"));

        gridLayout_12->addWidget(label_32, 1, 0, 1, 1);

        textBrowserStudentUpRoll = new QTextBrowser(gridLayoutWidget_9);
        textBrowserStudentUpRoll->setObjectName(QString::fromUtf8("textBrowserStudentUpRoll"));

        gridLayout_12->addWidget(textBrowserStudentUpRoll, 1, 1, 1, 1);

        textBrowserStudentUpPitch = new QTextBrowser(gridLayoutWidget_9);
        textBrowserStudentUpPitch->setObjectName(QString::fromUtf8("textBrowserStudentUpPitch"));

        gridLayout_12->addWidget(textBrowserStudentUpPitch, 1, 2, 1, 1);

        textBrowserStudentUpYaw = new QTextBrowser(gridLayoutWidget_9);
        textBrowserStudentUpYaw->setObjectName(QString::fromUtf8("textBrowserStudentUpYaw"));

        gridLayout_12->addWidget(textBrowserStudentUpYaw, 1, 3, 1, 1);

        label_33 = new QLabel(gridLayoutWidget_9);
        label_33->setObjectName(QString::fromUtf8("label_33"));

        gridLayout_12->addWidget(label_33, 2, 0, 1, 1);

        textBrowserStudentForeRoll = new QTextBrowser(gridLayoutWidget_9);
        textBrowserStudentForeRoll->setObjectName(QString::fromUtf8("textBrowserStudentForeRoll"));

        gridLayout_12->addWidget(textBrowserStudentForeRoll, 2, 1, 1, 1);

        textBrowserStudentForePitch = new QTextBrowser(gridLayoutWidget_9);
        textBrowserStudentForePitch->setObjectName(QString::fromUtf8("textBrowserStudentForePitch"));

        gridLayout_12->addWidget(textBrowserStudentForePitch, 2, 2, 1, 1);

        textBrowserStudentForeYaw = new QTextBrowser(gridLayoutWidget_9);
        textBrowserStudentForeYaw->setObjectName(QString::fromUtf8("textBrowserStudentForeYaw"));

        gridLayout_12->addWidget(textBrowserStudentForeYaw, 2, 3, 1, 1);

        label_28 = new QLabel(gridLayoutWidget_9);
        label_28->setObjectName(QString::fromUtf8("label_28"));

        gridLayout_12->addWidget(label_28, 0, 1, 1, 1);

        label_31 = new QLabel(gridLayoutWidget_9);
        label_31->setObjectName(QString::fromUtf8("label_31"));

        gridLayout_12->addWidget(label_31, 0, 2, 1, 1);

        label_29 = new QLabel(gridLayoutWidget_9);
        label_29->setObjectName(QString::fromUtf8("label_29"));

        gridLayout_12->addWidget(label_29, 0, 3, 1, 1);

        pushButtonExpStop = new QPushButton(tabExperiment);
        pushButtonExpStop->setObjectName(QString::fromUtf8("pushButtonExpStop"));
        pushButtonExpStop->setGeometry(QRect(580, 590, 81, 41));
        textBrowserHandCoorDelta = new QTextBrowser(tabExperiment);
        textBrowserHandCoorDelta->setObjectName(QString::fromUtf8("textBrowserHandCoorDelta"));
        textBrowserHandCoorDelta->setGeometry(QRect(700, 340, 61, 31));
        label_5 = new QLabel(tabExperiment);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(28, 350, 141, 20));
        label_13 = new QLabel(tabExperiment);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(30, 390, 141, 20));
        textBrowserElbowCoorDelta = new QTextBrowser(tabExperiment);
        textBrowserElbowCoorDelta->setObjectName(QString::fromUtf8("textBrowserElbowCoorDelta"));
        textBrowserElbowCoorDelta->setGeometry(QRect(700, 380, 61, 31));
        label_14 = new QLabel(tabExperiment);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(50, 430, 109, 13));
        textBrowserForeRollAngleDelta = new QTextBrowser(tabExperiment);
        textBrowserForeRollAngleDelta->setObjectName(QString::fromUtf8("textBrowserForeRollAngleDelta"));
        textBrowserForeRollAngleDelta->setGeometry(QRect(700, 420, 61, 31));
        pushButtonExpVisionShow = new QPushButton(tabExperiment);
        pushButtonExpVisionShow->setObjectName(QString::fromUtf8("pushButtonExpVisionShow"));
        pushButtonExpVisionShow->setGeometry(QRect(650, 100, 81, 21));
        pushButtonExpRecord = new QPushButton(tabExperiment);
        pushButtonExpRecord->setObjectName(QString::fromUtf8("pushButtonExpRecord"));
        pushButtonExpRecord->setGeometry(QRect(670, 590, 81, 41));
        comboBoxExpSimSeqSelection = new QComboBox(tabExperiment);
        comboBoxExpSimSeqSelection->setObjectName(QString::fromUtf8("ComboBoxExpSimSeqSelection"));
        comboBoxExpSimSeqSelection->setGeometry(QRect(610, 130, 139, 20));
        label_27 = new QLabel(tabExperiment);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(570, 130, 31, 20));
        label_43 = new QLabel(tabExperiment);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setGeometry(QRect(10, 180, 111, 16));
        label_44 = new QLabel(tabExperiment);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setGeometry(QRect(360, 180, 161, 16));
        label_45 = new QLabel(tabExperiment);
        label_45->setObjectName(QString::fromUtf8("label_45"));
        label_45->setGeometry(QRect(180, 310, 41, 20));
        label_46 = new QLabel(tabExperiment);
        label_46->setObjectName(QString::fromUtf8("label_46"));
        label_46->setGeometry(QRect(710, 310, 41, 16));
        textBrowserHandCoorTargetX = new QTextBrowser(tabExperiment);
        textBrowserHandCoorTargetX->setObjectName(QString::fromUtf8("textBrowserHandCoorTargetX"));
        textBrowserHandCoorTargetX->setGeometry(QRect(180, 340, 61, 31));
        textBrowserHandCoorTargetY = new QTextBrowser(tabExperiment);
        textBrowserHandCoorTargetY->setObjectName(QString::fromUtf8("textBrowserHandCoorTargetY"));
        textBrowserHandCoorTargetY->setGeometry(QRect(260, 340, 61, 31));
        textBrowserHandCoorTargetZ = new QTextBrowser(tabExperiment);
        textBrowserHandCoorTargetZ->setObjectName(QString::fromUtf8("textBrowserHandCoorTargetZ"));
        textBrowserHandCoorTargetZ->setGeometry(QRect(340, 340, 61, 31));
        textBrowserElbowCoorTargetZ = new QTextBrowser(tabExperiment);
        textBrowserElbowCoorTargetZ->setObjectName(QString::fromUtf8("textBrowserElbowCoorTargetZ"));
        textBrowserElbowCoorTargetZ->setGeometry(QRect(340, 380, 61, 31));
        textBrowserElbowCoorTargetY = new QTextBrowser(tabExperiment);
        textBrowserElbowCoorTargetY->setObjectName(QString::fromUtf8("textBrowserElbowCoorTargetY"));
        textBrowserElbowCoorTargetY->setGeometry(QRect(260, 380, 61, 31));
        textBrowserElbowCoorTargetX = new QTextBrowser(tabExperiment);
        textBrowserElbowCoorTargetX->setObjectName(QString::fromUtf8("textBrowserElbowCoorTargetX"));
        textBrowserElbowCoorTargetX->setGeometry(QRect(180, 380, 61, 31));
        textBrowserForeArmRollTarget = new QTextBrowser(tabExperiment);
        textBrowserForeArmRollTarget->setObjectName(QString::fromUtf8("textBrowserForeArmRollTarget"));
        textBrowserForeArmRollTarget->setGeometry(QRect(180, 420, 61, 31));
        textBrowserForeArmRollActual = new QTextBrowser(tabExperiment);
        textBrowserForeArmRollActual->setObjectName(QString::fromUtf8("textBrowserForeArmRollActual"));
        textBrowserForeArmRollActual->setGeometry(QRect(440, 420, 61, 31));
        textBrowserElbowCoorActualX = new QTextBrowser(tabExperiment);
        textBrowserElbowCoorActualX->setObjectName(QString::fromUtf8("textBrowserElbowCoorActualX"));
        textBrowserElbowCoorActualX->setGeometry(QRect(440, 380, 61, 31));
        textBrowserHandCoorActualZ = new QTextBrowser(tabExperiment);
        textBrowserHandCoorActualZ->setObjectName(QString::fromUtf8("textBrowserHandCoorActualZ"));
        textBrowserHandCoorActualZ->setGeometry(QRect(600, 340, 61, 31));
        textBrowserHandCoorActualY = new QTextBrowser(tabExperiment);
        textBrowserHandCoorActualY->setObjectName(QString::fromUtf8("textBrowserHandCoorActualY"));
        textBrowserHandCoorActualY->setGeometry(QRect(520, 340, 61, 31));
        textBrowserElbowCoorActualZ = new QTextBrowser(tabExperiment);
        textBrowserElbowCoorActualZ->setObjectName(QString::fromUtf8("textBrowserElbowCoorActualZ"));
        textBrowserElbowCoorActualZ->setGeometry(QRect(600, 380, 61, 31));
        textBrowserHandCoorActualX = new QTextBrowser(tabExperiment);
        textBrowserHandCoorActualX->setObjectName(QString::fromUtf8("textBrowserHandCoorActualX"));
        textBrowserHandCoorActualX->setGeometry(QRect(440, 340, 61, 31));
        textBrowserElbowCoorActualY = new QTextBrowser(tabExperiment);
        textBrowserElbowCoorActualY->setObjectName(QString::fromUtf8("textBrowserElbowCoorActualY"));
        textBrowserElbowCoorActualY->setGeometry(QRect(520, 380, 61, 31));
        label_47 = new QLabel(tabExperiment);
        label_47->setObjectName(QString::fromUtf8("label_47"));
        label_47->setGeometry(QRect(440, 310, 51, 20));
        horizontalLayoutWidget_6 = new QWidget(tabExperiment);
        horizontalLayoutWidget_6->setObjectName(QString::fromUtf8("horizontalLayoutWidget_6"));
        horizontalLayoutWidget_6->setGeometry(QRect(330, 30, 181, 22));
        horizontalLayout_10 = new QHBoxLayout(horizontalLayoutWidget_6);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        label_30 = new QLabel(horizontalLayoutWidget_6);
        label_30->setObjectName(QString::fromUtf8("label_30"));

        horizontalLayout_10->addWidget(label_30);

        comboBoxCandidateNumber = new QComboBox(horizontalLayoutWidget_6);
        comboBoxCandidateNumber->setObjectName(QString::fromUtf8("ComboBoxCandidateNumber"));

        horizontalLayout_10->addWidget(comboBoxCandidateNumber);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_6);

        label_48 = new QLabel(tabExperiment);
        label_48->setObjectName(QString::fromUtf8("label_48"));
        label_48->setGeometry(QRect(310, 10, 111, 16));
        pushButtonExpCalibration = new QPushButton(tabExperiment);
        pushButtonExpCalibration->setObjectName(QString::fromUtf8("pushButtonExpCalibration"));
        pushButtonExpCalibration->setGeometry(QRect(550, 30, 91, 21));
        labelMappingType = new QLabel(tabExperiment);
        labelMappingType->setObjectName(QString::fromUtf8("labelMappingType"));
        labelMappingType->setGeometry(QRect(50, 480, 711, 71));
        label_49 = new QLabel(tabExperiment);
        label_49->setObjectName(QString::fromUtf8("label_49"));
        label_49->setGeometry(QRect(10, 10, 91, 16));
        comboBoxNumberLoop = new QComboBox(tabExperiment);
        comboBoxNumberLoop->setObjectName(QString::fromUtf8("ComboBoxNumberLoop"));
        comboBoxNumberLoop->setGeometry(QRect(60, 30, 67, 20));
        tabWidgetMain->addTab(tabExperiment, QString());
        MappingAnalysis->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MappingAnalysis);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MappingAnalysis->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MappingAnalysis);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MappingAnalysis->setStatusBar(statusBar);
        menuBar = new QMenuBar(MappingAnalysis);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 868, 21));
        MappingAnalysis->setMenuBar(menuBar);

        retranslateUi(MappingAnalysis);
        QObject::connect(pushButtonIMUTestingTest, SIGNAL(clicked()), MappingAnalysis, SLOT(IMUtestStartClick()));
        QObject::connect(pushButtontextBrowserIMUTestingRecord, SIGNAL(clicked()), MappingAnalysis, SLOT(PostSavingClick()));
        QObject::connect(pushButtonArmMeasureRecord, SIGNAL(clicked()), MappingAnalysis, SLOT(ArmLengthRecClick()));
        QObject::connect(pushButtonVibroTestingTest, SIGNAL(clicked()), MappingAnalysis, SLOT(VibroTestStartClick()));
        QObject::connect(pushButtonExpVisionShow, SIGNAL(clicked()), MappingAnalysis, SLOT(expShowClick()));
        QObject::connect(pushButtonVibroTestingStop, SIGNAL(clicked()), MappingAnalysis, SLOT(VibroTestStopClick()));
        QObject::connect(pushButtonExpRecord, SIGNAL(clicked()), MappingAnalysis, SLOT(expRecordClick()));
        QObject::connect(pushButtonExpStart, SIGNAL(clicked()), MappingAnalysis, SLOT(expStartClick()));
        QObject::connect(pushButtonExpStop, SIGNAL(clicked()), MappingAnalysis, SLOT(expStopClick()));
        QObject::connect(pushButtonIMUTestingStop, SIGNAL(clicked()), MappingAnalysis, SLOT(IMUtestStopClick()));
        QObject::connect(pushButtonArmMeasureStart, SIGNAL(clicked()), MappingAnalysis, SLOT(ArmLengthStartClick()));
        QObject::connect(pushButtonThresholdRecord, SIGNAL(clicked()), MappingAnalysis, SLOT(ThresholdRecClick()));
        QObject::connect(pushButtonIMUTestingCalibration, SIGNAL(clicked()), MappingAnalysis, SLOT(IMUtestCalibrationClick()));
        QObject::connect(pushButtonExpCalibration, SIGNAL(clicked()), MappingAnalysis, SLOT(expCalibrationClick()));
        QObject::connect(pushButtonVibroTestingL2HAmp, SIGNAL(clicked()), MappingAnalysis, SLOT(VibroTestL2HAmpClick()));
        QObject::connect(pushButtonVibroTestingHighAmp, SIGNAL(clicked()), MappingAnalysis, SLOT(VibroTestHighAmpClick()));
        QObject::connect(pushButtonVibroTestingLowAmp, SIGNAL(clicked()), MappingAnalysis, SLOT(VibroTestLowAmpClick()));
        QObject::connect(pushButtonVibroTestingMappingPattern, SIGNAL(clicked()), MappingAnalysis, SLOT(VibroTestMappingPatternClick()));

        tabWidgetMain->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MappingAnalysis);
    } // setupUi

    void retranslateUi(QMainWindow *MappingAnalysis)
    {
        MappingAnalysis->setWindowTitle(QApplication::translate("MappingAnalysis", "Arm Mapping Experiment", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MappingAnalysis", "Option:", 0, QApplication::UnicodeUTF8));
        comboBoxArmMeasureOption->clear();
        comboBoxArmMeasureOption->insertItems(0, QStringList()
         << QApplication::translate("MappingAnalysis", "<None>", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MappingAnalysis", "Manual Measurement", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MappingAnalysis", "Automatical Measurement", 0, QApplication::UnicodeUTF8)
        );
        label_17->setText(QApplication::translate("MappingAnalysis", "Fore-Arm Length (mm):", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("MappingAnalysis", "Upper-Arm Length (mm):", 0, QApplication::UnicodeUTF8));
        pushButtonArmMeasureRecord->setText(QApplication::translate("MappingAnalysis", "Record", 0, QApplication::UnicodeUTF8));
        pushButtonArmMeasureStart->setText(QApplication::translate("MappingAnalysis", "Start", 0, QApplication::UnicodeUTF8));
        label_34->setText(QApplication::translate("MappingAnalysis", "Arm Length", 0, QApplication::UnicodeUTF8));
        label_35->setText(QApplication::translate("MappingAnalysis", "Threshold configuration", 0, QApplication::UnicodeUTF8));
        label_36->setText(QApplication::translate("MappingAnalysis", " Hand mapping", 0, QApplication::UnicodeUTF8));
        label_37->setText(QApplication::translate("MappingAnalysis", "Elbow mapping", 0, QApplication::UnicodeUTF8));
        label_38->setText(QApplication::translate("MappingAnalysis", "Roll ForeArm mapping", 0, QApplication::UnicodeUTF8));
        label_39->setText(QApplication::translate("MappingAnalysis", "Max1 (mm)", 0, QApplication::UnicodeUTF8));
        label_40->setText(QApplication::translate("MappingAnalysis", "Min1 (mm)", 0, QApplication::UnicodeUTF8));
        label_41->setText(QApplication::translate("MappingAnalysis", "Min (degree)", 0, QApplication::UnicodeUTF8));
        label_42->setText(QApplication::translate("MappingAnalysis", "Min1 (mm)", 0, QApplication::UnicodeUTF8));
        pushButtonThresholdRecord->setText(QApplication::translate("MappingAnalysis", "Record", 0, QApplication::UnicodeUTF8));
        label_50->setText(QApplication::translate("MappingAnalysis", "Max2 (mm)", 0, QApplication::UnicodeUTF8));
        label_51->setText(QApplication::translate("MappingAnalysis", "Min2 (mm)", 0, QApplication::UnicodeUTF8));
        label_52->setText(QApplication::translate("MappingAnalysis", "Min2 (mm)", 0, QApplication::UnicodeUTF8));
        tabWidgetMain->setTabText(tabWidgetMain->indexOf(tabArmMeasurement), QApplication::translate("MappingAnalysis", "Configuration", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MappingAnalysis", "IMU Testing", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MappingAnalysis", "Pitch (Y-degree)", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MappingAnalysis", "Yaw (Z-degree)", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MappingAnalysis", "Roll (X-degree)", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MappingAnalysis", "Upper-Arm", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("MappingAnalysis", "Fore-Arm", 0, QApplication::UnicodeUTF8));
        checkBoxIMUTestingSaving->setText(QApplication::translate("MappingAnalysis", "Saving as Posture number", 0, QApplication::UnicodeUTF8));
        pushButtontextBrowserIMUTestingRecord->setText(QApplication::translate("MappingAnalysis", "Record", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MappingAnalysis", "Vibro-tactile Testing", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MappingAnalysis", "Axis", 0, QApplication::UnicodeUTF8));
        comboBoxVibroTestingAxis->clear();
        comboBoxVibroTestingAxis->insertItems(0, QStringList()
         << QApplication::translate("MappingAnalysis", "<None>", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MappingAnalysis", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MappingAnalysis", "2", 0, QApplication::UnicodeUTF8)
        );
        label_12->setText(QApplication::translate("MappingAnalysis", "Duration (1-10s)", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MappingAnalysis", "Strength (0.1-1)", 0, QApplication::UnicodeUTF8));
        pushButtonIMUTestingStop->setText(QApplication::translate("MappingAnalysis", "Stop", 0, QApplication::UnicodeUTF8));
        pushButtonIMUTestingTest->setText(QApplication::translate("MappingAnalysis", "Test", 0, QApplication::UnicodeUTF8));
        comboBoxIMUSaving->clear();
        comboBoxIMUSaving->insertItems(0, QStringList()
         << QApplication::translate("MappingAnalysis", "<None>", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MappingAnalysis", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MappingAnalysis", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MappingAnalysis", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MappingAnalysis", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MappingAnalysis", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MappingAnalysis", "6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MappingAnalysis", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MappingAnalysis", "8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MappingAnalysis", "9", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MappingAnalysis", "10", 0, QApplication::UnicodeUTF8)
        );
        pushButtonVibroTestingStop->setText(QApplication::translate("MappingAnalysis", "Stop", 0, QApplication::UnicodeUTF8));
        pushButtonVibroTestingTest->setText(QApplication::translate("MappingAnalysis", "Test", 0, QApplication::UnicodeUTF8));
        pushButtonIMUTestingCalibration->setText(QApplication::translate("MappingAnalysis", "Calibration", 0, QApplication::UnicodeUTF8));
        pushButtonVibroTestingL2HAmp->setText(QApplication::translate("MappingAnalysis", "L2H Amp Pattern", 0, QApplication::UnicodeUTF8));
        pushButtonVibroTestingLowAmp->setText(QApplication::translate("MappingAnalysis", "Low Amp Pattern", 0, QApplication::UnicodeUTF8));
        pushButtonVibroTestingHighAmp->setText(QApplication::translate("MappingAnalysis", "High Amp Pattern", 0, QApplication::UnicodeUTF8));
        pushButtonVibroTestingMappingPattern->setText(QApplication::translate("MappingAnalysis", "Mapping Pattern", 0, QApplication::UnicodeUTF8));
        tabWidgetMain->setTabText(tabWidgetMain->indexOf(tabTesting), QApplication::translate("MappingAnalysis", "Testing", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("MappingAnalysis", "Pitch (Y-degree)", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("MappingAnalysis", "Yaw (Z-degree)", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("MappingAnalysis", "Roll (X-degree)", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MappingAnalysis", "Upper-Arm", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MappingAnalysis", "Fore-Arm", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("MappingAnalysis", "POSTURE SELECTION", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("MappingAnalysis", "Posture Number:", 0, QApplication::UnicodeUTF8));
        comboBoxMasterSelection->clear();
        comboBoxMasterSelection->insertItems(0, QStringList()
         << QApplication::translate("MappingAnalysis", "<None>", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MappingAnalysis", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MappingAnalysis", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MappingAnalysis", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MappingAnalysis", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MappingAnalysis", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MappingAnalysis", "6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MappingAnalysis", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MappingAnalysis", "8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MappingAnalysis", "9", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MappingAnalysis", "10", 0, QApplication::UnicodeUTF8)
        );
        label_24->setText(QApplication::translate("MappingAnalysis", "EXPERIMENT PARAMETERS", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("MappingAnalysis", "Vision Option", 0, QApplication::UnicodeUTF8));
        radioButtonExpVisionON->setText(QApplication::translate("MappingAnalysis", "ON", 0, QApplication::UnicodeUTF8));
        radioButtonExpVisionOFF->setText(QApplication::translate("MappingAnalysis", "OFF", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("MappingAnalysis", "Vibro-tactile Feedback", 0, QApplication::UnicodeUTF8));
        radioButtonExpVibroON->setText(QApplication::translate("MappingAnalysis", "ON", 0, QApplication::UnicodeUTF8));
        radioButtonExpVibroOFF->setText(QApplication::translate("MappingAnalysis", "OFF", 0, QApplication::UnicodeUTF8));
        comboBoxExpVisionPicVideoSelection->clear();
        comboBoxExpVisionPicVideoSelection->insertItems(0, QStringList()
         << QApplication::translate("MappingAnalysis", "<None>", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MappingAnalysis", "Picture", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MappingAnalysis", "Video", 0, QApplication::UnicodeUTF8)
        );
        pushButtonExpStart->setText(QApplication::translate("MappingAnalysis", "Start", 0, QApplication::UnicodeUTF8));
        label_32->setText(QApplication::translate("MappingAnalysis", "Upper-Arm", 0, QApplication::UnicodeUTF8));
        label_33->setText(QApplication::translate("MappingAnalysis", "Fore-Arm", 0, QApplication::UnicodeUTF8));
        label_28->setText(QApplication::translate("MappingAnalysis", "Roll (X-degree)", 0, QApplication::UnicodeUTF8));
        label_31->setText(QApplication::translate("MappingAnalysis", "Pitch (Y-degree)", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("MappingAnalysis", "Yaw (Z-degree)", 0, QApplication::UnicodeUTF8));
        pushButtonExpStop->setText(QApplication::translate("MappingAnalysis", "STOP", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MappingAnalysis", "Hand Coordinate (X-Y-Z:mm)", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MappingAnalysis", "Elbow Coordinate (X-Y-Z:mm)", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MappingAnalysis", "Fore-Arm Roll (degree)", 0, QApplication::UnicodeUTF8));
        pushButtonExpVisionShow->setText(QApplication::translate("MappingAnalysis", "Show", 0, QApplication::UnicodeUTF8));
        pushButtonExpRecord->setText(QApplication::translate("MappingAnalysis", "Record", 0, QApplication::UnicodeUTF8));
        comboBoxExpSimSeqSelection->clear();
        comboBoxExpSimSeqSelection->insertItems(0, QStringList()
         << QApplication::translate("MappingAnalysis", "<None>", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MappingAnalysis", "Simultaneous Feedback", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MappingAnalysis", "Sequential Feedback", 0, QApplication::UnicodeUTF8)
        );
        label_27->setText(QApplication::translate("MappingAnalysis", "Select", 0, QApplication::UnicodeUTF8));
        label_43->setText(QApplication::translate("MappingAnalysis", "MASTER POSTURE", 0, QApplication::UnicodeUTF8));
        label_44->setText(QApplication::translate("MappingAnalysis", "REAL-TIME (STUDENT POSTURE)", 0, QApplication::UnicodeUTF8));
        label_45->setText(QApplication::translate("MappingAnalysis", "TARGET ", 0, QApplication::UnicodeUTF8));
        label_46->setText(QApplication::translate("MappingAnalysis", "ERROR", 0, QApplication::UnicodeUTF8));
        label_47->setText(QApplication::translate("MappingAnalysis", "ACTUAL", 0, QApplication::UnicodeUTF8));
        label_30->setText(QApplication::translate("MappingAnalysis", "Candidate Number:", 0, QApplication::UnicodeUTF8));
        comboBoxCandidateNumber->clear();
        comboBoxCandidateNumber->insertItems(0, QStringList()
         << QApplication::translate("MappingAnalysis", "<None>", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MappingAnalysis", "0", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MappingAnalysis", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MappingAnalysis", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MappingAnalysis", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MappingAnalysis", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MappingAnalysis", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MappingAnalysis", "6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MappingAnalysis", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MappingAnalysis", "8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MappingAnalysis", "9", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MappingAnalysis", "10", 0, QApplication::UnicodeUTF8)
        );
        label_48->setText(QApplication::translate("MappingAnalysis", "SUBJECT SELECTION", 0, QApplication::UnicodeUTF8));
        pushButtonExpCalibration->setText(QApplication::translate("MappingAnalysis", "Calibration", 0, QApplication::UnicodeUTF8));
        labelMappingType->setText(QString());
        label_49->setText(QApplication::translate("MappingAnalysis", "NUMBER OF LOOP", 0, QApplication::UnicodeUTF8));
        comboBoxNumberLoop->clear();
        comboBoxNumberLoop->insertItems(0, QStringList()
         << QApplication::translate("MappingAnalysis", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MappingAnalysis", "1", 0, QApplication::UnicodeUTF8)
        );
        tabWidgetMain->setTabText(tabWidgetMain->indexOf(tabExperiment), QApplication::translate("MappingAnalysis", "Experiment", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MappingAnalysis: public Ui_MappingAnalysis {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPPINGANALYSIS_H
