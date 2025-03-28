#include <iostream>
#include <string>
using namespace std;

// Interface for Notification
class Notification {
public:
    virtual void send(const string& message) = 0;
    virtual ~Notification() {}
};

// Concrete class for Email Notification
class EmailNotification : public Notification {
public:
    void send(const string& message) override {
        cout << "Sending Email: " << message << endl;
    }
};

// Concrete class for SMS Notification
class SMSNotification : public Notification {
public:
    void send(const string& message) override {
        cout << "Sending SMS: " << message << endl;
    }
};

// Concrete class for Push Notification
class PushNotification : public Notification {
public:
    void send(const string& message) override {
        cout << "Sending Push Notification: " << message << endl;
    }
};

// Function to demonstrate sending notifications
void sendNotification(Notification* notification, const string& message) {
    notification->send(message);
}

int main() {
    EmailNotification email;
    SMSNotification sms;
    PushNotification push;

    sendNotification(&email, "Hello via Email!");
    sendNotification(&sms, "Hello via SMS!");
    sendNotification(&push, "Hello via Push Notification!");

    return 0;
}