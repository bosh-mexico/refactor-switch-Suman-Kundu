#ifndef PAYMENT_PROCESSORS_H
#define PAYMENT_PROCESSORS_H

#include <iostream>

// Abstract base class
class PaymentProcessor {
public:
    virtual ~PaymentProcessor() = default;
    virtual void processPayment(double amount) = 0;
    
protected:
    void logTransaction(double amount) {
        std::cout << "Transaction logged: $" << amount << std::endl;
    }
};

// Concrete payment processors
class PayPalProcessor : public PaymentProcessor {
public:
    void processPayment(double amount) override;
};

class GooglePayProcessor : public PaymentProcessor {
public:
    void processPayment(double amount) override;
};

class CreditCardProcessor : public PaymentProcessor {
public:
    void processPayment(double amount) override;
};

class UnknownProcessor : public PaymentProcessor {
public:
    void processPayment(double /* amount */) override;
};

class ApplePayProcessor : public PaymentProcessor {
public:
    void processPayment(double amount) override;
};

#endif // PAYMENT_PROCESSORS_H