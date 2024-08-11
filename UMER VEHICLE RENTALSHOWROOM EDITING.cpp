#include <iostream>
#include <string>
#include <limits>

using namespace std;

class Vehicle {
private:
    string model;
    string make;
    int year;
    string registrationNumber;

public:
    Vehicle(string model, string make, int year, string regNumber)
        : model(model), make(make), year(year), registrationNumber(regNumber) {}

    virtual double calculateRentalCost(int days) const {
        return 20.0 * days;
    }

    void displayInfo() const {
        cout << "Model: " << model << "\n";
        cout << "Make: " << make << "\n";
        cout << "Year: " << year << "\n";
        cout << "Registration Number: " << registrationNumber << "\n";
    }
};

class Car : public Vehicle {
private:
    int numberOfSeats;
    string fuelType;
    double trunkCapacity;

public:
    Car(string model, string make, int year, string regNumber,
        int seats, string fuel, double trunkCapacity)
        : Vehicle(model, make, year, regNumber),
          numberOfSeats(seats), fuelType(fuel), trunkCapacity(trunkCapacity) {}

    double calculateRentalCost(int days) const override {
        return 3000.0 * days;
    }

    void displayInfo() const {
        Vehicle::displayInfo();
  
    }
};

class SUV : public Car {
private:
    bool offRoadCapable;
    int towingCapacity;

public:
    SUV(string model, string make, int year, string regNumber,
        int seats, string fuel, double trunkCapacity,
        bool offRoad, int towing)
        : Car(model, make, year, regNumber, seats, fuel, trunkCapacity),
          offRoadCapable(offRoad), towingCapacity(towing) {}

    double calculateRentalCost(int days) const override {
        return 6000.0 * days;
    }

    void displayInfo() const {
        Car::displayInfo();
     
    }
};

class Truck : public Vehicle {
private:
    double cargoCapacity;

public:
    Truck(string model, string make, int year, string regNumber, double cargoCapacity)
        : Vehicle(model, make, year, regNumber), cargoCapacity(cargoCapacity) {}

    double calculateRentalCost(int days) const override {
        return 15750.0 * days;
    }

    void displayInfo() const {
        Vehicle::displayInfo();
 
    }
};

class Motorcycle : public Vehicle {
private:
    string type;
    int numberOfWheels;

public:
    Motorcycle(string model, string make, int year, string regNumber,
        string bikeType, int wheels)
        : Vehicle(model, make, year, regNumber), type(bikeType), numberOfWheels(wheels) {}

    double calculateRentalCost(int days) const override {
        return 1000.0 * days;
    }

    void displayInfo() const {
        Vehicle::displayInfo();
      
    }
};

class Customer {
private:
    string name;
    long long contactNumber;

public:
   
    Customer() {
        cout << "Enter customer name: ";
        getline(cin, name);

        cout << "Enter contact number: ";
        cin >> contactNumber;
        cin.ignore();
    }

    void displayInfo() const {
        cout << "Name: " << name << "\n";
        cout << "Contact Number: " << contactNumber << "\n";
    }
};

class Address {
private:
    string street;
    string city;

public:
    Address() {
        cout << "Enter street address: ";
        getline(cin, street);

        cout << "Enter city: ";
        getline(cin, city);
    }

    void displayInfo() const {
        cout << "Street: " << street << "\n";
        cout << "City: " << city << "\n";
    }
};

class License {
private:
    long long licenseNumber;
    int expirationMonth;  
    int expirationYear;

public:
    License() {
        cout << "Enter license number: ";
        if (!(cin >> licenseNumber)) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
            cout << "Invalid input for license number. Exiting program.\n";
            exit(1);
        }
        cin.ignore(); 

        cout << "Enter expiration month (MM): ";
        if (!(cin >> expirationMonth) || expirationMonth < 1 || expirationMonth > 12) {
            cin.clear();  
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
            cout << "Invalid input for expiration month. Exiting program.\n";
            exit(1);
        }

        cout << "Enter expiration year (YY): ";
        if (!(cin >> expirationYear) || expirationYear < 0) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
            cout << "Invalid input for expiration year. Exiting program.\n";
            exit(1);
        }
        cin.ignore(); 
    }

    void displayInfo() const {
        cout << "License Number: " << licenseNumber << "\n";
        cout << "Expiration Date: " << expirationMonth << "/" << expirationYear << "\n";
    }
};


