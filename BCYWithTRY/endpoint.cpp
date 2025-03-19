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
QString Cal_Abs1,Cal_Abs2,Cal_Abs3,Cal_Abs4,Cal_Abs5,Cal_Abs6,Cal_Abs7,Cal_Abs8,Cal_Abs9,Cal_Abs10;

void MainWindow::clearGraph_end()
{
    qv_x.clear();
    qv_y.clear();
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(qv_x,qv_y);
    ui->customPlot->xAxis->setLabelFont(QFont("sans", 9, QFont::Bold));
    ui->customPlot->yAxis->setLabelFont(QFont("sans", 9, QFont::Bold));

    ui->customPlot->xAxis->setLabel("Time(S)");
    ui->customPlot->yAxis->setLabel("Abs");     // Darken axis line color
    QPen darkPenX(Qt::black);  // Set the pen to black
    darkPenX.setWidth(3);      // Optionally set width to make it thicker
    QPen darkPenY(Qt::black);  // Set the pen to black
    darkPenY.setWidth(1);      // Optionally set width to make it thicker
    // Apply to axis lines
    ui->customPlot->xAxis->setBasePen(darkPenX);
    ui->customPlot->yAxis->setBasePen(darkPenY);

    // set axes ranges, so we see all data:
    ui->customPlot->xAxis->setRange(0,5);
    ui->customPlot->yAxis->setRange(0,5);

    ui->customPlot->addGraph();
    ui->customPlot->graph(1)->setData(qv_x,qv_y);
    ui->customPlot->addGraph();
    ui->customPlot->graph(2)->setData(qv_x,qv_y);
    ui->customPlot->addGraph();
    ui->customPlot->graph(3)->setData(qv_x,qv_y);
    ui->customPlot->addGraph();
    ui->customPlot->graph(4)->setData(qv_x,qv_y);
    ui->customPlot->clearPlottables();
    ui->customPlot->replot();
    ui->customPlot->update();
}


void MainWindow::clearGraph_cal()
{
    qv_x.clear();
    qv_y.clear();
    ui->customPlot_4->addGraph();
    ui->customPlot_4->graph(0)->setData(qv_x,qv_y);
    ui->customPlot_4->xAxis->setLabel("Time(S)");
    ui->customPlot_4->yAxis->setLabel("Abs");
    // set axes ranges, so we see all data:
    ui->customPlot_4->xAxis->setRange(0,5);
    ui->customPlot_4->yAxis->setRange(0,5);
    ui->customPlot_4->addGraph();
    ui->customPlot_4->graph(1)->setData(qv_x,qv_y);
    ui->customPlot_4->addGraph();
    ui->customPlot_4->graph(2)->setData(qv_x,qv_y);
    ui->customPlot_4->addGraph();
    ui->customPlot_4->graph(3)->setData(qv_x,qv_y);
    ui->customPlot_4->replot();
    ui->customPlot_4->update();
}

void MainWindow::clearGraph_multical()
{
    qv_x.clear();
    qv_y.clear();
    ui->customPlot_5->addGraph();
    ui->customPlot_5->graph(0)->setData(qv_x,qv_y);
    ui->customPlot_5->xAxis->setLabel("Concentration");
    ui->customPlot_5->yAxis->setLabel("Absorbance");
    // set axes ranges, so we see all data:
    ui->customPlot_5->xAxis->setRange(0,5);
    ui->customPlot_5->yAxis->setRange(0,5);
    ui->customPlot_5->addGraph();
    ui->customPlot_5->graph(1)->setData(qv_x,qv_y);
    ui->customPlot_5->addGraph();
    ui->customPlot_5->graph(2)->setData(qv_x,qv_y);
    ui->customPlot_5->addGraph();
    ui->customPlot_5->graph(3)->setData(qv_x,qv_y);
    ui->customPlot_5->replot();
    ui->customPlot_5->update();
}

void MainWindow::clearGraph_Turbidity()
{
    qv_x.clear();
    qv_y.clear();
    ui->customPlot_6->addGraph();
    ui->customPlot_6->graph(0)->setData(qv_x,qv_y);
    ui->customPlot_6->xAxis->setLabel("Concentration");
    ui->customPlot_6->yAxis->setLabel("Absorbance");
    // set axes ranges, so we see all data:
    ui->customPlot_6->xAxis->setRange(0,5);
    ui->customPlot_6->yAxis->setRange(0,5);
    ui->customPlot_6->addGraph();
    ui->customPlot_6->removeGraph(0);
    ui->customPlot_6->removeGraph(1);
    ui->customPlot_6->clearPlottables();
    ui->customPlot_6->replot();
    ui->customPlot_6->update();
}

void MainWindow::clearGraph_Turbidity_Grph()
{
    qv_x.clear();
    qv_y.clear();
    ui->customPlot_7->addGraph();
    ui->customPlot_7->graph(0)->setData(qv_x,qv_y);
    ui->customPlot_7->xAxis->setLabel("Concentration");
    ui->customPlot_7->yAxis->setLabel("Absorbance");
    // set axes ranges, so we see all data:
    ui->customPlot_7->xAxis->setRange(0,5);
    ui->customPlot_7->yAxis->setRange(0,5);
    ui->customPlot_7->addGraph();
    ui->customPlot_7->removeGraph(0);
    ui->customPlot_7->clearPlottables();
    ui->customPlot_7->clearItems(); // Clears all QCPItemText and other items from the plot
    ui->customPlot_7->replot();
    ui->customPlot_7->update();
}

void MainWindow::on_RunBlank_Btn_clicked()
{
    option=1;
    Run_Data=0;
    BackBlankfunc=1;
    ui->label_12->clear();
    ui->label_32->clear();
    ui->Home_Btn_3->setVisible(true);
    ui->Home_Btn_3->setDisabled(true);
    clearGraph_end();
    ui->Stop_Btn->setVisible(true);
    ui->Stop_Btn_2->setVisible(false);
    ui->Stop_Btn->setEnabled(true);
    ui->label->clear();
    ui->label->setVisible(false);
    ui->label_6->setVisible(false);
    ui->label_100->setVisible(false);
    ui->label_203->setVisible(false);
    ui->label_204->setVisible(false);
    ui->label_207->setVisible(false);
    ui->label_208->setVisible(false);
    ui->label_75->setVisible(false);
    ui->label_7->setVisible(false);
    ui->label_209->setVisible(false);
    ui->label_239->setVisible(true);
    ui->label_239->setText("Abs");
    ui->label_240->setVisible(true);
    ui->label_6->clear();
    ui->label_204->clear();
    ui->label_33->clear();
    ui->RunBlank_Btn->setDisabled(true);
    ui->RunCal_Btn->setDisabled(true);
    ui->E_QC_Check->setDisabled(true);
    ui->RunSample_Btn->setDisabled(true);
    ui->Retest->setDisabled(true);
    ui->Retest_3->setDisabled(true);
    ui->Retest_4->setDisabled(true);
    ui->comboBox->setDisabled(true);
    ui->Retest_5->setDisabled(true);
    ui->Save_Btn_5->setDisabled(true);
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
    QString wavelength;
    double blankval = 0 ;
    QSqlQuery query;
    // Start transaction
    query.exec("BEGIN TRANSACTION;");
    query.prepare("select wave from test where name = :name");
    query.bindValue(":name",TestName);
    if(!query.exec())
    {
        qDebug()<<"Query Error : "<<query.lastError().text();
        query.exec("ROLLBACK;");
        return;
    }
    else if(query.next())
        wavelength=query.value(0).toString();
    else
    {
        qDebug()<<"No record found for Testname : "<<TestName;
        return;
    }
    // Commit the transaction if all queries succeed
    query.exec("COMMIT;");
    qDebug()<<"Wave : "<<wavelength;

    QSqlQuery qry;
    // Start transaction
    qry.exec("BEGIN TRANSACTION;");
    qry.prepare("select intensity,blankval from tests where wave = :wave");
    qry.bindValue(":wave",wavelength);
    if(!qry.exec())
    {
        qDebug()<<"Query Error : "<<qry.lastError().text();
        qry.exec("ROLLBACK;");
        return;
    }
    else if(qry.next())
    {
        read_intensity=qry.value(0).toInt();
        blankval =qry.value(1).toDouble();
    }
    else
    {
        qDebug()<<"No record found for wave : "<<wavelength;
        return;
    }
    // Commit the transaction if all queries succeed
    qry.exec("COMMIT;");
    //read_intensity = intensity.toInt();
    qDebug()<<"Intensity : "<<read_intensity<<" blankval : "<<blankval;

    bc_y_val=0;
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
    clearData();
    total_read_point=5;
    current_end_read_point=0;
    ymin=absorbance-0.02;
    ymax=absorbance+0.02;
    blank_val=blankval;
    plot_end_blnk();
    readtimer->start(1000);
}

void MainWindow::plot_end_blnk()
{
    line=1;
}

