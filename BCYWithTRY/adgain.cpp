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

void MainWindow::on_toolButton_20_clicked()
{
    ui->pushButton_148->setVisible(false);
    ui->stackedWidget->setCurrentIndex(10);
}

void MainWindow::on_pushButton_8_clicked()
{
    Run_Data=1;
    Wave_LED_340();
    ui->pushButton_8->setDisabled(true);
    QSqlQuery query;
    QString wavelength , intensity,Blankval,serialno="1";
    query.exec("BEGIN TRANSACTION;");
    query.prepare("select intensity,wave from tests where sno=:sno");
    query.bindValue(":sno",serialno);
    if(!query.exec())
    {
        qDebug()<<"Query Error : "<<query.lastError().text();
        query.exec("ROLLBACK;");
    }
    else if(query.next())
    {
        intensity=query.value(0).toString();
        wavelength=query.value(1).toString();
    }
    else
    {
        qDebug()<<"No record found for Testname : "<<TestName;
    }

    read_intensity = intensity.toInt();
    if(wavelength=="340 nm")
    {
        read_wave=7;
        read_wavenm=0;
    }
    filtwave[0]=reading1();
    ui->label_114->setNum(filtwave[0]);
    w340=filtwave[0];
    Blankval = ui->label_114->text();
    if(Autocal_click==1)
        qDebug()<<"Autocal_w340 : "<<w340;
    else
    {
        query.prepare("UPDATE tests SET blankval = :blankval WHERE sno = :sno");
        query.bindValue(":blankval",Blankval);
        query.bindValue(":sno",serialno);
        if(!query.exec())
        {
            qDebug()<<"Query Error : "<<query.lastError().text();
            query.exec("ROLLBACK;");
        }
        else if(query.next())
        {
            qDebug()<<"Wave340: "<<w340;
        }
        else
        {
            qDebug()<<"No record found for Testname : "<<TestName<<w340;
        }
    }
    // Commit the transaction if all queries succeed
    query.exec("COMMIT;");
    ui->pushButton_8->setEnabled(true);
    Wave_LED_OFF();
}

void MainWindow::on_pushButton_9_clicked()
{
    Run_Data=1;
    Wave_LED_405();
    ui->pushButton_9->setDisabled(true);
    QSqlQuery query;
    QString wavelength , intensity,Blankval,serialno="2";
    query.exec("BEGIN TRANSACTION;");
    query.prepare("select intensity,wave from tests where sno=:sno");
    query.bindValue(":sno",serialno);
    if(!query.exec())
    {
        qDebug()<<"Query Error : "<<query.lastError().text();
        query.exec("ROLLBACK;");
    }
    else if(query.next())
    {
        intensity=query.value(0).toString();
        wavelength=query.value(1).toString();
    }
    else
    {
        qDebug()<<"No record found for Testname : "<<TestName;
    }

    read_intensity = intensity.toInt();
    if(wavelength=="405 nm")
    {
        read_wave=6;
        read_wavenm=1;
    }
    filtwave[0]=reading1();
    ui->label_115->setNum(filtwave[0]);
    w405=filtwave[0];
    Blankval = ui->label_115->text();
    if(Autocal_click==1)
        qDebug()<<"Autocal_w405 : "<<w405;
    else
    {
        query.prepare("UPDATE tests SET blankval = :blankval WHERE sno = :sno");
        query.bindValue(":blankval",Blankval);
        query.bindValue(":sno",serialno);
        if(!query.exec())
        {
            qDebug()<<"Query Error : "<<query.lastError().text();
            query.exec("ROLLBACK;");
        }
        else if(query.next())
        {
            qDebug()<<"Wave405: "<<w405;

        }
        else
        {
            qDebug()<<"No record found for Testname : "<<TestName<<w405;
        }
    }
    // Commit the transaction if all queries succeed
    query.exec("COMMIT;");
    ui->pushButton_9->setEnabled(true);
    Wave_LED_OFF();
}

