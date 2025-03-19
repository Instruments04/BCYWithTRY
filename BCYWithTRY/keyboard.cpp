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
static int opt=0;

void MainWindow::on_Patient_Name_Btn_clicked()
{
    opt=119;
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(0);
    key->getvalue(2);
    key->setData("Patient Name",ui->Patient_Name->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        // Retrieve and set data
        QString Data = key->getData();
        ui->Patient_Name->setText(Data);
        // Switch to desired stacked widget page
        ui->stackedWidget->setCurrentIndex(17);
    }
}

void MainWindow::on_Patient_Age_Btn_clicked()
{
    opt=120;
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Patient Age",ui->Patient_Age->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->Patient_Age->setText(Data);
        ui->stackedWidget->setCurrentIndex(17);
    }
}

void MainWindow::on_pushButton_200_clicked()
{
    opt=123;
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(2);
    key->getvalue(2);
    key->setData("Patient ID",ui->lineEdit_45->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_45->setText(Data);
        qDebug()<<"Click PID..";
        QSqlQueryModel * modal = new QSqlQueryModel();
        QSqlQuery * query= new QSqlQuery(mydb);
        query->prepare("select PID,PName,TName,Date,Time from Reports where PID='"+Data+"'");
        query->exec();
        modal->setQuery(*query);
        modal->setHeaderData( 0, Qt::Horizontal, QObject::tr("Patient ID") );
        modal->setHeaderData( 1, Qt::Horizontal, QObject::tr("Name") );
        modal->setHeaderData( 2, Qt::Horizontal, QObject::tr("Parameter name") );
        modal->setHeaderData( 3, Qt::Horizontal, QObject::tr("Date") );
        modal->setHeaderData( 4, Qt::Horizontal, QObject::tr("Time") );

        ui->tableView_2->setModel(modal);

        QSqlQueryModel * modall = new QSqlQueryModel();
        QSqlQuery* qury=new QSqlQuery(mydb);
        qury->prepare("select PID,PName,PAge,PGender,TName,ANrmlRang,BNrmlRang,ODVal,ResultOD,Unit,Date,Time from Reports where PID='"+Data+"'");
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
}

void MainWindow::on_pushButton_245_clicked()
{
    opt=127;
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(0);
    key->getvalue(2);
    key->setData("LotNo",ui->lineEdit_15->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_15->setText(Data);
        ui->stackedWidget->setCurrentIndex(22);
    }
}

void MainWindow::on_pushButton_296_clicked()
{
    opt=156;
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(0);
    key->getvalue(1);
    key->setData("Distributor Password",ui->lineEdit_96->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_96->setText(Data);
        ui->stackedWidget->setCurrentIndex(21);
        ui->stackedWidget_7->setCurrentIndex(0);
    }
}

void MainWindow::on_pushButton_298_clicked()
{
    opt=157;
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Distributor Code",ui->lineEdit_97->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_97->setText(Data);
        ui->stackedWidget->setCurrentIndex(21);
        ui->stackedWidget_7->setCurrentIndex(1);
    }
}


void MainWindow::on_pushButton_121_clicked()
{
    opt=167;
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(1);
    key->getvalue(2);
    key->setData("LAB Name",ui->Lab_name->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->Lab_name->setText(Data);
        ui->stackedWidget->setCurrentIndex(14);
    }
}

void MainWindow::on_pushButton_136_clicked()
{
    opt=168;
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(1);
    key->getvalue(2);
    key->setData("LAB Address",ui->Lab_address->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->Lab_address->setText(Data);
        ui->stackedWidget->setCurrentIndex(14);
    }
}

void MainWindow::on_pushButton_224_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Multiplication Factor",ui->lineEdit_147->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_147->setText(Data);
        ui->stackedWidget->setCurrentIndex(15);
    }
}


void MainWindow::on_pushButton_117_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(2);
    key->getvalue(2);
    key->setData("Patient Info",ui->PatientInfo_LineEdit->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        /*bool ok;
    QSqlQuery q;
    ok = q.exec("select * from  Reports where PID='"+Data+"'");
    if (ok && q.next())
    {
        qDebug()<<"Data Already Exists";
        QMessageBox msg(this);
        msg.setWindowFlags(Qt::Popup);
        msg.setStyleSheet("background-color:#a0cdfa;font: 75 20pt Liberation Serif ;");
        QPixmap p("/home/pi/git/BCYWithTRY/BCYWithTRY/img/cancel.png");
        auto newPixmap = p.scaled(80, 80);
        msg.setIconPixmap(newPixmap);
        QFont font;
        font.setBold(true);
        msg.setFont(font);
        msg.setText("Patient ID '"+Data+"' is already exist,please enter correct data.");
        QPushButton* saveButton = msg.addButton("Ok", QMessageBox::AcceptRole);
        saveButton->setStyleSheet("QPushButton{background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 #34ba91, stop: 0.5 #34ba91, stop: 1 #34ba91);color:black;}QPushButton:pressed {background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(0, 85, 0), stop: 0.5 rgb(0, 85, 0), stop: 1 rgb(0, 85, 0));color:white;}");
        msg.setDefaultButton(saveButton);
        msg.exec();
        if (msg.clickedButton() == saveButton)
        {
            ui->PatientInfo_LineEdit->clear();
            ui->stackedWidget->setCurrentIndex(17);
        }
    }*/
        if(!Data.isEmpty())
        {
            ui->EndPoint_Save_Btn->setEnabled(true);
            ui->EndPoint_Print_Btn->setEnabled(true);
        }
        else
        {
            ui->EndPoint_Save_Btn->setEnabled(false);
            ui->EndPoint_Print_Btn->setEnabled(false);
        }
        ui->PatientInfo_LineEdit->setText(Data);
        ui->stackedWidget->setCurrentIndex(17);
    }
}

void MainWindow::on_pushButton_118_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(0);
    key->getvalue(2);
    key->setData("Test Name",ui->lineEdit_4->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_4->setText(Data);
        QSqlQuery query;
        bool ok;
        QSqlQuery q;
        ok = q.exec("select * from test where name='"+Data+"'");
        if (ok && q.next())
        {
            QMessageBox msg(this);
            msg.setWindowFlags(Qt::Popup);
            msg.setStyleSheet("background-color:#a0cdfa;font: 75 20pt Liberation Serif ;");
            QPixmap p("/home/pi/git/BCYWithTRY/BCYWithTRY/img/notification.png");
            auto newPixmap = p.scaled(80, 80);
            msg.setIconPixmap(newPixmap);
            QFont font;
            font.setBold(true);
            msg.setFont(font);
            msg.setText("This parameter name was already exist");
            QPushButton* saveButton = msg.addButton("Ok", QMessageBox::AcceptRole);
            saveButton->setStyleSheet("QPushButton{background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 #34ba91, stop: 0.5 #34ba91, stop: 1 #34ba91);color:black;}QPushButton:pressed {background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(0, 85, 0), stop: 0.5 rgb(0, 85, 0), stop: 1 rgb(0, 85, 0));color:white;}");
            msg.setDefaultButton(saveButton);
            msg.exec();
            if (msg.clickedButton() == saveButton)
            {
                ui->pushButton_118->setVisible(true);
                ui->lineEdit_4->setStyleSheet("background-color:white;color:black;border: none");
                ui->lineEdit_4->clear();
                ui->stackedWidget->setCurrentIndex(4);
            }
            else
            {
                ui->lineEdit_4->setStyleSheet("border: 1px solid red");
                ui->lineEdit_4->clear();
                ui->pushButton_118->setVisible(true);
                ui->stackedWidget->setCurrentIndex(4);

            }
        }
    }
}

void MainWindow::on_pushButton_119_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(0);
    key->getvalue(2);
    key->setData("Unit",ui->lineEdit_5->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_5->setText(Data);
        ui->stackedWidget->setCurrentIndex(4);
    }
}

void MainWindow::on_pushButton_123_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Factor",ui->lineEdit_6->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_6->setText(Data);
        ui->stackedWidget->setCurrentIndex(4);
    }
}

void MainWindow::on_pushButton_124_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Delay Time(S)",ui->lineEdit_7->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_7->setText(Data);
        ui->stackedWidget->setCurrentIndex(4);
    }
}

