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
#include "printer.h"

void MainWindow::plot_two_blnk()
{
    line=4;
}

int MainWindow::Two_cal_print_image()
{
    QString conc,imagePath2;
    QSqlQuery qry;
    qry.prepare("select con1 from test where name='"+TestName+"'");
    qry.exec();
    while(qry.next())
        conc=qry.value(0).toString();

    qApp->processEvents();
    Printer *p = new Printer(ui, this);
    std::cout << "Trying to open port" << std::endl;
    bool res = p->open("/dev/ttyS0");
    std::cout << "Status: " << res << std::endl;
    if (!res) {
        std::cerr << "Error opening port, aborting" << std::endl;
        return (0);
    }
    p->reset();
    p->setAlign(Printer::MIDDLE);
    p->setBold(true);
    p->write(TestName);
    p->write("\nStd/Cal Graph");
    p->setBold(false);
    p->feed();
    p->feed();
    quint8 printimg[] = {27, 42, 0}; // Example data
    p->write(printimg, 3); // Send the reversed byte

    if(Obj_data==1)
        imagePath2 = "/home/pi/FKCPlot.png";
    else if(Obj_data==2)
        imagePath2 = "/home/pi/KCPlot.png";

    QImage image2 = loadImage(imagePath2);
    p->printImage(image2);
    p->feed();
    p->feed();
    p->setAlign(Printer::LEFT);
    p->write("Conc  : " + conc +  " "   +   ui->label_272->text());
    p->feed();
    p->feed();
    p->feed();
    p->close();
    return 0;
}

int MainWindow::Two_QC1_print_image()
{
    qDebug()<<"Current Obj_Data : "<<Obj_data<<"combo_2 : "<<ui->comboBox_2->currentText();
    QString Result , Rang_Min , Rang_Max,imagePath2,Current_Cmbo;
    Result = ui->label_276->text();
    Rang_Min = ui->label_277->text();
    Rang_Max = ui->label_278->text();
    float val = ui->label_276->text().toFloat();
    float min = ui->label_277->text().toFloat();
    float max = ui->label_278->text().toFloat();
    Current_Cmbo = ui->comboBox_2->currentText();
    ui->label_256->setVisible(true);
    if(val<=max && val>=min)
    {
        ui->label_256->setText("QC - Within Range");
        ui->label_256->setStyleSheet("QLabel {color : green;}");
    }
    else
    {
        ui->label_256->setText("QC - Without Range");
        ui->label_256->setStyleSheet("QLabel {color : red;}");
    }
    QThread::msleep(200);
    qApp->processEvents();
    Printer *p = new Printer(ui, this);
    std::cout << "Trying to open port" << std::endl;
    bool res = p->open("/dev/ttyS0");
    std::cout << "Status: " << res << std::endl;
    if (!res) {
        std::cerr << "Error opening port, aborting" << std::endl;
        return (0);
    }
     p->reset();
    p->setAlign(Printer::MIDDLE);
    p->setBold(true);
    p->write(TestName);
    if(Current_Cmbo=="QC - 1")
        p->write("\nQC-1 Graph");
    else if(Current_Cmbo=="QC - 2")
        p->write("\nQC-2 Graph");
    p->setBold(false);
    p->feed();
    p->feed();
    quint8 printimg[] = {27, 42, 0}; // Example data
    p->write(printimg, 3); // Send the reversed byte
    if(End_qc1_opt==1 || Two_qc1_opt==1 || Kin_qc1_opt==1)
    {
        if(Obj_data==1)
            imagePath2 = "/home/pi/FKQC1Plot.png";
        else if(Obj_data==2)
            imagePath2 = "/home/pi/KQC1Plot.png";
    }
    else if(End_qc2_opt==1 || Two_qc2_opt==1 || Kin_qc2_opt==1)
    {
        if(Obj_data==1)
            imagePath2 = "/home/pi/FKQC2Plot.png";
        else if(Obj_data==2)
            imagePath2 = "/home/pi/KQC2Plot.png";
    }

    QImage image2 = loadImage(imagePath2);
    p->printImage(image2);
    p->feed();
    p->feed();
    p->setAlign(Printer::LEFT);
    p->write("Result    : "   +  Result +  " "   +   ui->label_272->text());
    p->write("\nQC Range  : "   +  Rang_Min + " " + "to" + " "  +    Rang_Max);
    p->write("\nStatus    : "+ui->label_256->text());
    p->feed();
    p->feed();
    p->feed();
    p->close();
    return 0;
}

