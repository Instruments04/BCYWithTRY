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
#include <QtNetwork/QNetworkConfigurationManager>
#include <QNetworkSession>

void MainWindow::on_pushButton_12_clicked()
{
    qApp->processEvents();
    ui->pushButton_12->setDisabled(true);
    QString line;
    QString lines[1000];
    // Prepare the wpa_supplicant.conf content
    QString ssid = ui->comboBox_4->currentText();
    QString psk = ui->lineEdit_2->text();
    // QString pwd=ui->lineEdit_2->text();
    QFile file("/etc/wpa_supplicant/wpa_supplicant.conf");

    if(ssid=="------Select-------")
    {
        QMessageBox msg(this);
        msg.setWindowFlags(Qt::Popup); // Changed from Qt::Popup to Qt::Dialog
        msg.setStyleSheet("background-color:#a0cdfa;font: 75 20pt Liberation Serif ;");
        msg.setText("Please select a Wi-Fi network.");
        QPixmap p("/home/pi/git/BCYWithTRY/BCYWithTRY/img/notification.png");
        auto newPixmap = p.scaled(80, 80);
        msg.setIconPixmap(newPixmap);
        QPushButton* saveButton = msg.addButton("Ok", QMessageBox::AcceptRole);
        saveButton->setStyleSheet("QPushButton{background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 #34ba91, stop: 0.5 #34ba91, stop: 1 #34ba91);color:black;}QPushButton:pressed {background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(0, 85, 0), stop: 0.5 rgb(0, 85, 0), stop: 1 rgb(0, 85, 0));color:white;}");
        msg.setDefaultButton(saveButton);
        msg.exec();
        if (msg.clickedButton() == saveButton)
        {
            ui->stackedWidget->setCurrentIndex(12);
            ui->stackedWidget_5->setCurrentIndex(1);
        }
        else
        {
            ui->stackedWidget->setCurrentIndex(12);
            ui->stackedWidget_5->setCurrentIndex(1);
        }
        ui->pushButton_12->setEnabled(true);
        return;
    }
    else if (psk.isEmpty())
    {
        QMessageBox msg(this);
        msg.setWindowFlags(Qt::Popup); // Changed from Qt::Popup to Qt::Dialog
        msg.setStyleSheet("background-color:#a0cdfa;font: 75 20pt Liberation Serif ;");
        msg.setText("Please  enter the password.");
        QPixmap p("/home/pi/git/BCYWithTRY/BCYWithTRY/img/notification.png");
        auto newPixmap = p.scaled(80, 80);
        msg.setIconPixmap(newPixmap);
        QPushButton* saveButton = msg.addButton("Yes", QMessageBox::AcceptRole);
        saveButton->setStyleSheet("QPushButton{background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 #34ba91, stop: 0.5 #34ba91, stop: 1 #34ba91);color:black;}QPushButton:pressed {background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(0, 85, 0), stop: 0.5 rgb(0, 85, 0), stop: 1 rgb(0, 85, 0));color:white;}");
        msg.setDefaultButton(saveButton);
        msg.exec();
        if (msg.clickedButton() == saveButton)
        {
            ui->stackedWidget->setCurrentIndex(12);
            ui->stackedWidget_5->setCurrentIndex(1);
        }
        else
        {
            ui->stackedWidget->setCurrentIndex(12);
            ui->stackedWidget_5->setCurrentIndex(1);
        }
        ui->pushButton_12->setEnabled(true);
        return;
    }

    QString connectedWifi = getConnectedWifiName();

    // Compare case-insensitively to avoid mismatches due to letter casing
    if (!connectedWifi.isEmpty() && connectedWifi.compare(ssid, Qt::CaseInsensitive) == 0)
    {
        qDebug() << "Already connected to" << ssid;

        // Show message and return (No need to reconfigure)
        QMessageBox msg(this);
        msg.setWindowFlags(Qt::Popup);
        msg.setStyleSheet("background-color:#a0cdfa;font: 75 20pt Liberation Serif;");
        msg.setText("You are already connected to this Wi-Fi network.");
        QPixmap p("/home/pi/git/BCYWithTRY/BCYWithTRY/img/info.png");
        msg.setIconPixmap(p.scaled(80, 80));

        QPushButton* okButton = msg.addButton("Ok", QMessageBox::AcceptRole);
        okButton->setStyleSheet(
                    "QPushButton{background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 #34ba91, stop: 1 #34ba91);color:black;}"
                    "QPushButton:pressed {background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(0, 85, 0), stop: 1 rgb(0, 85, 0));color:white;}");

        msg.setDefaultButton(okButton);
        msg.exec();
        if (msg.clickedButton() == okButton)
        {
            ui->stackedWidget->setCurrentIndex(12);
            ui->stackedWidget_5->setCurrentIndex(1);
        }
        else
        {
            ui->stackedWidget->setCurrentIndex(12);
            ui->stackedWidget_5->setCurrentIndex(1);
        }
        ui->pushButton_12->setEnabled(true);
        return;  // Exit function since Wi-Fi is already connected
    }
    else
    {
        qDebug() << "Connecting to new Wi-Fi:" << ssid;
        if(file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream stream(&file);
            stream<<"ctrl_interface=DIR=/var/run/wpa_supplicant GROUP=netdev\n";
            stream<<"update_config=1\n";
            stream<<"country=IN\n";
            stream<<"\n";
            stream<<"network={\n";
            stream<<"\tssid=";
            stream<<ssid+"\n";
            stream<<"\tpsk=\"";
            stream<<psk+"\"\n";
            stream<<"\tkey_mgmt=WPA-PSK\n";
            stream<<"}";
            file.close();


            QProcess *process2 = new QProcess(this);
            process2->start("sh", QStringList() << "-c" << "sudo wpa_cli -i wlan0 reconfigure");

            if (process2->waitForFinished())
            {
                QString output = process2->readAllStandardOutput();
                QString error = process2->readAllStandardError();
                qDebug() << "wpa_cli output:" << output;
                qDebug() << "wpa_cli error:" << error;

                if (output.contains("OK"))
                {
                    QMessageBox *wifiMsg = new QMessageBox(this);
                    showInfoMessage(wifiMsg, "Wi-Fi configuration applied successfully. Connecting...");

                    // Timer for checking connection status
                    QTimer *connectionCheckTimer = new QTimer(this);
                    int *retryCount = new int(0);  // Keep track of retries

                    connect(connectionCheckTimer, &QTimer::timeout, this,
                            [this, connectionCheckTimer, wifiMsg, retryCount]()
                    {
                        QProcess checkConnection;
                        checkConnection.start("sh", QStringList() << "-c" << "iwgetid -r");

                        if (checkConnection.waitForFinished(2000)) // Timeout after 2 sec
                        {
                            QString connectionStatus = checkConnection.readAllStandardOutput().trimmed();
                            if (!connectionStatus.isEmpty())  // If connected, stop timer and close message box
                            {
                                connectionCheckTimer->stop();
                                connectionCheckTimer->deleteLater();
                                wifiMsg->close();
                                wifiMsg->deleteLater();
                                delete retryCount;
                                Current_Connection=connectionStatus;
                                showFinalInfoMessage(new QMessageBox(this), "Connected to Wi-Fi: " + connectionStatus);
                            }
                            else
                            {
                                (*retryCount)++;
                                if (*retryCount >= 5)  // Retry 5 times (15 seconds max)
                                {
                                    connectionCheckTimer->stop();
                                    connectionCheckTimer->deleteLater();
                                    wifiMsg->close();
                                    wifiMsg->deleteLater();
                                    delete retryCount;
                                    showErrorMessage("Failed to connect to Wi-Fi. Please check your credentials.");
                                }
                            }
                        }
                    });

                    connectionCheckTimer->start(3000); // Check every 3 seconds
                }
                else
                {
                    showErrorMessage("Failed to apply Wi-Fi configuration. Please try again.");
                }
            }
            else
            {
                showErrorMessage("Failed to execute wpa_cli command.");
            }

            delete process2;
        }
        else
        {
            showErrorMessage("Unable to open wpa_supplicant.conf for writing.");
        }

        ui->pushButton_12->setEnabled(true);
    }
}

