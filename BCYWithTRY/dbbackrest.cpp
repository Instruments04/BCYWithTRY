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

void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(16);
}

void MainWindow::connectToDatabase() {
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("/home/pi/git/Bar_Data.db");
    if (!mydb.open())
        qDebug() << "Can't Connect to DB!";
    else
        qDebug() << "Connected Successfully to DB!";
}

void MainWindow::closeDatabaseConnection() {
    QSqlDatabase mydb = QSqlDatabase::database();
    mydb.close();
}

void MainWindow::Restore_database()
{
    QMessageBox msg(this);
    msg.setWindowFlags(Qt::Popup);
    msg.setStyleSheet("background-color:#a0cdfa;font: 75 20pt Liberation Serif ;");
    QPixmap p("/home/pi/git/BCYWithTRY/BCYWithTRY/img/restore.png");
    auto newPixmap = p.scaled(80, 80);
    msg.setIconPixmap(newPixmap);
    msg.setText("Do you want to do data restore?");
    QPushButton* saveButton = msg.addButton("Yes", QMessageBox::AcceptRole);
    saveButton->setStyleSheet("QPushButton{background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 #34ba91, stop: 0.5 #34ba91, stop: 1 #34ba91);color:black;}QPushButton:pressed {background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(0, 85, 0), stop: 0.5 rgb(0, 85, 0), stop: 1 rgb(0, 85, 0));color:white;}");
    QPushButton* dontSaveButton = msg.addButton("Back", QMessageBox::DestructiveRole);
    dontSaveButton->setStyleSheet("QPushButton{background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 #ff5957, stop: 0.5 #ff5957, stop: 1 #ff5957);color:black;}QPushButton:pressed{background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(184, 0, 0), stop: 0.5 rgb(184, 0, 0), stop: 1 rgb(184, 0, 0)); color:white;}");
    msg.setDefaultButton(saveButton);
    msg.exec();
    if (msg.clickedButton() == saveButton)
    {

        QString dbPath = "/home/pi/git/Bar_Data.db";
        QString dumpPath = "/home/pi/git/Dump.sql";

        // Step 1: Delete the existing database file
        QFile::remove(dbPath);

        // Step 2: Restore the database from Dump.sql
        QProcess *restoreProcess = new QProcess(this);
        restoreProcess->setWorkingDirectory("/home/pi/git/");
        QStringList arguments;
        arguments << "-c" << QString("sqlite3 %1 < %2").arg(dbPath).arg(dumpPath);
        restoreProcess->start("sh", arguments);

        if (!restoreProcess->waitForStarted() || !restoreProcess->waitForFinished(-1) || (restoreProcess->exitStatus() != QProcess::NormalExit))
        {
            qWarning() << "Restore failed:" << restoreProcess->errorString();
            QMessageBox msg(this);
            msg.setWindowFlags(Qt::Popup);
            msg.setStyleSheet("background-color:#a0cdfa;font: 75 20pt Liberation Serif ;");
            QPixmap p("/home/pi/git/BCYWithTRY/BCYWithTRY/img/notification.png");
            auto newPixmap = p.scaled(80, 80);
            msg.setIconPixmap(newPixmap);
            msg.setText("The database restore failed.");
            QPushButton* saveButton = msg.addButton("Ok", QMessageBox::AcceptRole);
            saveButton->setStyleSheet("QPushButton{background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 #34ba91, stop: 0.5 #34ba91, stop: 1 #34ba91);color:black;}QPushButton:pressed {background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(0, 85, 0), stop: 0.5 rgb(0, 85, 0), stop: 1 rgb(0, 85, 0));color:white;}");
            msg.setDefaultButton(saveButton);
            msg.exec();
            if (msg.clickedButton() == saveButton)
                ui->stackedWidget->setCurrentIndex(16);
            else
                ui->stackedWidget->setCurrentIndex(16);
        }
        else
        {
            QMessageBox msg(this);
            msg.setWindowFlags(Qt::Popup);
            msg.setStyleSheet("background-color:#a0cdfa;font: 75 20pt Liberation Serif ;");
            QPixmap p("/home/pi/git/BCYWithTRY/BCYWithTRY/img/check-mark.png");
            auto newPixmap = p.scaled(80, 80);
            msg.setIconPixmap(newPixmap);
            msg.setText("Data Restore Done.");
            QPushButton* saveButton = msg.addButton("Ok", QMessageBox::AcceptRole);
            saveButton->setStyleSheet("QPushButton{background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 #34ba91, stop: 0.5 #34ba91, stop: 1 #34ba91);color:black;}QPushButton:pressed {background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(0, 85, 0), stop: 0.5 rgb(0, 85, 0), stop: 1 rgb(0, 85, 0));color:white;}");
            msg.setDefaultButton(saveButton);
            msg.exec();
            if (msg.clickedButton() == saveButton)
                ui->stackedWidget->setCurrentIndex(16);
            else
                ui->stackedWidget->setCurrentIndex(16);
        }

        delete restoreProcess;
    }
    else if (msg.clickedButton() == dontSaveButton)
    {
        ui->stackedWidget->setCurrentIndex(16);
    }
}