void MainWindow::on_RunCal_Btn_2_clicked()
{
    multi_cal1=0;
    Run_Data=0;
    if(Multi_calibration==1)
    {
        addColumnsToTable();
        clearGraph_cal();
        ui->Stop_Btn_3->setDisabled(true);
        ui->stackedWidget->setCurrentIndex(30);
        ui->stackedWidget_12->setCurrentIndex(0);
        ui->label_345->setText(TestName+" - Concentration test");
        ui->label_350->setText("CALIBRATOR");
        if(Obj_data==1)
        {
            ui->label_174->setVisible(false);
            ui->label_175->setVisible(false);
            ui->label_176->setVisible(false);
            ui->label_177->setVisible(false);
            ui->label_178->setVisible(false);
            ui->label_179->setVisible(false);
            ui->toolButton_65->setVisible(false);
            ui->concen_lbl->setVisible(true);
            ui->Absor_lbl->setVisible(true);
            ui->F_lbl->setVisible(true);
            ui->Conc_lbl->setVisible(true);
            ui->Abs_lbl->setVisible(true);
            ui->Fact_lbl->setVisible(true);

            ui->concen_lbl->setText("Conc.");
            ui->Absor_lbl->setText("ΔA(A2-A1)");
            ui->F_lbl->setText("Factor"); //
        }
        else if(Obj_data==2)
        {
            ui->label_174->setVisible(true);
            ui->label_175->setVisible(true);
            ui->label_176->setVisible(true);
            ui->label_177->setVisible(true);
            ui->label_178->setVisible(true);
            ui->label_179->setVisible(true);
            ui->label_174->setText("Abs1");
            ui->label_176->setText("Abs2");
            ui->label_178->setText("Abs3");
            ui->toolButton_65->setVisible(false);
            ui->concen_lbl->setVisible(true);
            ui->Absor_lbl->setVisible(true);
            ui->F_lbl->setVisible(true);
            ui->Conc_lbl->setVisible(true);
            ui->Abs_lbl->setVisible(true);
            ui->Fact_lbl->setVisible(true);

            ui->concen_lbl->setText("Conc.");
            ui->Absor_lbl->setText("ΔA/min");
            ui->F_lbl->setText("Factor"); //
        }
        ui->label_168->clear();
        ui->label_169->clear();
        ui->label_170->clear();
        ui->label_171->clear();
        ui->label_172->clear();
        ui->label_173->clear();
        ui->label_361->clear();
        ui->label_362->clear();
        ui->label_363->clear();
        ui->label_175->clear();
        ui->label_177->clear();
        ui->label_179->clear();

        ui->Conc_lbl->clear();
        ui->Abs_lbl->clear();
        ui->Fact_lbl->clear();
        QString Nostd;
        //int cal=0;
        QSqlQuery query;
        query.prepare("select * from test where name = '"+TestName+"'");
        query.exec();
        while(query.next())
        {
            //cal=query.value(16).toInt();
            Nostd=query.value(16).toString();
        }
        /*  if(cal==multi_cal1)
            ui->toolButton_39->setDisabled(false);
        else
            ui->toolButton_39->setDisabled(true);*/

        if(Nostd=="1")
        {
            ui->toolButton_30->setVisible(true);
            ui->toolButton_31->setVisible(false);
            ui->toolButton_32->setVisible(false);
            ui->toolButton_33->setVisible(false);
            ui->toolButton_34->setVisible(false);
            ui->toolButton_35->setVisible(false);
            ui->toolButton_36->setVisible(false);
            ui->toolButton_37->setVisible(false);
        }
        else if(Nostd=="2")
        {
            ui->toolButton_30->setVisible(true);
            ui->toolButton_31->setVisible(true);
            ui->toolButton_32->setVisible(false);
            ui->toolButton_33->setVisible(false);
            ui->toolButton_34->setVisible(false);
            ui->toolButton_35->setVisible(false);
            ui->toolButton_36->setVisible(false);
            ui->toolButton_37->setVisible(false);
        }
        else if(Nostd=="3")
        {
            ui->toolButton_30->setVisible(true);
            ui->toolButton_31->setVisible(true);
            ui->toolButton_32->setVisible(true);
            ui->toolButton_33->setVisible(false);
            ui->toolButton_34->setVisible(false);
            ui->toolButton_35->setVisible(false);
            ui->toolButton_36->setVisible(false);
            ui->toolButton_37->setVisible(false);
        }
        else if(Nostd=="4")
        {
            ui->toolButton_30->setVisible(true);
            ui->toolButton_31->setVisible(true);
            ui->toolButton_32->setVisible(true);
            ui->toolButton_33->setVisible(true);
            ui->toolButton_34->setVisible(false);
            ui->toolButton_35->setVisible(false);
            ui->toolButton_36->setVisible(false);
            ui->toolButton_37->setVisible(false);
        }
        else if(Nostd=="5")
        {
            ui->toolButton_30->setVisible(true);
            ui->toolButton_31->setVisible(true);
            ui->toolButton_32->setVisible(true);
            ui->toolButton_33->setVisible(true);
            ui->toolButton_34->setVisible(true);
            ui->toolButton_35->setVisible(false);
            ui->toolButton_36->setVisible(false);
            ui->toolButton_37->setVisible(false);
        }
        else if(Nostd=="6")
        {
            ui->toolButton_30->setVisible(true);
            ui->toolButton_31->setVisible(true);
            ui->toolButton_32->setVisible(true);
            ui->toolButton_33->setVisible(true);
            ui->toolButton_34->setVisible(true);
            ui->toolButton_35->setVisible(true);
            ui->toolButton_36->setVisible(false);
            ui->toolButton_37->setVisible(false);
        }
        else if(Nostd=="7")
        {
            ui->toolButton_30->setVisible(true);
            ui->toolButton_31->setVisible(true);
            ui->toolButton_32->setVisible(true);
            ui->toolButton_33->setVisible(true);
            ui->toolButton_34->setVisible(true);
            ui->toolButton_35->setVisible(true);
            ui->toolButton_36->setVisible(true);
            ui->toolButton_37->setVisible(false);
        }
        else if(Nostd=="8")
        {
            ui->toolButton_30->setVisible(true);
            ui->toolButton_31->setVisible(true);
            ui->toolButton_32->setVisible(true);
            ui->toolButton_33->setVisible(true);
            ui->toolButton_34->setVisible(true);
            ui->toolButton_35->setVisible(true);
            ui->toolButton_36->setVisible(true);
            ui->toolButton_37->setVisible(true);
        }


    }
    else if(Multi_calibration==2)
    {
        data1=1;
        chk=2;
        endsavebtn=0;
        ui->label_12->clear();
        ui->label_32->clear();
        if(Obj_data==1)
        {
            option=5;
            data1=1;
            clearGraph_end();
            FKCprintopt=0;
            tworuncal=1;
            CountBackfunc=1;
            twopointsavebtn=0;
            // endsavebtn=0;
            qDebug()<<"Obj_data : 1";
        }
        else if(Obj_data==2)
        {
            option=8;
            clearGraph_end();
            KCprintopt=0;
            kineticruncal=1;
            CountBackfunc=1;
            kineticsavebtn=0;
            // endsavebtn=0;
            qDebug()<<"Obj_data : 2";
        }
        ui->Home_Btn_3->setVisible(true);
        ui->Home_Btn_3->setDisabled(true);
        ui->Stop_Btn_2->setVisible(true);
        ui->Stop_Btn_2->setEnabled(true);
        ui->Stop_Btn->setVisible(false);
        ui->Stop_Btn->setEnabled(false);
        ui->label_203->setVisible(false);
        ui->label_204->setVisible(false);
        ui->label_106->clear();
        ui->label_121->clear();
        ui->label_123->clear();
        ui->label_125->clear();
        ui->label_120->clear();
        ui->label_122->clear();
        ui->label_194->clear();
        ui->label_195->clear();
        ui->label_198->clear();
        ui->label_119->clear();
        ui->label_34->clear();
        ui->label_196->clear();
        ui->label_204->clear();
        ui->label_33->clear();
        ui->label_76->clear();
        ui->label_127->clear();
        ui->label_128->clear();
        ui->label_132->clear();

        ui->label->clear();
        ui->label_100->setVisible(true);
        ui->label_33->setVisible(true);
        ui->label_272->setVisible(true);
        ui->label_207->setVisible(false);
        ui->label_75->setVisible(false);
        ui->label_34->setVisible(true);
        ui->label_197->setVisible(true);
        ui->label_196->setVisible(false);
        ui->label_76->setVisible(false);
        ui->label_193->setText("Abs");
        ui->label_120->setVisible(true);
        ui->label_122->setVisible(true);
        ui->label_72->setVisible(false);
        ui->label_76->setVisible(true);
        ui->label_243->setVisible(false);
        ui->label_72->setVisible(false);
        ui->label_119->setVisible(false);
        ui->label_193->setVisible(true);
        ui->label_100->setVisible(false);
        ui->label_240->setVisible(false);
        ui->label_239->setVisible(false);
        ui->Save_Btn_6->setVisible(true);
        ui->comboBox_2->setDisabled(true);
        ui->Retest_5->setDisabled(true);
        ui->RunCal_Btn_2->setDisabled(true);
        ui->RunSample_Btn_2->setDisabled(true);
        ui->TP_QC_Check->setDisabled(true);
        ui->Save_Btn_6->setDisabled(true);
        ui->Print_Btn->setDisabled(true);
        conditioncheck();//Pro_Code_Check();
    }
}

