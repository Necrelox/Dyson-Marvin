/*
** Created by ruby on 2021-11-28
** File : SenderMail
** description:
** SenderMail
*/

#include "SenderMail.h"

SenderMail::SenderMail(std::string to, std::string cc)
{
    std::string from = "behavior.undefined@gmail.com";
    std::string pass = "";
    std::vector<std::string> secret = {"necrelox@gmail.com"};
	std::vector<std::string> to2 = {"necrelox@gmail.com"};
	std::vector<std::string> cc1 = {"necrelox@gmail.com"};

    this->curl = new CurlSmtp(
            from,
            pass,
            to2,
            secret,
            cc1,
            std::vector<std::string>(),
            "",
            "",
            "smtp.gmail.com",
            "587"
            );

}

void SenderMail::sendMail(const std::string& subject, const std::string& message) {
    if (this->curl) {
        this->curl->set_subject(subject);
        this->curl->set_message(message);
        this->curl->send_mail();
    }
}

SenderMail::~SenderMail() {
   delete this->curl;
}

void SenderMail::set_Mail_To(const std::string& to) {
    if (this->curl)
        this->curl->set_to(std::vector<std::string> {to} );
}

void SenderMail::set_Mail_Cc(const std::string& cc) {
    if (this->curl)
        this->curl->set_cc(std::vector<std::string> {cc} );
}

void SenderMail::sendMail(const std::string &subject, const std::string &message, const std::vector<std::string> &attach)
{
    if (this->curl) {
        this->curl->set_subject(subject);
        this->curl->set_message(message);
        this->curl->set_attach(attach);
        this->curl->send_mail();
    }
}