void MainWindow::on_pushButton_132_clicked()
{
    QMessageBox msg(this);
    msg.setWindowFlags(Qt::Popup);
    msg.setStyleSheet("background-color:#a0cdfa;font: 75 20pt Liberation Serif ;");
    QPixmap p("/home/pi/git/BCYWithTRY/BCYWithTRY/img/backu.png");
    auto newPixmap = p.scaled(80, 80);
    msg.setIconPixmap(newPixmap);
    msg.setText("Do you want to do data backup?");
    QPushButton* saveButton = msg.addButton("Yes", QMessageBox::AcceptRole);
    saveButton->setStyleSheet("QPushButton{background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 #34ba91, stop: 0.5 #34ba91, stop: 1 #34ba91);color:black;}QPushButton:pressed {background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(0, 85, 0), stop: 0.5 rgb(0, 85, 0), stop: 1 rgb(0, 85, 0));color:white;}");
    QPushButton* dontSaveButton = msg.addButton("Back", QMessageBox::DestructiveRole);
    dontSaveButton->setStyleSheet("QPushButton{background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 #ff5957, stop: 0.5 #ff5957, stop: 1 #ff5957);color:black;}QPushButton:pressed{background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(184, 0, 0), stop: 0.5 rgb(184, 0, 0), stop: 1 rgb(184, 0, 0)); color:white;}");
    msg.setDefaultButton(saveButton);
    msg.exec();
    if (msg.clickedButton() == saveButton)
    {
        QString strError;
        QProcess *p = new QProcess(this);
        p->setWorkingDirectory("/home/pi/git/");
        p->start("sh",QStringList()<<"-c"<<"sudo sqlite3 /home/pi/git/Bar_Data.db .dump > /home/pi/git/Dump.sql");
        if (!p->waitForStarted() || !p->waitForFinished(-1) || (p->exitStatus() != QProcess::NormalExit))
        {
            switch (p->error())
            {
            case (QProcess::FailedToStart) :
                strError = tr("The process failed to start. Either the invoked "
                              "program is missing, or you may have insufficient permissions to invoke the program.");
                break;
            case (QProcess::Crashed) :
                strError = tr("The process crashed some time after starting successfully.");
                break;
            case (QProcess::WriteError) :
                strError = tr("An error occurred when attempting to write to the process. For example, the process may not be running, or it may have closed its input channel.");
                break;
            case (QProcess::ReadError):
                strError = tr("An error occurred when attempting to read from the process. For example, the process may not be running.");
                break;
            default:
                strError = tr("An unknown error occurred.");
            }

            QMessageBox msg(this);
            msg.setWindowFlags(Qt::Popup);
            msg.setStyleSheet("background-color:#a0cdfa;font: 75 20pt Liberation Serif ;");

            msg.setIcon(QMessageBox::Warning);
            msg.setText(strError);
            QPushButton* saveButton = msg.addButton("Yes", QMessageBox::AcceptRole);
            saveButton->setStyleSheet("QPushButton{background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 #34ba91, stop: 0.5 #34ba91, stop: 1 #34ba91);color:black;}QPushButton:pressed {background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(0, 85, 0), stop: 0.5 rgb(0, 85, 0), stop: 1 rgb(0, 85, 0));color:white;}");
            msg.setDefaultButton(saveButton);
            msg.exec();
        }

        QMessageBox msg(this);
        msg.setWindowFlags(Qt::Popup);
        msg.setStyleSheet("background-color:#a0cdfa;font: 75 20pt Liberation Serif ;");
        QPixmap pix("/home/pi/git/BCYWithTRY/BCYWithTRY/img/check-mark.png");
        auto newPixmap = pix.scaled(65, 65);
        msg.setIconPixmap(newPixmap);
        msg.setText("Data Backup Done.");
        QPushButton* saveButton = msg.addButton("Ok", QMessageBox::AcceptRole);
        saveButton->setStyleSheet("QPushButton{background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 #34ba91, stop: 0.5 #34ba91, stop: 1 #34ba91);color:black;}QPushButton:pressed {background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop: 0 rgb(0, 85, 0), stop: 0.5 rgb(0, 85, 0), stop: 1 rgb(0, 85, 0));color:white;}");
        msg.setDefaultButton(saveButton);
        msg.exec();
        if (msg.clickedButton() == saveButton)
        {
            ui->stackedWidget->setCurrentIndex(16);
        }

        delete p;
    }
    else if(msg.clickedButton() == dontSaveButton)
        ui->stackedWidget->setCurrentIndex(16);
    else
        qDebug()<<"out" ;
}

void MainWindow::on_pushButton_133_clicked()
{
    closeDatabaseConnection();
    // Perform the restore operation
    Restore_database();
    connectToDatabase();
}

void MainWindow::on_toolButton_19_clicked()
{
    ui->pushButton_148->setVisible(false);

    ui->stackedWidget->setCurrentIndex(10);
}
