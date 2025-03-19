/*
 * This file is part of Biochemistry.
 *
 * Biochemistry is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Biochemistry is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with <Your Project Name>. If not, see <https://www.gnu.org/licenses/>.
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"
QString ICON_PATH ="/home/pi/git/BCYWithTRY/BCYWithTRY/img/";

void MainWindow::Biochemistry_CSS()
{
    //Buttons Color Change

    ui->stackedWidget->setStyleSheet("background-color: #f4f4fc;");
    ui->frame_5->setStyleSheet("background-color:#f4f4fc;");
    ui->Logo_Btn_3->setStyleSheet("QPushButton{"
                                  "background-color: #f4f4fc;"
                                  "border-radius: 100px;"
                                  "min-width: 200px;"
                                  "max-width: 200px;"
                                  "min-height: 200px;"
                                  "max-height: 200px;"
                                  "}");
    QString toolButtonMenuStyle =
            "QToolButton{"
            "background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(12, 68, 145), stop: 0.5 rgb(12, 68, 145),  stop:1 rgb(12, 68, 145));"
            "border-radius: 25px;"
            "color: rgb(255, 255, 255);"
            "border: 1px solid black;"
            "padding-top: 25px;"
            "background-position: center bottom;"
            "background-repeat: no-repeat;"
            "background-origin: content;"
            "}"
            "QToolButton::hover{"
            "background-color: qlineargradient(spread:pad, x1:0, y1:0.0913636, x2:0.944, y2:0.392, stop:0.0969388 rgba(22, 123, 200, 255), stop:1 rgba(20, 113, 180, 255));"
            "}"
            "QToolButton::pressed{"
            "margin-top: 2px;"
            "margin-bottom: -4px;"
            "}";

    ui->toolButton_6->setStyleSheet(toolButtonMenuStyle);
    ui->toolButton_7->setStyleSheet(toolButtonMenuStyle);
    ui->toolButton_8->setStyleSheet(toolButtonMenuStyle);
    ui->toolButton_9->setStyleSheet(toolButtonMenuStyle);

    QString ButtonsStyle =
            "QPushButton{"
            "background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(12, 68, 145), stop: 0.5 rgb(12, 68, 145),  stop:1 rgb(12, 68, 145));"
            "border:1px solid black;"
            "color: white;"
            "}"
            "QPushButton:hover"
            "{"
            "background-color: qlineargradient(spread:pad, x1:0, y1:0.0913636, x2:0.944, y2:0.392, stop:0.0969388 rgba(22, 123, 200, 255), stop:1 rgba(20, 113, 180, 255));"
            "color:white;"
            "}"
            "QPushButton:disabled {"
            "background-color: rgb(170, 170, 127);"
            "color:black;"
            "}";

    //Settings
    ui->pushButton_10->setStyleSheet(ButtonsStyle); //Date&Time Change
    ui->pushButton_131->setStyleSheet(ButtonsStyle); //Multiplication factor
    ui->pushButton_148->setStyleSheet(ButtonsStyle); //Check for update
    ui->pushButton_134->setStyleSheet(ButtonsStyle); //LIS setup
    ui->pushButton_4->setStyleSheet(ButtonsStyle); //Wifi setup
    ui->pushButton_258->setStyleSheet(ButtonsStyle); //Brightness
    ui->pushButton_239->setStyleSheet(ButtonsStyle); //Login
    ui->pushButton_251->setStyleSheet(ButtonsStyle); //User
    ui->pushButton_252->setStyleSheet(ButtonsStyle); //Service
    ui->pushButton_253->setStyleSheet(ButtonsStyle); //Maintainer
    ui->pushButton_7->setStyleSheet(ButtonsStyle); //AD Gain
    ui->pushButton_11->setStyleSheet(ButtonsStyle); //S/w Updgrade
    ui->pushButton_231->setStyleSheet(ButtonsStyle); //Internal Printer
    ui->pushButton_227->setStyleSheet(ButtonsStyle); //Distributor Code
    ui->pushButton_151->setStyleSheet(ButtonsStyle); //Internal Printer Config Btn
    ui->pushButton_271->setStyleSheet(ButtonsStyle); //Check availabel network
    ui->pushButton_12->setStyleSheet(ButtonsStyle); //Connect Btn
    ui->pushButton_8->setStyleSheet(ButtonsStyle); //340nm
    ui->pushButton_9->setStyleSheet(ButtonsStyle); //405nm
    ui->pushButton_24->setStyleSheet(ButtonsStyle); //505nm
    ui->pushButton_26->setStyleSheet(ButtonsStyle); //545nm
    ui->pushButton_128->setStyleSheet(ButtonsStyle); //570nm
    ui->pushButton_129->setStyleSheet(ButtonsStyle); //630nm
    ui->pushButton_130->setStyleSheet(ButtonsStyle); //700nm
    ui->pushButton_149->setStyleSheet(ButtonsStyle); //700nm
    ui->pushButton_132->setStyleSheet(ButtonsStyle); //700nm
    ui->pushButton_133->setStyleSheet(ButtonsStyle); //700nm
    ui->EndPoint_Save_Btn->setStyleSheet(ButtonsStyle); //700nm
    ui->EndPoint_Print_Btn->setStyleSheet(ButtonsStyle); //700nm
    ui->pushButton_297->setStyleSheet(ButtonsStyle); //700nm
    ui->pushButton_299->setStyleSheet(ButtonsStyle); //700nm
    ui->pushButton_321->setStyleSheet(ButtonsStyle); //700nm
    ui->pushButton_328->setStyleSheet(ButtonsStyle); //700nm
    ui->pushButton_331->setStyleSheet(ButtonsStyle); //700nm
    ui->pushButton_333->setStyleSheet(ButtonsStyle); //700nm
    ui->pushButton_309->setStyleSheet(ButtonsStyle); //700nm
    ui->pushButton_279->setStyleSheet(ButtonsStyle); //700nm
    ui->pushButton_226->setStyleSheet(ButtonsStyle); //700nm
    ui->pushButton_263->setStyleSheet(ButtonsStyle); //700nm
    ui->pushButton_264->setStyleSheet(ButtonsStyle); //700nm
    ui->pushButton_256->setStyleSheet(ButtonsStyle); //700nm
    ui->pushButton_240->setStyleSheet(ButtonsStyle); //700nm
    ui->pushButton_191->setStyleSheet(ButtonsStyle); //700nm
    ui->pushButton_192->setStyleSheet(ButtonsStyle); //700nm
    ui->pushButton_194->setStyleSheet(ButtonsStyle); //700nm
    ui->pushButton_193->setStyleSheet(ButtonsStyle); //700nm
    ui->pushButton->setStyleSheet(ButtonsStyle); //700nm
    ui->pushButton_2->setStyleSheet(ButtonsStyle); //700nm
    ui->pushButton_3->setStyleSheet(ButtonsStyle); //700nm
    ui->pushButton_5->setStyleSheet(ButtonsStyle); //700nm
    ui->Load_Btn->setStyleSheet(ButtonsStyle); //700nm
    ui->Load_Btn_2->setStyleSheet(ButtonsStyle); //700nm

    ui->pushButton_254->setStyleSheet(ButtonsStyle); //700nm
    ui->pushButton_255->setStyleSheet(ButtonsStyle); //700nm
    ui->pushButton_259->setStyleSheet(ButtonsStyle); //700nm
    ui->pushButton_260->setStyleSheet(ButtonsStyle); //700nm
    ui->pushButton_268->setStyleSheet(ButtonsStyle); //700nm
    ui->pushButton_269->setStyleSheet(ButtonsStyle); //700nm
    ui->pushButton_248->setStyleSheet(ButtonsStyle); //700nm
    ui->pushButton_250->setStyleSheet(ButtonsStyle); //700nm
    ui->pushButton_261->setStyleSheet(ButtonsStyle); //700nm
    ui->pushButton_276->setStyleSheet(ButtonsStyle); //700nm

    QString ButtonsTStyle =
            "QToolButton{"
            "background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(12, 68, 145), stop: 0.5 rgb(12, 68, 145),  stop:1 rgb(12, 68, 145));"
            "border:1px solid black;"
            "color: white;"
            "}"
            "QToolButton:hover"
            "{"
            "background-color: qlineargradient(spread:pad, x1:0, y1:0.0913636, x2:0.944, y2:0.392, stop:0.0969388 rgba(22, 123, 200, 255), stop:1 rgba(20, 113, 180, 255));"
            "color:white;"
            "}"
            "QToolButton:disabled {"
            "background-color: rgb(170, 170, 127);"
            "color:black;"
            "}";

    ui->toolButton->setStyleSheet(ButtonsTStyle); //Printer Setup
    ui->toolButton_55->setStyleSheet(ButtonsTStyle); //Internal Demo Printer Btn
    ui->toolButton_2->setStyleSheet(ButtonsTStyle); //Internal Demo Printer Btn
    ui->toolButton_10->setStyleSheet(ButtonsTStyle); //Internal Demo Printer Btn
    ui->toolButton_25->setStyleSheet(ButtonsTStyle); //Internal Demo Printer Btn
    ui->toolButton_27->setStyleSheet(ButtonsTStyle); //Internal Demo Printer Btn
    ui->toolButton_11->setStyleSheet(ButtonsTStyle); //Internal Demo Printer Btn
    ui->toolButton_28->setStyleSheet(ButtonsTStyle); //Internal Demo Printer Btn
    ui->toolButton_3->setStyleSheet(ButtonsTStyle); //Internal Demo Printer Btn
    ui->toolButton_4->setStyleSheet(ButtonsTStyle); //700nm
    ui->toolButton_5->setStyleSheet(ButtonsTStyle); //700nm

    //Internal Printer Config
    QString ButtonsCStyle =
            "QComboBox {"
            "   background: rgb(12, 68, 145);"
            "   border: 1px solid gray;"
            "   color: white;"
            "   font-weight: bold;"
            "}"
            "QComboBox::drop-down {"
            "   border: none;"
            "}"
            "QComboBox QAbstractItemView {"
            "   background: rgb(12, 68, 145);"
            "   border: 1px solid gray;"
            "   selection-background-color: rgb(30, 100, 200);"
            "   selection-color: white;"
            "}"
            "QComboBox QAbstractItemView::item {"
            "   background: rgb(12, 68, 145);"
            "   color: white;"
            "   padding: 5px;"
            "}"
            "QComboBox QAbstractItemView::item:selected {"
            "   background: rgb(30, 100, 200);"
            "   color: white;"
            "}"
            "QComboBox::focus {"
            "   background: rgb(12, 68, 145);"
            "}"
            "QComboBox::indicator {"
            "   background: rgb(12, 68, 145);"
            "}";

    ui->comboBox_11->setStyleSheet(ButtonsCStyle);



    /*QString ButtonsCStyle =
            "QComboBox{"
            "background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(12, 68, 145), stop: 0.5 rgb(12, 68, 145),  stop:1 rgb(12, 68, 145));"
            "border:1px solid gray;"
            "color: rgb(255, 255, 255);"
            "font-style:bold;"
            "}"
            "QComboBox::drop-down {"
              "   background: rgb(30, 100, 200);"
              "   border: none;"
              "   width: 20px;"
              "}"
 "QComboBox::down-arrow {"
    "   image: url(:/icons/down-arr.png);"  // Change to your icon path
    "   width: 16px;"  // Adjust size of icon
    "   height: 16px;"
    "}"
            "QComboBox QAbstractItemView::item:selected {"
            "background: rgb(30, 100, 200);"  // Highlight color for selection
            "color: black;"
            "}"
            "QComboBox::hover{"
            "background-color: qlineargradient(spread:pad, x1:0, y1:0.0913636, x2:0.944, y2:0.392, stop:0.0969388 rgba(22, 123, 200, 255), stop:1 rgba(20, 113, 180, 255));"
            "}";

    ui->comboBox_11->setStyleSheet(ButtonsCStyle);*/
    ui->comboBox_17->setStyleSheet(ButtonsCStyle);
    ui->comboBox_14->setStyleSheet(ButtonsCStyle);
    ui->comboBox_18->setStyleSheet(ButtonsCStyle);
    ui->comboBox_4->setStyleSheet(ButtonsCStyle);
    ui->comboBox_10->setStyleSheet(ButtonsCStyle);
    ui->comboBox_13->setStyleSheet(ButtonsCStyle);
    ui->comboBox_12->setStyleSheet(ButtonsCStyle);
    ui->comboBox_16->setStyleSheet(ButtonsCStyle);
    ui->comboBox_9->setStyleSheet(ButtonsCStyle);
    ui->timeZoneComboBox_2->setStyleSheet(ButtonsCStyle);

    ui->Menu_Btn_2->setIcon(QIcon(ICON_PATH + "BioMenu.png"));
    qDebug()<<"Path : "<<ICON_PATH + "BioMenu.png";
    ui->Menu_Btn_2->setIconSize(QSize(50, 50));

    ui->Setting_Btn->setIcon(QIcon(ICON_PATH + "BioSettings.png"));
    ui->Setting_Btn->setIconSize(QSize(45, 45));

    ui->Power_Btn->setIcon(QIcon(ICON_PATH + "BioPoweroff.png"));
    ui->Power_Btn->setIconSize(QSize(45, 45));

    ui->Home_Btn_24->setIcon(QIcon(ICON_PATH + "BioBack.png"));
    ui->Home_Btn_24->setIconSize(QSize(50, 50));
    ui->Home_Btn_22->setIcon(QIcon(ICON_PATH + "BioBack.png"));
    ui->Home_Btn_22->setIconSize(QSize(50, 50));
    ui->Home_Btn_15->setIcon(QIcon(ICON_PATH + "BioBack.png"));
    ui->Home_Btn_15->setIconSize(QSize(50, 50));
    ui->Home_Btn_23->setIcon(QIcon(ICON_PATH + "BioBack.png"));
    ui->Home_Btn_23->setIconSize(QSize(50, 50));
    ui->Home_Btn_21->setIcon(QIcon(ICON_PATH + "BioBack.png"));
    ui->Home_Btn_21->setIconSize(QSize(50, 50));
    ui->Home_Btn_17->setIcon(QIcon(ICON_PATH + "BioBack.png"));
    ui->Home_Btn_17->setIconSize(QSize(50, 50));
    ui->Home_Btn_25->setIcon(QIcon(ICON_PATH + "BioBack.png"));
    ui->Home_Btn_25->setIconSize(QSize(50, 50));
    ui->Home_Btn_12->setIcon(QIcon(ICON_PATH + "BioBack.png"));
    ui->Home_Btn_12->setIconSize(QSize(50, 50));
    ui->toolButton_16->setIcon(QIcon(ICON_PATH + "BioBack.png"));
    ui->toolButton_16->setIconSize(QSize(50, 50));
    ui->Home_Btn_19->setIcon(QIcon(ICON_PATH + "BioBack.png"));
    ui->Home_Btn_19->setIconSize(QSize(50, 50));
    ui->Home_Btn_18->setIcon(QIcon(ICON_PATH + "BioBack.png"));
    ui->Home_Btn_18->setIconSize(QSize(50, 50));
    ui->Home_Btn_11->setIcon(QIcon(ICON_PATH + "BioBack.png"));
    ui->Home_Btn_11->setIconSize(QSize(50, 50));
    ui->Home_Btn_13->setIcon(QIcon(ICON_PATH + "BioBack.png"));
    ui->Home_Btn_13->setIconSize(QSize(50, 50));
    ui->Home_Btn_23->setIcon(QIcon(ICON_PATH + "BioBack.png"));
    ui->Home_Btn_23->setIconSize(QSize(50, 50));
    ui->toolButton_19->setIcon(QIcon(ICON_PATH + "BioBack.png"));
    ui->toolButton_19->setIconSize(QSize(50, 50));
    ui->toolButton_18->setIcon(QIcon(ICON_PATH + "BioBack.png"));
    ui->toolButton_18->setIconSize(QSize(50, 50));
    ui->toolButton_17->setIcon(QIcon(ICON_PATH + "BioBack.png"));
    ui->toolButton_17->setIconSize(QSize(50, 50));
    ui->toolButton_20->setIcon(QIcon(ICON_PATH + "BioBack.png"));
    ui->toolButton_20->setIconSize(QSize(50, 50));
    ui->toolButton_21->setIcon(QIcon(ICON_PATH + "BioBack.png"));
    ui->toolButton_21->setIconSize(QSize(50, 50));
    ui->toolButton_56->setIcon(QIcon(ICON_PATH + "BioBack.png"));
    ui->toolButton_56->setIconSize(QSize(50, 50));
    ui->Settings_Back_Btn->setIcon(QIcon(ICON_PATH + "BioBack.png"));
    ui->Settings_Back_Btn->setIconSize(QSize(50, 50));
    ui->Settings_Back_Btn_2->setIcon(QIcon(ICON_PATH + "BioBack.png"));
    ui->Settings_Back_Btn_2->setIconSize(QSize(50, 50));
    ui->toolButton_14->setIcon(QIcon(ICON_PATH + "BioHome.png"));
    ui->toolButton_14->setIconSize(QSize(50, 50));
    ui->Home_Btn_2->setIcon(QIcon(ICON_PATH + "BioBack.png"));
    ui->Home_Btn_2->setIconSize(QSize(50, 50));
    ui->Home_Btn_4->setIcon(QIcon(ICON_PATH + "BioBack.png"));
    ui->Home_Btn_4->setIconSize(QSize(50, 50));
    ui->toolButton_13->setIcon(QIcon(ICON_PATH + "BioHome.png"));
    ui->toolButton_13->setIconSize(QSize(50, 50));
    ui->toolButton_22->setIcon(QIcon(ICON_PATH + "BioBack.png"));
    ui->toolButton_22->setIconSize(QSize(50, 50));
    ui->toolButton_23->setIcon(QIcon(ICON_PATH + "BioBack.png"));
    ui->toolButton_23->setIconSize(QSize(50, 50));
    ui->toolButton_15->setIcon(QIcon(ICON_PATH + "BioBack.png"));
    ui->toolButton_15->setIconSize(QSize(50, 50));
    ui->Home_Btn_19->setIcon(QIcon(ICON_PATH + "BioBack.png"));
    ui->Home_Btn_19->setIconSize(QSize(50, 50));

    ui->Home_Btn_26->setIcon(QIcon(ICON_PATH + "BioBack.png"));
    ui->Home_Btn_26->setIconSize(QSize(50, 50));
    ui->Home_Btn_27->setIcon(QIcon(ICON_PATH + "BioBack.png"));
    ui->Home_Btn_27->setIconSize(QSize(50, 50));
    ui->Home_Btn_28->setIcon(QIcon(ICON_PATH + "BioBack.png"));
    ui->Home_Btn_28->setIconSize(QSize(50, 50));
    ui->toolButton_73->setIcon(QIcon(ICON_PATH + "BioBack.png"));
    ui->toolButton_73->setIconSize(QSize(50, 50));
    ui->toolButton_74->setIcon(QIcon(ICON_PATH + "BioBack.png"));
    ui->toolButton_74->setIconSize(QSize(50, 50));

    ui->Home_Btn_14->setIcon(QIcon(ICON_PATH + "BioBack.png"));
    ui->Home_Btn_14->setIconSize(QSize(50, 50));
    ui->Home_Btn_15->setIcon(QIcon(ICON_PATH + "BioBack.png"));
    ui->Home_Btn_15->setIconSize(QSize(50, 50));
    ui->Home_Btn_16->setIcon(QIcon(ICON_PATH + "BioHome.png"));
    ui->Home_Btn_16->setIconSize(QSize(50, 50));
}
