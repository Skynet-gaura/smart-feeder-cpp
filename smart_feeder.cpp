#include <iostream>

using namespace std;

class SmartFeeder {
private:
	int maxCapacity;
	int currentFood;
	int feedPortion;
public:
	SmartFeeder(int capacity, int portion) {
		maxCapacity = capacity;
		feedPortion = portion;
		currentFood = maxCapacity;
	}
	void refill() {
			currentFood = maxCapacity;
	}
	bool dispense() {
		if (currentFood >= feedPortion) {
			currentFood = currentFood - feedPortion;
			cout << "Food dispensed! Remaining: " << currentFood << "g." << endl;
			return true;
		}
		else
		{
			cout << "Error: not enough food!" << endl;
			return false;
		}
	}
};

int main(){
	SmartFeeder feeder(500, 50);
	for (int i = 1;i <= 18;i++) {
		cout << "Attempt " << i << ": ";
		if (feeder.dispense() == false) {
			feeder.refill();
			cout << "Feeder refiled automatically!" << endl;
		}
	}
	return 0;
}
