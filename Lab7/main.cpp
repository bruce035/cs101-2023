#include <iostream>
#include <string>

using namespace std;

class Car {
protected:
    string m_brand;
    string m_model;
    int m_year;
    int m_numDoors;

public:
    Car(string brand, string model, int year, int numDoors)
        : m_brand(brand), m_model(model), m_year(year), m_numDoors(numDoors) {}

    string getBrand() { return m_brand; }
    string getModel() { return m_model; }
    int getYear() { return m_year; }
    int getNumDoors() { return m_numDoors; }
};

class BMW_Car : public Car {
private:
    string m_DriveMode;

public:
    BMW_Car(string model, int year, int numDoors) : Car("BMW", model, year, numDoors) {
        cout << "Constructing BMW_Car\n";
        m_DriveMode = "Rear-wheel";
    }

    string getDriveMode() { return m_DriveMode; }
};

class AUDI_Car : public Car {
private:
    string m_DriveMode;

public:
    AUDI_Car(string model, int year, int numDoors) : Car("AUDI", model, year, numDoors) {
        cout << "Constructing AUDI_Car\n";
        m_DriveMode = "Front-wheel";
    }

    string getDriveMode() { return m_DriveMode; }
};

class BENZ_Car : public Car {
private:
    string m_DriveMode;

public:
    BENZ_Car(string model, int year, int numDoors) : Car("BENZ", model, year, numDoors) {
        cout << "Constructing BENZ_Car\n";
        m_DriveMode = "Front-wheel";
    }

    string getDriveMode() { return m_DriveMode; }
};

int main() {
    BMW_Car car1(" ", 2023, 6);
    cout << car1.getBrand() << " " << car1.getModel() << ": Drive Mode = " << car1.getDriveMode() << endl;

    AUDI_Car car2(" ", 2023, 4);
    cout << car2.getBrand() << " " << car2.getModel() << ": Drive Mode = " << car2.getDriveMode() << endl;

    BENZ_Car car3(" ", 2023, 4);
    cout << car3.getBrand() << " " << car3.getModel() << ": Drive Mode = " << car3.getDriveMode() << endl;

    return 0;
}
