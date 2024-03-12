#include<iostream>
#include<vector>
#include<string>
#include <functional>
#include <algorithm>
#include "conio.h"


class Harvest //плод
{
private:
	std::string Name_ = "";
	std::string Color_ = "";
	int Weight_ = 0;

public:
	Harvest() {}
	Harvest(std::string name, std::string color, int weight) {
		Name_ = name;
		Color_ = color;
		Weight_ = weight;
	}
	~Harvest(){}
	std::string Get_Name() { return Name_; }
	std::string Get_Color() { return Color_; }
	int Get_Weight() { return Weight_; }
};

class Plants //растение
{
public:
	virtual void Get_Quantity_Harvest() = 0;//возможное кол-во плодов
	virtual void Get_size_plant() = 0; //размер растения
	virtual void Info()const = 0;
	virtual void Get_Harvest(unsigned long int num) = 0;
	virtual void ALLWeight() = 0;
};

class Apple_tree:public Plants
{
private:
	std::vector<Harvest>harvest_;
	std::string size_ = " Big tree ";
	int Quantity_Harvest_;     //возможное кол-во плодов
	std::string Name_Fruit_ = "Apple";
	std::vector<Harvest>::iterator p = harvest_.begin();
	Harvest* New_Harvest() {
		int Rand_Weight = 0;                                                                     
		auto f= [&Rand_Weight]() {Rand_Weight = rand() % 30 + 150; };
		f();
		Harvest* tmp = new Harvest(Name_Fruit_, "green", Rand_Weight);
		return tmp;
	}
public:
	//конструктор
	Apple_tree(int num) {              
		auto num2 = (rand() % 40);
		Quantity_Harvest_ =  num2+num;
		harvest_.reserve(Quantity_Harvest_);
		if (num <= Quantity_Harvest_) 
			for (int i = 1; i <= num; i++) 
				harvest_.push_back(*New_Harvest());
		else{
			std::cout << "error \n";
			return;
		}
	}

	void Get_Harvest(unsigned long int num) override {
		if (num > harvest_.size())
			num = harvest_.size();
		harvest_.erase(harvest_.end() - num, harvest_.end());
	}
	void Get_size_plant()override {
		std::cout << "Apple_tree: " << size_ << std::endl;
	}
	void Info()const override {
		std::cout << "This Apple_tree:\n"
			<< "   Size tree - " << size_ << "\n"
			<< "Fruit: " << "\n";
		if (harvest_.empty())
			std::cout << " No Fruit  \n";
		else {
			for (auto p : harvest_) {
				std::cout << "   Name: " << p.Get_Name() << "  Color: " << p.Get_Color() << "  Weight: " << p.Get_Weight() << ".gramm" << std::endl;
			}
		}
	}
	void Get_Quantity_Harvest() override { //возможное кол-во плодов
		std::cout << "Quantity_Harvest: " << Quantity_Harvest_ << std::endl;
	}   
	/*void ALLWeight(std::function<int(int)> alg) {
		for (auto p: harvest_) {
			alg(p.Get_Weight());
		}
	}*/
	void ALLWeight()override {
		int Sum = 0;
		std::for_each(harvest_.begin(), harvest_.end(), [&Sum](Harvest & hr)->int {
			auto a = hr.Get_Weight();
			Sum += a;
			return Sum; 
			});
		std::cout<<"\n   ALL Weight Harvest = " << Sum << " g.\n\n";
	}
};

class Pear_tree :public Plants
{
private:
	std::vector<Harvest>harvest_;
	std::string size_ = " Big tree ";
	int Quantity_Harvest_;     //возможное кол-во плодов
	std::string Name_Fruit_ = "Pear";
	std::vector<Harvest>::iterator p = harvest_.begin();
	Harvest* New_Harvest() {
		int Rand_Weight = 0;
		auto f = [&Rand_Weight]() {Rand_Weight = rand() % 30 + 100; };
		f();
		Harvest* tmp = new Harvest(Name_Fruit_, "yellow", Rand_Weight);
		return tmp;
	}

public:
	Pear_tree(int num) { //конструктор
		auto num2 = (rand() % 30);
		Quantity_Harvest_ = num2 + num;
		harvest_.reserve(Quantity_Harvest_);
		if (num <= Quantity_Harvest_)
			for (int i = 1; i <= num; i++)
				harvest_.push_back(*New_Harvest());
		else {
			std::cout << "error \n";
			return;
		}
	}
	void Get_Harvest(unsigned long int num) override {
		if (num > harvest_.size())
			num = harvest_.size();
		harvest_.erase(harvest_.end() - num, harvest_.end());
	}
	void Get_size_plant()override {
		std::cout << "Pear_tree: " << size_ << std::endl;
	}
	void Info()const override {
		std::cout << "This Pear_tree:\n"
			<< "   Size tree - " << size_ << "\n"
			<< "Fruit: " << "\n";
		if (harvest_.empty())
			std::cout << " No Fruit  \n";
		else {
			for (auto p : harvest_) {
				std::cout << "   Name: " << p.Get_Name() << "  Color: " << p.Get_Color() << "  Weight: " << p.Get_Weight() << ".gramm" << std::endl;
			}
		}

	}
	void Get_Quantity_Harvest() override { //возможное кол-во плодов
		std::cout << "Quantity_Harvest: " << Quantity_Harvest_ << std::endl;
	}
	void ALLWeight()override {
		int Sum = 0;
		std::for_each(harvest_.begin(), harvest_.end(), [&Sum](Harvest& hr)->int {
			auto a = hr.Get_Weight();
			Sum += a;
			return Sum;
			});
		std::cout << "\n   ALL Weight Harvest = " << Sum << " g.\n\n";
	}


};

