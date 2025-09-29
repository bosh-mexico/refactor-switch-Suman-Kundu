#ifndef PAYMENT_FACTORY_H
#define PAYMENT_FACTORY_H

#include <memory>
#include <string>
#include <unordered_map>
#include <functional>
#include "PaymentProcessors.h"

class PaymentFactory {
private:
    static std::unordered_map<std::string, std::function<std::unique_ptr<PaymentProcessor>()>> processors;
    
    static std::string toUpper(const std::string& str);

public:
    static std::unique_ptr<PaymentProcessor> createProcessor(const std::string& paymentMode);
    static void registerProcessor(const std::string& mode, std::function<std::unique_ptr<PaymentProcessor>()> factory);
    static void initializeDefaultProcessors();
};

#endif // PAYMENT_FACTORY_H