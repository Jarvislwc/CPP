/*
基本類別設計：
>   題目說明： 建立一個表示「傳感器」的 Sensor 類別，該類別需包含以下屬性：
    >   type：傳感器的類型（例如溫度、濕度）。
    >   id：傳感器的唯一識別碼。
    >   unit：傳感器的單位（例如 °C、%）。
>   要求： 使用封裝將這些屬性設為私有，並提供相應的 getter 和 setter 方法，讓外部程式可以訪問和修改這些屬性。
>   目標： 學習物件屬性與封裝概念。
*/
#include <iostream>
#include <string>
using namespace std;

class Sensor
{
private:
    string type;
    int id;
    string unit;

public:
    Sensor(const std::string &type, int id, const std::string &unit)
        : type(type), id(id), unit(unit) {}
    void GetType();
    void SetType(string typeinfo);
    void GetID();
    void SetID(int idnumber);
    void GetUnit();
    void SetUnit(string unitinfo);
};

void Sensor::GetType()
{
    cout << "Your type is : " << type << endl;
}

void Sensor::SetType(string typeinfo)
{
    this->type = typeinfo;
    cout << "New type is " << this->type << endl;
}

void Sensor::GetID()
{
    cout << "Your ID is : " << id << endl;
}

void Sensor::SetID(int idnumber)
{
    this->id = idnumber;
    cout << "New id is " << this->id << endl;
}

void Sensor ::GetUnit()
{
    cout << "Unit is : " << unit << endl;
}
void Sensor ::SetUnit(string unitinfo)
{
    this->unit = unitinfo;
    cout << "New Unit is " << this->unit << endl;
}
int main()
{
    Sensor tempSensor("temperature", 101, "%");
    tempSensor.GetID();
    tempSensor.GetUnit();
    tempSensor.GetType();
    tempSensor.SetID(104);
    tempSensor.SetType("Holiday");
    tempSensor.SetUnit("CC");
    tempSensor.GetID();
    tempSensor.GetUnit();
    tempSensor.GetType();
}