void MainWindow::twocalibrate()
{
    QString wavelength , intensity ;
    double blankval = 0 ,con1 =0;
    int read = 0 ,dely = 0 ,lag=0;
    QSqlQuery query;
    query.prepare("select wave,dely,read,lag,con1 from test where name = :name");
    query.bindValue(":name",TestName);
    if(!query.exec())
    {
        qDebug()<<"Query Error : "<<query.lastError().text();
        return;
    }
    else if(query.next())
    {
        wavelength=query.value(0).toString();
        dely=query.value(1).toInt();
        read=query.value(2).toInt();
        lag=query.value(3).toInt();
        con1=query.value(4).toDouble();
    }
    else
    {
        qDebug()<<"No record found for Testname : "<<TestName;
        return;
    }
    QSqlQuery qry;
    qry.prepare("select intensity,blankval from tests where wave = :wavelength");
    qry.bindValue(":wavelength",wavelength);
    if(!qry.exec())
    {
        qDebug()<<"Query Error : "<<qry.lastError().text();
        return;
    }
    else if(qry.next())
    {
        read_intensity=qry.value(0).toInt();
        blankval =qry.value(1).toDouble();
    }
    else
    {
        qDebug()<<"No record found for Wave : "<<wavelength;
        return;
    }
    qDebug()<<"TestName : "<<TestName<<" "<<"wave : "<<wavelength<<" "<<"blank : "<<blankval;
    //read_intensity = intensity.toInt();
    /* int sno=1;
    QSqlQuery qy;
    qy.prepare("select mulfact from tests where where sno = :serial");
    qy.bindValue(":serial",sno);
    if(!qy.exec())
    {
        qDebug()<<"Query Error : "<<qy.lastError().text();
        return;
    }
    else if(qy.next())
        mulfact=qy.value(0).toDouble();
    else
    {
        qDebug()<<"No record found for sno : "<<TestName;
        return;
    }*/

    if(wavelength=="340 nm")
    {
        read_wave=7;
        read_wavenm=0;
    }
    else if(wavelength=="405 nm")
    {
        read_wave=6;
        read_wavenm=1;
    }
    else if(wavelength=="505 nm")
    {
        read_wave=5;
        read_wavenm=2;
    }
    else if(wavelength=="545 nm")
    {
        read_wave=4;
        read_wavenm=3;
    }
    else if(wavelength=="570 nm")
    {
        read_wave=3;
        read_wavenm=4;
    }
    else if(wavelength=="630 nm")
    {
        read_wave=2;
        read_wavenm=5;
    }
    else if(wavelength=="700 nm")
    {
        read_wave=0;
        read_wavenm=6;
    }
    QThread::sleep(1);
    clearData();
    total_read_point=read+dely;
    current_read_point=0;
    blank_val=blankval;
    dly=dely;
    // multiFact=mulfact;
    concen=con1;
    bc_y_val=0;
    ymin=absorbance-0.02;
    ymax=absorbance+0.02;
    if(Obj_data==1)
    {
        option=5;
        val=read/dely;
    }
    else if(Obj_data==2)
    {
        option=8;
        readingtime=read;
        val=lag;
        lagg=lag;
        sec_read_point=dly+(readingtime/lagg);
        third_read_point=dly+((readingtime/lagg)*2);
        last_read_point=dly+((readingtime/lagg)*3);
    }
    plot_two_calibrate();
    readtimer->start(10000);
}

