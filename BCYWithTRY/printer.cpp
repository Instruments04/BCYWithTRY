/*****************************************************************
* Thermal Printer Interface Library based on QT for the Rasp-Pi
* Based on the Arduino Library from Adafruit
* using QExtSerialPort
* Autor: Tobias Floery
* E-Mail: tobias@floery.net
***************************************************************/

#include "printer.h"
#include <QImage>
#include <iostream>
#include <unistd.h>
#include <QDebug>
#include <QThread>

Printer::Printer(Ui::MainWindow *uiMainWindow, QObject *parent) :
    QObject(parent), ui(uiMainWindow)  // Store the passed ui pointer
{
}

// opens the serial port specified py path

bool Printer::open(QString path) {

    port = new QextSerialPort(path);

    if (!port->open(QIODevice::WriteOnly))
        return false;

    // set options
    QString selectedBaudRate = ui->comboBox_11->currentText();
    qDebug()<<"Printer library :- Baudrate "<<selectedBaudRate;
    if (selectedBaudRate == "1200")
        port->setBaudRate(BAUD1200);
    else if (selectedBaudRate == "1800")
        port->setBaudRate(BAUD1800);
    else if (selectedBaudRate == "2400")
        port->setBaudRate(BAUD2400);
    else if (selectedBaudRate == "4800")
        port->setBaudRate(BAUD4800);
    else if (selectedBaudRate == "9600")
        port->setBaudRate(BAUD9600);
    else if (selectedBaudRate == "19200")
        port->setBaudRate(BAUD19200);
    else if (selectedBaudRate == "38400")
        port->setBaudRate(BAUD38400);
    else if (selectedBaudRate == "57600")
        port->setBaudRate(BAUD57600);
    else
        port->setBaudRate(BAUD9600);  // Default if unknown

    QString selectedDatabit = ui->comboBox_17->currentText();
    if (selectedDatabit == "5")
        port->setDataBits(DATA_5);
    else if (selectedDatabit == "6")
        port->setDataBits(DATA_6);
    else if (selectedDatabit == "7")
        port->setDataBits(DATA_7);
    else if (selectedDatabit == "8")
        port->setDataBits(DATA_8);
    else
        port->setDataBits(DATA_8);  // Default if unknown
    qDebug()<<"Printer library :- Databit "<<selectedDatabit;
    QString selectedParity = ui->comboBox_14->currentText();
    if (selectedParity == "ODD")
        port->setParity(PAR_ODD);
    else if (selectedParity == "EVEN")
        port->setParity(PAR_EVEN);
    else if (selectedParity == "NONE")
        port->setParity(PAR_NONE);
    else if (selectedParity == "SPACE")
        port->setParity(PAR_SPACE);
    else
        port->setParity(PAR_NONE);  // Default if unknown
    qDebug()<<"Printer library :- Parity "<<selectedParity;
    QString selectedFlowControl = ui->comboBox_18->currentText();

    if (selectedFlowControl == "NONE")
        port->setFlowControl(FLOW_OFF);
    else if (selectedFlowControl == "HARDWARE")
        port->setFlowControl(FLOW_HARDWARE);
    else if (selectedFlowControl == "SOFTWARE")
        port->setFlowControl(FLOW_XONXOFF);
    else
        port->setFlowControl(FLOW_OFF);  // Default if unknown
    qDebug()<<"Printer library :- FlowControl "<<selectedFlowControl;
    /* // set options
    port->setBaudRate(BAUD38400);
    port->setDataBits(DATA_8);
    port->setFlowControl(FLOW_HARDWARE);
    port->setParity(PAR_NONE);
    qDebug()<<"Baudrate : "<<port->baudRate();
    qDebug()<<"Databit : "<<port->dataBits();
    qDebug()<<"Parity : "<<port->parity();
    qDebug()<<"FlowCOntrol  : "<<port->flowControl();*/

    usleep(10000);
    setReverse(true);
    setUpDown(true);
    return true;
}

// close the serial port
void Printer::close() {
    port->close();
}

// write single byte
void Printer::write(quint8 byte) {
    port->write((const char*)&byte, 1);
}

