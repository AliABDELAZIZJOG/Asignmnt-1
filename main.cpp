#include <iostream>
#include <queue>
using namespace std;

class Car {

	private:
		string Car_Brand;   
		string Car_Type;
		string Car_Plate;
		int Speed; 
		int Year_Model;

	public:
		Car() {}
		Car(string Car_Brand, int Max_Speed, int Year_Model)
		{
			this -> Car_Brand = Car_Brand;
			Speed = Max_Speed;
			this -> Year_Model = Year_Model;
		}

		Car(string Car_Brand, string Car_Type, int Max_Speed, int Year_Model)
		{
			this->Car_Brand = Car_Brand;
			this->Car_Type = Car_Type;
			Speed = Max_Speed;
			this->Year_Model = Year_Model;
		}
	
		void setBrand(string str) { 
			Car_Brand = str;
		}
		string getBrand() {
			return Car_Brand;
		}

		void setType(string str) {
			Car_Type = str;
		}
		string getType() {
			return Car_Type;
		}

		void setPlate(string str) {
			Car_Plate = str;
		}
		string getPlate() {
			return Car_Plate;
		}

		void setSpeed(int x) {
			Speed = x;
		}
		int getSpeed() {
			return Speed;
		}
		
		void setYear(int x) {
			Year_Model = x;
		}
		int getYear() {
			return Year_Model;
		}
		void carinfo() {
			cout << "Car Brand: " << Car_Brand << endl;
			cout << "Car Type: " << Car_Type << endl;
			cout << "Car Plate: " << Car_Plate << endl;
			cout << "Car Speed: " << Speed << endl;
			cout << "Car Model: " << Year_Model << endl;
		}

};



class Road {

	private :
		char Road_Type;
		int Speed_Limit;
		int count = 0;

	public :
		Road() {}
		Road(char Road_Type, int Speed_Limit) {
			this->Road_Type = Road_Type;
			this->Speed_Limit = Speed_Limit;
		}

		void setRType(char chr) {
			Road_Type = chr;
		}
		char getRType() {
			return Road_Type;
		}

		void setSPLimit(int x) {
			Speed_Limit = x;
		}
		int getSPLimit() {
			return Speed_Limit;
		}

		void setCount(int x) {
			count = x;
		}
		int getCount() {
			return count;
		}

		bool Radar(int car_speed) 
		{
			if (car_speed > Speed_Limit) { 
				return true;			
			}								
			return false;
		}

		void allow(Car car) {
			if (Road_Type == 'A' && ((car.getType() == "Private Vehicle") || (car.getType() == "Motorcycle Vehicle")))
			{
				count = count + 1;
				if (Radar(car.getSpeed()) == true)
				{
					cout << "This vehicle has passed the speed limit on this road and will be fined." << endl;
					car.carinfo();
					cout << endl;
				}

			}

			if ((car.getType() != "Private Vehicle") && (car.getType() != "Motorcycle Vehicle"))
			{	
				cout << "This Vehicle is not allowed on road A and will be fined!" << endl;
				car.carinfo();
				cout << endl;
			}


			if (Road_Type == 'C' && car.getType() == "Truck")
			{
				count = count + 1;

				if (Radar(car.getSpeed()) == true)
				{
					cout << "This vehicle has passed the speed limit on this road and will be fined." << endl;
					car.carinfo();
					cout << endl;
				}
			}

			if (car.getType() != "Truck")
			{
				cout << "This Vehicle is not allowed on road C and will be fined!" << endl;
				car.carinfo();
				cout << endl;
			}

			if (Road_Type == 'B')
			{
				count = count + 1; 
				if (Radar(car.getSpeed()) == true)
				{
					cout << "This vehicle has passed the speed limit on this road and will be fined." << endl;
					car.carinfo();
					cout << endl;
				}		
				
			}
		}

		int age(int Year_Model) {
			return 2022 - Year_Model;
		}
		


};


int main() {
	
	Car porche("Porche", "Private Vehicle", 70, 1999);	
	Car merc("Mercedes", "Private Vehicle", 90, 2022);
	Car mercTruck("Mercedes", "Truck", 40, 2020);
	Car ford("Ford", "Private Vehicle", 50, 2016);
	Car Ducati("Ducati", "Motorcycle Vehicle", 330, 2017);

	Road suez('A', 60);
	Road ninety('B', 90);
	Road ringRoad('C', 50);



	queue <Car> event; 
	event.push(porche);
	event.push(merc);
	event.push(mercTruck);
	event.push(ford);
	event.push(Ducati);


	while (!event.empty()) {
		suez.Radar(event.front().getSpeed());
		suez.allow(event.front());
		suez.age(event.front().getYear());

		ninety.Radar(event.front().getSpeed());
		ninety.allow(event.front());
		ninety.age(event.front().getYear());

		ringRoad.Radar(event.front().getSpeed());
		ringRoad.allow(event.front());
		ringRoad.age(event.front().getYear());

		event.pop();
	}

	cout << "The number of cars that passed through the Suez road (A) is: " << suez.getCount() << endl;
	cout << "The number of cars that passed through the Ninety road (B) is: " << ninety.getCount() << endl;
	cout << "The number of cars that passed through the Ring Road road (C) is: " << ringRoad.getCount() << endl;

	double max;

	if (suez.getCount() > ninety.getCount() && suez.getCount() > ringRoad.getCount()) {
		max = suez.getCount();
	}
	else if (ninety.getCount() > ringRoad.getCount()) {
		max = ninety.getCount();
	}
	else {
		max = ringRoad.getCount();
	}


	cout << "The efficiency of the Suez road (A) is: " << (suez.getCount()/max)*100 << endl;
	cout << "The efficiency of the Ninety road (B) is: " << (ninety.getCount()/max)*100 << endl;
	cout << "The efficiency of the Ring Road road (C) is: " << (ringRoad.getCount()/max)*100 << endl;


	return 0;
}