void MainWindow::on_pushButton_122_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Incubation Time(S)",ui->lineEdit_8->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_8->setText(Data);

        QString Datas = ui->ReactionType_Combo->currentText();
        if(Datas == "End point")
            ui->label_420->clear();
        else if(Datas == "Fixed Kinetic")
            ui->label_420->clear();
        else if(Datas == "Kinetic")
        {
            if(Data == "120")
                ui->label_420->setText("2");
            else if(Data == "90")
                ui->label_420->setText("3");
            else if(Data == "180")
                ui->label_420->setText("3");
        }
        ui->stackedWidget->setCurrentIndex(4);
    }
}

void MainWindow::on_pushButton_120_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Linear Range(Min)",ui->lineEdit_9->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_9->setText(Data);
        ui->stackedWidget->setCurrentIndex(4);
    }
}

void MainWindow::on_pushButton_125_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Linear Range(Max)",ui->lineEdit_10->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_10->setText(Data);
        ui->stackedWidget->setCurrentIndex(4);
    }
}

void MainWindow::on_pushButton_126_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Normal Range(Male-Min)",ui->lineEdit_12->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_12->setText(Data);
        ui->stackedWidget->setCurrentIndex(4);
    }
}

void MainWindow::on_pushButton_127_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Normal Range(Male-Max)",ui->lineEdit_11->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_11->setText(Data);
        ui->stackedWidget->setCurrentIndex(4);
    }
}

void MainWindow::on_pushButton_207_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Concentration(1)",ui->lineEdit_88->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {

        QString Data = key->getData();
        ui->lineEdit_88->setText(Data);
        ui->stackedWidget->setCurrentIndex(4);
    }
}

void MainWindow::on_pushButton_213_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Concentration(2)",ui->lineEdit_92->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_92->setText(Data);
        ui->stackedWidget->setCurrentIndex(4);
    }
}

void MainWindow::on_pushButton_210_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Concentration(3)",ui->lineEdit_89->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_89->setText(Data);
        ui->stackedWidget->setCurrentIndex(4);
    }
}

void MainWindow::on_pushButton_212_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Concentration(4)",ui->lineEdit_95->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_95->setText(Data);
        ui->stackedWidget->setCurrentIndex(4);
    }
}

void MainWindow::on_pushButton_208_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Concentration(5)",ui->lineEdit_90->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_90->setText(Data);
        ui->stackedWidget->setCurrentIndex(4);
    }
}

void MainWindow::on_pushButton_214_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Concentration(6)",ui->lineEdit_94->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_94->setText(Data);
        ui->stackedWidget->setCurrentIndex(4);
    }
}

void MainWindow::on_pushButton_209_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Concentration(7)",ui->lineEdit_91->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_91->setText(Data);
        ui->stackedWidget->setCurrentIndex(4);
    }
}

void MainWindow::on_pushButton_211_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);key->getvalue(2);
    key->setData("Concentration(8)",ui->lineEdit_93->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_93->setText(Data);
        ui->stackedWidget->setCurrentIndex(4);
    }
}

void MainWindow::on_pushButton_137_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Control 1 - Minimum",ui->lineEdit_23->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_23->setText(Data);
        ui->stackedWidget->setCurrentIndex(4);

        double val1 = ui->lineEdit_23->text().toInt();
        double val2 = ui->lineEdit_141->text().toInt();
        double Datas = val1+val2;
        double Divide = Datas / 2 ;
        if(Divide<100.0)
        {
            if(Divide<10.0)
                ui->label_435->setText(QString::number(Divide, 'f' , 2));
            else
                ui->label_435->setText(QString::number(Divide, 'f' , 1));
        }
        else if(Divide>100.0)
        {
            ui->label_435->setText(QString::number(Divide, 'f' , 0));
        }
        qDebug()<<"Divide : "<<Divide<<Data;
    }
}

void MainWindow::on_pushButton_138_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Control 1 - LotNo",ui->lineEdit_26->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_26->setText(Data);
        ui->stackedWidget->setCurrentIndex(4);
    }
}
void MainWindow::on_pushButton_140_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Control 2 - Minimum",ui->lineEdit_28->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_28->setText(Data);
        ui->stackedWidget->setCurrentIndex(4);
        double val1 = ui->lineEdit_28->text().toInt();
        double val2 = ui->lineEdit_142->text().toInt();
        double Datas = val1+val2;
        double Divide = Datas / 2 ;
        if(Divide<100.0)
        {
            if(Divide<10.0)
                ui->label_436->setText(QString::number(Divide, 'f' , 2));
            else
                ui->label_436->setText(QString::number(Divide, 'f' , 1));
        }
        else if(Divide>100.0)
        {
            ui->label_436->setText(QString::number(Divide, 'f' , 0));
        }
        qDebug()<<"Divide : "<<Divide<<Data;
    }
}

void MainWindow::on_pushButton_141_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(2);
    key->getvalue(2);
    key->setData("Control 2 - LotNo",ui->lineEdit_29->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_29->setText(Data);
        ui->stackedWidget->setCurrentIndex(4);
    }
}
void MainWindow::on_pushButton_147_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(0);
    key->getvalue(2);
    key->setData("Unit",ui->lineEdit_27->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_27->setText(Data);
        ui->stackedWidget->setCurrentIndex(5);
    }
}

void MainWindow::on_pushButton_143_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Factor",ui->lineEdit_30->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_30->setText(Data);
        ui->stackedWidget->setCurrentIndex(5);
    }
}

void MainWindow::on_pushButton_145_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Linear Range(Low)",ui->lineEdit_33->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_33->setText(Data);
        ui->stackedWidget->setCurrentIndex(5);
    }
}

void MainWindow::on_pushButton_144_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Linear Range(High)",ui->lineEdit_34->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_34->setText(Data);
        ui->stackedWidget->setCurrentIndex(5);
    }
}

void MainWindow::on_pushButton_146_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Normal Range(Male-Min)",ui->lineEdit_36->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_36->setText(Data);
        ui->stackedWidget->setCurrentIndex(5);
    }
}

void MainWindow::on_pushButton_201_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Normal Range(Male-Max)",ui->lineEdit_35->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_35->setText(Data);
        ui->stackedWidget->setCurrentIndex(5);
    }
}

void MainWindow::on_pushButton_215_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Concentration(1)",ui->lineEdit_112->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_112->setText(Data);
        ui->stackedWidget->setCurrentIndex(5);
    }
}

void MainWindow::on_pushButton_236_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Concentration(2)",ui->lineEdit_116->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_116->setText(Data);
        ui->stackedWidget->setCurrentIndex(5);
    }
}

void MainWindow::on_pushButton_234_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Concentration(3)",ui->lineEdit_113->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_113->setText(Data);
        ui->stackedWidget->setCurrentIndex(5);
    }
}

void MainWindow::on_pushButton_238_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Concentration(4)",ui->lineEdit_119->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_119->setText(Data);
        ui->stackedWidget->setCurrentIndex(5);
    }
}

void MainWindow::on_pushButton_232_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Concentration(5)",ui->lineEdit_114->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_114->setText(Data);
        ui->stackedWidget->setCurrentIndex(5);
    }
}

void MainWindow::on_pushButton_237_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Concentration(6)",ui->lineEdit_118->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_118->setText(Data);
        ui->stackedWidget->setCurrentIndex(5);
    }
}

void MainWindow::on_pushButton_233_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Concentration(7)",ui->lineEdit_115->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_115->setText(Data);
        ui->stackedWidget->setCurrentIndex(5);
    }
}

void MainWindow::on_pushButton_235_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Concentration(8)",ui->lineEdit_117->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_117->setText(Data);
        ui->stackedWidget->setCurrentIndex(5);
    }
}

