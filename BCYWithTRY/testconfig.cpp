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

static QString arrayval[100]={""};
static QString arraylst[100]={""};
struct Pos { int row = -1, col = -1; };

//********************Test Configuration Button**************************

void MainWindow::on_toolButton_7_clicked()
{
    ui->pushButton->setEnabled(true);
    ui->stackedWidget->setCurrentIndex(3);

}

//********************Test Configuration (Add New Test)*************************
void MainWindow::on_pushButton_clicked()
{
    if(Test_Type=="Biochemistry")
    {
        ui->lineEdit_46->clear();
        ui->lineEdit_49->clear();
        ui->lineEdit_50->clear();
        ui->lineEdit_51->clear();
        ui->lineEdit_108->clear();
        ui->lineEdit_109->clear();

        ui->label_435->clear();
        ui->label_436->clear();
        ui->lineEdit_4->clear();
        ui->lineEdit_5->clear();
        ui->lineEdit_6->clear();
        ui->lineEdit_7->clear();
        ui->lineEdit_8->clear();
        ui->label_420->clear();
        ui->lineEdit_9->clear();
        ui->lineEdit_10->clear();
        ui->lineEdit_12->clear();
        ui->lineEdit_11->clear();
        ui->lineEdit_88->clear();
        ui->lineEdit_92->clear();
        ui->lineEdit_89->clear();
        ui->lineEdit_95->clear();
        ui->lineEdit_90->clear();
        ui->lineEdit_94->clear();
        ui->lineEdit_91->clear();
        ui->lineEdit_93->clear();
        ui->label_413->clear();
        ui->lineEdit_23->clear();
        ui->lineEdit_26->clear();
        ui->lineEdit_28->clear();
        ui->lineEdit_29->clear();
        ui->lineEdit_141->clear();
        ui->lineEdit_142->clear();
        ui->lineEdit_42->clear();
        ui->lineEdit_152->clear();
        ui->WaveLength_Combo->setCurrentIndex(0);
        ui->ReactionType_Combo->setCurrentIndex(0);
        ui->BlankType_Combo->setCurrentIndex(0);
        ui->pushButton_207->setEnabled(true);
        //ui->lab
        QString React = ui->ReactionType_Combo->currentText();
        if(React=="End point")
        {
            ui->pushButton_122->setDisabled(true);
            ui->pushButton_124->setDisabled(true);
        }
        else if(React == "Fixed Kinetic")
        {
            ui->pushButton_122->setDisabled(false);
            ui->pushButton_124->setDisabled(false);
        }
        else if(React == "Kinetic")
        {
            ui->pushButton_122->setDisabled(false);
            ui->pushButton_124->setDisabled(false);
        }
        qDebug()<<"Add new test";
        ui->stackedWidget->setCurrentIndex(4);
        ui->tabWidget_2->setCurrentIndex(0);
    }
    else  if(Test_Type=="Turbidity")
    {
        ui->stackedWidget->setCurrentIndex(33);
        ui->tabWidget_3->setCurrentIndex(0);
        ui->lineEdit_14->clear();
        ui->lineEdit_43->clear();
        ui->lineEdit_21->clear();
        ui->lineEdit_22->clear();
        ui->Reaction_Type->setCurrentIndex(0);
        ui->Graph_Type->setCurrentIndex(0);
        ui->lineEdit_25->clear();
        ui->lineEdit_31->clear();
        ui->lineEdit_32->clear();
        ui->lineEdit_38->clear();
        ui->lineEdit_37->clear();
        ui->comboBox_20->setCurrentIndex(0);
        ui->lineEdit_154->clear();
        ui->lineEdit_99->clear();
        ui->lineEdit_103->clear();
        ui->lineEdit_100->clear();
        ui->lineEdit_106->clear();
        ui->lineEdit_101->clear();
        ui->lineEdit_105->clear();
        ui->lineEdit_102->clear();
        ui->lineEdit_104->clear();
        ui->label_206->clear();
        ui->label_371->clear();
        ui->label_453->clear();
        ui->label_454->clear();
        ui->label_455->clear();
        ui->label_456->clear();
        ui->label_457->clear();
        ui->label_458->clear();
        ui->label_459->clear();
        ui->label_460->clear();
        ui->lineEdit_39->clear();
        ui->lineEdit_145->clear();
        ui->label_461->clear();
        ui->lineEdit_40->clear();
        ui->lineEdit_41->clear();
        ui->lineEdit_146->clear();
        ui->label_463->clear();
        ui->lineEdit_44->clear();
        QString selectedText=ui->comboBox_21->currentText();
        if(selectedText=="1")
        {
            ui->pushButton_223->setEnabled(true);
            ui->pushButton_281->setEnabled(false);
            ui->pushButton_246->setEnabled(false);
            ui->pushButton_283->setEnabled(false);
            ui->pushButton_225->setEnabled(false);
            ui->pushButton_282->setEnabled(false);
            ui->pushButton_243->setEnabled(false);
            ui->pushButton_247->setEnabled(false);
        }
        else if(selectedText=="2")
        {
            ui->pushButton_223->setEnabled(true);
            ui->pushButton_281->setEnabled(true);
            ui->pushButton_246->setEnabled(false);
            ui->pushButton_283->setEnabled(false);
            ui->pushButton_225->setEnabled(false);
            ui->pushButton_282->setEnabled(false);
            ui->pushButton_243->setEnabled(false);
            ui->pushButton_247->setEnabled(false);
        }
        else if(selectedText=="3")
        {
            ui->pushButton_223->setEnabled(true);
            ui->pushButton_281->setEnabled(true);
            ui->pushButton_246->setEnabled(true);
            ui->pushButton_283->setEnabled(false);
            ui->pushButton_225->setEnabled(false);
            ui->pushButton_282->setEnabled(false);
            ui->pushButton_243->setEnabled(false);
            ui->pushButton_247->setEnabled(false);
        }
        else if(selectedText=="4")
        {
            ui->pushButton_223->setEnabled(true);
            ui->pushButton_281->setEnabled(true);
            ui->pushButton_246->setEnabled(true);
            ui->pushButton_283->setEnabled(true);
            ui->pushButton_225->setEnabled(false);
            ui->pushButton_282->setEnabled(false);
            ui->pushButton_243->setEnabled(false);
            ui->pushButton_247->setEnabled(false);
        }
        else if(selectedText=="5")
        {
            ui->pushButton_223->setEnabled(true);
            ui->pushButton_281->setEnabled(true);
            ui->pushButton_246->setEnabled(true);
            ui->pushButton_283->setEnabled(true);
            ui->pushButton_225->setEnabled(true);
            ui->pushButton_282->setEnabled(false);
            ui->pushButton_243->setEnabled(false);
            ui->pushButton_247->setEnabled(false);
        }
        else if(selectedText=="6")
        {
            ui->pushButton_223->setEnabled(true);
            ui->pushButton_281->setEnabled(true);
            ui->pushButton_246->setEnabled(true);
            ui->pushButton_283->setEnabled(true);
            ui->pushButton_225->setEnabled(true);
            ui->pushButton_282->setEnabled(true);
            ui->pushButton_243->setEnabled(false);
            ui->pushButton_247->setEnabled(false);
        }
        else if(selectedText=="7")
        {
            ui->pushButton_223->setEnabled(true);
            ui->pushButton_281->setEnabled(true);
            ui->pushButton_246->setEnabled(true);
            ui->pushButton_283->setEnabled(true);
            ui->pushButton_225->setEnabled(true);
            ui->pushButton_282->setEnabled(true);
            ui->pushButton_243->setEnabled(true);
            ui->pushButton_247->setEnabled(false);
        }
        else if(selectedText=="8")
        {
            ui->pushButton_223->setEnabled(true);
            ui->pushButton_281->setEnabled(true);
            ui->pushButton_246->setEnabled(true);
            ui->pushButton_283->setEnabled(true);
            ui->pushButton_225->setEnabled(true);
            ui->pushButton_282->setEnabled(true);
            ui->pushButton_243->setEnabled(true);
            ui->pushButton_247->setEnabled(true);
        }
        ui->lineEdit_99->clear();
        ui->lineEdit_103->clear();
        ui->lineEdit_100->clear();
        ui->lineEdit_106->clear();
        ui->lineEdit_101->clear();
        ui->lineEdit_105->clear();
        ui->lineEdit_102->clear();
        ui->lineEdit_104->clear();
    }
}

void MainWindow::Call_Msg_box()
{
    // Set style for all line edits
    for (auto lineEdit : myLineEditsList)
        lineEdit.first->setStyleSheet("border: 1px solid red");

    // Hide specific buttons
    for (auto& buttonInfo : mypushButtonsList)
    {
        auto pushButton = buttonInfo.first;
        if (buttonInfo.second) // Check visibility flag
            pushButton->setVisible(false);
    }

    QMessageBox msg(this);
    msg.setWindowFlags(Qt::Popup);
    msg.setStyleSheet("background-color:#a0cdfa;font: 75 20pt Liberation Serif ;");
    QPixmap p(":/img/"+msgicondata+".png"); // Assuming the image is in the resource file
    auto newPixmap = p.scaled(80, 80);
    msg.setIconPixmap(newPixmap);
    msg.setText(msgboxtext);
    QPushButton* saveButton = msg.addButton("Ok", QMessageBox::AcceptRole);
    saveButton->setStyleSheet("QPushButton{background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 #34ba91, stop: 0.5 #34ba91, stop: 1 #34ba91);color:black;}QPushButton:pressed {background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(0, 85, 0), stop: 0.5 rgb(0, 85, 0), stop: 1 rgb(0, 85, 0));color:white;}");
    msg.setDefaultButton(saveButton);
    msg.exec();
    if (msg.clickedButton() == saveButton)
    {

        for (auto& buttonInfo : mypushButtonsList)
        {
            auto pushButton = buttonInfo.first;
            if (buttonInfo.second) // Check visibility flag
                pushButton->setVisible(true); // Show specific buttons
            else
                pushButton->setStyleSheet("border: 1px solid red"); // Set style sheet for other buttons
        }

        for (auto& lineEditInfo : myLineEditsList)
        {
            auto lineEdit = lineEditInfo.first;
            if (lineEditInfo.second) // Check visibility flag
                lineEdit->setStyleSheet("background-color:white; border: none"); // Set style for specific line edits
            else
                lineEdit->setVisible(true); // Show other line edits
        }

        for (auto& stackedWidgetInfo : myStackedWidgetsList)
        {
            auto stackedWidget = stackedWidgetInfo.first;
            auto index = stackedWidgetInfo.second;
            stackedWidget->setCurrentIndex(index); // Set index for specific stacked widget
        }

        for (auto& tabWidgetInfo : myTabWidgetsList)
        {
            auto tabWidget = tabWidgetInfo.first;
            auto index = tabWidgetInfo.second;
            tabWidget->setCurrentIndex(index); // Set index for specific tab widget
        }
    }
}

