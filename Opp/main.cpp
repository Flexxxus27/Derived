#include <iostream>
#include <string>

// Наследование - это механизм расширения функционала класса путем
// сужения его специализации, при котором открывается дорога для полиморфизма  


class Base {
public:
	Base():Base(0,0,0){}
	Base(int a, int b , int c):a(a),b(b),c(c){ }


	int a;
	int A() { return a; }
	int B() { return b; }
	int C() { return c; }

protected:
	int b;
private:
	int c;
}; 

// Публичное наследование - позволяет пользоваться в нутри класса наследника
//полями прайвет и протектед род. кл., так как будто они являются его полями прайвет и протект. 

class Derived:public Base{
public:

	Derived() = default;
	Derived(int a, int b, int c, int d):Base(a,b,c),d(d) {}

	int M00() {
		int res{};
		res = a + b; //свободно используем публичные и защищенные поля. 
		res /= C(); //приватные поля  доступны через методы доступа внутри класса. 
		return res;
	}
	int D() { return d; }
private: 
	int d;
};

class Animal {
public:
	int Age()const { return age_; }
	void Age(int newAge) { age_ = newAge; }

	void Name(std::string newName) { name_ = newName; }
	std::string Name()const { return name_; }

	//виртуал помечают функцию которая должна вызываться у наследников в момент их обработки под видом родителя
	 virtual void Say()const {
		std::cout << "r.\n";
	}

private:
	std::string name_;
	int age_;
};

class Kat :public Animal {
public:
	void Say()const override { // override - доп проверка, что все написано правильно.
		std::cout << "Meow.\n";
	}


};



int main() {
	setlocale(0, "");
	
	Base obj(1,2,5);

	obj.a;
	//obj.b;
	//obj.c;

	Derived dObj(1,2,3,5);
	dObj.B();

	Animal abs;
	abs.Name("Dog");
	abs.Age(1);
	abs.Say();

	Kat kat;
	kat.Name("Fluffy");
	kat.Age(3);
	kat.Say(); // по умолчанию вызовет свою реализацию
	kat.Animal::Say(); // принудительно вызвали реализацию родителя 
	Animal* p = &abs;
	p = &kat;
	p->Say();

	return 0;
}