void MainWindow::on_pushButton_160_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Control1 - Minimum",ui->lineEdit_59->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_59->setText(Data);
        ui->stackedWidget->setCurrentIndex(5);
        double val1 = ui->lineEdit_59->text().toDouble();
        double val2 = ui->lineEdit_143->text().toDouble();
        double Datas = val1+val2;
        double Divide = Datas / 2 ;
        if(Divide<100.0)
        {
            if(Divide<10.0)
                ui->label_216->setText(QString::number(Divide, 'f' , 2));
            else
                ui->label_216->setText(QString::number(Divide, 'f' , 1));
        }
        else if(Divide>100.0)
        {
            ui->label_216->setText(QString::number(Divide, 'f' , 0));
        }
        qDebug()<<"Divide : "<<Divide<<Data;
        qDebug()<<"Update Divide : "<<Divide<<Data;
    }
}

void MainWindow::on_pushButton_161_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(2);
    key->getvalue(2);
    key->setData("Control1 - LotNo",ui->lineEdit_60->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_60->setText(Data);
        ui->stackedWidget->setCurrentIndex(5);
    }
}

void MainWindow::on_pushButton_163_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Control2 - Minimum",ui->lineEdit_62->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_62->setText(Data);
        ui->stackedWidget->setCurrentIndex(5);
        double val1 = ui->lineEdit_62->text().toInt();
        double val2 = ui->lineEdit_144->text().toInt();
        double Datas = val1+val2;
        double Divide = Datas / 2 ;
        if(Divide<100.0)
        {
            if(Divide<10.0)
                ui->label_434->setText(QString::number(Divide, 'f' , 2));
            else
                ui->label_434->setText(QString::number(Divide, 'f' , 1));
        }
        else if(Divide>100.0)
        {
            ui->label_434->setText(QString::number(Divide, 'f' , 0));
        }
        qDebug()<<"Divide : "<<Divide<<Data;
    }
}

void MainWindow::on_pushButton_164_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(2);
    key->getvalue(2);
    key->setData("Control2 - LotNo",ui->lineEdit_63->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_63->setText(Data);
        ui->stackedWidget->setCurrentIndex(5);
    }

}
void MainWindow::on_pushButton_195_clicked()
{
    ui->lineEdit_13->setFocus();
    ui->lineEdit_13->installEventFilter(this);
    this->installEventFilter(this);

    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(2);
    key->getvalue(2);
    key->setData("Barcode Data",ui->lineEdit_13->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_13->setText(Data);
        qDebug()<<"Dataa : "<<Data;
        if(Data==" ")
        {
            ui->lineEdit_13->setText(Data.toLower());
            ui->stackedWidget->setCurrentIndex(22);
            ui->lineEdit_13->setFocus();
        }
        else
        {
            ui->lineEdit_13->setText(Data.toLower());
            ui->stackedWidget->setCurrentIndex(22);
            ui->lineEdit_13->setFocus();
            Barcode_ExistingCheck();
        }
    }
}
void MainWindow::on_pushButton_196_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(1);key->getvalue(2);
    key->setData("Test Code",ui->lineEdit_42->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_42->setText(Data);

        ui->stackedWidget->setCurrentIndex(4);
        TestCode_Checker1();
    }
}

void MainWindow::on_pushButton_204_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(0);key->getvalue(1);
    key->setData("Password",ui->lineEdit_2->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_2->setText(Data);
        ui->pushButton_23->setVisible(true);
        ui->stackedWidget->setCurrentIndex(12);
        on_pushButton_23_clicked();
    }
    //  ui->pushButton_25->setVisible(false);
}

void MainWindow::on_pushButton_172_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Intensity-340 nm",ui->lineEdit_72->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_72->setText(Data);


        int intensity=0;
        QSqlQuery query;
        query.prepare("select * from tests where sno=1");
        query.exec();
        while(query.next())
        {
            intensity=query.value(1).toInt();
        }
        QString ity1=QString::number(intensity);
        ui->lineEdit_72->setText(ity1);
        QSqlQuery qury;
        qury.prepare("update tests set intensity=:Data where sno=1");
        qury.bindValue(":Data",Data);
        qury.exec();
        on_pushButton_7_clicked();
    }
}

void MainWindow::on_pushButton_173_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Intensity-405 nm",ui->lineEdit_73->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_73->setText(Data);

        int intensity=0;
        QSqlQuery query;
        query.prepare("select * from tests where sno=2");
        query.exec();
        while(query.next())
        {
            intensity=query.value(1).toInt();
        }
        QString ity2=QString::number(intensity);
        ui->lineEdit_73->setText(ity2);

        QSqlQuery qury;
        qury.prepare("update tests set intensity=:Data where sno=2");
        qury.bindValue(":Data",Data);
        qury.exec();
        on_pushButton_7_clicked();
    }
}

void MainWindow::on_pushButton_174_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Intensity-505 nm",ui->lineEdit_74->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_74->setText(Data);

        int intensity=0;
        QSqlQuery query;
        query.prepare("select * from tests where sno=3");
        query.exec();
        while(query.next())
        {
            intensity=query.value(1).toInt();
        }
        QString ity3=QString::number(intensity);
        ui->lineEdit_74->setText(ity3);
        QSqlQuery qury;
        qury.prepare("update tests set intensity=:Data where sno=3");
        qury.bindValue(":Data",Data);
        qury.exec();
        on_pushButton_7_clicked();
    }
}

void MainWindow::on_pushButton_175_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Intensity-545 nm",ui->lineEdit_75->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_75->setText(Data);

        int intensity=0;
        QSqlQuery query;
        query.prepare("select * from tests where sno=4");
        query.exec();
        while(query.next())
        {
            intensity=query.value(1).toInt();
        }
        QString ity4=QString::number(intensity);
        ui->lineEdit_75->setText(ity4);
        QSqlQuery qury;
        qury.prepare("update tests set intensity=:Data where sno=4");
        qury.bindValue(":Data",Data);
        qury.exec();
        on_pushButton_7_clicked();
    }
}

void MainWindow::on_pushButton_176_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Intensity-570 nm",ui->lineEdit_76->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_76->setText(Data);

        int intensity=0;
        QSqlQuery query;
        query.prepare("select * from tests where sno=5");
        query.exec();
        while(query.next())
        {
            intensity=query.value(1).toInt();
        }
        QString ity5=QString::number(intensity);
        ui->lineEdit_76->setText(ity5);
        QSqlQuery qury;
        qury.prepare("update tests set intensity=:Data where sno=5");
        qury.bindValue(":Data",Data);
        qury.exec();
        on_pushButton_7_clicked();
    }
}

void MainWindow::on_pushButton_177_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Intensity-630 nm",ui->lineEdit_77->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_77->setText(Data);

        int intensity=0;
        QSqlQuery query;
        query.prepare("select * from tests where sno=6");
        query.exec();
        while(query.next())
        {
            intensity=query.value(1).toInt();
        }
        QString ity6=QString::number(intensity);
        ui->lineEdit_77->setText(ity6);
        QSqlQuery qury;
        qury.prepare("update tests set intensity=:Data where sno=6");
        qury.bindValue(":Data",Data);
        qury.exec();
        on_pushButton_7_clicked();
    }
}

void MainWindow::on_pushButton_178_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Intensity-700 nm",ui->lineEdit_78->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_78->setText(Data);

        int intensity=0;
        QSqlQuery query;
        query.prepare("select * from tests where sno=7");
        query.exec();
        while(query.next())
        {
            intensity=query.value(1).toInt();
        }
        QString ity7=QString::number(intensity);
        ui->lineEdit_78->setText(ity7);
        QSqlQuery qury;
        qury.prepare("update tests set intensity=:Data where sno=7");
        qury.bindValue(":Data",Data);
        qury.exec();
        on_pushButton_7_clicked();
    }
}

void MainWindow::on_pushButton_179_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Abs - 340 nm",ui->lineEdit_83->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_83->setText(Data);

        int ABS=0;
        QSqlQuery query;
        query.prepare("select * from tests where sno=1");
        query.exec();
        while(query.next())
        {
            ABS=query.value(9).toInt();
        }
        QString ABS1=QString::number(ABS);
        ui->lineEdit_83->setText(ABS1);
        QSqlQuery qry;
        qry.prepare("update tests set ABS=:Data where sno=1");
        qry.bindValue(":Data",Data);
        qry.exec();
        on_pushButton_7_clicked();
    }
}

