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
static QString array[100]={""};

void MainWindow::EndQC1_Func()
{
    QList<int> list1;
    QList<int> list2;
    QList<int> list3;
    QList<QString> Datee;
    QList<QString> Curr_Date;
    QString Date;
    Dateee = ui->SysDate_Lbl->text();
    Curr_Date.append(ui->SysDate_Lbl->text());
    QSqlQuery qqq;
    qqq.prepare("select ctrl1bno from test where name='"+TestName+"'");
    qqq.exec();
    while(qqq.next())
    {
        LottNo.append(qqq.value(0).toString());
        LNo=qqq.value(0).toString();
    }
    qDebug()<<"LottNo : "<<LottNo<<LNo;
    QC1_loop();

    QSqlQuery qry;
    qry.prepare("select * from "+QC1_Testname+" where Tname='"+TestName+"'");
    qry.exec();
    while(qry.next())
    {
        list3.append(qry.value(12).toInt());
        list2.append(qry.value(11).toInt());
        dat.append(qry.value(8).toString());
        LotNumber.append(qry.value(13).toString());
    }
    qDebug()<<"ENter";
    if(dat.isEmpty())
    {
        qDebug()<<"Date is empty";
        dat.append(Curr_Date);
    }
    QList<int> list4;
    QSqlQuery qury;
    qury.prepare("select * from "+QC1_Testname+" where Date='"+Dateee+"'");
    qury.exec();
    while(qury.next())
    {
        Datee.append(qury.value(8).toString());
        list1.append(qury.value(10).toInt());
    }
    qDebug()<<"while after ENter1";
    if(LotNumber.isEmpty())
    {
        qDebug()<<"lotnumber is empty";
        LotNumber.append(LNo);
    }
    qDebug()<<"LotNumber : "<<LotNumber;

    if(dat.last().toStdString() == Curr_Date.last().toStdString())
    {
        qDebug()<<"date Enter : ";
        qDebug()<<"Lotnumber : "<<LotNumber<<LottNo;
        if(LotNumber.last()==LottNo.last())
        {
            qDebug()<<"Lotnumber match";
            if(list3.isEmpty())
            {
                Dateee=ui->SysDate_Lbl->text();
                list1.append(10);
                mainval1= QString::number(list1.last());
                list2.append(10);
                mainval2= QString::number(list2.last());
                list3.append(10);
                mainval3= QString::number(list3.last());
                qDebug()<<"List3 is empty"<<list1<<list2<<list3;
            }
            else
            {
                qDebug()<<"List3 not empty";
                Dateee=ui->SysDate_Lbl->text();
                double xx1 = list1.last()+10;
                mainval1= QString::number(xx1);
                double xx2 = list2.last()+10;
                mainval2= QString::number(xx2);
                double xx3 = list3.last()+10;
                mainval3= QString::number(xx3);
                qDebug()<<"List3 is not empty"<<mainval1<<mainval2<<mainval3;
            }
            Call_End_QCData_Func();
        }
        else
        {
            qDebug()<<"Lotnumber not match";
            Dateee=ui->SysDate_Lbl->text();
            double xx1 = list1.last()+10;
            mainval1= QString::number(xx1);
            double xx2 = list2.last()+10;
            mainval2= QString::number(xx2);
            list3.append(10);
            mainval3= QString::number(list3.last());
            qDebug()<<"Lotnumber not match"<<mainval1<<mainval2<<mainval3;
            Call_End_QCData_Func();
        }

    }
    else if(dat.last().toStdString() != Curr_Date.last().toStdString())
    {
        qDebug()<<"Date not match";
        if(LotNumber.last()==LottNo.last())
        {
            qDebug()<<"Lotnumber match";
            if(list3.isEmpty())
            {

                Dateee=ui->SysDate_Lbl->text();
                list1.append(10);
                mainval1= QString::number(list1.last());
                list2.append(10);
                mainval2= QString::number(list2.last());
                list3.append(10);
                mainval3= QString::number(list3.last());
                qDebug()<<"List3 is empty"<<mainval1<<mainval2<<mainval3;
            }
            else
            {
                Dateee=ui->SysDate_Lbl->text();
                list1.append(10);
                mainval1= QString::number(list1.last());
                list2.append(10);
                mainval2= QString::number(list2.last());
                double xx3 = list3.last()+10;
                mainval3= QString::number(xx3);
                qDebug()<<"List3 is not empty"<<mainval1<<mainval2<<mainval3;
            }
            Call_End_QCData_Func();
        }
        else
        {
            Dateee=ui->SysDate_Lbl->text();
            list1.append(10);
            mainval1= QString::number(list1.last());
            list2.append(10);
            mainval2= QString::number(list2.last());
            list3.append(10);
            mainval3= QString::number(list3.last());
            qDebug()<<"Lotno not match "<<mainval1<<mainval2<<mainval3;
            Call_End_QCData_Func();
        }
    }
    else
    {
        qDebug()<<"Else part";
        double xx1 = list1.last()+10;
        mainval1= QString::number(xx1);
        double xx2 = list2.last()+10;
        mainval2= QString::number(xx2);
        double xx3 = list3.last()+10;
        mainval3= QString::number(xx3);
        Call_End_QCData_Func_Else();
    }
}
void MainWindow::Call_End_QCData_Func()
{
    qDebug()<<"Mainval1 empty : "<<mainval1;
    QString Data;
    QSqlQuery qry;
    if(QC1_Testname=="Potassium_QC1")
        Data="Proname";
    else
        Data="Procode";
    qry.prepare("insert into "+QC1_Testname+"(Tname,"+Data+",QC1Conc,QC1OD,Unit,QCMin,QCMax,Date,Time, xval1,xval2,xval3,LotNo) values(?,?,?,?,?,?,?,?,?,?,?,?,?)");
    qry.addBindValue(TestName);
    qry.addBindValue(Prod_Code);
    qry.addBindValue(QC1Conc);
    qry.addBindValue(QC1OD);
    qry.addBindValue(Unit);
    qry.addBindValue(QCMin);
    qry.addBindValue(QCMax);
    qry.addBindValue(Dateee);
    qry.addBindValue(Timeee);
    qry.addBindValue(mainval1);
    qry.addBindValue(mainval2);
    qry.addBindValue(mainval3);
    qry.addBindValue(LotNo);
    qry.exec();
    QList<double> listt;
    QList<double> lit;
    QSqlQuery quury;
    quury.prepare("select * from "+QC1_Testname+" where Date='"+Dateee+"'");
    quury.exec();
    while(quury.next())
    {
        listt.append(quury.value(10).toInt());
        lit.append(quury.value(3).toInt());
    }
    qDebug()<<"list : "<<listt;
    qDebug()<<"lit : "<<lit;
    QStringList strings;
    strings.reserve(listt.size());
    double vl = listt.size();
    double vlm = lit.size();
    addPoints(vl,vlm);
    QThread::msleep(10);
    endqcselect();
}