class Raspberries :public Plants
{
private:
	std::vector<Harvest>harvest_;
	std::string size_ = " Midlle tree ";
	int Quantity_Harvest_;     //возможное кол-во плодов
	std::string Name_Fruit_ = "Raspberries";
	std::vector<Harvest>::iterator p = harvest_.begin();
	Harvest* New_Harvest() {
		int Rand_Weight = 0;
		auto f = [&Rand_Weight]() {Rand_Weight = rand() % 3+ 20; };
		f();
		Harvest* tmp = new Harvest(Name_Fruit_, "Red", Rand_Weight);
		return tmp;
	}

public:
	Raspberries(int num) { //конструктор
		auto num2 = (rand() % 200);
		Quantity_Harvest_ = num2 + num;
		harvest_.reserve(Quantity_Harvest_);
		if (num <= Quantity_Harvest_)
			for (int i = 1; i <= num; i++)
				harvest_.push_back(*New_Harvest());
		else {
			std::cout << "error \n";
			return;
		}
	}
	void Get_Harvest(unsigned long int num) override {
		if (num > harvest_.size())
			num = harvest_.size();
		harvest_.erase(harvest_.end() - num, harvest_.end());
	}
	void Get_size_plant()override {
		std::cout << "Raspberries: " << size_ << std::endl;
	}
	void Info()const override {
		std::cout << "This Raspberries:\n"
			<< "   Size tree - " << size_ << "\n"
			<< "Fruit: " << "\n";
		if (harvest_.empty())
			std::cout << " No Fruit  \n";
		else {
			for (auto p : harvest_) {
				std::cout << "   Name: " << p.Get_Name() << "  Color: " << p.Get_Color() << "  Weight: " << p.Get_Weight() << ".gramm" << std::endl;
			}
		}
	}
	void Get_Quantity_Harvest() override { //возможное кол-во плодов
		std::cout << "Quantity_Harvest: " << Quantity_Harvest_ << std::endl;
	}
	void ALLWeight()override {
		int Sum = 0;
		std::for_each(harvest_.begin(), harvest_.end(), [&Sum](Harvest& hr)->int {
			auto a = hr.Get_Weight();
			Sum += a;
			return Sum;
			});
		std::cout << "\n   ALL Weight Harvest = " << Sum << " g.\n\n";
	}

};





int main() {
	srand(time(NULL));

	Raspberries ps(10);
	Apple_tree ap(7);
	Pear_tree pt(8);
	Plants* Plants_point;
	Plants_point = &ap;
	Plants_point->Info();
	Plants_point->ALLWeight();
	Plants_point->Get_Quantity_Harvest();
	std::cout << "\n\n";
	Plants_point = &pt;
	Plants_point->Info();
	Plants_point->ALLWeight();
	Plants_point->Get_size_plant();
	Plants_point->Get_Quantity_Harvest();
	std::cout << "\n\n";
	Plants_point = &ps;
	Plants_point->Info();
	Plants_point->ALLWeight();
	Plants_point->Get_size_plant();
	Plants_point->Get_Quantity_Harvest();
	std::cout << "===========================================\n\n";
	

	/*Plants_point->Get_Harvest(5);
	std::cout << "\n\n";
	Plants_point->Info();
	Plants_point->Get_Harvest(3);
	std::cout << "\n\n";
	Plants_point->Info();
	Plants_point->Get_Harvest(5);
	std::cout << "\n\n";
	Plants_point->Info();*/

	
	

	

	//std::sort(harvest_.begin(), harvest_.end(),
	//	[](const Runner& a, const Runner& b)->bool {
	//		return a.Name < b.Name;
	//	}
	//);


	_getch();
	return 0;
}

