
#include <iostream>

class IService {
public:
    virtual void performTask() = 0;
    virtual ~IService() = default;
};

class Service : public IService{
public:
    virtual void performTask() override {
        std::cout << "Service:: performTask() override {\n";
    }
};


class ServiceOne : public IService {
public:
    virtual void performTask() override {
        std::cout << "ServiceOne:: performTask() override {\n";
    }
};

class Client {
private:
    IService& m_service;
public:
    Client(IService& service) : m_service(service){

    }
    void execute() {
        m_service.performTask();
    }
};


int main()
{
    Service service;
    Client client(service);

    ServiceOne service2;
    Client client2(service2);

    client.execute();
    client2.execute();
}
