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
static QString arrayval[100]={""};

#define LED 26
#define LED_BASE 200
void MainWindow::on_toolButton_6_clicked()
{
    ui->stackedWidget_11->setVisible(false);
    testback=1;
    tabtest=1;
    tabrecent=0;
    tabedit=0;
    tabdelete=0;
    tabqc=0;
    tabfilter=0;
    exptopn=0;
    ui->pushButton_6->setVisible(true);
    ui->pushButton_139->setVisible(true);
    ui->pushButton_142->setVisible(false);
    if(Test_Type=="Biochemistry")
        on_pushButton_6_clicked();
    else if(Test_Type=="Turbidity")
        Listout_Turbidity_Parameter();

    ui->label_59->clear();
    ui->progressBar_2->setVisible(false);
    ui->pushButton_6->setStyleSheet("QPushButton {border: 2px solid green;border-top-left-radius:40px;border-top-right-radius:40px;background-color: white;padding: 10px;}");
    ui->pushButton_139->setStyleSheet("QPushButton {border: 2px solid black;border-top-left-radius:40px;border-top-right-radius:40px;background-color: #d0d5d6;padding: 10px;}");
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::Listout_Turbidity_Parameter()
{
    ui->stackedWidget->setCurrentIndex(1);
    clearGridLayout(ui->gridLayout_2);
    ui->Home_Lbl_2->setText("Select parameter to test");
    ui->pushButton_6->setStyleSheet("QPushButton {border: 2px solid green;border-top-left-radius:40px;border-top-right-radius:40px;background-color: white;padding: 10px;}");
    ui->pushButton_139->setStyleSheet("QPushButton {border: 2px solid black;border-top-left-radius:40px;border-top-right-radius:40px;background-color: #d0d5d6;padding: 10px;}");
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
    qDebug()<<"Objdel : "<<Objdel;
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
                connect(button, &QPushButton::clicked, this,&MainWindow::cald);
                ui->gridLayout_2->addWidget(button,i,j);
                count1++;
            }
            qDebug()<<"..";
            if(nextnumber==1)
            {
                QLayoutItem *child;
                while ((child = ui->gridLayout_2->takeAt(Objdel)) != nullptr)
                {
                    delete child->widget(); // delete the widget
                    delete child;   // delete the layout item
                }
                nextnumber=0;
            }
        }
    }
}

void MainWindow::cald()
{
    qApp->processEvents();
    QSqlQuery query;
    QObject *senderObj = sender(); // This will give Sender object
    QString senderObjName = senderObj->objectName();
    TestName=senderObjName;
    QString name, unit , Fact , Rctn , EndPoint , TwoPoint, Kinetic , Blnk , Calibrate , wave , Pro_Code ;

    unsigned int fact = 0  , blnk = 0 , Cal = 0 ;
    Fact = char (fact);
    Blnk =  char (blnk);
    Calibrate = char (Cal);
    if(Test_Type=="Biochemistry")
    {
        query.prepare("select wave,Pro_Code from test where name = :name");
        query.bindValue(":name",TestName);
        if(!query.exec())
        {
            qDebug()<<"Query Error : "<<query.lastError().text();
            return;
        }
        else if(query.next())
        {
            wave=query.value(0).toString();
            Pro_Code=query.value(1).toString();
        }
        else
        {
            qDebug()<<"No record found for Name : "<<TestName;
            return;
        }
        qDebug()<<"Wave : "<<wave<<" Pro_code : "<<Pro_Code<<Run_DW340<<Run_DW405<<Run_DW505<<Run_DW545<<Run_DW570<<Run_DW630<<Run_DW700<<"sno : "<<Auto_cal_sno;
        Prod_Code = Pro_Code;
        nanometer = wave;
        handleWave_cald(wave);
    }
    else if(Test_Type=="Turbidity")
    {
        tested();
    }
}

void MainWindow::handleWave_cald(const QString &wave) {
    struct WaveData {
        int sno;
        int gainVal;
        int internFirst;
        int internSecond;
        QString autocalString;
        int *incrementData; // Change reference to pointer
    };
    Loop_data=0;
    // Define wave-specific parameters
    QMap<QString, WaveData> waveParams = {
        {"340 nm", {1, w340, FrstInternval, SecInternval, "340nm", &Increament_data340}},
        {"405 nm", {2, w405, ThreeInternval, FourInternval, "405nm", &Increament_data405}},
        {"505 nm", {3, w505, FiveInternval, SixInternval, "505nm", &Increament_data505}},
        {"545 nm", {4, w545, SevenInternval, EightInternval, "545nm", &Increament_data545}},
        {"570 nm", {5, w570, NineInternval, TenInternval, "570nm", &Increament_data570}},
        {"630 nm", {6, w630, EleInternval, TweInternval, "630nm", &Increament_data630}},
        {"700 nm", {7, w700, ThirInternval, ForInternval, "700nm", &Increament_data700}}
    };

    if (!waveParams.contains(wave))
    {
        if(wave == "340 nm")
        {
            if(Run_DW340==1)
                handleWave(wave);
            else if(Run_DW340==2)
                Glucose_Check();
        }
        else if(wave == "405 nm")
        {
            if(Run_DW405==1)
                handleWave(wave);
            else if(Run_DW405==2)
                Glucose_Check();
        }
        else if(wave == "505 nm")
        {
            if(Run_DW505==1)
                handleWave(wave);
            else if(Run_DW505==2)
                Glucose_Check();
        }
        else if(wave == "545 nm")
        {
            if(Run_DW545==1)
                handleWave(wave);
            else if(Run_DW545==2)
                Glucose_Check();
        }
        else if(wave == "570 nm")
        {
            if(Run_DW570==1)
                handleWave(wave);
            else if(Run_DW570==2)
                Glucose_Check();
        }
        else if(wave == "630 nm")
        {
            if(Run_DW630==1)
                handleWave(wave);
            else if(Run_DW630==2)
                Glucose_Check();
        }
        else if(wave == "700 nm")
        {
            if(Run_DW700==1)
                handleWave(wave);
            else if(Run_DW700==2)
                Glucose_Check();
        }
        return;
    }

    WaveData &data = waveParams[wave];
    if (*data.incrementData != 0)
    { // Dereference the pointer
        if(wave == "340 nm")
        {
            if(Run_DW340==1)
                handleWave(wave);
            else if(Run_DW340==2)
                Glucose_Check();
        }
        else if(wave == "405 nm")
        {
            if(Run_DW405==1)
                handleWave(wave);
            else if(Run_DW405==2)
                Glucose_Check();
        }
        else if(wave == "505 nm")
        {
            if(Run_DW505==1)
                handleWave(wave);
            else if(Run_DW505==2)
                Glucose_Check();
        }
        else if(wave == "545 nm")
        {
            if(Run_DW545==1)
                handleWave(wave);
            else if(Run_DW545==2)
                Glucose_Check();
        }
        else if(wave == "570 nm")
        {
            if(Run_DW570==1)
                handleWave(wave);
            else if(Run_DW570==2)
                Glucose_Check();
        }
        else if(wave == "630 nm")
        {
            if(Run_DW630==1)
                handleWave(wave);
            else if(Run_DW630==2)
                Glucose_Check();
        }
        else if(wave == "700 nm")
        {
            if(Run_DW700==1)
                handleWave(wave);
            else if(Run_DW700==2)
                Glucose_Check();
        }
        return;
    }

    // Assign calibration values
    Auto_cal_sno = data.sno;
    Autocal_Gainval = data.gainVal;
    Autocal_Intern_First = data.internFirst;
    Autocal_Intern_Second = data.internSecond;
    Autocal_String = data.autocalString;
    ui->frame_9->setDisabled(true);
    ui->pushButton_6->setDisabled(true);
    ui->pushButton_139->setDisabled(true);
    ui->Home_Btn_2->setDisabled(true);
    ui->progressBar_2->setValue(0);
    ui->label_257->setText(Autocal_String);
    ui->label_59->clear();
    Autocal_click=1;
    Start_Loop_Calibrate->start(1000);
    // ui->frame_9->setVisible(false);
    Circle_Progress_Update();
    ui->stackedWidget_11->setGeometry(215,170,373,113);
    ui->stackedWidget_11->setVisible(true);
}

void MainWindow::handleWave(const QString& wave)
{
    QMap<QString, int> waveMap = {
        {"340 nm", 1},
        {"405 nm", 2},
        {"505 nm", 3},
        {"545 nm", 4},
        {"570 nm", 5},
        {"630 nm", 6},
        {"700 nm", 7}
    };

    if (!waveMap.contains(wave)) {
        qDebug() << "Unknown wave:" << wave;
        return;
    }

    int waveIndex = waveMap[wave];
    qDebug()<<"WaveIndex : "<<waveIndex;
    Wave_LED_OFF();
    setWaveLED(wave);

    int blankVal = 0;
    fetchWaveData(waveIndex, blankVal);

    if (blankVal == 0)
    {
        runTest(waveIndex);
    }
    else {
        if (isValidBlankVal(blankVal)) {
            Glucose_Check();
        } else {
            handleInvalidBlankVal(waveIndex);
        }
    }
}

void MainWindow::fetchWaveData(int waveIndex, int blankVal)
{
    QSqlQuery query;
    query.prepare("SELECT blankval FROM tests WHERE sno = :sno");
    query.bindValue(":sno", waveIndex);
    if (!query.exec()) {
        qDebug() << "Error fetching wave data:" << query.lastError().text();
        return;
    }
    while (query.next()) {
        blankVal = query.value(0).toInt();
    }
    qDebug()<<"Blank val fetch "<<blankVal;
}

void MainWindow::setWaveLED(const QString& wave)
{
    if (wave == "340 nm") Wave_LED_340();
    else if (wave == "405 nm") Wave_LED_405();
    else if (wave == "505 nm") Wave_LED_505();
    else if (wave == "545 nm") Wave_LED_545();
    else if (wave == "570 nm") Wave_LED_570();
    else if (wave == "630 nm") Wave_LED_630();
    else if (wave == "700 nm") Wave_LED_700();
}

bool MainWindow::isValidBlankVal(int blankVal)
{
    return blankVal <= endvl && blankVal >= startvl;
}

void MainWindow::handleInvalidBlankVal(int waveIndex)
{
    QLabel* label = nullptr;
    switch (waveIndex) {
    case 1: label = ui->label_114; break;
    case 2: label = ui->label_115; break;
    case 3: label = ui->label_117; break;
    case 4: label = ui->label_118; break;
    case 5: label = ui->label_124; break;
    case 6: label = ui->label_126; break;
    case 7: label = ui->label_183; break;
    }

    if (!label) return;

    QString blankVal = label->text();
    label->clear();
    QSqlQuery query;
    query.prepare("UPDATE tests SET blankval = :blankVal WHERE sno = :sno");
    query.bindValue(":blankVal", blankVal);
    query.bindValue(":sno", waveIndex);
    if (!query.exec()) {
        qDebug() << "Error updating blank value:" << query.lastError().text();
    }

    runTest(waveIndex);
}

void MainWindow::runTest(int waveIndex)
{
    switch (waveIndex) {
    case 1: test340(); break;
    case 2: test405(); break;
    case 3: test505(); break;
    case 4: test545(); break;
    case 5: test570(); break;
    case 6: test630(); break;
    case 7: test700(); break;
    }
}