class Reservation {
private:
    Vehicle* reservedVehicle;
    Customer reservingCustomer;
    string startDate;
    int reservationDays;

public:
    Reservation(Vehicle* vehicle, const Customer& customer, const string& start, int days)
        : reservedVehicle(vehicle), reservingCustomer(customer), startDate(start), reservationDays(days) {}

    void displayInfo() const {
        cout << "\n\t\tReservation Information:\n";
        cout << "Start Date: (TO BE FILLED BY THE PERSON SITTING AT THE COUNTER)" << startDate << "\n";
        cout << "Reservation Days: " << reservationDays << "\n";
        cout << "Reserved Vehicle:\n";
        reservedVehicle->displayInfo();
        cout << "Reserving Customer:\n";
        reservingCustomer.displayInfo();
        cout << "Rental Cost: Rs" << reservedVehicle->calculateRentalCost(reservationDays) << "\n";
    }
};

class RentalAgency {
private:
    static const int maxVehicles = 3;
    static const int maxCustomers = 3;
    static const int maxReservations = 3;
    Vehicle* availableVehicles[maxVehicles];
    Customer customers[maxCustomers];
    Reservation reservations[maxReservations];

public:
    void displayInfo() const {
        cout << "Available Vehicles:\n";
        for (int i = 0; i < maxVehicles; ++i) {
            availableVehicles[i]->displayInfo();
            cout << "-------------\n";
        }

        cout << "Customers:\n";
        for (int i = 0; i < maxCustomers; ++i) {
            customers[i].displayInfo();
            cout << "-------------\n";
        }

        cout << "Reservations:\n";
        for (int i = 0; i < maxReservations; ++i) {
            reservations[i].displayInfo();
            cout << "-------------\n";
        }
    }
};