void MainWindow::showErrorMessage(const QString &message) {
    QMessageBox msg(this);
    msg.setWindowFlags(Qt::Popup);
    msg.setStyleSheet("background-color:#a0cdfa;font: 75 20pt Liberation Serif;");
    QPixmap p("/home/pi/git/BCYWithTRY/BCYWithTRY/img/notification.png");
    auto newPixmap = p.scaled(80, 80);
    msg.setIconPixmap(newPixmap);
    msg.setText(message);
    QPushButton *okButton = msg.addButton("Ok", QMessageBox::AcceptRole);
    okButton->setStyleSheet(
                "QPushButton{background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 #34ba91, stop: 1 #34ba91);color:black;}"
                "QPushButton:pressed {background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(0, 85, 0), stop: 1 rgb(0, 85, 0));color:white;}");
    msg.setDefaultButton(okButton);
    msg.exec();
    ui->stackedWidget->setCurrentIndex(12);
    ui->stackedWidget_5->setCurrentIndex(1);
}

void MainWindow::showInfoMessage(QMessageBox *msg, const QString &message)
{
    msg->setWindowFlags(Qt::Popup);
    msg->setStyleSheet("background-color:#a0cdfa;font: 75 20pt Liberation Serif;");
    QPixmap p("/home/pi/git/BCYWithTRY/BCYWithTRY/img/check-mark.png");
    auto newPixmap = p.scaled(80, 80);
    msg->setIconPixmap(newPixmap);
    msg->setText(message);
    msg->setStandardButtons(QMessageBox::NoButton);  // No buttons, so it cannot be closed manually
    msg->show();
}