void MainWindow::on_pushButton_184_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Abs - 405 nm",ui->lineEdit_84->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_84->setText(Data);
        int ABS=0;
        QSqlQuery query;
        query.prepare("select * from tests where sno=2");
        query.exec();
        while(query.next())
        {
            ABS=query.value(9).toInt();
        }
        QString ABS2=QString::number(ABS);
        ui->lineEdit_84->setText(ABS2);
        QSqlQuery qry;
        qry.prepare("update tests set ABS=:Data where sno=2");
        qry.bindValue(":Data",Data);
        qry.exec();
        on_pushButton_7_clicked();
    }
}

void MainWindow::on_pushButton_181_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Abs - 505 nm",ui->lineEdit_80->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_80->setText(Data);

        int ABS=0;
        QSqlQuery query;
        query.prepare("select * from tests where sno=3");
        query.exec();
        while(query.next())
        {
            ABS=query.value(9).toInt();
        }
        QString ABS3=QString::number(ABS);
        ui->lineEdit_80->setText(ABS3);
        QSqlQuery qry;
        qry.prepare("update tests set ABS=:Data where sno=3");
        qry.bindValue(":Data",Data);
        qry.exec();
        on_pushButton_7_clicked();
    }
}

void MainWindow::on_pushButton_183_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Abs - 545 nm",ui->lineEdit_82->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_82->setText(Data);
        int ABS=0;
        QSqlQuery query;
        query.prepare("select * from tests where sno=4");
        query.exec();
        while(query.next())
        {
            ABS=query.value(9).toInt();
        }
        QString ABS4=QString::number(ABS);
        ui->lineEdit_82->setText(ABS4);
        QSqlQuery qry;
        qry.prepare("update tests set ABS=:Data where sno=4");
        qry.bindValue(":Data",Data);
        qry.exec();
        on_pushButton_7_clicked();
    }
}

void MainWindow::on_pushButton_185_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Abs - 570 nm",ui->lineEdit_79->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_79->setText(Data);
        int ABS=0;
        QSqlQuery query;
        query.prepare("select * from tests where sno=5");
        query.exec();
        while(query.next())
        {
            ABS=query.value(9).toInt();
        }
        QString ABS5=QString::number(ABS);
        ui->lineEdit_79->setText(ABS5);
        QSqlQuery qry;
        qry.prepare("update tests set ABS=:Data where sno=5");
        qry.bindValue(":Data",Data);
        qry.exec();
        on_pushButton_7_clicked();
    }
}

void MainWindow::on_pushButton_182_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Abs - 630 nm",ui->lineEdit_81->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_81->setText(Data);
        int ABS=0;
        QSqlQuery query;
        query.prepare("select * from tests where sno=6");
        query.exec();
        while(query.next())
        {
            ABS=query.value(9).toInt();
        }
        QString ABS6=QString::number(ABS);
        ui->lineEdit_81->setText(ABS6);
        QSqlQuery qry;
        qry.prepare("update tests set ABS=:Data where sno=6");
        qry.bindValue(":Data",Data);
        qry.exec();
        on_pushButton_7_clicked();
    }
}

void MainWindow::on_pushButton_180_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Abs - 700 nm",ui->lineEdit_85->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_85->setText(Data);
        int ABS=0;
        QSqlQuery query;
        query.prepare("select * from tests where sno=7");
        query.exec();
        while(query.next())
        {
            ABS=query.value(9).toInt();
        }
        QString ABS7=QString::number(ABS);
        ui->lineEdit_85->setText(ABS7);
        QSqlQuery qry;
        qry.prepare("update tests set ABS=:Data where sno=7");
        qry.bindValue(":Data",Data);
        qry.exec();
        on_pushButton_7_clicked();
    }
}

void MainWindow::on_pushButton_188_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Abs - 340 nm",ui->lineEdit_139->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_139->setText(Data);

        int ABSO=0;
        QSqlQuery query;
        query.prepare("select * from tests where sno=1");
        query.exec();
        while(query.next())
        {
            ABSO=query.value(10).toInt();
        }
        QString ABSO1=QString::number(ABSO);
        ui->lineEdit_139->setText(ABSO1);
        QSqlQuery qy;
        qy.prepare("update tests set ABSO=:Data where sno=1");
        qy.bindValue(":Data",Data);
        qy.exec();
        on_pushButton_7_clicked();
    }

}

void MainWindow::on_pushButton_205_clicked()
{

    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Abs - 405 nm",ui->lineEdit_137->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_137->setText(Data);
        int ABSO=0;
        QSqlQuery query;
        query.prepare("select * from tests where sno=2");
        query.exec();
        while(query.next())
        {
            ABSO=query.value(10).toInt();
        }
        QString ABSO2=QString::number(ABSO);
        ui->lineEdit_137->setText(ABSO2);
        QSqlQuery qy;
        qy.prepare("update tests set ABSO=:Data where sno=2");
        qy.bindValue(":Data",Data);
        qy.exec();
        on_pushButton_7_clicked();
    }
}

void MainWindow::on_pushButton_216_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Abs - 505 nm",ui->lineEdit_86->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_86->setText(Data);

        int ABSO=0;
        QSqlQuery query;
        query.prepare("select * from tests where sno=3");
        query.exec();
        while(query.next())
        {
            ABSO=query.value(10).toInt();
        }
        QString ABSO3=QString::number(ABSO);
        ui->lineEdit_86->setText(ABSO3);
        QSqlQuery qy;
        qy.prepare("update tests set ABSO=:Data where sno=3");
        qy.bindValue(":Data",Data);
        qy.exec();
        on_pushButton_7_clicked();
    }
}


void MainWindow::on_pushButton_206_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);key->getvalue(2);
    key->setData("Abs - 545 nm",ui->lineEdit_87->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_87->setText(Data);

        int ABSO=0;
        QSqlQuery query;
        query.prepare("select * from tests where sno=4");
        query.exec();
        while(query.next())
        {
            ABSO=query.value(10).toInt();
        }
        QString ABSO4=QString::number(ABSO);
        ui->lineEdit_87->setText(ABSO4);
        QSqlQuery qy;
        qy.prepare("update tests set ABSO=:Data where sno=4");
        qy.bindValue(":Data",Data);
        qy.exec();
        on_pushButton_7_clicked();
    }
}
void MainWindow::on_pushButton_186_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Abs - 570 nm",ui->lineEdit_140->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_140->setText(Data);
        int ABSO=0;
        QSqlQuery query;
        query.prepare("select * from tests where sno=5");
        query.exec();
        while(query.next())
        {
            ABSO=query.value(10).toInt();
        }
        QString ABSO5=QString::number(ABSO);
        ui->lineEdit_140->setText(ABSO5);
        QSqlQuery qy;
        qy.prepare("update tests set ABSO=:Data where sno=5");
        qy.bindValue(":Data",Data);
        qy.exec();
        on_pushButton_7_clicked();
    }
}

void MainWindow::on_pushButton_217_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Abs - 630 nm",ui->lineEdit_136->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_136->setText(Data);
        int ABSO=0;
        QSqlQuery query;
        query.prepare("select * from tests where sno=6");
        query.exec();
        while(query.next())
        {
            ABSO=query.value(10).toInt();
        }
        QString ABSO6=QString::number(ABSO);
        ui->lineEdit_136->setText(ABSO6);
        QSqlQuery qy;
        qy.prepare("update tests set ABSO=:Data where sno=6");
        qy.bindValue(":Data",Data);
        qy.exec();
        on_pushButton_7_clicked();
    }
}

void MainWindow::on_pushButton_187_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Abs - 700 nm",ui->lineEdit_138->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_138->setText(Data);
        int ABSO=0;
        QSqlQuery query;
        query.prepare("select * from tests where sno=7");
        query.exec();
        while(query.next())
        {
            ABSO=query.value(10).toInt();
        }
        QString ABSO7=QString::number(ABSO);
        ui->lineEdit_138->setText(ABSO7);
        QSqlQuery qy;
        qy.prepare("update tests set ABSO=:Data where sno=7");
        qy.bindValue(":Data",Data);
        qy.exec();
        on_pushButton_7_clicked();
    }
}

