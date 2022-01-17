#include<iostream>

class room
{
private:
	double temperature;
public:
	room()
	{
		this->temperature = 25;
	}
	void setTemp(double newtemp)
	{
		this->temperature = newtemp;
	}
	double getTemp()
	{
		return temperature;
	}
};

class conditioner
{
private:
	bool isOn;
	double temperature;
	room Room;
public:
	conditioner()
	{
		isOn = false;
		temperature = 25;
	}
	void setTemp(double newtemp)
	{
		if (this->isOn) 
		{
			this->temperature = newtemp;
			this->Room.setTemp(newtemp);
		}
	}
	void switchCondition()
	{
		this->isOn += 1;
	}
	double getTemp()
	{
		return temperature;
	}
	bool getIsOn()
	{
		return isOn;
	}
	room getRoom()
	{
		return Room;
	}
};

class pult
{
public:
	void setTemp(conditioner& conditioner, double newtemp)
	{
			conditioner.setTemp(newtemp);
	}
	void switchCondition(conditioner& conditioner)
	{
		conditioner.switchCondition();
	}
};

int main()
{
	conditioner cond;
	pult pult;

	std::cout << cond.getRoom().getTemp() << "\n";

	pult.switchCondition(cond);
	pult.setTemp(cond, 20);

	std::cout << cond.getRoom().getTemp() << "\n";
}