void MainWindow::plot_two_calibrate()
{
    if(Obj_data==1)
        line=5;
    else if(Obj_data==2)
        line=8;
}

void MainWindow::on_Save_Btn_6_clicked()
{
    if(Obj_data==1)
    {
        Cal_His_Val=0;
        // Twopoint Save Btn...
        twopointsavebtn=1;
        Tname="" ; batchno="";concent="";Calib_Abs="" ;factor=""; dte="";
        QSqlQuery query;
        calibrate = 0 ;
        fact =0;
        CalibrateAbs = char (calibrate);
        CalibrateAbs = ui->label_76->text();
        Fact = char (fact);
        Fact = ui->label_34->text();
        Fact = ui->label_240->text();
        // QString TestName = ui->TestName_Lbl->text();
        ui->Save_Btn_6->setDisabled(true);
        Calibration_Histry_All();
    }
    else if(Obj_data==2)
    {
        Cal_His_Val=0;
        // Endpoint Save Btn...

        kineticsavebtn=1;
        Tname="" ; batchno="";concent="";Calib_Abs="" ;factor=""; dte="";
        QSqlQuery query;
        calibrate = 0 ;
        fact =0;
        CalibrateAbs = char (calibrate);
        CalibrateAbs = ui->label_76->text();
        Fact = char (fact);
        Fact = ui->label_34->text();
        Fact = ui->label_240->text();
        ui->Save_Btn_6->setDisabled(true);
        Calibration_Histry_All();
    }

}