// write a string
void Printer::write(QString str)
{
    port->write(str.toUtf8());
}

void Printer::writes(char SOMETHING)
{
    port->write(&SOMETHING);
}


// initialize the printerl
void Printer::init() {
    // reset();
    setStatus(true);
    setControlParameter();
    setPrintDensity();
    setSleepTime();
    setCodeTable();
    setCharacterSet();
    setBarcodePrintReadable();

    setReverse(false);
    port->flush();
}

// reset the printer
void Printer::reset() {
    write(27);
    write(64);
    usleep(50000);
    uint8_t printData[] = {0x1B, 0x7B, 0x00}; // Example data
    write(printData, 3); // Send the reversed byte
    usleep(5000);          // Wait for command to take effect
    port->flush();
}

// sets the printer online (true) or ofline (false)
void Printer::setStatus(bool state) {
    write(27);
    write(61);
    write(state ? 1 : 0);
}

// set control parameters: heatingDots, heatingTime, heatingInterval
void Printer::setControlParameter(quint8 heatingDots, quint8 heatingTime, quint8 heatingInterval) {
    write(27);
    write(55);
    write(heatingDots);
    write(heatingTime);
    write(heatingInterval);
}

// set sleep Time in seconds, time after last print the printer should stay awake
void Printer::setSleepTime(quint8 seconds) {
    write(27);
    write(56);
    write(seconds);
    usleep(50000);
    write(0xFF);
}

// set double width mode: on=true, off=false
void Printer::setDoubleWidth(bool state) {
    write(27);
    write(state?14:20);

}


// set the print density and break time
void Printer::setPrintDensity(quint8 printDensity, quint8 printBreakTime) {
    write(18);
    write(35);
    write((printBreakTime << 5) | printDensity);
}

// set the used character set
void Printer::setCharacterSet(CharacterSet set) {
    write(27);
    write(82);
    write(set);
}

// set the used code table
void Printer::setCodeTable(CodeTable table) {
    write(27);
    write(116);
    write(table);
}

// feed single line
void Printer::feed(void) {
    write(10);
}

// feed <<lines>> lines
void Printer::feed(quint8 lines) {
    write(27);
    write(74);
    write(lines);
}

// set line spacing
void Printer::setLineSpacing(quint8 spacing) {
    write(27);
    write(51);
    write(spacing);
}

// set Align Mode: LEFT, MIDDLE, RIGHT
void Printer::setAlign(AlignMode align) {
    write(27);
    write(97);
    write(align);
}

// set how many blanks should be kept on the left side
void Printer::setLeftBlankCharNums(quint8 space) {
    if (space >= 47) space = 47;

    write(27);
    write(66);
    write(space);
}

// set Bold Mode: on=true, off=false
void Printer::setBold(bool state) {
    write(27);
    write(32);
    write((quint8) state);
    write(27);
    write(69);
    write((quint8) state);
}

// set Reverse printing Mode
void Printer::setReverse(bool state) {
    write(29);
    write(66);
    write((quint8) state);
}

// set Up/Down Mode
void Printer::setUpDown(bool state) {
    write(27);
    write(123);
    write((quint8) state);
}

// set Underline printing
void Printer::setUnderline(bool state) {
    write(27);
    write(45);
    write((quint8) state);
}

// enable / disable the key on the frontpanel
void Printer::setKeyPanel(bool state) {
    write(27);
    write(99);
    write(53);
    write((quint8) state);
}

// where should a readable barcode code be printed
void Printer::setBarcodePrintReadable(PrintReadable n) {
    write(29);
    write(72);
    write(n);
}

// sets the height of the barcode in pixels
void Printer::setBarcodeHeight(quint8 height) {
    if (height <= 1) height = 1;

    write(29);
    write(104);
    write(height);
}

// sets the barcode line widths (only 2 or 3)
void Printer::setBarCodeWidth(quint8 width) {
    if (width <= 2) width=2;
    else if (width >= 3) width=3;

    write(29);
    write(119);
    write(width);
}