void MainWindow::showFinalInfoMessage(QMessageBox *msg, const QString &message)
{
    msg->setWindowFlags(Qt::Popup);
    msg->setStyleSheet("background-color:#a0cdfa;font: 75 20pt Liberation Serif;");
    QPixmap p("/home/pi/git/BCYWithTRY/BCYWithTRY/img/check-mark.png");
    auto newPixmap = p.scaled(80, 80);
    msg->setIconPixmap(newPixmap);
    msg->setText(message);
    QPushButton* saveButton = msg->addButton("Ok", QMessageBox::AcceptRole);
    saveButton->setStyleSheet("background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 #34ba91, stop: 0.5 #34ba91, stop: 1 #34ba91);color:black;}QPushButton:pressed {background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(0, 85, 0), stop: 0.5 rgb(0, 85, 0), stop: 1 rgb(0, 85, 0));color:white;}");
    msg->setDefaultButton(saveButton);
    msg->exec();
    if (msg->clickedButton() == saveButton)
    {
        QProcess *process2 = new QProcess(this);
        process2->start("sh", QStringList() << "-c" << "sudo hostname -I");
        process2->waitForFinished();

        QString data2 = process2->readAllStandardOutput();
        qDebug() << "Data:" << data2;
        QStringList list2 = data2.split(" ");
        QString IP = list2.at(0);
        qDebug() << "IP:" << IP;

        ui->label_418->setText(Current_Connection);
        ui->label_416->setText(IP);
        ui->label_419->setText("Connected...");
        ui->pushButton_272->setVisible(true);
        ui->pushButton_273->setVisible(false);
        delete process2;

        ui->toolButton_15->setVisible(true);
        ui->toolButton_21->setVisible(false);
        ui->stackedWidget_5->setCurrentIndex(0);
        ui->stackedWidget->setCurrentIndex(12);
    }
}


void MainWindow::on_pushButton_23_clicked()
{
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    ui->pushButton_23->hide();
    ui->pushButton_25->show();
}

void MainWindow::on_pushButton_25_clicked()
{
    ui->lineEdit_2->setEchoMode(QLineEdit::Normal);
    ui->pushButton_25->hide();
    ui->pushButton_23->show();
}

void MainWindow::on_pushButton_271_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
    ui->stackedWidget_5->setCurrentIndex(1);
    ui->toolButton_15->setVisible(false);
    ui->toolButton_21->setVisible(true);
    ui->pushButton_23->setVisible(true);
    ui->pushButton_25->setVisible(false);
    ui->lineEdit_2->clear();
    if(!ui->comboBox_4->currentText().isEmpty())
             ui->comboBox_4->clear();
    else
        qDebug()<<"List not empty";

    //Wifi Setup*************************

    QStringList list2;
    QProcess *process1 = new QProcess(this);
    process1->start("sh",QStringList()<<"-c"<<"sudo iwlist wlan0 scan | grep ESSID");//scan list of wifi networks
    process1->waitForFinished();
    QString data = process1->readAllStandardOutput();
    QString Error= process1->readAllStandardError();
    list2 = (QStringList()<<"------Select-------");//append to dropdownlist
    if(!list2.empty())
        ui->comboBox_4->addItems(list2);
    else
        qDebug()<<"The list is empty";

    QStringList list = data.split("\n");//split data
    for(int i=0;i<list.count()-1;i++)
    {
        QStringList list1 = list.at(i).split("ESSID:");
        QString data1 = list1.at(1);
        list2 = (QStringList()<<data1);
        if(!list2.empty())
            ui->comboBox_4->addItems(list2);
        else
            qDebug()<<"The list is empty";//adding wifi names to dropdownlist

        qDebug()<<"Data : "<<data;
        qDebug()<<"Error : "<<Error;
        qDebug()<<"List1 : "<<list1;
        qDebug()<<"List2 : "<<list2;
    }

    QTcpSocket socket;
    socket.connectToHost("8.8.8.8", 53);
    if (socket.waitForConnected())
    {
        QString text = socket.localAddress().toString();
    }
    else
    {
        QMessageBox msg(this);
        msg.setWindowFlags(Qt::Popup);
        msg.setStyleSheet("background-color:#a0cdfa;font: 75 20pt Liberation Serif ;");
        msg.setText("Couldn't connect to the DNS server! No internet connection.");
        msg.setWindowTitle("No internet connection");
        msg.setIcon(QMessageBox::Critical);
        QPushButton* saveButton = msg.addButton("Ok", QMessageBox::AcceptRole);
        saveButton->setStyleSheet("QPushButton{background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 #34ba91, stop: 0.5 #34ba91, stop: 1 #34ba91);color:black;}QPushButton:pressed {background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(0, 85, 0), stop: 0.5 rgb(0, 85, 0), stop: 1 rgb(0, 85, 0));color:white;}");
        msg.setDefaultButton(saveButton);
        msg.exec();
    }
    delete process1;
    on_pushButton_23_clicked();
}

