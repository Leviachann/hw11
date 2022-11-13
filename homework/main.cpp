#include <iostream>
#include <stack>

using namespace std;

class Engine {
public:
  string engineNo = "";
  string company = "";
  double volume = 0;

  Engine() {}

  Engine(string eNo, string comp, double vol)
      : engineNo(eNo), company(comp), volume(vol) {}

  friend ostream &operator<<(ostream &out, const Engine obj) {
    out << "*****Engine***** \nEngine Number: " << obj.engineNo
        << "\nCompany: " << obj.company << "\nVolume: " << obj.volume;
    return out;
  }
};

class Vehicle {
public:
  static int staticId;
  int id;
  string vendor;
  string model;
  Engine engine;

  Vehicle(string vend, string mod, Engine eng) {
    id = staticId++;
    vendor = vend;
    model = mod;
    engine = eng;
  }

  virtual void Show() {
    cout << "Id: " << id << "\nVendor: " << vendor << "\nModel: " << model
         << "\n"
         << engine << endl;
  }
};
int Vehicle::staticId = 789;

class Car : public Vehicle {
public:
  bool hasSpoiler;
  Car(string vend, string mod, Engine eng, bool hasSpoiler)
      : Vehicle(vend, mod, eng) {
    this->hasSpoiler = hasSpoiler;
  }

  void Show() override {
    cout << "*******Car*******\n";

    Vehicle::Show();
    cout << "Spoiler: " << (hasSpoiler ? "var" : "yox") << endl;
  }
};

class Ship : public Vehicle {
public:
  bool hasSail;
  Ship(string vend, string mod, Engine eng, bool hasSail)
      : Vehicle(vend, mod, eng) {
    this->hasSail = hasSail;
  }

  void Show() override {
    cout << "*******Ship*******\n";
    Vehicle::Show();
    cout << "Sail: " << (hasSail ? "var" : "yox") << endl;
  }
};

class Airplane : public Vehicle {
public:
  int passCap, engCount;
  Airplane(string vend, string mod, Engine eng, int passCap, int engCount)
      : Vehicle(vend, mod, eng) {
    this->passCap = passCap;
    this->engCount = engCount;
  }

  void Show() override {
    cout << "*******Airplane*******\n";
    Vehicle::Show();
    cout << "Passangers capacity: " << passCap << endl;
    cout << "Engine count: " << engCount << endl;
  }
};

class Garrage {
public:
  stack<Vehicle *> vehicles;

  void ShowAllVehicles() {
    while (!vehicles.empty()) {
      vehicles.top()->Show();
      vehicles.pop();
    }
  }
};

int main() {
  Garrage *garrage = new Garrage();
  garrage->vehicles.push(
      new Car("bmw", "m8", Engine("100", "volvo", 4.4), true));
  garrage->vehicles.push(
      new Ship("yamaha", "2522SD", Engine("256", "Yamaha Marine", 1.8), false));

  garrage->ShowAllVehicles();
  delete garrage;
}