// prints a barcode
void Printer::printBarcode(QString data, BarcodeType type) {
    write(29);
    write(107);
    write(type);
    write(data);
    write(0);
}

bool Printer::isPrinterReady()
{
    return port->isOpen() && port->isWritable();
}

// Function to print a self-test page
void Printer::printSelfTestPage() {
    // ASCII: DC2 T -> Decimal: 18 84 -> Hex: 12 54
    write(18);  // DC2 - Device Control 2
    write(84);  // 'T' command for self-test
    usleep(50000);  // 50ms delay to allow the printer to process

    qDebug()<<"SelfTest Done.";
}

void Printer::write(const quint8 *data, int size)
{
    port->write(reinterpret_cast<const char *>(data), size);
    port->flush();
}

void Printer::printImage(QImage img, quint8 threshold)
{
    QImage scaledImg = img.scaled(384, img.height() * 384 / img.width(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QImage bw = scaledImg.convertToFormat(QImage::Format_Mono, Qt::MonoOnly | Qt::ThresholdDither | Qt::AvoidDither);
    int width = bw.width() / 8; // Width in bytes
    int height = bw.height(); // Allocate memory for image data
    quint8 *data = new quint8[width * height]; memset(data, 0, width * height);
    // Convert pixels to binary data
    for (int y = 0; y < bw.height(); y++)
    {
        for (int x = 0; x < bw.width(); x++)
        {
            quint8 pixel = qGray(bw.pixel(x, y)) > threshold ? 0 : 1;
            data[y * width + x / 8] |= (pixel & 0x01) << (7 - x % 8);
        }
    }
    // split images with height > 255 into parts (from Adafruit)
    for (int rowStart=0; rowStart<height; rowStart+=256) {
        int chunkHeight = ((height - rowStart) > 255) ? 255 : (height - rowStart);
        write(18);
        write(42);
        write(chunkHeight);
        write(width);

        for (int i=0; i<(width*chunkHeight); i++) {
            write(data[rowStart*width + i]);
        }
        usleep(50000);
    }

    // Clean up
    delete[] data;
}

void Printer::printBitImage(const QImage &image, quint8 threshold)
{
    // Scale image to fit printer width (max 384 pixels)
    QImage scaledImg = image.scaled(384, image.height() * 384 / image.width(), Qt::KeepAspectRatio, Qt::SmoothTransformation);

    // Convert image to monochrome (black & white)
    QImage bw = scaledImg.convertToFormat(QImage::Format_Mono, Qt::MonoOnly | Qt::ThresholdDither | Qt::AvoidDither);

    int width = bw.width();
    int height = bw.height();
    int width_bytes = (width + 7) / 8;  // Ensure width is rounded up to nearest byte (multiple of 8)

    // Allocate memory for image data
    quint8 *data = new quint8[width_bytes * height];
    memset(data, 0, width_bytes * height);

    // Convert pixels to bit image format (MSB first)
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            quint8 pixel = qGray(bw.pixel(x, y)) > threshold ? 0 : 1;
            data[y * width_bytes + (x / 8)] |= (pixel & 0x01) << (7 - (x % 8));
        }
    }

    // **Choose bit image mode**
    const quint8 m = 1;  // Change to 1 (8-dot double-density mode)

    // **Split the image into chunks if height > 255**
    for (int rowStart = 0; rowStart < height; rowStart += 255) {
        int chunkHeight = ((height - rowStart) > 255) ? 255 : (height - rowStart);

        // **Send ESC * m nL nH**
        write(0x1B); // ESC
        write(0x2A); // '*'
        write(m);    // Bit image mode (1 = 8-dot double density)
        write(width_bytes & 0xFF); // nL
        write((width_bytes >> 8) & 0xFF); // nH

        // **Send bitmap data**
        for (int i = 0; i < (width_bytes * chunkHeight); i++) {
            write(data[rowStart * width_bytes + i]);
        }

        // **Ensure new line after each chunk**
        write(0x0A); // Line Feed (LF) to move to next row
        usleep(50000); // Small delay
    }

    // Clean up
    delete[] data;
}

