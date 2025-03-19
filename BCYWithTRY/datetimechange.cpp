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
int datetimeset=0;

void MainWindow::on_pushButton_226_clicked()
{
    if(datetimeset==2)
    {
        QMessageBox msg(this);
        msg.setWindowFlags(Qt::Popup);
        msg.setStyleSheet("background-color:#a0cdfa;font: 75 20pt Liberation Serif ;");
        msg.setText("Date & time set successfully.");
        QPixmap p("/home/pi/git/BCYWithTRY/BCYWithTRY/img/check-mark.png");
        auto newPixmap = p.scaled(45, 45);
        msg.setIconPixmap(newPixmap);
        QPushButton* saveButton = msg.addButton("Ok", QMessageBox::AcceptRole);
        saveButton->setStyleSheet("background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 #34ba91, stop: 0.5 #34ba91, stop: 1 #34ba91);color:black;}QPushButton:pressed {background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(0, 85, 0), stop: 0.5 rgb(0, 85, 0), stop: 1 rgb(0, 85, 0));color:white;}");
        msg.setDefaultButton(saveButton);
        msg.exec();
        if (msg.clickedButton() == saveButton)
        {
            ui->Home_Btn_12->setVisible(true);
            ui->Home_Btn_17->setVisible(false);
            int Index = ui->timeZoneComboBox_2->currentIndex();
            QString Data;
            QSqlQuery qry;
            QSqlQuery qy;
            qy.prepare("select ZoneIndex from TimeZone where sno=1");
            qy.exec();
            while(qy.next())
                Data=qy.value(0).toString();
            QString Indexval = QString::number(Index);
            QSqlQuery query;
            query.prepare("update TimeZone set ZoneIndex='"+Indexval+"' where sno=1");
            if(query.exec())
                qDebug()<<"Update Done";
            else
                qDebug()<<"Update Error";

            QThread::msleep(500);

            QDate date = QDate::currentDate();
            QString datetext= date.toString("yyyy / MM / dd");
            ui->SysDate_Lbl->setText(datetext);

            QTime time = QTime::currentTime();
            QString time_text = time.toString("hh : mm : ss");
            ui->SysTime_Lbl->setText(time_text);
            ui->stackedWidget_4->setCurrentIndex(0);
            ui->stackedWidget->setCurrentIndex(20);
        }
        else
        {
            ui->stackedWidget_4->setCurrentIndex(0);
            ui->stackedWidget->setCurrentIndex(20);
        }
    }
}