void MainWindow::Call_End_QCData_Func_Else()
{ 
    qDebug()<<"Else Part2";
    Dateee=ui->SysDate_Lbl->text();
    QString Data;
    QSqlQuery qry;
    if(QC1_Testname=="Potassium_QC1")
        Data="Proname";
    else
        Data="Procode";
    qry.prepare("insert into "+QC1_Testname+"(Tname,"+Data+",QC1Conc,QC1OD,Unit,QCMin,QCMax,Date,Time, xval1,xval2,xval3,LotNo) values(?,?,?,?,?,?,?,?,?,?,?,?,?)");
    qry.addBindValue(TestName);
    qry.addBindValue(Prod_Code);
    qry.addBindValue(QC1Conc);
    qry.addBindValue(QC1OD);
    qry.addBindValue(Unit);
    qry.addBindValue(QCMin);
    qry.addBindValue(QCMax);
    qry.addBindValue(Dateee);
    qry.addBindValue(Timeee);
    qry.addBindValue(mainval1);
    qry.addBindValue(mainval2);
    qry.addBindValue(mainval3);
    qry.addBindValue(LotNo);
    qry.exec();

    QThread::msleep(10);

    QList<int> listt1;
    QList<int> listt2;
    QList<int> listt3;
    QList<int> listt4;
    QString xxval1 , xxval2 , xxval3;
    QString conc;
    QSqlQuery qyy;
    qyy.prepare("select * from "+QC1_Testname+" where Tname='"+TestName+"'");
    qyy.exec();
    while(qyy.next())
    {
        listt4.append(qyy.value(12).toInt());
    }
    QSqlQuery qy;
    qy.prepare("select * from "+QC1_Testname+" where Date='"+Dateee+"'");
    qy.exec();
    while(qy.next())
    {
        listt1.append(qy.value(3).toInt());
        listt2.append(qy.value(10).toInt());
        listt3.append(qy.value(11).toInt());
    }
    if(listt2.isEmpty())
    {
        QByteArray arr = dat.last().toLocal8Bit();
        QString Month1 , Month2, TotalMonth;
        Month1=arr[7];
        Month2=arr[8];
        TotalMonth=Month1+Month2;
        QByteArray arr1 = ui->SysDate_Lbl->text().toLocal8Bit();
        QString CMonth1 , CMonth2,CurrentMonth;
        CMonth1 = arr1[7];
        CMonth2 = arr1[8];
        CurrentMonth = CMonth1+CMonth2;
        qDebug()<<"else part TotalMOnth : "<<TotalMonth <<"Currnt_Month : "<<CurrentMonth;

        if(TotalMonth==CurrentMonth)
        {
            if(listt3.isEmpty())
            {
                listt2.append(10);
                xxval1=QString::number(listt2.last());
                listt3.append(10);
                xxval2=QString::number(listt3.last());
                listt4.append(10);
                xxval3=QString::number(listt4.last());
            }
            else
            {
                qDebug()<<"List is Emptyyyyyy";
                listt2.append(10);
                xxval1=QString::number(listt2.last());
                xxval2=QString::number(listt3.last()+10);
                xxval3=QString::number(listt4.last()+10);
            }
        }
        else
        {
            listt2.append(10);
            xxval1=QString::number(listt2.last());
            listt3.append(10);
            xxval2=QString::number(listt3.last());
            listt4.append(10);
            xxval3= QString::number(listt4.last());
        }

        QSqlQuery q;
        q.prepare("update "+QC1_Testname+" set xval1='"+xxval1+"' , xval2='"+xxval2+"', xval3='"+xxval3+"' where Date = '"+Dateee+"'");
        q.exec();
        while(q.next())
        {
            qDebug()<<"Update Done"<<xxval1;
        }
    }
    else
    {
        QByteArray arr = dat.last().toLocal8Bit();
        QString Month1 , Month2, TotalMonth;
        Month1=arr[7];
        Month2=arr[8];
        TotalMonth=Month1+Month2;
        QByteArray arr1 = ui->SysDate_Lbl->text().toLocal8Bit();
        QString CMonth1 , CMonth2,CurrentMonth;
        CMonth1 = arr1[7];
        CMonth2 = arr1[8];
        CurrentMonth = CMonth1+CMonth2;
        qDebug()<<"else part TotalMOnth : "<<TotalMonth <<"Currnt_Month : "<<CurrentMonth;

        if(TotalMonth==CurrentMonth)
        {
            qDebug()<<"Query else part..";
            double xx1= listt2.last()+10;
            double xx2= listt3.last()+10;
            double xx3= listt4.last()+10;
            xxval1=QString::number(xx1);
            xxval2=QString::number(xx2);
            xxval3=QString::number(xx3);
            qDebug()<<"List (10) :"<<listt2;
            qDebug()<<"List (11) :"<<listt3;
        }
        else
        {
            listt2.append(10);
            listt3.append(10);
            listt4.append(10);
            qDebug()<<"Query else part..";
            double xx1= listt2.last();
            double xx2= listt3.last();
            double xx3= listt4.last();
            xxval1=QString::number(xx1);
            xxval2=QString::number(xx2);
            xxval3=QString::number(xx3);
            qDebug()<<"List (10) :"<<listt2;
            qDebug()<<"List (11) :"<<listt3;
        }

        QSqlQuery q;
        q.prepare("update "+QC1_Testname+" set xval1='"+xxval1+"' , xval2='"+xxval2+"', xval3='"+xxval3+"' where Date = '"+Dateee+"'");
        q.exec();
        while(q.next())
        {
            qDebug()<<"Update Done"<<xxval1<<xxval2;
        }
    }
    QList<double> listt;
    QList<double> lit;
    QSqlQuery quury;
    quury.prepare("select * from "+QC1_Testname+" where Date='"+Dateee+"'");
    quury.exec();
    while(quury.next())
    {
        listt.append(quury.value(10).toInt());
        lit.append(quury.value(3).toInt());
    }
    qDebug()<<"listt"<<listt;
    qDebug()<<"lit"<<lit;
    QStringList strings;
    strings.reserve(listt.size());
    double vl = listt.size();
    double vlm = lit.size();
    // incv=xval;
    qDebug()<<"vl"<<vl;
    qDebug()<<"vlm"<<vlm;
    addPoints(vl,vlm);
    QThread::msleep(10);
    endqcselect();
    qDebug()<<vlm<<"QC1"<<vl<<"X"<<"this is 1st QC";
}