void MainWindow::on_RunCal_Btn_clicked()
{
    multi_cal1=0;
    Run_Data=0;
    if(Multi_calibration==1)
    {
        ui->Stop_Btn_3->setDisabled(true);
        addColumnsToTable();
        clearGraph_cal();
        ui->stackedWidget->setCurrentIndex(30);
        ui->stackedWidget_12->setCurrentIndex(0);
        ui->label_368->setText(TestName+" - Concentration test");
        ui->label_364->setText("CALIBRATOR");
        ui->label_174->setText("B.Abs");
        ui->label_176->setText("C.Abs");
        ui->label_178->setText("C.Abs-B.Abs");
        ui->label_175->setText(ui->label_240->text());

        ui->label_174->setVisible(true);
        ui->label_175->setVisible(true);
        ui->label_176->setVisible(true);
        ui->label_177->setVisible(true);

        ui->label_178->setVisible(true);
        ui->label_179->setVisible(true);

        ui->toolButton_65->setVisible(true);
        ui->label_168->clear();
        ui->label_172->clear();
        ui->label_169->clear();
        ui->label_170->clear();
        ui->label_173->clear();
        ui->label_361->clear();
        ui->label_362->clear();
        ui->label_363->clear();
        ui->label_167->clear();

        // ui->label_173->clear();
        ui->label_177->clear();
        ui->label_179->clear();
        ui->Conc_lbl->clear();
        ui->Abs_lbl->clear();
        ui->Fact_lbl->clear();
        ui->concen_lbl->setVisible(true);
        ui->Absor_lbl->setVisible(true);
        ui->F_lbl->setVisible(true);
        ui->Conc_lbl->setVisible(true);
        ui->Abs_lbl->setVisible(true);
        ui->Fact_lbl->setVisible(true);

        ui->concen_lbl->setText("Conc.");
        ui->Absor_lbl->setText("Abs");
        ui->F_lbl->setText("Factor");

        QString Nostd;
        //int cal=0;
        QSqlQuery query;
        query.prepare("select * from test where name = '"+TestName+"'");
        query.exec();
        while(query.next())
        {
            // cal=query.value(16).toInt();
            Nostd=query.value(16).toString();
        }
        /*  if(cal==multi_cal1)
            ui->toolButton_39->setDisabled(false);
        else
            ui->toolButton_39->setDisabled(true);*/

        if(Nostd=="1")
        {
            ui->toolButton_57->setVisible(true);
            ui->toolButton_61->setVisible(false);
            ui->toolButton_63->setVisible(false);
            ui->toolButton_58->setVisible(false);
            ui->toolButton_60->setVisible(false);
            ui->toolButton_64->setVisible(false);
            ui->toolButton_59->setVisible(false);
            ui->toolButton_62->setVisible(false);
        }
        else if(Nostd=="2")
        {
            ui->toolButton_57->setVisible(true);
            ui->toolButton_61->setVisible(true);
            ui->toolButton_63->setVisible(false);
            ui->toolButton_58->setVisible(false);
            ui->toolButton_60->setVisible(false);
            ui->toolButton_64->setVisible(false);
            ui->toolButton_59->setVisible(false);
            ui->toolButton_62->setVisible(false);
        }
        else if(Nostd=="3")
        {
            ui->toolButton_57->setVisible(true);
            ui->toolButton_61->setVisible(true);
            ui->toolButton_63->setVisible(true);
            ui->toolButton_58->setVisible(false);
            ui->toolButton_60->setVisible(false);
            ui->toolButton_64->setVisible(false);
            ui->toolButton_59->setVisible(false);
            ui->toolButton_62->setVisible(false);
        }
        else if(Nostd=="4")
        {
            ui->toolButton_57->setVisible(true);
            ui->toolButton_61->setVisible(true);
            ui->toolButton_63->setVisible(true);
            ui->toolButton_58->setVisible(true);
            ui->toolButton_60->setVisible(false);
            ui->toolButton_64->setVisible(false);
            ui->toolButton_59->setVisible(false);
            ui->toolButton_62->setVisible(false);
        }
        else if(Nostd=="5")
        {
            ui->toolButton_57->setVisible(true);
            ui->toolButton_61->setVisible(true);
            ui->toolButton_63->setVisible(true);
            ui->toolButton_58->setVisible(true);
            ui->toolButton_60->setVisible(true);
            ui->toolButton_64->setVisible(false);
            ui->toolButton_59->setVisible(false);
            ui->toolButton_62->setVisible(false);
        }
        else if(Nostd=="6")
        {
            ui->toolButton_57->setVisible(true);
            ui->toolButton_61->setVisible(true);
            ui->toolButton_63->setVisible(true);
            ui->toolButton_58->setVisible(true);
            ui->toolButton_60->setVisible(true);
            ui->toolButton_64->setVisible(true);
            ui->toolButton_59->setVisible(false);
            ui->toolButton_62->setVisible(false);
        }
        else if(Nostd=="7")
        {
            ui->toolButton_57->setVisible(true);
            ui->toolButton_61->setVisible(true);
            ui->toolButton_63->setVisible(true);
            ui->toolButton_58->setVisible(true);
            ui->toolButton_60->setVisible(true);
            ui->toolButton_64->setVisible(true);
            ui->toolButton_59->setVisible(true);
            ui->toolButton_62->setVisible(false);
        }
        else if(Nostd=="8")
        {
            ui->toolButton_57->setVisible(true);
            ui->toolButton_61->setVisible(true);
            ui->toolButton_63->setVisible(true);
            ui->toolButton_58->setVisible(true);
            ui->toolButton_60->setVisible(true);
            ui->toolButton_64->setVisible(true);
            ui->toolButton_59->setVisible(true);
            ui->toolButton_62->setVisible(true);
        }
    }
    else if(Multi_calibration==2)
    {
        chk=2;
        endruncal=1;
        option=2;
        line=2;
        ui->label_106->clear();
        ui->label_12->clear();
        ui->label_32->clear();
        ui->label_121->clear();
        ui->label_123->clear();
        ui->label_125->clear();
        ui->label_120->clear();
        ui->label_122->clear();
        ui->label_194->clear();
        ui->label_195->clear();
        ui->label_198->clear();
        clearGraph_end();
        CountBackfunc=1;
        endpointsavebtn=0;
        ui->Home_Btn_3->setVisible(true);
        ui->Home_Btn_3->setDisabled(true);
        ui->Stop_Btn->setVisible(false);
        ui->Stop_Btn_2->setVisible(true);
        ui->Stop_Btn->setEnabled(false);
        ui->Stop_Btn_2->setEnabled(true);
        ui->label_34->clear();
        ui->label_224->clear();
        ui->label_75->clear();
        ui->label_33->clear();
        ui->label_7->setVisible(false);
        ui->label_196->clear();
        ui->label_225->clear();
        ui->label_204->setVisible(false);
        ui->label_203->setVisible(false);
        ui->label_6->setVisible(false);
        ui->label_100->setText("Abs");
        ui->label_207->setVisible(true);
        ui->label_75->setVisible(true);
        ui->label_208->setVisible(false);
        ui->label_209->setVisible(false);
        ui->label_196->setVisible(false);
        ui->label_197->setVisible(false);
        ui->label_76->setVisible(false);
        ui->label_224->setVisible(true);
        ui->label_225->setVisible(true);
        ui->label_226->setText("Abs");
        ui->label_226->setVisible(true);
        ui->label_227->setVisible(true);
        ui->RunBlank_Btn->setDisabled(true);
        ui->RunCal_Btn->setDisabled(true);
        ui->E_QC_Check->setDisabled(true);
        ui->RunSample_Btn->setDisabled(true);
        ui->Retest->setDisabled(true);
        ui->Retest_3->setDisabled(true);
        ui->Retest_4->setDisabled(true);
        ui->comboBox->setDisabled(true);
        ui->Retest_5->setDisabled(true);
        ui->Save_Btn_5->setVisible(true);
        ui->Save_Btn_5->setDisabled(true);
        ui->label_241->setVisible(false);
        ui->label_242->setVisible(false);
        ui->Print_Btn->setDisabled(true);
        conditioncheck();//Pro_Code_Check();
    }
}

void MainWindow::endcalibrate()
{
    option=2;
    QString wavelength , intensity ;
    double blankval = 0 ;
    double  con1 = 0;
    QSqlQuery query;
    query.exec("BEGIN TRANSACTION;");
    query.prepare("select wave,con1 from test where name = :name");
    query.bindValue(":name",TestName);
    if(!query.exec())
    {
        qDebug()<<"Query Error : "<<query.lastError().text();
        query.exec("ROLLBACK;");
        return;
    }
    else if(query.next())
    {
        wavelength=query.value(0).toString();
        con1=query.value(1).toDouble();
    }
    else
    {
        qDebug()<<"No record found for Testname : "<<TestName;
        return;
    }
    query.exec("COMMIT;");
    qDebug()<<"Wave : "<<wavelength<<" Con1 : "<<con1;

    QSqlQuery qry;
    qry.exec("BEGIN TRANSACTION;");
    qry.prepare("select intensity,blankval from tests where wave = :wave");
    qry.bindValue(":wave",wavelength);
    if(!qry.exec())
    {
        qDebug()<<"Query Error : "<<qry.lastError().text();
        qry.exec("ROLLBACK;");
        return;
    }
    else if(qry.next())
    {
        read_intensity=qry.value(0).toInt();
        blankval =qry.value(1).toDouble();
    }
    else
    {
        qDebug()<<"No record found for wave : "<<wavelength;
        return;
    }

    qry.exec("COMMIT;");
    //read_intensity = intensity.toInt();
    qDebug()<<"Intensity : "<<read_intensity<<" blankval : "<<blankval;

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
    clearData();
    total_read_point=5;
    current_end_read_point=0;
    blank_val=blankval;
    // multiFact=mulfact;
    bc_y_val=0;
    ymin=absorbance-0.02;
    ymax=absorbance+0.02;
    concen = con1;
    plot_end_calibrate();
    readtimer->start(1000);
}

void MainWindow::plot_end_calibrate()
{
    if(Multi_calibration==1)
        line=16;
    else
        line=2;
}

void MainWindow::plot_end_Recalibrate()
{
    if(Multi_calibration==1)
        line=19;
    else if(Multi_calibration==2)
        line=10;
}

void MainWindow::on_Save_Btn_5_clicked()
{
    Cal_His_Val=0;
    // Endpoint Save Btn...
    endpointsavebtn=1;
    Tname="" ; batchno="";concent="";Calib_Abs="";factor=""; dte="";
    QSqlQuery query;
    calibrate = 0 ;
    fact =0;
    CalibrateAbs = char (calibrate);
    CalibrateAbs = ui->label_224->text();
    Fact = char (fact);
    Fact = ui->label_223->text();
    Fact = ui->label_225->text();
    TestName = ui->TestName_Lbl->text();
    ui->Save_Btn_5->setDisabled(true);
    Calibration_Histry_All();
}

void MainWindow::on_RunSample_Btn_clicked()
{
    chk=2;
    option=3;
    Run_Data=0;
    endrunsamp=1;
    CountBackfunc=1;
    Fixed_Kinetic_Print=0;
    Kinetic_Print=0;
    endsavebtn=0;
    check_saveBtn=0;
    ui->label_12->clear();
    ui->label_32->clear();
    ui->label_106->clear();
    ui->label_121->clear();
    ui->label_123->clear();
    ui->label_125->clear();
    ui->label_120->clear();
    ui->label_122->clear();
    ui->label_194->clear();
    ui->label_195->clear();
    ui->label_198->clear();
    ui->Save_Btn_5->setDisabled(true);
    clearGraph_end();
    ui->pushButton_117->setDisabled(false);
    ui->PatientInfo_LineEdit->setDisabled(false);
    ui->Patient_Name_Btn->setDisabled(false);
    ui->Patient_Age_Btn->setDisabled(false);
    ui->Home_Btn_3->setVisible(true);
    ui->Home_Btn_3->setDisabled(true);
    TestName = ui->TestName_Lbl->text();
    ui->Stop_Btn->setVisible(false);
    ui->Stop_Btn_2->setVisible(true);
    ui->Stop_Btn_2->setEnabled(true);
    ui->RunBlank_Btn->setDisabled(true);
    ui->RunCal_Btn->setDisabled(true);
    ui->E_QC_Check->setDisabled(true);
    ui->RunSample_Btn->setDisabled(true);
    ui->Retest->setDisabled(true);
    ui->Retest_3->setDisabled(true);
    ui->Retest_4->setDisabled(true);
    ui->comboBox->setDisabled(true);
    ui->Retest_5->setDisabled(true);
    ui->label_6->setEnabled(true);
    ui->label_6->clear();
    ui->label_75->clear();
    ui->label_208->clear();
    ui->label_7->setVisible(true);
    ui->label_6->setVisible(true);
    ui->label_33->clear();
    ui->label_7->setText("Abs-B.Abs");
    ui->label_203->setVisible(false);
    ui->label_204->setVisible(false);
    ui->label_208->setVisible(true);
    ui->label_209->setVisible(true);
    ui->label_207->setVisible(false);
    ui->label_75->setVisible(false);
    ui->Print_Btn->setVisible(true);
    ui->Print_Btn->setDisabled(true);
    ui->radioButton_5->setDisabled(false);
    ui->radioButton_6->setDisabled(false);
    ui->radioButton_7->setDisabled(false);
    ui->pushButton_117->setDisabled(false);
    ui->Patient_Name_Btn->setDisabled(false);
    ui->Patient_Age_Btn->setDisabled(false);
    ui->EndPoint_Save_Btn->setEnabled(true);
    retestval=1;
    conditioncheck();//Pro_Code_Check();
}

