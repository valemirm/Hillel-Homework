#include <iostream>
using namespace std;

// 1. Опишіть клас JetPlane (Реактивний літак), успадковуючи його від двох базових класів – Rocket (Ракета) та Airplane (Літак).

class Rocket
{
public:
    Rocket() : numberOfEngines(5) {}
    virtual ~Rocket() {}
    virtual void SuperSpeed() const { cout << "Rocket can travel at supersonic speed using " << numberOfEngines << " rocket engines!\n"; } // за рахунок ракетного двигуна
    unsigned short GetEngines() const { return numberOfEngines; }
    void SetEngines(unsigned short engineNum) { numberOfEngines = engineNum; }

protected:
    unsigned short numberOfEngines;
};

class Airplane
{
public:
    Airplane() : numberOfWings(2) {}
    virtual ~Airplane() {}
    virtual void Wings() const { cout << "Airplane has " << numberOfWings << " lift wings to carry itself!\n"; }
    unsigned short GetWings() const { return numberOfWings; }

protected:
    const unsigned short numberOfWings;
};

class JetPlane : public Rocket, public Airplane
{
public:
    JetPlane() {}
    JetPlane(unsigned short engineNum) { numberOfEngines = engineNum; };
    virtual ~JetPlane() {}
    virtual void SuperSpeed() const { cout << "Jet plane can travel at supersonic speed using " << numberOfEngines << " jet engines!\n"; } // за рахунок реактивного двигуна
    virtual void Wings() const { cout << "Jet plane has " << numberOfWings << " lift wings to carry itself!\n"; }

};

// 2. Виконайте від класу JetPlane, оголошеного в першій вправі, новий клас Boeing747.

class Boeing747 : public JetPlane
{
public:
    Boeing747(unsigned short engineNum) { numberOfEngines = engineNum; }
    virtual ~Boeing747() {}
    virtual void SuperSpeed() const { cout << "Boeing cannot travel at supersonic speed even using " << numberOfEngines << " jet engines!\n"; }
    virtual void Wings() const { cout << "Boeing has " << numberOfWings << " lift wings to carry itself!\n"; }
};

int main()
{
    JetPlane FighterJet(2);
    FighterJet.SuperSpeed();
    FighterJet.Wings();
    cout << "\n\n";
    Boeing747 Boeing(4);
    Boeing.SuperSpeed();
    Boeing.Wings();

    return 0;
}