void MainWindow::on_RunSample_Btn_2_clicked()
{
    ui->label_12->clear();
    ui->label_32->clear();
    Run_Data=0;
    if(Obj_data==1)
    {
        option=6;
        tworunsamp=1;
        Fixed_Kinetic_Print=1;
        Kinetic_Print=0;
        FKSprintopt=0;
        CountBackfunc=1;
        check_saveBtn=0;
        endsavebtn=0;
        ui->label_72->setVisible(true);
        ui->label_119->setVisible(true);
        ui->label_119->clear();
    }
    else if(Obj_data==2)
    {
        option=9;
        KSprintopt=0;
        Kinetic_Print=1;
        Fixed_Kinetic_Print=0;
        kineticrunsamp=1;
        CountBackfunc=1;
        check_saveBtn=0;
        endsavebtn=0;
        ui->label_72->setVisible(false);
        ui->label_119->setVisible(false);
    }
    qDebug()<<"Obj_data : "<<Obj_data<<"opt : "<<option;
    ui->Save_Btn_6->setDisabled(true);
    clearGraph_end();
    ui->pushButton_117->setDisabled(false);
    ui->PatientInfo_LineEdit->setDisabled(false);
    ui->Patient_Name_Btn->setDisabled(false);
    ui->Patient_Age_Btn->setDisabled(false);
    ui->Home_Btn_3->setVisible(true);
    ui->comboBox_2->setDisabled(true);
    ui->Retest_5->setDisabled(true);
    ui->Home_Btn_3->setDisabled(true);
    ui->Stop_Btn->setVisible(false);
    ui->Stop_Btn_2->setVisible(true);
    ui->Stop_Btn_2->setEnabled(true);
    ui->RunSample_Btn_2->setDisabled(true);
    ui->RunCal_Btn_2->setDisabled(true);
    ui->TP_QC_Check->setDisabled(true);
    ui->Print_Btn->setVisible(false);
    ui->Print_Btn->setVisible(true);
    ui->Print_Btn->setDisabled(true);
    ui->label_106->clear();
    ui->label_121->clear();
    ui->label_123->clear();
    ui->label_125->clear();
    ui->label_120->clear();
    ui->label_122->clear();
    ui->label_194->clear();
    ui->label_195->clear();
    ui->label_198->clear();

    ui->label_127->clear();
    ui->label_128->clear();
    ui->label_132->clear();
    ui->label_204->clear();
    ui->label_33->clear();
    ui->label_120->setVisible(true);
    ui->label_122->setVisible(true);
    ui->label_207->setVisible(false);
    ui->radioButton_5->setDisabled(false);
    ui->radioButton_6->setDisabled(false);
    ui->radioButton_7->setDisabled(false);
    ui->pushButton_117->setDisabled(false);
    ui->Patient_Name_Btn->setDisabled(false);
    ui->Patient_Age_Btn->setDisabled(false);
    ui->EndPoint_Save_Btn->setEnabled(true);
    conditioncheck();//Pro_Code_Check();
}

