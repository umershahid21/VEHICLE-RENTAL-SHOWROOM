# Umer Vehicle Rental Showroom

## Overview

This C++ application manages vehicle rentals for a rental showroom. It handles vehicle selection, customer information, license verification, reservations, and payment processing.

## Classes

### Vehicle

- **Purpose**: Base class for all types of vehicles.
- **Attributes**:
  - `string model`: Model of the vehicle.
  - `string make`: Manufacturer of the vehicle.
  - `int year`: Year of manufacture.
  - `string registrationNumber`: Vehicle registration number.
- **Methods**:
  - `Vehicle(string model, string make, int year, string regNumber)`: Constructor to initialize vehicle details.
  - `virtual double calculateRentalCost(int days) const`: Calculates rental cost based on days. Default implementation returns `20.0 * days`.
  - `void displayInfo() const`: Displays vehicle details.

### Car

- **Purpose**: Represents a car.
- **Attributes**:
  - `int numberOfSeats`: Number of seats.
  - `string fuelType`: Type of fuel used.
  - `double trunkCapacity`: Capacity of the trunk.
- **Methods**:
  - `Car(string model, string make, int year, string regNumber, int seats, string fuel, double trunkCapacity)`: Constructor to initialize car details.
  - `double calculateRentalCost(int days) const override`: Returns `3000.0 * days` as rental cost.
  - `void displayInfo() const`: Displays car details (inherits from `Vehicle`).

### SUV

- **Purpose**: Represents an SUV, derived from `Car`.
- **Attributes**:
  - `bool offRoadCapable`: Indicates if the SUV is off-road capable.
  - `int towingCapacity`: Towing capacity of the SUV.
- **Methods**:
  - `SUV(string model, string make, int year, string regNumber, int seats, string fuel, double trunkCapacity, bool offRoad, int towing)`: Constructor to initialize SUV details.
  - `double calculateRentalCost(int days) const override`: Returns `6000.0 * days` as rental cost.
  - `void displayInfo() const`: Displays SUV details (inherits from `Car`).

### Truck

- **Purpose**: Represents a truck.
- **Attributes**:
  - `double cargoCapacity`: Capacity of the truck.
- **Methods**:
  - `Truck(string model, string make, int year, string regNumber, double cargoCapacity)`: Constructor to initialize truck details.
  - `double calculateRentalCost(int days) const override`: Returns `15750.0 * days` as rental cost.
  - `void displayInfo() const`: Displays truck details (inherits from `Vehicle`).

### Motorcycle

- **Purpose**: Represents a motorcycle.
- **Attributes**:
  - `string type`: Type of motorcycle (e.g., cruiser, sport).
  - `int numberOfWheels`: Number of wheels.
- **Methods**:
  - `Motorcycle(string model, string make, int year, string regNumber, string bikeType, int wheels)`: Constructor to initialize motorcycle details.
  - `double calculateRentalCost(int days) const override`: Returns `1000.0 * days` as rental cost.
  - `void displayInfo() const`: Displays motorcycle details (inherits from `Vehicle`).

### Customer

- **Purpose**: Represents a customer.
- **Attributes**:
  - `string name`: Customer's name.
  - `long long contactNumber`: Customer's contact number.
- **Methods**:
  - `Customer()`: Constructor to initialize customer details.
  - `void displayInfo() const`: Displays customer information.

### Address

- **Purpose**: Represents a customer's address.
- **Attributes**:
  - `string street`: Street address.
  - `string city`: City.
- **Methods**:
  - `Address()`: Constructor to initialize address details.
  - `void displayInfo() const`: Displays address information.

### License

- **Purpose**: Represents a customer's driving license.
- **Attributes**:
  - `long long licenseNumber`: License number.
  - `int expirationMonth`: Expiration month.
  - `int expirationYear`: Expiration year.
- **Methods**:
  - `License()`: Constructor to initialize license details.
  - `void displayInfo() const`: Displays license information.

### Reservation

- **Purpose**: Represents a vehicle reservation.
- **Attributes**:
  - `Vehicle* reservedVehicle`: Pointer to the reserved vehicle.
  - `Customer reservingCustomer`: The customer making the reservation.
  - `string startDate`: Start date of the reservation.
  - `int reservationDays`: Number of days for the reservation.
- **Methods**:
  - `Reservation(Vehicle* vehicle, const Customer& customer, const string& start, int days)`: Constructor to initialize reservation details.
  - `void displayInfo() const`: Displays reservation information.

### RentalAgency

- **Purpose**: Manages the rental agency operations.
- **Attributes**:
  - `Vehicle* availableVehicles[3]`: Array of available vehicles.
  - `Customer customers[3]`: Array of customers.
  - `Reservation reservations[3]`: Array of reservations.
- **Methods**:
  - `void displayInfo() const`: Displays information about available vehicles, customers, and reservations.

## Main Program Flow

1. **Welcome Message**: Greets the user.
2. **Vehicle Selection**: Allows the user to choose a vehicle type (Car, Truck, Motorcycle, SUV).
3. **Vehicle Choice**: Prompts the user to select a specific vehicle model.
4. **License Verification**: Checks if the user has a valid driver's license.
5. **Customer Information**: Collects customer details.
6. **Address and License Details**: Collects address and license details.
7. **Reservation Details**: Creates a reservation with the selected vehicle and details.
8. **Payment Options**: Offers payment methods (Cash or Card).
9. **Receipt and Final Confirmation**: Displays receipt and asks if the user wants another vehicle or to exit.

## Running the Program

1. **Compile**: Use a C++ compiler to compile the code.
2. **Execute**: Run the compiled executable to start the application.
3. **Follow Prompts**: Follow the on-screen prompts to interact with the rental system.
