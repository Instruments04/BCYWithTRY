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
static QString arraylst[100]={""};

void MainWindow::clearGraph_QC()
{
    qv_x.clear();
    qv_y.clear();
    ui->customPlot_3->xAxis->setTicks(false);
    ui->customPlot_3->yAxis->setTicks(false);
    ui->customPlot_3->addGraph();
    ui->customPlot_3->graph(0)->setData(qv_x,qv_y);
    ui->customPlot_3->xAxis->setLabel("x");
    ui->customPlot_3->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->customPlot_3->xAxis->setRange(0,5);
    ui->customPlot_3->yAxis->setRange(0,5);
    ui->customPlot_3->yAxis->ticker().clear();
    ui->customPlot_3->replot();
    ui->customPlot_3->addGraph();
    ui->customPlot_3->graph(1)->setData(qv_x,qv_y);
    ui->customPlot_3->addGraph();
    ui->customPlot_3->graph(2)->setData(qv_x,qv_y);
    ui->customPlot_3->addGraph();
    ui->customPlot_3->graph(3)->setData(qv_x,qv_y);
    ui->customPlot_3->replot();
    ui->customPlot_3->update();
}

void MainWindow::on_toolButton_8_clicked()
{
    ui->stackedWidget_11->setVisible(false);
    clearGridLayout(ui->gridLayout_2);
    ui->pushButton_6->setVisible(false);
    ui->pushButton_139->setVisible(false);
    ui->pushButton_142->setVisible(true);
    ui->pushButton_142->setStyleSheet("QPushButton {border: 2px solid green;border-top-left-radius:40px;border-top-right-radius:40px;background-color: white;padding: 10px;}");
    qcback=1;
    ui->Home_Lbl_2->setText("Select parameter to view its control values");
    tabnumber2=1;
    tabtest=4;
    tabrecent=0;
    tabedit=0;
    tabdelete=0;
    tabqc=1;
    tabfilter=0;
    exptopn=0;
    //SetupScroller(ui->scrollArea_3);
    if(Test_Type=="Biochemistry")
    {
    ui->scrollArea_7->verticalScrollBar()->setStyleSheet("QScrollBar:vertical {"
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
    ui->scrollArea_7->horizontalScrollBar()->setStyleSheet( "QScrollBar:horizontal { "
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



    QSqlQuery query;
    query.prepare("SELECT name FROM test ORDER BY name ASC;");
    query.exec();
    int count=0;
    while(query.next())
    {
        QString s=query.value(0).toString();
        arraylst[count]=s;
        count++;
        qDebug()<<s;
    }
    int count1=0;
    const QSize btnSize = QSize(150, 50);
    for (int i=0;i<15 ;i++ )
    {
        for (int j=0;j<5 ;j++ )
        {
            if(count1==count)
                break;
            else
            {
                QPushButton *button = new QPushButton(arraylst[count1]);
                button->setStyleSheet(
                            "QPushButton {"
                            "  background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(12, 68, 145), stop: 0.5 rgb(12, 68, 145),  stop:1 rgb(12, 68, 145));"
                            "  color: white;"
                            "}"
                            "QPushButton:hover {"
                            "  background-color: qlineargradient(spread:pad, x1:0, y1:0.0913636, x2:0.944, y2:0.392, stop:0.0969388 rgba(22, 123, 200, 255), stop:1 rgba(20, 113, 180, 255));"
                            "  color: white;"
                            "}"
                            "QPushButton:pressed {"
                              " background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(12, 68, 145), stop: 0.5 rgb(12, 68, 145),  stop:1 rgb(12, 68, 145));"
                            "margin-top: 2px;"
                            "margin-bottom: -4px;"
                             "color: white;"
                            "}"
                            );
                QFont font = button->font();
                font.setBold(true);
                button->setFont(font);
                button->setFixedSize(btnSize);
                button->setObjectName(arraylst[count1]);
                connect(button, &QPushButton::clicked, this, &MainWindow::cald1);
                ui->gridLayout_2->addWidget(button,i,j);
            }
            count1++;
        }
    }
    }
    else if(Test_Type=="Turbidity")
    {
        qDebug()<<"Turbi";
    }
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::cald1()
{
    QObject *senderObj = sender(); // This will give Sender object
    QString senderObjName = senderObj->objectName();
    TestName=senderObjName;
    ui->stackedWidget->setCurrentIndex(24);
    ui->stackedWidget_3->setCurrentIndex(0);
    QSqlQuery qu;
    qu.prepare("select Pro_Code from test where name='"+TestName+"'");
    qu.exec();
    while (qu.next())
        Prod_Code=qu.value(0).toString();
}

void MainWindow::on_pushButton_191_clicked()
{
    ui->stackedWidget->setCurrentIndex(24);
    ui->stackedWidget_3->setCurrentIndex(1);
    ui->pushButton_292->setVisible(true);
    ui->pushButton_338->setVisible(true);
    ui->label_430->clear();
    ui->label_440->clear();
    ui->tableView_3->verticalScrollBar()->setStyleSheet("QScrollBar:vertical {"
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
    ui->tableView_3->horizontalScrollBar()->setStyleSheet(
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
    ui->pushButton_309->setVisible(true);
    ui->pushButton_316->setVisible(false);
    ui->comboBox_15->setVisible(false);
    ui->label_49->setVisible(false);
    ui->label_423->setText(TestName +" "+ "QC-1");
    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery* query=new QSqlQuery(mydb);
    query->prepare("select Tname, Procode,QC1Conc, QCMin , QCMax,Unit,Date, Time from QC where Tname = '"+TestName+"'");
    query->exec();
    modal->setQuery(*query);
    ui->tableView_3->setModel(modal);
    qDebug() << ( modal->rowCount());
}

void MainWindow::on_pushButton_194_clicked()
{
    ui->stackedWidget->setCurrentIndex(24);
    ui->stackedWidget_3->setCurrentIndex(1);
    ui->pushButton_292->setVisible(true);
    ui->pushButton_338->setVisible(true);
    ui->label_430->clear();
    ui->label_440->clear();
    ui->tableView_3->verticalScrollBar()->setStyleSheet("QScrollBar:vertical {"
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
    ui->tableView_3->horizontalScrollBar()->setStyleSheet(
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
    ui->pushButton_309->setVisible(false);
    ui->pushButton_316->setVisible(true);
    ui->comboBox_15->setVisible(false);
    ui->label_49->setVisible(false);
    ui->label_423->setText(TestName+" "+"QC-2");
    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery* query=new QSqlQuery(mydb);
    query->prepare("select TName, Procode,QC2Conc, QCMin , QCMax,Unit,Date, Time from QC2 where TName = '"+TestName+"'");
    query->exec();
    modal->setQuery(*query);
    ui->tableView_3->setModel(modal);
    qDebug() << ( modal->rowCount());
}

void MainWindow::on_pushButton_309_clicked()
{
    QString vl;
    QString fDate , fMonth , fYear , tDate , tMonth , tYear , slash;
    slash = "/";
    QString fdateString = ui->label_430->text();
    QString tdateString = ui->label_440->text();
    if(fdateString=="")
    {
        QMessageBox msg(this);
        msg.setWindowFlags(Qt::Popup);
        msg.setStyleSheet("background-color:#a0cdfa;font: 75 20pt Liberation Serif ;");
        QPixmap p("/home/pi/git/BCYWithTRY/BCYWithTRY/img/notification.png");
        auto newPixmap = p.scaled(80, 80);
        msg.setIconPixmap(newPixmap);
        msg.setText("From date is empty.");
        QPushButton* saveButton = msg.addButton("Ok", QMessageBox::AcceptRole);
        saveButton->setStyleSheet("QPushButton{background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 #34ba91, stop: 0.5 #34ba91, stop: 1 #34ba91);color:black;}QPushButton:pressed {background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(0, 85, 0), stop: 0.5 rgb(0, 85, 0), stop: 1 rgb(0, 85, 0));color:white;}");
        msg.setDefaultButton(saveButton);
        msg.exec();
        if (msg.clickedButton() == saveButton)
            ui->stackedWidget_3->setCurrentIndex(1);
        else
            ui->stackedWidget_3->setCurrentIndex(1);
    }
    else if(tdateString=="")
    {
        QMessageBox msg(this);
        msg.setWindowFlags(Qt::Popup);
        msg.setStyleSheet("background-color:#a0cdfa;font: 75 20pt Liberation Serif ;");
        QPixmap p("/home/pi/git/BCYWithTRY/BCYWithTRY/img/notification.png");
        auto newPixmap = p.scaled(80, 80);
        msg.setIconPixmap(newPixmap);
        msg.setText("To date is empty.");
        QPushButton* saveButton = msg.addButton("Ok", QMessageBox::AcceptRole);
        saveButton->setStyleSheet("QPushButton{background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 #34ba91, stop: 0.5 #34ba91, stop: 1 #34ba91);color:black;}QPushButton:pressed {background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(0, 85, 0), stop: 0.5 rgb(0, 85, 0), stop: 1 rgb(0, 85, 0));color:white;}");
        msg.setDefaultButton(saveButton);
        msg.exec();
        if (msg.clickedButton() == saveButton)
            ui->stackedWidget_3->setCurrentIndex(1);
        else
            ui->stackedWidget_3->setCurrentIndex(1);
    }
    else
    {
        QSqlQueryModel * modal = new QSqlQueryModel();
        QSqlQuery *query = new QSqlQuery (mydb) ;
        QC1_loop();
        query->prepare("SELECT Tname, Procode,LotNo,QC1Conc, QCMin , QCMax,Unit,Date, Time FROM "+QC1_Testname+" WHERE Date BETWEEN '"+fdateString+"' AND '"+tdateString+"'");
        query->exec();
        qDebug()<<fdateString;
        qDebug()<<tdateString;
        modal->setQuery(*query);
        modal->setHeaderData( 0, Qt::Horizontal, QObject::tr("Parameter name") );
        modal->setHeaderData( 1, Qt::Horizontal, QObject::tr("Product code") );
        modal->setHeaderData( 2, Qt::Horizontal, QObject::tr("Lot no") );
        modal->setHeaderData( 3, Qt::Horizontal, QObject::tr("QC1(Conc.)") );
        modal->setHeaderData( 4, Qt::Horizontal, QObject::tr("QC1(Minimum)") );
        modal->setHeaderData( 5, Qt::Horizontal, QObject::tr("QC1(Maximum)") );
        modal->setHeaderData( 6, Qt::Horizontal, QObject::tr("Unit") );
        modal->setHeaderData( 7, Qt::Horizontal, QObject::tr("Date") );
        modal->setHeaderData( 8, Qt::Horizontal, QObject::tr("Time") );
        ui->tableView_3->setModel(modal);
        qDebug() << ( modal->rowCount());
        ui->stackedWidget->setCurrentIndex(24);
        ui->stackedWidget_3->setCurrentIndex(1);
    }
}

void MainWindow::on_pushButton_316_clicked()
{
    QString fDate , fMonth , fYear , tDate , tMonth , tYear , slash;
    slash = "/";
    QString fdateString = ui->label_430->text();
    //const QDate tdate= tYear +" "+ slash+" "+tMonth+" "+ slash+" " +tDate;//ui->dateEdit_2->date();
    QString tdateString = ui->label_440->text();
    if(fdateString=="")
    {
        QMessageBox msg(this);
        msg.setWindowFlags(Qt::Popup);
        msg.setStyleSheet("background-color:#a0cdfa;font: 75 20pt Liberation Serif ;");
        QPixmap pix("/home/pi/git/BCYWithTRY/BCYWithTRY/img/notification.png");
        auto newPixmap = pix.scaled(65, 65);
        msg.setIconPixmap(newPixmap);
        msg.setStyleSheet("font:16pt Arial;");
        msg.setText("From date is empty.");
        QPushButton* saveButton = msg.addButton("Ok", QMessageBox::AcceptRole);
        saveButton->setStyleSheet("QPushButton{background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 #34ba91, stop: 0.5 #34ba91, stop: 1 #34ba91);color:black;}QPushButton:pressed {background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(0, 85, 0), stop: 0.5 rgb(0, 85, 0), stop: 1 rgb(0, 85, 0));color:white;}");
        msg.setDefaultButton(saveButton);
        msg.exec();
        if (msg.clickedButton() == saveButton)
            ui->stackedWidget_3->setCurrentIndex(1);
        else
            ui->stackedWidget_3->setCurrentIndex(1);
    }
    else if(tdateString=="")
    {
        QMessageBox msg(this);
        msg.setWindowFlags(Qt::Popup);
        msg.setStyleSheet("background-color:#a0cdfa;font: 75 20pt Liberation Serif ;");
        QPixmap pix("/home/pi/git/BCYWithTRY/BCYWithTRY/img/notification.png");
        auto newPixmap = pix.scaled(65, 65);
        msg.setIconPixmap(newPixmap);
        msg.setStyleSheet("font:16pt Arial;");
        msg.setText("To date is empty.");
        QPushButton* saveButton = msg.addButton("Ok", QMessageBox::AcceptRole);
        saveButton->setStyleSheet("QPushButton{background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 #34ba91, stop: 0.5 #34ba91, stop: 1 #34ba91);color:black;}QPushButton:pressed {background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(0, 85, 0), stop: 0.5 rgb(0, 85, 0), stop: 1 rgb(0, 85, 0));color:white;}");
        msg.setDefaultButton(saveButton);
        msg.exec();
        if (msg.clickedButton() == saveButton)
            ui->stackedWidget_3->setCurrentIndex(1);
        else
            ui->stackedWidget_3->setCurrentIndex(1);
    }
    else
    {
        QSqlQueryModel * modal = new QSqlQueryModel();
        QSqlQuery *query = new QSqlQuery (mydb) ;
        QC2_loop();
        query->prepare("SELECT Tname, Procode,LotNo,QC2Conc, QCMin , QCMax,Unit,Date, Time FROM "+QC2_Testname+" WHERE Date BETWEEN '"+fdateString+"' AND '"+tdateString+"'");
        query->exec();
        qDebug()<<fdateString;
        qDebug()<<tdateString;
        modal->setQuery(*query);
        modal->setHeaderData( 0, Qt::Horizontal, QObject::tr("Parameter name") );
        modal->setHeaderData( 1, Qt::Horizontal, QObject::tr("Product code") );
        modal->setHeaderData( 2, Qt::Horizontal, QObject::tr("Lot no") );
        modal->setHeaderData( 3, Qt::Horizontal, QObject::tr("QC2(Conc.)") );
        modal->setHeaderData( 4, Qt::Horizontal, QObject::tr("QC2(Minimum)") );
        modal->setHeaderData( 5, Qt::Horizontal, QObject::tr("QC2(Maximum)") );
        modal->setHeaderData( 6, Qt::Horizontal, QObject::tr("Unit") );
        modal->setHeaderData( 7, Qt::Horizontal, QObject::tr("Date") );
        modal->setHeaderData( 8, Qt::Horizontal, QObject::tr("Time") );
        ui->tableView_3->setModel(modal);
        ui->stackedWidget->setCurrentIndex(24);
        ui->stackedWidget_3->setCurrentIndex(1);
    }
}

void MainWindow::on_pushButton_192_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(2);
    ui->label_425->clear();
    ui->label_426->clear();
    ui->comboBox_15->clear();
    ui->comboBox_16->clear();
    ui->pushButton_328->setVisible(false);
    ui->pushButton_329->setVisible(false);
    ui->pushButton_292->setVisible(false);
    ui->label_49->setVisible(false);
    ui->comboBox_15->setVisible(false);
    ui->comboBox_16->setVisible(false);
    ui->pushButton_315->setVisible(true);
    ui->pushButton_315->setDisabled(false);
    ui->pushButton_321->setVisible(false);
    ui->label_48->setText(TestName+ " " + "QC-1");
    // ui->pushButton_90->setVisible(true);
    // ui->pushButton_91->setVisible(true);
    clearGraph_QC();
    clearData();
    ui->pushButton_331->setEnabled(false);
    ui->pushButton_333->setEnabled(false);
}

void MainWindow::on_pushButton_193_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(2);
    ui->pushButton_328->setVisible(false);
    ui->pushButton_329->setVisible(false);
    ui->comboBox_15->clear();
    ui->comboBox_16->clear();
    ui->label_425->clear();
    ui->label_426->clear();
    ui->label_49->setVisible(false);
    ui->comboBox_15->setVisible(false);
    ui->comboBox_16->setVisible(false);
    ui->pushButton_315->setVisible(false);
    ui->pushButton_321->setVisible(true);
    ui->pushButton_290->setVisible(true);
    ui->pushButton_291->setVisible(true);
    ui->pushButton_321->setDisabled(false);
    ui->label_48->setText(TestName+ " " + "QC-2");
    clearGraph_QC();
    clearData();
    ui->pushButton_331->setEnabled(false);
    ui->pushButton_333->setEnabled(false);
}

void MainWindow::comboclear()
{
    ui->comboBox_15->clear();
    ui->comboBox_16->clear();
}
void MainWindow::on_pushButton_315_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(2);
    QList<QString> QC1LottNumber;

    ui->pushButton_328->setVisible(true);
    ui->pushButton_329->setVisible(false);
    QObject *senderObj = sender(); // This will give Sender object
    QString senderObjName = senderObj->objectName();
    qDebug()<<"SenderObj : " <<senderObjName;
    // QC1 Graph Update Btn
    ui->label_49->setVisible(true);
    ui->comboBox_15->setVisible(true);
    ui->comboBox_16->setVisible(false);

    QString cbo=ui->comboBox_15->currentText();
    if(cbo=="")
        qDebug()<<"Combo empty";
    ui->comboBox_15->clear();

    QString TesName,mainval,QCMini, QCMaxi ;
    QString fdateString = ui->label_425->text();
    QString tdateString = ui->label_426->text();
    qDebug()<<"From date : " <<fdateString;
    qDebug()<<"To date : " <<tdateString;

    if(fdateString=="")
    {
        QMessageBox msg(this);
        msg.setWindowFlags(Qt::Popup);
        msg.setStyleSheet("background-color:#a0cdfa;font: 75 20pt Liberation Serif ;");
        QPixmap pix("/home/pi/git/BCYWithTRY/BCYWithTRY/img/notification.png");
        auto newPixmap = pix.scaled(65, 65);
        msg.setIconPixmap(newPixmap);
        msg.setStyleSheet("font:16pt Arial;");
        msg.setText("From date is empty.");
        QPushButton* saveButton = msg.addButton("Ok", QMessageBox::AcceptRole);
        saveButton->setStyleSheet("QPushButton{background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 #34ba91, stop: 0.5 #34ba91, stop: 1 #34ba91);color:black;}QPushButton:pressed {background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(0, 85, 0), stop: 0.5 rgb(0, 85, 0), stop: 1 rgb(0, 85, 0));color:white;}");
        msg.setDefaultButton(saveButton);
        msg.exec();
        if (msg.clickedButton() == saveButton)
            ui->stackedWidget_3->setCurrentIndex(2);
        else
            ui->stackedWidget_3->setCurrentIndex(2);
    }
    else if(tdateString=="")
    {
        QMessageBox msg(this);
        msg.setWindowFlags(Qt::Popup);
        msg.setStyleSheet("background-color:#a0cdfa;font: 75 20pt Liberation Serif ;");
        QPixmap pix("/home/pi/git/BCYWithTRY/BCYWithTRY/img/notification.png");
        auto newPixmap = pix.scaled(65, 65);
        msg.setIconPixmap(newPixmap);
        msg.setStyleSheet("font:16pt Arial;");
        msg.setText("To date is empty.");
        QPushButton* saveButton = msg.addButton("Ok", QMessageBox::AcceptRole);
        saveButton->setStyleSheet("QPushButton{background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 #34ba91, stop: 0.5 #34ba91, stop: 1 #34ba91);color:black;}QPushButton:pressed {background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(0, 85, 0), stop: 0.5 rgb(0, 85, 0), stop: 1 rgb(0, 85, 0));color:white;}");
        msg.setDefaultButton(saveButton);
        msg.exec();
        if (msg.clickedButton() == saveButton)
            ui->stackedWidget_3->setCurrentIndex(2);
        else
            ui->stackedWidget_3->setCurrentIndex(2);
    }
    else {

        Fromdt=fdateString;
        Todt=tdateString;
        QSqlQuery query;// = new QSqlQuery (mydb) ;
        QList<double> listed , listt;
        QC1_loop();
        query.prepare("SELECT LotNo FROM "+QC1_Testname+" WHERE Date BETWEEN '"+fdateString+"' AND '"+tdateString+"'");
        query.exec();
        while(query.next())
            QC1LottNumber.append(query.value(0).toString());

        if(QC1LottNumber.isEmpty())
        {
            QMessageBox msg(this);
            msg.setWindowFlags(Qt::Popup);
            msg.setStyleSheet("background-color:#a0cdfa;font: 75 20pt Liberation Serif ;");
            QPixmap pix("/home/pi/git/BCYWithTRY/BCYWithTRY/img/notification.png");
            auto newPixmap = pix.scaled(65, 65);
            msg.setIconPixmap(newPixmap);
            msg.setStyleSheet("font:16pt Arial;");
            msg.setText("There is no data on this date");
            QPushButton* saveButton = msg.addButton("Ok", QMessageBox::AcceptRole);
            saveButton->setStyleSheet("QPushButton{background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 #34ba91, stop: 0.5 #34ba91, stop: 1 #34ba91);color:black;}QPushButton:pressed {background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(0, 85, 0), stop: 0.5 rgb(0, 85, 0), stop: 1 rgb(0, 85, 0));color:white;}");
            msg.setDefaultButton(saveButton);
            msg.exec();
            if (msg.clickedButton() == saveButton)
            {
                ui->stackedWidget->setCurrentIndex(24);
                ui->stackedWidget_3->setCurrentIndex(2);
            }
            else
            {
                ui->stackedWidget->setCurrentIndex(24);
                ui->stackedWidget_3->setCurrentIndex(2);
            }
        }
        qDebug()<<"Before remove duplicates : "<<QC1LottNumber;

        QC1LottNumber.removeDuplicates();
        qDebug()<<"Afterr LotNumber list : "<<QC1LottNumber;
        QThread::msleep(2000);
        ui->comboBox_15->addItems(QC1LottNumber);
        clearGraph_QC();
    }
    ui->pushButton_331->setEnabled(false);
    ui->pushButton_333->setEnabled(false);
}


void MainWindow::on_pushButton_321_clicked()
{

    ui->stackedWidget_3->setCurrentIndex(2);
    QList<QString> QC2LottNumber;
    ui->pushButton_328->setVisible(false);
    ui->pushButton_329->setVisible(true);
    QThread::msleep(1000);
    ui->label_49->setVisible(true);
    ui->comboBox_15->setVisible(false);
    ui->comboBox_16->setVisible(true);
    ui->comboBox_16->clear();
    QString TesName, QCMini , QCMaxi,mainval;
    QString fDate , fMonth , fYear , tDate , tMonth , tYear , slash;
    QString fdateString = ui->label_425->text();
    QString tdateString = ui->label_426->text();
    qDebug()<<"From date pb_321: " <<fdateString;
    qDebug()<<"To date : " <<tdateString;

    if(fdateString=="")
    {
        QMessageBox msg(this);
        msg.setWindowFlags(Qt::Popup);
        msg.setStyleSheet("background-color:#a0cdfa;font: 75 20pt Liberation Serif ;");
        QPixmap p("/home/pi/git/BCYWithTRY/BCYWithTRY/img/notification.png");
        auto newPixmap = p.scaled(80, 80);
        msg.setIconPixmap(newPixmap);
        msg.setText("From date is empty.");
        QPushButton* saveButton = msg.addButton("Ok", QMessageBox::AcceptRole);
        saveButton->setStyleSheet("QPushButton{background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 #34ba91, stop: 0.5 #34ba91, stop: 1 #34ba91);color:black;}QPushButton:pressed {background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(0, 85, 0), stop: 0.5 rgb(0, 85, 0), stop: 1 rgb(0, 85, 0));color:white;}");
        msg.setDefaultButton(saveButton);
        msg.exec();
        if (msg.clickedButton() == saveButton)
            ui->stackedWidget_3->setCurrentIndex(2);

        else
            ui->stackedWidget_3->setCurrentIndex(2);

    }
    else if(tdateString=="")
    {
        QMessageBox msg(this);
        msg.setWindowFlags(Qt::Popup);
        msg.setStyleSheet("background-color:#a0cdfa;font: 75 20pt Liberation Serif ;");
        QPixmap p("/home/pi/git/BCYWithTRY/BCYWithTRY/img/notification.png");
        auto newPixmap = p.scaled(80, 80);
        msg.setIconPixmap(newPixmap);
        msg.setText("To date is empty.");
        QPushButton* saveButton = msg.addButton("Ok", QMessageBox::AcceptRole);
        saveButton->setStyleSheet("QPushButton{background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 #34ba91, stop: 0.5 #34ba91, stop: 1 #34ba91);color:black;}QPushButton:pressed {background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(0, 85, 0), stop: 0.5 rgb(0, 85, 0), stop: 1 rgb(0, 85, 0));color:white;}");
        msg.setDefaultButton(saveButton);
        msg.exec();
        if (msg.clickedButton() == saveButton)
            ui->stackedWidget_3->setCurrentIndex(2);
        else
            ui->stackedWidget_3->setCurrentIndex(2);

    }
    else {
        QC2_loop();
        QSqlQuery query; //= new QSqlQuery (mydb) ;
        QList<double> listed , listt;

        query.prepare("SELECT LotNo FROM "+QC2_Testname+" WHERE Date BETWEEN '"+fdateString+"' AND '"+tdateString+"'");
        query.exec();
        while(query.next())
            QC2LottNumber.append(query.value(0).toString());

        if(QC2LottNumber.isEmpty())
        {
            QMessageBox msg(this);
            msg.setWindowFlags(Qt::Popup);
            msg.setStyleSheet("background-color:#a0cdfa;font: 75 20pt Liberation Serif ;");
            QPixmap pix("/home/pi/git/BCYWithTRY/BCYWithTRY/img/notification.png");
            auto newPixmap = pix.scaled(65, 65);
            msg.setIconPixmap(newPixmap);
            msg.setStyleSheet("font:16pt Arial;");
            msg.setText("There is no data on this date");
            QPushButton* saveButton = msg.addButton("Ok", QMessageBox::AcceptRole);
            saveButton->setStyleSheet("QPushButton{background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 #34ba91, stop: 0.5 #34ba91, stop: 1 #34ba91);color:black;}QPushButton:pressed {background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(0, 85, 0), stop: 0.5 rgb(0, 85, 0), stop: 1 rgb(0, 85, 0));color:white;}");
            msg.setDefaultButton(saveButton);
            msg.exec();
            if (msg.clickedButton() == saveButton)
            {
                ui->stackedWidget->setCurrentIndex(24);
                ui->stackedWidget_3->setCurrentIndex(2);
            }

            else
            {
                ui->stackedWidget->setCurrentIndex(24);
                ui->stackedWidget_3->setCurrentIndex(2);
            }
        }
        qDebug()<<"Before remove duplicates : "<<QC2LottNumber;
        QC2LottNumber.removeDuplicates();
        qDebug()<<"Aftter LotNumber list : "<<QC2LottNumber;
        QThread::msleep(1000);
        ui->comboBox_16->addItems(QC2LottNumber);
        clearGraph_QC();

    }
    ui->pushButton_331->setEnabled(false);
    ui->pushButton_333->setEnabled(false);
}

void MainWindow::endqcselect()
{
    qDebug()<<"endqcselect";
    QString Barcode_Test_Name;
    if(Prod_Code=="MB1011")
        Barcode_Test_Name="GLUCOSE";
    else if(Prod_Code=="MB1021")
        Barcode_Test_Name="GLUCOSE-HK";
    else if(Prod_Code=="MB1031")
        Barcode_Test_Name="ADA";
    else if(Prod_Code=="MB1041")
        Barcode_Test_Name="ALBUMIN";
    else if(Prod_Code=="MB1051")
        Barcode_Test_Name="ALP";
    else if(Prod_Code=="MB1061")
        Barcode_Test_Name="AMYLASE";
    else if(Prod_Code=="MB1071")
        Barcode_Test_Name="AMMONIA";
    else if(Prod_Code=="MB1081")
        Barcode_Test_Name="ASO";
    else if(Prod_Code=="MB1091")
        Barcode_Test_Name="ACE";
    else if(Prod_Code=="MB1101")
        Barcode_Test_Name="BICARBONATE";
    else if(Prod_Code=="MB1111")
        Barcode_Test_Name="BILIRUBIN DIRECT";
    else if(Prod_Code=="MB1121")
        Barcode_Test_Name="BILIRUBIN TOTAL";
    else if(Prod_Code=="MB1131")
        Barcode_Test_Name="CALCIUM";
    else if(Prod_Code=="MB1141")
        Barcode_Test_Name="CHLORIDE";
    else if(Prod_Code=="MB1151")
        Barcode_Test_Name="CK-MB";
    else if(Prod_Code=="MB1161")
        Barcode_Test_Name="CK-NAC";
    else if(Prod_Code=="MB1171")
        Barcode_Test_Name="CREATININE(ENZY)";
    else if(Prod_Code=="MB1181")
        Barcode_Test_Name="CREATININE(KINE)";
    else if(Prod_Code=="MB1191")
        Barcode_Test_Name="ETHYL ALCOHOL";
    else if(Prod_Code=="MB1201")
        Barcode_Test_Name="GAMMA GT";
    else if(Prod_Code=="MB1211")
        Barcode_Test_Name="GOT(AST)";
    else if(Prod_Code=="MB1221")
        Barcode_Test_Name="GPT(ALT)";
    else if(Prod_Code=="MB1231")
        Barcode_Test_Name="HDL CHOLESTEROL";
    else if(Prod_Code=="MB1241")
        Barcode_Test_Name="HEMOGLOBIN";
    else if(Prod_Code=="MB1251")
        Barcode_Test_Name="HOMOCYSTEINE";
    else if(Prod_Code=="MB1261")
        Barcode_Test_Name="IRON";
    else if(Prod_Code=="MB1271")
        Barcode_Test_Name="LACTATE";
    else if(Prod_Code=="MB1281")
        Barcode_Test_Name="LDH";
    else if(Prod_Code=="MB1291")
        Barcode_Test_Name="LDL CHOLESTEROL";
    else if(Prod_Code=="MB1301")
        Barcode_Test_Name="LIPASE";
    else if(Prod_Code=="MB1311")
        Barcode_Test_Name="MAGNESIUM";
    else if(Prod_Code=="MB1321")
        Barcode_Test_Name="MICROALBUMIN";
    else if(Prod_Code=="MB1331")
        Barcode_Test_Name="PHOSPHOLIPIDS";
    else if(Prod_Code=="MB1341")
        Barcode_Test_Name="PHOSPHORUS-UV";
    else if(Prod_Code=="MB1351")
        Barcode_Test_Name="PHOSPHORUS-C";
    else if(Prod_Code=="MB1361")
        Barcode_Test_Name="POTASSIUM";
    else if(Prod_Code=="MB1371")
        Barcode_Test_Name="RHEUMATOID FACTOR";
    else if(Prod_Code=="MB1381")
        Barcode_Test_Name="SODIUM";
    else if(Prod_Code=="MB1391")
        Barcode_Test_Name="TOTAL CHOLESTEROL";
    else if(Prod_Code=="MB1401")
        Barcode_Test_Name="TOTAL PROTEIN";
    else if(Prod_Code=="MB1411")
        Barcode_Test_Name="TPU/CSF";
    else if(Prod_Code=="MB1421")
        Barcode_Test_Name="TIBC";
    else if(Prod_Code=="MB1431")
        Barcode_Test_Name="TRIGLYCERIDES";
    else if(Prod_Code=="MB1441")
        Barcode_Test_Name="UREA";
    else if(Prod_Code=="MB1451")
        Barcode_Test_Name="URIC ACID";
    else if(Prod_Code=="MB1461")
        Barcode_Test_Name="ZINC";
    else if(Prod_Code=="MB1471")
        Barcode_Test_Name="CHOLINESTERASE";
    else if(Prod_Code=="MB1481")
        Barcode_Test_Name="COPPER";
    else if(Prod_Code=="MB1491")
        Barcode_Test_Name="LITHIUM";
    else if(Prod_Code=="MB1501")
        Barcode_Test_Name="TBA";
    else if(Prod_Code=="MB1511")
        Barcode_Test_Name="UIBC";
    else if(Prod_Code=="MB1521")
        Barcode_Test_Name="GD";
    else if(Prod_Code=="MB1462")
           Barcode_Test_Name="ZINC-S";
       else if(Prod_Code=="MB1651")
           Barcode_Test_Name="MAGNESIUM(C)";
       else if(Prod_Code=="MB1212")
           Barcode_Test_Name="AST-S";
       else if(Prod_Code=="MB1222")
           Barcode_Test_Name="ALT-S";
       else if(Prod_Code=="MB1052")
           Barcode_Test_Name="ALP-S";
       else if(Prod_Code=="MB1122")
           Barcode_Test_Name="BILIRUBIN TOTAL-S";
       else if(Prod_Code=="MB1182")
           Barcode_Test_Name="CREATININE-S";
    ui->label_45->setText(""+Barcode_Test_Name+" - Concentration test");
    if(End_qc1_opt==1 || Two_qc1_opt==1 || Kin_qc1_opt==1)
    {
        QC_plot_func();
        End_qc1_opt=0;
        Two_qc1_opt=0;
        Kin_qc1_opt=0;
    }
    else if(End_qc2_opt==1 || Two_qc2_opt==1 || Kin_qc2_opt==1)
    {
        QC_plot_func();
        End_qc2_opt=0;
        Two_qc2_opt=0;
        Kin_qc2_opt=0;
    }
    else
        qDebug()<<"exit";

    ui->stackedWidget->setCurrentIndex(6);
}
