#include <iostream>
#include "PaymentFactory.h"

using namespace std;

void checkout(const string& paymentMode, double amount) {
    auto processor = PaymentFactory::createProcessor(paymentMode);
    processor->processPayment(amount);
}

void addNewPaymentMethod() {
    PaymentFactory::registerProcessor("APPLEPAY", []() {
        return make_unique<ApplePayProcessor>();
    });
}

int main() {
    PaymentFactory::initializeDefaultProcessors();
    
    double amount = 150.75;
    
    cout << "Testing payment methods:" << endl;
    checkout("PayPal", amount);
    checkout("GooglePay", amount);
    checkout("CreditCard", amount);
    checkout("Unknown", amount);
    
    cout << "\nAdding new payment method:" << endl;
    addNewPaymentMethod();
    checkout("ApplePay", amount);
    
    cout << "\nTesting case insensitivity:" << endl;
    checkout("paypal", amount);
    checkout("CREDITCARD", amount);
    
    return 0;
}