QString MainWindow::getConnectedWifiName()
{
    QProcess process;
    process.start("iwgetid -r");  // Get the currently connected Wi-Fi SSID
    process.waitForFinished(); // Blocking call, can be improved with async
    QString output = process.readAllStandardOutput().trimmed();

    if (output.isEmpty()) {
        qDebug() << "No Wi-Fi is currently connected.";
    } else {
        qDebug() << "Currently connected Wi-Fi: " << output;
    }

    return output;
}

// Slot to handle the connect button click
void MainWindow::on_pushButton_4_clicked()
{
    ui->toolButton_15->setVisible(true);
    ui->toolButton_21->setVisible(false);
    QString wifiName = getConnectedWifiName();
    qDebug() << "Connected WiFi name:" << wifiName;

    if (ui->label_418->text() == "off/any" || wifiName.isEmpty()) {
        ui->label_418->clear();
        ui->label_416->clear();
        ui->label_419->setText("Disconnected...");
        ui->pushButton_273->setVisible(true);
        ui->pushButton_272->setVisible(false);
    }
    else {
        QProcess *process = new QProcess(this);
        process->start("sh", QStringList() << "-c" << "sudo hostname -I");
        process->waitForFinished();

        QString datas = process->readAllStandardOutput();
        qDebug() << "Data:" << datas;
        QStringList list1 = datas.split(" ");
        QString IP = list1.at(0);
        delete process;
        qDebug() << "IP:" << IP;

        ui->label_416->setText(IP);
        ui->stackedWidget_5->setCurrentIndex(0);
        ui->toolButton_15->setVisible(true);
        ui->toolButton_21->setVisible(false);
        ui->pushButton_23->setVisible(true);
        ui->pushButton_25->setVisible(false);

        QProcess *process1 = new QProcess(this);
        process1->start("sh", QStringList() << "-c" << "sudo iwconfig | grep ESSID");
        process1->waitForFinished();

        QString data = process1->readAllStandardOutput();
        QString error = process1->readAllStandardError();
        QStringList list = data.split("\n");

        for (int i = 0; i < list.count() - 1; ++i) {
            QStringList list1 = list.at(i).split("ESSID:");
            QString data1 = list1.at(1);
            qDebug() << "Data:" << data;
            qDebug() << "Error:" << error;
            qDebug() << "List1:" << list1;
            qDebug() << "Data1:" << data1;
            ui->label_418->setText(data1);
        }

        QString IPA = ui->label_416->text();
        if (ui->checkBox->isChecked()) {
            if (IPA.isEmpty()) {
                handleDisconnectedState();
            } else {
                handleConnectedState(wifiName);
            }
        } else {
            if (IPA.isEmpty()) {
                handleDisconnectedState();
            } else {
                handleConnectedState(wifiName);
            }
        }
        delete process1;
    }
    ui->stackedWidget->setCurrentIndex(12);
    ui->stackedWidget_5->setCurrentIndex(0);
}