void MainWindow::twosample()
{
    qDebug()<<"Two sample btn "<<"Opt : "<<option<<line;
    QString wavelength , intensity ;
    double blankval = 0 , fact = 0;
    int read = 0 ,lag =0, dely = 0  ;
    QSqlQuery query;
    query.prepare("select wave,read,lag,dely,fact from test where name = :name");
    query.bindValue(":name",TestName);
    if(!query.exec())
    {
        qDebug()<<"Query Error : "<<query.lastError().text();
        return;
    }
    else if(query.next())
    {
        wavelength=query.value(0).toString();
        read=query.value(1).toInt();
        lag=query.value(2).toInt();
        dely=query.value(3).toInt();
        fact=query.value(4).toDouble();
    }
    else
    {
        qDebug()<<"No record found for Testname : "<<TestName;
        return;
    }
    QSqlQuery qry;
    qry.prepare("select intensity,blankval from tests where wave = :wavelength");
    qry.bindValue(":wavelength",wavelength);
    if(!qry.exec())
    {
        qDebug()<<"Query Error : "<<qry.lastError().text();
        return;
    }
    else if(qry.next())
    {
        read_intensity=qry.value(0).toInt();
        blankval=qry.value(1).toDouble();
    }
    else
    {
        qDebug()<<"No record found for wave : "<<wavelength;
        return;
    }

    //read_intensity = intensity.toInt();
    /*  int sno=1;
    QSqlQuery qy;
    qy.prepare("select mulfact from tests where where sno = :serial");
    qy.bindValue(":serial",sno);
    if(!qy.exec())
    {
        qDebug()<<"Query Error : "<<qy.lastError().text();
        return;
    }
    else if(qy.next())
        mulfact=qy.value(0).toDouble();
    else
    {
        qDebug()<<"No record found for sno : "<< 1;
        return;
    }*/

    if(wavelength=="340 nm")
    {
        read_wave=7;
        read_wavenm=0;
    }
    else if(wavelength=="405 nm")
    {
        read_wave=6;
        read_wavenm=1;
    }
    else if(wavelength=="505 nm")
    {
        read_wave=5;
        read_wavenm=2;
    }
    else if(wavelength=="545 nm")
    {
        read_wave=4;
        read_wavenm=3;
    }
    else if(wavelength=="570 nm")
    {
        read_wave=3;
        read_wavenm=4;
    }
    else if(wavelength=="630 nm")
    {
        read_wave=2;
        read_wavenm=5;
    }
    else if(wavelength=="700 nm")
    {
        read_wave=0;
        read_wavenm=6;
    }
    dly=dely;
    // multiFact=mulfact;
    fct=fact;
    bc_y_val=0;
    blank_val=blankval;
    current_read_point=0;
    ymin=absorbance-0.02;
    ymax=absorbance+0.02;
    total_read_point=read+dely;
    QThread::sleep(1);
    clearData();
    if(Obj_data==1)
    {
        option=6;
        val=read/dely;
    }
    else if(Obj_data==2)
    {
        option=9;
        readingtime=read;
        val=lag;
        lagg=lag;
        sec_read_point=dly+(readingtime/lagg);
        third_read_point=dly+((readingtime/lagg)*2);
        last_read_point=dly+((readingtime/lagg)*3);
    }
    plot_two();
    readtimer->start(10000);
}