void MainWindow::runQualityCheck(const QString &wave, int sno, QLabel *label, int readWave)
{
    // Create and configure the initial quality check message box
    QMessageBox msg(this);
    msg.setWindowFlags(Qt::Popup);
    msg.setStyleSheet("background-color: rgb(206, 230, 255);font: 75 20pt Liberation Serif;");
    QPixmap shieldPixmap("/home/pi/git/BCYWithTRY/BCYWithTRY/img/Shield.png");
    msg.setIconPixmap(shieldPixmap.scaled(80, 80));
    msg.setText(QString("Quality check - %1\n\nRun distilled water").arg(wave));
    QPushButton* saveButton = msg.addButton("Run", QMessageBox::AcceptRole);
    saveButton->setStyleSheet("QPushButton{background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 #34ba91, stop: 0.5 #34ba91, stop: 1 #34ba91);color:black;}QPushButton:pressed {background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(0, 85, 0), stop: 0.5 rgb(0, 85, 0), stop: 1 rgb(0, 85, 0));color:white;}");
    QPushButton* dontSaveButton = msg.addButton("Back", QMessageBox::DestructiveRole);
    dontSaveButton->setStyleSheet("QPushButton{background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 #ff5957, stop: 0.5 #ff5957, stop: 1 #ff5957);color:black;}QPushButton:pressed{background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(184, 0, 0), stop: 0.5 rgb(184, 0, 0), stop: 1 rgb(184, 0, 0)); color:white;}");
    msg.setDefaultButton(saveButton);
    msg.exec();
    if (msg.clickedButton() == saveButton)
    {
        QString wavelength , intensity,Blankval;
        // Perform database query
        QSqlQuery query;
        // Start transaction
        query.exec("BEGIN TRANSACTION;");
        query.prepare("SELECT intensity,wave FROM tests WHERE sno = :sno");
        query.bindValue(":sno", sno);
        if(!query.exec())
        {
            qDebug()<<"Query Error : "<<query.lastError().text();
            query.exec("ROLLBACK;");
        }
        else if(query.next())
        {
            intensity = query.value(0).toString();
            wavelength = query.value(1).toString();
        }
        else
        {
            qDebug()<<"No record found for Testname : "<<TestName;
        }

        read_intensity = intensity.toInt();
        if (wavelength == wave)
            read_wave = readWave;

        if(wave=="340 nm")
        {

            read_wavenm=0;
        }
        else if(wave=="405 nm")
        {

            read_wavenm=1;
        }
        else if(wave=="505 nm")
        {
                   read_wavenm=2;
        }
        else if(wave=="545 nm")
        {
            read_wavenm=3;
        }
        else if(wave=="570 nm")
        {
            read_wavenm=4;
        }
        else if(wave=="630 nm")
        {
            read_wavenm=5;
        }
        else if(wave=="700 nm")
        {
            read_wavenm=6;
        }

        // Simulate reading intensity
        filtwave[0] = reading1();
        int currentWaveValue = filtwave[0];
        label->setNum(currentWaveValue);
        qDebug()<<"Run Distilled Blankval : "<<currentWaveValue<<" wavelength : "<<wavelength;
        // Update blank value in the database
        QString blankVal = QString::number(currentWaveValue);
        query.prepare("UPDATE tests SET blankval = :blankVal WHERE sno = :sno");
        query.bindValue(":blankVal", blankVal);
        query.bindValue(":sno", sno);
        if (!query.exec())
        {
            qDebug()<<"Query Error : "<<query.lastError().text();
            query.exec("ROLLBACK;");
        }
        else
        {
            qDebug()<<"Update done";
        }

        // Perform quality check
        if (currentWaveValue >= startvl && currentWaveValue <= endvl)
        {
            showQualityCheckResult(wave, "PASS", "/home/pi/git/BCYWithTRY/BCYWithTRY/img/check-mark.png");
            Glucose_Check();

            if(wave=="340 nm")
                Run_DW340=2;
            else if(wave=="405 nm")
                Run_DW405=2;
            else if(wave=="505 nm")
                Run_DW505=2;
            else if(wave=="545 nm")
                Run_DW545=2;
            else if(wave=="570 nm")
                Run_DW570=2;
            else if(wave=="630 nm")
                Run_DW630=2;
            else if(wave=="700 nm")
                Run_DW700=2;


            Autocal_click=0;
            ui->frame_9->setDisabled(false);
            ui->pushButton_6->setDisabled(false);
            ui->pushButton_139->setDisabled(false);
            ui->Home_Btn_2->setDisabled(false);
        }
        else
        {
            QString errorMessage = currentWaveValue > endvl
                    ? "Intensity value - HIGH\n\nContact Service Team"
                    : "Intensity value - LOW\n\nContact Service Team";
            showQualityCheckResult(wave, "FAILED\n\n" + errorMessage, "/home/pi/git/BCYWithTRY/BCYWithTRY/img/cancel.png");
            QString Data="";
            query.prepare("UPDATE tests SET blankval = :blankVal WHERE sno = :sno");
            query.bindValue(":blankVal", Data);
            query.bindValue(":sno", sno);
            if (!query.exec())
            {
                qDebug()<<"Query Error : "<<query.lastError().text();
                query.exec("ROLLBACK;");
            }
            else
            {
                qDebug()<<"Update done";
            }
            Autocal_click=1;

            if(wave=="340 nm")
                Run_DW340=1;
            else if(wave=="405 nm")
                Run_DW405=1;
            else if(wave=="505 nm")
                Run_DW505=1;
            else if(wave=="545 nm")
                Run_DW545=1;
            else if(wave=="570 nm")
                Run_DW570=1;
            else if(wave=="630 nm")
                Run_DW630=1;
            else if(wave=="700 nm")
                Run_DW700=1;


            ui->stackedWidget->setCurrentIndex(1);
        }
        // Commit the transaction if all queries succeed
        query.exec("COMMIT;");
    }
    else if(msg.clickedButton() == dontSaveButton)
    {
        if(wave=="340 nm")
            Run_DW340=1;
        else if(wave=="405 nm")
            Run_DW405=1;
        else if(wave=="505 nm")
            Run_DW505=1;
        else if(wave=="545 nm")
            Run_DW545=1;
        else if(wave=="570 nm")
            Run_DW570=1;
        else if(wave=="630 nm")
            Run_DW630=1;
        else if(wave=="700 nm")
            Run_DW700=1;

        Autocal_click=1;
        Wave_LED_OFF();
        ui->frame_9->setDisabled(false);
        ui->pushButton_6->setDisabled(false);
        ui->pushButton_139->setDisabled(false);
        ui->Home_Btn_2->setDisabled(false);
        ui->stackedWidget_11->setVisible(false);
        ui->stackedWidget->setCurrentIndex(1);
    }
}

void MainWindow::showQualityCheckResult(const QString &wave, const QString &status, const QString &iconPath)
{
    QMessageBox * msg = new QMessageBox(this);
    msg->setWindowFlags(Qt::Popup);
    msg->setStyleSheet("background-color:#a0cdfa;font: 75 20pt Liberation Serif ;");
    QPixmap resultPixmap(iconPath);
    msg->setIconPixmap(resultPixmap.scaled(80, 80));
    msg->setText(QString("Internal quality check - %1\n\n%2").arg(wave, status));
    QPushButton* saveButton = msg->addButton("Ok", QMessageBox::AcceptRole);
    saveButton->setStyleSheet("QPushButton{background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 #34ba91, stop: 0.5 #34ba91, stop: 1 #34ba91);color:black;}QPushButton:pressed {background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(0, 85, 0), stop: 0.5 rgb(0, 85, 0), stop: 1 rgb(0, 85, 0));color:white;}");
    msg->setDefaultButton(saveButton);
    msg->exec();
    if (msg->clickedButton() == saveButton)
    {
        ui->stackedWidget_11->setVisible(false);
        Wave_LED();
        ui->frame_9->setDisabled(false);
        ui->pushButton_6->setDisabled(false);
        ui->pushButton_139->setDisabled(false);
        ui->Home_Btn_2->setDisabled(false);
        ui->stackedWidget->setCurrentIndex(1);
    }
    else
        qDebug()<<"Out side click";
}

void MainWindow::test340()
{
    runQualityCheck("340 nm", 1, ui->label_114, 7);
}

void MainWindow::test405()
{
    runQualityCheck("405 nm", 2, ui->label_115, 6);
}

void MainWindow::test505()
{
    runQualityCheck("505 nm", 3, ui->label_117, 5);
}

void MainWindow::test545()
{
    runQualityCheck("545 nm", 4, ui->label_118, 4);
}

void MainWindow::test570()
{
    runQualityCheck("570 nm", 5, ui->label_124, 3);
}

void MainWindow::test630()
{
    runQualityCheck("630 nm", 6, ui->label_126, 2);
}

void MainWindow::test700()
{
    runQualityCheck("700 nm", 7, ui->label_183, 0);
}

