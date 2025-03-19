#ifndef HL7MLLP_H
#define HL7MLLP_H

#include <string>
#include "hl7socket.h"
#include "ui_mainwindow.h"

struct HL7MLLP : private HL7Socket
{
    bool isCConnected;
    HL7MLLP(const std::string& host, const std::string& port, Ui::MainWindow *ui)
        : HL7Socket(host, port, ui), isCConnected(isConnected())
    {
    }

    HL7MLLP(int sockfd) : HL7Socket(sockfd), isCConnected(true) {}

    ~HL7MLLP() {}

    bool isInited()
    {
        return (getSocket() != -1);
    }

    bool isConnectedd() const
    {
        return isCConnected;
    }

    size_t send_msg_mllp(const std::string& data)
    {
        char* mllp_data = new char[data.length() + 3];
        if (!mllp_data) return 0;

        mllp_data[0] = 0x0b;
        strcpy(mllp_data + 1, data.c_str());
        mllp_data[data.length() + 1] = 0x1c;
        mllp_data[data.length() + 2] = 0x0d;
        size_t len = write(getSocket(), mllp_data, data.length() + 3);

        if (len != data.length() + 3)
        {
            std::cerr << "Error: partial/failed write" << std::endl;
            isCConnected = false;
        }
        else
        {
            isCConnected = true;
        }
        delete[] mllp_data;
        return len;
    }

    size_t read_msg_mllp(std::string& data)
    {
        std::string buffer;
        bool bStart = true;
        bool bFinish = false;

        size_t n = read_msg(buffer);
        if (n == -1) return n;

        while (n > 0)
        {
            size_t iS = 0;
            if (bStart)
            {
                while ((buffer[iS] != 0x0b) && (iS < n))
                    iS++;
                if ((iS + 1) < n)
                {
                    bStart = false;
                    bFinish = true;
                }
            }
            if (bFinish)
            {
                size_t iF = iS;
                while (iF < n)
                {
                    if ((buffer[iF] == 0x1c) && (iF < (n - 1)) && (buffer[iF + 1] == 0x0d))
                    {
                        buffer[iF] = 0;
                        bFinish = false;
                        break;
                    }
                    iF++;
                }
                data = buffer;
            }
            data = buffer.c_str() + iS + 1;
            if (!bStart && !bFinish)
                break;
            buffer.clear();
            n = read_msg(buffer);
        }
        return data.length();
    }
};

#endif // HL7MLLP_H
