#include "PaymentFactory.h"
#include "PaymentProcessors.h"
#include <algorithm>

std::unordered_map<std::string, std::function<std::unique_ptr<PaymentProcessor>()>> PaymentFactory::processors;

std::string PaymentFactory::toUpper(const std::string& str) {
    std::string upper = str;
    std::transform(upper.begin(), upper.end(), upper.begin(), ::toupper);
    return upper;
}

std::unique_ptr<PaymentProcessor> PaymentFactory::createProcessor(const std::string& paymentMode) {
    std::string upperMode = toUpper(paymentMode);
    auto it = processors.find(upperMode);
    return (it != processors.end()) ? it->second() : std::make_unique<UnknownProcessor>();
}

void PaymentFactory::registerProcessor(const std::string& mode, std::function<std::unique_ptr<PaymentProcessor>()> factory) {
    processors[toUpper(mode)] = factory;
}

void PaymentFactory::initializeDefaultProcessors() {
    processors["PAYPAL"] = []() { return std::make_unique<PayPalProcessor>(); };
    processors["GOOGLEPAY"] = []() { return std::make_unique<GooglePayProcessor>(); };
    processors["CREDITCARD"] = []() { return std::make_unique<CreditCardProcessor>(); };
}