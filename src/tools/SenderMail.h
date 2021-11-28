/*
** Created by ruby on 2021-11-28
** File : SenderMail
** description:
** SenderMail
*/
#ifndef SENDER_MAIL_H
#define SENDER_MAIL_H

#include "curlsmtp.h"


class SenderMail {
private:
    CurlSmtp *curl = nullptr;

public:
    void sendMail(const std::string &subject, const std::string &message);
    void sendMail(const std::string &subject, const std::string &message, const std::vector<std::string> &attach);
    void set_Mail_To(const std::string& to);
    void set_Mail_Cc(const std::string& cc);
    SenderMail(std::string to, std::string cc);
    ~SenderMail();

};


#endif