void MainWindow::tested()
{
    if(Test_Type=="Biochemistry")
    {
        int RecentCNT=0;
        QString Pro_Code;
        double ctrl1min=0 , ctrl1max=0 , ctrl2min=0,ctrl2max=0;
        QString name, unit , Fact , Rctn , EndPoint , TwoPoint, Kinetic , Blnk , Calibrate;
        unsigned int fact = 0  , blnk = 0 , Cal = 0 ;
        int Wave=0,No_std=0;
        Fact = char (fact);
        Blnk =  char (blnk);
        Calibrate = char (Cal);
        QSqlQuery query;

        query.exec("BEGIN TRANSACTION;");
        query.prepare("select Pro_Code,RecentCNT,ctrl1min,ctrl1max,ctrl2min,ctrl2max,unit,rctn,fact,blnkval,calibrateabs,wave,nostd from test where name = :name");
        query.bindValue(":name",TestName);
        if(!query.exec())
        {
            qDebug()<<"Query Error : "<<query.lastError().text();
            query.exec("ROLLBACK;");
        }
        else if(query.next())
        {
            Pro_Code=query.value(0).toString();
            RecentCNT=query.value(1).toInt();
            ctrl1min=query.value(2).toDouble();
            ctrl1max=query.value(3).toDouble();
            ctrl2min=query.value(4).toDouble();
            ctrl2max=query.value(5).toDouble();
            unit=query.value(6).toString();
            Rctn=query.value(7).toString();
            Fact = query.value(8).toString();
            Blnk = query.value(9).toString();
            Calibrate = query.value(10).toString();
            Wave= query.value(11).toInt();
            No_std=query.value(12).toInt();

        }
        else
        {
            qDebug()<<"No record found for Name : "<<TestName;
        }
        qDebug()<<"enter : "<<Pro_Code<<Blnk;
        if(No_std>1)
        {
            Multi_calibration=1;
            ui->RunCal_Btn->setText("New \n Std / Cal");
            ui->RunCal_Btn_2->setText("New \n Std / Cal");
        }
        else
        {
            Multi_calibration=2;
            ui->RunCal_Btn->setText("Run \n Std / Cal");
            ui->RunCal_Btn_2->setText("Run \n Std / Cal");
        }
        qDebug()<<"Data : "<<Multi_calibration;
        if(RecentCNT==0)
        {
            RecentCNT=1;
            QString   data = QString::number(RecentCNT).rightJustified(7, '0');
            query.prepare("update test set RecentCNT='"+data+"' where name='"+TestName+"'");
            query.exec();
        }
        else if(RecentCNT>=5000000)
        {
            RecentCNT=1;
            QString   data = QString::number(RecentCNT).rightJustified(7, '0');
            query.prepare("update test set RecentCNT='"+data+"' where name='"+TestName+"'");
            query.exec();
        }
        else
        {
            RecentCNT++;
            QString   data = QString::number(RecentCNT).rightJustified(7, '0');
            query.prepare("update test set RecentCNT='"+data+"' where name='"+TestName+"'");
            query.exec();
        }
        query.exec("COMMIT;");

        ui->label_33->clear();
        ui->label_6->clear();
        ui->label_208->clear();
        ui->label_120->clear();
        ui->label_122->clear();
        ui->label_119->clear();
        ui->label_106->clear();
        ui->label_121->clear();
        ui->label_123->clear();
        ui->label_125->clear();
        ui->label_127->clear();
        ui->label_128->clear();
        ui->label_204->clear();
        ui->label_195->clear();
        ui->label_194->clear();
        ui->label_198->clear();
        ui->PatientInfo_LineEdit->clear();

        ui->label_234->clear();
        ui->label_276->clear();
        ui->label_278->clear();
        ui->label_277->clear();

        name=ui->TestName_Lbl->text();
        ui->customPlot->setToolTip("");
        ui->label_272->setText(unit);
        ui->Unit_lineEdit_8->setText(unit);
        ui->label->setText(Blnk);
        ui->label_240->setText(Blnk);
        ui->label_196->setText(Fact);
        ui->label_76->setText(Fact);
        ui->label_242->setText(Fact);
        ui->label_223->setText(Fact);
        ui->label_225->setText(Fact);
        ui->label_277->setText(QString::number(ctrl2min));
        ui->label_278->setText(QString::number(ctrl2max));
        QString EQC = ui->comboBox->currentText();
        QString TKQC = ui->comboBox_2->currentText();

        if(Rctn == "End point" )
        {
            Obj_data=0;
            ui->TestName_Lbl->setText(TestName);
            ui->comboBox->setCurrentIndex(0);
            ui->Retest_5->setEnabled(true);
            clearGraph_end();
            QString EQC ;
            EQC=ui->comboBox->currentText();
            if(EQC=="QC - 1")
            {
                ui->label_274->setText(QString::number(ctrl1min,'f',2));
                ui->label_275->setText(QString::number(ctrl1max,'f',2));
                if(qc1retestbtn==1)
                {
                    ui->Retest_3->setDisabled(false);
                }
                else if(qc1retestbtn==0)
                {
                    ui->Retest_3->setDisabled(true);
                }
            }
            else if(EQC=="QC - 2")
            {
                ui->label_274->setText(QString::number(ctrl2min,'f',2));
                ui->label_275->setText(QString::number(ctrl2max,'f',2));

                if(qc2retestbtn==1)
                {
                    ui->Retest_3->setDisabled(false);
                }
                else if(qc2retestbtn==0)
                {
                    ui->Retest_3->setDisabled(true);
                }
            }
            ui->Stop_Btn->setDisabled(true);
            ui->Stop_Btn_2->setDisabled(true);
            ui->Home_Btn_3->setVisible(true);
            ui->Home_Btn_3->setEnabled(true);
            ui->RunSample_Btn->setDisabled(false);
            ui->RunSample_Btn_2->setDisabled(false);
            ui->label_6->setVisible(false);
            ui->Save_Btn->setEnabled(true);
            ui->label_203->setVisible(false);
            ui->label_204->setVisible(false);
            ui->label_12->clear();
            ui->label_32->clear();
            ui->Retest->setEnabled(false);
            ui->Retest->setVisible(true);
            ui->Retest_3->setEnabled(false);
            ui->Retest_4->setEnabled(false);
            ui->Retest_4->setVisible(true);
            // End_Point Btn Hide
            ui->TestName_Lbl->setVisible(true);
            ui->Patient_Info_Lbl_4->setVisible(true);
            ui->pushButton_117->setVisible(true);
            ui->PatientInfo_LineEdit->setVisible(true);
            ui->RunBlank_Btn->setVisible(true);
            ui->label_193->setVisible(false);
            ui->label->setVisible(false);
            ui->RunCal_Btn->setVisible(true);
            ui->RunBlank_Btn->setEnabled(true);
            ui->RunCal_Btn->setEnabled(true);
            ui->RunSample_Btn->setEnabled(true);
            ui->E_QC_Check->setEnabled(true);
            ui->label_100->setVisible(false);
            ui->label_239->setVisible(true);
            ui->label_240->setVisible(true);
            ui->label_34->setVisible(false);
            ui->label_196->setVisible(false);
            ui->Save_Btn_5->setVisible(false);
            ui->RunSample_Btn->setVisible(true);
            ui->label_33->setVisible(true);
            ui->label_272->setVisible(true);
            ui->Print_Btn->setVisible(false);
            ui->label_6->setVisible(false);
            ui->label_207->setVisible(false);
            ui->label_209->setVisible(false);
            ui->label_7->setVisible(false);
            ui->label_32->setVisible(false);
            ui->label_12->setVisible(false);
            ui->label_34->clear();
            ui->label_196->clear();
            ui->label_208->setVisible(false);
            ui->label_106->setVisible(false);
            ui->label_120->setVisible(false);
            ui->label_121->setVisible(false);
            ui->label_122->setVisible(false);
            ui->label_123->setVisible(false);
            ui->label_125->setVisible(false);
            ui->label_194->setVisible(false);
            ui->label_195->setVisible(false);
            ui->label_198->setVisible(false);
            ui->comboBox->setVisible(true);
            ui->comboBox->setEnabled(true);
            ui->label_228->setVisible(true);
            ui->label_229->setVisible(true);
            ui->label_273->setVisible(true);
            ui->label_230->setVisible(true);
            ui->label_274->setVisible(true);
            ui->label_232->setVisible(true);
            ui->label_275->setVisible(true);
            ui->label_231->setVisible(true);
            ui->Retest_3->setVisible(true);
            ui->comboBox_2->setVisible(false);
            ui->label_234->setVisible(false);
            ui->label_238->setVisible(false);
            ui->label_276->setVisible(false);
            ui->label_237->setVisible(false);
            ui->label_277->setVisible(false);
            ui->label_236->setVisible(false);
            ui->label_278->setVisible(false);
            ui->label_235->setVisible(false);
            ui->label_254->setVisible(false);
            ui->label_256->setVisible(false);
            // Two_Point Btn Hide
            ui->RunCal_Btn_2->setVisible(false);
            ui->label_197->setVisible(false);
            ui->Save_Btn_6->setVisible(false);
            ui->RunSample_Btn_2->setVisible(false);
            ui->Print_Btn->setVisible(false);
            ui->label_120->setVisible(false);
            ui->label_122->setVisible(false);
            ui->label_72->setVisible(false);
            ui->label_119->setVisible(false);
            //Kinetic Btn _Hide
            ui->label_98->setVisible(false);
            ui->label_75->setVisible(false);
            ui->label_106->setVisible(false);
            ui->label_121->setVisible(false);
            ui->label_123->setVisible(false);
            ui->label_125->setVisible(false);
            ui->label_97->setVisible(false);
            ui->label_127->setVisible(false);
            ui->label_98->setVisible(false);
            ui->label_128->setVisible(false);
            ui->label_99->setVisible(false);
            ui->label_132->setVisible(false);
            ui->label_243->setVisible(false);
            ui->label_241->setVisible(false);
            ui->label_242->setVisible(false);
            ui->comboBox->setVisible(true);
            ui->label_229->setVisible(true);
            ui->label_228->setVisible(true);
            ui->label_230->setVisible(true);
            ui->label_273->setVisible(true);
            ui->label_231->setVisible(true);
            ui->label_274->setVisible(true);
            ui->label_275->setVisible(true);
            ui->label_232->setVisible(true);
            ui->E_QC_Check->setVisible(true);
            ui->comboBox_2->setVisible(false);
            ui->label_238->setVisible(false);
            ui->label_234->setVisible(false);
            ui->label_276->setVisible(false);
            ui->label_237->setVisible(false);
            ui->label_235->setVisible(false);
            ui->label_277->setVisible(false);
            ui->label_236->setVisible(false);
            ui->label_278->setVisible(false);
            ui->TP_QC_Check->setVisible(false);
            if(Fact == "")
            {
                ui->RunBlank_Btn->setEnabled(true);
                ui->RunCal_Btn->setEnabled(true);
                ui->RunSample_Btn->setEnabled(true);
                ui->E_QC_Check->setEnabled(true);
                ui->RunCal_Btn->setVisible(true);
                ui->RunCal_Btn_2->setVisible(false);
                ui->label_226->setText("Abs");
                ui->label_239->setText("Abs");
                ui->label_224->setText(Calibrate);
                ui->label_224->setVisible(true);
                ui->label_225->setVisible(true);
                ui->label_226->setVisible(true);
                ui->label_223->setVisible(false);
                ui->label_34->setVisible(false);
                ui->label_76->setVisible(false);
                ui->RunSample_Btn->setEnabled(true);
                ui->RunSample_Btn_2->setEnabled(true);
                ui->label_227->setVisible(true);
                ui->label_241->setVisible(false);
                ui->label_242->setVisible(false);
                ui->label_243->setVisible(false);
                ui->comboBox->setVisible(true);
                ui->comboBox_2->setVisible(false);
            }
            else
            {
                ui->RunBlank_Btn->setEnabled(true);
                ui->RunCal_Btn->setEnabled(true);
                ui->RunSample_Btn->setEnabled(true);
                ui->E_QC_Check->setEnabled(true);
                ui->RunCal_Btn->setVisible(true);
                ui->RunCal_Btn_2->setVisible(false);
                ui->Save_Btn_5->setVisible(false);
                ui->label_34->setVisible(false);
                ui->label_76->setVisible(false);
                ui->label_100->setVisible(false);
                ui->label_240->setVisible(true);
                ui->label_239->setText("Abs");
                ui->label_241->setText("Factor");
                ui->label_225->setText(Fact);
                ui->label_242->setText(Fact);
                ui->label_223->setVisible(false);
                ui->label_226->setVisible(false);
                ui->label_225->setVisible(false);
                ui->label_224->setVisible(false);
                ui->label_227->setVisible(false);
                ui->label_241->setVisible(true);
                ui->label_242->setVisible(true);
                ui->label_243->setVisible(false);
                ui->comboBox->setVisible(true);
                ui->comboBox_2->setVisible(false);
            }
          //  Counting();
            Wave_LED_OFF();
            Wave_LED();
            ui->stackedWidget->setCurrentIndex(2);
        }
        else if(Rctn == "Fixed Kinetic" || Rctn == "Kinetic")
        {
            if(Rctn=="Fixed Kinetic")
                Obj_data=1;
            else if(Rctn == "Kinetic")
                Obj_data=2;

            ui->TestName_Lbl->setText(TestName);
            clearGraph_end();
            ui->Retest_5->setEnabled(true);
            ui->Home_Btn_3->setVisible(true);
            ui->Home_Btn_3->setEnabled(true);
            ui->comboBox_2->setCurrentIndex(0);
            // Fixed Kinetic //
            QString EQC ;
            EQC=ui->comboBox_2->currentText();
            if(EQC=="QC - 1")
            {
                ui->label_277->setText(QString::number(ctrl1min,'f',2));
                ui->label_278->setText(QString::number(ctrl1max,'f',2));
            }
            else if(EQC=="QC - 2")
            {
                ui->label_277->setText(QString::number(ctrl2min,'f',2));
                ui->label_278->setText(QString::number(ctrl2max,'f',2));
            }
            ui->label_12->clear();
            ui->label_32->clear();
            ui->Stop_Btn_2->setDisabled(true);
            ui->RunSample_Btn->setDisabled(false);
            ui->RunSample_Btn_2->setDisabled(false);
            ui->RunCal_Btn_2->setEnabled(true);
            ui->label_75->setVisible(false);
            ui->label_208->setVisible(false);
            ui->label_209->setVisible(false);
            ui->label_72->setVisible(false);
            ui->label_119->setVisible(false);
            ui->label_12->setVisible(true);
            ui->label_32->setVisible(true);
            ui->TP_QC_Check->setEnabled(true);
            ui->label_239->setVisible(false);
            ui->label_240->setVisible(false);
            ui->Retest->setEnabled(false);
            ui->Retest_3->setEnabled(false);
            ui->Retest_4->setEnabled(false);
            ui->Retest_4->setVisible(false);
            ui->label_254->setVisible(false);
            ui->label_256->setVisible(false);
            // Two_Point Btn Hide
            ui->Retest->setVisible(false);
            ui->TestName_Lbl->setVisible(true);
            ui->Patient_Info_Lbl_4->setVisible(true);
            ui->pushButton_117->setVisible(true);
            ui->PatientInfo_LineEdit->setVisible(true);
            ui->label_197->setVisible(true);
            ui->Save_Btn_6->setVisible(false);
            ui->RunSample_Btn_2->setVisible(true);
            ui->Print_Btn->setVisible(false);
            ui->label_120->setVisible(false);
            ui->label_122->setVisible(false);
            ui->label_34->clear();
            ui->label_196->clear();
            ui->label_203->setVisible(false);
            ui->label_204->setVisible(false);
            // End_Point Btn Hide
            ui->RunBlank_Btn->setVisible(false);
            ui->label->setVisible(true);
            ui->RunCal_Btn->setVisible(false);
            ui->label_100->setVisible(true);
            ui->label_34->setVisible(true);
            ui->label_197->setVisible(false);
            ui->label_207->setVisible(false);
            ui->label_196->setVisible(false);
            ui->Save_Btn_5->setVisible(false);
            ui->RunSample_Btn->setVisible(false);
            ui->label_33->setVisible(true);
            ui->label_272->setVisible(true);
            ui->Print_Btn->setVisible(false);
            ui->label_6->setVisible(false);
            ui->label_7->setVisible(false);
            //Kinetic Btn _Hide
            ui->label_98->setVisible(false);
            ui->label_197->setVisible(false);
            ui->label_106->setVisible(false);
            ui->label_121->setVisible(false);
            ui->label_123->setVisible(false);
            ui->label_125->setVisible(false);
            ui->label_97->setVisible(false);
            ui->label_127->setVisible(false);
            ui->label_98->setVisible(false);
            ui->label_128->setVisible(false);
            ui->label_99->setVisible(false);
            ui->label_132->setVisible(false);
            ui->comboBox->setVisible(false);
            ui->label_228->setVisible(false);
            ui->label_229->setVisible(false);
            ui->label_273->setVisible(false);
            ui->label_230->setVisible(false);
            ui->label_274->setVisible(false);
            ui->label_232->setVisible(false);
            ui->label_275->setVisible(false);
            ui->label_231->setVisible(false);
            ui->Retest_3->setVisible(false);
            ui->comboBox_2->setVisible(true);
            ui->label_234->setVisible(true);
            ui->label_238->setVisible(true);
            ui->label_276->setVisible(true);
            ui->label_237->setVisible(true);
            ui->label_277->setVisible(true);
            ui->label_236->setVisible(true);
            ui->label_278->setVisible(true);
            ui->label_235->setVisible(true);
            ui->label_241->setVisible(false);
            ui->label_242->setVisible(false);
            ui->label_224->setVisible(false);
            ui->E_QC_Check->setVisible(false);
            ui->TP_QC_Check->setVisible(true);
            ui->label_223->setVisible(false);
            if(Fact == "")
            {
                ui->RunCal_Btn_2->setEnabled(true);
                ui->TP_QC_Check->setEnabled(true);
                ui->RunCal_Btn_2->setVisible(true);
                ui->label_203->setText("ΔA/min");
                ui->label_193->setText("Abs");
                ui->label_100->setVisible(false);
                ui->label_193->setVisible((true));
                ui->label_197->setVisible(true);
                ui->label_203->setVisible(false);
                ui->label_204->setVisible(false);
                ui->label_76->setVisible(false);
                ui->label_227->setVisible(false);
                ui->label_224->setVisible(false);
                ui->label_225->setVisible(false);
                ui->label_227->setVisible(false);
                ui->label_223->setVisible(false);
                ui->label_226->setVisible(false);
                ui->label_241->setVisible(false);
                ui->label_242->setVisible(false);
                ui->label_243->setVisible(false);
                ui->RunSample_Btn->setEnabled(true);
                ui->RunSample_Btn_2->setEnabled(true);
                ui->comboBox_2->setVisible(true);
                ui->comboBox->setVisible(false);
            }
            else
            {
                ui->RunCal_Btn_2->setVisible(true);
                ui->RunCal_Btn_2->setEnabled(true);
                ui->TP_QC_Check->setEnabled(true);
                ui->RunSample_Btn_2->setEnabled(true);
                ui->Save_Btn_6->setVisible(false);
                ui->label_243->setVisible(true);
                ui->label_239->setVisible(false);
                ui->label_243->setVisible(true);
                ui->label_100->setVisible(false);
                ui->label_193->setVisible(false);
                ui->label_196->setText(Fact);
                ui->label_76->setText(Fact);
                ui->label_76->setVisible(false);
                ui->label->setVisible(false);
                ui->label_240->setText(Fact);
                ui->label_240->setVisible(true);
                ui->label_241->setVisible(false);
                ui->label_197->setVisible(false);
                ui->label_203->setVisible(false);
                ui->label_204->setVisible(false);
                ui->label_76->setVisible(false);
                ui->label_34->setVisible(false);
                ui->label_227->setVisible(false);
                ui->label_224->setVisible(false);
                ui->label_225->setVisible(false);
                ui->label_227->setVisible(false);
                ui->label_223->setVisible(false);
                ui->label_226->setVisible(false);
                ui->label_196->setVisible(false);
                ui->label_241->setVisible(false);
                ui->label_242->setVisible(false);
                ui->comboBox_2->setVisible(true);
                ui->comboBox->setVisible(false);
            }
            //Counting();
            Wave_LED_OFF();
            Wave_LED();
            ui->stackedWidget->setCurrentIndex(2);
        }
    }
    else if(Test_Type=="Turbidity")
    {
        int RecentCNT=0;
        QSqlQuery query;
        query.exec("BEGIN TRANSACTION;");
        query.prepare("select RecentCNT from Turbidity_test where TestName = :name");
        query.bindValue(":name",TestName);
        if(!query.exec())
        {
            qDebug()<<"Query Error : "<<query.lastError().text();
            query.exec("ROLLBACK;");
        }
        else if(query.next())
        {
            RecentCNT=query.value(0).toInt();

        }
        qDebug()<<"RecentCNt : "<<RecentCNT;
        if(RecentCNT==0)
        {
            RecentCNT=1;
            QString   data = QString::number(RecentCNT).rightJustified(7, '0');
            query.prepare("update Turbidity_test set RecentCNT='"+data+"' where TestName='"+TestName+"'");
            query.exec();
        }
        else if(RecentCNT>=5000000)
        {
            RecentCNT=1;
            QString   data = QString::number(RecentCNT).rightJustified(7, '0');
            query.prepare("update Turbidity_test set RecentCNT='"+data+"' where TestName='"+TestName+"'");
            query.exec();
        }
        else
        {
            RecentCNT++;
            QString   data = QString::number(RecentCNT).rightJustified(7, '0');
            query.prepare("update Turbidity_test set RecentCNT='"+data+"' where TestName='"+TestName+"'");
            query.exec();
        }
        query.exec("COMMIT;");
        Turbi_cal_final=0;
        Turbi_cal_finaled=0;

        ui->Abs_lbl_21->setVisible(true);
        ui->TestName_Lbl_14->setText(TestName);
        QString No_cal,FActor,Unit;
        QSqlQuery qy;
        qy.prepare("select * from Turbidity_test where TestName='"+TestName+"'");
        qy.exec();
        while(qy.next())
        {
            FActor=qy.value(6).toString();
            No_cal=qy.value(10).toString();
            Unit=qy.value(4).toString();
        }
        ui->SampleUnit_Lbl->setText(Unit);
        ui->fct_lbl_val->setText(FActor);
        if(No_cal=="1")
        {
            ui->fct_lbl_val->setVisible(true);
            ui->fct_lbl->setVisible(true);
        }
        else
        {
            ui->fct_lbl_val->setVisible(false);
            ui->fct_lbl->setVisible(false);
        }
        ui->IsIo_lbl->clear();
        ui->OD_lbl_val->clear();
        ui->stackedWidget_13->setCurrentIndex(0);
        ui->stackedWidget_14->setCurrentIndex(0);
        ui->stackedWidget_16->setVisible(false);
        ui->stackedWidget->setCurrentIndex(32);
        Turbidity_NewCal();
    }
}