void MainWindow::on_pushButton_218_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Control 1 - Maximum",ui->lineEdit_141->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_141->setText(Data);
        //Save
        ui->stackedWidget->setCurrentIndex(4);

        double val1 = ui->lineEdit_23->text().toInt();
        double val2 = ui->lineEdit_141->text().toInt();
        double Datas = val1+val2;
        double Divide = Datas / 2 ;
        if(Divide<100.0)
        {
            if(Divide<10.0)
                ui->label_435->setText(QString::number(Divide, 'f' , 2));
            else
                ui->label_435->setText(QString::number(Divide, 'f' , 1));
        }
        else if(Divide>100.0)
        {
            ui->label_435->setText(QString::number(Divide, 'f' , 0));
        }
        qDebug()<<"Divide : "<<Divide<<Data;
    }
}

void MainWindow::on_pushButton_219_clicked()
{
    //Save
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Control 2 - Maximum",ui->lineEdit_142->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_142->setText(Data);
        ui->stackedWidget->setCurrentIndex(4);

        double val1 = ui->lineEdit_28->text().toInt();
        double val2 = ui->lineEdit_142->text().toInt();
        double Datas = val1+val2;
        double Divide = Datas / 2 ;
        if(Divide<100.0)
        {
            if(Divide<10.0)
                ui->label_436->setText(QString::number(Divide, 'f' , 2));
            else
                ui->label_436->setText(QString::number(Divide, 'f' , 1));
        }
        else if(Divide>100.0)
        {
            ui->label_436->setText(QString::number(Divide, 'f' , 0));
        }
        qDebug()<<"Divide : "<<Divide<<Data;
    }
}

void MainWindow::on_pushButton_220_clicked()
{
    //Update
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Control1 - Maximum",ui->lineEdit_143->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_143->setText(Data);
        ui->stackedWidget->setCurrentIndex(5);

        double val1 = ui->lineEdit_59->text().toDouble();
        double val2 = ui->lineEdit_143->text().toDouble();
        double Datas = val1+val2;
        double Divide = Datas / 2 ;
        if(Divide<100.0)
        {
            if(Divide<10.0)
                ui->label_216->setText(QString::number(Divide, 'f' , 2));
            else
                ui->label_216->setText(QString::number(Divide, 'f' , 1));
        }
        else if(Divide>100.0)
        {
            ui->label_216->setText(QString::number(Divide, 'f' , 0));
        }
        qDebug()<<"Divide : "<<Divide<<Data;
    }
}

void MainWindow::on_pushButton_221_clicked()
{
    //Update
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Control2 - Maximum",ui->lineEdit_144->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_144->setText(Data);
        ui->stackedWidget->setCurrentIndex(5);

        double val1 = ui->lineEdit_62->text().toDouble();
        double val2 = ui->lineEdit_144->text().toDouble();
        double Datas = val1+val2;
        double Divide = Datas / 2 ;
        if(Divide<100.0)
        {
            if(Divide<10.0)
                ui->label_434->setText(QString::number(Divide, 'f' , 2));
            else
                ui->label_434->setText(QString::number(Divide, 'f' , 1));
        }
        else if(Divide>100.0)
        {
            ui->label_434->setText(QString::number(Divide, 'f' , 0));
        }
        qDebug()<<"Divide : "<<Divide<<Data;
    }
}

void MainWindow::on_pushButton_275_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(2);
    key->getvalue(2);
    key->setData("LotNo",ui->lineEdit_153->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_153->setText(Data);
        ui->stackedWidget->setCurrentIndex(5);
    }
}


void MainWindow::on_pushButton_267_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(2);
    key->getvalue(2);
    key->setData("LotNo",ui->lineEdit_152->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_152->setText(Data);
        ui->stackedWidget->setCurrentIndex(4);
    }
}

void MainWindow::on_pushButton_277_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(2);
    key->getvalue(2);
    key->setData("IP Address",ui->IPAddress_lineEdit->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->IPAddress_lineEdit->setText(Data);
        ui->stackedWidget->setCurrentIndex(19);
        ui->stackedWidget_6->setCurrentIndex(1);
    }
}


void MainWindow::on_pushButton_278_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Port",ui->Port_lineEdit->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->Port_lineEdit->setText(Data);
        ui->stackedWidget->setCurrentIndex(19);
        ui->stackedWidget_6->setCurrentIndex(1);
    }
}

void MainWindow::on_pushButton_244_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(1);
    key->getvalue(1);
    if(settings_mode==1)
        key->setData("Service Password",ui->lineEdit_150->text());
    else if(settings_mode==2)
        key->setData("Maintainer Password",ui->lineEdit_150->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_150->setText(Data);
        if(Data.isEmpty())
        {
            ui->pushButton_13->setEnabled(true);
            ui->pushButton_14->setEnabled(true);
            ui->pushButton_13->setVisible(true);
            ui->pushButton_14->setVisible(false);
        }
        else
        {
            ui->pushButton_13->setEnabled(true);
            ui->pushButton_14->setEnabled(true);
            ui->pushButton_13->setVisible(false);
            ui->pushButton_14->setVisible(true);
        }
    }
}

void MainWindow::on_pushButton_249_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(1);
    key->getvalue(2);
    key->setData("Enter a file name ",ui->lineEdit_52->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_52->setText(Data);
    }
}


void MainWindow::on_pushButton_222_clicked()
{
    QString Serial = ui->label_44->text();
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(1);
    key->setData("Patient Name",ui->PName_lineEdit->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->PName_lineEdit->setText(Data);
        qDebug()<<"Sno :"<<Serial<<"Pname : "<<Data;

        QSqlQuery query;
        query.prepare("UPDATE Reports SET PName = :Data WHERE TRIM(PID) = :Serial");
        query.bindValue(":Data", Data.trimmed());
        query.bindValue(":Serial", Serial.trimmed());

        if (!query.exec()) {
            qDebug() << "Update failed:" << query.lastError().text();
        } else {
            qDebug() << "Update successful.";
            qDebug() << "Affected Rows:" << query.numRowsAffected();

            if (query.numRowsAffected() == 0) {
                qDebug() << "No rows matched the condition. Check the sno value.";
            }

            // Check the updated data
            QSqlQuery checkQuery;
            checkQuery.prepare("SELECT * FROM Reports WHERE PID = :Serial");
            checkQuery.bindValue(":Serial", Serial.trimmed());
            if (checkQuery.exec()) {
                if (checkQuery.next()) {
                    qDebug() << "Row after update: Sno:" << checkQuery.value("PID").toString()
                             << "PName:" << checkQuery.value("PName").toString();
                } else {
                    qDebug() << "No row found with sno = " << Serial;
                }
            } else {
                qDebug() << "Error fetching updated data:" << checkQuery.lastError().text();
            }

            // Create a new QSqlQueryModel
            QSqlQueryModel *modal = new QSqlQueryModel();

            // Create and prepare the query
            QSqlQuery query(mydb);
            query.prepare("SELECT PID, PName, TName, Date, Time FROM Reports");

            // Execute the query
            if (!query.exec()) {
                qDebug() << "Query execution failed:" << query.lastError().text();
                return;
            }

            // Set the query result to the model
            modal->setQuery(query);

            // Set custom headers
            modal->setHeaderData(0, Qt::Horizontal, QObject::tr("Patient ID"));
            modal->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
            modal->setHeaderData(2, Qt::Horizontal, QObject::tr("Parameter Name"));
            modal->setHeaderData(3, Qt::Horizontal, QObject::tr("Date"));
            modal->setHeaderData(4, Qt::Horizontal, QObject::tr("Time"));

            // Assign the model to the table views
            ui->tableView_2->setModel(modal);
            ui->tableView_5->setModel(modal);

            // Resize columns to fit contents
            ui->tableView_2->resizeColumnsToContents();
            ui->tableView_5->resizeColumnsToContents();

        }


        ui->stackedWidget->setCurrentIndex(9);
    }
}

