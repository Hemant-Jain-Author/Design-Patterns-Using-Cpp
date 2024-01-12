#include <iostream>

// Interface definitions
class Printable {
public:
    virtual void print(const std::string& document) = 0;
};

class Scannable {
public:
    virtual void scan() = 0;
};

class Faxable {
public:
    virtual void fax(const std::string& document) = 0;
};

// Concrete printer classes
class BasicInkjetPrinter : public Printable, public Scannable {
public:
    void print(const std::string& document) override {
        std::printf("Printing %s using basic inkjet printer\n", document.c_str());
    }

    void scan() override {
        std::cout << "Scanning using basic inkjet printer\n";
    }
};

class HighEndOfficePrinter : public Printable, public Scannable, public Faxable {
public:
    void print(const std::string& document) override {
        std::printf("Printing %s using high-end office printer\n", document.c_str());
    }

    void scan() override {
        std::cout << "Scanning using high-end office printer\n";
    }

    void fax(const std::string& document) override {
        std::printf("Faxing %s using high-end office printer\n", document.c_str());
    }
};

// Client code
int main() {
    // BasicInkjetPrinter
    BasicInkjetPrinter basicPrinter;
    basicPrinter.print("Sample Document");
    basicPrinter.scan();

    // HighEndOfficePrinter
    HighEndOfficePrinter officePrinter;
    officePrinter.print("Important Report");
    officePrinter.scan();
    officePrinter.fax("Confidential Memo");

    return 0;
}

/*
Printing Sample Document using basic inkjet printer
Scanning using basic inkjet printer
Printing Important Report using high end office printer
Scanning using high end office printer
Faxing Confidential Memo using high end office printer
*/