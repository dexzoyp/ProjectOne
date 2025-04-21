#pragma once
#include <iostream>
#include <string>
#include <chrono>
#include <condition_variable>
#include <iostream>
#include <map>
#include <memory>
#include <mutex>
#include <queue>
#include <thread>
#define PRINT(x) std::cout << x << std::endl


class AlgorithmInterface {
public:
    virtual void Execute() = 0;
    virtual ~AlgorithmInterface() = default;
};

// Realization/Implementation
class MatrixAlgorithm : public AlgorithmInterface {
public:
    MatrixAlgorithm() {}
    virtual void Execute() override { PRINT("MatrixAlgorithm"); } // Implementation
};
inline void ImplementationCode() {
    // AlgorithmInterface* algo = new AlgorithmInterface(); // ERROR the code cannot compile...
    AlgorithmInterface* algo = new MatrixAlgorithm();
    MatrixAlgorithm* algo2 = new MatrixAlgorithm();
    algo->Execute();  // Polymorphic call
    algo2->Execute();
    delete algo;
    delete algo2;
}

//(vptr)


// Inheritance
class Animal {
protected:
    std::string m_name;

public:
    Animal() {}
    virtual ~Animal() = default;
    void SetName(std::string_view name) { m_name = name; }
    virtual void PolymorphicMethod() {
        PRINT("Animal::PolymorphicMethod");
    };
};

class Dog : public Animal {
public:
    Dog() {}
    void Bark() { PRINT((m_name + ">Bark")); }
    virtual void PolymorphicMethod() override {
        PRINT("Dog::PolymorphicMethod");
    }
};

inline void InheritanceCode() {
    Animal* animal = new Dog(); // Inherited
    animal->SetName("Bari"); // Inherited method
    Dog* myDog = dynamic_cast<Dog*>(animal); // Runtime polymorphism
    if (myDog != nullptr) {
        myDog->Bark();  // Non Polymorphic call
        myDog->PolymorphicMethod(); // Polymorphic call
    }
    delete animal;
}



// Messeging
struct Message {
    std::string sender;
    std::string content;
};

class MessageQueue {
    std::queue<Message> queue;
    std::mutex mtx;
    std::condition_variable cv;

public:
    void SendMessage(const Message& msg) {
        std::lock_guard<std::mutex> lock(mtx);
        queue.push(msg);
        cv.notify_one();
    }
    Message receiveMessage() {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this] { return !queue.empty(); });

        Message msg = queue.front();
        queue.pop();
        return msg;
    }
};

class MessageServiceInterface {
public:
    virtual void SendMessage(const std::string& to, const std::string& msg) = 0;
    virtual void ReceiveMessages() = 0;
    virtual ~MessageServiceInterface() = default;
};

class DirectMessage : public MessageServiceInterface {
    std::shared_ptr<MessageQueue> messageQueue;

public:
    explicit DirectMessage(std::shared_ptr<MessageQueue> mQueue) : messageQueue(mQueue) {}

    void SendMessage(const std::string& to, const std::string& msg) override {
        std::cout << "[DirectMessage] Sending message to " << to << ": " << msg << std::endl;
        messageQueue->SendMessage({ to, msg });
    }

    void ReceiveMessages() override {
        while (true) {
            Message msg = messageQueue->receiveMessage();
            std::cout << "[DirectMessage] Received message: " << msg.content << " from "
                << msg.sender << std::endl;
        }
    }
};

class User {
    std::string m_name;
    std::shared_ptr<MessageServiceInterface> messageService;
    std::shared_ptr<MessageQueue> messageQueue;
    std::thread receiveLoop;

public:
    explicit User(const std::string& name, std::shared_ptr<MessageServiceInterface> service,
        std::shared_ptr<MessageQueue> mq)
        : m_name(name),
        messageService(service),
        messageQueue(mq),
        receiveLoop(&MessageServiceInterface::ReceiveMessages, messageService.get()) {
    }
    void SendMessage(const std::string& to, const std::string& msg) const {
        messageService->SendMessage(to, msg);
    }
    const std::string& GetName() const { return m_name; }
    ~User() {
        if (receiveLoop.joinable()) {
            receiveLoop.detach();
        }
    }
};

inline void MessegingCode() {
    auto messageQueue = std::make_shared<MessageQueue>();
    std::shared_ptr<DirectMessage> service = std::make_shared<DirectMessage>(messageQueue);
    User u1("@user1", service, messageQueue);
    User u2("@user2", service, messageQueue);
    u1.SendMessage(u2.GetName(), "Hello, u2, how are you?");
    u2.SendMessage(u1.GetName(), "Hii, u1, Im fine, wbu? xx");
    std::this_thread::sleep_for(std::chrono::seconds(4));
    u1.SendMessage(u2.GetName(), "Heyyyy?");
    std::this_thread::sleep_for(std::chrono::seconds(4));
}

// Association
class Student;  // Forward declaration
class Teacher {
public:
    std::string name;
    explicit Teacher(const std::string& _name) : name(_name) {}

    void TeachStudents(std::vector<Student>& students);
};

class Student {
public:
    int id;
    explicit Student(int _id) : id(_id) {}
};
void Teacher::TeachStudents(std::vector<Student>& students) {// Association: Teacher uses students to teach them
    for (auto& student : students) {
        PRINT(student.id);
    }
}

inline void AssociationCode() {
    Teacher teacher("Maria");
    std::vector<Student> students;
    for (int i = 0; i < 10; ++i) {
        Student student(i);
        students.push_back(student);
    }
    teacher.TeachStudents(students);
}



// Aggregation
class Address {
private:
    std::string street;
    std::string city;
    std::string country;

public:
    Address(std::string street, std::string city, std::string country)
        : street(street), city(city), country(country) {
    }

    void showAddress() const {
        std::cout << "Address: " << street << ", " << city << ", " << country << std::endl;
    }
};

class Person {
private:
    std::string name;
    Address* address;  // Aggregation: Person has an Address (but does NOT own it)
public:
    Person(std::string name, Address* address) : name(name), address(address) {}

    void showPerson() const {
        std::cout << "Name: " << name << std::endl;
        if (address) {
            address->showAddress();
        }
        else {
            std::cout << "No address available." << std::endl;
        }
    }
};

inline void AggregationCode() {
    Address addr("bul Bulgaria", "Sofia", "Bulgaria");
    {
        Person person("Angel Angelov", &addr);
        person.showPerson();
    }
}

// Composition
class Room {
private:
    int roomNumber;

public:
    Room(int number) : roomNumber(number) {}

    void showRoom() const { std::cout << "Room Number: " << roomNumber << std::endl; }
};

class House {
private:
    std::string owner;
    std::vector<Room> rooms;  // Composition: House OWNS Rooms
public:
    House(std::string ownerName, int numRooms) : owner(ownerName) {
        for (int i = 1; i <= numRooms; ++i) {
            rooms.emplace_back(i);
        }
    }

    void showHouse() const {
        std::cout << "House owned by: " << owner << std::endl;
        std::cout << "Rooms in the house:" << std::endl;
        for (const auto& room : rooms) {
            room.showRoom();
        }
    }
};

inline void CompositionCode() {
    House myHouse("Angel Angelov", 3);
    myHouse.showHouse();
}