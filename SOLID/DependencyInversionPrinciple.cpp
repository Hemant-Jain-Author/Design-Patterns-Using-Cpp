#include <iostream>
#include <stdexcept>

class IMailSender {
public:
    virtual void sendMail(const std::string& toAddress, const std::string& fromAddress,
                           const std::string& subject, const std::string& body) = 0;
};

class SmtpServer : public IMailSender {
public:
    void sendMail(const std::string& toAddress, const std::string& fromAddress,
                  const std::string& subject, const std::string& body) override {
        std::cout << "Send mail: subject: " << subject << " from: " << fromAddress
                  << " to: " << toAddress << " body: " << body << std::endl;
    }
};

class EmailSender {
private:
    IMailSender* mailSender;

public:
    explicit EmailSender(IMailSender* mailSender) : mailSender(mailSender) {
        if (mailSender == nullptr) {
            throw std::invalid_argument("mailSender must not be null");
        }
    }

    void sendEmail(const std::string& toAddress, const std::string& fromAddress,
                   const std::string& subject, const std::string& body) {
        // Delegate email sending to the mail sender implementation
        mailSender->sendMail(toAddress, fromAddress, subject, body);
    }
};

int main() {
    // Create an instance of the SmtpServer class
    SmtpServer smtpServer;

    // Create an instance of the EmailSender class and pass in the SmtpServer instance
    EmailSender emailSender(&smtpServer);

    // Send an email using the EmailSender instance
    emailSender.sendEmail("recipient@example.com", "sender@example.com", "mail subject.",
                          "This is a test email body.");

    return 0;
}

/*
Send mail: subject: mail subject. from: sender@example.com to: recipient@example.com body: This is a test email body.
*/