void MainWindow::on_timeZoneComboBox_2_currentTextChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
    QString Zones = ui->timeZoneComboBox_2->currentText();
    QString timeZone;

    if (Zones == "(UTC+02:00) Amman")
        timeZone = "Asia/Amman";
    else if (Zones == "(UTC+02:00) Beirut")
        timeZone = "Asia/Beirut";
    else if (Zones == "(UTC+02:00) Damascus")
        timeZone = "Asia/Damascus";
    else if (Zones == "(UTC+02:00) Gaza, Hebron")
        timeZone = "Asia/Gaza";
    else if (Zones == "(UTC+02:00) Jerusalem")
        timeZone = "Asia/Jerusalem";
    else if (Zones == "(UTC+03:00) Baghdad")
        timeZone = "Asia/Baghdad";
    else if (Zones == "(UTC+03:00) Kuwait, Riyadh")
        timeZone = "Asia/Riyadh";
    else if (Zones == "(UTC+03:30) Tehran")
        timeZone = "Asia/Tehran";
    else if (Zones == "(UTC+04:00) Baku")
        timeZone = "Asia/Baku";
    else if (Zones == "(UTC+04:00) Abu Dhabi, Muscat")
        timeZone = "Asia/Dubai";
    else if (Zones == "(UTC+04:00) Tbilisi")
        timeZone = "Asia/Tbilisi";
    else if (Zones == "(UTC+04:00) Yerevan")
        timeZone = "Asia/Yerevan";
    else if (Zones == "(UTC+04:30) Kabul")
        timeZone = "Asia/Kabul";
    else if (Zones == "(UTC+05:00) Ashgabat, Tashkent")
        timeZone = "Asia/Ashgabat";
    else if (Zones == "(UTC+05:00) Islamabad, Karachi")
        timeZone = "Asia/Karachi";
    else if (Zones == "(UTC+05:00) Qyzylorda")
        timeZone = "Asia/Qyzylorda";
    else if (Zones == "(UTC+05:00) Tashkent")
        timeZone = "Asia/Tashkent";
    else if (Zones == "(UTC+05:00) Ekaterinburg")
        timeZone = "Asia/Yekaterinburg";
    else if (Zones == "(UTC+05:30) Sri Jayawardenepura")
        timeZone = "Asia/Colombo";
    else if (Zones == "(UTC+05:30) Chennai, Kolkata, Mumbai, New Delhi")
        timeZone = "Asia/Kolkata";
    else if (Zones == "(UTC+05:45) Kathmandu")
        timeZone = "Asia/Kathmandu";
    else if (Zones == "(UTC+06:00) Dhaka")
        timeZone = "Asia/Dhaka";
    else if (Zones == "(UTC+06:00) Omsk")
        timeZone = "Asia/Omsk";
    else if (Zones == "(UTC+06:30) Yangon (Rangoon)")
        timeZone = "Asia/Yangon";
    else if (Zones == "(UTC+07:00) Bangkok, Hanoi, Jakarta")
        timeZone = "Asia/Bangkok";
    else if (Zones == "(UTC+07:00) Barnaul, Gorno-Altaysk")
        timeZone = "Asia/Barnaul";
    else if (Zones == "(UTC+07:00) Hovd")
        timeZone = "Asia/Hovd";
    else if (Zones == "(UTC+07:00) Krasnoyarsk")
        timeZone = "Asia/Krasnoyarsk";
    else if (Zones == "(UTC+07:00) Novosibirsk")
        timeZone = "Asia/Novosibirsk";
    else if (Zones == "(UTC+07:00) Tomsk")
        timeZone = "Asia/Tomsk";
    else if (Zones == "(UTC+08:00) Beijing, Chongqing, Hong Kong, Urumqi")
        timeZone = "Asia/Shanghai";
    else if (Zones == "(UTC+08:00) Kuala Lumpur, Singapore")
        timeZone = "Asia/Kuala_Lumpur";
    else if (Zones == "(UTC+08:00) Taipei")
        timeZone = "Asia/Taipei";
    else if (Zones == "(UTC+08:00) Ulaanbaatar")
        timeZone = "Asia/Ulaanbaatar";
    else if (Zones == "(UTC+09:00) Pyongyang")
        timeZone = "Asia/Pyongyang";
    else if (Zones == "(UTC+09:00) Chita")
        timeZone = "Asia/Chita";
    else if (Zones == "(UTC+09:00) Seoul")
        timeZone = "Asia/Seoul";
    else if (Zones == "(UTC+09:00) Osaka, Sapporo, Tokyo")
        timeZone = "Asia/Tokyo";
    else if (Zones == "(UTC+09:00) Yakutsk")
        timeZone = "Asia/Yakutsk";
    else if (Zones == "(UTC+10:00) Brisbane")
        timeZone = "Australia/Brisbane";
    else if (Zones == "(UTC+10:00) Canberra, Melbourne, Sydney")
        timeZone = "Australia/Sydney";
    else if (Zones == "(UTC+10:00) Guam, Port Moresby")
        timeZone = "Pacific/Guam";
    else if (Zones == "(UTC+10:00) Hobart")
        timeZone = "Australia/Hobart";
    else if (Zones == "(UTC+10:00) Vladivostok")
        timeZone = "Asia/Vladivostok";
    else if (Zones == "(UTC+11:00) Magadan")
        timeZone = "Asia/Magadan";
    else if (Zones == "(UTC+11:00) Sakhalin")
        timeZone = "Asia/Sakhalin";
    else if (Zones == "(UTC+12:00) Anadyr, Petropavlovsk-Kamchatsky")
        timeZone = "Asia/Anadyr";
    qDebug()<<"Time-zone : "<<timeZone;
    if (!timeZone.isEmpty())
    {
        QProcess *Dateprocess = new QProcess(this);
        datetimeset = 2;
        Dateprocess->start("sh", QStringList() << "-c" << "sudo timedatectl set-timezone " + timeZone);
        if (!Dateprocess->waitForStarted()) {
            qDebug() << "Error : " << Dateprocess->errorString();
        }
        Dateprocess->waitForFinished(-1);
        delete Dateprocess;

        QDate curdate = QDate::currentDate();
        QString datetxt = curdate.toString("yyyy / MM / dd");
        ui->SysDate_Lbl->setText(datetxt);

        int systemHwClockStatus = system("sudo hwclock -w");
        if (systemHwClockStatus == -1) {
            qDebug() << "Failed to sync hardware clock";
        }


        // Enable and start NTP service
        int systemNtpStatus = system("sudo timedatectl set-ntp true");
        if (systemNtpStatus == -1) {
            qDebug() << "Failed to enable NTP service";
        }
    }
    QDate curdate=QDate::currentDate();
    QString datetxt= curdate.toString("yyyy / MM / dd");
    ui->SysDate_Lbl->setText(datetxt);

    QTime time = QTime::currentTime();
    QString time_text = time.toString("hh : mm : ss");
    ui->SysTime_Lbl->setText(time_text);
}
