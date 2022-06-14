COMPILER = g++
STD_OPTION = -std=c++17
WARNING_OPTION = -Wall
OUTPUT_OPTION = -o
PROGRAM = main.out

all: $(PROGRAM)

run: $(PROGRAM)
	./$(PROGRAM)

$(PROGRAM): main.cpp CustomerType_Employee.cpp CustomerType_Student.cpp CustomerType_Vendor.cpp VehicleType_Car.cpp VehicleType_Truck.cpp VehicleType_Motorcycle.cpp Invoice.cpp
	$(COMPILER) $(STD_OPTION) $(WARNING_OPTION) main.cpp CustomerType_Employee.cpp CustomerType_Student.cpp CustomerType_Vendor.cpp VehicleType_Car.cpp VehicleType_Truck.cpp VehicleType_Motorcycle.cpp Invoice.cpp $(OUTPUT_OPTION) $(PROGRAM) 

clean:
	rm *.out