void MainWindow::on_TP_QC_Check_clicked()
{
    QString cmbox= ui->comboBox_2->currentText();
    ui->label_12->clear();
    ui->label_32->clear();
    Run_Data=0;
    if(Obj_data==1)
    {
        option=13;
        tworuncal=1;
        if(cmbox=="QC - 1")
        {
            FKQC1printopt=0;
        }
        else if(cmbox=="QC - 2")
        {
            FKQC2printopt=0;
        }
        CountBackfunc=1;
    }
    else if(Obj_data==2)
    {
        option=14;
        kineticruncal=1;
        CountBackfunc=1;
        if(cmbox=="QC - 1")
        {
            KQC1printopt=0;
        }
        else if(cmbox=="QC - 2")
        {
            KQC2printopt=0;
        }
        qDebug()<<"Obj : "<<Obj_data<<" "<<"Cmbo : "<<cmbox;
    }
    clearGraph_end();
    ui->label_72->setVisible(false);
    ui->label_119->setVisible(false);
    ui->Save_Btn_6->setDisabled(true);
    ui->Home_Btn_3->setVisible(true);
    ui->Home_Btn_3->setDisabled(true);
    ui->Stop_Btn_2->setVisible(true);
    ui->comboBox_2->setDisabled(true);
    ui->Retest_5->setDisabled(true);
    ui->Print_Btn->setDisabled(true);
    ui->Stop_Btn->setVisible(false);
    ui->Stop_Btn_2->setEnabled(true);
    ui->TP_QC_Check->setDisabled(true);
    ui->RunSample_Btn_2->setDisabled(true);
    ui->RunCal_Btn_2->setDisabled(true);
    ui->label_120->setVisible(true);
    ui->label_122->setVisible(true);
    ui->label_106->clear();
    ui->label_121->clear();
    ui->label_123->clear();
    ui->label_125->clear();
    ui->label_120->clear();
    ui->label_122->clear();
    ui->label_194->clear();
    ui->label_195->clear();
    ui->label_198->clear();
    ui->label_127->clear();
    ui->label_128->clear();
    ui->label_132->clear();
    ui->label_127->clear();
    ui->label_128->clear();
    ui->label_132->clear();
    ui->label_204->clear();
    ui->label_33->clear();
    ui->label_203->setVisible(false);
    ui->label_204->setVisible(false);
    ui->label_207->setVisible(false);
    ui->label_234->clear();
    ui->label_276->clear();
    ui->label_256->setVisible(false);
    ui->Print_Btn->setDisabled(true);
    conditioncheck();//Pro_Code_Check();

}