void MainWindow::Turbidity_NewCal()
{
    QString Cal1,Cal2,Cal3,Cal4,Cal5,Cal6,Cal7,Cal8,Unit1,Unit2,Unit3,Unit4,Unit5,Unit6,Unit7,Unit8,Abs1,Abs2,Abs3,Abs4,Abs5,Abs6,Abs7,Abs8,OldAbs1,OldAbs2,OldAbs3,OldAbs4,OldAbs5,OldAbs6,OldAbs7,OldAbs8;
    QString Cal1_Date,Cal2_Date,Cal3_Date,Cal4_Date,Cal5_Date,Cal6_Date,Cal7_Date,Cal8_Date,Cal1_ExDate,Cal2_ExDate,Cal3_ExDate,Cal4_ExDate,Cal5_ExDate,Cal6_ExDate,Cal7_ExDate,Cal8_ExDate,No_Std_Cal;
    int Intensity=0;
    QSqlQuery qy;
    qy.prepare("select * from Turbidity_test where TestName='"+TestName+"'");
    qy.exec();
    while(qy.next())
    {
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
        OldAbs1=qy.value(49).toString();
        OldAbs2=qy.value(50).toString();
        OldAbs3=qy.value(51).toString();
        OldAbs4=qy.value(52).toString();
        OldAbs5=qy.value(53).toString();
        OldAbs6=qy.value(54).toString();
        OldAbs7=qy.value(55).toString();
        OldAbs8=qy.value(56).toString();

        Unit1=qy.value(4).toString();
        Unit2=qy.value(4).toString();
        Unit3=qy.value(4).toString();
        Unit4=qy.value(4).toString();
        Unit5=qy.value(4).toString();
        Unit6=qy.value(4).toString();
        Unit7=qy.value(4).toString();
        Unit8=qy.value(4).toString();
        Cal1_Date=qy.value(57).toString();
        Cal2_Date=qy.value(58).toString();
        Cal3_Date=qy.value(59).toString();
        Cal4_Date=qy.value(60).toString();
        Cal5_Date=qy.value(61).toString();
        Cal6_Date=qy.value(62).toString();
        Cal7_Date=qy.value(63).toString();
        Cal8_Date=qy.value(64).toString();
        Cal1_ExDate=qy.value(65).toString();
        Cal2_ExDate=qy.value(66).toString();
        Cal3_ExDate=qy.value(67).toString();
        Cal4_ExDate=qy.value(68).toString();
        Cal5_ExDate=qy.value(69).toString();
        Cal6_ExDate=qy.value(70).toString();
        Cal7_ExDate=qy.value(71).toString();
        // Intensity=qy.value(73).toInt();
        Cal8_ExDate=qy.value(72).toString();
        No_Std_Cal=qy.value(10).toString();
    }
    qDebug()<<"Cal1 : "<<Cal1<<" "<<"Cal2 : "<<Cal2<<" "<<"Cal3 : "<<Cal3<<" "<<"Cal4 : "<<Cal4<<" "<<"Cal5 : "<<Cal5<<" "<<"Cal6 : "<<Cal6<<" "<<"Cal7 : "<<Cal7<<" "<<"Cal8 : "<<Cal8;
    qDebug()<<"Abs1 : "<<Abs1<<" "<<"Abs2 : "<<Abs2<<" "<<"Abs3 : "<<Abs3<<" "<<"Abs4 : "<<Abs4<<" "<<"Abs5 : "<<Abs5<<" "<<"Abs6 : "<<Abs6<<" "<<"Abs7 : "<<Abs7<<" "<<"Abs8 : "<<Abs8;
    qDebug()<<"Unit1 : "<<Unit1<<" "<<"Unit2 : "<<Unit2<<" "<<"Unit3 : "<<Unit3<<" "<<"Unit4 : "<<Unit4<<" "<<"Unit5 : "<<Unit5<<" "<<"Unit6 : "<<Unit6<<" "<<"Unit7 : "<<Unit7<<" "<<"Unit8 : "<<Unit8;
    qDebug()<<"Cal1_Date : "<<Cal1_Date<<" "<<"Cal2_Date : "<<Cal2_Date<<" "<<"Cal3_Date : "<<Cal3_Date<<" "<<"Cal4_Date : "<<Cal4_Date<<" "<<"Cal5_Date : "<<Cal5_Date<<" "<<"Cal6_Date : "<<Cal6_Date<<" "<<"Cal7_Date : "<<Cal7_Date<<" "<<"Cal8_Date : "<<Cal8_Date;
    qDebug()<<"Cal1_ExDate : "<<Cal1_ExDate<<" "<<"Cal2_ExDate : "<<Cal2_ExDate<<" "<<"Cal3_ExDate : "<<Cal3_ExDate<<" "<<"Cal4_ExDate : "<<Cal4_ExDate<<" "<<"Cal5_ExDate : "<<Cal5_ExDate<<" "<<"Cal6_ExDate : "<<Cal6_ExDate<<" "<<"Cal7_ExDate : "<<Cal7_ExDate<<" "<<"Cal8_ExDate : "<<Cal8_ExDate;
    QSqlQuery qyy;
    qyy.prepare("select * from Turbidity_test where sno=1");
    qyy.exec();
    while(qyy.next())
        Intensity=qyy.value(73).toInt();
    qDebug()<<"Intensity... : "<<Intensity;
    pwmWrite (LED, Intensity);
    digitalWrite (LED_BASE + 6,HIGH) ;

    ui->Conc1_lbl1->setText(Cal1);
    ui->Conc2_lbl1->setText(Cal2);
    ui->Conc3_lbl1->setText(Cal3);
    ui->Conc4_lbl1->setText(Cal4);
    ui->Conc5_lbl1->setText(Cal5);
    ui->Conc6_lbl1->setText(Cal6);
    ui->Conc7_lbl1->setText(Cal7);
    ui->Conc8_lbl1->setText(Cal8);
    if(No_Std_Cal=="1")
    {

        ui->toolButton_45->setVisible(false);
        ui->toolButton_44->setVisible(false);
        ui->Conc1_lbl1->setVisible(true);
        ui->ISI01_lbl->setVisible(true);
        ui->Unit1_lbl->setVisible(true);
        ui->Expiry1_lbl->setVisible(true);

        ui->Conc2_lbl1->setVisible(false);
        ui->ISI02_lbl->setVisible(false);
        ui->Unit2_lbl->setVisible(false);
        ui->Expiry2_lbl->setVisible(false);

        ui->Conc3_lbl1->setVisible(false);
        ui->ISI03_lbl->setVisible(false);
        ui->Unit3_lbl->setVisible(false);
        ui->Expiry3_lbl->setVisible(false);

        ui->Conc4_lbl1->setVisible(false);
        ui->ISI04_lbl->setVisible(false);
        ui->Unit4_lbl->setVisible(false);
        ui->Expiry4_lbl->setVisible(false);

        ui->Conc5_lbl1->setVisible(false);
        ui->ISI05_lbl->setVisible(false);
        ui->Unit5_lbl->setVisible(false);
        ui->Expiry5_lbl->setVisible(false);

        ui->Conc6_lbl1->setVisible(false);
        ui->ISI06_lbl->setVisible(false);
        ui->Unit6_lbl->setVisible(false);
        ui->Expiry6_lbl->setVisible(false);

        ui->Conc7_lbl1->setVisible(false);
        ui->ISI07_lbl->setVisible(false);
        ui->Unit7_lbl->setVisible(false);
        ui->Expiry7_lbl->setVisible(false);

        ui->Conc8_lbl1->setVisible(false);
        ui->ISI08_lbl->setVisible(false);
        ui->Unit8_lbl->setVisible(false);
        ui->Expiry8_lbl->setVisible(false);

        ui->TestName_Lbl_17->setVisible(true);
        ui->Cal1_lbl->setVisible(true);
        ui->Cal1_TestBtn->setVisible(true);
        ui->lineEdit_24->setVisible(true);

        ui->pushButton_286->setVisible(true);
        ui->pushButton_287->setVisible(false);
        ui->pushButton_288->setVisible(false);
        ui->pushButton_289->setVisible(false);
        ui->pushButton_301->setVisible(false);
        ui->pushButton_302->setVisible(false);
        ui->pushButton_303->setVisible(false);
        ui->pushButton_304->setVisible(false);

        ui->TestName_Lbl_18->setVisible(false);
        ui->Cal2_lbl->setVisible(false);
        ui->Cal2_TestBtn->setVisible(false);
        ui->lineEdit_57->setVisible(false);

        ui->TestName_Lbl_19->setVisible(false);
        ui->Cal3_lbl->setVisible(false);
        ui->Cal3_TestBtn->setVisible(false);
        ui->lineEdit_58->setVisible(false);

        ui->TestName_Lbl_20->setVisible(false);
        ui->Cal4_lbl->setVisible(false);
        ui->Cal4_TestBtn->setVisible(false);
        ui->lineEdit_67->setVisible(false);

        ui->TestName_Lbl_21->setVisible(false);
        ui->Cal5_lbl->setVisible(false);
        ui->Cal5_TestBtn->setVisible(false);
        ui->lineEdit_68->setVisible(false);

        ui->TestName_Lbl_22->setVisible(false);
        ui->Cal6_lbl->setVisible(false);
        ui->Cal6_TestBtn->setVisible(false);
        ui->lineEdit_69->setVisible(false);

        ui->TestName_Lbl_23->setVisible(false);
        ui->Cal7_lbl->setVisible(false);
        ui->Cal7_TestBtn->setVisible(false);
        ui->lineEdit_70->setVisible(false);

        ui->TestName_Lbl_24->setVisible(false);
        ui->Cal8_lbl->setVisible(false);
        ui->Cal8_TestBtn->setVisible(false);
        ui->lineEdit_71->setVisible(false);
    }
    else if(No_Std_Cal=="2")
    {
        ui->toolButton_45->setVisible(false);
        ui->toolButton_44->setVisible(false);

        ui->Conc1_lbl1->setVisible(true);
        ui->ISI01_lbl->setVisible(true);
        ui->Unit1_lbl->setVisible(true);
        ui->Expiry1_lbl->setVisible(true);

        ui->Conc2_lbl1->setVisible(true);
        ui->ISI02_lbl->setVisible(true);
        ui->Unit2_lbl->setVisible(true);
        ui->Expiry2_lbl->setVisible(true);

        ui->pushButton_286->setVisible(true);
        ui->pushButton_287->setVisible(true);
        ui->pushButton_288->setVisible(false);
        ui->pushButton_289->setVisible(false);
        ui->pushButton_301->setVisible(false);
        ui->pushButton_302->setVisible(false);
        ui->pushButton_303->setVisible(false);
        ui->pushButton_304->setVisible(false);

        ui->Conc3_lbl1->setVisible(false);
        ui->ISI03_lbl->setVisible(false);
        ui->Unit3_lbl->setVisible(false);
        ui->Expiry3_lbl->setVisible(false);

        ui->Conc4_lbl1->setVisible(false);
        ui->ISI04_lbl->setVisible(false);
        ui->Unit4_lbl->setVisible(false);
        ui->Expiry4_lbl->setVisible(false);

        ui->Conc5_lbl1->setVisible(false);
        ui->ISI05_lbl->setVisible(false);
        ui->Unit5_lbl->setVisible(false);
        ui->Expiry5_lbl->setVisible(false);

        ui->Conc6_lbl1->setVisible(false);
        ui->ISI06_lbl->setVisible(false);
        ui->Unit6_lbl->setVisible(false);
        ui->Expiry6_lbl->setVisible(false);

        ui->Conc7_lbl1->setVisible(false);
        ui->ISI07_lbl->setVisible(false);
        ui->Unit7_lbl->setVisible(false);
        ui->Expiry7_lbl->setVisible(false);

        ui->Conc8_lbl1->setVisible(false);
        ui->ISI08_lbl->setVisible(false);
        ui->Unit8_lbl->setVisible(false);
        ui->Expiry8_lbl->setVisible(false);

        ui->TestName_Lbl_17->setVisible(true);
        ui->Cal1_lbl->setVisible(true);
        ui->Cal1_TestBtn->setVisible(true);
        ui->lineEdit_24->setVisible(true);

        ui->TestName_Lbl_18->setVisible(true);
        ui->Cal2_lbl->setVisible(true);
        ui->Cal2_TestBtn->setVisible(true);
        ui->lineEdit_57->setVisible(true);

        ui->TestName_Lbl_19->setVisible(false);
        ui->Cal3_lbl->setVisible(false);
        ui->Cal3_TestBtn->setVisible(false);
        ui->lineEdit_58->setVisible(false);

        ui->TestName_Lbl_20->setVisible(false);
        ui->Cal4_lbl->setVisible(false);
        ui->Cal4_TestBtn->setVisible(false);
        ui->lineEdit_67->setVisible(false);

        ui->TestName_Lbl_21->setVisible(false);
        ui->Cal5_lbl->setVisible(false);
        ui->Cal5_TestBtn->setVisible(false);
        ui->lineEdit_68->setVisible(false);

        ui->TestName_Lbl_22->setVisible(false);
        ui->Cal6_lbl->setVisible(false);
        ui->Cal6_TestBtn->setVisible(false);
        ui->lineEdit_69->setVisible(false);

        ui->TestName_Lbl_23->setVisible(false);
        ui->Cal7_lbl->setVisible(false);
        ui->Cal7_TestBtn->setVisible(false);
        ui->lineEdit_70->setVisible(false);

        ui->TestName_Lbl_24->setVisible(false);
        ui->Cal8_lbl->setVisible(false);
        ui->Cal8_TestBtn->setVisible(false);
        ui->lineEdit_71->setVisible(false);
    }
    else if(No_Std_Cal=="3")
    {
        ui->toolButton_45->setVisible(false);
        ui->toolButton_44->setVisible(false);

        ui->Conc1_lbl1->setVisible(true);
        ui->ISI01_lbl->setVisible(true);
        ui->Unit1_lbl->setVisible(true);
        ui->Expiry1_lbl->setVisible(true);

        ui->Conc2_lbl1->setVisible(true);
        ui->ISI02_lbl->setVisible(true);
        ui->Unit2_lbl->setVisible(true);
        ui->Expiry2_lbl->setVisible(true);

        ui->Conc3_lbl1->setVisible(true);
        ui->ISI03_lbl->setVisible(true);
        ui->Unit3_lbl->setVisible(true);
        ui->Expiry3_lbl->setVisible(true);

        ui->pushButton_286->setVisible(true);
        ui->pushButton_287->setVisible(true);
        ui->pushButton_288->setVisible(true);
        ui->pushButton_289->setVisible(false);
        ui->pushButton_301->setVisible(false);
        ui->pushButton_302->setVisible(false);
        ui->pushButton_303->setVisible(false);
        ui->pushButton_304->setVisible(false);

        ui->Conc4_lbl1->setVisible(false);
        ui->ISI04_lbl->setVisible(false);
        ui->Unit4_lbl->setVisible(false);
        ui->Expiry4_lbl->setVisible(false);

        ui->Conc5_lbl1->setVisible(false);
        ui->ISI05_lbl->setVisible(false);
        ui->Unit5_lbl->setVisible(false);
        ui->Expiry5_lbl->setVisible(false);

        ui->Conc6_lbl1->setVisible(false);
        ui->ISI06_lbl->setVisible(false);
        ui->Unit6_lbl->setVisible(false);
        ui->Expiry6_lbl->setVisible(false);

        ui->Conc7_lbl1->setVisible(false);
        ui->ISI07_lbl->setVisible(false);
        ui->Unit7_lbl->setVisible(false);
        ui->Expiry7_lbl->setVisible(false);

        ui->Conc8_lbl1->setVisible(false);
        ui->ISI08_lbl->setVisible(false);
        ui->Unit8_lbl->setVisible(false);
        ui->Expiry8_lbl->setVisible(false);

        ui->TestName_Lbl_17->setVisible(true);
        ui->Cal1_lbl->setVisible(true);
        ui->Cal1_TestBtn->setVisible(true);
        ui->lineEdit_24->setVisible(true);

        ui->TestName_Lbl_18->setVisible(true);
        ui->Cal2_lbl->setVisible(true);
        ui->Cal2_TestBtn->setVisible(true);
        ui->lineEdit_57->setVisible(true);

        ui->TestName_Lbl_19->setVisible(true);
        ui->Cal3_lbl->setVisible(true);
        ui->Cal3_TestBtn->setVisible(true);
        ui->lineEdit_58->setVisible(true);

        ui->TestName_Lbl_20->setVisible(false);
        ui->Cal4_lbl->setVisible(false);
        ui->Cal4_TestBtn->setVisible(false);
        ui->lineEdit_67->setVisible(false);

        ui->TestName_Lbl_21->setVisible(false);
        ui->Cal5_lbl->setVisible(false);
        ui->Cal5_TestBtn->setVisible(false);
        ui->lineEdit_68->setVisible(false);

        ui->TestName_Lbl_22->setVisible(false);
        ui->Cal6_lbl->setVisible(false);
        ui->Cal6_TestBtn->setVisible(false);
        ui->lineEdit_69->setVisible(false);

        ui->TestName_Lbl_23->setVisible(false);
        ui->Cal7_lbl->setVisible(false);
        ui->Cal7_TestBtn->setVisible(false);
        ui->lineEdit_70->setVisible(false);

        ui->TestName_Lbl_24->setVisible(false);
        ui->Cal8_lbl->setVisible(false);
        ui->Cal8_TestBtn->setVisible(false);
        ui->lineEdit_71->setVisible(false);
    }
    else if(No_Std_Cal=="4")
    {
        ui->toolButton_45->setVisible(false);
        ui->toolButton_44->setVisible(false);

        ui->Conc1_lbl1->setVisible(true);
        ui->ISI01_lbl->setVisible(true);
        ui->Unit1_lbl->setVisible(true);
        ui->Expiry1_lbl->setVisible(true);

        ui->Conc2_lbl1->setVisible(true);
        ui->ISI02_lbl->setVisible(true);
        ui->Unit2_lbl->setVisible(true);
        ui->Expiry2_lbl->setVisible(true);

        ui->Conc3_lbl1->setVisible(true);
        ui->ISI03_lbl->setVisible(true);
        ui->Unit3_lbl->setVisible(true);
        ui->Expiry3_lbl->setVisible(true);

        ui->Conc4_lbl1->setVisible(true);
        ui->ISI04_lbl->setVisible(true);
        ui->Unit4_lbl->setVisible(true);
        ui->Expiry4_lbl->setVisible(true);

        ui->pushButton_286->setVisible(true);
        ui->pushButton_287->setVisible(true);
        ui->pushButton_288->setVisible(true);
        ui->pushButton_289->setVisible(true);
        ui->pushButton_301->setVisible(false);
        ui->pushButton_302->setVisible(false);
        ui->pushButton_303->setVisible(false);
        ui->pushButton_304->setVisible(false);

        ui->Conc5_lbl1->setVisible(false);
        ui->ISI05_lbl->setVisible(false);
        ui->Unit5_lbl->setVisible(false);
        ui->Expiry5_lbl->setVisible(false);

        ui->Conc6_lbl1->setVisible(false);
        ui->ISI06_lbl->setVisible(false);
        ui->Unit6_lbl->setVisible(false);
        ui->Expiry6_lbl->setVisible(false);

        ui->Conc7_lbl1->setVisible(false);
        ui->ISI07_lbl->setVisible(false);
        ui->Unit7_lbl->setVisible(false);
        ui->Expiry7_lbl->setVisible(false);

        ui->Conc8_lbl1->setVisible(false);
        ui->ISI08_lbl->setVisible(false);
        ui->Unit8_lbl->setVisible(false);
        ui->Expiry8_lbl->setVisible(false);

        ui->TestName_Lbl_17->setVisible(true);
        ui->Cal1_lbl->setVisible(true);
        ui->Cal1_TestBtn->setVisible(true);
        ui->lineEdit_24->setVisible(true);

        ui->TestName_Lbl_18->setVisible(true);
        ui->Cal2_lbl->setVisible(true);
        ui->Cal2_TestBtn->setVisible(true);
        ui->lineEdit_57->setVisible(true);

        ui->TestName_Lbl_19->setVisible(true);
        ui->Cal3_lbl->setVisible(true);
        ui->Cal3_TestBtn->setVisible(true);
        ui->lineEdit_58->setVisible(true);

        ui->TestName_Lbl_20->setVisible(true);
        ui->Cal4_lbl->setVisible(true);
        ui->Cal4_TestBtn->setVisible(true);
        ui->lineEdit_67->setVisible(true);

        ui->TestName_Lbl_21->setVisible(false);
        ui->Cal5_lbl->setVisible(false);
        ui->Cal5_TestBtn->setVisible(false);
        ui->lineEdit_68->setVisible(false);

        ui->TestName_Lbl_22->setVisible(false);
        ui->Cal6_lbl->setVisible(false);
        ui->Cal6_TestBtn->setVisible(false);
        ui->lineEdit_69->setVisible(false);

        ui->TestName_Lbl_23->setVisible(false);
        ui->Cal7_lbl->setVisible(false);
        ui->Cal7_TestBtn->setVisible(false);
        ui->lineEdit_70->setVisible(false);

        ui->TestName_Lbl_24->setVisible(false);
        ui->Cal8_lbl->setVisible(false);
        ui->Cal8_TestBtn->setVisible(false);
        ui->lineEdit_71->setVisible(false);
    }
    else if(No_Std_Cal=="5")
    {
        ui->toolButton_45->setVisible(true);
        ui->toolButton_44->setVisible(true);

        ui->Conc1_lbl1->setVisible(true);
        ui->ISI01_lbl->setVisible(true);
        ui->Unit1_lbl->setVisible(true);
        ui->Expiry1_lbl->setVisible(true);

        ui->Conc2_lbl1->setVisible(true);
        ui->ISI02_lbl->setVisible(true);
        ui->Unit2_lbl->setVisible(true);
        ui->Expiry2_lbl->setVisible(true);

        ui->Conc3_lbl1->setVisible(true);
        ui->ISI03_lbl->setVisible(true);
        ui->Unit3_lbl->setVisible(true);
        ui->Expiry3_lbl->setVisible(true);

        ui->Conc4_lbl1->setVisible(true);
        ui->ISI04_lbl->setVisible(true);
        ui->Unit4_lbl->setVisible(true);
        ui->Expiry4_lbl->setVisible(true);

        ui->Conc5_lbl1->setVisible(true);
        ui->ISI05_lbl->setVisible(true);
        ui->Unit5_lbl->setVisible(true);
        ui->Expiry5_lbl->setVisible(true);

        ui->pushButton_286->setVisible(true);
        ui->pushButton_287->setVisible(true);
        ui->pushButton_288->setVisible(true);
        ui->pushButton_289->setVisible(true);
        ui->pushButton_301->setVisible(true);
        ui->pushButton_302->setVisible(false);
        ui->pushButton_303->setVisible(false);
        ui->pushButton_304->setVisible(false);

        ui->Conc6_lbl1->setVisible(false);
        ui->ISI06_lbl->setVisible(false);
        ui->Unit6_lbl->setVisible(false);
        ui->Expiry6_lbl->setVisible(false);

        ui->Conc7_lbl1->setVisible(false);
        ui->ISI07_lbl->setVisible(false);
        ui->Unit7_lbl->setVisible(false);
        ui->Expiry7_lbl->setVisible(false);

        ui->Conc8_lbl1->setVisible(false);
        ui->ISI08_lbl->setVisible(false);
        ui->Unit8_lbl->setVisible(false);
        ui->Expiry8_lbl->setVisible(false);

        ui->TestName_Lbl_17->setVisible(true);
        ui->Cal1_lbl->setVisible(true);
        ui->Cal1_TestBtn->setVisible(true);
        ui->lineEdit_24->setVisible(true);

        ui->TestName_Lbl_18->setVisible(true);
        ui->Cal2_lbl->setVisible(true);
        ui->Cal2_TestBtn->setVisible(true);
        ui->lineEdit_57->setVisible(true);

        ui->TestName_Lbl_19->setVisible(true);
        ui->Cal3_lbl->setVisible(true);
        ui->Cal3_TestBtn->setVisible(true);
        ui->lineEdit_58->setVisible(true);

        ui->TestName_Lbl_20->setVisible(true);
        ui->Cal4_lbl->setVisible(true);
        ui->Cal4_TestBtn->setVisible(true);
        ui->lineEdit_67->setVisible(true);

        ui->TestName_Lbl_21->setVisible(true);
        ui->Cal5_lbl->setVisible(true);
        ui->Cal5_TestBtn->setVisible(true);
        ui->lineEdit_68->setVisible(true);

        ui->TestName_Lbl_22->setVisible(false);
        ui->Cal6_lbl->setVisible(false);
        ui->Cal6_TestBtn->setVisible(false);
        ui->lineEdit_69->setVisible(false);

        ui->TestName_Lbl_23->setVisible(false);
        ui->Cal7_lbl->setVisible(false);
        ui->Cal7_TestBtn->setVisible(false);
        ui->lineEdit_70->setVisible(false);

        ui->TestName_Lbl_24->setVisible(false);
        ui->Cal8_lbl->setVisible(false);
        ui->Cal8_TestBtn->setVisible(false);
        ui->lineEdit_71->setVisible(false);
    }
    else if(No_Std_Cal=="6")
    {
        ui->toolButton_45->setVisible(true);
        ui->toolButton_44->setVisible(true);

        ui->Conc1_lbl1->setVisible(true);
        ui->ISI01_lbl->setVisible(true);
        ui->Unit1_lbl->setVisible(true);
        ui->Expiry1_lbl->setVisible(true);

        ui->Conc2_lbl1->setVisible(true);
        ui->ISI02_lbl->setVisible(true);
        ui->Unit2_lbl->setVisible(true);
        ui->Expiry2_lbl->setVisible(true);

        ui->Conc3_lbl1->setVisible(true);
        ui->ISI03_lbl->setVisible(true);
        ui->Unit3_lbl->setVisible(true);
        ui->Expiry3_lbl->setVisible(true);

        ui->Conc4_lbl1->setVisible(true);
        ui->ISI04_lbl->setVisible(true);
        ui->Unit4_lbl->setVisible(true);
        ui->Expiry4_lbl->setVisible(true);

        ui->Conc5_lbl1->setVisible(true);
        ui->ISI05_lbl->setVisible(true);
        ui->Unit5_lbl->setVisible(true);
        ui->Expiry5_lbl->setVisible(true);

        ui->Conc6_lbl1->setVisible(true);
        ui->ISI06_lbl->setVisible(true);
        ui->Unit6_lbl->setVisible(true);
        ui->Expiry6_lbl->setVisible(true);

        ui->Conc7_lbl1->setVisible(false);
        ui->ISI07_lbl->setVisible(false);
        ui->Unit7_lbl->setVisible(false);
        ui->Expiry7_lbl->setVisible(false);

        ui->Conc8_lbl1->setVisible(false);
        ui->ISI08_lbl->setVisible(false);
        ui->Unit8_lbl->setVisible(false);
        ui->Expiry8_lbl->setVisible(false);

        ui->TestName_Lbl_17->setVisible(true);
        ui->Cal1_lbl->setVisible(true);
        ui->Cal1_TestBtn->setVisible(true);
        ui->lineEdit_24->setVisible(true);

        ui->TestName_Lbl_18->setVisible(true);
        ui->Cal2_lbl->setVisible(true);
        ui->Cal2_TestBtn->setVisible(true);
        ui->lineEdit_57->setVisible(true);

        ui->TestName_Lbl_19->setVisible(true);
        ui->Cal3_lbl->setVisible(true);
        ui->Cal3_TestBtn->setVisible(true);
        ui->lineEdit_58->setVisible(true);

        ui->TestName_Lbl_20->setVisible(true);
        ui->Cal4_lbl->setVisible(true);
        ui->Cal4_TestBtn->setVisible(true);
        ui->lineEdit_67->setVisible(true);

        ui->TestName_Lbl_21->setVisible(true);
        ui->Cal5_lbl->setVisible(true);
        ui->Cal5_TestBtn->setVisible(true);
        ui->lineEdit_68->setVisible(true);

        ui->TestName_Lbl_22->setVisible(true);
        ui->Cal6_lbl->setVisible(true);
        ui->Cal6_TestBtn->setVisible(true);
        ui->lineEdit_69->setVisible(true);

        ui->pushButton_286->setVisible(true);
        ui->pushButton_287->setVisible(true);
        ui->pushButton_288->setVisible(true);
        ui->pushButton_289->setVisible(true);
        ui->pushButton_301->setVisible(true);
        ui->pushButton_302->setVisible(true);
        ui->pushButton_303->setVisible(false);
        ui->pushButton_304->setVisible(false);

        ui->TestName_Lbl_23->setVisible(false);
        ui->Cal7_lbl->setVisible(false);
        ui->Cal7_TestBtn->setVisible(false);
        ui->lineEdit_70->setVisible(false);

        ui->TestName_Lbl_24->setVisible(false);
        ui->Cal8_lbl->setVisible(false);
        ui->Cal8_TestBtn->setVisible(false);
        ui->lineEdit_71->setVisible(false);
    }
    else if(No_Std_Cal=="7")
    {
        ui->toolButton_45->setVisible(true);
        ui->toolButton_44->setVisible(true);

        ui->Conc1_lbl1->setVisible(true);
        ui->ISI01_lbl->setVisible(true);
        ui->Unit1_lbl->setVisible(true);
        ui->Expiry1_lbl->setVisible(true);

        ui->Conc2_lbl1->setVisible(true);
        ui->ISI02_lbl->setVisible(true);
        ui->Unit2_lbl->setVisible(true);
        ui->Expiry2_lbl->setVisible(true);

        ui->Conc3_lbl1->setVisible(true);
        ui->ISI03_lbl->setVisible(true);
        ui->Unit3_lbl->setVisible(true);
        ui->Expiry3_lbl->setVisible(true);

        ui->Conc4_lbl1->setVisible(true);
        ui->ISI04_lbl->setVisible(true);
        ui->Unit4_lbl->setVisible(true);
        ui->Expiry4_lbl->setVisible(true);

        ui->Conc5_lbl1->setVisible(true);
        ui->ISI05_lbl->setVisible(true);
        ui->Unit5_lbl->setVisible(true);
        ui->Expiry5_lbl->setVisible(true);

        ui->Conc6_lbl1->setVisible(true);
        ui->ISI06_lbl->setVisible(true);
        ui->Unit6_lbl->setVisible(true);
        ui->Expiry6_lbl->setVisible(true);

        ui->Conc7_lbl1->setVisible(true);
        ui->ISI07_lbl->setVisible(true);
        ui->Unit7_lbl->setVisible(true);
        ui->Expiry7_lbl->setVisible(true);

        ui->Conc8_lbl1->setVisible(false);
        ui->ISI08_lbl->setVisible(false);
        ui->Unit8_lbl->setVisible(false);
        ui->Expiry8_lbl->setVisible(false);

        ui->TestName_Lbl_17->setVisible(true);
        ui->Cal1_lbl->setVisible(true);
        ui->Cal1_TestBtn->setVisible(true);
        ui->lineEdit_24->setVisible(true);

        ui->TestName_Lbl_18->setVisible(true);
        ui->Cal2_lbl->setVisible(true);
        ui->Cal2_TestBtn->setVisible(true);
        ui->lineEdit_57->setVisible(true);

        ui->TestName_Lbl_19->setVisible(true);
        ui->Cal3_lbl->setVisible(true);
        ui->Cal3_TestBtn->setVisible(true);
        ui->lineEdit_58->setVisible(true);

        ui->TestName_Lbl_20->setVisible(true);
        ui->Cal4_lbl->setVisible(true);
        ui->Cal4_TestBtn->setVisible(true);
        ui->lineEdit_67->setVisible(true);

        ui->TestName_Lbl_21->setVisible(true);
        ui->Cal5_lbl->setVisible(true);
        ui->Cal5_TestBtn->setVisible(true);
        ui->lineEdit_68->setVisible(true);

        ui->TestName_Lbl_22->setVisible(true);
        ui->Cal6_lbl->setVisible(true);
        ui->Cal6_TestBtn->setVisible(true);
        ui->lineEdit_69->setVisible(true);

        ui->TestName_Lbl_23->setVisible(true);
        ui->Cal7_lbl->setVisible(true);
        ui->Cal7_TestBtn->setVisible(true);
        ui->lineEdit_70->setVisible(true);


        ui->pushButton_286->setVisible(true);
        ui->pushButton_287->setVisible(true);
        ui->pushButton_288->setVisible(true);
        ui->pushButton_289->setVisible(true);
        ui->pushButton_301->setVisible(true);
        ui->pushButton_302->setVisible(true);
        ui->pushButton_303->setVisible(true);
        ui->pushButton_304->setVisible(false);

        ui->TestName_Lbl_24->setVisible(false);
        ui->Cal8_lbl->setVisible(false);
        ui->Cal8_TestBtn->setVisible(false);
        ui->lineEdit_71->setVisible(false);
    }
    else if(No_Std_Cal=="8")
    {
        ui->toolButton_45->setVisible(true);
        ui->toolButton_44->setVisible(true);

        ui->Conc1_lbl1->setVisible(true);
        ui->ISI01_lbl->setVisible(true);
        ui->Unit1_lbl->setVisible(true);
        ui->Expiry1_lbl->setVisible(true);

        ui->Conc2_lbl1->setVisible(true);
        ui->ISI02_lbl->setVisible(true);
        ui->Unit2_lbl->setVisible(true);
        ui->Expiry2_lbl->setVisible(true);

        ui->Conc3_lbl1->setVisible(true);
        ui->ISI03_lbl->setVisible(true);
        ui->Unit3_lbl->setVisible(true);
        ui->Expiry3_lbl->setVisible(true);

        ui->Conc4_lbl1->setVisible(true);
        ui->ISI04_lbl->setVisible(true);
        ui->Unit4_lbl->setVisible(true);
        ui->Expiry4_lbl->setVisible(true);

        ui->Conc5_lbl1->setVisible(true);
        ui->ISI05_lbl->setVisible(true);
        ui->Unit5_lbl->setVisible(true);
        ui->Expiry5_lbl->setVisible(true);

        ui->Conc6_lbl1->setVisible(true);
        ui->ISI06_lbl->setVisible(true);
        ui->Unit6_lbl->setVisible(true);
        ui->Expiry6_lbl->setVisible(true);

        ui->Conc7_lbl1->setVisible(true);
        ui->ISI07_lbl->setVisible(true);
        ui->Unit7_lbl->setVisible(true);
        ui->Expiry7_lbl->setVisible(true);

        ui->Conc8_lbl1->setVisible(true);
        ui->ISI08_lbl->setVisible(true);
        ui->Unit8_lbl->setVisible(true);
        ui->Expiry8_lbl->setVisible(true);

        ui->TestName_Lbl_17->setVisible(true);
        ui->Cal1_lbl->setVisible(true);
        ui->Cal1_TestBtn->setVisible(true);
        ui->lineEdit_24->setVisible(true);

        ui->TestName_Lbl_18->setVisible(true);
        ui->Cal2_lbl->setVisible(true);
        ui->Cal2_TestBtn->setVisible(true);
        ui->lineEdit_57->setVisible(true);

        ui->TestName_Lbl_19->setVisible(true);
        ui->Cal3_lbl->setVisible(true);
        ui->Cal3_TestBtn->setVisible(true);
        ui->lineEdit_58->setVisible(true);

        ui->TestName_Lbl_20->setVisible(true);
        ui->Cal4_lbl->setVisible(true);
        ui->Cal4_TestBtn->setVisible(true);
        ui->lineEdit_67->setVisible(true);

        ui->TestName_Lbl_21->setVisible(true);
        ui->Cal5_lbl->setVisible(true);
        ui->Cal5_TestBtn->setVisible(true);
        ui->lineEdit_68->setVisible(true);

        ui->TestName_Lbl_22->setVisible(true);
        ui->Cal6_lbl->setVisible(true);
        ui->Cal6_TestBtn->setVisible(true);
        ui->lineEdit_69->setVisible(true);

        ui->TestName_Lbl_23->setVisible(true);
        ui->Cal7_lbl->setVisible(true);
        ui->Cal7_TestBtn->setVisible(true);
        ui->lineEdit_70->setVisible(true);

        ui->TestName_Lbl_24->setVisible(true);
        ui->Cal8_lbl->setVisible(true);
        ui->Cal8_TestBtn->setVisible(true);
        ui->lineEdit_71->setVisible(true);

        ui->pushButton_286->setVisible(true);
        ui->pushButton_287->setVisible(true);
        ui->pushButton_288->setVisible(true);
        ui->pushButton_289->setVisible(true);
        ui->pushButton_301->setVisible(true);
        ui->pushButton_302->setVisible(true);
        ui->pushButton_303->setVisible(true);
        ui->pushButton_304->setVisible(true);

    }
    ui->ISI01_lbl->setText(OldAbs1);
    ui->ISI02_lbl->setText(OldAbs2);
    ui->ISI03_lbl->setText(OldAbs3);
    ui->ISI04_lbl->setText(OldAbs4);
    ui->ISI05_lbl->setText(OldAbs5);
    ui->ISI06_lbl->setText(OldAbs6);
    ui->ISI07_lbl->setText(OldAbs7);
    ui->ISI08_lbl->setText(OldAbs8);

    QDate currentDate1 = QDate::fromString(Cal1_ExDate, "yyyy-MM-dd");
    QDate currentDate2 = QDate::fromString(Cal2_ExDate, "yyyy-MM-dd");
    QDate currentDate3 = QDate::fromString(Cal3_ExDate, "yyyy-MM-dd");
    QDate currentDate4 = QDate::fromString(Cal4_ExDate, "yyyy-MM-dd");
    QDate currentDate5 = QDate::fromString(Cal5_ExDate, "yyyy-MM-dd");
    QDate currentDate6 = QDate::fromString(Cal6_ExDate, "yyyy-MM-dd");
    QDate currentDate7 = QDate::fromString(Cal7_ExDate, "yyyy-MM-dd");
    QDate currentDate8 = QDate::fromString(Cal8_ExDate, "yyyy-MM-dd");
    qDebug()<<"Current Date1 : "<<currentDate1;
    QString Expiry="Expired";

    if(Abs1==" ")
    {
        ui->Unit1_lbl->setText(" ");
        ui->Expiry1_lbl->setText(" ");
    }
    else
    {
        ui->Unit1_lbl->setText(Unit1);
        if (QDate::currentDate() > currentDate1)
            ui->Expiry1_lbl->setText("<b><font color='red'>"+Expiry+"</font></b>");
        else
            ui->Expiry1_lbl->setText("<b><font color='green'>"+Cal1_ExDate+"</font></b>");
    }

    if(Abs2==" ")
    {
        ui->Unit2_lbl->setText(" ");
        ui->Expiry2_lbl->setText(" ");
    }
    else
    {
        ui->Unit2_lbl->setText(Unit2);
        if (QDate::currentDate() > currentDate2)
            ui->Expiry2_lbl->setText("<b><font color='red'>"+Expiry+"</font></b>");
        else
            ui->Expiry2_lbl->setText("<b><font color='green'>"+Cal2_ExDate+"</font></b>");    }

    if(Abs3==" ")
    {
        ui->Unit3_lbl->setText(" ");
        ui->Expiry3_lbl->setText(" ");
    }
    else
    {
        ui->Unit3_lbl->setText(Unit3);
        if (QDate::currentDate() > currentDate3)
            ui->Expiry3_lbl->setText("<b><font color='red'>"+Expiry+"</font></b>");
        else
            ui->Expiry3_lbl->setText("<b><font color='green'>"+Cal3_ExDate+"</font></b>");
    }

    if(Abs4==" ")
    {
        ui->Unit4_lbl->setText(" ");
        ui->Expiry4_lbl->setText(" ");
    }
    else
    {
        ui->Unit4_lbl->setText(Unit4);
        if (QDate::currentDate() > currentDate4)
            ui->Expiry4_lbl->setText("<b><font color='red'>"+Expiry+"</font></b>");
        else
            ui->Expiry4_lbl->setText("<b><font color='green'>"+Cal4_ExDate+"</font></b>");    }

    if(Abs5==" ")
    {
        ui->Unit5_lbl->setText(" ");
        ui->Expiry5_lbl->setText(" ");
    }
    else
    {
        ui->Unit5_lbl->setText(Unit5);

        if (QDate::currentDate() > currentDate5)
            ui->Expiry5_lbl->setText("<b><font color='red'>"+Expiry+"</font></b>");
        else
            ui->Expiry5_lbl->setText("<b><font color='green'>"+Cal5_ExDate+"</font></b>");
    }

    if(Abs6==" ")
    {
        ui->Unit6_lbl->setText(" ");
        ui->Expiry6_lbl->setText(" ");
    }
    else
    {
        ui->Unit6_lbl->setText(Unit6);
        if (QDate::currentDate() > currentDate6)
            ui->Expiry6_lbl->setText("<b><font color='red'>"+Expiry+"</font></b>");
        else
            ui->Expiry6_lbl->setText("<b><font color='green'>"+Cal6_ExDate+"</font></b>");
    }

    if(Abs7==" ")
    {
        ui->Unit7_lbl->setText(" ");
        ui->Expiry7_lbl->setText(" ");
    }
    else
    {
        ui->Unit7_lbl->setText(Unit7);
        if (QDate::currentDate() > currentDate7)
            ui->Expiry7_lbl->setText("<b><font color='red'>"+Expiry+"</font></b>");
        else
            ui->Expiry7_lbl->setText("<b><font color='green'>"+Cal7_ExDate+"</font></b>");
    }

    if(Abs8==" ")
    {
        ui->Unit8_lbl->setText(" ");
        ui->Expiry8_lbl->setText(" ");
    }
    else
    {
        ui->Unit8_lbl->setText(Unit8);
        if (QDate::currentDate() > currentDate8)
            ui->Expiry8_lbl->setText("<b><font color='red'>"+Expiry+"</font></b>");
        else
            ui->Expiry8_lbl->setText("<b><font color='green'>"+Cal8_ExDate+"</font></b>");
    }
}
// Function to calculate expiry date after 3 months
QDate MainWindow::calculateExpiryDate1(const QDate& currentDate1) {
    // Add 3 months to the current date
    QDate expiryDate1 = currentDate1.addMonths(3);
    return expiryDate1;
}