void MainWindow::endsample()
{
    option=3;
    QString wavelength , intensity ;
    double blankval = 0 , fact = 0 ,   con1 = 0;

    QSqlQuery query;
    query.exec("BEGIN TRANSACTION;");
    query.prepare("select wave,fact,con1 from test where name = :name");
    query.bindValue(":name",TestName);
    if(!query.exec())
    {
        qDebug()<<"Query Error : "<<query.lastError().text();
        query.exec("ROLLBACK;");
        return;
    }
    else if(query.next())
    {
        wavelength=query.value(0).toString();
        fact=query.value(1).toDouble();
        con1=query.value(2).toDouble();
    }
    else
    {
        qDebug()<<"No record found for Name : "<<TestName;
        return;
    }
    query.exec("COMMIT;");

    qDebug()<<"Wave : "<<wavelength<<" Con1 : "<<con1;

    QSqlQuery qry;
    qry.exec("BEGIN TRANSACTION;");
    qry.prepare("select intensity,blankval from tests where wave = :wave");
    qry.bindValue(":wave",wavelength);
    if(!qry.exec())
    {
        qDebug()<<"Query Error : "<<qry.lastError().text();
        qry.exec("ROLLBACK;");
        return;
    }
    else if(qry.next())
    {
        read_intensity=qry.value(0).toInt();
        blankval =qry.value(1).toDouble();
    }
    else
    {
        qDebug()<<"No record found for wave : "<<wavelength;
        return;
    }
    qry.exec("COMMIT;");
    //read_intensity = intensity.toInt();
    qDebug()<<"Intensity : "<<read_intensity<<" blankval : "<<blankval;

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
    total_read_point=5;
    current_end_read_point=0;
    blank_val=blankval;
    concen=con1;
    fct=fact;
    qDebug()<<concen;
    bc_y_val=0;
    ymin=absorbance-0.02;
    ymax=absorbance+0.02;
    // multiFact=mulfact;
    plot_end();
    readtimer->start(1000);
}

void MainWindow::on_E_QC_Check_clicked()
{
    chk=2;
    option=12;
    Run_Data=0;
    endruncal=1;
    CountBackfunc=1;
    ui->label_12->clear();
    ui->label_32->clear();
    ui->label_106->clear();
    ui->label_121->clear();
    ui->label_123->clear();
    ui->label_125->clear();
    ui->label_120->clear();
    ui->label_122->clear();
    ui->label_194->clear();
    ui->label_195->clear();
    ui->label_198->clear();
    ui->Save_Btn_5->setDisabled(true);
    clearGraph_end();
    ui->Home_Btn_3->setVisible(true);
    ui->Home_Btn_3->setDisabled(true);
    ui->Stop_Btn->setVisible(false);
    ui->Stop_Btn_2->setVisible(true);
    ui->Stop_Btn_2->setEnabled(true);
    TestName = ui->TestName_Lbl->text();
    ui->RunBlank_Btn->setDisabled(true);
    ui->RunCal_Btn->setDisabled(true);
    ui->E_QC_Check->setDisabled(true);
    ui->RunSample_Btn->setDisabled(true);
    ui->Retest->setDisabled(true);
    ui->Retest_3->setDisabled(true);
    ui->Retest_4->setDisabled(true);
    ui->comboBox->setDisabled(true);
    ui->Retest_5->setDisabled(true);
    ui->label_6->setEnabled(true);
    ui->label_6->clear();
    ui->label_75->clear();
    ui->label_208->clear();
    ui->label_7->setVisible(false);
    ui->label_6->setVisible(false);
    ui->label_228->clear();
    ui->label_273->clear();
    ui->label_7->setText("Abs-B.ABS");
    ui->label_203->setVisible(false);
    ui->label_204->setVisible(false);
    ui->label_208->setVisible(true);
    ui->label_209->setVisible(true);
    ui->label_207->setVisible(false);
    ui->label_75->setVisible(false);
    ui->label_228->clear();
    ui->label_273->clear();
    ui->label_254->setVisible(false);
    ui->Print_Btn->setDisabled(true);

    conditioncheck();//Pro_Code_Check();


}