void MainWindow::on_pushButton_230_clicked()
{
    QString Serial = ui->label_44->text();
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(2);
    key->setData("Patient Age",ui->PAge_lineEdit->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->PAge_lineEdit->setText(Data);

        QSqlQuery query;
        query.prepare("UPDATE Reports SET PAge = :Data WHERE TRIM(PID) = :Serial");
        query.bindValue(":Data", Data.trimmed());
        query.bindValue(":Serial", Serial.trimmed());

        if (!query.exec()) {
            qDebug() << "Update failed:" << query.lastError().text();
        } else {
            qDebug() << "Update successful.";
            qDebug() << "Affected Rows:" << query.numRowsAffected();

            if (query.numRowsAffected() == 0) {
                qDebug() << "No rows matched the condition. Check the sno value.";
            }

            // Check the updated data
            QSqlQuery checkQuery;
            checkQuery.prepare("SELECT * FROM Reports WHERE PID = :Serial");
            checkQuery.bindValue(":Serial", Serial.trimmed());
            if (checkQuery.exec()) {
                if (checkQuery.next()) {
                    qDebug() << "Row after update: Sno:" << checkQuery.value("PID").toString()
                             << "PName:" << checkQuery.value("PAge").toString();
                } else {
                    qDebug() << "No row found with sno = " << Serial;
                }
            } else {
                qDebug() << "Error fetching updated data:" << checkQuery.lastError().text();
            }

            // Create a new QSqlQueryModel
            QSqlQueryModel *modal = new QSqlQueryModel();

            // Create and prepare the query
            QSqlQuery query(mydb);
            query.prepare("SELECT PID, PName, TName, Date, Time FROM Reports");

            // Execute the query
            if (!query.exec()) {
                qDebug() << "Query execution failed:" << query.lastError().text();
                return;
            }

            // Set the query result to the model
            modal->setQuery(query);

            // Set custom headers
            modal->setHeaderData(0, Qt::Horizontal, QObject::tr("Patient ID"));
            modal->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
            modal->setHeaderData(2, Qt::Horizontal, QObject::tr("Parameter Name"));
            modal->setHeaderData(3, Qt::Horizontal, QObject::tr("Date"));
            modal->setHeaderData(4, Qt::Horizontal, QObject::tr("Time"));

            // Assign the model to the table views
            ui->tableView_2->setModel(modal);
            ui->tableView_5->setModel(modal);

            // Resize columns to fit contents
            ui->tableView_2->resizeColumnsToContents();
            ui->tableView_5->resizeColumnsToContents();
        }

        ui->stackedWidget->setCurrentIndex(9);
    }
}

void MainWindow::on_pushButton_262_clicked()
{
    QString Serial = ui->label_44->text();
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(1);
    key->setData("Unit",ui->Unit_LE->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->Unit_LE->setText(Data);

        QSqlQuery query;
        query.prepare("UPDATE Reports SET Unit = :Data WHERE TRIM(PID) = :Serial");
        query.bindValue(":Data", Data.trimmed());
        query.bindValue(":Serial", Serial.trimmed());

        if (!query.exec()) {
            qDebug() << "Update failed:" << query.lastError().text();
        } else {
            qDebug() << "Update successful.";
            qDebug() << "Affected Rows:" << query.numRowsAffected();

            if (query.numRowsAffected() == 0) {
                qDebug() << "No rows matched the condition. Check the sno value.";
            }

            // Check the updated data
            QSqlQuery checkQuery;
            checkQuery.prepare("SELECT * FROM Reports WHERE PID = :Serial");
            checkQuery.bindValue(":Serial", Serial.trimmed());
            if (checkQuery.exec()) {
                if (checkQuery.next()) {
                    qDebug() << "Row after update: Sno:" << checkQuery.value("PID").toString()
                             << "PName:" << checkQuery.value("Unit").toString();
                } else {
                    qDebug() << "No row found with sno = " << Serial;
                }
            } else {
                qDebug() << "Error fetching updated data:" << checkQuery.lastError().text();
            }

            // Create a new QSqlQueryModel
            QSqlQueryModel *modal = new QSqlQueryModel();

            // Create and prepare the query
            QSqlQuery query(mydb);
            query.prepare("SELECT PID, PName, TName, Date, Time FROM Reports");

            // Execute the query
            if (!query.exec()) {
                qDebug() << "Query execution failed:" << query.lastError().text();
                return;
            }

            // Set the query result to the model
            modal->setQuery(query);

            // Set custom headers
            modal->setHeaderData(0, Qt::Horizontal, QObject::tr("Patient ID"));
            modal->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
            modal->setHeaderData(2, Qt::Horizontal, QObject::tr("Parameter Name"));
            modal->setHeaderData(3, Qt::Horizontal, QObject::tr("Date"));
            modal->setHeaderData(4, Qt::Horizontal, QObject::tr("Time"));

            // Assign the model to the table views
            ui->tableView_2->setModel(modal);
            ui->tableView_5->setModel(modal);

            // Resize columns to fit contents
            ui->tableView_2->resizeColumnsToContents();
            ui->tableView_5->resizeColumnsToContents();
        }

        ui->stackedWidget->setCurrentIndex(9);
    }
}


void MainWindow::on_pushButton_266_clicked()
{
    QString Serial = ui->label_44->text();
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(1);
    key->setData("Above-Normal Range",ui->A_Rang->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->A_Rang->setText(Data);
        QSqlQuery query;
        query.prepare("update Reports set ANrmlRang='"+Data+"' where sno='"+Serial+"'");
        if(query.exec())
        {
            qDebug()<<"Update done ";
        }
        ui->stackedWidget->setCurrentIndex(9);
    }
}

void MainWindow::on_pushButton_265_clicked()
{
    QString Serial = ui->label_44->text();
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(1);
    key->setData("Below-Normal Range",ui->B_Rang->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->B_Rang->setText(Data);
        QSqlQuery query;
        query.prepare("update Reports set BNrmlRang='"+Data+"' where sno='"+Serial+"'");
        if(query.exec())
        {
            qDebug()<<"Update done ";
        }
        ui->stackedWidget->setCurrentIndex(9);
    }
}


void MainWindow::on_pushButton_152_clicked()
{
    //Test Name

    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(0);
    key->getvalue(2);
    key->setData("Test Name",ui->lineEdit_14->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_14->setText(Data);
        QSqlQuery query;
        bool ok;
        QSqlQuery q;
        ok = q.exec("select * from test where name='"+Data+"'");
        if (ok && q.next())
        {
            msgboxtext="This parameter name was already exist.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,33});
            myTabWidgetsList.append({ ui->tabWidget_3, 0 });
            mypushButtonsList.append({ ui->pushButton_152, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_14, true }); // Add the specific line edit
            Call_Msg_box();
        }
    }
}

void MainWindow::on_pushButton_197_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(1);
    key->getvalue(2);
    key->setData("Test Code",ui->lineEdit_43->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec();
    QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_43->setText(Data);
        bool ok;
        QSqlQuery q;
        ok = q.exec("select * from test where Pro_Code='"+Data+"'");
        if (ok && q.next())
        {
            msgboxtext="Testcode : '"+Data+"' already exists, Kindly enter correct one.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,33});
            myTabWidgetsList.append({ ui->tabWidget_3, 0 });
            mypushButtonsList.append({ ui->pushButton_197, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_43, true }); // Add the specific line edit
            Call_Msg_box();

        }
    }
}

void MainWindow::on_pushButton_153_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(0);
    key->getvalue(2);
    key->setData("Unit",ui->lineEdit_21->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_21->setText(Data);
        ui->stackedWidget_3->setCurrentIndex(0);
        ui->stackedWidget->setCurrentIndex(33);
    }
}

void MainWindow::on_pushButton_156_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Factor",ui->lineEdit_22->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_22->setText(Data);
        ui->stackedWidget_3->setCurrentIndex(0);
        ui->stackedWidget->setCurrentIndex(33);
    }
}

void MainWindow::on_pushButton_155_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("R1+Sample",ui->lineEdit_25->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_25->setText(Data);
        ui->stackedWidget_3->setCurrentIndex(0);
        ui->stackedWidget->setCurrentIndex(33);
    }
}

void MainWindow::on_pushButton_154_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Linear Range(Min)",ui->lineEdit_31->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec();
    QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_31->setText(Data);
        ui->stackedWidget_3->setCurrentIndex(0);
        ui->stackedWidget->setCurrentIndex(33);
    }
}

void MainWindow::on_pushButton_157_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Linear Range(Max)",ui->lineEdit_32->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_32->setText(Data);
        ui->stackedWidget_3->setCurrentIndex(0);
        ui->stackedWidget->setCurrentIndex(33);
    }
}