QDate MainWindow::calculateExpiryDate2(const QDate& currentDate2) {
    // Add 3 months to the current date
    QDate expiryDate2 = currentDate2.addMonths(3);
    return expiryDate2;
}

QDate MainWindow::calculateExpiryDate3(const QDate& currentDate3) {
    // Add 3 months to the current date
    QDate expiryDate3 = currentDate3.addMonths(3);
    return expiryDate3;
}

QDate MainWindow::calculateExpiryDate4(const QDate& currentDate4) {
    // Add 3 months to the current date
    QDate expiryDate4 = currentDate4.addMonths(3);
    return expiryDate4;
}

QDate MainWindow::calculateExpiryDate5(const QDate& currentDate5) {
    // Add 3 months to the current date
    QDate expiryDate5 = currentDate5.addMonths(3);
    return expiryDate5;
}

QDate MainWindow::calculateExpiryDate6(const QDate& currentDate6) {
    // Add 3 months to the current date
    QDate expiryDate6 = currentDate6.addMonths(3);
    return expiryDate6;
}

QDate MainWindow::calculateExpiryDate7(const QDate& currentDate7) {
    // Add 3 months to the current date
    QDate expiryDate7 = currentDate7.addMonths(3);
    return expiryDate7;
}

QDate MainWindow::calculateExpiryDate8(const QDate& currentDate8) {
    // Add 3 months to the current date
    QDate expiryDate8 = currentDate8.addMonths(3);
    return expiryDate8;
}