int main() {
    cout << "Welcome to Umer Rental Showroom!\n\n";

    do {
        cout << "Choose the type of vehicle to rent:\n";
        cout << "1. Car\n";
        cout << "2. Truck\n";
        cout << "3. Motorcycle\n";
        cout << "4. SUV\n";
        cout << "Enter your choice (1-4): ";

        int choice;
        cin >> choice;
        cin.ignore();

        Vehicle* rentedVehicle = NULL;
        double rentalCost = 0.0;
if (choice == 1) {
    cout << "Choose a car:\n";
    cout << "1. Honda Civic\n";
    cout << "2. Toyota Camry\n";
    cout << "3. Changan Alsivin\n";
    cout << "4. Suzuki WagonR\n";
    cout << "5. Tesla Model S\n";

    int carChoice;
    cin >> carChoice;
    cin.ignore();

    if (carChoice == 1) {
        rentedVehicle = new Car("CIVIC", "HONDA", 2023, "ABC123", 5, "Gasoline", 15.5);
        rentalCost = 8000.0;
    } else if (carChoice == 2) {
        rentedVehicle = new Car("CAMRY", "TOYOTA", 2021, "XYZ456", 5, "Gasoline", 14.0);
        rentalCost = 17000.0;
    } else if (carChoice == 3) {
        rentedVehicle = new Car("ALSIVIN", "CHANGAN", 2022, "MST123", 4, "Gasoline", 13.8);
        rentalCost = 7000.0;
    } else if (carChoice == 4) {
        rentedVehicle = new Car("WAGONR", "SUZUKI", 2017, "MLB789", 5, "Gasoline", 15.0);
        rentalCost = 4000.0;
    } else if (carChoice == 5) {
        rentedVehicle = new Car("Model S", "TESLA", 2020, "TES001", 5, "Electric", 12.0);
        rentalCost = 35000.0;
    } else {
        cout << "Invalid choice.\n";
        return 1;
    }
}
    else if (choice == 2) {
    cout << "Choose a truck:\n";
    cout << "1. Ford F-150\n";
    cout << "2. Chevy Silverado\n";

    int truckChoice;
    cin >> truckChoice;
    cin.ignore();

    if (truckChoice == 1) {
        rentedVehicle = new Truck("F-150", "Ford", 2012, "DEF456", 2000.0);
        rentalCost = 41000.0;
    } else if (truckChoice == 2) {
        rentedVehicle = new Truck("Silverado", "Chevy", 2015, "GHI789", 1800.0);
        rentalCost = 36000.0;
    } else {
        cout << "Invalid choice.\n";
        return 1;
    }
} else if (choice == 3) {
    cout << "Choose a motorcycle:\n";
    cout << "1. Harley Davidson\n";
    cout << "2. Yamaha YBR\n";
    cout << "3. HONDA CD-70\n";

    int motorcycleChoice;
    cin >> motorcycleChoice;
    cin.ignore();

    if (motorcycleChoice == 1) {
        rentedVehicle = new Motorcycle("Harley", "Harley Davidson", 2022, "MOTO123", "Cruiser", 2);
        rentalCost = 7000.0;
    } else if (motorcycleChoice == 2) {
        rentedVehicle = new Motorcycle("YBR", "Yamaha", 2022, "MOTO456", "Sport Bike", 2);
        rentalCost = 5000.0;
    } else if (motorcycleChoice == 3) {
        rentedVehicle = new Motorcycle("CD-70", "HONDA", 2014, "DUC789", "Street", 2);
        rentalCost = 1000.0;
    } else {
        cout << "Invalid choice.\n";
        return 1;
    }
} else if (choice == 4) {
    cout << "Choose an SUV:\n";
    cout << "1. Toyota Fortuner Legender\n";
    cout << "2. Kia Sportage\n";
    cout << "3. Hyundai Tucson\n";

    int suvChoice;
    cin >> suvChoice;
    cin.ignore();

    if (suvChoice == 1) {
        rentedVehicle = new SUV("Fortuner Legender", "Toyota", 2022, "GHI789", 7, "Gasoline", 20.0, true, 5000);
        rentalCost = 22000.0;
    } else if (suvChoice == 2) {
        rentedVehicle = new SUV("Sportage", "Kia", 2021, "JKL012", 8, "Gasoline", 18.0, false, 4000);
        rentalCost = 19000.0;
    } else if (suvChoice == 3) {
        rentedVehicle = new SUV("Tucson", "Hyundai", 2022, "JEEP001", 5, "Gasoline", 19.5, true, 4500);
        rentalCost = 18500.0;
    } else {
        cout << "Invalid choice.\n";
        return 1;
    }
} else {
    cout << "Invalid choice.\n";
    return 1;
}
          int hasLicense;
        cout << "Do you have a valid driver's license? (1. Yes, 2. No): ";
        cin >> hasLicense;
        cin.ignore();
        if (hasLicense != 1) {
            cout << "You cannot rent the vehicle without a valid license. Exiting program.\n";
            delete rentedVehicle;
            return 1;
        }
         Customer myCustomer;
        Address myAddress;
        License myLicense;

        cout << "Enter number of days for reservation: ";
        int reservationDays;
        cin >> reservationDays;
        system("cls");

        if (rentalCost == 0) {
            cout << "You cannot rent the vehicle. Rental cost is 0 Rs.\n";
            delete rentedVehicle;
            continue;
        }

        Reservation myReservation(rentedVehicle, myCustomer, "", reservationDays);

        cout<<"\t\t\t YOUR FINAL RECIEPT IS \t\t\t\n";
		cout << "\n\t\tVehicle Information:\n";
        rentedVehicle->displayInfo();

        cout << "\t\tCustomer Information:\n";
        myCustomer.displayInfo();

        cout << "\n\t\tAddress Information:\n";
        myAddress.displayInfo();

        cout << "\t\tLicense Information:\n";
        myLicense.displayInfo();

        myReservation.displayInfo();

        cout << "\n\nOur Valuable customer so far. I hope your experience is going Great. I am the management head at this place.\n";
        cout << "\nPlease Choose a payment method:\n";
        cout << "1. Cash (Go to Cash Counter)\n";
        cout << "2. Card\n";
        cout << "3. Don't want the car\n";
        cout << "Enter your choice (1-3): ";

        int paymentChoice;
        cin >> paymentChoice;

        if (paymentChoice == 1) {
            cout << "Please proceed to the cash counter for cash payment.\n";
        } else if (paymentChoice == 2) {
            cout << "Enter credit card number: ";
            string creditCardNumber;
            cin.ignore();
            getline(cin, creditCardNumber);
            cout << "Payment successful! Thank you for trusting us.\n";
        } else if (paymentChoice == 3) {
            cout << "Thank you for considering Umer Rental Showroom! We hope to serve you another time.\n";
        } else {
            cout << "Invalid choice.\n";
            return 1;
        }

        delete rentedVehicle;

        cout << "\nDo you need another vehicle? (1. Yes, 2. No): ";
        int anotherVehicleChoice;
        cin >> anotherVehicleChoice;

        if (anotherVehicleChoice != 1) {
            cout << "\nThanks for trusting us. Goodbye from Umer Vehicle Rental Showroom!\n";
            break;
        }

    } while (true);

    return 0;
}