void MainWindow::endreqcrun()
{
    option=15;
    QString wavelength , intensity ;
    double blankval = 0  , fact = 0 ,   con1 = 0;

    QSqlQuery query;
    query.exec("BEGIN TRANSACTION;");
    query.prepare("select wave,fact,con1 from test where name = :name");
    query.bindValue(":name",TestName);
    if(!query.exec())
    {
        qDebug()<<"Query Error name : "<<query.lastError().text();
        query.exec("ROLLBACK;");
        return;
    }
    else if(query.next())
    {
        wavelength=query.value(0).toString();
        fact=query.value(1).toDouble();
        con1=query.value(2).toDouble();
    }
    else
    {
        qDebug()<<"No record found for name : "<<TestName;
        return;
    }
    query.exec("COMMIT;");

    QSqlQuery qry;
    qry.exec("BEGIN TRANSACTION;");
    qry.prepare("select intensity,blankval from tests where wave = :wavelength");
    qry.bindValue(":wavelength",wavelength);
    if(!qry.exec())
    {
        qDebug()<<"Query Error wave: "<<qry.lastError().text();
        qry.exec("ROLLBACK;");
        return;
    }
    else if(qry.next())
    {
        read_intensity=qry.value(0).toInt();
        blankval =qry.value(1).toDouble();
    }
    else
    {
        qDebug()<<"No record found for wave : "<<wavelength;
        return;
    }
    // Commit the transaction if all queries succeed
    qry.exec("COMMIT;");
    //read_intensity = intensity.toInt();

    /*int sno=1;
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
    total_read_point=5;
    current_end_read_point=0;
    blank_val=blankval;
    concen=con1;
    fct=fact;
    qDebug()<<concen;
    bc_y_val=0;
    ymin=absorbance-0.02;
    ymax=absorbance+0.02;
    // multiFact=mulfact;
    plot_endreqc();
    readtimer->start(1000);
}

void MainWindow::endqcrun()
{
    option=12;
    Run_Data=0;
    qDebug()<<"Endqcrun Enter";
    clearGraph_end();
    QString wavelength , intensity ;
    double blankval = 0 , fact = 0 ,   con1 = 0;
    QSqlQuery query;
    query.exec("BEGIN TRANSACTION;");
    query.prepare("select wave,fact,con1 from test where name = :name");
    query.bindValue(":name",TestName);
    if(!query.exec())
    {
        qDebug()<<"Query Error name: "<<query.lastError().text();
        query.exec("ROLLBACK;");
        return;
    }
    else if(query.next())
    {
        wavelength=query.value(0).toString();
        fact=query.value(1).toDouble();
        con1=query.value(2).toDouble();
    }
    else
    {
        qDebug()<<"No record found for Name : "<<TestName;
        return;
    }
    query.exec("COMMIT;");
    QSqlQuery qry;
    qry.exec("BEGIN TRANSACTION;");
    qry.prepare("select intensity,blankval from tests where wave = :wavelength");
    qry.bindValue(":wavelength",wavelength);
    if(!qry.exec())
    {
        qDebug()<<"Query Error wave: "<<qry.lastError().text();
        qry.exec("ROLLBACK;");
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
    // Commit the transaction if all queries succeed
    qry.exec("COMMIT;");

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
    total_read_point=5;
    current_end_read_point=0;
    blank_val=blankval;
    concen=con1;
    fct=fact;
    qDebug()<<concen;
    bc_y_val=0;
    ymin=absorbance-0.02;
    ymax=absorbance+0.02;
    // multiFact=mulfact;
    plot_endqc();
    readtimer->start(1000);
}

void MainWindow::clearData()
{
    qv_x.clear();
    qv_y.clear();
}

void MainWindow::plot_end()
{
    line=3;
}

void MainWindow::plot_endqc()
{
    line=12;
}

void MainWindow::plot_endreqc()
{
    line=13;
}
void MainWindow::plot_Reend()
{
    line=11;
}

void MainWindow::on_Retest_clicked()
{
    option=10;
    Run_Data=0;
    BackBlankfunc=1;
    Calreteststop=1;
    clearGraph_end();
    ui->label_12->clear();
    ui->label_32->clear();
    ui->Home_Btn_3->setVisible(true);
    ui->Home_Btn_3->setDisabled(true);
    ui->Stop_Btn->setVisible(true);
    ui->Stop_Btn->setEnabled(true);
    ui->Stop_Btn_2->setVisible(false);
    ui->Stop_Btn_2->setDisabled(true);
    TestName = ui->TestName_Lbl->text();
    ui->label_34->clear();
    ui->label_224->clear();
    ui->label_224->setVisible(true);
    ui->label_226->setVisible(true);
    ui->label_242->setVisible(false);
    ui->label_241->setVisible(false);
    ui->label_75->clear();
    ui->label_6->setVisible(true);
    ui->label_33->clear();
    ui->label_7->setVisible(false);
    ui->label_100->setVisible(false);
    ui->label_196->clear();
    ui->label_225->clear();
    ui->label_204->setVisible(false);
    ui->label_203->setVisible(false);
    ui->label_6->setVisible(false);
    ui->label_239->setText("Abs");
    ui->radioButton_5->setDisabled(false);
    ui->radioButton_6->setDisabled(false);
    ui->radioButton_7->setDisabled(false);
    ui->RunBlank_Btn->setDisabled(true);
    ui->RunCal_Btn->setDisabled(true);
    ui->E_QC_Check->setDisabled(true);
    ui->RunSample_Btn->setDisabled(true);
    ui->Save_Btn_5->setDisabled(true);
    ui->Retest->setDisabled(true);
    ui->Retest_3->setDisabled(true);
    ui->Retest_4->setDisabled(true);
    ui->comboBox->setDisabled(true);
    ui->Retest_5->setDisabled(true);
    ui->label_207->setVisible(true);
    ui->label_75->setVisible(true);
    ui->label_208->setVisible(false);
    ui->label_209->setVisible(false);
    ui->label_196->setVisible(false);
    ui->label_197->setVisible(false);
    ui->label_76->setVisible(false);
    ui->label_225->setVisible(true);
    ui->label_226->setText("Abs");
    ui->label_227->setVisible(true);
    ui->Print_Btn->setDisabled(true);

    QString wavelength , intensity ;
    double blankval = 0;
    double  con1 = 0;
    QSqlQuery query;
    query.exec("BEGIN TRANSACTION;");
    query.prepare("select wave,con1 from test where name = :name");
    query.bindValue(":name",TestName);
    if(!query.exec())
    {
        qDebug()<<"Query Error name : "<<query.lastError().text();
        query.exec("ROLLBACK;");
        return;
    }
    else if(query.next())
    {
        wavelength=query.value(0).toString();
        con1=query.value(1).toDouble();
    }
    else
    {
        qDebug()<<"No record found for Name : "<<TestName;
        return;
    }
    query.exec("COMMIT;");
    QSqlQuery qry;
    qry.exec("BEGIN TRANSACTION;");
    qry.prepare("select intensity,blankval from tests where wave = :wavelength");
    qry.bindValue(":wavelength",wavelength);
    if(!qry.exec())
    {
        qDebug()<<"Query Error wave : "<<qry.lastError().text();
        qry.exec("ROLLBACK;");
        return;
    }
    else if(qry.next())
    {
        read_intensity=qry.value(0).toInt();
        blankval =qry.value(1).toDouble();
    }
    else
    {
        qDebug()<<"No record found for wave : "<<wavelength;
        return;
    }
    // Commit the transaction if all queries succeed
    qry.exec("COMMIT;");

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
    total_read_point=5;
    current_end_read_point=0;
    blank_val=blankval;
    // multiFact=mulfact;
    bc_y_val=0;
    ymin=absorbance-0.02;
    ymax=absorbance+0.02;
    concen = con1;
    qDebug()<<con1;
    plot_end_Recalibrate();
    readtimer->start(1000);
}

void MainWindow::on_Retest_4_clicked()
{
    option=11;
    Run_Data=0;
    clearGraph_end();
    BackBlankfunc=1;
    endsavebtn=0;
    retestval=2;
    Samplereteststop=1;
    ui->label_12->clear();
    ui->label_32->clear();
    ui->EndPoint_Save_Btn->setEnabled(true);
    ui->Home_Btn_3->setVisible(true);
    ui->Home_Btn_3->setDisabled(true);
    ui->Stop_Btn_2->setVisible(false);
    ui->Stop_Btn->setVisible(true);
    ui->Stop_Btn->setEnabled(true);
    ui->Print_Btn->setDisabled(true);
    // QString TestName = ui->TestName_Lbl->text();
    ui->label_6->setEnabled(true);
    ui->label_6->clear();
    ui->label_75->clear();
    ui->label_208->clear();
    ui->label_7->setVisible(true);
    ui->label_6->setVisible(true);
    ui->label_33->clear();
    ui->label_7->setText("Abs-B.Abs");
    ui->label_203->setVisible(false);
    ui->label_204->setVisible(false);
    ui->label_208->setVisible(true);
    ui->label_209->setVisible(true);
    ui->label_207->setVisible(false);
    ui->label_75->setVisible(false);
    ui->Save_Btn_5->setDisabled(true);
    ui->RunBlank_Btn->setDisabled(true);
    ui->radioButton_5->setDisabled(false);
    ui->radioButton_6->setDisabled(false);
    ui->radioButton_7->setDisabled(false);
    ui->RunCal_Btn->setDisabled(true);
    ui->E_QC_Check->setDisabled(true);
    ui->RunSample_Btn->setDisabled(true);
    ui->Retest->setDisabled(true);
    ui->Retest_3->setDisabled(true);
    ui->Retest_4->setDisabled(true);
    ui->comboBox->setDisabled(true);
    ui->Retest_5->setDisabled(true);
    ui->Print_Btn->setDisabled(true);
    QString wavelength , intensity ;
    double blankval = 0, fact = 0 ,   con1 = 0;
    QSqlQuery query;
    query.exec("BEGIN TRANSACTION;");
    query.prepare("select wave,fact,con1 from test where name = :name");
    query.bindValue(":name",TestName);
    if(!query.exec())
    {
        qDebug()<<"Query Error : "<<query.lastError().text();
        query.exec("ROLLBACK;");
        return;
    }
    else if(query.next())
    {
        wavelength=query.value(0).toString();
        fact=query.value(1).toDouble();
        con1=query.value(2).toDouble();
    }
    else
    {
        qDebug()<<"No record found for Name : "<<TestName;
        return;
    }
    query.exec("COMMIT;");
    QSqlQuery qry;
    qry.exec("BEGIN TRANSACTION;");
    qry.prepare("select intensity,blankval from tests where wave = :wavelength");
    qry.bindValue(":wavelength",wavelength);
    if(!qry.exec())
    {
        qDebug()<<"Query Error : "<<query.lastError().text();
        qry.exec("ROLLBACK;");
        return;
    }
    else if(qry.next())
    {
        read_intensity=qry.value(0).toInt();
        blankval =qry.value(1).toDouble();
    }
    else
    {
        qDebug()<<"No record found for wave : "<<wavelength;
        return;
    }
    // Commit the transaction if all queries succeed
    qry.exec("COMMIT;");


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
    total_read_point=5;
    current_end_read_point=0;
    blank_val=blankval;
    concen=con1;
    fct=fact;
    qDebug()<<concen;
    bc_y_val=0;
    ymin=absorbance-0.02;
    ymax=absorbance+0.02;
    //multiFact=mulfact;
    plot_Reend();
    readtimer->start(1000);
}

void MainWindow::addPoints(double xx, double yy)
{
    qv_xv.append(xx);
    qv_yv.append(yy);
}

void MainWindow::addPoint(double x, double y)
{
    qv_x.append(x);
    qv_y.append(y);
    if(y<ymax)
        ymax=y;
    if(y>ymin)
        ymin=y;
    if(y>bc_y_val)
        bc_y_val=y;

    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(qv_x,qv_y);
    ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle::ssDisc);
    ui->customPlot->graph(0)->setPen(QPen(Qt::blue,1.5));
    ui->customPlot->xAxis->setLabelFont(QFont("sans", 9, QFont::Bold));
    ui->customPlot->yAxis->setLabelFont(QFont("sans", 9, QFont::Bold));
    // Darken axis line color
    QPen darkPenX(Qt::black);  // Set the pen to black
    darkPenX.setWidth(3);      // Optionally set width to make it thicker
    QPen darkPenY(Qt::black);  // Set the pen to black
    darkPenY.setWidth(1);      // Optionally set width to make it thicker
    // Apply to axis lines
    ui->customPlot->xAxis->setBasePen(darkPenX);
    ui->customPlot->yAxis->setBasePen(darkPenY);
    // ui->customPlot->graph(1)->setPen(QPen(Qt::red, 3));
    // Optionally, if you want to make the text bold or larger, you can adjust the font
    QFont font = ui->customPlot->xAxis->tickLabelFont();
    font.setBold(true);  // Make the font bold
    font.setPointSize(9);  // Optionally set a larger font size
    ui->customPlot->xAxis->setTickLabelFont(font);
    ui->customPlot->yAxis->setTickLabelFont(font);
    ui->customPlot->update();
    ui->customPlot->replot();
    if(line==1)
    {
        ui->customPlot->xAxis->setLabel("Time(S)");
        ui->customPlot->yAxis->setLabel("Abs");     // Darken axis line color
        QPen darkPenX(Qt::black);  // Set the pen to black
        darkPenX.setWidth(3);    // Optionally set width to make it thicker      // Optionally set width to make it thicker
        QPen darkPenY(Qt::black);  // Set the pen to black
        darkPenY.setWidth(1);      // Optionally set width to make it thicker
        // Apply to axis lines
        ui->customPlot->xAxis->setBasePen(darkPenX);
        ui->customPlot->yAxis->setBasePen(darkPenY);
        // set axes ranges, so we see all data:
        ui->customPlot->xAxis->setRange(1, total_read_point);
        ui->customPlot->yAxis->setRange(-0.2,2.8);
        ui->customPlot->replot();
        ui->customPlot->update();
    }
    else if(line==2)
    {
        qDebug()<<"line : "<<line;
        ui->customPlot->xAxis->setLabel("Time(S)");
        ui->customPlot->yAxis->setLabel("Abs");     // Darken axis line color
        QPen darkPenX(Qt::black);  // Set the pen to black
        darkPenX.setWidth(3);
        QPen darkPenY(Qt::black);  // Set the pen to black
        darkPenY.setWidth(1);      // Optionally set width to make it thicker      // Optionally set width to make it thicker

        // Apply to axis lines
        ui->customPlot->xAxis->setBasePen(darkPenX);
        ui->customPlot->yAxis->setBasePen(darkPenY);
        // set axes ranges, so we see all data:
        ui->customPlot->xAxis->setRange(1, total_read_point);
        ui->customPlot->yAxis->setRange(-0.2,2.8);
        ui->customPlot->replot();
        ui->customPlot->update();
        qDebug()<<"Endpoint Calibrate";
    }
    else if(line==3)
    {
        ui->customPlot->xAxis->setLabel("Time(S)");
        ui->customPlot->yAxis->setLabel("Abs");     // Darken axis line color
        QPen darkPenX(Qt::black);  // Set the pen to black
        darkPenX.setWidth(3);
        QPen darkPenY(Qt::black);  // Set the pen to black
        darkPenY.setWidth(1);      // Optionally set width to make it thicker      // Optionally set width to make it thicker

        // Apply to axis lines
        ui->customPlot->xAxis->setBasePen(darkPenX);
        ui->customPlot->yAxis->setBasePen(darkPenY);
        // set axes ranges, so we see all data:
        ui->customPlot->xAxis->setRange(1, total_read_point);
        ui->customPlot->yAxis->setRange(-0.2,2.8);
        ui->customPlot->replot();
        ui->customPlot->update();

        qDebug()<<"EndPoint Sample";
    }
    else if(line==4)
    {
        ui->customPlot->xAxis->setLabel("Time(S)");
        ui->customPlot->yAxis->setLabel("Abs");     // Darken axis line color
        QPen darkPenX(Qt::black);  // Set the pen to black
        darkPenX.setWidth(3);
        QPen darkPenY(Qt::black);  // Set the pen to black
        darkPenY.setWidth(1);      // Optionally set width to make it thicker      // Optionally set width to make it thicker

        // Apply to axis lines
        ui->customPlot->xAxis->setBasePen(darkPenX);
        ui->customPlot->yAxis->setBasePen(darkPenY);
        // set axes ranges, so we see all data:
        ui->customPlot->xAxis->setRange(1, total_read_point);
        ui->customPlot->yAxis->setRange(-0.2,2.6);
        ui->customPlot->replot();
        ui->customPlot->update();
        qDebug()<<"Twopoint blank ";
    }
    else if(line==5)
    {
        QVector<double> xv1(2);
        QVector<double> yv1(2);
        QVector<double> xv2(2);
        QVector<double> yv2(2);

        // Set the x values for the initial and final lines
        xv1[0] = xv1[1] = dly;
        xv2[0] = xv2[1] = total_read_point;

        // Set the y values based on the min and max of qv_y
        double minY = *std::min_element(qv_y.begin(), qv_y.end()) - 0.25;
        double maxY = *std::max_element(qv_y.begin(), qv_y.end()) + 0.25;
        yv1[0] = yv2[0] = minY;
        yv1[1] = yv2[1] = maxY;

        // Set axis labels and ranges
        ui->customPlot->xAxis->setLabel("Time(S)");
        ui->customPlot->yAxis->setLabel("Abs");     // Darken axis line color
        QPen darkPenX(Qt::black);  // Set the pen to black
        darkPenX.setWidth(3);
        QPen darkPenY(Qt::black);  // Set the pen to black
        darkPenY.setWidth(1);      // Optionally set width to make it thicker      // Optionally set width to make it thicker

        // Apply to axis lines
        ui->customPlot->xAxis->setBasePen(darkPenX);
        ui->customPlot->yAxis->setBasePen(darkPenY);
        // Optionally, if you want to make the text bold or larger, you can adjust the font
        QFont font = ui->customPlot->xAxis->tickLabelFont();
        font.setBold(true);  // Make the font bold
        font.setPointSize(9);  // Optionally set a larger font size
        ui->customPlot->xAxis->setTickLabelFont(font);
        ui->customPlot->yAxis->setTickLabelFont(font);

        ui->customPlot->xAxis->setRange(dly, total_read_point);
        ui->customPlot->yAxis->setRange(minY, maxY);

        // Add the initial red line
        ui->customPlot->addGraph();
        ui->customPlot->graph(1)->setPen(QPen(Qt::red, 3));
        ui->customPlot->graph(1)->setData(xv1, yv1);
        qDebug()<<"XV1 : "<<xv1<<" "<<"YV1 : "<<yv1;
        // Add the final red line
        ui->customPlot->addGraph();
        ui->customPlot->graph(2)->setPen(QPen(Qt::red, 8));
        ui->customPlot->graph(2)->setData(xv2, yv2);
        qDebug()<<"XV2 : "<<xv2<<" "<<"YV2 : "<<yv2;
        // Replot the custom plot
        ui->customPlot->replot();

        qDebug() << "Two Calibrate";
    }
    else if(line==6)
    {
        QVector<double> xv1(2);
        QVector<double> yv1(2);
        QVector<double> xv2(2);
        QVector<double> yv2(2);
        xv1[0]=xv1[1]=dly;
        xv2[0]=xv2[1]=total_read_point;
        yv1[0]=yv2[0]=*std::min_element(qv_y.begin() , qv_y.end())-0.25;
        yv1[1]=yv2[1]=*std::max_element(qv_y.begin() , qv_y.end())+0.25;
        // Clear any existing graphs to prevent overlaps
        //ui->customPlot->clearGraphs();
        //ui->customPlot->clearPlottables();

        ui->customPlot->xAxis->setLabel("Time(S)");
        ui->customPlot->yAxis->setLabel("Abs");     // Darken axis line color
        QPen darkPenX(Qt::black);  // Set the pen to black
        darkPenX.setWidth(3);
        QPen darkPenY(Qt::black);  // Set the pen to black
        darkPenY.setWidth(1);      // Optionally set width to make it thicker      // Optionally set width to make it thicker

        // Apply to axis lines
        ui->customPlot->xAxis->setBasePen(darkPenX);
        ui->customPlot->yAxis->setBasePen(darkPenY);
        // set axes ranges, so we see all data:
        ui->customPlot->xAxis->setRange(dly, total_read_point);
        ui->customPlot->yAxis->setRange(*std::min_element(qv_y.begin() , qv_y.end())-0.25,*std::max_element(qv_y.begin() , qv_y.end())+0.25);
        ui->customPlot->update();
        ui->customPlot->addGraph();
        ui->customPlot->graph(1)->setPen(QPen(Qt::red,3));
        ui->customPlot->graph(1)->setData(xv1,yv1);
        qDebug()<<"XV1 : "<<xv1<<" "<<"YV1 : "<<yv1;
        ui->customPlot->addGraph();
        ui->customPlot->graph(2)->setPen(QPen(Qt::red,8));
        ui->customPlot->graph(2)->setData(xv2,yv2);
        qDebug()<<"XV2 : "<<xv2<<" "<<"YV2 : "<<yv2;
        ui->customPlot->replot();
        qDebug()<<"Two Sample";
    }

    else if(line==7)
    {
        ui->customPlot->graph(0)->setData(qv_x,qv_y);
        ui->customPlot->xAxis->setLabel("Time(S)");
        ui->customPlot->yAxis->setLabel("Abs");     // Darken axis line color
        QPen darkPenX(Qt::black);  // Set the pen to black
        darkPenX.setWidth(3);
        QPen darkPenY(Qt::black);  // Set the pen to black
        darkPenY.setWidth(1);      // Optionally set width to make it thicker      // Optionally set width to make it thicker

        // Apply to axis lines
        ui->customPlot->xAxis->setBasePen(darkPenX);
        ui->customPlot->yAxis->setBasePen(darkPenY);
        // set axes ranges, so we see all data:
        ui->customPlot->xAxis->setRange(1, total_read_point);
        ui->customPlot->yAxis->setRange(-0.2,2.6);
        ui->customPlot->replot();
        ui->customPlot->update();
        qDebug()<<"Kinetic Blank";
    }
    else if (line==8)
    {
        QVector<double> xv1(2);
        QVector<double> yv1(2);
        QVector<double> xv2(2);
        QVector<double> yv2(2);
        QVector<double> xv3(2);
        QVector<double> yv3(2);
        QVector<double> xv4(2);
        QVector<double> yv4(2);
        xv1[0]=xv1[1]=dly;
        xv2[0]=xv2[1]=dly+(readingtime/lagg);
        xv3[0]=xv3[1]=dly+(readingtime/lagg)*2;
        xv4[0]=xv4[1]=dly+(readingtime/lagg)*3;
        yv1[0]=yv2[0]=yv3[0]=yv4[0]=*std::min_element(qv_y.begin() , qv_y.end())-0.25;
        yv1[1]=*std::max_element(qv_y.begin() , qv_y.end())+0.25;
        yv2[1]=*std::max_element(qv_y.begin() , qv_y.end())+0.25;
        yv3[1]=*std::max_element(qv_y.begin() , qv_y.end())+0.25;
        yv4[1]=*std::max_element(qv_y.begin() , qv_y.end())+0.25;
        qDebug()<<"";
        if(val==2)
        {
            // Clear any existing graphs to prevent overlaps
            //ui->customPlot->clearPlottables();
            ui->customPlot->xAxis->setLabel("Time(S)");
            ui->customPlot->yAxis->setLabel("Abs");     // Darken axis line color
            QPen darkPenX(Qt::black);  // Set the pen to black
            darkPenX.setWidth(3);QPen darkPenY(Qt::black);  // Set the pen to black
            darkPenY.setWidth(1);      // Optionally set width to make it thicker      // Optionally set width to make it thicker

            // Apply to axis lines
            ui->customPlot->xAxis->setBasePen(darkPenX);
            ui->customPlot->yAxis->setBasePen(darkPenY);
            // set axes ranges, so we see all data:
            ui->customPlot->xAxis->setRange(dly, total_read_point);
            ui->customPlot->yAxis->setRange(*std::min_element(qv_y.begin() , qv_y.end())-0.25,*std::max_element(qv_y.begin() , qv_y.end())+0.25);
            ui->customPlot->update();
            ui->customPlot->addGraph();
            ui->customPlot->graph(1)->setPen(QPen(Qt::red,3));
            ui->customPlot->graph(1)->setData(xv1,yv1);
            ui->customPlot->addGraph();
            ui->customPlot->graph(2)->setPen(QPen(Qt::red,3));
            ui->customPlot->graph(2)->setData(xv2,yv2);
            ui->customPlot->addGraph();
            ui->customPlot->graph(3)->setPen(QPen(Qt::red,8));
            ui->customPlot->graph(3)->setData(xv3,yv3);
            ui->customPlot->replot();
            qDebug()<<"XV1 : "<<xv1<<" "<<"YV1 : "<<yv1;
            qDebug()<<"XV2 : "<<xv2<<" "<<"YV2 : "<<yv2;
            qDebug()<<"XV3 : "<<xv3<<" "<<"YV3 : "<<yv3;
            qDebug()<<"Kinetic Calibrate";
        }
        else if(val==3)
        {
            ui->customPlot->xAxis->setLabel("Time(S)");
            ui->customPlot->yAxis->setLabel("Abs");     // Darken axis line color
            QPen darkPenX(Qt::black);  // Set the pen to black
            darkPenX.setWidth(3);QPen darkPenY(Qt::black);  // Set the pen to black
            darkPenY.setWidth(1);      // Optionally set width to make it thicker      // Optionally set width to make it thicker

            // Apply to axis lines
            ui->customPlot->xAxis->setBasePen(darkPenX);
            ui->customPlot->yAxis->setBasePen(darkPenY);
            // set axes ranges, so we see all data:
            ui->customPlot->xAxis->setRange(dly, total_read_point);
            ui->customPlot->yAxis->setRange(*std::min_element(qv_y.begin() , qv_y.end())-0.25,*std::max_element(qv_y.begin() , qv_y.end())+0.25);
            ui->customPlot->update();
            ui->customPlot->addGraph();
            ui->customPlot->graph(1)->setPen(QPen(Qt::red,3));
            ui->customPlot->graph(1)->setData(xv1,yv1);
            ui->customPlot->addGraph();
            ui->customPlot->graph(2)->setPen(QPen(Qt::red,3));
            ui->customPlot->graph(2)->setData(xv2,yv2);
            ui->customPlot->addGraph();
            ui->customPlot->graph(3)->setPen(QPen(Qt::red,3));
            ui->customPlot->graph(3)->setData(xv3,yv3);
            ui->customPlot->addGraph();
            ui->customPlot->graph(4)->setPen(QPen(Qt::red,8));
            ui->customPlot->graph(4)->setData(xv4,yv4);
            ui->customPlot->replot();
            qDebug()<<"XV1 : "<<xv1<<" "<<"YV1 : "<<yv1;
            qDebug()<<"XV2 : "<<xv2<<" "<<"YV2 : "<<yv2;
            qDebug()<<"XV3 : "<<xv3<<" "<<"YV3 : "<<yv3;
            qDebug()<<"XV4 : "<<xv4<<" "<<"YV4 : "<<yv4;
            qDebug()<<"Kinetic Calibaret";
        }
    }
    else if (line==9)
    {
        QVector<double> xv1(2);
        QVector<double> yv1(2);
        QVector<double> xv2(2);
        QVector<double> yv2(2);
        QVector<double> xv3(2);
        QVector<double> yv3(2);
        QVector<double> xv4(2);
        QVector<double> yv4(2);
        xv1[0]=xv1[1]=dly;
        xv2[0]=xv2[1]=dly+(readingtime/lagg);
        xv3[0]=xv3[1]=dly+(readingtime/lagg)*2;
        xv4[0]=xv4[1]=dly+(readingtime/lagg)*3;
        yv1[0]=*std::min_element(qv_y.begin() , qv_y.end())-0.25;
        yv2[0]=*std::min_element(qv_y.begin() , qv_y.end())-0.25;
        yv3[0]=*std::min_element(qv_y.begin() , qv_y.end())-0.25;
        yv4[0]=*std::min_element(qv_y.begin() , qv_y.end())-0.25;

        yv1[1]=*std::max_element(qv_y.begin() , qv_y.end())+0.25;
        yv2[1]=*std::max_element(qv_y.begin() , qv_y.end())+0.25;
        yv3[1]=*std::max_element(qv_y.begin() , qv_y.end())+0.25;
        yv4[1]=*std::max_element(qv_y.begin() , qv_y.end())+0.25;
        if(val==2)
        {
            ui->customPlot->xAxis->setLabel("Time(S)");
            ui->customPlot->yAxis->setLabel("Abs");     // Darken axis line color
            QPen darkPenX(Qt::black);  // Set the pen to black
            darkPenX.setWidth(3);QPen darkPenY(Qt::black);  // Set the pen to black
            darkPenY.setWidth(1);      // Optionally set width to make it thicker      // Optionally set width to make it thicker

            // Apply to axis lines
            ui->customPlot->xAxis->setBasePen(darkPenX);
            ui->customPlot->yAxis->setBasePen(darkPenY);
            // set axes ranges, so we see all data:
            ui->customPlot->xAxis->setRange(dly, total_read_point);
            ui->customPlot->yAxis->setRange(*std::min_element(qv_y.begin() , qv_y.end())-0.25,*std::max_element(qv_y.begin() , qv_y.end())+0.25);
            ui->customPlot->update();
            ui->customPlot->addGraph();
            ui->customPlot->graph(1)->setPen(QPen(Qt::red,3));
            ui->customPlot->graph(1)->setData(xv1,yv1);
            ui->customPlot->addGraph();
            ui->customPlot->graph(2)->setPen(QPen(Qt::red,3));
            ui->customPlot->graph(2)->setData(xv2,yv2);
            ui->customPlot->addGraph();
            ui->customPlot->graph(3)->setPen(QPen(Qt::red,8));
            ui->customPlot->graph(3)->setData(xv3,yv3);
            ui->customPlot->replot();
            qDebug()<<"XV1 : "<<xv1<<" "<<"YV1 : "<<yv1;
            qDebug()<<"XV2 : "<<xv2<<" "<<"YV2 : "<<yv2;
            qDebug()<<"XV3 : "<<xv3<<" "<<"YV3 : "<<yv3;
            qDebug()<<"Kinetic Sample";

        }
        else if(val==3)
        {
            ui->customPlot->xAxis->setLabel("Time(S)");
            ui->customPlot->yAxis->setLabel("Abs");     // Darken axis line color
            QPen darkPenX(Qt::black);  // Set the pen to black
            darkPenX.setWidth(3);QPen darkPenY(Qt::black);  // Set the pen to black
            darkPenY.setWidth(1);      // Optionally set width to make it thicker      // Optionally set width to make it thicker

            // Apply to axis lines
            ui->customPlot->xAxis->setBasePen(darkPenX);
            ui->customPlot->yAxis->setBasePen(darkPenY);
            // set axes ranges, so we see all data:
            ui->customPlot->xAxis->setRange(dly, total_read_point);
            ui->customPlot->yAxis->setRange(*std::min_element(qv_y.begin() , qv_y.end())-0.25,*std::max_element(qv_y.begin() , qv_y.end())+0.25);
            ui->customPlot->update();
            ui->customPlot->addGraph();
            ui->customPlot->graph(1)->setPen(QPen(Qt::red,3));
            ui->customPlot->graph(1)->setData(xv1,yv1);
            ui->customPlot->addGraph();
            ui->customPlot->graph(2)->setPen(QPen(Qt::red,3));
            ui->customPlot->graph(2)->setData(xv2,yv2);
            ui->customPlot->addGraph();
            ui->customPlot->graph(3)->setPen(QPen(Qt::red,3));
            ui->customPlot->graph(3)->setData(xv3,yv3);
            ui->customPlot->addGraph();
            ui->customPlot->graph(4)->setPen(QPen(Qt::red,8));
            ui->customPlot->graph(4)->setData(xv4,yv4);
            ui->customPlot->replot();
            qDebug()<<"XV1 : "<<xv1<<" "<<"YV1 : "<<yv1;
            qDebug()<<"XV2 : "<<xv2<<" "<<"YV2 : "<<yv2;
            qDebug()<<"XV3 : "<<xv3<<" "<<"YV3 : "<<yv3;
            qDebug()<<"XV4 : "<<xv4<<" "<<"YV4 : "<<yv4;
            qDebug()<<"Kinetic Sample";
        }
    }

    else if(line==10)
    {
        ui->customPlot->graph(0)->setData(qv_x,qv_y);
        ui->customPlot->xAxis->setLabel("Time(S)");
        ui->customPlot->yAxis->setLabel("Abs");     // Darken axis line color
        QPen darkPenX(Qt::black);  // Set the pen to black
        darkPenX.setWidth(3);QPen darkPenY(Qt::black);  // Set the pen to black
        darkPenY.setWidth(1);      // Optionally set width to make it thicker      // Optionally set width to make it thicker

        // Apply to axis lines
        ui->customPlot->xAxis->setBasePen(darkPenX);
        ui->customPlot->yAxis->setBasePen(darkPenY);
        // set axes ranges, so we see all data:
        ui->customPlot->xAxis->setRange(1, total_read_point);
        ui->customPlot->yAxis->setRange(-0.2,2.6);
        ui->customPlot->replot();
        ui->customPlot->update();
        // qDebug()<<"endPoint Re-Calibrate";
    }

    else if(line==11)
    {
        ui->customPlot->graph(0)->setData(qv_x,qv_y);
        ui->customPlot->xAxis->setLabel("Time(S)");
        ui->customPlot->yAxis->setLabel("Abs");     // Darken axis line color
        QPen darkPenX(Qt::black);  // Set the pen to black
        darkPenX.setWidth(3);QPen darkPenY(Qt::black);  // Set the pen to black
        darkPenY.setWidth(1);      // Optionally set width to make it thicker      // Optionally set width to make it thicker

        // Apply to axis lines
        ui->customPlot->xAxis->setBasePen(darkPenX);
        ui->customPlot->yAxis->setBasePen(darkPenY);
        // set axes ranges, so we see all data:
        ui->customPlot->xAxis->setRange(1, total_read_point);
        ui->customPlot->yAxis->setRange(-0.2,2.6);
        ui->customPlot->replot();
        ui->customPlot->update();
        // qDebug()<<"endPoint Re-Sample";
    }

    else if(line==12)
    {
        ui->customPlot->graph(0)->setData(qv_x,qv_y);
        ui->customPlot->xAxis->setLabel("Time(S)");
        ui->customPlot->yAxis->setLabel("Abs");     // Darken axis line color
        QPen darkPenX(Qt::black);  // Set the pen to black
        darkPenX.setWidth(3);QPen darkPenY(Qt::black);  // Set the pen to black
        darkPenY.setWidth(1);      // Optionally set width to make it thicker      // Optionally set width to make it thicker

        // Apply to axis lines
        ui->customPlot->xAxis->setBasePen(darkPenX);
        ui->customPlot->yAxis->setBasePen(darkPenY);
        ui->customPlot->update();
        // set axes ranges, so we see all data:
        ui->customPlot->xAxis->setRange(1, total_read_point);
        ui->customPlot->yAxis->setRange(-0.2,2.6);
        ui->customPlot->replot();
        ui->customPlot->update();
        qDebug()<<"EndQc1 Run";
    }

    else if(line==13)
    {
        ui->customPlot->graph(0)->setData(qv_x,qv_y);
        ui->customPlot->xAxis->setLabel("Time(S)");
        ui->customPlot->yAxis->setLabel("Abs");     // Darken axis line color
        QPen darkPenX(Qt::black);  // Set the pen to black
        darkPenX.setWidth(3);QPen darkPenY(Qt::black);  // Set the pen to black
        darkPenY.setWidth(1);      // Optionally set width to make it thicker      // Optionally set width to make it thicker

        // Apply to axis lines
        ui->customPlot->xAxis->setBasePen(darkPenX);
        ui->customPlot->yAxis->setBasePen(darkPenY);
        // set axes ranges, so we see all data:
        ui->customPlot->xAxis->setRange(1, total_read_point);
        ui->customPlot->yAxis->setRange(-0.2,2.6);
        ui->customPlot->replot();
        ui->customPlot->update();
        qDebug()<<"EndQC2 Run";
    }

    else if(line==14)
    {
        QVector<double> xv1(2);
        QVector<double> yv1(2);
        QVector<double> xv2(2);
        QVector<double> yv2(2);

        xv1[0]=xv1[1]=dly;
        xv2[0]=xv2[1]=total_read_point;
        yv1[0]=yv2[0]=*std::min_element(qv_y.begin() , qv_y.end())-0.25;
        yv1[1]=yv2[1]=*std::max_element(qv_y.begin() , qv_y.end())+0.25;
        // Clear any existing graphs to prevent overlaps
        //  ui->customPlot->clearPlottables();
        ui->customPlot->xAxis->setLabel("Time(S)");
        ui->customPlot->yAxis->setLabel("Abs");     // Darken axis line color
        QPen darkPenX(Qt::black);  // Set the pen to black
        darkPenX.setWidth(3);QPen darkPenY(Qt::black);  // Set the pen to black
        darkPenY.setWidth(1);      // Optionally set width to make it thicker      // Optionally set width to make it thicker

        // Apply to axis lines
        ui->customPlot->xAxis->setBasePen(darkPenX);
        ui->customPlot->yAxis->setBasePen(darkPenY);
        // set axes ranges, so we see all data:
        ui->customPlot->xAxis->setRange(dly, total_read_point);
        ui->customPlot->yAxis->setRange(*std::min_element(qv_y.begin() , qv_y.end())-0.25,*std::max_element(qv_y.begin() , qv_y.end())+0.25);
        ui->customPlot->update();
        ui->customPlot->addGraph();
        ui->customPlot->graph(1)->setPen(QPen(Qt::red,3));
        ui->customPlot->graph(1)->setData(xv1,yv1);
        ui->customPlot->addGraph();
        ui->customPlot->graph(2)->setPen(QPen(Qt::red,8));
        ui->customPlot->graph(2)->setData(xv2,yv2);
        ui->customPlot->replot();
        qDebug()<<"Two QC";
    }

    else if (line==15)
    {
        QVector<double> xv1(2);
        QVector<double> yv1(2);
        QVector<double> xv2(2);
        QVector<double> yv2(2);
        QVector<double> xv3(2);
        QVector<double> yv3(2);
        QVector<double> xv4(2);
        QVector<double> yv4(2);
        xv1[0]=xv1[1]=dly;
        xv2[0]=xv2[1]=dly+(readingtime/lagg);
        xv3[0]=xv3[1]=dly+(readingtime/lagg)*2;
        xv4[0]=xv4[1]=dly+(readingtime/lagg)*3;
        yv1[0]=*std::min_element(qv_y.begin() , qv_y.end())-0.25;
        yv2[0]=*std::min_element(qv_y.begin() , qv_y.end())-0.25;
        yv3[0]=*std::min_element(qv_y.begin() , qv_y.end())-0.25;
        yv4[0]=*std::min_element(qv_y.begin() , qv_y.end())-0.25;

        yv1[1]=*std::max_element(qv_y.begin() , qv_y.end())+0.25;
        yv2[1]=*std::max_element(qv_y.begin() , qv_y.end())+0.25;
        yv3[1]=*std::max_element(qv_y.begin() , qv_y.end())+0.25;
        yv4[1]=*std::max_element(qv_y.begin() , qv_y.end())+0.25;
        if(val==2)
        {
            //ui->customPlot->clearPlottables();
            ui->customPlot->xAxis->setLabel("Time(S)");
            ui->customPlot->yAxis->setLabel("Abs");     // Darken axis line color
            QPen darkPenX(Qt::black);  // Set the pen to black
            darkPenX.setWidth(3);QPen darkPenY(Qt::black);  // Set the pen to black
            darkPenY.setWidth(1);      // Optionally set width to make it thicker      // Optionally set width to make it thicker

            // Apply to axis lines
            ui->customPlot->xAxis->setBasePen(darkPenX);
            ui->customPlot->yAxis->setBasePen(darkPenY);
            // set axes ranges, so we see all data:
            ui->customPlot->xAxis->setRange(dly, total_read_point);
            ui->customPlot->yAxis->setRange(*std::min_element(qv_y.begin() , qv_y.end())-0.25,*std::max_element(qv_y.begin() , qv_y.end())+0.25);
            ui->customPlot->update();
            ui->customPlot->addGraph();
            ui->customPlot->graph(1)->setPen(QPen(Qt::red,3));
            ui->customPlot->graph(1)->setData(xv1,yv1);
            ui->customPlot->addGraph();
            ui->customPlot->graph(2)->setPen(QPen(Qt::red,3));
            ui->customPlot->graph(2)->setData(xv2,yv2);
            ui->customPlot->addGraph();
            ui->customPlot->graph(3)->setPen(QPen(Qt::red,8));
            ui->customPlot->graph(3)->setData(xv3,yv3);
            ui->customPlot->replot();
            qDebug()<<"Kinetic QC";

        }
        else if(val==3)
        {
            // Add the main data graph with a blue rounded pen
            ui->customPlot->xAxis->setLabel("Time(S)");
            ui->customPlot->yAxis->setLabel("Abs");     // Darken axis line color
            QPen darkPenX(Qt::black);  // Set the pen to black
            darkPenX.setWidth(3);QPen darkPenY(Qt::black);  // Set the pen to black
            darkPenY.setWidth(1);      // Optionally set width to make it thicker      // Optionally set width to make it thicker

            // Apply to axis lines
            ui->customPlot->xAxis->setBasePen(darkPenX);
            ui->customPlot->yAxis->setBasePen(darkPenY);
            // set axes ranges, so we see all data:
            ui->customPlot->xAxis->setRange(dly, total_read_point);
            ui->customPlot->yAxis->setRange(*std::min_element(qv_y.begin() , qv_y.end())-0.25,*std::max_element(qv_y.begin() , qv_y.end())+0.25);
            ui->customPlot->update();
            ui->customPlot->addGraph();
            ui->customPlot->graph(1)->setPen(QPen(Qt::red,3));
            ui->customPlot->graph(1)->setData(xv1,yv1);
            ui->customPlot->addGraph();
            ui->customPlot->graph(2)->setPen(QPen(Qt::red,3));
            ui->customPlot->graph(2)->setData(xv2,yv2);
            ui->customPlot->addGraph();
            ui->customPlot->graph(3)->setPen(QPen(Qt::red,3));
            ui->customPlot->graph(3)->setData(xv3,yv3);
            ui->customPlot->addGraph();
            ui->customPlot->graph(4)->setPen(QPen(Qt::red,8));
            ui->customPlot->graph(4)->setData(xv4,yv4);
            ui->customPlot->replot();
            qDebug()<<"Kinetic QC";
        }
    }
    else if(line==16)
    {
        ui->customPlot_4->addGraph();
        ui->customPlot_4->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
        ui->customPlot_4->graph(0)->setLineStyle(QCPGraph::lsLine);
        ui->customPlot_4->graph(0)->setPen(QPen(Qt::blue,1));
        ui->customPlot_4->graph(0)->setData(qv_x,qv_y);
        ui->customPlot_4->xAxis->setLabel("Time(S)");
        ui->customPlot_4->yAxis->setLabel("Abs");
        // set axes ranges, so we see all data:
        ui->customPlot_4->xAxis->setRange(1, total_read_point);
        ui->customPlot_4->yAxis->setRange(-0.2,2.8);
        ui->customPlot_4->replot();
        ui->customPlot_4->update();
    }
    else if(line==17)
    {
        QString TestName = ui->TestName_Lbl->text();
        QVector<double> xv1(2);
        QVector<double> yv1(2);
        QVector<double> xv2(2);
        QVector<double> yv2(2);
        xv1[0]=xv1[1]=dly;
        xv2[0]=xv2[1]=total_read_point;
        yv1[0]=yv2[0]=*std::min_element(qv_y.begin() , qv_y.end())-0.25;
        yv1[1]=yv2[1]=*std::max_element(qv_y.begin() , qv_y.end())+0.25;
        ui->customPlot_4->addGraph();
        ui->customPlot_4->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
        ui->customPlot_4->graph(0)->setLineStyle(QCPGraph::lsLine);
        ui->customPlot_4->graph(0)->setPen(QPen(Qt::blue,1));
        ui->customPlot_4->graph(0)->setData(qv_x,qv_y);

        ui->customPlot_4->xAxis->setLabel("Time(S)");
        ui->customPlot_4->yAxis->setLabel("Abs");
        // set axes ranges, so we see all data:
        ui->customPlot_4->xAxis->setRange(dly, total_read_point);
        ui->customPlot_4->yAxis->setRange(*std::min_element(qv_y.begin() , qv_y.end())-0.25,*std::max_element(qv_y.begin() , qv_y.end())+0.25);
        ui->customPlot_4->update();
        ui->customPlot_4->addGraph();
        ui->customPlot_4->graph(1)->setPen(QPen(Qt::red,3));
        ui->customPlot_4->graph(1)->setData(xv1,yv1);
        ui->customPlot_4->addGraph();
        ui->customPlot_4->graph(2)->setPen(QPen(Qt::red,8));
        ui->customPlot_4->graph(2)->setData(xv2,yv2);
        ui->customPlot_4->replot();

        qDebug()<<"Two Calibrate";
    }

    else if(line==18)
    {
        QString TestName = ui->TestName_Lbl->text();
        QVector<double> xv1(2);
        QVector<double> yv1(2);
        QVector<double> xv2(2);
        QVector<double> yv2(2);
        QVector<double> xv3(2);
        QVector<double> yv3(2);
        QVector<double> xv4(2);
        QVector<double> yv4(2);
        xv1[0]=xv1[1]=dly;
        xv2[0]=xv2[1]=dly+(readingtime/lagg);
        xv3[0]=xv3[1]=dly+(readingtime/lagg)*2;
        xv4[0]=xv4[1]=dly+(readingtime/lagg)*3;
        yv1[0]=yv2[0]=yv3[0]=yv4[0]=*std::min_element(qv_y.begin() , qv_y.end())-0.25;
        yv1[1]=*std::max_element(qv_y.begin() , qv_y.end())+0.25;
        yv2[1]=*std::max_element(qv_y.begin() , qv_y.end())+0.25;
        yv3[1]=*std::max_element(qv_y.begin() , qv_y.end())+0.25;
        yv4[1]=*std::max_element(qv_y.begin() , qv_y.end())+0.25;
        qDebug()<<"";
        if(val==2)
        {
            ui->customPlot_4->addGraph();
            ui->customPlot_4->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
            ui->customPlot_4->graph(0)->setLineStyle(QCPGraph::lsLine);
            ui->customPlot_4->graph(0)->setPen(QPen(Qt::blue,1));
            ui->customPlot_4->graph(0)->setData(qv_x,qv_y);
            ui->customPlot_4->xAxis->setLabel("Time(S)");
            ui->customPlot_4->yAxis->setLabel("Abs");
            // set axes ranges, so we see all data:
            ui->customPlot_4->xAxis->setRange(dly, total_read_point);
            ui->customPlot_4->yAxis->setRange(*std::min_element(qv_y.begin() , qv_y.end())-0.25,*std::max_element(qv_y.begin() , qv_y.end())+0.25);
            ui->customPlot_4->update();
            ui->customPlot_4->addGraph();
            ui->customPlot_4->graph(1)->setPen(QPen(Qt::red,3));
            ui->customPlot_4->graph(1)->setData(xv1,yv1);
            ui->customPlot_4->addGraph();
            ui->customPlot_4->graph(2)->setPen(QPen(Qt::red,3));
            ui->customPlot_4->graph(2)->setData(xv2,yv2);
            ui->customPlot_4->addGraph();
            ui->customPlot_4->graph(3)->setPen(QPen(Qt::red,8));
            ui->customPlot_4->graph(3)->setData(xv3,yv3);
            ui->customPlot_4->replot();
            qDebug()<<"Kinetic Calibrate";
        }
        else if(val==3)
        {
            ui->customPlot_4->addGraph();
            ui->customPlot_4->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
            ui->customPlot_4->graph(0)->setLineStyle(QCPGraph::lsLine);
            ui->customPlot_4->graph(0)->setPen(QPen(Qt::blue,1));
            ui->customPlot_4->graph(0)->setData(qv_x,qv_y);
            ui->customPlot_4->xAxis->setLabel("Time(S)");
            ui->customPlot_4->yAxis->setLabel("Abs");
            // set axes ranges, so we see all data:
            ui->customPlot_4->xAxis->setRange(dly, total_read_point);
            ui->customPlot_4->yAxis->setRange(*std::min_element(qv_y.begin() , qv_y.end())-0.25,*std::max_element(qv_y.begin() , qv_y.end())+0.25);
            ui->customPlot_4->update();
            ui->customPlot_4->addGraph();
            ui->customPlot_4->graph(1)->setPen(QPen(Qt::red,3));
            ui->customPlot_4->graph(1)->setData(xv1,yv1);
            ui->customPlot_4->addGraph();
            ui->customPlot_4->graph(2)->setPen(QPen(Qt::red,3));
            ui->customPlot_4->graph(2)->setData(xv2,yv2);
            ui->customPlot_4->addGraph();
            ui->customPlot_4->graph(3)->setPen(QPen(Qt::red,3));
            ui->customPlot_4->graph(3)->setData(xv3,yv3);
            ui->customPlot_4->addGraph();
            ui->customPlot_4->graph(4)->setPen(QPen(Qt::red,8));
            ui->customPlot_4->graph(4)->setData(xv4,yv4);
            ui->customPlot_4->replot();
            qDebug()<<"Kinetic Calibaret";
        }
    }

    else if(line==19)
    {
        ui->customPlot_4->addGraph();
        ui->customPlot_4->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
        ui->customPlot_4->graph(0)->setLineStyle(QCPGraph::lsLine);
        ui->customPlot_4->graph(0)->setPen(QPen(Qt::blue,1));
        ui->customPlot_4->graph(0)->setData(qv_x,qv_y);
        ui->customPlot_4->xAxis->setLabel("Time(S)");
        ui->customPlot_4->yAxis->setLabel("Abs");
        // set axes ranges, so we see all data:
        ui->customPlot_4->xAxis->setRange(1, total_read_point);
        ui->customPlot_4->yAxis->setRange(-0.2,2.6);
        ui->customPlot_4->replot();
        ui->customPlot_4->update();
        // qDebug()<<"endPoint Re-Calibrate";
    }

    else if(line==20)
    {
        QVector<double> xv1(2);
        QVector<double> yv1(2);
        QVector<double> xv2(2);
        QVector<double> yv2(2);
        xv1[0]=xv1[1]=0;
        xv2[0]=xv2[1]=total_read_point;
        yv1[0]=yv2[0]=*std::min_element(qv_y.begin() , qv_y.end())-0.25;
        yv1[1]=yv2[1]=*std::max_element(qv_y.begin() , qv_y.end())+0.25;

        // Plot the main graph as before
        ui->customPlot_7->addGraph();
        ui->customPlot_7->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
        ui->customPlot_7->graph(0)->setLineStyle(QCPGraph::lsLine);
        ui->customPlot_7->graph(0)->setData(qv_x, qv_y);
        ui->customPlot_7->xAxis->setLabel("Time(S)");
        ui->customPlot_7->yAxis->setLabel("Abs");

        // Set axes ranges
        ui->customPlot_7->xAxis->setRange(0, total_read_point);
        ui->customPlot_7->yAxis->setRange(*std::min_element(qv_y.begin(), qv_y.end()) - 0.25,
                                          *std::max_element(qv_y.begin(), qv_y.end()) + 0.25);

        // Add the line and scatter graphs as before
        ui->customPlot_7->addGraph();
        ui->customPlot_7->graph(1)->setPen(QPen(Qt::green, 3));
        ui->customPlot_7->graph(1)->setData(xv1, yv1);

        ui->customPlot_7->addGraph();
        ui->customPlot_7->graph(2)->setPen(QPen(Qt::red, 8));
        ui->customPlot_7->graph(2)->setData(xv2, yv2);


        // Add QCPItemText for only the first and last points in qv_x and qv_y
        if (!qv_x.isEmpty() && !qv_y.isEmpty())
        {
            // Offset value for shifting the label
           // double xOffset = 60; // Adjust this value as needed
            // Create label for the first point
            qDebug()<<"qv_x : "<<qv_x<<" "<<"qv_y : "<<qv_y<<" Current : "<<Turbi_Current_Read_Point<<"Total : "<<total_read_point;
            if(Turbi_Current_Read_Point == 0)
            {
                ui->label_567->setText(QString("(%1 , %2)").arg(read135).arg(read180));
                qDebug()<<"SetText : "<<read135<<" "<<read180;
            }
            else if(Turbi_Current_Read_Point >= total_read_point)
            {
                ui->label_568->setText(QString("(%1 , %2)").arg(Afterread135).arg(Afterread180));
                qDebug()<<"SetText : "<<Afterread135<<" "<<Afterread180;
                ui->toolButton_73->setDisabled(false);

            }
        }

        // Update and replot
        ui->customPlot_7->update();
        ui->customPlot_7->replot();

    }
}

void MainWindow::on_Print_Btn_clicked()
{
    QString PID = ui->PatientInfo_LineEdit->text();
    if(endsavebtn==1)
    {
        if(PID=="")
        {
            ui->EndPoint_Save_Btn->setEnabled(false);
            ui->pushButton_117->setDisabled(false);
            ui->Patient_Name_Btn->setDisabled(false);
            ui->Patient_Age_Btn->setDisabled(false);
            ui->radioButton_5->setDisabled(false);
            ui->radioButton_6->setDisabled(false);
            ui->radioButton_7->setDisabled(false);
            if(retestval==1)
            {
                ui->EndPoint_Print_Btn->setVisible(true);
                ui->EndPoint_Print_Btn->setEnabled(false);
                ui->radioButton_5->setDisabled(false);
                ui->radioButton_6->setDisabled(false);
                ui->radioButton_7->setDisabled(false);
            }
            else if(retestval==2)
            {
                ui->EndPoint_Print_Btn->setVisible(true);
                ui->EndPoint_Print_Btn->setEnabled(false);
                ui->radioButton_5->setDisabled(false);
                ui->radioButton_6->setDisabled(false);
                ui->radioButton_7->setDisabled(false);
            }

            ui->Home_Btn_11->setVisible(true);
            ui->Home_Btn_18->setVisible(false);
            ui->Home_Btn_19->setVisible(false);
        }
        else
        {
            ui->pushButton_117->setDisabled(true);
            ui->Patient_Name_Btn->setDisabled(true);
            ui->Patient_Age_Btn->setDisabled(true);
            ui->radioButton_5->setDisabled(true);
            ui->radioButton_6->setDisabled(true);
            ui->radioButton_7->setDisabled(true);
            if(retestval==1)
            {
                ui->EndPoint_Print_Btn->setVisible(true);
                ui->EndPoint_Print_Btn->setEnabled(true);
                ui->radioButton_5->setDisabled(true);
                ui->radioButton_6->setDisabled(true);
                ui->radioButton_7->setDisabled(true);
            }
            else if(retestval==2)
            {
                ui->EndPoint_Print_Btn->setVisible(true);
                ui->EndPoint_Print_Btn->setEnabled(true);
                ui->radioButton_5->setDisabled(true);
                ui->radioButton_6->setDisabled(true);
                ui->radioButton_7->setDisabled(true);
            }

            ui->Home_Btn_11->setVisible(true);
            ui->Home_Btn_18->setVisible(false);
            ui->Home_Btn_19->setVisible(false);
        }
    }
    else
    {
        if(PID=="")
        {
            ui->EndPoint_Save_Btn->setEnabled(false);
            ui->pushButton_117->setDisabled(false);
            ui->Patient_Name_Btn->setDisabled(false);
            ui->Patient_Age_Btn->setDisabled(false);
            ui->radioButton_5->setDisabled(false);
            ui->radioButton_6->setDisabled(false);
            ui->radioButton_7->setDisabled(false);
            if(retestval==1)
            {
                ui->EndPoint_Print_Btn->setVisible(true);
                ui->EndPoint_Print_Btn->setEnabled(false);
                ui->radioButton_5->setDisabled(false);
                ui->radioButton_6->setDisabled(false);
                ui->radioButton_7->setDisabled(false);
            }
            else if(retestval==2)
            {
                ui->EndPoint_Print_Btn->setVisible(true);
                ui->EndPoint_Print_Btn->setEnabled(false);
                ui->radioButton_5->setDisabled(false);
                ui->radioButton_6->setDisabled(false);
                ui->radioButton_7->setDisabled(false);
            }
            ui->Home_Btn_11->setVisible(true);
            ui->Home_Btn_18->setVisible(false);
            ui->Home_Btn_19->setVisible(false);
        }
        else
        {
            ui->EndPoint_Save_Btn->setEnabled(true);
            ui->pushButton_117->setDisabled(false);
            ui->Patient_Name_Btn->setDisabled(false);
            ui->Patient_Age_Btn->setDisabled(false);
            ui->radioButton_5->setDisabled(false);
            ui->radioButton_6->setDisabled(false);
            ui->radioButton_7->setDisabled(false);
            if(retestval==1)
            {
                ui->EndPoint_Print_Btn->setVisible(true);
                ui->EndPoint_Print_Btn->setEnabled(true);
                ui->radioButton_5->setDisabled(false);
                ui->radioButton_6->setDisabled(false);
                ui->radioButton_7->setDisabled(false);
            }
            else if(retestval==2)
            {
                ui->EndPoint_Print_Btn->setVisible(true);
                ui->EndPoint_Print_Btn->setEnabled(true);
                ui->radioButton_5->setDisabled(false);
                ui->radioButton_6->setDisabled(false);
                ui->radioButton_7->setDisabled(false);
            }
            ui->Home_Btn_11->setVisible(true);
            ui->Home_Btn_18->setVisible(false);
            ui->Home_Btn_19->setVisible(false);
        }
    }
    ui->stackedWidget->setCurrentIndex(17);

}