void MainWindow::on_Save_Btn_clicked()
{
    save_data_back=1;
    QString name, unit ,  wave,rctn,temp, fact, blnk, dely, read, lag, linmin, linmax, normin, normax;
    QString mode, nostd, rpt, con1,con2,con3,con4,con5,con6,con7,con8;
    QString ctrl1avg, ctrl1min, ctrl1max , ctrl1bno, ctrl2avg, ctrl2min,ctrl2max, ctrl2bno , Inc_Dec,TestCode , Batch_No;
    name=ui->lineEdit_4->text();
    unit=ui->lineEdit_5->text();
    wave = ui->WaveLength_Combo->currentText();
    rctn=ui->ReactionType_Combo->currentText();
    temp=ui->label_448->text();
    fact=ui->lineEdit_6->text();
    blnk=ui->BlankType_Combo->currentText();
    dely=ui->lineEdit_7->text();
    read=ui->lineEdit_8->text();
    lag=ui->label_420->text();
    linmin=ui->lineEdit_9->text();
    linmax=ui->lineEdit_10->text();
    normin=ui->lineEdit_12->text();
    normax=ui->lineEdit_11->text();
    nostd=ui->comboBox_5->currentText();
    rpt=ui->comboBox_6->currentText();
    con1=ui->lineEdit_88->text();
    con2=ui->lineEdit_92->text();
    con3=ui->lineEdit_89->text();
    con4=ui->lineEdit_95->text();
    con5=ui->lineEdit_90->text();
    con6=ui->lineEdit_94->text();
    con7=ui->lineEdit_91->text();
    con8=ui->lineEdit_93->text();
    ctrl1avg=ui->label_435->text();
    ctrl1min=ui->lineEdit_23->text();
    ctrl1max=ui->lineEdit_141->text();
    ctrl1bno=ui->lineEdit_26->text();
    ctrl2avg=ui->label_436->text();
    ctrl2min=ui->lineEdit_28->text();
    ctrl2max=ui->lineEdit_142->text();
    ctrl2bno=ui->lineEdit_29->text();
    TestCode=ui->lineEdit_42->text();
    Batch_No=ui->lineEdit_152->text();

    if(blnk=="--Select--")
        blnk="-";
    QString cmbo = ui->ReactionType_Combo->currentText();
    if(cmbo=="End point")
    {
        if(name=="")
        {
            msgboxtext="Please enter test name.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,4});
            myTabWidgetsList.append({ ui->tabWidget_2, 0 });
            mypushButtonsList.append({ ui->pushButton_118, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_4, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (TestCode=="")
        {
            msgboxtext="Please enter test code.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,4});
            myTabWidgetsList.append({ ui->tabWidget_2, 0 });
            mypushButtonsList.append({ ui->pushButton_196, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_42, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (unit=="")
        {
            msgboxtext="Please enter unit.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,4});
            myTabWidgetsList.append({ ui->tabWidget_2, 0 });
            mypushButtonsList.append({ ui->pushButton_119, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_5, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (linmin=="")
        {
            msgboxtext="Please enter linear minimum.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,4});
            myTabWidgetsList.append({ ui->tabWidget_2, 0 });
            mypushButtonsList.append({ ui->pushButton_120, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_9, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (linmax=="")
        {
            msgboxtext="Please enter linear maximum.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,4});
            myTabWidgetsList.append({ ui->tabWidget_2, 0 });
            mypushButtonsList.append({ ui->pushButton_125, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_10, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (normin=="")
        {
            msgboxtext="Please enter normal minimum.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,4});
            myTabWidgetsList.append({ ui->tabWidget_2, 0 });
            mypushButtonsList.append({ ui->pushButton_126, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_12, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (normax=="")
        {
            msgboxtext="Please enter linear minimum.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,4});
            myTabWidgetsList.append({ ui->tabWidget_2, 0 });
            mypushButtonsList.append({ ui->pushButton_127, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_11, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (Batch_No=="")
        {
            msgboxtext="Please enter lot-number.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,4});
            myTabWidgetsList.append({ ui->tabWidget_2, 1 });
            mypushButtonsList.append({ ui->pushButton_267, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_152, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (con1=="")
        {
            msgboxtext="Please enter concentration(1).";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,4});
            myTabWidgetsList.append({ ui->tabWidget_2, 1 });
            mypushButtonsList.append({ ui->pushButton_207, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_88, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (ctrl1min=="")
        {
            msgboxtext="Please enter control1 - minimum.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,4});
            myTabWidgetsList.append({ ui->tabWidget_2, 2 });
            mypushButtonsList.append({ ui->pushButton_137, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_23, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (ctrl1max=="")
        {
            msgboxtext="Please enter control1 - maximum.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,4});
            myTabWidgetsList.append({ ui->tabWidget_2, 2 });
            mypushButtonsList.append({ ui->pushButton_218, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_141, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (ctrl1bno=="")
        {
            msgboxtext="Please enter control1 - lotno.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,4});
            myTabWidgetsList.append({ ui->tabWidget_2,2 });
            mypushButtonsList.append({ ui->pushButton_138, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_26, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (ctrl2min=="")
        {
            msgboxtext="Please enter control2 - minimum.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,4});
            myTabWidgetsList.append({ ui->tabWidget_2, 2 });
            mypushButtonsList.append({ ui->pushButton_140, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_88, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (ctrl2max=="")
        {
            msgboxtext="Please enter control2 - maximum.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,4});
            myTabWidgetsList.append({ ui->tabWidget_2,2 });
            mypushButtonsList.append({ ui->pushButton_219, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_142, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (ctrl2bno=="")
        {
            msgboxtext="Please enter control2 - lotno.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,4});
            myTabWidgetsList.append({ ui->tabWidget_2, 2 });
            mypushButtonsList.append({ ui->pushButton_141, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_29, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else
            Parameter_savefunc();
    }
    else if(cmbo=="Fixed Kinetic")
    {
        if(name=="")
        {
            msgboxtext="Please enter test name.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,4});
            myTabWidgetsList.append({ ui->tabWidget_2, 0 });
            mypushButtonsList.append({ ui->pushButton_118, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_4, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (TestCode=="")
        {
            msgboxtext="Please enter test code.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,4});
            myTabWidgetsList.append({ ui->tabWidget_2, 0 });
            mypushButtonsList.append({ ui->pushButton_196, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_42, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (unit=="")
        {
            msgboxtext="Please enter unit.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,4});
            myTabWidgetsList.append({ ui->tabWidget_2, 0 });
            mypushButtonsList.append({ ui->pushButton_119, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_5, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (dely=="")
        {
            msgboxtext="Please enter dely time.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,4});
            myTabWidgetsList.append({ ui->tabWidget_2, 0 });
            mypushButtonsList.append({ ui->pushButton_124, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_7, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (read=="")
        {
            msgboxtext="Please enter incubation time(S).";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,4});
            myTabWidgetsList.append({ ui->tabWidget_2, 0 });
            mypushButtonsList.append({ ui->pushButton_122, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_8, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (linmin=="")
        {
            msgboxtext="Please enter linear min.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,4});
            myTabWidgetsList.append({ ui->tabWidget_2, 0 });
            mypushButtonsList.append({ ui->pushButton_120, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_9, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (linmax=="")
        {
            msgboxtext="Please enter linear max.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,4});
            myTabWidgetsList.append({ ui->tabWidget_2, 0 });
            mypushButtonsList.append({ ui->pushButton_120, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_10, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (normin=="")
        {
            msgboxtext="Please enter normal min.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,4});
            myTabWidgetsList.append({ ui->tabWidget_2, 0 });
            mypushButtonsList.append({ ui->pushButton_126, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_12, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (normax=="")
        {
            msgboxtext="Please enter normal max.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,4});
            myTabWidgetsList.append({ ui->tabWidget_2, 0 });
            mypushButtonsList.append({ ui->pushButton_127, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_11, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (dely=="0")
        {
            msgboxtext="Please enter correct delay time(S).";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,4});
            myTabWidgetsList.append({ ui->tabWidget_2, 0 });
            mypushButtonsList.append({ ui->pushButton_124, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_7, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (read=="0")
        {
            msgboxtext="Please enter correct incubation time(S).";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,4});
            myTabWidgetsList.append({ ui->tabWidget_2, 0 });
            mypushButtonsList.append({ ui->pushButton_122, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_8, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (Batch_No=="")
        {
            msgboxtext="Please enter lotno.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,4});
            myTabWidgetsList.append({ ui->tabWidget_2, 1 });
            mypushButtonsList.append({ ui->pushButton_267, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_152, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (con1=="")
        {
            msgboxtext="Please enter concentration(1).";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,4});
            myTabWidgetsList.append({ ui->tabWidget_2,1 });
            mypushButtonsList.append({ ui->pushButton_207, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_88, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (ctrl1min=="")
        {
            msgboxtext="Please enter control1 - minimum.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,4});
            myTabWidgetsList.append({ ui->tabWidget_2, 2 });
            mypushButtonsList.append({ ui->pushButton_137, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_23, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (ctrl1max=="")
        {
            msgboxtext="Please enter control1 - maximum.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,4});
            myTabWidgetsList.append({ ui->tabWidget_2, 2 });
            mypushButtonsList.append({ ui->pushButton_218, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_141, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (ctrl1bno=="")
        {
            msgboxtext="Please enter control1 - lotno.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,4});
            myTabWidgetsList.append({ ui->tabWidget_2, 2 });
            mypushButtonsList.append({ ui->pushButton_138, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_26, true }); // Add the specific line edit
            Call_Msg_box();
        }

        else if (ctrl2min=="")
        {
            msgboxtext="Please enter control2 - minimum.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,4});
            myTabWidgetsList.append({ ui->tabWidget_2, 2 });
            mypushButtonsList.append({ ui->pushButton_140, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_88, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (ctrl2max=="")
        {
            msgboxtext="Please enter control2 - maximum.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,4});
            myTabWidgetsList.append({ ui->tabWidget_2, 2 });
            mypushButtonsList.append({ ui->pushButton_219, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_142, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (ctrl2bno=="")
        {
            msgboxtext="Please enter control2 - lotno.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,4});
            myTabWidgetsList.append({ ui->tabWidget_2, 2 });
            mypushButtonsList.append({ ui->pushButton_141, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_29, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else
            Parameter_savefunc();
    }
    else if(cmbo=="Kinetic")
    {
        if(name=="")
        {
            msgboxtext="Please enter test name.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,4});
            myTabWidgetsList.append({ ui->tabWidget_2, 0 });
            mypushButtonsList.append({ ui->pushButton_118, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_4, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (TestCode=="")
        {
            msgboxtext="Please enter test code.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,4});
            myTabWidgetsList.append({ ui->tabWidget_2, 0 });
            mypushButtonsList.append({ ui->pushButton_196, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_42, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (unit=="")
        {
            msgboxtext="Please enter unit.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,4});
            myTabWidgetsList.append({ ui->tabWidget_2, 0 });
            mypushButtonsList.append({ ui->pushButton_119, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_5, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (dely=="")
        {
            msgboxtext="Please enter dely time.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,4});
            myTabWidgetsList.append({ ui->tabWidget_2, 0 });
            mypushButtonsList.append({ ui->pushButton_124, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_7, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (read=="")
        {
            msgboxtext="Please enter incubation time(S).";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,4});
            myTabWidgetsList.append({ ui->tabWidget_2, 0 });
            mypushButtonsList.append({ ui->pushButton_122, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_8, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (linmin=="")
        {
            msgboxtext="Please enter linear min.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,4});
            myTabWidgetsList.append({ ui->tabWidget_2, 0 });
            mypushButtonsList.append({ ui->pushButton_120, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_9, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (linmax=="")
        {
            msgboxtext="Please enter linear max.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,4});
            myTabWidgetsList.append({ ui->tabWidget_2, 0 });
            mypushButtonsList.append({ ui->pushButton_120, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_10, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (normin=="")
        {
            msgboxtext="Please enter normal min.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,4});
            myTabWidgetsList.append({ ui->tabWidget_2, 0 });
            mypushButtonsList.append({ ui->pushButton_126, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_12, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (normax=="")
        {
            msgboxtext="Please enter normal max.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,4});
            myTabWidgetsList.append({ ui->tabWidget_2, 0 });
            mypushButtonsList.append({ ui->pushButton_127, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_11, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (dely=="0")
        {
            msgboxtext="Please enter correct delay time(S).";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,4});
            myTabWidgetsList.append({ ui->tabWidget_2, 0 });
            mypushButtonsList.append({ ui->pushButton_124, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_7, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (read=="0")
        {
            msgboxtext="Please enter correct incubation time(S).";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,4});
            myTabWidgetsList.append({ ui->tabWidget_2, 0 });
            mypushButtonsList.append({ ui->pushButton_122, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_8, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (Batch_No=="")
        {
            msgboxtext="Please enter lotno.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,4});
            myTabWidgetsList.append({ ui->tabWidget_2, 1 });
            mypushButtonsList.append({ ui->pushButton_267, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_152, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (con1=="")
        {
            msgboxtext="Please enter concentration(1).";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,4});
            myTabWidgetsList.append({ ui->tabWidget_2, 1 });
            mypushButtonsList.append({ ui->pushButton_207, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_88, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (ctrl1min=="")
        {
            msgboxtext="Please enter control1 - minimum.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,4});
            myTabWidgetsList.append({ ui->tabWidget_2, 2 });
            mypushButtonsList.append({ ui->pushButton_137, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_23, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (ctrl1max=="")
        {
            msgboxtext="Please enter control1 - maximum.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,4});
            myTabWidgetsList.append({ ui->tabWidget_2, 2 });
            mypushButtonsList.append({ ui->pushButton_218, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_141, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (ctrl1bno=="")
        {
            msgboxtext="Please enter control1 - lotno.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,4});
            myTabWidgetsList.append({ ui->tabWidget_2, 2 });
            mypushButtonsList.append({ ui->pushButton_138, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_26, true }); // Add the specific line edit
            Call_Msg_box();
        }

        else if (ctrl2min=="")
        {
            msgboxtext="Please enter control2 - minimum.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,4});
            myTabWidgetsList.append({ ui->tabWidget_2, 2 });
            mypushButtonsList.append({ ui->pushButton_140, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_88, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (ctrl2max=="")
        {
            msgboxtext="Please enter control2 - maximum.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,4});
            myTabWidgetsList.append({ ui->tabWidget_2, 2 });
            mypushButtonsList.append({ ui->pushButton_219, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_142, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (ctrl2bno=="")
        {
            msgboxtext="Please enter control2 - lotno.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,4});
            myTabWidgetsList.append({ ui->tabWidget_2, 2 });
            mypushButtonsList.append({ ui->pushButton_141, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_29, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else
            Parameter_savefunc();
    }
    else
    {
        msgboxtext="Please enter valid data.";
        msgicondata="notification";
        mypushButtonsList.clear(); // Clear existing lists
        myLineEditsList.clear();
        myStackedWidgetsList.clear();
        myTabWidgetsList.clear();
        Call_Msg_box();
    }
}

void MainWindow::Parameter_savefunc()
{
    QString name, unit ,  wave,rctn,temp, fact, blnk, dely, read, lag, linmin, linmax, normin, normax;
    QString mode, nostd, rpt, con1,con2,con3,con4,con5,con6,con7,con8;
    QString ctrl1avg, ctrl1min, ctrl1max , ctrl1bno, ctrl2avg, ctrl2min,ctrl2max, ctrl2bno , Inc_Dec,TestCode , Batch_No;
    name=ui->lineEdit_4->text();
    unit=ui->lineEdit_5->text();
    wave = ui->WaveLength_Combo->currentText();
    rctn=ui->ReactionType_Combo->currentText();
    temp=ui->label_448->text();
    fact=ui->lineEdit_6->text();
    blnk=ui->BlankType_Combo->currentText();
    dely=ui->lineEdit_7->text();
    read=ui->lineEdit_8->text();
    lag=ui->label_420->text();
    linmin=ui->lineEdit_9->text();
    linmax=ui->lineEdit_10->text();
    normin=ui->lineEdit_12->text();
    normax=ui->lineEdit_11->text();
    nostd=ui->comboBox_5->currentText();
    rpt=ui->comboBox_6->currentText();
    con1=ui->lineEdit_88->text();
    con2=ui->lineEdit_92->text();
    con3=ui->lineEdit_89->text();
    con4=ui->lineEdit_95->text();
    con5=ui->lineEdit_90->text();
    con6=ui->lineEdit_94->text();
    con7=ui->lineEdit_91->text();
    con8=ui->lineEdit_93->text();
    ctrl1avg=ui->label_435->text();
    ctrl1min=ui->lineEdit_23->text();
    ctrl1max=ui->lineEdit_141->text();
    ctrl1bno=ui->lineEdit_26->text();
    ctrl2avg=ui->label_436->text();
    ctrl2min=ui->lineEdit_28->text();
    ctrl2max=ui->lineEdit_142->text();
    ctrl2bno=ui->lineEdit_29->text();
    TestCode=ui->lineEdit_42->text();
    Batch_No=ui->lineEdit_152->text();

    ui->lineEdit_4->setStyleSheet("background-color:white;border:none");
    ui->lineEdit_5->setStyleSheet("background-color:white;border:none");
    ui->lineEdit_6->setStyleSheet("background-color:white;border:none");
    ui->lineEdit_7->setStyleSheet("background-color:white;border:none");
    ui->lineEdit_8->setStyleSheet("background-color:white;border:none");
    ui->lineEdit_9->setStyleSheet("background-color:white;border:none");
    ui->lineEdit_10->setStyleSheet("background-color:white;border:none");
    ui->lineEdit_11->setStyleSheet("background-color:white;border:none");
    ui->lineEdit_12->setStyleSheet("background-color:white;border:none");
    ui->lineEdit_23->setStyleSheet("background-color:white;border:none");
    ui->lineEdit_26->setStyleSheet("background-color:white;border:none");
    ui->lineEdit_28->setStyleSheet("background-color:white;border:none");
    ui->lineEdit_29->setStyleSheet("background-color:white;border:none");
    ui->lineEdit_88->setStyleSheet("background-color:white;border:none");
    ui->lineEdit_89->setStyleSheet("background-color:white;border:none");
    ui->lineEdit_90->setStyleSheet("background-color:white;border:none");
    ui->lineEdit_91->setStyleSheet("background-color:white;border:none");
    ui->lineEdit_92->setStyleSheet("background-color:white;border:none");
    ui->lineEdit_93->setStyleSheet("background-color:white;border:none");
    ui->lineEdit_94->setStyleSheet("background-color:white;border:none");
    ui->lineEdit_95->setStyleSheet("background-color:white;border:none");
    ui->lineEdit_141->setStyleSheet("background-color:white;border:none");
    ui->lineEdit_142->setStyleSheet("background-color:white;border:none");
    ui->lineEdit_42->setStyleSheet("background-color:white;border:none");
    ui->pushButton_118->setVisible(true);
    ui->pushButton_119->setVisible(true);
    ui->pushButton_120->setVisible(true);
    ui->pushButton_122->setVisible(true);
    ui->pushButton_123->setVisible(true);
    ui->pushButton_124->setVisible(true);
    ui->pushButton_125->setVisible(true);
    ui->pushButton_126->setVisible(true);
    ui->pushButton_127->setVisible(true);
    ui->pushButton_138->setVisible(true);
    ui->pushButton_140->setVisible(true);
    ui->pushButton_141->setVisible(true);
    ui->pushButton_137->setVisible(true);

    ui->pushButton_207->setVisible(true);
    ui->pushButton_208->setVisible(true);
    ui->pushButton_209->setVisible(true);
    ui->pushButton_210->setVisible(true);
    ui->pushButton_211->setVisible(true);
    ui->pushButton_212->setVisible(true);
    ui->pushButton_213->setVisible(true);
    ui->pushButton_214->setVisible(true);
    ui->pushButton_218->setVisible(true);
    ui->pushButton_219->setVisible(true);

    QString RecentCNT="0000000";

    QSqlQuery qry;

    qry.prepare("insert into test(name,wave,rctn,unit,temp,fact,blnk,dely,read,lag,linmin,linmax,normin,normax ,nostd,rpt,con1,con2,con3,con4,con5,con6,con7,con8,"
                "ctrl1avg,ctrl1min,ctrl1max,ctrl1bno,ctrl2avg,ctrl2min,ctrl2max,ctrl2bno,Pro_Code,Batch_No,RecentCNT) values(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)");

    qry.addBindValue(name);
    qry.addBindValue(wave);
    qry.addBindValue(rctn);
    qry.addBindValue(unit);
    qry.addBindValue(temp);
    qry.addBindValue(fact);
    qry.addBindValue(blnk);
    qry.addBindValue(dely);
    qry.addBindValue(read);
    qry.addBindValue(lag);
    qry.addBindValue(linmin);
    qry.addBindValue(linmax);
    qry.addBindValue(normin);
    qry.addBindValue(normax);
    qry.addBindValue(nostd);
    qry.addBindValue(rpt);
    qry.addBindValue(con1);
    qry.addBindValue(con2);
    qry.addBindValue(con3);
    qry.addBindValue(con4);
    qry.addBindValue(con5);
    qry.addBindValue(con6);
    qry.addBindValue(con7);
    qry.addBindValue(con8);
    qry.addBindValue(ctrl1avg);
    qry.addBindValue(ctrl1min);
    qry.addBindValue(ctrl1max);
    qry.addBindValue(ctrl1bno);
    qry.addBindValue(ctrl2avg);
    qry.addBindValue(ctrl2min);
    qry.addBindValue(ctrl2max);
    qry.addBindValue(ctrl2bno);
    qry.addBindValue(TestCode);
    qry.addBindValue(Batch_No);
    qry.addBindValue(RecentCNT);
    if(qry.exec())
    {
        msgboxtext="New test added.";
        msgicondata="check-mark";
        mypushButtonsList.clear(); // Clear existing lists
        myLineEditsList.clear();
        myStackedWidgetsList.clear();
        myTabWidgetsList.clear();
        myStackedWidgetsList.append({ ui->stackedWidget,0});
        Call_Msg_box();
    }
}

//********************Test Configuration (Edit Button)**************************

void MainWindow::on_pushButton_2_clicked()
{
    if(Test_Type=="Biochemistry")
    {
        clearGridLayout(ui->gridLayout_2);
        ui->pushButton_6->setVisible(false);
        ui->pushButton_139->setVisible(false);
        ui->pushButton_142->setVisible(true);
        ui->pushButton_142->setStyleSheet("QPushButton {border: 2px solid green;border-top-left-radius:40px;border-top-right-radius:40px;background-color: white;padding: 10px;}");

        editback=1;
        exptopn=0;
        tabnumber2=1;
        qDebug()<<"Recent Btn already deleted";
        ui->Home_Lbl_2->setText("Select parameter to edit");
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


        ui->gridLayout_2->update();
        QSqlQuery query;
        query.prepare("SELECT name FROM test ORDER BY name ASC;");
        query.exec();
        int count=0;
        while(query.next())
        {
            QString s=query.value(0).toString();
            arraylst[count]=s;
            count++;
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
                                "  background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(12, 68, 145), stop: 0.5 rgb(12, 68, 145), stop:1 rgb(12, 68, 145));"
                                "  color: white;"
                                "}"
                                "QPushButton:hover {"
                                "  background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0.08, stop:0.164773 rgba(0, 214, 157, 255), stop:1 rgba(0, 214, 157, 255));""}"
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
                    connect(button, &QPushButton::clicked, this, &MainWindow::cald2);
                    ui->gridLayout_2->addWidget(button,i,j);
                }
                count1++;
            }
        }
        ui->stackedWidget->setCurrentIndex(1);

    }
    else if(Test_Type=="Turbidity")
    {
        clearGridLayout(ui->gridLayout_2);
        ui->pushButton_6->setVisible(false);
        ui->pushButton_139->setVisible(false);
        ui->pushButton_142->setVisible(true);
        ui->pushButton_142->setStyleSheet("QPushButton {border: 2px solid green;border-top-left-radius:40px;border-top-right-radius:40px;background-color: white;padding: 10px;}");

        editback=1;

        tabnumber2=1;
        ui->Home_Lbl_2->setText("Select parameter to edit");
        ui->scrollArea_7->verticalScrollBar()->setStyleSheet("QScrollBar:vertical {"
                                                             "    border: 1px solid #999999;"
                                                             "    background:white;"
                                                             "    width:25px;    "
                                                             "    margin: 0px 0px 0px 0px;"
                                                             "}"
                                                             "QScrollBar::handle:vertical {"
                                                             "   background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0.08, stop:0.164773 rgba(0, 145, 106, 255), stop:1 rgba(0, 145, 106, 255));"
                                                             "    min-height: 0px;"
                                                             "}"
                                                             "QScrollBar::add-line:vertical {"
                                                             "    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0.08, stop:0.164773 rgba(0, 145, 106, 255), stop:1 rgba(0, 145, 106, 255));"
                                                             "    height: 0px;"
                                                             "    subcontrol-position: bottom;"
                                                             "    subcontrol-origin: margin;"
                                                             "}"
                                                             "QScrollBar::sub-line:vertical {"
                                                             "    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0.08, stop:0.164773 rgba(0, 145, 106, 255), stop:1 rgba(0, 145, 106, 255));"
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
                                                                "    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0.08, stop:0.164773 rgba(0, 145, 106, 255), stop:1 rgba(0, 145, 106, 255));"
                                                                "    min-height: 0px;"
                                                                "}"
                                                                "QScrollBar::add-line:horizontal {"
                                                                "    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0.08, stop:0.164773 rgba(0, 145, 106, 255), stop:1 rgba(0, 145, 106, 255));"
                                                                "    height: 0px;"
                                                                "    subcontrol-position: bottom;"
                                                                "    subcontrol-origin: margin;"
                                                                "}"
                                                                "QScrollBar::sub-line:horizontal {"
                                                                "    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0.08, stop:0.164773 rgba(0, 145, 106, 255), stop:1 rgba(0, 145, 106, 255));"
                                                                "    height: 0 px;"
                                                                "    subcontrol-position: top;"
                                                                "    subcontrol-origin: margin;"
                                                                "}");

        ui->gridLayout_2->update();

        QSqlQuery query;
        query.prepare("SELECT TestName FROM Turbidity_test ORDER BY TestName ASC;");
        query.exec();
        int count=0;
        while(query.next())
        {
            QString s=query.value(0).toString();
            arrayval[count]=s;
            count++;
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
                    QPushButton *button = new QPushButton(arrayval[count1]);
                    button->setStyleSheet(
                                "QPushButton {"
                                "  background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0.08, stop:0.164773 rgba(0, 145, 106, 255), stop:1 rgba(0, 145, 106, 255));"
                                "  color: white;"
                                "}"
                                "QPushButton:hover {"
                                "  background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0.08, stop:0.164773 rgba(0, 214, 157, 255), stop:1 rgba(0, 214, 157, 255));}"
                                "QPushButton:disabled {"
                                "  background: rgb(170, 170, 127);"
                                "  color: black;"
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
                    button->setObjectName(arrayval[count1]);
                    connect(button, &QPushButton::clicked, this, &MainWindow::cald2);
                    ui->gridLayout_2->addWidget(button,i,j);
                }
                count1++;

                if(nextnumber3==3)
                {
                    QLayoutItem *child;
                    while ((child = ui->gridLayout_2->takeAt(Objdel)) != nullptr)
                    {

                        delete child->widget(); // delete the widget
                        delete child;   // delete the layout item
                    }
                    nextnumber3=0;
                }
            }
        }
        ui->stackedWidget->setCurrentIndex(1);
    }

}

void MainWindow::cald2()
{
    QObject *senderObj = sender(); // This will give Sender object
    QString senderObjName = senderObj->objectName();
    ui->label_16->setText(senderObjName);
    ui->label_439->setText(senderObjName);
    TestName= senderObjName;
    if(Test_Type=="Biochemistry")
    {
        QString unit;
        QSqlQuery query;
        QString  Wave ,Rctn , Blnk , Temp, Fact,Nostd ;
        double Dely=0, Read=0, Lag=0, Linmin=0, Linmax=0, Normin=0, Normax=0 , Rpt=0 , Con1=0,Con2=0,Con3=0,Con4=0,Con5=0,Con6=0,Con7=0,Con8=0,Infant_Min=0,Infant_Max=0,Child_Min=0,Child_Max=0,Female_Min=0,Female_Max=0;
        QString Mode, Ctrl1bno,Ctrl2bno,StandAbso , Inc_Dec,TestCode,Batch_No ;
        double Ctrl1avg=0, Ctrl1min=0,Ctrl1max=0, Ctrl2avg=0, Ctrl2min=0,Ctrl2max=0 ;


        QString TestName = ui->label_16->text();
        query.prepare("select * from test where name = :name");
        query.bindValue(":name",TestName);
        if(!query.exec())
        {
            qDebug()<<"Query Error : "<<query.lastError().text();
            return;
        }
        else if(query.next())
        {
            unit=query.value(4).toString();
            Wave=query.value(2).toString();
            Rctn=query.value(3).toString();
            Temp=query.value(5).toString();
            Fact=query.value(6).toString();
            Blnk=query.value(7).toString();
            Dely=query.value(8).toDouble();
            Read=query.value(9).toDouble();
            Lag=query.value(10).toDouble();
            Linmin=query.value(11).toDouble();
            Linmax=query.value(12).toDouble();
            Normin=query.value(13).toDouble();
            Normax=query.value(14).toDouble();
            Nostd=query.value(16).toString();
            Rpt=query.value(17).toDouble();
            Con1=query.value(18).toDouble();
            Con2=query.value(19).toDouble();
            Con3=query.value(20).toDouble();
            Con4=query.value(21).toDouble();
            Con5=query.value(22).toDouble();
            Con6=query.value(23).toDouble();
            Con7=query.value(24).toDouble();
            Con8=query.value(25).toDouble();
            Ctrl1avg=query.value(26).toDouble();
            Ctrl1min=query.value(27).toDouble();
            Ctrl1max=query.value(35).toDouble();
            Ctrl1bno=query.value(28).toString();
            Ctrl2avg=query.value(29).toDouble();
            Ctrl2min=query.value(30).toDouble();
            Ctrl2max=query.value(34).toDouble();
            Ctrl2bno=query.value(31).toString();
            StandAbso=query.value(33).toString();
            Inc_Dec=query.value(34).toString();
            TestCode=query.value(38).toString();
            Batch_No=query.value(39).toString();

            Infant_Min=query.value(81).toDouble();
            Infant_Max=query.value(82).toDouble();
            Child_Min=query.value(83).toDouble();
            Child_Max=query.value(84).toDouble();
            Female_Min=query.value(85).toDouble();
            Female_Max=query.value(86).toDouble();

        }
        else
        {
            qDebug()<<"No record found for Name : "<<TestName;
            return;
        }
        ui->pushButton_215->setEnabled(true);
        Prod_Code=TestCode;
        ui->lineEdit_27->setText(unit);
        ui->label_442->setText(Wave);
        ui->label_443->setText(Rctn);
        ui->label_444->setText(Temp);
        ui->lineEdit_30->setText(Fact);
        ui->label_445->setText(Blnk);

        ui->lineEdit_128->setText(QString::number(Infant_Min,'f',2));
        ui->lineEdit_129->setText(QString::number(Infant_Max,'f',2));
        ui->lineEdit_130->setText(QString::number(Child_Min,'f',2));
        ui->lineEdit_131->setText(QString::number(Child_Max,'f',2));
        ui->lineEdit_132->setText(QString::number(Female_Min,'f',2));
        ui->lineEdit_133->setText(QString::number(Female_Max,'f',2));

        ui->label_446->setText(QString::number(Dely,'f',2));
        ui->label_447->setText(QString::number(Read,'f',2));
        ui->label_413->setText(QString::number(Lag,'f',2));
        ui->lineEdit_33->setText(QString::number(Linmin,'f',2));
        ui->lineEdit_34->setText(QString::number(Linmax,'f',2));
        ui->lineEdit_36->setText(QString::number(Normin,'f',2));
        ui->lineEdit_35->setText(QString::number(Normax,'f',2));
        ui->comboBox_7->setCurrentText(Nostd);
        ui->comboBox_8->setCurrentText(QString::number(Rpt,'f',2));
        ui->lineEdit_112->setText(QString::number(Con1,'f',2));
        ui->lineEdit_116->setText(QString::number(Con2,'f',2));
        ui->lineEdit_113->setText(QString::number(Con3,'f',2));
        ui->lineEdit_119->setText(QString::number(Con4,'f',2));
        ui->lineEdit_114->setText(QString::number(Con5,'f',2));
        ui->lineEdit_118->setText(QString::number(Con6,'f',2));
        ui->lineEdit_115->setText(QString::number(Con7,'f',2));
        ui->lineEdit_117->setText(QString::number(Con8,'f',2));
        ui->label_216->setText(QString::number(Ctrl1avg,'f',2));
        ui->lineEdit_59->setText(QString::number(Ctrl1min,'f',2));
        ui->lineEdit_143->setText(QString::number(Ctrl1max,'f',2));
        ui->lineEdit_60->setText(Ctrl1bno);
        ui->label_434->setText(QString::number(Ctrl2avg,'f',2));
        ui->lineEdit_62->setText(QString::number(Ctrl2min,'f',2));
        ui->lineEdit_144->setText(QString::number(Ctrl2max,'f',2));
        ui->lineEdit_63->setText(Ctrl2bno);
        ui->label_408->setText(StandAbso);
        ui->label_441->setText(TestCode);
        ui->lineEdit_153->setText(Batch_No);

        QString React = ui->label_443->text();
        QString NoStd = ui->comboBox_7->currentText();
        qDebug()<<ui->comboBox_7->currentText();
        ui->pushButton_215->setEnabled(true) ;
        if(NoStd == "1")
        {
            ui->pushButton_234->setDisabled(true);
            ui->pushButton_238->setDisabled(true) ;
            ui->pushButton_232->setDisabled(true) ;
            ui->pushButton_237->setDisabled(true) ;
            ui->pushButton_233->setDisabled(true) ;
            ui->pushButton_235->setDisabled(true) ;
            ui->pushButton_215->setDisabled(false) ;
            ui->pushButton_236->setDisabled(true) ;
        }
        qDebug()<<"Nostd";

        QString batch , concentrate,abso, factor,dte;
        QSqlQuery qq,qq1,qq2,qq3,qq4,qq5,qq6,qq7,qq8,qq9;
        qDebug()<<"Pro Code : "<<Prod_Code;

        if(Prod_Code=="MB1011")
            Calibration_Histry_TestName="Cal_His_Glucose";
        else if(Prod_Code=="MB1021")
            Calibration_Histry_TestName="Cal_His_Glucose_HK";
        else if(Prod_Code=="MB1031")
            Calibration_Histry_TestName="Cal_His_ADA";
        else if(Prod_Code=="MB1041")
            Calibration_Histry_TestName="Cal_His_Albumin";
        else if(Prod_Code=="MB1051")
            Calibration_Histry_TestName="Cal_His_ALP";
        else if(Prod_Code=="MB1061")
            Calibration_Histry_TestName="Cal_His_Amylase";
        else if(Prod_Code=="MB1071")
            Calibration_Histry_TestName="Cal_His_Ammonia";
        else if(Prod_Code=="MB1081")
            Calibration_Histry_TestName="Cal_His_ASO";
        else if(Prod_Code=="MB1091")
            Calibration_Histry_TestName="Cal_His_ACE";
        else if(Prod_Code=="MB1101")
            Calibration_Histry_TestName="Cal_His_Bicarbonate";
        else if(Prod_Code=="MB1111")
            Calibration_Histry_TestName="Cal_His_BDirect";
        else if(Prod_Code=="MB1121")
            Calibration_Histry_TestName="Cal_His_BTotal";
        else if(Prod_Code=="MB1131")
            Calibration_Histry_TestName="Cal_His_Calcium";
        else if(Prod_Code=="MB1141")
            Calibration_Histry_TestName="Cal_His_Chloride";
        else if(Prod_Code=="MB1151")
            Calibration_Histry_TestName="Cal_His_CK_MB";
        else if(Prod_Code=="MB1161")
            Calibration_Histry_TestName="Cal_His_CK_NAC";
        else if(Prod_Code=="MB1171")
            Calibration_Histry_TestName="Cal_His_Crea_Enzy";
        else if(Prod_Code=="MB1181")
            Calibration_Histry_TestName="Cal_His_Crea_Kine";
        else if(Prod_Code=="MB1191")
            Calibration_Histry_TestName="Cal_His_Ethyl_Alco";
        else if(Prod_Code=="MB1201")
            Calibration_Histry_TestName="Cal_His_GGT";
        else if(Prod_Code=="MB1211")
            Calibration_Histry_TestName="Cal_His_AST";
        else if(Prod_Code=="MB1221")
            Calibration_Histry_TestName="Cal_His_ALT";
        else if(Prod_Code=="MB1231")
            Calibration_Histry_TestName="Cal_His_HDL_Choles";
        else if(Prod_Code=="MB1241")
            Calibration_Histry_TestName="Cal_His_Hemoglobin";
        else if(Prod_Code=="MB1251")
            Calibration_Histry_TestName="Cal_His_HCY";
        else if(Prod_Code=="MB1261")
            Calibration_Histry_TestName="Cal_His_Iron";
        else if(Prod_Code=="MB1271")
            Calibration_Histry_TestName="Cal_His_Lactate";
        else if(Prod_Code=="MB1281")
            Calibration_Histry_TestName="Cal_His_LDH";
        else if(Prod_Code=="MB1291")
            Calibration_Histry_TestName="Cal_His_LDL_Choles";
        else if(Prod_Code=="MB1301")
            Calibration_Histry_TestName="Cal_His_Lipase";
        else if(Prod_Code=="MB1311")
            Calibration_Histry_TestName="Cal_His_Magnesium";
        else if(Prod_Code=="MB1321")
            Calibration_Histry_TestName="Cal_His_Microalbumin";
        else if(Prod_Code=="MB1331")
            Calibration_Histry_TestName="Cal_His_Phospholipids";
        else if(Prod_Code=="MB1341")
            Calibration_Histry_TestName="Cal_His_Phos_UV";
        else if(Prod_Code=="MB1351")
            Calibration_Histry_TestName="Cal_His_Phos_C";
        else if(Prod_Code=="MB1361")
            Calibration_Histry_TestName="Cal_His_Potassium";
        else if(Prod_Code=="MB1371")
            Calibration_Histry_TestName="Cal_His_RF";
        else if(Prod_Code=="MB1381")
            Calibration_Histry_TestName="Cal_His_Sodium";
        else if(Prod_Code=="MB1391")
            Calibration_Histry_TestName="Cal_His_TC";
        else if(Prod_Code=="MB1401")
            Calibration_Histry_TestName="Cal_His_TP";
        else if(Prod_Code=="MB1411")
            Calibration_Histry_TestName="Cal_His_TPU_CSF";
        else if(Prod_Code=="MB1421")
            Calibration_Histry_TestName="Cal_His_TIBC";
        else if(Prod_Code=="MB1431")
            Calibration_Histry_TestName="Cal_His_Trigly";
        else if(Prod_Code=="MB1441")
            Calibration_Histry_TestName="Cal_His_Urea";
        else if(Prod_Code=="MB1451")
            Calibration_Histry_TestName="Cal_His_Uric_Acid";
        else if(Prod_Code=="MB1461")
            Calibration_Histry_TestName="Cal_His_Zinc";
        else if(Prod_Code=="MB1471")
            Calibration_Histry_TestName="Cal_His_Cholin";
        else if(Prod_Code=="MB1481")
            Calibration_Histry_TestName="Cal_His_Copper";
        else if(Prod_Code=="MB1491")
            Calibration_Histry_TestName="Cal_His_Lithium";
        else if(Prod_Code=="MB1501")
            Calibration_Histry_TestName="Cal_His_TBA";
        else if(Prod_Code=="MB1511")
            Calibration_Histry_TestName="Cal_His_UIBC";
        else if(Prod_Code=="MB1521")
            Calibration_Histry_TestName="Cal_His_GD";
        else if(Prod_Code=="MB1462")
            Calibration_Histry_TestName="Cal_His_ZINC_S";
        else if(Prod_Code=="MB1651")
            Calibration_Histry_TestName="Cal_His_MAGNESIUM_C";
        else if(Prod_Code=="MB1212")
            Calibration_Histry_TestName="Cal_His_AST_S";
        else if(Prod_Code=="MB1222")
            Calibration_Histry_TestName="Cal_His_ALT_S";
        else if(Prod_Code=="MB1052")
            Calibration_Histry_TestName="Cal_His_ALP_S";
        else if(Prod_Code=="MB1122")
            Calibration_Histry_TestName="Cal_His_BTOTAL_S";
        else if(Prod_Code=="MB1182")
            Calibration_Histry_TestName="Cal_His_CREATININE_S";

        qDebug()<<"Calibration Histry Name : "<<Calibration_Histry_TestName;
        qq.prepare("select * from "+Calibration_Histry_TestName+" where sno=1");
        qq.exec();
        while(qq.next())
        {
            batch=qq.value(2).toString();
            concentrate=qq.value(3).toString();
            abso=qq.value(4).toString();
            factor=qq.value(5).toString();
            dte=qq.value(6).toString();
        }

        ui->label_287->setText(batch);
        ui->label_288->setText(concentrate);
        ui->label_289->setText(abso);
        ui->label_290->setText(factor);
        ui->label_291->setText(dte);

        qq1.prepare("select * from "+Calibration_Histry_TestName+" where sno=2");
        qq1.exec();
        while(qq1.next())
        {
            batch=qq1.value(2).toString();
            concentrate=qq1.value(3).toString();
            abso=qq1.value(4).toString();
            factor=qq1.value(5).toString();
            dte=qq1.value(6).toString();
        }
        ui->label_296->setText(batch);
        ui->label_295->setText(concentrate);
        ui->label_294->setText(abso);
        ui->label_293->setText(factor);
        ui->label_292->setText(dte);
        qq2.prepare("select * from "+Calibration_Histry_TestName+" where sno=3");
        qq2.exec();
        while(qq2.next())
        {
            batch=qq2.value(2).toString();
            concentrate=qq2.value(3).toString();
            abso=qq2.value(4).toString();
            factor=qq2.value(5).toString();
            dte=qq2.value(6).toString();
        }
        ui->label_301->setText(batch);
        ui->label_300->setText(concentrate);
        ui->label_299->setText(abso);
        ui->label_298->setText(factor);
        ui->label_297->setText(dte);

        qq3.prepare("select * from "+Calibration_Histry_TestName+" where sno=4");
        qq3.exec();
        while(qq3.next())
        {
            batch=qq3.value(2).toString();
            concentrate=qq3.value(3).toString();
            abso=qq3.value(4).toString();
            factor=qq3.value(5).toString();
            dte=qq3.value(6).toString();
        }
        ui->label_306->setText(batch);
        ui->label_305->setText(concentrate);
        ui->label_304->setText(abso);
        ui->label_303->setText(factor);
        ui->label_302->setText(dte);

        qq4.prepare("select * from "+Calibration_Histry_TestName+" where sno=5");
        qq4.exec();
        while(qq4.next())
        {
            batch=qq4.value(2).toString();
            concentrate=qq4.value(3).toString();
            abso=qq4.value(4).toString();
            factor=qq4.value(5).toString();
            dte=qq4.value(6).toString();
        }
        ui->label_311->setText(batch);
        ui->label_310->setText(concentrate);
        ui->label_309->setText(abso);
        ui->label_308->setText(factor);
        ui->label_307->setText(dte);

        qq5.prepare("select * from "+Calibration_Histry_TestName+" where sno=6");
        qq5.exec();
        while(qq5.next())
        {
            batch=qq5.value(2).toString();
            concentrate=qq5.value(3).toString();
            abso=qq5.value(4).toString();
            factor=qq5.value(5).toString();
            dte=qq5.value(6).toString();
        }
        ui->label_316->setText(batch);
        ui->label_315->setText(concentrate);
        ui->label_314->setText(abso);
        ui->label_313->setText(factor);
        ui->label_312->setText(dte);

        qq6.prepare("select * from "+Calibration_Histry_TestName+" where sno=7");
        qq6.exec();
        while(qq6.next())
        {
            batch=qq6.value(2).toString();
            concentrate=qq6.value(3).toString();
            abso=qq6.value(4).toString();
            factor=qq6.value(5).toString();
            dte=qq6.value(6).toString();
        }
        ui->label_321->setText(batch);
        ui->label_320->setText(concentrate);
        ui->label_319->setText(abso);
        ui->label_318->setText(factor);
        ui->label_317->setText(dte);

        qq7.prepare("select * from "+Calibration_Histry_TestName+" where sno=8");
        qq7.exec();
        while(qq7.next())
        {
            batch=qq7.value(2).toString();
            concentrate=qq7.value(3).toString();
            abso=qq7.value(4).toString();
            factor=qq7.value(5).toString();
            dte=qq7.value(6).toString();
        }
        ui->label_326->setText(batch);
        ui->label_325->setText(concentrate);
        ui->label_324->setText(abso);
        ui->label_323->setText(factor);
        ui->label_322->setText(dte);

        qq8.prepare("select * from "+Calibration_Histry_TestName+" where sno=9");
        qq8.exec();
        while(qq8.next())
        {
            batch=qq8.value(2).toString();
            concentrate=qq8.value(3).toString();
            abso=qq8.value(4).toString();
            factor=qq8.value(5).toString();
            dte=qq8.value(6).toString();
        }
        ui->label_331->setText(batch);
        ui->label_330->setText(concentrate);
        ui->label_329->setText(abso);
        ui->label_328->setText(factor);
        ui->label_327->setText(dte);

        qq9.prepare("select * from "+Calibration_Histry_TestName+" where sno=10");
        qq9.exec();
        while(qq9.next())
        {
            batch=qq9.value(2).toString();
            concentrate=qq9.value(3).toString();
            abso=qq9.value(4).toString();
            factor=qq9.value(5).toString();
            dte=qq9.value(6).toString();
        }
        ui->label_336->setText(batch);
        ui->label_335->setText(concentrate);
        ui->label_334->setText(abso);
        ui->label_333->setText(factor);
        ui->label_332->setText(dte);

        ui->stackedWidget->setCurrentIndex(5);
        ui->tabWidget_4->setCurrentIndex(0);
    }
    else if(Test_Type=="Turbidity")
    {
        ui->label_540->setText(TestName);
        QString Testname, TestCode,Wave,Unit,Temp,Fact,Blank,Incubation,Graph_Type,No_of_cal,Cal1,Cal2,Cal3,Cal4,Cal5,Cal6,Cal7,Cal8,Abs1,Abs2,Abs3,Abs4,Abs5,Abs6,Abs7,Abs8,LinMin,LinMax,NorMin,NorMax,Ctrl1Avg,Ctrl1Min,Ctrl1Max,Ctrl1Bno,Ctrl2Avg,Ctrl2Min,Ctrl2Max,Ctrl2Bno,Batch_No,Reaction_typ,After_Inc,Direct_read;
        QSqlQuery qy;
        qy.prepare("select * from Turbidity_test where TestName='"+TestName+"'");
        qy.exec();
        while(qy.next())
        {
            Testname=qy.value(1).toString();
            TestCode=qy.value(2).toString();
            Wave=qy.value(3).toString();
            Unit=qy.value(4).toString();
            Temp=qy.value(5).toString();
            Fact=qy.value(6).toString();
            Blank=qy.value(7).toString();
            Incubation=qy.value(8).toString();
            Graph_Type=qy.value(9).toString();
            No_of_cal=qy.value(10).toString();
            Batch_No=qy.value(47).toString();
            Cal1=qy.value(11).toString();
            Cal2=qy.value(12).toString();
            Cal3=qy.value(13).toString();
            Cal4=qy.value(14).toString();
            Cal5=qy.value(15).toString();
            Cal6=qy.value(16).toString();
            Cal7=qy.value(17).toString();
            Cal8=qy.value(18).toString();
            Abs1=qy.value(19).toString();
            Abs2=qy.value(20).toString();
            Abs3=qy.value(21).toString();
            Abs4=qy.value(22).toString();
            Abs5=qy.value(23).toString();
            Abs6=qy.value(24).toString();
            Abs7=qy.value(25).toString();
            Abs8=qy.value(26).toString();
            Ctrl1Min=qy.value(40).toString();
            Ctrl1Max=qy.value(41).toString();
            Ctrl1Avg=qy.value(39).toString();
            Ctrl1Bno=qy.value(42).toString();
            Ctrl2Min=qy.value(44).toString();
            Ctrl2Max=qy.value(45).toString();
            Ctrl2Avg=qy.value(43).toString();
            Ctrl2Bno=qy.value(46).toString();
            LinMin=qy.value(35).toString();
            LinMax=qy.value(36).toString();
            NorMin=qy.value(37).toString();
            NorMax=qy.value(38).toString();
            Reaction_typ=qy.value(81).toString();
            After_Inc=qy.value(89).toString();
            Direct_read=qy.value(90).toString();

        }
        qDebug()<<"Data : "<<Cal1<<Cal2<<Cal3<<Cal4<<Cal5<<Cal6<<Cal7<<Cal8<<No_of_cal;

        ui->label_468->setText(Testname);
        ui->label_469->setText(TestCode);
        ui->label_470->setText(Wave);
        ui->lineEdit_47->setText(Unit);
        ui->label_471->setText(Temp);
        ui->lineEdit_48->setText(Fact);
        ui->lineEdit_61->setText(Incubation);
        ui->Graph_Type_2->setCurrentText(Graph_Type);
        ui->lineEdit_53->setText(LinMin);
        ui->lineEdit_54->setText(LinMax);
        ui->lineEdit_55->setText(NorMin);
        ui->lineEdit_56->setText(NorMax);
        ui->lineEdit_155->setText(Batch_No);
        ui->lineEdit_120->setText(Cal1);
        ui->lineEdit_124->setText(Cal2);
        ui->lineEdit_121->setText(Cal3);
        ui->lineEdit_127->setText(Cal4);
        ui->lineEdit_122->setText(Cal5);
        ui->lineEdit_126->setText(Cal6);
        ui->lineEdit_123->setText(Cal7);
        ui->lineEdit_125->setText(Cal8);
        ui->label_505->setText(Ctrl1Avg);
        ui->lineEdit_64->setText(Ctrl1Min);
        ui->lineEdit_151->setText(Ctrl1Max);
        ui->lineEdit_65->setText(Ctrl1Bno);
        ui->comboBox_21->setCurrentText(No_of_cal);
        ui->lineEdit_66->setText(Ctrl2Min);
        ui->lineEdit_156->setText(Ctrl2Max);
        ui->lineEdit_98->setText(Ctrl2Bno);
        ui->label_510->setText(Ctrl2Avg);
        ui->label_489->setText(Abs1);
        ui->label_485->setText(Abs2);
        ui->label_490->setText(Abs3);
        ui->label_491->setText(Abs4);
        ui->label_492->setText(Abs5);
        ui->label_487->setText(Abs6);
        ui->label_488->setText(Abs7);
        ui->label_486->setText(Abs8);
        ui->lineEdit_173->setText(After_Inc);
        ui->lineEdit_171->setText(Direct_read);
        ui->Reaction_Type_2->setCurrentText(Reaction_typ);
        qDebug()<<ui->lineEdit_120->text()<<"" <<ui->lineEdit_124->text();
        qDebug()<<ui->lineEdit_121->text()<<"" <<ui->lineEdit_127->text();
        qDebug()<<ui->lineEdit_122->text()<<"" <<ui->lineEdit_126->text();
        qDebug()<<ui->lineEdit_123->text()<<"" <<ui->lineEdit_125->text();
        if(No_of_cal=="1")
        {
            qDebug()<<"No of cal : 1";
            ui->pushButton_307->setEnabled(true);
            ui->pushButton_313->setEnabled(false);
            ui->pushButton_311->setEnabled(false);
            ui->pushButton_317->setEnabled(false);
            ui->pushButton_308->setEnabled(false);
            ui->pushButton_314->setEnabled(false);
            ui->pushButton_310->setEnabled(false);
            ui->pushButton_312->setEnabled(false);
            ui->lineEdit_120->setText(Cal1);
            ui->lineEdit_124->clear();
            ui->lineEdit_121->clear();
            ui->lineEdit_127->clear();
            ui->lineEdit_122->clear();
            ui->lineEdit_126->clear();
            ui->lineEdit_123->clear();
            ui->lineEdit_125->clear();
        }
        else if(No_of_cal=="2")
        {
            qDebug()<<"No of cal : 2";
            ui->pushButton_307->setEnabled(true);
            ui->pushButton_313->setEnabled(true);
            ui->pushButton_311->setEnabled(false);
            ui->pushButton_317->setEnabled(false);
            ui->pushButton_308->setEnabled(false);
            ui->pushButton_314->setEnabled(false);
            ui->pushButton_310->setEnabled(false);
            ui->pushButton_312->setEnabled(false);
            ui->lineEdit_120->setText(Cal1);
            ui->lineEdit_124->setText(Cal2);
            ui->lineEdit_121->clear();
            ui->lineEdit_127->clear();
            ui->lineEdit_122->clear();
            ui->lineEdit_126->clear();
            ui->lineEdit_123->clear();
            ui->lineEdit_125->clear();
        }
        else if(No_of_cal=="3")
        {
            qDebug()<<"No of cal : 3";
            ui->pushButton_307->setEnabled(true);
            ui->pushButton_313->setEnabled(true);
            ui->pushButton_311->setEnabled(true);
            ui->pushButton_317->setEnabled(false);
            ui->pushButton_308->setEnabled(false);
            ui->pushButton_314->setEnabled(false);
            ui->pushButton_310->setEnabled(false);
            ui->pushButton_312->setEnabled(false);
            ui->lineEdit_120->setText(Cal1);
            ui->lineEdit_124->setText(Cal2);
            ui->lineEdit_121->setText(Cal3);
            ui->lineEdit_127->clear();
            ui->lineEdit_122->clear();
            ui->lineEdit_126->clear();
            ui->lineEdit_123->clear();
            ui->lineEdit_125->clear();
        }
        else if(No_of_cal=="4")
        {
            qDebug()<<"No of cal : 4";
            ui->pushButton_307->setEnabled(true);
            ui->pushButton_313->setEnabled(true);
            ui->pushButton_311->setEnabled(true);
            ui->pushButton_317->setEnabled(true);
            ui->pushButton_308->setEnabled(false);
            ui->pushButton_314->setEnabled(false);
            ui->pushButton_310->setEnabled(false);
            ui->pushButton_312->setEnabled(false);
            ui->lineEdit_120->setText(Cal1);
            ui->lineEdit_124->setText(Cal2);
            ui->lineEdit_121->setText(Cal3);
            ui->lineEdit_127->setText(Cal4);
            ui->lineEdit_122->clear();
            ui->lineEdit_126->clear();
            ui->lineEdit_123->clear();
            ui->lineEdit_125->clear();
        }
        else if(No_of_cal=="5")
        {
            qDebug()<<"No of cal : 5";
            ui->pushButton_307->setEnabled(true);
            ui->pushButton_313->setEnabled(true);
            ui->pushButton_311->setEnabled(true);
            ui->pushButton_317->setEnabled(true);
            ui->pushButton_308->setEnabled(true);
            ui->pushButton_314->setEnabled(false);
            ui->pushButton_310->setEnabled(false);
            ui->pushButton_312->setEnabled(false);
            ui->lineEdit_120->setText(Cal1);
            ui->lineEdit_124->setText(Cal2);
            ui->lineEdit_121->setText(Cal3);
            ui->lineEdit_127->setText(Cal4);
            ui->lineEdit_122->setText(Cal5);
            ui->lineEdit_126->clear();
            ui->lineEdit_123->clear();
            ui->lineEdit_125->clear();
        }
        else if(No_of_cal=="6")
        {
            qDebug()<<"No of cal : 6";
            ui->pushButton_307->setEnabled(true);
            ui->pushButton_313->setEnabled(true);
            ui->pushButton_311->setEnabled(true);
            ui->pushButton_317->setEnabled(true);
            ui->pushButton_308->setEnabled(true);
            ui->pushButton_314->setEnabled(true);
            ui->pushButton_310->setEnabled(false);
            ui->pushButton_312->setEnabled(false);
            ui->lineEdit_120->setText(Cal1);
            ui->lineEdit_124->setText(Cal2);
            ui->lineEdit_121->setText(Cal3);
            ui->lineEdit_127->setText(Cal4);
            ui->lineEdit_122->setText(Cal5);
            ui->lineEdit_126->setText(Cal6);
            ui->lineEdit_123->clear();
            ui->lineEdit_125->clear();
        }
        else if(No_of_cal=="7")
        {
            qDebug()<<"No of cal : 7";
            ui->pushButton_307->setEnabled(true);
            ui->pushButton_313->setEnabled(true);
            ui->pushButton_311->setEnabled(true);
            ui->pushButton_317->setEnabled(true);
            ui->pushButton_308->setEnabled(true);
            ui->pushButton_314->setEnabled(true);
            ui->pushButton_310->setEnabled(true);
            ui->pushButton_312->setEnabled(false);
            ui->lineEdit_120->setText(Cal1);
            ui->lineEdit_124->setText(Cal2);
            ui->lineEdit_121->setText(Cal3);
            ui->lineEdit_127->setText(Cal4);
            ui->lineEdit_122->setText(Cal5);
            ui->lineEdit_126->setText(Cal6);
            ui->lineEdit_123->setText(Cal7);
            ui->lineEdit_125->clear();
        }
        else if(No_of_cal=="8")
        {
            qDebug()<<"No of cal : 8";
            ui->pushButton_307->setEnabled(true);
            ui->pushButton_313->setEnabled(true);
            ui->pushButton_311->setEnabled(true);
            ui->pushButton_317->setEnabled(true);
            ui->pushButton_308->setEnabled(true);
            ui->pushButton_314->setEnabled(true);
            ui->pushButton_310->setEnabled(true);
            ui->pushButton_312->setEnabled(true);
            ui->lineEdit_120->setText(Cal1);
            ui->lineEdit_124->setText(Cal2);
            ui->lineEdit_121->setText(Cal3);
            ui->lineEdit_127->setText(Cal4);
            ui->lineEdit_122->setText(Cal5);
            ui->lineEdit_126->setText(Cal6);
            ui->lineEdit_123->setText(Cal7);
            ui->lineEdit_125->setText(Cal8);
        }
        ui->stackedWidget->setCurrentIndex(34);
        ui->tabWidget_5->setCurrentIndex(0);
    }
}


void MainWindow::on_Update_Btn_clicked()
{
    update_data_back=1;
    QString name, unit;
    QSqlQuery query;
    QSqlQuery qry;

    QString  Fact, Wave, Rctn ,  Temp,Blnk, Dely, Read, Lag, Linmin, Linmax, Normin, Normax;
    QString Mode, Nostd, Rpt, Con1,Con2,Con3,Con4,Con5,Con6,Con7,Con8;
    QString Ctrl1avg, Ctrl1min,Ctrl1max, Ctrl1bno, Ctrl2avg, Ctrl2min,Ctrl2max, Ctrl2bno , Inc_Dec , TestCode,Batch_No;
    QString Infant_Min,Infant_Max,Child_Min,Child_Max,Female_Min,Female_Max;

    int wave = 0, rctn = 0, temp = 0, fact = 0, blnk = 0, dely = 0, read = 0, lag = 0, linmin = 0, linmax = 0, normin = 0, normax = 0;
    int mode = 0, nostd = 0, rpt = 0, con1 = 0,con2 = 0,con3 = 0,con4 = 0,con5 = 0,con6 = 0,con7 = 0,con8 = 0;
    int ctrl1avg = 0, ctrl1min = 0,ctrl1max=0, ctrl1bno = 0, ctrl2avg = 0, ctrl2min = 0,ctrl2max=0, ctrl2bno = 0 ;


    Wave = char(wave);
    Fact=char(fact);
    Rctn=char(rctn);
    Temp=char(temp);
    Blnk =char (blnk);
    Dely=char(dely);
    Read=char(read);
    Lag=char(lag);
    Linmin=char(linmin);
    Linmax=char(linmax);
    Normin=char(normin);
    Normax=char(normax);
    Mode= char(mode);
    Nostd= char(nostd);
    Rpt= char(rpt);
    Con1=char(con1);
    Con2=char(con2);
    Con3=char(con3);
    Con4=char(con4);
    Con5=char(con5);
    Con6=char(con6);
    Con7=char(con7);
    Con8=char(con8);

    Ctrl1avg=char(ctrl1avg);
    Ctrl1min=char(ctrl1min);
    Ctrl1max=char(ctrl1max);
    Ctrl1bno=char(ctrl1bno);
    Ctrl2avg=char(ctrl2avg);
    Ctrl2min=char(ctrl2min);
    Ctrl2max=char(ctrl2max);
    Ctrl2bno=char(ctrl2bno);

    name = ui->label_439->text();
    unit=ui->lineEdit_27->text();
    Wave=ui->label_442->text();
    Rctn=ui->label_443->text();
    Temp=ui->label_444->text();
    Fact=ui->lineEdit_30->text();
    Blnk=ui->label_445->text();
    Dely=ui->label_446->text();
    Read=ui->label_447->text();
    Lag=ui->label_413->text();
    Linmin=ui->lineEdit_33->text();
    Linmax=ui->lineEdit_34->text();

    Infant_Min=ui->lineEdit_128->text();
    Infant_Max=ui->lineEdit_129->text();
    Child_Min=ui->lineEdit_130->text();
    Child_Max=ui->lineEdit_131->text();
    Normin=ui->lineEdit_36->text();
    Normax=ui->lineEdit_35->text();
    Female_Min=ui->lineEdit_132->text();
    Female_Max=ui->lineEdit_133->text();

    Nostd=ui->comboBox_7->currentText();
    Rpt=ui->comboBox_8->currentText();
    Con1=ui->lineEdit_112->text();
    Con2=ui->lineEdit_116->text();
    Con3=ui->lineEdit_113->text();
    Con4=ui->lineEdit_119->text();
    Con5=ui->lineEdit_114->text();
    Con6=ui->lineEdit_118->text();
    Con7=ui->lineEdit_115->text();
    Con8=ui->lineEdit_117->text();
    Ctrl1avg=ui->label_216->text();
    Ctrl1min=ui->lineEdit_59->text();
    Ctrl1max=ui->lineEdit_143->text();
    Ctrl1bno=ui->lineEdit_60->text();
    Ctrl2avg=ui->label_434->text();
    Ctrl2min=ui->lineEdit_62->text();
    Ctrl2max=ui->lineEdit_144->text();
    Ctrl2bno=ui->lineEdit_63->text();
    TestCode=ui->label_441->text();
    Batch_No=ui->lineEdit_153->text();
    QString Concen , Batch,ProductCode;
    QSqlQuery qqry;
    QSqlQuery qrry;
    qqry.prepare("select con1,Batch_No,Pro_Code from test where name = :name");
    qqry.bindValue(":name",TestName);
    if(!qqry.exec())
    {
        qDebug()<<"Query Error : "<<qqry.lastError().text();
        return;
    }
    else if(qqry.next())
    {
        Concen = qqry.value(0).toString();
        Batch=qqry.value(1).toString();
        ProductCode = qqry.value(2).toString();
    }
    else
    {
        qDebug()<<"No record found for Name : "<<TestName;
        return;
    }
    qDebug()<<"concentration :"<<Concen<<"Batch : "<<Batch<<"PROCode : " <<ProductCode;

    QString React = ui->label_443->text();
    if(React=="End point")
    {
        if (Batch_No=="")
        {
            msgboxtext="Please enter lotno.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,5});
            myTabWidgetsList.append({ ui->tabWidget_4, 1 });
            mypushButtonsList.append({ ui->pushButton_275, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_153, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (Con1=="")
        {
            msgboxtext="Please enter concentration(1).";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,5});
            myTabWidgetsList.append({ ui->tabWidget_4, 1 });
            mypushButtonsList.append({ ui->pushButton_215, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_112, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (Ctrl1min=="")
        {
            msgboxtext="Please enter control1 - minimum.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,5});
            myTabWidgetsList.append({ ui->tabWidget_4, 2 });
            mypushButtonsList.append({ ui->pushButton_160, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_59, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (Ctrl1max=="")
        {
            msgboxtext="Please enter control1 - maximum.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,5});
            myTabWidgetsList.append({ ui->tabWidget_4, 2 });
            mypushButtonsList.append({ ui->pushButton_220, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_143, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (Ctrl1bno=="")
        {
            msgboxtext="Please enter control1 - lotno.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,5});
            myTabWidgetsList.append({ ui->tabWidget_4, 2 });
            mypushButtonsList.append({ ui->pushButton_161, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_60, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (Ctrl2min=="")
        {
            msgboxtext="Please enter control2 - minimum.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,5});
            myTabWidgetsList.append({ ui->tabWidget_4, 2 });
            mypushButtonsList.append({ ui->pushButton_163, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_62, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (Ctrl2max=="")
        {
            msgboxtext="Please enter control2 - maximum.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,5});
            myTabWidgetsList.append({ ui->tabWidget_4, 2 });
            mypushButtonsList.append({ ui->pushButton_221, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_144, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (Ctrl2bno=="")
        {
            msgboxtext="Please enter control2 - lotno.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,5});
            myTabWidgetsList.append({ ui->tabWidget_4, 2 });
            mypushButtonsList.append({ ui->pushButton_164, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_63, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else
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
            msg.setText(" Are you sure you want to update data ?");
            QPushButton* saveButton = msg.addButton("Yes", QMessageBox::AcceptRole);
            saveButton->setStyleSheet("QPushButton{background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 #34ba91, stop: 0.5 #34ba91, stop: 1 #34ba91);color:black;}QPushButton:pressed {background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(0, 85, 0), stop: 0.5 rgb(0, 85, 0), stop: 1 rgb(0, 85, 0));color:white;}");
            QPushButton* dontSaveButton = msg.addButton("Go back", QMessageBox::DestructiveRole);
            dontSaveButton->setStyleSheet("QPushButton{background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 #ff5957, stop: 0.5 #ff5957, stop: 1 #ff5957);color:black;}QPushButton:pressed{background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(184, 0, 0), stop: 0.5 rgb(184, 0, 0), stop: 1 rgb(184, 0, 0)); color:white;}");
            msg.setDefaultButton(saveButton);
            msg.exec();
            if (msg.clickedButton() == saveButton)
            {
                qrry.prepare("update test set name='"+name+"' where Pro_Code ='"+ProductCode+"");
                qrry.exec();

                query.prepare("update test set name='"+name+"',unit='"+unit+"',wave='"+Wave+"', rctn='"+Rctn+"', temp='"+Temp+"', fact='"+Fact+"', blnk='"+Blnk+"', dely='"+Dely+"', read='"+Read+"', lag='"+Lag+"',linmin='"+Linmin+"', linmax='"+Linmax+"', normin='"+Normin+"', normax='"+Normax+"', nostd='"+Nostd+"', rpt='"+Rpt+"', con1='"+Con1+"',con2='"+Con2+"',con3='"+Con3+"',con4='"+Con4+"',con5='"+Con5+"',con6='"+Con6+"',con7='"+Con7+"',con8='"+Con8+"',ctrl1avg='"+Ctrl1avg+"', ctrl1min='"+Ctrl1min+"',ctrl1max='"+Ctrl1max+"', ctrl1bno='"+Ctrl1bno+"', ctrl2avg='"+Ctrl2avg+"', ctrl2min='"+Ctrl2min+"', ctrl2max='"+Ctrl2max+"',ctrl2bno='"+Ctrl2bno+"' ,Inc_Dec='"+Inc_Dec+"' ,Pro_Code='"+TestCode+"',Batch_No='"+Batch_No+"',Infant_Nmin='"+Infant_Min+"', Infant_Nmax='"+Infant_Max+"', Child_Nmin='"+Child_Min+"', Child_Nmax='"+Child_Max+"',Female_Nmin='"+Female_Min+"', Female_Nmax='"+Female_Max+"' where name='"+TestName+"'");
                if(query.exec())
                {

                    QMessageBox msg(this);
                    msg.setWindowFlags(Qt::Popup);
                    msg.setStyleSheet("background-color:#a0cdfa;font: 75 20pt Liberation Serif ;");
                    QPixmap p("/home/pi/git/BCYWithTRY/BCYWithTRY/img/check-mark.png");
                    auto newPixmap = p.scaled(80, 80);
                    msg.setIconPixmap(newPixmap);
                    QFont font;
                    font.setBold(true);
                    msg.setFont(font);
                    msg.setText(" Data updated.");
                    QPushButton* saveButton = msg.addButton("Ok", QMessageBox::AcceptRole);
                    saveButton->setStyleSheet("QPushButton{background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 #34ba91, stop: 0.5 #34ba91, stop: 1 #34ba91);color:black;}QPushButton:pressed {background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(0, 85, 0), stop: 0.5 rgb(0, 85, 0), stop: 1 rgb(0, 85, 0));color:white;}");
                    msg.setDefaultButton(saveButton);
                    msg.exec();
                    if (msg.clickedButton() == saveButton)
                    {
                        qDebug()<<"Update done";
                        ui->stackedWidget->setCurrentIndex(0);
                    }
                }

            }
            else if (msg.clickedButton() == dontSaveButton)
            {
                ui->stackedWidget->setCurrentIndex(5);
            }
        }
    }

    else if(React == "Fixed Kinetic")
    {
        if (Batch_No=="")
        {
            msgboxtext="Please enter lotno.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,5});
            myTabWidgetsList.append({ ui->tabWidget_4, 1 });
            mypushButtonsList.append({ ui->pushButton_275, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_153, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (Con1=="")
        {
            msgboxtext="Please enter concentration(1).";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,5});
            myTabWidgetsList.append({ ui->tabWidget_4, 1 });
            mypushButtonsList.append({ ui->pushButton_215, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_112, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (Ctrl1min=="")
        {
            msgboxtext="Please enter control1 - minimum.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,5});
            myTabWidgetsList.append({ ui->tabWidget_4, 2 });
            mypushButtonsList.append({ ui->pushButton_160, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_59, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (Ctrl1max=="")
        {
            msgboxtext="Please enter control1 - maximum.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,5});
            myTabWidgetsList.append({ ui->tabWidget_4, 2 });
            mypushButtonsList.append({ ui->pushButton_220, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_143, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (Ctrl1bno=="")
        {
            msgboxtext="Please enter control1 - lotno.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,5});
            myTabWidgetsList.append({ ui->tabWidget_4, 2 });
            mypushButtonsList.append({ ui->pushButton_161, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_60, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (Ctrl2min=="")
        {
            msgboxtext="Please enter control2 - minimum.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,5});
            myTabWidgetsList.append({ ui->tabWidget_4, 2 });
            mypushButtonsList.append({ ui->pushButton_163, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_62, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (Ctrl2max=="")
        {
            msgboxtext="Please enter control2 - maximum.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,5});
            myTabWidgetsList.append({ ui->tabWidget_4, 2 });
            mypushButtonsList.append({ ui->pushButton_221, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_144, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (Ctrl2bno=="")
        {
            msgboxtext="Please enter control2 - lotno.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,5});
            myTabWidgetsList.append({ ui->tabWidget_4, 2 });
            mypushButtonsList.append({ ui->pushButton_164, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_63, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else
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
            msg.setText("Are you sure you want to update data?");
            QPushButton* saveButton = msg.addButton("Yes", QMessageBox::AcceptRole);
            saveButton->setStyleSheet("QPushButton{background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 #34ba91, stop: 0.5 #34ba91, stop: 1 #34ba91);color:black;}QPushButton:pressed {background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(0, 85, 0), stop: 0.5 rgb(0, 85, 0), stop: 1 rgb(0, 85, 0));color:white;}");
            QPushButton* dontSaveButton = msg.addButton("Go back", QMessageBox::DestructiveRole);
            dontSaveButton->setStyleSheet("QPushButton{background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 #ff5957, stop: 0.5 #ff5957, stop: 1 #ff5957);color:black;}QPushButton:pressed{background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(184, 0, 0), stop: 0.5 rgb(184, 0, 0), stop: 1 rgb(184, 0, 0)); color:white;}");
            msg.setDefaultButton(saveButton);
            msg.exec();
            if (msg.clickedButton() == saveButton)
            {
                qrry.prepare("update test set name='"+name+"' where Pro_Code ='"+ProductCode+"");
                qrry.exec();

                query.prepare("update test set name='"+name+"',unit='"+unit+"',wave='"+Wave+"', rctn='"+Rctn+"', temp='"+Temp+"', fact='"+Fact+"', blnk='"+Blnk+"', dely='"+Dely+"', read='"+Read+"', lag='"+Lag+"',linmin='"+Linmin+"', linmax='"+Linmax+"', normin='"+Normin+"', normax='"+Normax+"', nostd='"+Nostd+"', rpt='"+Rpt+"', con1='"+Con1+"',con2='"+Con2+"',con3='"+Con3+"',con4='"+Con4+"',con5='"+Con5+"',con6='"+Con6+"',con7='"+Con7+"',con8='"+Con8+"',ctrl1avg='"+Ctrl1avg+"', ctrl1min='"+Ctrl1min+"',ctrl1max='"+Ctrl1max+"', ctrl1bno='"+Ctrl1bno+"', ctrl2avg='"+Ctrl2avg+"', ctrl2min='"+Ctrl2min+"', ctrl2max='"+Ctrl2max+"',ctrl2bno='"+Ctrl2bno+"' ,Inc_Dec='"+Inc_Dec+"' ,Pro_Code='"+TestCode+"',Batch_No='"+Batch_No+"',Infant_Nmin='"+Infant_Min+"', Infant_Nmax='"+Infant_Max+"', Child_Nmin='"+Child_Min+"', Child_Nmax='"+Child_Max+"',Female_Nmin='"+Female_Min+"', Female_Nmax='"+Female_Max+"' where name='"+TestName+"'");
                if(query.exec())
                {

                    QMessageBox msg(this);
                    msg.setWindowFlags(Qt::Popup);
                    msg.setStyleSheet("background-color:#a0cdfa;font: 75 20pt Liberation Serif ;");
                    QPixmap p("/home/pi/git/BCYWithTRY/BCYWithTRY/img/check-mark.png");
                    auto newPixmap = p.scaled(80, 80);
                    msg.setIconPixmap(newPixmap);
                    QFont font;
                    font.setBold(true);
                    msg.setFont(font);
                    msg.setText(" Data updated.");
                    QPushButton* saveButton = msg.addButton("Ok", QMessageBox::AcceptRole);
                    saveButton->setStyleSheet("QPushButton{background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 #34ba91, stop: 0.5 #34ba91, stop: 1 #34ba91);color:black;}QPushButton:pressed {background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(0, 85, 0), stop: 0.5 rgb(0, 85, 0), stop: 1 rgb(0, 85, 0));color:white;}");
                    msg.setDefaultButton(saveButton);
                    msg.exec();
                    if (msg.clickedButton() == saveButton)
                    {
                        qDebug()<<"Update done";
                        ui->stackedWidget->setCurrentIndex(0);
                    }
                }
            }
            else if (msg.clickedButton() == dontSaveButton)
            {
                ui->stackedWidget->setCurrentIndex(5);
            }
        }

    }

    else if(React == "Kinetic")
    {
        if (Batch_No=="")
        {
            msgboxtext="Please enter lotno.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,5});
            myTabWidgetsList.append({ ui->tabWidget_4, 1 });
            mypushButtonsList.append({ ui->pushButton_275, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_153, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (Con1=="")
        {
            msgboxtext="Please enter concentration(1).";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,5});
            myTabWidgetsList.append({ ui->tabWidget_4, 1 });
            mypushButtonsList.append({ ui->pushButton_215, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_112, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (Ctrl1min=="")
        {
            msgboxtext="Please enter control1 - minimum.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,5});
            myTabWidgetsList.append({ ui->tabWidget_4, 2 });
            mypushButtonsList.append({ ui->pushButton_160, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_59, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (Ctrl1max=="")
        {
            msgboxtext="Please enter control1 - maximum.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,5});
            myTabWidgetsList.append({ ui->tabWidget_4, 2 });
            mypushButtonsList.append({ ui->pushButton_220, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_143, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (Ctrl1bno=="")
        {
            msgboxtext="Please enter control1 - lotno.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,5});
            myTabWidgetsList.append({ ui->tabWidget_4, 2 });
            mypushButtonsList.append({ ui->pushButton_161, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_60, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (Ctrl2min=="")
        {
            msgboxtext="Please enter control2 - minimum.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,5});
            myTabWidgetsList.append({ ui->tabWidget_4, 2 });
            mypushButtonsList.append({ ui->pushButton_163, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_62, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (Ctrl2max=="")
        {
            msgboxtext="Please enter control2 - maximum.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,5});
            myTabWidgetsList.append({ ui->tabWidget_4, 2 });
            mypushButtonsList.append({ ui->pushButton_221, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_144, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if (Ctrl2bno=="")
        {
            msgboxtext="Please enter control2 - lotno.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,5});
            myTabWidgetsList.append({ ui->tabWidget_4, 2 });
            mypushButtonsList.append({ ui->pushButton_164, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_63, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else
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
            msg.setText("Are you sure you want to update data?");
            QPushButton* saveButton = msg.addButton("Yes", QMessageBox::AcceptRole);
            saveButton->setStyleSheet("QPushButton{background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 #34ba91, stop: 0.5 #34ba91, stop: 1 #34ba91);color:black;}QPushButton:pressed {background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(0, 85, 0), stop: 0.5 rgb(0, 85, 0), stop: 1 rgb(0, 85, 0));color:white;}");
            QPushButton* dontSaveButton = msg.addButton("Go back", QMessageBox::DestructiveRole);
            dontSaveButton->setStyleSheet("QPushButton{background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 #ff5957, stop: 0.5 #ff5957, stop: 1 #ff5957);color:black;}QPushButton:pressed{background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(184, 0, 0), stop: 0.5 rgb(184, 0, 0), stop: 1 rgb(184, 0, 0)); color:white;}");
            msg.setDefaultButton(saveButton);
            msg.exec();
            if (msg.clickedButton() == saveButton)
            {
                qrry.prepare("update test set name='"+name+"' where Pro_Code ='"+ProductCode+"");
                qrry.exec();

                query.prepare("update test set name='"+name+"',unit='"+unit+"',wave='"+Wave+"', rctn='"+Rctn+"', temp='"+Temp+"', fact='"+Fact+"', blnk='"+Blnk+"', dely='"+Dely+"', read='"+Read+"', lag='"+Lag+"',linmin='"+Linmin+"', linmax='"+Linmax+"', normin='"+Normin+"', normax='"+Normax+"', nostd='"+Nostd+"', rpt='"+Rpt+"', con1='"+Con1+"',con2='"+Con2+"',con3='"+Con3+"',con4='"+Con4+"',con5='"+Con5+"',con6='"+Con6+"',con7='"+Con7+"',con8='"+Con8+"',ctrl1avg='"+Ctrl1avg+"', ctrl1min='"+Ctrl1min+"',ctrl1max='"+Ctrl1max+"', ctrl1bno='"+Ctrl1bno+"', ctrl2avg='"+Ctrl2avg+"', ctrl2min='"+Ctrl2min+"', ctrl2max='"+Ctrl2max+"',ctrl2bno='"+Ctrl2bno+"' ,Inc_Dec='"+Inc_Dec+"' ,Pro_Code='"+TestCode+"',Batch_No='"+Batch_No+"',Infant_Nmin='"+Infant_Min+"', Infant_Nmax='"+Infant_Max+"', Child_Nmin='"+Child_Min+"', Child_Nmax='"+Child_Max+"',Female_Nmin='"+Female_Min+"', Female_Nmax='"+Female_Max+"' where name='"+TestName+"'");
                if(query.exec())
                {

                    QMessageBox msg(this);
                    msg.setWindowFlags(Qt::Popup);
                    msg.setStyleSheet("background-color:#a0cdfa;font: 75 20pt Liberation Serif ;");
                    QPixmap p("/home/pi/git/BCYWithTRY/BCYWithTRY/img/check-mark.png");
                    auto newPixmap = p.scaled(80, 80);
                    msg.setIconPixmap(newPixmap);
                    QFont font;
                    font.setBold(true);
                    msg.setFont(font);
                    msg.setText(" Data updated.");
                    QPushButton* saveButton = msg.addButton("Ok", QMessageBox::AcceptRole);
                    saveButton->setStyleSheet("QPushButton{background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 #34ba91, stop: 0.5 #34ba91, stop: 1 #34ba91);color:black;}QPushButton:pressed {background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(0, 85, 0), stop: 0.5 rgb(0, 85, 0), stop: 1 rgb(0, 85, 0));color:white;}");
                    msg.setDefaultButton(saveButton);
                    msg.exec();
                    if (msg.clickedButton() == saveButton)
                    {
                        qDebug()<<"Update done";
                        ui->stackedWidget->setCurrentIndex(0);
                    }
                }

            }
            else if (msg.clickedButton() == dontSaveButton)
            {
                ui->stackedWidget->setCurrentIndex(5);
            }
        }
    }
}

//********************Test Configuration (Delete Button)**************************

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    clearGridLayout(ui->gridLayout_2);
    ui->pushButton_6->setVisible(false);
    ui->pushButton_139->setVisible(false);
    ui->pushButton_142->setVisible(true);
    ui->pushButton_142->setStyleSheet("QPushButton {border: 2px solid green;border-top-left-radius:40px;border-top-right-radius:40px;background-color: white;padding: 10px;}");

    deleteback=1;

    tabnumber2=1;
    qDebug()<<"Recent Btn already deleted";
    ui->Home_Lbl_2->setText("Select parameter to delete");
    tabtest=3;
    tabrecent=0;
    tabedit=0;
    tabdelete=1;
    tabqc=0;
    tabfilter=0;
    exptopn=0;
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



        ui->gridLayout_2->update();
    }
    else if(Test_Type=="Turbidity")
    {
        ui->scrollArea_7->verticalScrollBar()->setStyleSheet("QScrollBar:vertical {"
                                                             "    border: 1px solid #999999;"
                                                             "    background:white;"
                                                             "    width:25px;    "
                                                             "    margin: 0px 0px 0px 0px;"
                                                             "}"
                                                             "QScrollBar::handle:vertical {"
                                                             "   background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0.08, stop:0.164773 rgba(0, 145, 106, 255), stop:1 rgba(0, 145, 106, 255));"
                                                             "    min-height: 0px;"
                                                             "}"
                                                             "QScrollBar::add-line:vertical {"
                                                             "    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0.08, stop:0.164773 rgba(0, 145, 106, 255), stop:1 rgba(0, 145, 106, 255));"
                                                             "    height: 0px;"
                                                             "    subcontrol-position: bottom;"
                                                             "    subcontrol-origin: margin;"
                                                             "}"
                                                             "QScrollBar::sub-line:vertical {"
                                                             "    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0.08, stop:0.164773 rgba(0, 145, 106, 255), stop:1 rgba(0, 145, 106, 255));"
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
                                                                "    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0.08, stop:0.164773 rgba(0, 145, 106, 255), stop:1 rgba(0, 145, 106, 255));"
                                                                "    min-height: 0px;"
                                                                "}"
                                                                "QScrollBar::add-line:horizontal {"
                                                                "    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0.08, stop:0.164773 rgba(0, 145, 106, 255), stop:1 rgba(0, 145, 106, 255));"
                                                                "    height: 0px;"
                                                                "    subcontrol-position: bottom;"
                                                                "    subcontrol-origin: margin;"
                                                                "}"
                                                                "QScrollBar::sub-line:horizontal {"
                                                                "    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0.08, stop:0.164773 rgba(0, 145, 106, 255), stop:1 rgba(0, 145, 106, 255));"
                                                                "    height: 0 px;"
                                                                "    subcontrol-position: top;"
                                                                "    subcontrol-origin: margin;"
                                                                "}");

        ui->gridLayout_2->update();
    }
    QSqlQuery query;
    if(Test_Type=="Biochemistry")
    {
        query.prepare("SELECT name FROM test ORDER BY name ASC;");
        query.exec();
        int count=0;
        while(query.next())
        {
            QString s=query.value(0).toString();
            arraylst[count]=s;
            count++;
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
                                "  background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(12, 68, 145), stop: 0.5 rgb(12, 68, 145), stop:1 rgb(12, 68, 145));"
                                "  color: white;"
                                "}"
                                "QPushButton:hover {"
                                "  background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0.08, stop:0.164773 rgba(0, 214, 157, 255), stop:1 rgba(0, 214, 157, 255));""}"
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
                    connect(button, &QPushButton::clicked, this , &MainWindow::cald3);
                    ui->gridLayout_2->addWidget(button , i,j);
                    vaalu=i;
                    vaalu2=j;
                    count1++;

                }
            }
        }
    }
    else if(Test_Type=="Turbidity")
    {
        query.prepare("SELECT TestName FROM Turbidity_test ORDER BY TestName ASC;");
        query.exec();
        int count=0;
        while(query.next())
        {
            QString s=query.value(0).toString();
            arrayval[count]=s;
            count++;
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
                    QPushButton *button = new QPushButton(arrayval[count1]);
                    button->setStyleSheet(
                                "QPushButton {"
                                "  background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0.08, stop:0.164773 rgba(0, 145, 106, 255), stop:1 rgba(0, 145, 106, 255));"
                                "  color: white;"
                                "}"
                                "QPushButton:hover {"
                                "  background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0.08, stop:0.164773 rgba(0, 214, 157, 255), stop:1 rgba(0, 214, 157, 255));}"
                                "QPushButton:disabled {"
                                "  background: rgb(170, 170, 127);"
                                "  color: black;"
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
                    button->setObjectName(arrayval[count1]);
                    connect(button, &QPushButton::clicked, this , &MainWindow::cald3);
                    ui->gridLayout_2->addWidget(button , i,j);
                    vaalu=i;
                    vaalu2=j;
                    count1++;
                    if(nextnumber2==2)
                    {
                        QLayoutItem *child;
                        while ((child = ui->gridLayout_2->takeAt(Objdel)) != nullptr)
                        {

                            delete child->widget(); // delete the widget
                            delete child;   // delete the layout item
                        }
                        nextnumber2=0;
                    }
                }
            }
        }
    }
}

Pos gridPosition(QWidget * widget)
{
    if (! widget->parentWidget()) return {};
    auto layout = qobject_cast<QGridLayout*>(widget->parentWidget()->layout());
    if (! layout) return {};
    int index = layout->indexOf(widget);
    Q_ASSERT(index >= 0);
    int _;
    Pos pos;
    layout->getItemPosition(index, &pos.row, &pos.col, &_, &_);
    return pos;
}

void MainWindow::cald3()
{
    QObject *senderObj = sender(); // This will give Sender object
    QString senderObjName = senderObj->objectName();
    TestName=senderObjName;
    QMessageBox msg(this);
    msg.setWindowFlags(Qt::Popup);
    msg.setStyleSheet("background-color:#a0cdfa;font: 75 20pt Liberation Serif ;");
    QPixmap p("/home/pi/git/BCYWithTRY/BCYWithTRY/img/notification.png");
    auto newPixmap = p.scaled(80, 80);
    msg.setIconPixmap(newPixmap);
    QFont font;
    font.setBold(true);
    msg.setFont(font);
    msg.setText("Do you want to delete the parameter ?");
    QPushButton* saveButton = msg.addButton("Yes", QMessageBox::AcceptRole);
    saveButton->setStyleSheet("QPushButton{background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 #34ba91, stop: 0.5 #34ba91, stop: 1 #34ba91);color:black;}QPushButton:pressed {background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(0, 85, 0), stop: 0.5 rgb(0, 85, 0), stop: 1 rgb(0, 85, 0));color:white;}");
    QPushButton* dontSaveButton = msg.addButton("No", QMessageBox::DestructiveRole);
    dontSaveButton->setStyleSheet("QPushButton{background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 #ff5957, stop: 0.5 #ff5957, stop: 1 #ff5957);color:black;}QPushButton:pressed{background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(184, 0, 0), stop: 0.5 rgb(184, 0, 0), stop: 1 rgb(184, 0, 0)); color:white;}");
    msg.setDefaultButton(saveButton);
    msg.exec();
    if (msg.clickedButton() == saveButton)
    {
        senderObj->deleteLater();
        nextnumber=1;
        nextnumber2=2;
        nextnumber3=3;
        nextnumber4=4;

        QSqlQuery query;
        if(Test_Type=="Biochemistry")
            query.prepare("Delete from test where name='"+TestName+"'");
        else if(Test_Type=="Turbidity")
            query.prepare("Delete from Turbidity_test where TestName='"+TestName+"'");
        if(query.exec())
        {

            QMessageBox msg(this);
            msg.setWindowFlags(Qt::Popup);
            msg.setStyleSheet("background-color:#a0cdfa;font: 75 20pt Liberation Serif ;");
            QPixmap p("/home/pi/git/BCYWithTRY/BCYWithTRY/img/check-mark.png");
            auto newPixmap = p.scaled(80, 80);
            msg.setIconPixmap(newPixmap);
            QFont font;
            font.setBold(true);
            msg.setFont(font);
            msg.setText("Data deleted.");
            QPushButton* saveButton = msg.addButton("Ok", QMessageBox::AcceptRole);
            saveButton->setStyleSheet("QPushButton{background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 #34ba91, stop: 0.5 #34ba91, stop: 1 #34ba91);color:black;}QPushButton:pressed {background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(0, 85, 0), stop: 0.5 rgb(0, 85, 0), stop: 1 rgb(0, 85, 0));color:white;}");
            msg.setDefaultButton(saveButton);
            msg.exec();
            if (msg.clickedButton() == saveButton)
            {
                ui->stackedWidget->setCurrentIndex(3);
                ui->gridLayout_2->update();
            }
        }
    }
    else if (msg.clickedButton() == dontSaveButton)
    {
        // Handle cancel button click, e.g., close the dialog or perform other actions.
    }
}


void MainWindow::on_Save_Btn_2_clicked()
{
    QString Testname, TestCode,Wave,Unit,Temp,Fact,Blank,Incubation,Graph_Type,Reaction_Type,No_of_cal,Cal1,Cal2,Cal3,Cal4,Cal5,Cal6,Cal7,Cal8,Abs1,Abs2,Abs3,Abs4,Abs5,Abs6,Abs7,Abs8,Fact1,Fact2,Fact3,Fact4,Fact5,Fact6,Fact7,Fact8,LinMin,LinMax,NorMin,NorMax,Ctrl1Avg,Ctrl1Min,Ctrl1Max,Ctrl1Bno,Ctrl2Avg,Ctrl2Min,Ctrl2Max,Ctrl2Bno,Batch_No,RecentCNT,OldAbs1,OldAbs2,OldAbs3,OldAbs4,OldAbs5,OldAbs6,OldAbs7,OldAbs8,Cal1_Date,Cal2_Date,Cal3_Date,Cal4_Date,Cal5_Date,Cal6_Date,Cal7_Date,Cal8_Date,Rctn_type,after_Incubation,Direct_read;
    QString Infant_Min,Infant_Max,Child_Min,Child_Max,Female_Min,Female_Max;
    QString Cal1_ExDate,Cal2_ExDate,Cal3_ExDate,Cal4_ExDate,Cal5_ExDate,Cal6_ExDate,Cal7_ExDate,Cal8_ExDate,Intensity,Slope,Intercept,A_Val,B_Val,C_Val,D_Val,G_Val;

    Testname=ui->lineEdit_14->text();
    TestCode=ui->lineEdit_43->text();
    Wave=ui->label_206->text();
    Unit=ui->lineEdit_21->text();
    Temp=ui->label_371->text();
    Fact=ui->lineEdit_22->text();
    Blank=" ";
    Incubation=ui->lineEdit_25->text();
    Reaction_Type=ui->Reaction_Type->currentText();
    Graph_Type= ui->Graph_Type->currentText();

    No_of_cal=ui->comboBox_20->currentText();
    Cal1=ui->lineEdit_99->text();
    Cal2=ui->lineEdit_103->text();
    Cal3=ui->lineEdit_100->text();
    Cal4=ui->lineEdit_106->text();
    Cal5=ui->lineEdit_101->text();
    Cal6=ui->lineEdit_105->text();
    Cal7=ui->lineEdit_102->text();
    Cal8=ui->lineEdit_104->text();

    LinMin=ui->lineEdit_31->text();
    LinMax=ui->lineEdit_32->text();

    Infant_Min=ui->lineEdit_134->text();
    Infant_Max=ui->lineEdit_135->text();
    Child_Min=ui->lineEdit_148->text();
    Child_Max=ui->lineEdit_158->text();
    NorMin=ui->lineEdit_38->text();
    NorMax=ui->lineEdit_37->text();
    Female_Min=ui->lineEdit_159->text();
    Female_Max=ui->lineEdit_160->text();

    Ctrl1Min=ui->lineEdit_39->text();
    Ctrl1Max=ui->lineEdit_145->text();
    Ctrl1Avg=ui->label_461->text();
    Ctrl1Bno=ui->lineEdit_40->text();
    Ctrl2Min=ui->lineEdit_41->text();
    Ctrl2Max=ui->lineEdit_146->text();
    Ctrl2Avg=ui->label_463->text();
    Ctrl2Bno=ui->lineEdit_44->text();
    Batch_No=ui->lineEdit_154->text();
    after_Incubation = ui->lineEdit_170->text();
    Direct_read = ui->lineEdit_169->text();
    RecentCNT ="0000000";

    Abs1= " ";
    Abs2= " ";
    Abs3= " ";
    Abs4= " ";
    Abs5= " ";
    Abs6= " ";
    Abs7= " ";
    Abs8= " ";

    Fact1=" ";
    Fact2=" ";
    Fact3=" ";
    Fact4=" ";
    Fact5=" ";
    Fact6=" ";
    Fact7=" ";
    Fact8=" ";

    OldAbs1=" ";
    OldAbs2=" ";
    OldAbs3=" ";
    OldAbs4=" ";
    OldAbs5=" ";
    OldAbs6=" ";
    OldAbs7=" ";
    OldAbs8=" ";

    Cal1_Date=" ";
    Cal2_Date=" ";
    Cal3_Date=" ";
    Cal4_Date=" ";
    Cal5_Date=" ";
    Cal6_Date=" ";
    Cal7_Date=" ";
    Cal8_Date=" ";

    Cal1_ExDate=" ";
    Cal2_ExDate=" ";
    Cal3_ExDate=" ";
    Cal4_ExDate=" ";
    Cal5_ExDate=" ";
    Cal6_ExDate=" ";
    Cal7_ExDate=" ";
    Cal8_ExDate=" ";
    Intensity=" ";
    Slope=" ";
    Intercept=" ";
    A_Val=" ";
    B_Val=" ";
    C_Val=" ";
    D_Val=" ";
    G_Val=" ";
    Rctn_type=ui->Reaction_Type->currentText();

    if(Testname=="")
    {
        msgboxtext="Please enter test name.";
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
    else if(TestCode=="")
    {
        msgboxtext="Please enter test code.";
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
    else if(Unit=="")
    {
        msgboxtext="Please enter unit.";
        msgicondata="notification";
        mypushButtonsList.clear(); // Clear existing lists
        myLineEditsList.clear();
        myStackedWidgetsList.clear();
        myTabWidgetsList.clear();
        myStackedWidgetsList.append({ ui->stackedWidget,33});
        myTabWidgetsList.append({ ui->tabWidget_3, 0 });
        mypushButtonsList.append({ ui->pushButton_153, true }); // Add the specific button
        myLineEditsList.append({ ui->lineEdit_21, true }); // Add the specific line edit
        Call_Msg_box();
    }
    else if(Reaction_Type=="--Select--")
    {
        msgboxtext="Please select reation type.";
        msgicondata="notification";
        mypushButtonsList.clear(); // Clear existing lists
        myLineEditsList.clear();
        myStackedWidgetsList.clear();
        myTabWidgetsList.clear();
        myStackedWidgetsList.append({ ui->stackedWidget,33});
        myTabWidgetsList.append({ ui->tabWidget_3, 0 });
        Call_Msg_box();
    }
    else if(Graph_Type=="--Select--")
    {
        msgboxtext="Please select graph type.";
        msgicondata="notification";
        mypushButtonsList.clear(); // Clear existing lists
        myLineEditsList.clear();
        myStackedWidgetsList.clear();
        myTabWidgetsList.clear();
        myStackedWidgetsList.append({ ui->stackedWidget,33});
        myTabWidgetsList.append({ ui->tabWidget_3, 0 });
        Call_Msg_box();
    }

    else if(Incubation=="")
    {
        msgboxtext="Please enter Incubation time(M).";
        msgicondata="notification";
        mypushButtonsList.clear(); // Clear existing lists
        myLineEditsList.clear();
        myStackedWidgetsList.clear();
        myTabWidgetsList.clear();
        myStackedWidgetsList.append({ ui->stackedWidget,33});
        myTabWidgetsList.append({ ui->tabWidget_3, 0 });
        mypushButtonsList.append({ ui->pushButton_155, true }); // Add the specific button
        myLineEditsList.append({ ui->lineEdit_25, true }); // Add the specific line edit
        Call_Msg_box();
    }

    else if(LinMin=="")
    {
        msgboxtext="Please enter linear minimum.";
        msgicondata="notification";
        mypushButtonsList.clear(); // Clear existing lists
        myLineEditsList.clear();
        myStackedWidgetsList.clear();
        myTabWidgetsList.clear();
        myStackedWidgetsList.append({ ui->stackedWidget,33});
        myTabWidgetsList.append({ ui->tabWidget_3, 0 });
        mypushButtonsList.append({ ui->pushButton_154, true }); // Add the specific button
        myLineEditsList.append({ ui->lineEdit_31, true }); // Add the specific line edit
        Call_Msg_box();
    }
    else if(LinMax=="")
    {
        msgboxtext="Please enter linear maximum.";
        msgicondata="notification";
        mypushButtonsList.clear(); // Clear existing lists
        myLineEditsList.clear();
        myStackedWidgetsList.clear();
        myTabWidgetsList.clear();
        myStackedWidgetsList.append({ ui->stackedWidget,33});
        myTabWidgetsList.append({ ui->tabWidget_3, 0 });
        mypushButtonsList.append({ ui->pushButton_157, true }); // Add the specific button
        myLineEditsList.append({ ui->lineEdit_32, true }); // Add the specific line edit
        Call_Msg_box();
    }

    else if(NorMin=="")
    {
        msgboxtext="Please enter normal minimum.";
        msgicondata="notification";
        mypushButtonsList.clear(); // Clear existing lists
        myLineEditsList.clear();
        myStackedWidgetsList.clear();
        myTabWidgetsList.clear();
        myStackedWidgetsList.append({ ui->stackedWidget,33});
        myTabWidgetsList.append({ ui->tabWidget_3, 0 });
        mypushButtonsList.append({ ui->pushButton_158, true }); // Add the specific button
        myLineEditsList.append({ ui->lineEdit_38, true }); // Add the specific line edit
        Call_Msg_box();
    }
    else if(NorMax=="")
    {
        msgboxtext="Please enter normal maximum.";
        msgicondata="notification";
        mypushButtonsList.clear(); // Clear existing lists
        myLineEditsList.clear();
        myStackedWidgetsList.clear();
        myTabWidgetsList.clear();
        myStackedWidgetsList.append({ ui->stackedWidget,33});
        myTabWidgetsList.append({ ui->tabWidget_3, 0 });
        mypushButtonsList.append({ ui->pushButton_159, true }); // Add the specific button
        myLineEditsList.append({ ui->lineEdit_37, true }); // Add the specific line edit
        Call_Msg_box();
    }
    else if(Batch_No=="")
    {
        msgboxtext="Please enter batch no.";
        msgicondata="notification";
        mypushButtonsList.clear(); // Clear existing lists
        myLineEditsList.clear();
        myStackedWidgetsList.clear();
        myTabWidgetsList.clear();
        myStackedWidgetsList.append({ ui->stackedWidget,33});
        myTabWidgetsList.append({ ui->tabWidget_3, 1 });
        mypushButtonsList.append({ ui->pushButton_280, true }); // Add the specific button
        myLineEditsList.append({ ui->lineEdit_154, true }); // Add the specific line edit
        Call_Msg_box();
    }
    else if(Ctrl1Min=="")
    {
        msgboxtext="Please enter control1-minimum.";
        msgicondata="notification";
        mypushButtonsList.clear(); // Clear existing lists
        myLineEditsList.clear();
        myStackedWidgetsList.clear();
        myTabWidgetsList.clear();
        myStackedWidgetsList.append({ ui->stackedWidget,33});
        myTabWidgetsList.append({ ui->tabWidget_3, 2 });
        mypushButtonsList.append({ ui->pushButton_162, true }); // Add the specific button
        myLineEditsList.append({ ui->lineEdit_39, true }); // Add the specific line edit
        Call_Msg_box();
    }
    else if(Ctrl1Max=="")
    {
        msgboxtext="Please enter control1-maximum.";
        msgicondata="notification";
        mypushButtonsList.clear(); // Clear existing lists
        myLineEditsList.clear();
        myStackedWidgetsList.clear();
        myTabWidgetsList.clear();
        myStackedWidgetsList.append({ ui->stackedWidget,33});
        myTabWidgetsList.append({ ui->tabWidget_3, 2 });
        mypushButtonsList.append({ ui->pushButton_284, true }); // Add the specific button
        myLineEditsList.append({ ui->lineEdit_145, true }); // Add the specific line edit
        Call_Msg_box();
    }
    else if(Ctrl1Bno=="")
    {
        msgboxtext="Please enter control1-lotno.";
        msgicondata="notification";
        mypushButtonsList.clear(); // Clear existing lists
        myLineEditsList.clear();
        myStackedWidgetsList.clear();
        myTabWidgetsList.clear();
        myStackedWidgetsList.append({ ui->stackedWidget,33});
        myTabWidgetsList.append({ ui->tabWidget_3, 2 });
        mypushButtonsList.append({ ui->pushButton_165, true }); // Add the specific button
        myLineEditsList.append({ ui->lineEdit_40, true }); // Add the specific line edit
        Call_Msg_box();
    }
    else if(Ctrl2Min=="")
    {
        msgboxtext="Please enter control2-minimum.";
        msgicondata="notification";
        mypushButtonsList.clear(); // Clear existing lists
        myLineEditsList.clear();
        myStackedWidgetsList.clear();
        myTabWidgetsList.clear();
        myStackedWidgetsList.append({ ui->stackedWidget,33});
        myTabWidgetsList.append({ ui->tabWidget_3, 2 });
        mypushButtonsList.append({ ui->pushButton_166, true }); // Add the specific button
        myLineEditsList.append({ ui->lineEdit_41, true }); // Add the specific line edit
        Call_Msg_box();
    }
    else if(Ctrl2Max=="")
    {
        msgboxtext="Please enter control2-maximum.";
        msgicondata="notification";
        mypushButtonsList.clear(); // Clear existing lists
        myLineEditsList.clear();
        myStackedWidgetsList.clear();
        myTabWidgetsList.clear();
        myStackedWidgetsList.append({ ui->stackedWidget,33});
        myTabWidgetsList.append({ ui->tabWidget_3, 2 });
        mypushButtonsList.append({ ui->pushButton_285, true }); // Add the specific button
        myLineEditsList.append({ ui->lineEdit_146, true }); // Add the specific line edit
        Call_Msg_box();
    }
    else if(Ctrl2Bno=="")
    {
        msgboxtext="Please enter control2-lotno.";
        msgicondata="notification";
        mypushButtonsList.clear(); // Clear existing lists
        myLineEditsList.clear();
        myStackedWidgetsList.clear();
        myTabWidgetsList.clear();
        myStackedWidgetsList.append({ ui->stackedWidget,33});
        myTabWidgetsList.append({ ui->tabWidget_3, 2 });
        mypushButtonsList.append({ ui->pushButton_167, true }); // Add the specific button
        myLineEditsList.append({ ui->lineEdit_44, true }); // Add the specific line edit
        Call_Msg_box();
    }
    else if(No_of_cal=="1")
    {
        if(Cal1=="")
        {
            msgboxtext="Please enter cal1.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,33});
            myTabWidgetsList.append({ ui->tabWidget_3, 1 });
            mypushButtonsList.append({ ui->pushButton_223, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_99, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else
            Data_store();
    }
    else if(No_of_cal=="2")
    {
        if(Cal1=="")
        {
            msgboxtext="Please enter cal1.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,33});
            myTabWidgetsList.append({ ui->tabWidget_3, 1 });
            mypushButtonsList.append({ ui->pushButton_223, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_99, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if(Cal2=="")
        {
            msgboxtext="Please enter cal2.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,33});
            myTabWidgetsList.append({ ui->tabWidget_3, 1 });
            mypushButtonsList.append({ ui->pushButton_281, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_103, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else
            Data_store();
    }
    else if(No_of_cal=="3")
    {
        if(Cal1=="")
        {
            msgboxtext="Please enter cal1.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,33});
            myTabWidgetsList.append({ ui->tabWidget_3, 1 });
            mypushButtonsList.append({ ui->pushButton_223, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_99, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if(Cal2=="")
        {
            msgboxtext="Please enter cal2.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,33});
            myTabWidgetsList.append({ ui->tabWidget_3, 1 });
            mypushButtonsList.append({ ui->pushButton_281, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_103, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if(Cal3=="")
        {
            msgboxtext="Please enter cal3.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,33});
            myTabWidgetsList.append({ ui->tabWidget_3, 1 });
            mypushButtonsList.append({ ui->pushButton_246, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_100, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else
            Data_store();
    }
    else if(No_of_cal=="4")
    {
        if(Cal1=="")
        {
            msgboxtext="Please enter cal1.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,33});
            myTabWidgetsList.append({ ui->tabWidget_3, 1 });
            mypushButtonsList.append({ ui->pushButton_223, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_99, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if(Cal2=="")
        {
            msgboxtext="Please enter cal2.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,33});
            myTabWidgetsList.append({ ui->tabWidget_3, 1 });
            mypushButtonsList.append({ ui->pushButton_281, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_103, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if(Cal3=="")
        {
            msgboxtext="Please enter cal3.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,33});
            myTabWidgetsList.append({ ui->tabWidget_3, 1 });
            mypushButtonsList.append({ ui->pushButton_246, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_100, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if(Cal4=="")
        {
            msgboxtext="Please enter cal4.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,33});
            myTabWidgetsList.append({ ui->tabWidget_3, 1 });
            mypushButtonsList.append({ ui->pushButton_283, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_106, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else
            Data_store();
    }
    else if(No_of_cal=="5")
    {
        if(Cal1=="")
        {
            msgboxtext="Please enter cal1.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,33});
            myTabWidgetsList.append({ ui->tabWidget_3, 1 });
            mypushButtonsList.append({ ui->pushButton_223, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_99, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if(Cal2=="")
        {
            msgboxtext="Please enter cal2.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,33});
            myTabWidgetsList.append({ ui->tabWidget_3, 1 });
            mypushButtonsList.append({ ui->pushButton_281, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_103, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if(Cal3=="")
        {
            msgboxtext="Please enter cal3.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,33});
            myTabWidgetsList.append({ ui->tabWidget_3, 1 });
            mypushButtonsList.append({ ui->pushButton_246, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_100, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if(Cal4=="")
        {
            msgboxtext="Please enter cal4.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,33});
            myTabWidgetsList.append({ ui->tabWidget_3, 1 });
            mypushButtonsList.append({ ui->pushButton_283, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_106, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if(Cal5=="")
        {
            msgboxtext="Please enter cal5.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,33});
            myTabWidgetsList.append({ ui->tabWidget_3, 1 });
            mypushButtonsList.append({ ui->pushButton_225, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_101, true }); // Add the specific line edit
        }
        else
            Data_store();
    }
    else if(No_of_cal=="6")
    {
        if(Cal1=="")
        {
            msgboxtext="Please enter cal1.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,33});
            myTabWidgetsList.append({ ui->tabWidget_3, 1 });
            mypushButtonsList.append({ ui->pushButton_223, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_99, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if(Cal2=="")
        {
            msgboxtext="Please enter cal2.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,33});
            myTabWidgetsList.append({ ui->tabWidget_3, 1 });
            mypushButtonsList.append({ ui->pushButton_281, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_103, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if(Cal3=="")
        {
            msgboxtext="Please enter cal3.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,33});
            myTabWidgetsList.append({ ui->tabWidget_3, 1 });
            mypushButtonsList.append({ ui->pushButton_246, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_100, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if(Cal4=="")
        {
            msgboxtext="Please enter cal4.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,33});
            myTabWidgetsList.append({ ui->tabWidget_3, 1 });
            mypushButtonsList.append({ ui->pushButton_283, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_106, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if(Cal5=="")
        {
            msgboxtext="Please enter cal5.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,33});
            myTabWidgetsList.append({ ui->tabWidget_3, 1 });
            mypushButtonsList.append({ ui->pushButton_225, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_101, true }); // Add the specific line edit
        }
        else if(Cal6=="")
        {
            msgboxtext="Please enter cal6.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,33});
            myTabWidgetsList.append({ ui->tabWidget_3, 1 });
            mypushButtonsList.append({ ui->pushButton_282, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_105, true }); // Add the specific line edit
        }
        else
            Data_store();
    }
    else if(No_of_cal=="7")
    {
        if(Cal1=="")
        {
            msgboxtext="Please enter cal1.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,33});
            myTabWidgetsList.append({ ui->tabWidget_3, 1 });
            mypushButtonsList.append({ ui->pushButton_223, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_99, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if(Cal2=="")
        {
            msgboxtext="Please enter cal2.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,33});
            myTabWidgetsList.append({ ui->tabWidget_3, 1 });
            mypushButtonsList.append({ ui->pushButton_281, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_103, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if(Cal3=="")
        {
            msgboxtext="Please enter cal3.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,33});
            myTabWidgetsList.append({ ui->tabWidget_3, 1 });
            mypushButtonsList.append({ ui->pushButton_246, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_100, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if(Cal4=="")
        {
            msgboxtext="Please enter cal4.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,33});
            myTabWidgetsList.append({ ui->tabWidget_3, 1 });
            mypushButtonsList.append({ ui->pushButton_283, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_106, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if(Cal5=="")
        {
            msgboxtext="Please enter cal5.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,33});
            myTabWidgetsList.append({ ui->tabWidget_3, 1 });
            mypushButtonsList.append({ ui->pushButton_225, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_101, true }); // Add the specific line edit
        }
        else if(Cal6=="")
        {
            msgboxtext="Please enter cal6.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,33});
            myTabWidgetsList.append({ ui->tabWidget_3, 1 });
            mypushButtonsList.append({ ui->pushButton_282, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_105, true }); // Add the specific line edit
        }
        else if(Cal7=="")
        {
            msgboxtext="Please enter cal7.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,33});
            myTabWidgetsList.append({ ui->tabWidget_3, 1 });
            mypushButtonsList.append({ ui->pushButton_243, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_102, true }); // Add the specific line edit
        }
        else
            Data_store();
    }
    else if(No_of_cal=="8")
    {
        if(Cal1=="")
        {
            msgboxtext="Please enter cal1.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,33});
            myTabWidgetsList.append({ ui->tabWidget_3, 1 });
            mypushButtonsList.append({ ui->pushButton_223, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_99, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if(Cal2=="")
        {
            msgboxtext="Please enter cal2.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,33});
            myTabWidgetsList.append({ ui->tabWidget_3, 1 });
            mypushButtonsList.append({ ui->pushButton_281, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_103, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if(Cal3=="")
        {
            msgboxtext="Please enter cal3.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,33});
            myTabWidgetsList.append({ ui->tabWidget_3, 1 });
            mypushButtonsList.append({ ui->pushButton_246, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_100, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if(Cal4=="")
        {
            msgboxtext="Please enter cal4.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,33});
            myTabWidgetsList.append({ ui->tabWidget_3, 1 });
            mypushButtonsList.append({ ui->pushButton_283, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_106, true }); // Add the specific line edit
            Call_Msg_box();
        }
        else if(Cal5=="")
        {
            msgboxtext="Please enter cal5.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,33});
            myTabWidgetsList.append({ ui->tabWidget_3, 1 });
            mypushButtonsList.append({ ui->pushButton_225, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_101, true }); // Add the specific line edit
        }
        else if(Cal6=="")
        {
            msgboxtext="Please enter cal6.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,33});
            myTabWidgetsList.append({ ui->tabWidget_3, 1 });
            mypushButtonsList.append({ ui->pushButton_282, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_105, true }); // Add the specific line edit
        }
        else if(Cal7=="")
        {
            msgboxtext="Please enter cal7.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,33});
            myTabWidgetsList.append({ ui->tabWidget_3, 1 });
            mypushButtonsList.append({ ui->pushButton_243, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_102, true }); // Add the specific line edit
        }
        else if(Cal8=="")
        {
            msgboxtext="Please enter cal8.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,33});
            myTabWidgetsList.append({ ui->tabWidget_3, 1 });
            mypushButtonsList.append({ ui->pushButton_247, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_104, true }); // Add the specific line edit
        }
        else
            Data_store();
    }
}

void MainWindow::on_Update_Btn_2_clicked()
{
    QString Testname, TestCode,Wave,Unit,Temp,Fact,Blank,Incubation,Graph_Type,No_of_cal,Cal1,Cal2,Cal3,Cal4,Cal5,Cal6,Cal7,Cal8,LinMin,LinMax,NorMin,NorMax,Ctrl1Avg,Ctrl1Min,Ctrl1Max,Ctrl1Bno,Ctrl2Avg,Ctrl2Min,Ctrl2Max,Ctrl2Bno,Batch_No,Rctn_type,After_Incu,Direct_read;
    QString Infant_Min,Infant_Max,Child_Min,Child_Max,Female_Min,Female_Max;

    Testname=ui->label_468->text();
    TestCode=ui->label_469->text();
    Wave=ui->label_470->text();
    Unit=ui->lineEdit_47->text();
    Temp=ui->label_471->text();
    Fact=ui->lineEdit_48->text();
    Blank=" ";
    Incubation=ui->lineEdit_61->text();
    After_Incu=ui->lineEdit_173->text();
    Direct_read=ui->lineEdit_171->text();
    Graph_Type=ui->Graph_Type_2->currentText();
    No_of_cal=ui->comboBox_21->currentText();
    Cal1=ui->lineEdit_120->text();
    Cal2=ui->lineEdit_124->text();
    Cal3=ui->lineEdit_121->text();
    Cal4=ui->lineEdit_127->text();
    Cal5=ui->lineEdit_122->text();
    Cal6=ui->lineEdit_126->text();
    Cal7=ui->lineEdit_123->text();
    Cal8=ui->lineEdit_125->text();
    LinMin=ui->lineEdit_53->text();
    LinMax=ui->lineEdit_54->text();

    Infant_Min=ui->lineEdit_163->text();
    Infant_Max=ui->lineEdit_164->text();
    Child_Min=ui->lineEdit_165->text();
    Child_Max=ui->lineEdit_166->text();
    NorMin=ui->lineEdit_55->text();
    NorMax=ui->lineEdit_56->text();
    Female_Min=ui->lineEdit_167->text();
    Female_Max=ui->lineEdit_168->text();

    Ctrl1Avg=ui->label_505->text();
    Ctrl1Min=ui->lineEdit_64->text();
    Ctrl1Max=ui->lineEdit_151->text();
    Ctrl1Bno=ui->lineEdit_65->text();
    Ctrl2Avg=ui->label_510->text();
    Ctrl2Min=ui->lineEdit_66->text();
    Ctrl2Max=ui->lineEdit_156->text();
    Ctrl2Bno=ui->lineEdit_98->text();
    Rctn_type=ui->Reaction_Type_2->currentText();
    Batch_No=ui->lineEdit_155->text();

    if(Unit=="")
    {
        msgboxtext="Please enter unit.";
        msgicondata="notification";
        mypushButtonsList.clear(); // Clear existing lists
        myLineEditsList.clear();
        myStackedWidgetsList.clear();
        myTabWidgetsList.clear();
        myStackedWidgetsList.append({ ui->stackedWidget,34});
        myTabWidgetsList.append({ ui->tabWidget_5, 0 });
        mypushButtonsList.append({ ui->pushButton_171, true }); // Add the specific button
        myLineEditsList.append({ ui->lineEdit_47, true }); // Add the specific line edit
    }
    else if(Incubation=="")
    {
        msgboxtext="Please enter Incubation time(M).";
        msgicondata="notification";
        mypushButtonsList.clear(); // Clear existing lists
        myLineEditsList.clear();
        myStackedWidgetsList.clear();
        myTabWidgetsList.clear();
        myStackedWidgetsList.append({ ui->stackedWidget,34});
        myTabWidgetsList.append({ ui->tabWidget_5, 0 });
        mypushButtonsList.append({ ui->pushButton_305, true }); // Add the specific button
        myLineEditsList.append({ ui->lineEdit_61, true }); // Add the specific line edit
    }

    else if(LinMin=="")
    {
        msgboxtext="Please enter linear minimum.";
        msgicondata="notification";
        mypushButtonsList.clear(); // Clear existing lists
        myLineEditsList.clear();
        myStackedWidgetsList.clear();
        myTabWidgetsList.clear();
        myStackedWidgetsList.append({ ui->stackedWidget,34});
        myTabWidgetsList.append({ ui->tabWidget_5, 0 });
        mypushButtonsList.append({ ui->pushButton_169, true }); // Add the specific button
        myLineEditsList.append({ ui->lineEdit_53, true }); // Add the specific line edit
    }
    else if(LinMax=="")
    {
        msgboxtext="Please enter linear maximum.";
        msgicondata="notification";
        mypushButtonsList.clear(); // Clear existing lists
        myLineEditsList.clear();
        myStackedWidgetsList.clear();
        myTabWidgetsList.clear();
        myStackedWidgetsList.append({ ui->stackedWidget,34});
        myTabWidgetsList.append({ ui->tabWidget_5, 0 });
        mypushButtonsList.append({ ui->pushButton_168, true }); // Add the specific button
        myLineEditsList.append({ ui->lineEdit_54, true }); // Add the specific line edit
    }
    else if(NorMin=="")
    {
        msgboxtext="Please enter normal minimum.";
        msgicondata="notification";
        mypushButtonsList.clear(); // Clear existing lists
        myLineEditsList.clear();
        myStackedWidgetsList.clear();
        myTabWidgetsList.clear();
        myStackedWidgetsList.append({ ui->stackedWidget,34});
        myTabWidgetsList.append({ ui->tabWidget_5, 0 });
        mypushButtonsList.append({ ui->pushButton_170, true }); // Add the specific button
        myLineEditsList.append({ ui->lineEdit_55, true }); // Add the specific line edit
    }
    else if(NorMax=="")
    {
        msgboxtext="Please enter normal maximum.";
        msgicondata="notification";
        mypushButtonsList.clear(); // Clear existing lists
        myLineEditsList.clear();
        myStackedWidgetsList.clear();
        myTabWidgetsList.clear();
        myStackedWidgetsList.append({ ui->stackedWidget,34});
        myTabWidgetsList.append({ ui->tabWidget_5, 1 });
        mypushButtonsList.append({ ui->pushButton_300, true }); // Add the specific button
        myLineEditsList.append({ ui->lineEdit_56, true }); // Add the specific line edit
    }
    else if(Batch_No=="")
    {
        msgboxtext="Please enter batch no.";
        msgicondata="notification";
        mypushButtonsList.clear(); // Clear existing lists
        myLineEditsList.clear();
        myStackedWidgetsList.clear();
        myTabWidgetsList.clear();
        myStackedWidgetsList.append({ ui->stackedWidget,34});
        myTabWidgetsList.append({ ui->tabWidget_5, 1 });
        mypushButtonsList.append({ ui->pushButton_306, true }); // Add the specific button
        myLineEditsList.append({ ui->lineEdit_155, true }); // Add the specific line edit
    }
    else if(Ctrl1Min=="")
    {
        msgboxtext="Please enter control1-minimum.";
        msgicondata="notification";
        mypushButtonsList.clear(); // Clear existing lists
        myLineEditsList.clear();
        myStackedWidgetsList.clear();
        myTabWidgetsList.clear();
        myStackedWidgetsList.append({ ui->stackedWidget,34});
        myTabWidgetsList.append({ ui->tabWidget_5, 2 });
        mypushButtonsList.append({ ui->pushButton_199, true }); // Add the specific button
        myLineEditsList.append({ ui->lineEdit_64, true }); // Add the specific line edit
        Call_Msg_box();
    }
    else if(Ctrl1Max=="")
    {
        msgboxtext="Please enter control1-maximum.";
        msgicondata="notification";
        mypushButtonsList.clear(); // Clear existing lists
        myLineEditsList.clear();
        myStackedWidgetsList.clear();
        myTabWidgetsList.clear();
        myStackedWidgetsList.append({ ui->stackedWidget,34});
        myTabWidgetsList.append({ ui->tabWidget_5, 2 });
        mypushButtonsList.append({ ui->pushButton_319, true }); // Add the specific button
        myLineEditsList.append({ ui->lineEdit_151, true }); // Add the specific line edit
        Call_Msg_box();
    }
    else if(Ctrl1Bno=="")
    {
        msgboxtext="Please enter control1-lotno.";
        msgicondata="notification";
        mypushButtonsList.clear(); // Clear existing lists
        myLineEditsList.clear();
        myStackedWidgetsList.clear();
        myTabWidgetsList.clear();
        myStackedWidgetsList.append({ ui->stackedWidget,34});
        myTabWidgetsList.append({ ui->tabWidget_5, 2 });
        mypushButtonsList.append({ ui->pushButton_318, true }); // Add the specific button
        myLineEditsList.append({ ui->lineEdit_65, true }); // Add the specific line edit
        Call_Msg_box();
    }
    else if(Ctrl2Min=="")
    {
        msgboxtext="Please enter control2-minimum.";
        msgicondata="notification";
        mypushButtonsList.clear(); // Clear existing lists
        myLineEditsList.clear();
        myStackedWidgetsList.clear();
        myTabWidgetsList.clear();
        myStackedWidgetsList.append({ ui->stackedWidget,34});
        myTabWidgetsList.append({ ui->tabWidget_5, 2 });
        mypushButtonsList.append({ ui->pushButton_320, true }); // Add the specific button
        myLineEditsList.append({ ui->lineEdit_66, true }); // Add the specific line edit
        Call_Msg_box();
    }
    else if(Ctrl2Max=="")
    {
        msgboxtext="Please enter control2-maximum.";
        msgicondata="notification";
        mypushButtonsList.clear(); // Clear existing lists
        myLineEditsList.clear();
        myStackedWidgetsList.clear();
        myTabWidgetsList.clear();
        myStackedWidgetsList.append({ ui->stackedWidget,34});
        myTabWidgetsList.append({ ui->tabWidget_5, 2 });
        mypushButtonsList.append({ ui->pushButton_323, true }); // Add the specific button
        myLineEditsList.append({ ui->lineEdit_156, true }); // Add the specific line edit
        Call_Msg_box();
    }
    else if(Ctrl2Bno=="")
    {
        msgboxtext="Please enter control2-lotno.";
        msgicondata="notification";
        mypushButtonsList.clear(); // Clear existing lists
        myLineEditsList.clear();
        myStackedWidgetsList.clear();
        myTabWidgetsList.clear();
        myStackedWidgetsList.append({ ui->stackedWidget,34});
        myTabWidgetsList.append({ ui->tabWidget_5, 2 });
        mypushButtonsList.append({ ui->pushButton_322, true }); // Add the specific button
        myLineEditsList.append({ ui->lineEdit_98, true }); // Add the specific line edit
        Call_Msg_box();
    }

    else if(No_of_cal=="1")
    {
        if(Cal1=="")
        {
            msgboxtext="Please enter cal1.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,34});
            myTabWidgetsList.append({ ui->tabWidget_5, 1 });
            mypushButtonsList.append({ ui->pushButton_307, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_120, true }); // Add the specific line edit
        }
        else
            Data_Updation();
    }
    else if(No_of_cal=="2")
    {
        if(Cal1=="")
        {
            msgboxtext="Please enter cal1.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,34});
            myTabWidgetsList.append({ ui->tabWidget_5, 1 });
            mypushButtonsList.append({ ui->pushButton_307, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_120, true }); // Add the specific line edit
        }
        else if(Cal2=="")
        {
            msgboxtext="Please enter cal2.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,34});
            myTabWidgetsList.append({ ui->tabWidget_5, 1 });
            mypushButtonsList.append({ ui->pushButton_313, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_124, true }); // Add the specific line edit
        }
        else
            Data_Updation();
    }
    else if(No_of_cal=="3")
    {
        if(Cal1=="")
        {
            msgboxtext="Please enter cal1.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,34});
            myTabWidgetsList.append({ ui->tabWidget_5, 1 });
            mypushButtonsList.append({ ui->pushButton_307, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_120, true }); // Add the specific line edit
        }
        else if(Cal2=="")
        {
            msgboxtext="Please enter cal2.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,34});
            myTabWidgetsList.append({ ui->tabWidget_5, 1 });
            mypushButtonsList.append({ ui->pushButton_313, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_124, true }); // Add the specific line edit
        }
        else if(Cal3=="")
        {
            msgboxtext="Please enter cal3.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,34});
            myTabWidgetsList.append({ ui->tabWidget_5, 1 });
            mypushButtonsList.append({ ui->pushButton_311, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_121, true }); // Add the specific line edit
        }
        else
            Data_Updation();
    }
    else if(No_of_cal=="4")
    {
        if(Cal1=="")
        {
            msgboxtext="Please enter cal1.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,34});
            myTabWidgetsList.append({ ui->tabWidget_5, 1 });
            mypushButtonsList.append({ ui->pushButton_307, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_120, true }); // Add the specific line edit
        }
        else if(Cal2=="")
        {
            msgboxtext="Please enter cal2.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,34});
            myTabWidgetsList.append({ ui->tabWidget_5, 1 });
            mypushButtonsList.append({ ui->pushButton_313, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_124, true }); // Add the specific line edit
        }
        else if(Cal3=="")
        {
            msgboxtext="Please enter cal3.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,34});
            myTabWidgetsList.append({ ui->tabWidget_5, 1 });
            mypushButtonsList.append({ ui->pushButton_311, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_121, true }); // Add the specific line edit
        }
        else if(Cal4=="")
        {
            msgboxtext="Please enter cal4.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,34});
            myTabWidgetsList.append({ ui->tabWidget_5, 1 });
            mypushButtonsList.append({ ui->pushButton_317, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_127, true }); // Add the specific line edit
        }
        else
            Data_Updation();
    }
    else if(No_of_cal=="5")
    {
        if(Cal1=="")
        {
            msgboxtext="Please enter cal1.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,34});
            myTabWidgetsList.append({ ui->tabWidget_5, 1 });
            mypushButtonsList.append({ ui->pushButton_307, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_120, true }); // Add the specific line edit
        }
        else if(Cal2=="")
        {
            msgboxtext="Please enter cal2.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,34});
            myTabWidgetsList.append({ ui->tabWidget_5, 1 });
            mypushButtonsList.append({ ui->pushButton_313, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_124, true }); // Add the specific line edit
        }
        else if(Cal3=="")
        {
            msgboxtext="Please enter cal3.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,34});
            myTabWidgetsList.append({ ui->tabWidget_5, 1 });
            mypushButtonsList.append({ ui->pushButton_311, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_121, true }); // Add the specific line edit
        }
        else if(Cal4=="")
        {
            msgboxtext="Please enter cal4.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,34});
            myTabWidgetsList.append({ ui->tabWidget_5, 1 });
            mypushButtonsList.append({ ui->pushButton_317, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_127, true }); // Add the specific line edit
        }
        else if(Cal5=="")
        {
            msgboxtext="Please enter cal5.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,34});
            myTabWidgetsList.append({ ui->tabWidget_5, 1 });
            mypushButtonsList.append({ ui->pushButton_308, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_122, true }); // Add the specific line edit
        }
        else
            Data_Updation();
    }
    else if(No_of_cal=="6")
    {
        if(Cal1=="")
        {
            msgboxtext="Please enter cal1.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,34});
            myTabWidgetsList.append({ ui->tabWidget_5, 1 });
            mypushButtonsList.append({ ui->pushButton_307, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_120, true }); // Add the specific line edit
        }
        else if(Cal2=="")
        {
            msgboxtext="Please enter cal2.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,34});
            myTabWidgetsList.append({ ui->tabWidget_5, 1 });
            mypushButtonsList.append({ ui->pushButton_313, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_124, true }); // Add the specific line edit
        }
        else if(Cal3=="")
        {
            msgboxtext="Please enter cal3.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,34});
            myTabWidgetsList.append({ ui->tabWidget_5, 1 });
            mypushButtonsList.append({ ui->pushButton_311, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_121, true }); // Add the specific line edit
        }
        else if(Cal4=="")
        {
            msgboxtext="Please enter cal4.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,34});
            myTabWidgetsList.append({ ui->tabWidget_5, 1 });
            mypushButtonsList.append({ ui->pushButton_317, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_127, true }); // Add the specific line edit
        }
        else if(Cal5=="")
        {
            msgboxtext="Please enter cal5.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,34});
            myTabWidgetsList.append({ ui->tabWidget_5, 1 });
            mypushButtonsList.append({ ui->pushButton_308, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_122, true }); // Add the specific line edit
        }
        else if(Cal6=="")
        {
            msgboxtext="Please enter cal6.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,34});
            myTabWidgetsList.append({ ui->tabWidget_5, 1 });
            mypushButtonsList.append({ ui->pushButton_314, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_126, true }); // Add the specific line edit
        }
        else
            Data_Updation();
    }
    else if(No_of_cal=="7")
    {
        if(Cal1=="")
        {
            msgboxtext="Please enter cal1.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,34});
            myTabWidgetsList.append({ ui->tabWidget_5, 1 });
            mypushButtonsList.append({ ui->pushButton_307, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_120, true }); // Add the specific line edit
        }
        else if(Cal2=="")
        {
            msgboxtext="Please enter cal2.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,34});
            myTabWidgetsList.append({ ui->tabWidget_5, 1 });
            mypushButtonsList.append({ ui->pushButton_313, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_124, true }); // Add the specific line edit
        }
        else if(Cal3=="")
        {
            msgboxtext="Please enter cal3.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,34});
            myTabWidgetsList.append({ ui->tabWidget_5, 1 });
            mypushButtonsList.append({ ui->pushButton_311, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_121, true }); // Add the specific line edit
        }
        else if(Cal4=="")
        {
            msgboxtext="Please enter cal4.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,34});
            myTabWidgetsList.append({ ui->tabWidget_5, 1 });
            mypushButtonsList.append({ ui->pushButton_317, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_127, true }); // Add the specific line edit
        }
        else if(Cal5=="")
        {
            msgboxtext="Please enter cal5.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,34});
            myTabWidgetsList.append({ ui->tabWidget_5, 1 });
            mypushButtonsList.append({ ui->pushButton_308, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_122, true }); // Add the specific line edit
        }
        else if(Cal6=="")
        {
            msgboxtext="Please enter cal6.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,34});
            myTabWidgetsList.append({ ui->tabWidget_5, 1 });
            mypushButtonsList.append({ ui->pushButton_314, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_126, true }); // Add the specific line edit
        }
        else if(Cal7=="")
        {
            msgboxtext="Please enter cal7.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,34});
            myTabWidgetsList.append({ ui->tabWidget_5, 1 });
            mypushButtonsList.append({ ui->pushButton_310, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_123, true }); // Add the specific line edit
        }
        else
            Data_Updation();
    }
    else if(No_of_cal=="8")
    {
        if(Cal1=="")
        {
            msgboxtext="Please enter cal1.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,34});
            myTabWidgetsList.append({ ui->tabWidget_5, 1 });
            mypushButtonsList.append({ ui->pushButton_307, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_120, true }); // Add the specific line edit
        }
        else if(Cal2=="")
        {
            msgboxtext="Please enter cal2.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,34});
            myTabWidgetsList.append({ ui->tabWidget_5, 1 });
            mypushButtonsList.append({ ui->pushButton_313, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_124, true }); // Add the specific line edit
        }
        else if(Cal3=="")
        {
            msgboxtext="Please enter cal3.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,34});
            myTabWidgetsList.append({ ui->tabWidget_5, 1 });
            mypushButtonsList.append({ ui->pushButton_311, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_121, true }); // Add the specific line edit
        }
        else if(Cal4=="")
        {
            msgboxtext="Please enter cal4.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,34});
            myTabWidgetsList.append({ ui->tabWidget_5, 1 });
            mypushButtonsList.append({ ui->pushButton_317, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_127, true }); // Add the specific line edit
        }
        else if(Cal5=="")
        {
            msgboxtext="Please enter cal5.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,34});
            myTabWidgetsList.append({ ui->tabWidget_5, 1 });
            mypushButtonsList.append({ ui->pushButton_308, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_122, true }); // Add the specific line edit
        }
        else if(Cal6=="")
        {
            msgboxtext="Please enter cal6.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,34});
            myTabWidgetsList.append({ ui->tabWidget_5, 1 });
            mypushButtonsList.append({ ui->pushButton_314, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_126, true }); // Add the specific line edit
        }
        else if(Cal7=="")
        {
            msgboxtext="Please enter cal7.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,34});
            myTabWidgetsList.append({ ui->tabWidget_5, 1 });
            mypushButtonsList.append({ ui->pushButton_310, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_123, true }); // Add the specific line edit
        }
        else if(Cal8=="")
        {
            msgboxtext="Please enter cal8.";
            msgicondata="notification";
            mypushButtonsList.clear(); // Clear existing lists
            myLineEditsList.clear();
            myStackedWidgetsList.clear();
            myTabWidgetsList.clear();
            myStackedWidgetsList.append({ ui->stackedWidget,34});
            myTabWidgetsList.append({ ui->tabWidget_5, 1 });
            mypushButtonsList.append({ ui->pushButton_312, true }); // Add the specific button
            myLineEditsList.append({ ui->lineEdit_125, true }); // Add the specific line edit
        }
        else
            Data_Updation();
    }
    else
        Data_Updation();
}

void MainWindow::Data_store()
{
    QString Testname, TestCode,Wave,Unit,Temp,Fact,Blank,Incubation,Graph_Type,No_of_cal,Cal1,Cal2,Cal3,Cal4,Cal5,Cal6,Cal7,Cal8,Abs1,Abs2,Abs3,Abs4,Abs5,Abs6,Abs7,Abs8,Fact1,Fact2,Fact3,Fact4,Fact5,Fact6,Fact7,Fact8,LinMin,LinMax,NorMin,NorMax,Ctrl1Avg,Ctrl1Min,Ctrl1Max,Ctrl1Bno,Ctrl2Avg,Ctrl2Min,Ctrl2Max,Ctrl2Bno,Batch_No,RecentCNT,OldAbs1,OldAbs2,OldAbs3,OldAbs4,OldAbs5,OldAbs6,OldAbs7,OldAbs8,Cal1_Date,Cal2_Date,Cal3_Date,Cal4_Date,Cal5_Date,Cal6_Date,Cal7_Date,Cal8_Date,Rctn_type,After_Incu, Direct_read;
    QString Infant_Min,Infant_Max,Child_Min,Child_Max,Female_Min,Female_Max;
    QString Cal1_ExDate,Cal2_ExDate,Cal3_ExDate,Cal4_ExDate,Cal5_ExDate,Cal6_ExDate,Cal7_ExDate,Cal8_ExDate,Intensity,Slope,Intercept,A_Val,B_Val,C_Val,D_Val,G_Val;

    Testname=ui->lineEdit_14->text();
    TestCode=ui->lineEdit_43->text();
    Wave=ui->label_206->text();
    Unit=ui->lineEdit_21->text();
    Temp=ui->label_371->text();
    Fact=ui->lineEdit_22->text();
    Blank=" ";
    Incubation=ui->lineEdit_25->text();
    After_Incu=ui->lineEdit_170->text();
    Direct_read=ui->lineEdit_169->text();
    Graph_Type= ui->Graph_Type->currentText();

    No_of_cal=ui->comboBox_20->currentText();
    Cal1=ui->lineEdit_99->text();
    Cal2=ui->lineEdit_103->text();
    Cal3=ui->lineEdit_100->text();
    Cal4=ui->lineEdit_106->text();
    Cal5=ui->lineEdit_101->text();
    Cal6=ui->lineEdit_105->text();
    Cal7=ui->lineEdit_102->text();
    Cal8=ui->lineEdit_104->text();

    LinMin=ui->lineEdit_31->text();
    LinMax=ui->lineEdit_32->text();

    Infant_Min=ui->lineEdit_134->text();
    Infant_Max=ui->lineEdit_135->text();
    Child_Min=ui->lineEdit_148->text();
    Child_Max=ui->lineEdit_158->text();
    NorMin=ui->lineEdit_38->text();
    NorMax=ui->lineEdit_37->text();
    Female_Min=ui->lineEdit_159->text();
    Female_Max=ui->lineEdit_160->text();

    Ctrl1Min=ui->lineEdit_39->text();
    Ctrl1Max=ui->lineEdit_145->text();
    Ctrl1Avg=ui->label_461->text();
    Ctrl1Bno=ui->lineEdit_40->text();
    Ctrl2Min=ui->lineEdit_41->text();
    Ctrl2Max=ui->label_146->text();
    Ctrl2Avg=ui->label_463->text();
    Ctrl2Bno=ui->lineEdit_44->text();
    Batch_No=ui->lineEdit_154->text();
    QString DCMotor_speed="0";
    RecentCNT ="0000000";

    Abs1= " ";
    Abs2= " ";
    Abs3= " ";
    Abs4= " ";
    Abs5= " ";
    Abs6= " ";
    Abs7= " ";
    Abs8= " ";

    Fact1=" ";
    Fact2=" ";
    Fact3=" ";
    Fact4=" ";
    Fact5=" ";
    Fact6=" ";
    Fact7=" ";
    Fact8=" ";

    OldAbs1=" ";
    OldAbs2=" ";
    OldAbs3=" ";
    OldAbs4=" ";
    OldAbs5=" ";
    OldAbs6=" ";
    OldAbs7=" ";
    OldAbs8=" ";

    Cal1_Date=" ";
    Cal2_Date=" ";
    Cal3_Date=" ";
    Cal4_Date=" ";
    Cal5_Date=" ";
    Cal6_Date=" ";
    Cal7_Date=" ";
    Cal8_Date=" ";

    Cal1_ExDate=" ";
    Cal2_ExDate=" ";
    Cal3_ExDate=" ";
    Cal4_ExDate=" ";
    Cal5_ExDate=" ";
    Cal6_ExDate=" ";
    Cal7_ExDate=" ";
    Cal8_ExDate=" ";
    Intensity=" ";
    Slope=" ";
    Intercept=" ";
    A_Val=" ";
    B_Val=" ";
    C_Val=" ";
    D_Val=" ";
    G_Val=" ";
    Rctn_type=ui->Reaction_Type->currentText();

    if(Ctrl1Min=="")
    {
        msgboxtext="Please enter control1-minimum.";
        msgicondata="notification";
        mypushButtonsList.clear(); // Clear existing lists
        myLineEditsList.clear();
        myStackedWidgetsList.clear();
        myTabWidgetsList.clear();
        myStackedWidgetsList.append({ ui->stackedWidget,33});
        myTabWidgetsList.append({ ui->tabWidget_3, 2 });
        mypushButtonsList.append({ ui->pushButton_162, true }); // Add the specific button
        myLineEditsList.append({ ui->lineEdit_39, true }); // Add the specific line edit
    }
    else if(Ctrl1Max=="")
    {
        msgboxtext="Please enter control1-maximum.";
        msgicondata="notification";
        mypushButtonsList.clear(); // Clear existing lists
        myLineEditsList.clear();
        myStackedWidgetsList.clear();
        myTabWidgetsList.clear();
        myStackedWidgetsList.append({ ui->stackedWidget,33});
        myTabWidgetsList.append({ ui->tabWidget_3, 2 });
        mypushButtonsList.append({ ui->pushButton_284, true }); // Add the specific button
        myLineEditsList.append({ ui->lineEdit_145, true }); // Add the specific line edit
    }
    else if(Ctrl1Bno=="")
    {
        msgboxtext="Please enter control1-lotno.";
        msgicondata="notification";
        mypushButtonsList.clear(); // Clear existing lists
        myLineEditsList.clear();
        myStackedWidgetsList.clear();
        myTabWidgetsList.clear();
        myStackedWidgetsList.append({ ui->stackedWidget,33});
        myTabWidgetsList.append({ ui->tabWidget_3, 2 });
        mypushButtonsList.append({ ui->pushButton_165, true }); // Add the specific button
        myLineEditsList.append({ ui->lineEdit_40, true }); // Add the specific line edit

    }
    else if(Ctrl2Min=="")
    {
        msgboxtext="Please enter control2-minimum.";
        msgicondata="notification";
        mypushButtonsList.clear(); // Clear existing lists
        myLineEditsList.clear();
        myStackedWidgetsList.clear();
        myTabWidgetsList.clear();
        myStackedWidgetsList.append({ ui->stackedWidget,33});
        myTabWidgetsList.append({ ui->tabWidget_3, 2 });
        mypushButtonsList.append({ ui->pushButton_166, true }); // Add the specific button
        myLineEditsList.append({ ui->lineEdit_41, true }); // Add the specific line edit

    }
    else if(Ctrl2Max=="")
    {
        msgboxtext="Please enter control2-maximum.";
        msgicondata="notification";
        mypushButtonsList.clear(); // Clear existing lists
        myLineEditsList.clear();
        myStackedWidgetsList.clear();
        myTabWidgetsList.clear();
        myStackedWidgetsList.append({ ui->stackedWidget,33});
        myTabWidgetsList.append({ ui->tabWidget_3, 2 });
        mypushButtonsList.append({ ui->pushButton_285, true }); // Add the specific button
        myLineEditsList.append({ ui->lineEdit_146, true }); // Add the specific line edit

    }
    else if(Ctrl2Bno=="")
    {
        msgboxtext="Please enter control2-lotno.";
        msgicondata="notification";
        mypushButtonsList.clear(); // Clear existing lists
        myLineEditsList.clear();
        myStackedWidgetsList.clear();
        myTabWidgetsList.clear();
        myStackedWidgetsList.append({ ui->stackedWidget,33});
        myTabWidgetsList.append({ ui->tabWidget_3, 2 });
        mypushButtonsList.append({ ui->pushButton_167, true }); // Add the specific button
        myLineEditsList.append({ ui->lineEdit_44, true }); // Add the specific line edit

    }
    else
    {
        QSqlQuery qry;
        qry.prepare("insert into Turbidity_test(TestName,TestCode,Wave,Unit,Temp,Fact,Blank,Incubation,Graph_Type,No_of_Cal,Cal1,Cal2,Cal3,Cal4,Cal5,Cal6,Cal7,Cal8,Abs1,Abs2,Abs3,Abs4,Abs5,Abs6,Abs7,Abs8,Fact1,Fact2,Fact3,Fact4,Fact5,Fact6,Fact7,Fact8,LinMin,LinMax,NorMin,NorMax,Ctrl1Avg,Ctrl1Min,Ctrl1Max,Ctrl1Bno,Ctrl2Avg,Ctrl2Min,Ctrl2Max,Ctrl2Bno,Batch_No,RecentCNT,Old_Abs1,Old_Abs2,Old_Abs3,Old_Abs4,Old_Abs5,Old_Abs6,Old_Abs7,Old_Abs8,Cal1_Date,Cal2_Date,Cal3_Date,Cal4_Date,Cal5_Date,Cal6_Date,Cal7_Date,Cal8_Date,Cal1_ExDate,Cal2_ExDate,Cal3_ExDate,Cal4_ExDate,Cal5_ExDate,Cal6_ExDate,Cal7_ExDate,Cal8_ExDate,Intensity,Slope,Intercept,A_Val,B_Val,C_Val,D_Val,G_Val,Reaction_Type,Infant_Nmin,Infant_Nmax,Child_Nmin,Child_Nmax,Female_Nmin,Female_Nmax,DCMotor_Instensity,IncuR2,DirRead) values(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)");
        qry.addBindValue(Testname);
        qry.addBindValue(TestCode);
        qry.addBindValue(Wave);
        qry.addBindValue(Unit);
        qry.addBindValue(Temp);
        qry.addBindValue(Fact);
        qry.addBindValue(Blank);
        qry.addBindValue(Incubation);
        qry.addBindValue(Graph_Type);
        qry.addBindValue(No_of_cal);
        qry.addBindValue(Cal1);
        qry.addBindValue(Cal2);
        qry.addBindValue(Cal3);
        qry.addBindValue(Cal4);
        qry.addBindValue(Cal5);
        qry.addBindValue(Cal6);
        qry.addBindValue(Cal7);
        qry.addBindValue(Cal8);
        qry.addBindValue(Abs1);
        qry.addBindValue(Abs2);
        qry.addBindValue(Abs3);
        qry.addBindValue(Abs4);
        qry.addBindValue(Abs5);
        qry.addBindValue(Abs6);
        qry.addBindValue(Abs7);
        qry.addBindValue(Abs8);
        qry.addBindValue(Fact1);
        qry.addBindValue(Fact2);
        qry.addBindValue(Fact3);
        qry.addBindValue(Fact4);
        qry.addBindValue(Fact5);
        qry.addBindValue(Fact6);
        qry.addBindValue(Fact7);
        qry.addBindValue(Fact8);
        qry.addBindValue(LinMin);
        qry.addBindValue(LinMax);
        qry.addBindValue(NorMin);
        qry.addBindValue(NorMax);
        qry.addBindValue(Ctrl1Bno);
        qry.addBindValue(Ctrl1Min);
        qry.addBindValue(Ctrl1Max);
        qry.addBindValue(Ctrl1Avg);
        qry.addBindValue(Ctrl2Bno);
        qry.addBindValue(Ctrl2Min);
        qry.addBindValue(Ctrl2Max);
        qry.addBindValue(Ctrl2Avg);
        qry.addBindValue(Batch_No);
        qry.addBindValue(RecentCNT);
        qry.addBindValue(OldAbs1);
        qry.addBindValue(OldAbs2);
        qry.addBindValue(OldAbs3);
        qry.addBindValue(OldAbs4);
        qry.addBindValue(OldAbs5);
        qry.addBindValue(OldAbs6);
        qry.addBindValue(OldAbs7);
        qry.addBindValue(OldAbs8);
        qry.addBindValue(Cal1_Date);
        qry.addBindValue(Cal2_Date);
        qry.addBindValue(Cal3_Date);
        qry.addBindValue(Cal4_Date);
        qry.addBindValue(Cal5_Date);
        qry.addBindValue(Cal6_Date);
        qry.addBindValue(Cal7_Date);
        qry.addBindValue(Cal8_Date);
        qry.addBindValue(Cal1_ExDate);
        qry.addBindValue(Cal2_ExDate);
        qry.addBindValue(Cal3_ExDate);
        qry.addBindValue(Cal4_ExDate);
        qry.addBindValue(Cal5_ExDate);
        qry.addBindValue(Cal6_ExDate);
        qry.addBindValue(Cal7_ExDate);
        qry.addBindValue(Cal8_ExDate);
        qry.addBindValue(Intensity);
        qry.addBindValue(Slope);
        qry.addBindValue(Intercept);
        qry.addBindValue(A_Val);
        qry.addBindValue(B_Val);
        qry.addBindValue(C_Val);
        qry.addBindValue(D_Val);
        qry.addBindValue(G_Val);
        qry.addBindValue(Rctn_type);
        qry.addBindValue(Infant_Min);
        qry.addBindValue(Infant_Max);
        qry.addBindValue(Child_Min);
        qry.addBindValue(Child_Max);
        qry.addBindValue(Female_Min);
        qry.addBindValue(Female_Max);
        qry.addBindValue(DCMotor_speed);
        qry.addBindValue(After_Incu);
        qry.addBindValue(Direct_read);
        if(qry.exec())
        {
            QMessageBox msg(this);
            msg.setWindowFlags(Qt::Popup);
            msg.setStyleSheet("font: 75 20pt Liberation Serif ;");
            msg.setStyleSheet("font:16pt Arial;");
            msg.setText("New test added.");
            QPixmap p("/home/pi/git/BCYWithTRY/BCYWithTRY/img/check-mark.png");
            auto newPixmap = p.scaled(45, 45);
            msg.setIconPixmap(newPixmap);
            msg.setStandardButtons(QMessageBox::Ok);
            if(msg.exec()==QMessageBox::Ok)
            {
                ui->stackedWidget->setCurrentIndex(0);
                qDebug()<<"Ok";
            }
        }
    }
}

void MainWindow::Data_Updation()
{
    QString Testname, TestCode,Wave,Unit,Temp,Fact,Blank,Incubation,Graph_Type,No_of_cal,Cal1,Cal2,Cal3,Cal4,Cal5,Cal6,Cal7,Cal8,LinMin,LinMax,NorMin,NorMax,Ctrl1Avg,Ctrl1Min,Ctrl1Max,Ctrl1Bno,Ctrl2Avg,Ctrl2Min,Ctrl2Max,Ctrl2Bno,Batch_No,Rctn_type,After_Incu, Direct_Read;
    QString Infant_Min,Infant_Max,Child_Min,Child_Max,Female_Min,Female_Max;
    Testname=ui->label_468->text();
    TestCode=ui->label_469->text();
    Wave=ui->label_470->text();
    Unit=ui->lineEdit_47->text();
    Temp=ui->label_471->text();
    Fact=ui->lineEdit_48->text();
    Blank=" ";
    Incubation=ui->lineEdit_61->text();
    After_Incu=ui->lineEdit_173->text();
    Direct_Read=ui->lineEdit_171->text();
    Graph_Type=ui->Graph_Type_2->currentText();
    No_of_cal=ui->comboBox_21->currentText();
    Cal1=ui->lineEdit_120->text();
    Cal2=ui->lineEdit_124->text();
    Cal3=ui->lineEdit_121->text();
    Cal4=ui->lineEdit_127->text();
    Cal5=ui->lineEdit_122->text();
    Cal6=ui->lineEdit_126->text();
    Cal7=ui->lineEdit_123->text();
    Cal8=ui->lineEdit_125->text();
    LinMin=ui->lineEdit_53->text();
    LinMax=ui->lineEdit_54->text();
    Infant_Min=ui->lineEdit_163->text();
    Infant_Max=ui->lineEdit_164->text();
    Child_Min=ui->lineEdit_165->text();
    Child_Max=ui->lineEdit_166->text();
    NorMin=ui->lineEdit_55->text();
    NorMax=ui->lineEdit_56->text();
    Female_Min=ui->lineEdit_167->text();
    Female_Max=ui->lineEdit_168->text();
    Ctrl1Avg=ui->label_505->text();
    Ctrl1Min=ui->lineEdit_64->text();
    Ctrl1Max=ui->lineEdit_151->text();
    Ctrl1Bno=ui->lineEdit_65->text();
    Ctrl2Avg=ui->label_510->text();
    Ctrl2Min=ui->lineEdit_66->text();
    Ctrl2Max=ui->lineEdit_156->text();
    Ctrl2Bno=ui->lineEdit_98->text();
    Rctn_type=ui->Reaction_Type_2->currentText();
    Batch_No=ui->lineEdit_155->text();
    QString DCMotor="";
    QString ProductCode;
    QSqlQuery qqry;
    qqry.prepare("select * from Turbidity_test where TestName ='"+TestName+"'");
    qqry.exec();
    while(qqry.next())
    {
        ProductCode = qqry.value(2).toString();
    }
    QMessageBox msg(this);
    msg.setWindowFlags(Qt::Popup);
    msg.setStyleSheet("font: 75 20pt Liberation Serif ;");
    QPixmap p("/home/pi/git/BCYWithTRY/BCYWithTRY/img/notification.png");
    auto newPixmap = p.scaled(80, 80);
    msg.setIconPixmap(newPixmap);
    QFont font;
    font.setBold(true);
    msg.setFont(font);
    msg.setText(" Are you sure you want to update data ?");
    msg.setStandardButtons(QMessageBox::Ok |  QMessageBox::Cancel);
    msg.setButtonText(QMessageBox::Ok , "Yes");
    msg.setButtonText(QMessageBox::Cancel , "Go back");
    msg.setFixedWidth(500);
    int result = msg.exec();
    if (result == QMessageBox::Ok)
    {
        QString Data=" ";
        QSqlQuery qrry;

        qrry.prepare("update Turbidity_test set TestName='"+Testname+"' where TestCode ='"+ProductCode+"");
        qrry.exec();
        QSqlQuery query;
        query.prepare("update Turbidity_test set TestName='"+Testname+"',Unit='"+Unit+"',Wave='"+Wave+"',Temp='"+Temp+"', Fact='"+Fact+"',Blank='"+Blank+"',Incubation='"+Incubation+"',Graph_Type='"+Graph_Type+"',Linmin='"+LinMin+"', Linmax='"+LinMax+"', Normin='"+NorMin+"', Normax='"+NorMax+"', No_of_Cal='"+No_of_cal+"',Cal1='"+Cal1+"',Cal2='"+Cal2+"',Cal3='"+Cal3+"',Cal4='"+Cal4+"',Cal5='"+Cal5+"',Cal6='"+Cal6+"',Cal7='"+Cal7+"',Cal8='"+Cal8+"',Ctrl1Avg='"+Ctrl1Avg+"', Ctrl1Min='"+Ctrl1Min+"',Ctrl1max='"+Ctrl1Max+"', Ctrl1Bno='"+Ctrl1Bno+"', Ctrl2Avg='"+Ctrl2Avg+"', Ctrl2Min='"+Ctrl2Min+"', Ctrl2Max='"+Ctrl2Max+"',Ctrl2Bno='"+Ctrl2Bno+"',Batch_No='"+Batch_No+"',Reaction_Type='"+Rctn_type+"',Infant_Nmin='"+Infant_Min+"', Infant_Nmax='"+Infant_Max+"', Child_Nmin='"+Child_Min+"', Child_Nmax='"+Child_Max+"',Female_Nmin='"+Female_Min+"', Female_Nmax='"+Female_Max+"', DCMotor_Instensity='"+DCMotor+"', IncuR2='"+After_Incu+"', DirRead='"+Direct_Read+"' where TestName='"+TestName+"'");
        if(query.exec())
        {

            QMessageBox msg(this);
            msg.setWindowFlags(Qt::Popup);
            msg.setStyleSheet("font: 75 20pt Liberation Serif ;");
            QPixmap p("/home/pi/git/BCYWithTRY/BCYWithTRY/img/check-mark.png");
            auto newPixmap = p.scaled(80, 80);
            msg.setIconPixmap(newPixmap);
            QFont font;
            font.setBold(true);
            msg.setFont(font);
            msg.setText(" Data updated.");
            msg.setStandardButtons(QMessageBox::Ok);
            msg.setFixedWidth(500);
            if(msg.exec() == QMessageBox::Ok)
            {
                qDebug()<<"Update done";
                ui->stackedWidget->setCurrentIndex(0);
            }
        }
    }
}
