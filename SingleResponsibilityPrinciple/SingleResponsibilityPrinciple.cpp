#include "FileWriter.h"
#include "Management.h"
#include "Employee.h"

int main()
{
    Employee e1(0, "Ivan", 5000);
    Employee e2(1, "Maria", 5000);

    Management management;
    management.AddEmployee(e1);
    management.AddEmployee(e2);

    FileWriter file;
    file.SaveToFile(management);
}