void MainWindow::twoqcrun()
{
    QString wavelength , intensity ;
    double blankval = 0 , fact = 0;
    int read = 0 ,lag =0, dely = 0  ;
    QSqlQuery query;
    query.prepare("select wave,read,lag,dely,fact from test where name = :name");
    query.bindValue(":name",TestName);
    if(!query.exec())
    {
        qDebug()<<"Query Error : "<<query.lastError().text();
        return;
    }
    else if(query.next())
    {
        wavelength=query.value(0).toString();
        read=query.value(1).toInt();
        lag=query.value(2).toInt();
        dely=query.value(3).toInt();
        fact=query.value(4).toDouble();
    }
    else
    {
        qDebug()<<"No record found for Testname : "<<TestName;
        return;
    }
    QSqlQuery qry;
    qry.prepare("select intensity,blankval from tests where wave = :wavelength");
    qry.bindValue(":wavelength",wavelength);
    if(!qry.exec())
    {
        qDebug()<<"Query Error : "<<qry.lastError().text();
        return;
    }
    else if(qry.next())
    {
        read_intensity=qry.value(0).toInt();
        blankval=qry.value(1).toDouble();
    }
    else
    {
        qDebug()<<"No record found for wave : "<<wavelength;
        return;
    }

    //read_intensity = intensity.toInt();
    /* int sno=1;
    QSqlQuery qy;
    qy.prepare("select mulfact from tests where where sno = :serial");
    qy.bindValue(":serial",sno);
    if(!qy.exec())
    {
        qDebug()<<"Query Error : "<<qy.lastError().text();
        return;
    }
    else if(qy.next())
    {
        mulfact=qy.value(0).toDouble();
    }
    else
    {
        qDebug()<<"No record found for sno : "<<1;
        return;
    }*/

    if(wavelength=="340 nm")
    {
        read_wave=7;
        read_wavenm=0;
    }
    else if(wavelength=="405 nm")
    {
        read_wave=6;
        read_wavenm=1;
    }
    else if(wavelength=="505 nm")
    {
        read_wave=5;
        read_wavenm=2;
    }
    else if(wavelength=="545 nm")
    {
        read_wave=4;
        read_wavenm=3;
    }
    else if(wavelength=="570 nm")
    {
        read_wave=3;
        read_wavenm=4;
    }
    else if(wavelength=="630 nm")
    {
        read_wave=2;
        read_wavenm=5;
    }
    else if(wavelength=="700 nm")
    {
        read_wave=0;
        read_wavenm=6;
    }
    QThread::sleep(1);
    clearData();
    total_read_point=read+dely;
    current_read_point=0;
    blank_val=blankval;
    readingtime=read;
    // multiFact=mulfact;
    bc_y_val=0;
    ymin=absorbance-0.02;
    ymax=absorbance+0.02;
    fct=fact;
    dly=dely;
    if(Obj_data==1)
    {
        option=13;
        val=read/dely;
        readtimer->start(10000);
    }
    else if(Obj_data==2)
    {
        option=14;
        val=lag;
        lagg=lag;
        sec_read_point=dly+(readingtime/lagg);
        third_read_point=dly+((readingtime/lagg)*2);
        last_read_point=dly+((readingtime/lagg)*3);
    }
    two_qcplot();
    readtimer->start(10000);
}

void MainWindow::plot_two()
{
    if(Obj_data==1)
        line=6;
    else if(Obj_data==2)
        line=9;

    qDebug()<<"sample btn "<<"Opt : "<<option<<line<<"plot 2";
}

void MainWindow::two_qcplot()
{
    if(Obj_data==1)
        line=14;
    else if(Obj_data==2)
        line=15;
}