void MainWindow::on_pushButton_158_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Normal Range(Male-Min)",ui->lineEdit_38->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_38->setText(Data);
        ui->stackedWidget_3->setCurrentIndex(0);
        ui->stackedWidget->setCurrentIndex(33);
    }
}

void MainWindow::on_pushButton_159_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Normal Range(Male-Max)",ui->lineEdit_37->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_37->setText(Data);
        ui->stackedWidget_3->setCurrentIndex(0);
        ui->stackedWidget->setCurrentIndex(33);
    }
}

void MainWindow::on_pushButton_280_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(2);
    key->getvalue(2);
    key->setData("LotNo",ui->lineEdit_154->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_154->setText(Data);
        ui->stackedWidget_3->setCurrentIndex(1);
        ui->stackedWidget->setCurrentIndex(33);
    }
}

void MainWindow::on_pushButton_223_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Concentration(1)",ui->lineEdit_99->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {

        QString Data = key->getData();
        ui->lineEdit_99->setText(Data);
        ui->stackedWidget_3->setCurrentIndex(1);
        ui->stackedWidget->setCurrentIndex(33);
    }
}

void MainWindow::on_pushButton_281_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Concentration(2)",ui->lineEdit_103->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {

        QString Data = key->getData();
        ui->lineEdit_103->setText(Data);
        ui->stackedWidget_3->setCurrentIndex(1);
        ui->stackedWidget->setCurrentIndex(33);
    }
}

void MainWindow::on_pushButton_246_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Concentration(3)",ui->lineEdit_100->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {

        QString Data = key->getData();
        ui->lineEdit_100->setText(Data);
        ui->stackedWidget_3->setCurrentIndex(1);
        ui->stackedWidget->setCurrentIndex(33);
    }
}

void MainWindow::on_pushButton_283_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Concentration(4)",ui->lineEdit_106->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {

        QString Data = key->getData();
        ui->lineEdit_106->setText(Data);
        ui->stackedWidget_3->setCurrentIndex(1);
        ui->stackedWidget->setCurrentIndex(33);
    }
}

void MainWindow::on_pushButton_225_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Concentration(5)",ui->lineEdit_101->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {

        QString Data = key->getData();
        ui->lineEdit_101->setText(Data);
        ui->stackedWidget_3->setCurrentIndex(1);
        ui->stackedWidget->setCurrentIndex(33);
    }
}

void MainWindow::on_pushButton_282_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Concentration(6)",ui->lineEdit_105->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {

        QString Data = key->getData();
        ui->lineEdit_105->setText(Data);
        ui->stackedWidget_3->setCurrentIndex(1);
        ui->stackedWidget->setCurrentIndex(33);
    }
}

void MainWindow::on_pushButton_243_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Concentration(7)",ui->lineEdit_102->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {

        QString Data = key->getData();
        ui->lineEdit_102->setText(Data);
        ui->stackedWidget_3->setCurrentIndex(1);
        ui->stackedWidget->setCurrentIndex(33);
    }
}

void MainWindow::on_pushButton_247_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Concentration(8)",ui->lineEdit_104->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {

        QString Data = key->getData();
        ui->lineEdit_104->setText(Data);
        ui->stackedWidget_3->setCurrentIndex(1);
        ui->stackedWidget->setCurrentIndex(33);
    }
}

void MainWindow::on_pushButton_162_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Control 1 - Minimum",ui->lineEdit_39->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_39->setText(Data);

        double val1 = ui->lineEdit_39->text().toInt();
        double val2 = ui->lineEdit_145->text().toInt();
        double Datas = val1+val2;
        double Divide = Datas / 2 ;
        if(Divide<100.0)
        {
            if(Divide<10.0)
                ui->label_461->setText(QString::number(Divide, 'f' , 2));
            else
                ui->label_461->setText(QString::number(Divide, 'f' , 1));
        }
        else if(Divide>100.0)
        {
            ui->label_461->setText(QString::number(Divide, 'f' , 0));
        }
        ui->stackedWidget_3->setCurrentIndex(2);
        ui->stackedWidget->setCurrentIndex(33);
    }
}

void MainWindow::on_pushButton_284_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Control 1 - Maximum",ui->lineEdit_145->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_145->setText(Data);

        double val1 = ui->lineEdit_39->text().toInt();
        double val2 = ui->lineEdit_145->text().toInt();
        double Datas = val1+val2;
        double Divide = Datas / 2 ;
        if(Divide<100.0)
        {
            if(Divide<10.0)
                ui->label_461->setText(QString::number(Divide, 'f' , 2));
            else
                ui->label_461->setText(QString::number(Divide, 'f' , 1));
        }
        else if(Divide>100.0)
        {
            ui->label_461->setText(QString::number(Divide, 'f' , 0));
        }
        ui->stackedWidget_3->setCurrentIndex(2);
        ui->stackedWidget->setCurrentIndex(33);
    }
}

void MainWindow::on_pushButton_165_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(2);
    key->getvalue(2);
    key->setData("Control1 - LotNo",ui->lineEdit_40->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_40->setText(Data);
        ui->stackedWidget_3->setCurrentIndex(2);
        ui->stackedWidget->setCurrentIndex(33);
    }
}

void MainWindow::on_pushButton_166_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Control 2 - Minimum",ui->lineEdit_41->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_41->setText(Data);

        double val1 = ui->lineEdit_41->text().toInt();
        double val2 = ui->lineEdit_146->text().toInt();
        double Datas = val1+val2;
        double Divide = Datas / 2 ;
        if(Divide<100.0)
        {
            if(Divide<10.0)
                ui->label_463->setText(QString::number(Divide, 'f' , 2));
            else
                ui->label_463->setText(QString::number(Divide, 'f' , 1));
        }
        else if(Divide>100.0)
        {
            ui->label_463->setText(QString::number(Divide, 'f' , 0));
        }
        ui->stackedWidget_3->setCurrentIndex(2);
        ui->stackedWidget->setCurrentIndex(33);
    }
}

void MainWindow::on_pushButton_285_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Control 2 - Maximum",ui->lineEdit_146->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_146->setText(Data);

        double val1 = ui->lineEdit_41->text().toInt();
        double val2 = ui->lineEdit_146->text().toInt();
        double Datas = val1+val2;
        double Divide = Datas / 2 ;
        if(Divide<100.0)
        {
            if(Divide<10.0)
                ui->label_463->setText(QString::number(Divide, 'f' , 2));
            else
                ui->label_463->setText(QString::number(Divide, 'f' , 1));
        }
        else if(Divide>100.0)
        {
            ui->label_463->setText(QString::number(Divide, 'f' , 0));
        }
        ui->stackedWidget_3->setCurrentIndex(2);
        ui->stackedWidget->setCurrentIndex(33);
    }
}

void MainWindow::on_pushButton_167_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(2);
    key->getvalue(2);
    key->setData("Control2 - LotNo",ui->lineEdit_44->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_44->setText(Data);
        ui->stackedWidget_3->setCurrentIndex(2);
        ui->stackedWidget->setCurrentIndex(33);
    }
}

void MainWindow::on_pushButton_171_clicked()
{
    //Unit
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(0);
    key->getvalue(2);
    key->setData("Unit",ui->lineEdit_47->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_47->setText(Data);
        ui->stackedWidget_5->setCurrentIndex(0);
        ui->stackedWidget->setCurrentIndex(34);
    }
}

void MainWindow::on_pushButton_198_clicked()
{
    //Factor
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Factor",ui->lineEdit_48->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_48->setText(Data);
        ui->stackedWidget_5->setCurrentIndex(0);
        ui->stackedWidget->setCurrentIndex(34);
    }
}

void MainWindow::on_pushButton_305_clicked()
{
    //Incubation
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("R1+Sample",ui->lineEdit_61->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_61->setText(Data);
        ui->stackedWidget_5->setCurrentIndex(0);
        ui->stackedWidget->setCurrentIndex(34);
    }
}

