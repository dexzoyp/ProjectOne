#include <iostream>
#include "FileWriter.h"
#include "Management.h"

int main()
{
    Employee e1(0, "Ivan", 5000);
    Employee e2(1, "Maria", 5000);

    Management managment;
    managment.AddEmployee(e1);
    managment.AddEmployee(e2);

    FileWriter file;
    file.SaveToFile(managment);
}
