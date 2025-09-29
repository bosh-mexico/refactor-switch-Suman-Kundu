#include "PaymentProcessors.h"

void PayPalProcessor::processPayment(double amount) {
    std::cout << "Processing PayPal payment of $" << amount << std::endl;
    logTransaction(amount);
}

void GooglePayProcessor::processPayment(double amount) {
    std::cout << "Processing GooglePay payment of $" << amount << std::endl;
    logTransaction(amount);
}

void CreditCardProcessor::processPayment(double amount) {
    std::cout << "Processing Credit Card payment of $" << amount << std::endl;
    logTransaction(amount);
}

void UnknownProcessor::processPayment(double /* amount */) {
    std::cout << "Invalid payment mode selected!" << std::endl;
}

void ApplePayProcessor::processPayment(double amount) {
    std::cout << "Processing Apple Pay payment of $" << amount << std::endl;
    logTransaction(amount);
}