void MainWindow::handleDisconnectedState()
{
    ui->label_419->setText("Disconnected...");
    ui->pushButton_273->setVisible(true);
    ui->pushButton_272->setVisible(false);

    QMessageBox msg(this);
    msg.setWindowFlags(Qt::Popup);
    msg.setStyleSheet("font: 75 20pt Liberation Serif;");
    msg.setText("Couldn't connect to the DNS server! No internet connection.");
    msg.setWindowTitle("No internet connection");
    msg.setIcon(QMessageBox::Critical);
    QPushButton* saveButton = msg.addButton("Ok", QMessageBox::AcceptRole);
    saveButton->setStyleSheet("QPushButton{background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 #34ba91, stop: 0.5 #34ba91, stop: 1 #34ba91);color:black;}QPushButton:pressed {background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(0, 85, 0), stop: 0.5 rgb(0, 85, 0), stop: 1 rgb(0, 85, 0));color:white;}");
    msg.setDefaultButton(saveButton);
    msg.exec();

    ui->stackedWidget->setCurrentIndex(17);
    ui->stackedWidget_5->setCurrentIndex(1);
    ui->toolButton_15->setVisible(false);
    ui->toolButton_21->setVisible(true);
    ui->pushButton_23->setVisible(true);
    ui->pushButton_25->setVisible(false);
}

void MainWindow::handleConnectedState(const QString &wifiName)
{
    ui->label_418->setText(wifiName);
    ui->label_419->setText("Connected...");
    ui->label_586->setText(getAnyDeskID());
    ui->pushButton_272->setVisible(true);
    ui->pushButton_273->setVisible(false);
}

// Slot to handle the checkbox click to block/unblock Wi-Fi
void MainWindow::on_checkBox_clicked()
{
    if (ui->checkBox->isChecked())
        unblockWifi();
    else
        blockWifi();
}

void MainWindow::unblockWifi()
{
    ui->pushButton_271->setDisabled(false);
    QProcess *process = new QProcess(this);
    process->start("sh", QStringList() << "-c" << "sudo rfkill unblock wifi");

    if (!process->waitForStarted()) {
        qDebug() << "Error:" << process->errorString();
    }
    process->waitForFinished(-1);
    delete process;
    QThread::msleep(5000);

    scanWifiNetworks();
}

void MainWindow::blockWifi()
{
    ui->pushButton_271->setDisabled(true);
    QProcess *process = new QProcess(this);
    process->start("sh", QStringList() << "-c" << "sudo rfkill block wifi");

    if (!process->waitForStarted()) {
        qDebug() << "Error:" << process->errorString();
    }
    process->waitForFinished(-1);
    delete process;

    ui->label_418->clear();
    ui->label_416->clear();
    ui->label_419->setText("Disconnected...");
    ui->pushButton_273->setVisible(true);
    ui->pushButton_272->setVisible(false);
}

void MainWindow::scanWifiNetworks()
{
    QStringList list2;
    QProcess *process1 = new QProcess(this);
    process1->start("sh", QStringList() << "-c" << "sudo iwlist wlan0 scan | grep ESSID");
    process1->waitForFinished();

    QString data = process1->readAllStandardOutput();
    QString error = process1->readAllStandardError();
    list2 = (QStringList() << "------Select-------");

    QStringList list = data.split("\n");
    for (int i = 0; i < list.count() - 1; ++i) {
        if (ui->label_418->text() == "off/any") {
            handleDisconnectedState();
        } else {
            QStringList list1 = list.at(i).split("ESSID:");
            QString data1 = list1.at(1);
            list2 = (QStringList() << data1);
            qDebug() << "Data:" << data;
            qDebug() << "Error:" << error;
            qDebug() << "List1:" << list1;
            qDebug() << "List2:" << list2;

            QProcess *process2 = new QProcess(this);
            process2->start("sh", QStringList() << "-c" << "sudo hostname -I");
            process2->waitForFinished();

            QString data2 = process2->readAllStandardOutput();
            qDebug() << "Data:" << data2;
            QStringList list2 = data2.split(" ");
            QString IP = list2.at(0);
            qDebug() << "IP:" << IP;

            ui->label_418->setText(data1);
            ui->label_416->setText(IP);
            ui->label_419->setText("Connected...");
            ui->pushButton_272->setVisible(true);
            ui->pushButton_273->setVisible(false);
            ui->label_586->setText(getAnyDeskID());
            delete process2;
        }
    }
    delete process1;
}

QString MainWindow::getAnyDeskID()
{
    QProcess process;
    process.start("anydesk --get-id");
    process.waitForFinished();
    QString output = process.readAllStandardOutput().trimmed();
    return output.isEmpty() ? "No AnyDesk ID Found" : output;
}