void MainWindow::on_pushButton_169_clicked()
{
    //Linear Min
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Linear Range(Min)",ui->lineEdit_53->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_53->setText(Data);
        ui->stackedWidget_5->setCurrentIndex(0);
        ui->stackedWidget->setCurrentIndex(34);
    }
}

void MainWindow::on_pushButton_168_clicked()
{
    //Linear Max
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Linear Range(Max)",ui->lineEdit_54->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_54->setText(Data);
        ui->stackedWidget_5->setCurrentIndex(0);
        ui->stackedWidget->setCurrentIndex(34);
    }
}

void MainWindow::on_pushButton_170_clicked()
{
    //Normal Min
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Normal Range(Male-Min)",ui->lineEdit_55->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_55->setText(Data);
        ui->stackedWidget_5->setCurrentIndex(0);
        ui->stackedWidget->setCurrentIndex(34);
    }
}

void MainWindow::on_pushButton_300_clicked()
{
    //Normal Max
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Normal Range(Male-Max)",ui->lineEdit_56->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_56->setText(Data);
        ui->stackedWidget_5->setCurrentIndex(0);
        ui->stackedWidget->setCurrentIndex(34);
    }
}

void MainWindow::on_pushButton_306_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(0);
    key->getvalue(2);
    key->setData("LotNo",ui->lineEdit_155->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_155->setText(Data);
        ui->stackedWidget_5->setCurrentIndex(1);
        ui->stackedWidget->setCurrentIndex(34);
    }
}

void MainWindow::on_pushButton_307_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Concentration(1)",ui->lineEdit_120->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {

        QString Data = key->getData();
        ui->lineEdit_120->setText(Data);
        ui->stackedWidget_5->setCurrentIndex(1);
        ui->stackedWidget->setCurrentIndex(34);
    }
}

void MainWindow::on_pushButton_313_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Concentration(2)",ui->lineEdit_124->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {

        QString Data = key->getData();
        ui->lineEdit_124->setText(Data);
        ui->stackedWidget_5->setCurrentIndex(1);
        ui->stackedWidget->setCurrentIndex(34);
    }
}

void MainWindow::on_pushButton_311_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Concentration(3)",ui->lineEdit_121->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {

        QString Data = key->getData();
        ui->lineEdit_121->setText(Data);
        ui->stackedWidget_5->setCurrentIndex(1);
        ui->stackedWidget->setCurrentIndex(34);
    }
}

void MainWindow::on_pushButton_317_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Concentration(4)",ui->lineEdit_127->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {

        QString Data = key->getData();
        ui->lineEdit_127->setText(Data);
        ui->stackedWidget_5->setCurrentIndex(1);
        ui->stackedWidget->setCurrentIndex(34);
    }
}

void MainWindow::on_pushButton_308_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Concentration(5)",ui->lineEdit_122->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {

        QString Data = key->getData();
        ui->lineEdit_122->setText(Data);
        ui->stackedWidget_5->setCurrentIndex(1);
        ui->stackedWidget->setCurrentIndex(34);
    }
}

void MainWindow::on_pushButton_314_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Concentration(6)",ui->lineEdit_126->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {

        QString Data = key->getData();
        ui->lineEdit_126->setText(Data);
        ui->stackedWidget_5->setCurrentIndex(1);
        ui->stackedWidget->setCurrentIndex(34);
    }
}

void MainWindow::on_pushButton_310_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Concentration(7)",ui->lineEdit_123->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {

        QString Data = key->getData();
        ui->lineEdit_123->setText(Data);
        ui->stackedWidget_5->setCurrentIndex(1);
        ui->stackedWidget->setCurrentIndex(34);
    }
}

void MainWindow::on_pushButton_312_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Concentration(8)",ui->lineEdit_125->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {

        QString Data = key->getData();
        ui->lineEdit_125->setText(Data);
        ui->stackedWidget_5->setCurrentIndex(1);
        ui->stackedWidget->setCurrentIndex(34);
    }
}

void MainWindow::on_pushButton_199_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Control 1 - Minimum",ui->lineEdit_64->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_64->setText(Data);

        double val1 = ui->lineEdit_64->text().toInt();
        double val2 = ui->lineEdit_151->text().toInt();
        double Datas = val1+val2;
        double Divide = Datas / 2 ;
        if(Divide<100.0)
        {
            if(Divide<10.0)
                ui->label_505->setText(QString::number(Divide, 'f' , 2));
            else
                ui->label_505->setText(QString::number(Divide, 'f' , 1));
        }
        else if(Divide>100.0)
        {
            ui->label_505->setText(QString::number(Divide, 'f' , 0));
        }
        qDebug()<<"Divide : "<<Divide<<Data;
        ui->stackedWidget_5->setCurrentIndex(2);
        ui->stackedWidget->setCurrentIndex(34);
    }
}

void MainWindow::on_pushButton_319_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Control 1 - Maximum",ui->lineEdit_151->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_151->setText(Data);

        double val1 = ui->lineEdit_64->text().toInt();
        double val2 = ui->lineEdit_151->text().toInt();
        double Datas = val1+val2;
        double Divide = Datas / 2 ;
        if(Divide<100.0)
        {
            if(Divide<10.0)
                ui->label_505->setText(QString::number(Divide, 'f' , 2));
            else
                ui->label_505->setText(QString::number(Divide, 'f' , 1));
        }
        else if(Divide>100.0)
        {
            ui->label_505->setText(QString::number(Divide, 'f' , 0));
        }
        qDebug()<<"Divide : "<<Divide<<Data;
        ui->stackedWidget_5->setCurrentIndex(2);
        ui->stackedWidget->setCurrentIndex(34);
    }
}

void MainWindow::on_pushButton_318_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Control 1 - LotNo",ui->lineEdit_65->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_65->setText(Data);
        ui->stackedWidget_5->setCurrentIndex(2);
        ui->stackedWidget->setCurrentIndex(34);
    }
}

void MainWindow::on_pushButton_320_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Control 2 - Minimum",ui->lineEdit_66->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_66->setText(Data);

        double val1 = ui->lineEdit_66->text().toInt();
        double val2 = ui->lineEdit_156->text().toInt();
        double Datas = val1+val2;
        double Divide = Datas / 2 ;
        if(Divide<100.0)
        {
            if(Divide<10.0)
                ui->label_510->setText(QString::number(Divide, 'f' , 2));
            else
                ui->label_510->setText(QString::number(Divide, 'f' , 1));
        }
        else if(Divide>100.0)
        {
            ui->label_510->setText(QString::number(Divide, 'f' , 0));
        }
        qDebug()<<"Divide : "<<Divide<<Data;
        ui->stackedWidget_5->setCurrentIndex(2);
        ui->stackedWidget->setCurrentIndex(34);
    }
}

void MainWindow::on_pushButton_323_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Control 2 - Maximum",ui->lineEdit_156->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_156->setText(Data);

        double val1 = ui->lineEdit_64->text().toInt();
        double val2 = ui->lineEdit_151->text().toInt();
        double Datas = val1+val2;
        double Divide = Datas / 2 ;
        if(Divide<100.0)
        {
            if(Divide<10.0)
                ui->label_505->setText(QString::number(Divide, 'f' , 2));
            else
                ui->label_505->setText(QString::number(Divide, 'f' , 1));
        }
        else if(Divide>100.0)
        {
            ui->label_505->setText(QString::number(Divide, 'f' , 0));
        }
        qDebug()<<"Divide : "<<Divide<<Data;
        ui->stackedWidget_5->setCurrentIndex(2);
        ui->stackedWidget->setCurrentIndex(34);
    }
}

void MainWindow::on_pushButton_322_clicked()
{
    Virtual_Keyboard *key=new Virtual_Keyboard(this);
    key->setModal(true);
    key->setPage(3);
    key->getvalue(2);
    key->setData("Control 2 - LotNo",ui->lineEdit_98->text());
    key->setGeometry(virtual_x, virtual_y, keyboardWidth, keyboardHeight);
    key->exec(); QString returndata = key->ReturnData();
    if(returndata == "1")
        qDebug()<<"back";
    else
    {
        QString Data = key->getData();
        ui->lineEdit_98->setText(Data);
        ui->stackedWidget_5->setCurrentIndex(2);
        ui->stackedWidget->setCurrentIndex(34);
    }
}