void MainWindow::Glucose_Check()
{
    ui->lineEdit_13->clear();
    ui->label_270->clear();
    ui->label_271->clear();
    ui->lineEdit_17->clear();
    ui->lineEdit_15->clear();
    ui->label_273->clear();
    ui->label_276->clear();
    ui->label_234->clear();
    ui->lineEdit_13->setFocus();
    QDate Current_Year=QDate::currentDate();
    QDate Current_Month=QDate::currentDate();
    ui->dateEdit->setDisplayFormat("MM");
    ui->dateEdit->setDate(Current_Month);
    ui->dateEdit_2->setDisplayFormat("yyyy");
    ui->dateEdit_2->setDate(Current_Year);
    Barcode_count_check_func();

    QString Temp,Count;
    QSqlQuery query;
    query.prepare("select Temp from "+Barcode_checkname+" where sno =1");
    query.exec();
    while(query.next())
        Temp=query.value(0).toString();
    Glu_Temp = Temp;
    bool ok ;
    QSqlQuery qry;
    ok=qry.exec("select Count from "+Barcode_checkname+" where Data='"+Glu_Temp+"'");
    while(ok && qry.next())
        Count=qry.value(0).toString();

    if(Count=="0")
    {
       /* ui->label_215->setText("Test Name : "+TestName+"");
        ui->Home_Btn_13->setVisible(true);
        ui->Home_Btn_23->setVisible(false);
        ui->label_221->setVisible(false);
        ui->label_266->setVisible(false);
        ui->stackedWidget->setCurrentIndex(22);*/
        tested();
    }
    else
        tested();
}

void MainWindow::Counting()
{
    Barcode_count_check_func();
    QString Temp , Count;
    QSqlQuery query;
    query.prepare("select Temp from "+Barcode_checkname+" where sno=1");
    query.exec();
    while(query.next())
        Temp=query.value(0).toString();
    QSqlQuery qry;
    qry.prepare("select Count from "+Barcode_checkname+" where Data = '"+Temp+"'");
    qry.exec();
    while(qry.next())
        Count=qry.value(0).toString();
    ui->label_253->setText(Count);
}