void MainWindow::on_pushButton_24_clicked()
{
    Run_Data=1;
    Wave_LED_505();
    ui->pushButton_24->setDisabled(true);
    QSqlQuery query;
    QString wavelength , intensity,Blankval,serialno="3";
    query.exec("BEGIN TRANSACTION;");
    query.prepare("select intensity,wave from tests where sno=:sno");
    query.bindValue(":sno",serialno);
    if(!query.exec())
    {
        qDebug()<<"Query Error : "<<query.lastError().text();
        query.exec("ROLLBACK;");
    }
    else if(query.next())
    {
        intensity=query.value(0).toString();
        wavelength=query.value(1).toString();
    }
    else
    {
        qDebug()<<"No record found for Testname : "<<TestName;
    }

    read_intensity = intensity.toInt();
    if(wavelength=="505 nm")
    {
        read_wave=5;
        read_wavenm=2;
    }
    filtwave[0]=reading1();
    ui->label_117->setNum(filtwave[0]);
    w505=filtwave[0];
    Blankval = ui->label_117->text();
    if(Autocal_click==1)
        qDebug()<<"Autocal_w505 : "<<w505;
    else
    {
        query.prepare("UPDATE tests SET blankval = :blankval WHERE sno = :sno");
        query.bindValue(":blankval",Blankval);
        query.bindValue(":sno",serialno);
        if(!query.exec())
        {
            qDebug()<<"Query Error : "<<query.lastError().text();
            query.exec("ROLLBACK;");
        }
        else if(query.next())
        {
            qDebug()<<"Wave505: "<<w505;

        }
        else
        {
            qDebug()<<"No record found for Testname : "<<TestName<<w505;
        }
    }
    // Commit the transaction if all queries succeed
    query.exec("COMMIT;");
    ui->pushButton_24->setEnabled(true);
    Wave_LED_OFF();

}

void MainWindow::on_pushButton_26_clicked()
{
    Run_Data=1;
    Wave_LED_545();
    ui->pushButton_26->setDisabled(true);
    QSqlQuery query;
    QString wavelength , intensity,Blankval,serialno="4";
    query.exec("BEGIN TRANSACTION;");
    query.prepare("select intensity,wave from tests where sno=:sno");
    query.bindValue(":sno",serialno);
    if(!query.exec())
    {
        qDebug()<<"Query Error : "<<query.lastError().text();
        query.exec("ROLLBACK;");
    }
    else if(query.next())
    {
        intensity=query.value(0).toString();
        wavelength=query.value(1).toString();
    }
    else
    {
        qDebug()<<"No record found for Testname : "<<TestName;
    }

    read_intensity = intensity.toInt();
    if(wavelength=="545 nm")
    {
        read_wave=4;
        read_wavenm=3;
    }
    filtwave[0]=reading1();
    ui->label_118->setNum(filtwave[0]);
    w545=filtwave[0];
    Blankval = ui->label_118->text();
    if(Autocal_click==1)
        qDebug()<<"Autocal_w545 : "<<w545;
    else
    {
        query.prepare("UPDATE tests SET blankval = :blankval WHERE sno = :sno");
        query.bindValue(":blankval",Blankval);
        query.bindValue(":sno",serialno);
        if(!query.exec())
        {
            qDebug()<<"Query Error : "<<query.lastError().text();
            query.exec("ROLLBACK;");
        }
        else if(query.next())
        {
            qDebug()<<"Wave545: "<<w545;

        }
        else
        {
            qDebug()<<"No record found for Testname : "<<TestName<<w545;
        }
    }
    // Commit the transaction if all queries succeed
    query.exec("COMMIT;");
    ui->pushButton_26->setEnabled(true);
    Wave_LED_OFF();

}

void MainWindow::on_pushButton_128_clicked()
{
    Run_Data=1;
    Wave_LED_570();
    ui->pushButton_128->setEnabled(false);
    QSqlQuery query;
    QString wavelength , intensity,Blankval,serialno="5";
    query.exec("BEGIN TRANSACTION;");
    query.prepare("select intensity,wave from tests where sno=:sno");
    query.bindValue(":sno",serialno);
    if(!query.exec())
    {
        qDebug()<<"Query Error : "<<query.lastError().text();
        query.exec("ROLLBACK;");
    }
    else if(query.next())
    {
        intensity=query.value(0).toString();
        wavelength=query.value(1).toString();
    }
    else
    {
        qDebug()<<"No record found for Testname : "<<TestName;
    }

    read_intensity = intensity.toInt();
    if(wavelength=="570 nm")
    {
        read_wave=3;
        read_wavenm=4;
    }
    filtwave[0]=reading1();
    ui->label_124->setNum(filtwave[0]);
    w570=filtwave[0];
    Blankval = ui->label_124->text();
    if(Autocal_click==1)
        qDebug()<<"Autocal_w570 : "<<w570;
    else
    {
        query.prepare("UPDATE tests SET blankval = :blankval WHERE sno = :sno");
        query.bindValue(":blankval",Blankval);
        query.bindValue(":sno",serialno);
        if(!query.exec())
        {
            qDebug()<<"Query Error : "<<query.lastError().text();
            query.exec("ROLLBACK;");
        }
        else if(query.next())
        {
            qDebug()<<"Wave570: "<<w570;

        }
        else
        {
            qDebug()<<"No record found for Testname : "<<TestName<<w570;
        }
    }
    // Commit the transaction if all queries succeed
    query.exec("COMMIT;");
    ui->pushButton_128->setEnabled(true);
    Wave_LED_OFF();
}

