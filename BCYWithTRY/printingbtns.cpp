/*********************************************************************************************
 *    This file is part of Biochemistry.
 *    Biochemistry is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    Biochemistry is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program.  If not, see <http://www.gnu.org/licenses/>
 *********************************************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "printer.h"

QImage MainWindow::loadImage(const QString &filePath)
{
    QImage image(filePath);
    if (image.isNull())
    {
        qDebug() << "Error loading image: " << filePath;
        return QImage(); // Return an empty QImage
    }
    return image;
}

// Function to reverse bits in a byte
uint8_t MainWindow::reverseBits(uint8_t byte) {
    uint8_t reversed = 0;
    for (int i = 0; i < 8; i++) {
        reversed <<= 1;
        reversed |= (byte & 1);
        byte >>= 1;
    }
    return reversed;
}

int MainWindow::on_EndPoint_Print_Btn_clicked()
{
    if(endsavebtn==1)
    {
        ui->pushButton_117->setDisabled(true);
        ui->Patient_Name_Btn->setDisabled(true);
        ui->Patient_Age_Btn->setDisabled(true);
        ui->radioButton_5->setDisabled(true);
        ui->radioButton_6->setDisabled(true);
        ui->radioButton_7->setDisabled(true);
        // endsavebtn=0;
    }
    else
    {
        ui->pushButton_117->setDisabled(false);
        ui->Patient_Name_Btn->setDisabled(false);
        ui->Patient_Age_Btn->setDisabled(false);
        ui->radioButton_5->setDisabled(false);
        ui->radioButton_6->setDisabled(false);
        ui->radioButton_7->setDisabled(false);
    }

    QString PID= ui->PatientInfo_LineEdit->text();
    QString PName= ui->Patient_Name->text();
    QString PAge= ui->Patient_Age->text();
    ui->EndPoint_Print_Btn->setDisabled(true);
    QByteArray arry =  ui->label_272->text().toLocal8Bit().constData();
    qDebug()<<"Unit 0 : "<<arry[0];

    QString lab_name , lab_address , data;
    QSqlQuery qry;
    qry.prepare("select * from Lab_details where sno=1");
    qry.exec();
    while(qry.next())
    {
        lab_name = qry.value(1).toString();
        lab_address = qry.value(2).toString();
        data = qry.value(3).toString();
    }

    QString unit_initdata , unit_initdata1 , unit_initdata2, unit_initdata3 , unit_initdata4 , unit_initdata5,unit_initdata6,unit_initdata7,unit_initdata8;
    unit_initdata = arry[0];
    unit_initdata1 = arry[1];
    unit_initdata2 = arry[2];
    unit_initdata3 = arry[3];
    unit_initdata4 = arry[4];
    unit_initdata5 = arry[5];
    unit_initdata6 = arry[6];
    unit_initdata7 = arry[7];
    unit_initdata8 = arry[8];

    int num = 230;
    char character = char(num);
    QString sno, NormalMin, NormalMax,Infant_Nmin, Infant_Nmax, Child_Nmin, Child_Nmax,Female_Nmin, Female_Nmax;
    QSqlQuery qury;
    qury.prepare("SELECT normin,normax,Infant_Nmin, Infant_Nmax, Child_Nmin, Child_Nmax,Female_Nmin, Female_Nmax FROM test WHERE name = :TestName");
    qury.bindValue(":TestName", TestName);
    qury.exec();
    while (qury.next())
    {
        NormalMin = qury.value(0).toString();
        NormalMax = qury.value(1).toString();
        Infant_Nmin = qury.value(2).toString();
        Infant_Nmax = qury.value(3).toString();
        Child_Nmin = qury.value(4).toString();
        Child_Nmax = qury.value(5).toString();
        Female_Nmin = qury.value(6).toString();
        Female_Nmax = qury.value(7).toString();
    }
    qApp->processEvents();
    Printer *p = new Printer(ui, this);
    std::cout << "Trying to open port" << std::endl;
    bool res = p->open("/dev/ttyS0");
    std::cout << "Status: " << res << std::endl;
    if (!res) {
        std::cerr << "Error opening port, aborting" << std::endl;
        return (0);
    }

    if(PID=="")
    {
        QMessageBox msg(this);
        msg.setWindowFlags(Qt::Popup);
        msg.setStyleSheet("background-color:#a0cdfa;font: 75 20pt Liberation Serif ;");
        msg.setText("Please Enter Patient ID");
        QPixmap p("/home/pi/git/BCYWithTRY/BCYWithTRY/img/info.png");
        auto newPixmap = p.scaled(80, 80);
        msg.setIconPixmap(newPixmap);
        QPushButton* saveButton = msg.addButton("Ok", QMessageBox::AcceptRole);
        saveButton->setStyleSheet("QPushButton{background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 #34ba91, stop: 0.5 #34ba91, stop: 1 #34ba91);color:black;}QPushButton:pressed {background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(0, 85, 0), stop: 0.5 rgb(0, 85, 0), stop: 1 rgb(0, 85, 0));color:white;}");
        msg.setDefaultButton(saveButton);
        msg.exec();
        if (msg.clickedButton() == saveButton)
            ui->stackedWidget->setCurrentIndex(17);
        else
            ui->stackedWidget->setCurrentIndex(17);
        ui->EndPoint_Print_Btn->setDisabled(false);
        ui->Patient_Name_Btn->setDisabled(false);
        ui->Patient_Age_Btn->setDisabled(false);
        ui->pushButton_117->setDisabled(false);
    }
    else
    {
        ui->EndPoint_Print_Btn->setDisabled(true);
        timer->stop();
        timer1->stop();
        p->reset();
        p->setAlign(Printer::MIDDLE);
        p->setBold(true);
        if (data == "1") {
            p->write(lab_name);
            p->write("\n" + lab_address);
            p->write("\n\n Test Report");
        } else if (data == "2") {
            p->write("MCA-11 Test Report");
        }
        p->setBold(false);
        p->feed();
        p->feed();
        p->setAlign(Printer::LEFT);
        // Print dynamic information
        if (!ui->PatientInfo_LineEdit->text().isEmpty())
            p->write("Patient ID    : " + ui->PatientInfo_LineEdit->text());
        if (!PName.isEmpty())
            p->write("\nPatient Name  : " + ui->Patient_Name->text());
        if (!text.isEmpty())
            p->write("\nPatient Gender: " + text);
        if (!PAge.isEmpty())
            p->write("\nPatient Age   : " + PAge);
        if (!ui->TestName_Lbl->text().isEmpty())
        {
            if(Prod_Code=="MB1011")
                p->write("\nTest Name     : GLUCOSE");
            else if(Prod_Code=="MB1021")
                p->write("\nTest Name     : GLUCOSE-HK");
            else if(Prod_Code=="MB1031")
                p->write("\nTest Name     : ADA");
            else if(Prod_Code=="MB1041")
                p->write("\nTest Name     : ALBUMIN");
            else if(Prod_Code=="MB1051")
                p->write("\nTest Name     : ALP");
            else if(Prod_Code=="MB1061")
                p->write("\nTest Name     : AMYLASE");
            else if(Prod_Code=="MB1071")
                p->write("\nTest Name     : AMMONIA");
            else if(Prod_Code=="MB1081")
                p->write("\nTest Name     : ASO");
            else if(Prod_Code=="MB1091")
                p->write("\nTest Name     : ACE");
            else if(Prod_Code=="MB1101")
                p->write("\nTest Name     : BICARBONATE");
            else if(Prod_Code=="MB1111")
                p->write("\nTest Name     : DBIL");
            else if(Prod_Code=="MB1121")
                p->write("\nTest Name     : TBIL");
            else if(Prod_Code=="MB1131")
                p->write("\nTest Name     : CALCIUM");
            else if(Prod_Code=="MB1141")
                p->write("\nTest Name     : CHLORIDE");
            else if(Prod_Code=="MB1151")
                p->write("\nTest Name     : CK-MB");
            else if(Prod_Code=="MB1161")
                p->write("\nTest Name     : CK-NAC");
            else if(Prod_Code=="MB1171")
                p->write("\nTest Name     : CREA-ENZY");
            else if(Prod_Code=="MB1181")
                p->write("\nTest Name     : CREATININE");
            else if(Prod_Code=="MB1191")
                p->write("\nTest Name     : ETHYL ALCOHOL");
            else if(Prod_Code=="MB1201")
                p->write("\nTest Name     : GGT");
            else if(Prod_Code=="MB1211")
                p->write("\nTest Name     : AST");
            else if(Prod_Code=="MB1221")
                p->write("\nTest Name     : ALT");
            else if(Prod_Code=="MB1231")
                p->write("\nTest Name     : HDL");
            else if(Prod_Code=="MB1241")
                p->write("\nTest Name     : HEMOGLOBIN");
            else if(Prod_Code=="MB1251")
                p->write("\nTest Name     : HOMOCYSTEINE");
            else if(Prod_Code=="MB1261")
                p->write("\nTest Name     : IRON");
            else if(Prod_Code=="MB1271")
                p->write("\nTest Name     : LACTATE");
            else if(Prod_Code=="MB1281")
                p->write("\nTest Name     : LDH");
            else if(Prod_Code=="MB1291")
                p->write("\nTest Name     : LDL");
            else if(Prod_Code=="MB1301")
                p->write("\nTest Name     : LIPASE");
            else if(Prod_Code=="MB1311")
                p->write("\nTest Name     : MAGNESIUM");
            else if(Prod_Code=="MB1321")
                p->write("\nTest Name     : MICRO ALBUMIN");
            else if(Prod_Code=="MB1331")
                p->write("\nTest Name     : PHOSPHOLIPIDS");
            else if(Prod_Code=="MB1341")
                p->write("\nTest Name     : PHOS-UV");
            else if(Prod_Code=="MB1351")
                p->write("\nTest Name     : PHOS-C");
            else if(Prod_Code=="MB1361")
                p->write("\nTest Name     : POTASSIUM");
            else if(Prod_Code=="MB1371")
                p->write("\nTest Name     : RF");
            else if(Prod_Code=="MB1381")
                p->write("\nTest Name     : SODIUM");
            else if(Prod_Code=="MB1391")
                p->write("\nTest Name     : TCHO");
            else if(Prod_Code=="MB1401")
                p->write("\nTest Name     : TP");
            else if(Prod_Code=="MB1411")
                p->write("\nTest Name     : TPU/CSF");
            else if(Prod_Code=="MB1421")
                p->write("\nTest Name     : TIBC");
            else if(Prod_Code=="MB1431")
                p->write("\nTest Name     : TG");
            else if(Prod_Code=="MB1441")
                p->write("\nTest Name     : UREA");
            else if(Prod_Code=="MB1451")
                p->write("\nTest Name     : URIC ACID");
            else if(Prod_Code=="MB1461")
                p->write("\nTest Name     : ZINC");
            else if(Prod_Code=="MB1471")
                p->write("\nTest Name     : CHOLIN");
            else if(Prod_Code=="MB1481")
                p->write("\nTest Name     : COPPER");
            else if(Prod_Code=="MB1491")
                p->write("\nTest Name     : LITHIUM");
            else if(Prod_Code=="MB1501")
                p->write("\nTest Name     : TBA");
            else if(Prod_Code=="MB1511")
                p->write("\nTest Name     : UIBC");
            else if(Prod_Code=="MB1521")
                p->write("\nTest Name     : GDH");
            else if(Prod_Code=="MB1462")
                p->write("\nTest Name     : ZINC-S");
            else if(Prod_Code=="MB1651")
                p->write("\nTest Name     : MAGNESIUM(C)");
            else if(Prod_Code=="MB1212")
                p->write("\nTest Name     : AST-S");
            else if(Prod_Code=="MB1222")
                p->write("\nTest Name     : ALT-S");
            else if(Prod_Code=="MB1052")
                p->write("\nTest Name     : ALP-S");
            else if(Prod_Code=="MB1122")
                p->write("\nTest Name     : TBIL-S");
            else if(Prod_Code=="MB1182")
                p->write("\nTest Name     : CREATININE-S");

            //p->write("\nTest Name     : " + ui->TestName_Lbl->text());
        }
        if (!ui->label_33->text().isEmpty())
        {
            p->write("\nResult        : " + ui->label_33->text()+" ");
            if (unit_initdata == "Â")
            {
                p->write(character);
                p->write(unit_initdata2 + unit_initdata3 + unit_initdata4 +
                         unit_initdata5 + unit_initdata6 + unit_initdata7 + unit_initdata8);
            }
            else if (!ui->label_272->text().isEmpty())
                p->write(" " + ui->label_272->text());
        }
        p->write("\nDate          : " + ui->SysDate_Lbl->text());
        p->write("\nTime          : " + ui->SysTime_Lbl->text());
        p->feed();
        p->setAlign(Printer::MIDDLE);
        p->write("\nNormal Range  :-");
        p->setAlign(Printer::LEFT);
        if (!Infant_Nmin.isEmpty() && !Infant_Nmax.isEmpty())
            p->write("\nInfant Range  : " + Infant_Nmin + " to " + Infant_Nmax);
        if (!Child_Nmin.isEmpty() && !Child_Nmax.isEmpty())
            p->write("\nChild Range  : " + Child_Nmin + " to " + Child_Nmax);
        if (!NormalMin.isEmpty() && !NormalMax.isEmpty())
            p->write("\nMale Range  : " + NormalMin + " to " + NormalMax);
        if (!Female_Nmin.isEmpty() && !Female_Nmax.isEmpty())
            p->write("\nFemale Range  : " + Female_Nmin + " to " + Female_Nmax);

        p->feed();
        p->feed();

        if(Fixed_Kinetic_Print==1)
        {
            if(FKSprintopt==1) // Run Cal, QC1 , QC2 & Samp
            {
                p->setAlign(Printer::MIDDLE);
                p->setBold(true);
                p->write("Sample Graph");
                p->setBold(false);
                uint8_t printimg[] = {0x1D, 0x76, 0x30}; // Example data
                p->write(printimg, 3); // Send the reversed byte
                p->feed();
                p->feed();
                QString imagePath2 = "/home/pi/FKSPlot.png";
                QImage image2 = loadImage(imagePath2);
                p->printImage(image2,128);
                p->feed();
                p->feed();
            }
        }

        else if(Kinetic_Print==1)
        {
            if(KSprintopt==1) // Run Cal, QC1 , QC2 & Samp
            {

                p->setAlign(Printer::MIDDLE);
                p->setBold(true);
                p->write("Sample Graph");
                p->setBold(false);
                uint8_t printimg[] = {0x1D, 0x76, 0x30}; // Example data
                p->write(printimg, 3); // Send the reversed byte
                p->feed();
                p->feed();
                QString imagePath2 = "/home/pi/KSPlot.png";
                QImage image2 = loadImage(imagePath2);
                p->printImage(image2,128);
                p->feed();
                p->feed();
            }
        }
        p->feed();
        p->feed();
        p->close();
    }
    delete p;
    ui->EndPoint_Print_Btn->setDisabled(false);
    timer->start();
    timer1->start();

    return 1;
}

