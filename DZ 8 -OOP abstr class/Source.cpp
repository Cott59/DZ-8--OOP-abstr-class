#include<iostream>
#include<vector>
#include<string>
#include <functional>
#include <algorithm>
#include "conio.h"


class Harvest //����
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

class Plants //��������
{
public:
	virtual void Get_Quantity_Harvest() = 0;//��������� ���-�� ������
	virtual void Get_size_plant() = 0; //������ ��������
	virtual void Info()const = 0;
	//virtual void Get_Harvest(int num, Plants* plants) = 0;

};

class Apple_tree:public Plants
{
private:
	std::vector<Harvest>harvest_;
	std::string size_ = " Big tree ";
	int Quantity_Harvest_;     //��������� ���-�� ������
	std::string Name_Fruit_ = "Apple";
	std::vector<Harvest>::iterator p = harvest_.begin();
	Harvest* New_Harvest() {
		int Rand_Weight = 0;
		                                                                     //srand(time(NULL));
		auto f= [&Rand_Weight]() {Rand_Weight = rand() % 30 + 150; };
		f();
		Harvest* tmp = new Harvest(Name_Fruit_, "green", Rand_Weight);
		return tmp;
	}

public:
	Apple_tree(int num) { //�����������
		                                                                       //num = (rand() % 40);
		Quantity_Harvest_ = (rand() % 30);
		                                                                      /*harvest_.size()= Quantity_Harvest*/
		if (num <= Quantity_Harvest_) 
			for (int i = 1; i <= num; i++) 
				harvest_.push_back(*New_Harvest());
		else{
			std::cout << "error \n";
			return;
		}
	}
	void Get_size_plant()override {
		std::cout << "Apple_tree: " << size_ << std::endl;
	}
	void Info()const override {
		std::cout << "This Apple_tree:\n"
			<< "   Size tree - " << size_ << "\n"
			<< "Fruit: " << "\n";
		for (auto p : harvest_) {
			std::cout << "   Name: " << p.Get_Name() << "  Color: " << p.Get_Color() << "  Weight: " << p.Get_Weight() << ".gramm" << std::endl;
		}
		
	}
	void Get_Quantity_Harvest() override { //��������� ���-�� ������
		std::cout << "Quantity_Harvest: " << Quantity_Harvest_ << std::endl;
	}   
	


};

class Pear_tree :public Plants
{
private:
	std::vector<Harvest>harvest_;
	std::string size_ = " Big tree ";
	int Quantity_Harvest_;     //��������� ���-�� ������
	std::string Name_Fruit_ = "Pear";
	std::vector<Harvest>::iterator p = harvest_.begin();
	Harvest* New_Harvest() {
		int Rand_Weight = 0;
		//srand(time(NULL));
		auto f = [&Rand_Weight]() {Rand_Weight = rand() % 30 + 100; };
		f();
		Harvest* tmp = new Harvest(Name_Fruit_, "yellow", Rand_Weight);
		return tmp;
	}

public:
	Pear_tree(int num) { //�����������
		//num = (rand() % 40);
		Quantity_Harvest_ = (rand() % 30);
		/*harvest_.size()= Quantity_Harvest*/
		if (num <= Quantity_Harvest_)
			for (int i = 1; i <= num; i++)
				harvest_.push_back(*New_Harvest());
		else {
			std::cout << "error \n";
			return;
		}
	}
	void Get_size_plant()override {
		std::cout << "Pear_tree: " << size_ << std::endl;
	}
	void Info()const override {
		std::cout << "This Pear_tree:\n"
			<< "   Size tree - " << size_ << "\n"
			<< "Fruit: " << "\n";
		for (auto p : harvest_) {
			std::cout << "   Name: " << p.Get_Name() << "  Color: " << p.Get_Color() << "  Weight: " << p.Get_Weight() << ".gramm" << std::endl;
		}

	}
	void Get_Quantity_Harvest() override { //��������� ���-�� ������
		std::cout << "Quantity_Harvest: " << Quantity_Harvest_ << std::endl;
	}



};

class Raspberries :public Plants
{
private:
	std::vector<Harvest>harvest_;
	std::string size_ = " Midlle tree ";
	int Quantity_Harvest_;     //��������� ���-�� ������
	std::string Name_Fruit_ = "Raspberries";
	std::vector<Harvest>::iterator p = harvest_.begin();
	Harvest* New_Harvest() {
		int Rand_Weight = 0;
		//srand(time(NULL));
		auto f = [&Rand_Weight]() {Rand_Weight = rand() % 3+ 20; };
		f();
		Harvest* tmp = new Harvest(Name_Fruit_, "Red", Rand_Weight);
		return tmp;
	}

public:
	Raspberries(int num) { //�����������
		//num = (rand() % 40);
		Quantity_Harvest_ = (rand() % 80);
		/*harvest_.size()= Quantity_Harvest*/
		if (num <= Quantity_Harvest_)
			for (int i = 1; i <= num; i++)
				harvest_.push_back(*New_Harvest());
		else {
			std::cout << "error \n";
			return;
		}
	}
	void Get_size_plant()override {
		std::cout << "Raspberries: " << size_ << std::endl;
	}
	void Info()const override {
		std::cout << "This Raspberries:\n"
			<< "   Size tree - " << size_ << "\n"
			<< "Fruit: " << "\n";
		for (auto p : harvest_) {
			std::cout << "   Name: " << p.Get_Name() << "  Color: " << p.Get_Color() << "  Weight: " << p.Get_Weight() << ".gramm" << std::endl;
		}

	}
	void Get_Quantity_Harvest() override { //��������� ���-�� ������
		std::cout << "Quantity_Harvest: " << Quantity_Harvest_ << std::endl;
	}


};

void Get_Harvest(int num, Plants* plants) {
	plants->Info();

}

int main() {
	Raspberries ps(16);
	Apple_tree ap(7);
	Pear_tree pt(8);
	Plants* Plants_point;
	Plants_point = &ap;
	Plants_point->Info();
	Plants_point->Get_size_plant();
	Plants_point->Get_Quantity_Harvest();
	std::cout << "\n\n";
	Plants_point = &pt;
	Plants_point->Info();
	Plants_point->Get_size_plant();
	Plants_point->Get_Quantity_Harvest();
	std::cout << "\n\n";
	Plants_point = &ps;
	Plants_point->Info();
	Plants_point->Get_size_plant();
	Plants_point->Get_Quantity_Harvest();
	std::cout << "\n\n";
	Plants_point = &ap;
	Get_Harvest(3, Plants_point);         //  ??????????


	//ap.Info();
	//std::sort(harvest_.begin(), harvest_.end(),
	//	[](const Runner& a, const Runner& b)->bool {
	//		return a.Name < b.Name;
	//	}
	//);


	_getch();
	return 0;
}