void MainWindow::on_pushButton_129_clicked()
{
    Run_Data=1;
    Wave_LED_630();
    ui->pushButton_129->setEnabled(false);
    QSqlQuery query;
    QString wavelength , intensity,Blankval,serialno="6";
    query.exec("BEGIN TRANSACTION;");
    query.prepare("select intensity,wave from tests where sno=:sno");
    query.bindValue(":sno",serialno);
    if(!query.exec())
    {
        qDebug()<<"Query Error : "<<query.lastError().text();
        query.exec("ROLLBACK;");
    }
    else if(query.next())
    {
        intensity=query.value(0).toString();
        wavelength=query.value(1).toString();
    }
    else
    {
        qDebug()<<"No record found for Testname : "<<TestName;
    }

    read_intensity = intensity.toInt();
    if(wavelength=="630 nm")
    {
        read_wave=2;
        read_wavenm=5;
    }
    filtwave[0]=reading1();
    ui->label_126->setNum(filtwave[0]);
    w630=filtwave[0];

    Blankval = ui->label_126->text();
    if(Autocal_click==1)
        qDebug()<<"Autocal_w630 : "<<w630;
    else
    {
        query.prepare("UPDATE tests SET blankval = :blankval WHERE sno = :sno");
        query.bindValue(":blankval",Blankval);
        query.bindValue(":sno",serialno);
        if(!query.exec())
        {
            qDebug()<<"Query Error : "<<query.lastError().text();
            query.exec("ROLLBACK;");
        }
        else if(query.next())
        {
            qDebug()<<"Wave630: "<<w630;

        }
        else
        {
            qDebug()<<"No record found for Testname : "<<TestName<<w630;
        }
    }
    // Commit the transaction if all queries succeed
    query.exec("COMMIT;");
    ui->pushButton_129->setEnabled(true);
    Wave_LED_OFF();

}

void MainWindow::on_pushButton_130_clicked()
{
    Run_Data=1;
    Wave_LED_700();
    ui->pushButton_130->setEnabled(false);
    QSqlQuery query;
    QString wavelength , intensity,Blankval,serialno="7";
    query.exec("BEGIN TRANSACTION;");
    query.prepare("select intensity,wave from tests where sno=:sno");
    query.bindValue(":sno",serialno);
    if(!query.exec())
    {
        qDebug()<<"Query Error : "<<query.lastError().text();
        query.exec("ROLLBACK;");
    }
    else if(query.next())
    {
        intensity=query.value(0).toString();
        wavelength=query.value(1).toString();
    }
    else
    {
        qDebug()<<"No record found for Testname : "<<TestName;
    }

    read_intensity = intensity.toInt();
    if(wavelength=="700 nm")
    {
        read_wave=0;
        read_wavenm=6;
    }
    filtwave[0]=reading1();
    ui->label_183->setNum(filtwave[0]);
    w700=filtwave[0];
    Blankval = ui->label_183->text();
    if(Autocal_click==1)
        qDebug()<<"Autocal_w700 : "<<w700;
    else
    {
        query.prepare("UPDATE tests SET blankval = :blankval WHERE sno = :sno");
        query.bindValue(":blankval",Blankval);
        query.bindValue(":sno",serialno);
        if(!query.exec())
        {
            qDebug()<<"Query Error : "<<query.lastError().text();
            query.exec("ROLLBACK;");
        }
        else if(query.next())
        {
            qDebug()<<"Wave700: "<<w700;

        }
        else
        {
            qDebug()<<"No record found for Testname : "<<TestName<<w700;
        }
    }
    // Commit the transaction if all queries succeed
    query.exec("COMMIT;");
    ui->pushButton_130->setEnabled(true);
    Wave_LED_OFF();
}
