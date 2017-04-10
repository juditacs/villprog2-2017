#include <iostream>
#include <string>
#include <sstream>

class IPrintable {
public:
    virtual std::string toString() const = 0;
    virtual ~IPrintable() {}
};

class IBookable {
public:
	virtual int getPrice() const = 0;
    virtual ~IBookable() {}
};

class Printer {
public:
    void AddElementsToPrint(IPrintable* printables[], int count) {
        for (int i=0; i<count; i++) std::cout << printables[i]->toString() << std::endl;
    }
};

class Booking {
public:
    void AddItems(IBookable* bookables[], int count) {
        int total = 0;
        for (int i=0; i<count; i++) {
            std::cout << bookables[i]->getPrice() << std::endl;
            total += bookables[i]->getPrice();
        }
        std::cout << "total: " << total << std::endl;
    }
};

class Product: public IPrintable, public IBookable {
private:
	std::string name;
	int price;
public:
	Product(std::string pname, int price) : name(pname), price(price) {}
	int getPrice() const { return price; }
	std::string toString() const {
        std::stringstream ss;
        ss << name << ": " << price;
        return ss.str();
    }
};

class ShopDetails: public IPrintable {
private:
	std::string name;
	std::string address;
public:
	ShopDetails(std::string name, std::string address) : name(name), address(address) {}
    std::string toString() const { return name + " - " + address; }
};

int main() {
	IPrintable* printables[3];

	printables[0] = new ShopDetails("BestShop", "Somewhere over the rainbow");
	printables[1] = new Product("milk", 120);
	printables[2] = new Product("bread", 150);

	Printer printer;
	printer.AddElementsToPrint(printables, 3);

	for (int i = 0; i < 3; i++)
		delete printables[i];

    IBookable* bookables[2];
	bookables[0] = new Product("milk", 120);
	bookables[1] = new Product("bread", 150);

    Booking b;
    b.AddItems(bookables, 2);

	for (int i = 0; i < 2; i++)
		delete bookables[i];

	return 0;
}
