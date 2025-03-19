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
QString ICON_PATH ="/home/pi/git/Biochemistry_Updates/BCUID/img/";
void MainWindow::Biochemistry_CSS()
{
    ui->toolButton_6->setStyleSheet("QToolButton{background-color: rgb(12, 68, 145);"
    "border-radius: 25px;"
    "color: rgb(255, 255, 255);"
    "border: 1px solid black;"
    "padding-top: 25px;"
    "background-position: center bottom;"
    "background-repeat: no-repeat;"
    "background-origin: content;"
    "}"
    "QToolButton::hover{"
    "background-color: qlineargradient(spread:pad, x1:0, y1:0.0913636, x2:0.944, y2:0.392, stop:0.0969388 rgba(22, 123, 200, 255), stop:1 rgba(20, 113, 180, 255));"
    "}"
    "QToolButton::pressed"
    "{"
      "margin-top: 2px;"
    "margin-bottom: -4px;"
    "}");

    QPixmap p(ICON_PATH+"BioMenu.png");
    auto newPixmap = p.scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QIcon New_Icon(newPixmap);
    ui->Menu_Btn_2->setIcon(New_Icon);

    QPixmap p1(ICON_PATH+"BioSettings.png");
    auto newPixmap1 = p1.scaled(45, 45, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QIcon New_Icon1(newPixmap1);
    ui->Setting_Btn->setIcon(New_Icon1);

    QPixmap p2(ICON_PATH+"BioPoweroff.png");
    auto newPixmap2 = p2.scaled(45, 45, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QIcon New_Icon2(newPixmap2);
    ui->Power_Btn->setIcon(New_Icon2);
}

void MainWindow::Turbidity_CSS()
{
    ui->toolButton_6->setStyleSheet("QToolButton{    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(213, 84, 24, 255), stop:1 rgba(213, 84, 24, 255));"
                                    "border:1px solid black;"
    "border-radius: 25px;"
    "color: rgb(255, 255, 255);"
    "border: 1px solid black;"
    "padding-top: 25px;"
    "background-position: center bottom;"
    "background-repeat: no-repeat;"
    "background-origin: content;"
    "}"
    "QToolButton::hover{"
    "background-color: qlineargradient(spread:pad, x1:0, y1:0.0913636, x2:0.944, y2:0.392, stop:0.0969388 rgba(22, 123, 200, 255), stop:1 rgba(20, 113, 180, 255));"
    "}"
    "QToolButton::pressed"
    "{"
      "margin-top: 2px;"
    "margin-bottom: -4px;"
    "}");


    QPixmap p(ICON_PATH+"TurMenu.png");
    auto newPixmap = p.scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QIcon New_Icon(newPixmap);
    ui->Menu_Btn_2->setIcon(New_Icon);

    QPixmap p1(ICON_PATH + "TurSettting.png");
    auto newPixmap1 = p1.scaled(45, 45, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QIcon New_Icon1(newPixmap1);
    ui->Setting_Btn->setIcon(New_Icon1);

    QPixmap p2(ICON_PATH+"TurPoweroff.png");
    auto newPixmap2 = p2.scaled(45, 45, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QIcon New_Icon2(newPixmap2);
    ui->Power_Btn->setIcon(New_Icon2);
}
