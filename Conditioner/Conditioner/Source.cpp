#include<iostream>

class Room
{
private:
	double temperature;
public:
	Room()
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
	Room* room;
	conditioner() {}
public:
	conditioner(Room* room)
	{
		isOn = false;
		this->room = room;
	}
	void setTemp(double newtemp)
	{
		if (this->isOn)
		{
			this->room->setTemp(newtemp);
		}
	}
	void switchCondition()
	{
		this->isOn = !this->isOn;
	}
};

class pult
{
private:
	conditioner* cond;
public:
	pult(conditioner* someCond)
	{
		this->cond = someCond;
	}
	void setTemp(double newtemp)
	{
		cond->setTemp(newtemp);
	}
	void switchCondition()
	{
		cond->switchCondition();
	}
};

int main()
{
	Room room;
	conditioner cond(&room);
	pult pult(&cond);

	std::cout << room.getTemp() << "\n";
	pult.switchCondition();
	pult.setTemp(20);
	std::cout << room.getTemp() << "\n";
}