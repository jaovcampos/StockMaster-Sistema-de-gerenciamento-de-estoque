// monitor.h
#ifndef MONITOR_H
#define MONITOR_H

#include <string>
#include <vector>
#include <map>

class Monitor {
public:
    Monitor();
    ~Monitor();

    void addProduct(std::string productName, int quantity);
    void removeProduct(std::string productName, int quantity);
    int getQuantity(std::string productName);
    std::vector<std::string> getProducts();

private:
    std::map<std::string, int> products_;
};

#endif // MONITOR_H