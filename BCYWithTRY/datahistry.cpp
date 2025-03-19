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
#include <iostream>
#include "printer.h"
static QString array[100]={""};

void MainWindow::on_toolButton_9_clicked()
{
    ui->stackedWidget_11->setVisible(false);
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_Load_Btn_clicked()
{
    ui->tableView->verticalScrollBar()->setStyleSheet("QScrollBar:vertical {"
                                                      "    border: 1px solid #999999;"
                                                      "    background:white;"
                                                      "    width:25px;    "
                                                      "    margin: 0px 0px 0px 0px;"
                                                      "}"
                                                      "QScrollBar::handle:vertical {"
                                                      "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
                                                      "    stop: 0 rgb(12, 68, 145), stop: 0.5 rgb(12, 68, 145), stop:1 rgb(12, 68, 145));"
                                                      "    min-height: 0px;"
                                                      "}"
                                                      "QScrollBar::add-line:vertical {"
                                                      "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
                                                      "    stop: 0 rgb(12, 68, 145), stop: 0.5 rgb(12, 68, 145),  stop:1 rgb(12, 68, 145));"
                                                      "    height: 0px;"
                                                      "    subcontrol-position: bottom;"
                                                      "    subcontrol-origin: margin;"
                                                      "}"
                                                      "QScrollBar::sub-line:vertical {"
                                                      "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
                                                      "    stop: 0  rgb(12, 68, 145), stop: 0.5 rgb(12, 68, 145),  stop:1 rgb(12, 68, 145));"
                                                      "    height: 0 px;"
                                                      "    subcontrol-position: top;"
                                                      "    subcontrol-origin: margin;"
                                                      "}"
                                                      );
    ui->tableView->horizontalScrollBar()->setStyleSheet(
                "QScrollBar:horizontal { ""    border: 1px solid #999999;"
                "    background:white;"
                "    height:25px;    "
                "    margin: 0px 0px 0px 0px;"
                "}"
                "QScrollBar::handle:horizontal {"
                "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
                "    stop: 0 rgb(12, 68, 145), stop: 0.5 rgb(12, 68, 145), stop:1 rgb(12, 68, 145));"
                "    min-height: 0px;"
                "}"
                "QScrollBar::add-line:horizontal {"
                "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
                "    stop: 0 rgb(12, 68, 145), stop: 0.5 rgb(12, 68, 145),  stop:1 rgb(12, 68, 145));"
                "    height: 0px;"
                "    subcontrol-position: bottom;"
                "    subcontrol-origin: margin;"
                "}"
                "QScrollBar::sub-line:horizontal {"
                "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
                "    stop: 0  rgb(12, 68, 145), stop: 0.5 rgb(12, 68, 145),  stop:1 rgb(12, 68, 145));"
                "    height: 0 px;"
                "    subcontrol-position: top;"
                "    subcontrol-origin: margin;"
                "}");
    ui->tableView->verticalHeader()->setVisible(true);
    ui->tableView->horizontalHeader()->setVisible(true);
    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery* query=new QSqlQuery(mydb);
    if(Test_Type=="Biochemistry")
    {
        query->prepare("select name,Pro_Code,wave,rctn,unit,temp,fact,blnk,dely,read,lag,linmin,linmax,normin,normax,Batch_No,con1,con2,con3,con4,con5,con6,con7,con8,ctrl1avg,ctrl1min,ctrl1max,ctrl1bno,ctrl2avg,ctrl2min,ctrl2max,ctrl2bno,calibrateabs from test ");
        query->exec();
        modal->setQuery(*query);
        qDebug()<<"Model row cnt : "<<modal->rowCount();

        modal->setHeaderData( 0, Qt::Horizontal, QObject::tr("Parameter name") );
        modal->setHeaderData( 1, Qt::Horizontal, QObject::tr("Test code") );
        modal->setHeaderData( 2, Qt::Horizontal, QObject::tr("Wavelength") );
        modal->setHeaderData( 3, Qt::Horizontal, QObject::tr("Reaction type") );
        modal->setHeaderData( 4, Qt::Horizontal, QObject::tr("Unit") );
        modal->setHeaderData( 5, Qt::Horizontal, QObject::tr("Temperature") );
        modal->setHeaderData( 6, Qt::Horizontal, QObject::tr("Factor") );
        modal->setHeaderData( 7, Qt::Horizontal, QObject::tr("Blank type") );
        modal->setHeaderData( 8, Qt::Horizontal, QObject::tr("Delay time(S)") );
        modal->setHeaderData( 9, Qt::Horizontal, QObject::tr("Reading time(S)") );
        modal->setHeaderData( 10, Qt::Horizontal, QObject::tr("No.of readings") );
        modal->setHeaderData( 11, Qt::Horizontal, QObject::tr("Linear range(min)") );
        modal->setHeaderData( 12, Qt::Horizontal, QObject::tr("Linear range(max)") );
        modal->setHeaderData( 13, Qt::Horizontal, QObject::tr("Normal range(min)") );
        modal->setHeaderData( 14, Qt::Horizontal, QObject::tr("Normal range(max)") );
        modal->setHeaderData( 15, Qt::Horizontal, QObject::tr("Lot no") );
        modal->setHeaderData( 16, Qt::Horizontal, QObject::tr("Concentration 1") );
        modal->setHeaderData( 17, Qt::Horizontal, QObject::tr("Concentration 2") );
        modal->setHeaderData( 18, Qt::Horizontal, QObject::tr("Concentration 3") );
        modal->setHeaderData( 19, Qt::Horizontal, QObject::tr("Concentration 4") );
        modal->setHeaderData( 20, Qt::Horizontal, QObject::tr("Concentration 5") );
        modal->setHeaderData( 21, Qt::Horizontal, QObject::tr("Concentration 6") );
        modal->setHeaderData( 22, Qt::Horizontal, QObject::tr("Concentration 7") );
        modal->setHeaderData( 23, Qt::Horizontal, QObject::tr("Concentration 8") );
        modal->setHeaderData( 24, Qt::Horizontal, QObject::tr("Control1-Average") );
        modal->setHeaderData( 25, Qt::Horizontal, QObject::tr("Control1-Minimum") );
        modal->setHeaderData( 26, Qt::Horizontal, QObject::tr("Control1-Maximum") );
        modal->setHeaderData( 27, Qt::Horizontal, QObject::tr("Control1-Lotno") );
        modal->setHeaderData( 28, Qt::Horizontal, QObject::tr("Control2-Average") );
        modal->setHeaderData( 29, Qt::Horizontal, QObject::tr("Control2-Minimum") );
        modal->setHeaderData( 30, Qt::Horizontal, QObject::tr("Control2-Maximum") );
        modal->setHeaderData( 31, Qt::Horizontal, QObject::tr("Control2-Lotno") );
        modal->setHeaderData( 32, Qt::Horizontal, QObject::tr("Calibrate-Abs") );

        ui->tableView->setModel(modal);
        ui->tableView->resizeColumnsToContents() ;
        ui->stackedWidget->setCurrentIndex(8);

    }
    else if(Test_Type=="Turbidity")
    {
        query->prepare("select TestName,TestCode,Wave,Unit,Temp,Fact,Blank,Incubation,Graph_Type,No_of_Cal,Cal1,Cal2,Cal3,Cal4,Cal5,Cal6,Cal7,Cal8,LinMin,LinMax,NorMin,NorMax,Ctrl1Avg,Ctrl1Min,Ctrl1Max,Ctrl1Bno,Ctrl2Avg,Ctrl2Min,Ctrl2Max,Ctrl2Bno,Batch_No,Reaction_Type from Turbidity_test ");
        query->exec();
        modal->setQuery(*query);
        modal->setHeaderData( 0, Qt::Horizontal, QObject::tr("Parameter Name") );
        modal->setHeaderData( 1, Qt::Horizontal, QObject::tr("Test code") );
        modal->setHeaderData( 2, Qt::Horizontal, QObject::tr("Wavelength") );
        modal->setHeaderData( 3, Qt::Horizontal, QObject::tr("Unit") );
        modal->setHeaderData( 4, Qt::Horizontal, QObject::tr("Temperature") );
        modal->setHeaderData( 5, Qt::Horizontal, QObject::tr("Factor") );
        modal->setHeaderData( 6, Qt::Horizontal, QObject::tr("Blank type") );
        modal->setHeaderData( 7, Qt::Horizontal, QObject::tr("Incubation") );
        modal->setHeaderData( 8, Qt::Horizontal, QObject::tr("Graph type") );
        modal->setHeaderData( 9, Qt::Horizontal, QObject::tr("Reading time(S)") );
        modal->setHeaderData( 10, Qt::Horizontal, QObject::tr("Concentration 1") );
        modal->setHeaderData( 11, Qt::Horizontal, QObject::tr("Concentration 2") );
        modal->setHeaderData( 12, Qt::Horizontal, QObject::tr("Concentration 3") );
        modal->setHeaderData( 13, Qt::Horizontal, QObject::tr("Concentration 4") );
        modal->setHeaderData( 14, Qt::Horizontal, QObject::tr("Concentration 5") );
        modal->setHeaderData( 15, Qt::Horizontal, QObject::tr("Concentration 6") );
        modal->setHeaderData( 16, Qt::Horizontal, QObject::tr("Concentration 7") );
        modal->setHeaderData( 17, Qt::Horizontal, QObject::tr("Concentration 8") );
        modal->setHeaderData( 18, Qt::Horizontal, QObject::tr("Linear Range(Min)") );
        modal->setHeaderData( 19, Qt::Horizontal, QObject::tr("Linear Range(Max)") );
        modal->setHeaderData( 20, Qt::Horizontal, QObject::tr("Normal Range(Min)") );
        modal->setHeaderData( 21, Qt::Horizontal, QObject::tr("Normal Range(Max)") );
        modal->setHeaderData( 22, Qt::Horizontal, QObject::tr("Control1-Average") );
        modal->setHeaderData( 23, Qt::Horizontal, QObject::tr("Control1-Minimum") );
        modal->setHeaderData( 24, Qt::Horizontal, QObject::tr("Control1-Maximum") );
        modal->setHeaderData( 25, Qt::Horizontal, QObject::tr("Control1-Lotno") );
        modal->setHeaderData( 26, Qt::Horizontal, QObject::tr("Control2-Average") );
        modal->setHeaderData( 27, Qt::Horizontal, QObject::tr("Control2-Minimum") );
        modal->setHeaderData( 28, Qt::Horizontal, QObject::tr("Control2-Maximum") );
        modal->setHeaderData( 29, Qt::Horizontal, QObject::tr("Control2-Lotno") );
        modal->setHeaderData( 30, Qt::Horizontal, QObject::tr("Batch No") );
        modal->setHeaderData( 31, Qt::Horizontal, QObject::tr("Reaction type") );
        ui->tableView->setModel(modal);
        ui->tableView->resizeColumnsToContents() ;
        ui->stackedWidget->setCurrentIndex(8);
    }
}

void MainWindow::on_toolButton_13_clicked()
{
    ui->tableView->verticalScrollBar()->setStyleSheet(
                "QScrollBar:vertical { width: 100px; }");
    ui->stackedWidget->setCurrentIndex(0);
}


// ///////////////////////////// Internal Printer ////////////////////////////////

void MainWindow::on_Load_Btn_2_clicked()
{
    ui->frame_13->setVisible(false);
    ui->frame_14->setVisible(false);
    ui->frame_15->setVisible(false);
    ui->label_85->setVisible(false);
    ui->pushButton_15->setVisible(false);
    ui->comboBox_19->setVisible(false);
    ui->pushButton_254->setEnabled(false);
    ui->label_438->setVisible(false);
    ui->tableView_2->setModel(nullptr);
    ui->tableView_5->setModel(nullptr);
    ui->label_428->setVisible(false);
    ui->label_431->setVisible(false);

    ui->label_450->setVisible(false);
    ui->label_451->setVisible(false);

    ui->pushButton_294->setVisible(false);
    ui->label_432->setVisible(false);
    ui->label_433->setVisible(false);
    ui->pushButton_293->setVisible(false);

    ui->label_438->setVisible(false);
    ui->frame_12->setVisible(false);
    ui->toolButton_23->setEnabled(true);
    ui->toolButton_45->setEnabled(true);
    ui->pushButton_248->setEnabled(true);
    ui->pushButton_250->setEnabled(true);
    ui->frame_64->setEnabled(true);
    ui->frame_64->setVisible(true);
    if(Test_Type=="Biochemistry")
    {
        ui->tableView_2->verticalScrollBar()->setStyleSheet("QScrollBar:vertical {"
                                                            "    border: 1px solid #999999;"
                                                            "    background:white;"
                                                            "    width:25px;    "
                                                            "    margin: 0px 0px 0px 0px;"
                                                            "}"
                                                            "QScrollBar::handle:vertical {"
                                                            "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
                                                            "    stop: 0 rgb(12, 68, 145), stop: 0.5 rgb(12, 68, 145), stop:1 rgb(12, 68, 145));"
                                                            "    min-height: 0px;"
                                                            "}"
                                                            "QScrollBar::add-line:vertical {"
                                                            "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
                                                            "    stop: 0 rgb(12, 68, 145), stop: 0.5 rgb(12, 68, 145),  stop:1 rgb(12, 68, 145));"
                                                            "    height: 0px;"
                                                            "    subcontrol-position: bottom;"
                                                            "    subcontrol-origin: margin;"
                                                            "}"
                                                            "QScrollBar::sub-line:vertical {"
                                                            "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
                                                            "    stop: 0  rgb(12, 68, 145), stop: 0.5 rgb(12, 68, 145),  stop:1 rgb(12, 68, 145));"
                                                            "    height: 0 px;"
                                                            "    subcontrol-position: top;"
                                                            "    subcontrol-origin: margin;"
                                                            "}"
                                                            );
        ui->tableView_2->horizontalScrollBar()->setStyleSheet(
                    "QScrollBar:horizontal { "
                    "    border: 1px solid #999999;"
                    "    background:white;"
                    "    height:25px;    "
                    "    margin: 0px 0px 0px 0px;"
                    "}"
                    "QScrollBar::handle:horizontal {"
                    "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
                    "    stop: 0 rgb(12, 68, 145), stop: 0.5 rgb(12, 68, 145), stop:1 rgb(12, 68, 145));"
                    "    min-height: 0px;"
                    "}"
                    "QScrollBar::add-line:horizontal {"
                    "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
                    "    stop: 0 rgb(12, 68, 145), stop: 0.5 rgb(12, 68, 145),  stop:1 rgb(12, 68, 145));"
                    "    height: 0px;"
                    "    subcontrol-position: bottom;"
                    "    subcontrol-origin: margin;"
                    "}"
                    "QScrollBar::sub-line:horizontal {"
                    "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
                    "    stop: 0  rgb(12, 68, 145), stop: 0.5 rgb(12, 68, 145),  stop:1 rgb(12, 68, 145));"
                    "    height: 0 px;"
                    "    subcontrol-position: top;"
                    "    subcontrol-origin: margin;"
                    "}");

        ui->tableView_5->verticalScrollBar()->setStyleSheet("QScrollBar:vertical {"
                                                            "    border: 1px solid #999999;"
                                                            "    background:white;"
                                                            "    width:25px;    "
                                                            "    margin: 0px 0px 0px 0px;"
                                                            "}"
                                                            "QScrollBar::handle:vertical {"
                                                            "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
                                                            "    stop: 0 rgb(12, 68, 145), stop: 0.5 rgb(12, 68, 145), stop:1 rgb(12, 68, 145));"
                                                            "    min-height: 0px;"
                                                            "}"
                                                            "QScrollBar::add-line:vertical {"
                                                            "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
                                                            "    stop: 0 rgb(12, 68, 145), stop: 0.5 rgb(12, 68, 145),  stop:1 rgb(12, 68, 145));"
                                                            "    height: 0px;"
                                                            "    subcontrol-position: bottom;"
                                                            "    subcontrol-origin: margin;"
                                                            "}"
                                                            "QScrollBar::sub-line:vertical {"
                                                            "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
                                                            "    stop: 0  rgb(12, 68, 145), stop: 0.5 rgb(12, 68, 145),  stop:1 rgb(12, 68, 145));"
                                                            "    height: 0 px;"
                                                            "    subcontrol-position: top;"
                                                            "    subcontrol-origin: margin;"
                                                            "}"
                                                            );
        ui->tableView_5->horizontalScrollBar()->setStyleSheet(
                    "QScrollBar:horizontal { ""    border: 1px solid #999999;"
                    "    background:white;"
                    "    height:25px;    "
                    "    margin: 0px 0px 0px 0px;"
                    "}"
                    "QScrollBar::handle:horizontal {"
                    "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
                    "    stop: 0 rgb(12, 68, 145), stop: 0.5 rgb(12, 68, 145), stop:1 rgb(12, 68, 145));"
                    "    min-height: 0px;"
                    "}"
                    "QScrollBar::add-line:horizontal {"
                    "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
                    "    stop: 0 rgb(12, 68, 145), stop: 0.5 rgb(12, 68, 145),  stop:1 rgb(12, 68, 145));"
                    "    height: 0px;"
                    "    subcontrol-position: bottom;"
                    "    subcontrol-origin: margin;"
                    "}"
                    "QScrollBar::sub-line:horizontal {"
                    "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
                    "    stop: 0  rgb(12, 68, 145), stop: 0.5 rgb(12, 68, 145),  stop:1 rgb(12, 68, 145));"
                    "    height: 0 px;"
                    "    subcontrol-position: top;"
                    "    subcontrol-origin: margin;"
                    "}");
    }
    else if(Test_Type=="Turbidity")
    {
        ui->tableView_2->verticalScrollBar()->setStyleSheet("QScrollBar:vertical {"
                                                            "    border: 1px solid #999999;"
                                                            "    background:white;"
                                                            "    width:25px;    "
                                                            "    margin: 0px 0px 0px 0px;"
                                                            "}"
                                                            "QScrollBar::handle:vertical {"
                                                            "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0.08, stop:0.164773 rgba(0, 145, 106, 255), stop:1 rgba(0, 145, 106, 255));"
                                                            "    min-height: 0px;"
                                                            "}"
                                                            "QScrollBar::add-line:vertical {"
                                                            "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0.08, stop:0.164773 rgba(0, 145, 106, 255), stop:1 rgba(0, 145, 106, 255));"
                                                            "    height: 0px;"
                                                            "    subcontrol-position: bottom;"
                                                            "    subcontrol-origin: margin;"
                                                            "}"
                                                            "QScrollBar::sub-line:vertical {"
                                                            "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
                                                            "    stop: 0  rgb(12, 68, 145), stop: 0.5 rgb(12, 68, 145),  stop:1 rgb(12, 68, 145));"
                                                            "    height: 0 px;"
                                                            "    subcontrol-position: top;"
                                                            "    subcontrol-origin: margin;"
                                                            "}"
                                                            );
        ui->tableView_2->horizontalScrollBar()->setStyleSheet(
                    "QScrollBar:horizontal { "
                    "    border: 1px solid #999999;"
                    "    background:white;"
                    "    height:25px;    "
                    "    margin: 0px 0px 0px 0px;"
                    "}"
                    "QScrollBar::handle:horizontal {"
                    "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
                    "    stop: 0 rgb(12, 68, 145), stop: 0.5 rgb(12, 68, 145), stop:1 rgb(12, 68, 145));"
                    "    min-height: 0px;"
                    "}"
                    "QScrollBar::add-line:horizontal {"
                    "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
                    "    stop: 0 rgb(12, 68, 145), stop: 0.5 rgb(12, 68, 145),  stop:1 rgb(12, 68, 145));"
                    "    height: 0px;"
                    "    subcontrol-position: bottom;"
                    "    subcontrol-origin: margin;"
                    "}"
                    "QScrollBar::sub-line:horizontal {"
                    "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
                    "    stop: 0  rgb(12, 68, 145), stop: 0.5 rgb(12, 68, 145),  stop:1 rgb(12, 68, 145));"
                    "    height: 0 px;"
                    "    subcontrol-position: top;"
                    "    subcontrol-origin: margin;"
                    "}");

        ui->tableView_5->verticalScrollBar()->setStyleSheet("QScrollBar:vertical {"
                                                            "    border: 1px solid #999999;"
                                                            "    background:white;"
                                                            "    width:25px;    "
                                                            "    margin: 0px 0px 0px 0px;"
                                                            "}"
                                                            "QScrollBar::handle:vertical {"
                                                            "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
                                                            "    stop: 0 rgb(12, 68, 145), stop: 0.5 rgb(12, 68, 145), stop:1 rgb(12, 68, 145));"
                                                            "    min-height: 0px;"
                                                            "}"
                                                            "QScrollBar::add-line:vertical {"
                                                            "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
                                                            "    stop: 0 rgb(12, 68, 145), stop: 0.5 rgb(12, 68, 145),  stop:1 rgb(12, 68, 145));"
                                                            "    height: 0px;"
                                                            "    subcontrol-position: bottom;"
                                                            "    subcontrol-origin: margin;"
                                                            "}"
                                                            "QScrollBar::sub-line:vertical {"
                                                            "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
                                                            "    stop: 0  rgb(12, 68, 145), stop: 0.5 rgb(12, 68, 145),  stop:1 rgb(12, 68, 145));"
                                                            "    height: 0 px;"
                                                            "    subcontrol-position: top;"
                                                            "    subcontrol-origin: margin;"
                                                            "}"
                                                            );
        ui->tableView_5->horizontalScrollBar()->setStyleSheet(
                    "QScrollBar:horizontal { ""    border: 1px solid #999999;"
                    "    background:white;"
                    "    height:25px;    "
                    "    margin: 0px 0px 0px 0px;"
                    "}"
                    "QScrollBar::handle:horizontal {"
                    "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
                    "    stop: 0 rgb(12, 68, 145), stop: 0.5 rgb(12, 68, 145), stop:1 rgb(12, 68, 145));"
                    "    min-height: 0px;"
                    "}"
                    "QScrollBar::add-line:horizontal {"
                    "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
                    "    stop: 0 rgb(12, 68, 145), stop: 0.5 rgb(12, 68, 145),  stop:1 rgb(12, 68, 145));"
                    "    height: 0px;"
                    "    subcontrol-position: bottom;"
                    "    subcontrol-origin: margin;"
                    "}"
                    "QScrollBar::sub-line:horizontal {"
                    "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
                    "    stop: 0  rgb(12, 68, 145), stop: 0.5 rgb(12, 68, 145),  stop:1 rgb(12, 68, 145));"
                    "    height: 0 px;"
                    "    subcontrol-position: top;"
                    "    subcontrol-origin: margin;"
                    "}");
    }
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery* query=new QSqlQuery(mydb);
    query->prepare("select PID,PName,TName,Date,Time from Turbidity_Result");
    query->exec();
    model->setQuery(*query);
    model->setHeaderData( 0, Qt::Horizontal, QObject::tr("Patient ID") );
    model->setHeaderData( 1, Qt::Horizontal, QObject::tr("Name") );
    model->setHeaderData( 2, Qt::Horizontal, QObject::tr("Parameter name") );
    model->setHeaderData( 3, Qt::Horizontal, QObject::tr("Date") );
    model->setHeaderData( 4, Qt::Horizontal, QObject::tr("Time") );

    ui->tableView_2->setModel(model);

    QSqlQueryModel * modall = new QSqlQueryModel();
    QSqlQuery* qury=new QSqlQuery(mydb);
    qury->prepare("select PID,PName,PAge,PGender,TName,ANrmlRang,BNrmlRang,ODVal,ResultOD,Unit,Date,Time from Turbidity_Result");
    qury->exec();
    modall->setQuery(*qury);

    modall->setHeaderData( 0, Qt::Horizontal, QObject::tr("Patient ID") );
    modall->setHeaderData( 1, Qt::Horizontal, QObject::tr("Name") );
    modall->setHeaderData( 2, Qt::Horizontal, QObject::tr("Age") );
    modall->setHeaderData( 3, Qt::Horizontal, QObject::tr("Gender") );
    modall->setHeaderData( 4, Qt::Horizontal, QObject::tr("Parameter name") );
    modall->setHeaderData( 5, Qt::Horizontal, QObject::tr("Normal range(Max)") );
    modall->setHeaderData( 6, Qt::Horizontal, QObject::tr("Normal range(Min)") );
    modall->setHeaderData( 7, Qt::Horizontal, QObject::tr("OD value") );
    modall->setHeaderData( 8, Qt::Horizontal, QObject::tr("Result OD") );
    modall->setHeaderData( 9, Qt::Horizontal, QObject::tr("Unit") );
    modall->setHeaderData( 10, Qt::Horizontal, QObject::tr("Date") );
    modall->setHeaderData( 11, Qt::Horizontal, QObject::tr("Time") );

    ui->tableView_5->setModel(modall);
    // Refresh the view to ensure it picks up the changes
    ui->tableView_2->resizeColumnsToContents() ;
    ui->tableView_5->resizeColumnsToContents();

    int Sending_Data=0;
    QSqlQuery qry;
    qry.prepare("select Sending_Results from LIS where sno=1");
    qry.exec();
    while(qry.next())
    {
        Sending_Data=qry.value(0).toInt(); // Individual Data (or) Grp Data send
    }
    qDebug()<<"Sending_data : "<<Sending_Data;
    if(LIS_connect_data==1)
    {
        if(LIS_data==1)
        {
            if(Sending_Data==1)
            {
                ui->pushButton_17->setEnabled(true);
                ui->pushButton_261->setDisabled(true);
            }
            else if(Sending_Data==2)
            {
                ui->pushButton_17->setEnabled(false);
                ui->pushButton_261->setDisabled(false);
            }
            else
            {
                ui->pushButton_17->setEnabled(false);
                ui->pushButton_261->setDisabled(true);
            }
        }
        else
        {
            if(Sending_Data==1)
            {
                ui->pushButton_17->setEnabled(true);
                ui->pushButton_261->setDisabled(true);
            }
            else if(Sending_Data==2)
            {
                ui->pushButton_17->setEnabled(false);
                ui->pushButton_261->setDisabled(false);
            }
            else
            {
                ui->pushButton_17->setEnabled(false);
                ui->pushButton_261->setDisabled(true);
            }
        }
    }
    else
    {
        ui->pushButton_17->setEnabled(false);
        ui->pushButton_261->setDisabled(true);
    }
    ui->stackedWidget_10->setCurrentIndex(0);
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::cald4()
{
    ui->tableView_2->setVisible(true);
    ui->label_450->setVisible(true);
    ui->label_451->setVisible(true);
    QObject *senderObj = sender(); // This will give Sender object
    QString senderObjName = senderObj->objectName();
    ui->label_451->setText(senderObjName);
    QString TestName = ui->label_451->text();
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery* query=new QSqlQuery(mydb);
    if(Test_Type=="Biochemistry")
        query->prepare("select PID,PName,TName,Date,Time from Reports where TName='"+TestName+"'");
    else if(Test_Type=="Turbidity")
        query->prepare("select PID,PName,TName,Date,Time from Turbidity_Result where TName='"+TestName+"'");

    query->exec();
    model->setQuery(*query);
    model->setHeaderData( 0, Qt::Horizontal, QObject::tr("Patient ID") );
    model->setHeaderData( 1, Qt::Horizontal, QObject::tr("Name") );
    model->setHeaderData( 2, Qt::Horizontal, QObject::tr("Parameter name") );
    model->setHeaderData( 3, Qt::Horizontal, QObject::tr("Date") );
    model->setHeaderData( 4, Qt::Horizontal, QObject::tr("Time") );

    ui->tableView_2->setModel(model);

    QSqlQueryModel * modall = new QSqlQueryModel();
    QSqlQuery* qury=new QSqlQuery(mydb);
    if(Test_Type=="Biochemistry")
        qury->prepare("select PID,PName,PAge,PGender,TName,ANrmlRang,BNrmlRang,ODVal,ResultOD,Unit,Date,Time from Reports where TName='"+TestName+"'");
    else if(Test_Type=="Turbidity")
        qury->prepare("select PID,PName,PAge,PGender,TName,ANrmlRang,BNrmlRang,ODVal,ResultOD,Unit,Date,Time from Turbidity_Result where TName='"+TestName+"'");

    qury->prepare("select PID,PName,PAge,PGender,TName,ANrmlRang,BNrmlRang,ODVal,ResultOD,Unit,Date,Time from Reports where TName='"+TestName+"'");
    qury->exec();
    modall->setQuery(*qury);
    modall->setHeaderData( 0, Qt::Horizontal, QObject::tr("Patient ID") );
    modall->setHeaderData( 1, Qt::Horizontal, QObject::tr("Name") );
    modall->setHeaderData( 2, Qt::Horizontal, QObject::tr("Age") );
    modall->setHeaderData( 3, Qt::Horizontal, QObject::tr("Gender") );
    modall->setHeaderData( 4, Qt::Horizontal, QObject::tr("Parameter name") );
    modall->setHeaderData( 5, Qt::Horizontal, QObject::tr("Normal range(Max)") );
    modall->setHeaderData( 6, Qt::Horizontal, QObject::tr("Normal range(Min)") );
    modall->setHeaderData( 7, Qt::Horizontal, QObject::tr("OD value") );
    modall->setHeaderData( 8, Qt::Horizontal, QObject::tr("Result OD") );
    modall->setHeaderData( 9, Qt::Horizontal, QObject::tr("Unit") );
    modall->setHeaderData( 10, Qt::Horizontal, QObject::tr("Date") );
    modall->setHeaderData( 11, Qt::Horizontal, QObject::tr("Time") );

    ui->tableView_5->setModel(modall);
    ui->tableView_2->resizeColumnsToContents() ;
    ui->tableView_5->resizeColumnsToContents();
    ui->stackedWidget->setCurrentIndex(9);

}

// ///////////////////////////// External Printer ////////////////////////////////

void MainWindow::on_toolButton_22_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

bool copyAndRemoveFile(const QString& sourceFilePath, const QString& destFilePath) {
    QFile sourceFile(sourceFilePath);
    if (!sourceFile.exists()) {
        qDebug() << "Source file does not exist:" << sourceFilePath;
        return false;
    }

    QFile destFile(destFilePath);
    if (destFile.exists()) {
        qDebug() << "Destination file already exists:" << destFilePath;
        return false;
    }

    if (sourceFile.copy(destFilePath)) {
        if (QFile::remove(sourceFilePath)) {
            qDebug() << "Moved and removed" << sourceFilePath << "to" << destFilePath;
            return true;
        } else {
            qDebug() << "Failed to remove source file:" << sourceFilePath;
            return false;
        }
    } else {
        qDebug() << "Failed to copy" << sourceFilePath << "to" << destFilePath;
        return false;
    }
}
