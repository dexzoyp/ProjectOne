#include <iostream>

class Printer {
public:
    virtual void print(const std::string& document) = 0;
    virtual ~Printer() = default; 
};
class Scanner {
public:
    virtual void scan(const std::string& document) = 0;
    virtual ~Scanner() = default;
};

class Fax
{
public:
    virtual void fax(const std::string& document) = 0;
    virtual ~Fax() = default;
};

class MultifunctionalPrinter :  public Printer, public Scanner, public Fax
{
public:
    void print(const std::string& document) override final
    {
        std::cout << "print\n";
    }
    void scan(const std::string& document) override final
    {
        std::cout << "scan\n";
    }
    void fax(const std::string& document) override final
    {
        std::cout << "fax\n";
    }
    ~MultifunctionalPrinter()
    {
        std::cout << "print\n";
    }
};

class SimplerPrinter : public Printer
{
public:
    void print(const std::string& document) override final
    {
        std::cout << "print\n";
    }
    ~SimplerPrinter()
    {
        std::cout << "print\n";
    }
};


int main()
{
    MultifunctionalPrinter* mprinter = new MultifunctionalPrinter();
    mprinter->print("Document");

    SimplerPrinter* sprinter = new SimplerPrinter();
    sprinter->print("");

    std::cout << "Hello World!\n";
}
