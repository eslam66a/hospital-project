#include <bits/stdc++.h>
using namespace std;

struct Patient
{
    int specialization;
    string name;
    int statis;
};

string PatientsData[21][6] = {};

bool AddPatient(int HisSpecialization, string HisName, int HisStatis, int count[])
{
    if (count[HisSpecialization] >= 5)
        return false;

    if (HisStatis == 1)
    {
        for (int i = count[HisSpecialization]; i >= 1; i--)
        {
            PatientsData[HisSpecialization][i + 1] = PatientsData[HisSpecialization][i];
        }
        PatientsData[HisSpecialization][1] = HisName + " urgent";
    }
    else
    {
        PatientsData[HisSpecialization][count[HisSpecialization] + 1] = HisName + " regular";
    }
    count[HisSpecialization]++;
    return true;
}

void PrintAllPatients(int count[])
{
    for (int i = 1; i <= 20; i++)
    {
        if (count[i] == 0)
            continue;
        else
        {
            cout << "There are " << count[i] << " patients in specialization " << i << "\n";
            for (int j = 0; j <= count[i]; j++)
            {
                cout << PatientsData[i][j] << "\n";
            }
        }
    }
}

string GetName(string Name)
{
    istringstream iss(Name);
    string name;
    iss >> name;
    return name;
}

void GetNextPatients(int HisSpec, int count[])
{
    if (count[HisSpec] == 0)
        cout << "No Patients in specialization " << HisSpec << "\n";
    else
    {
        cout << "Mr " << GetName(PatientsData[HisSpec][1]) << " Please go with the Dr\n";
        for (int j = 1; j < count[HisSpec]; j++)
        {
            PatientsData[HisSpec][j] = PatientsData[HisSpec][j + 1];
        }
        count[HisSpec]--;
    }
}

void PrintOnePatient(string TheName, int count[])
{
    for (int i = 1; i <= 20; i++)
    {
        for (int j = 1; j <= count[i]; j++)
        {
            if (GetName(PatientsData[i][j]) == TheName)
            {
                cout << PatientsData[i][j] << "\n";
                break;
            }
        }
    }
}

int main()
{
    int choice;
    Patient ThePatient;
    int count[21] = {};
    while (true)
    {
        cout << "Enter Your Choice: \n"
             << "1) Add New Patient\n"
             << "2) Print All Patients\n"
             << "3) Get Next Patient\n"
             << "4) Print Specific Patients\n"
             << "5) Exit\n";

        while (true)
        {
            cin >> choice;
            if (choice <= 5 and choice >= 1)
                break;
            else
                cout << "Enter Correct Choice!: \n";
        }

        if (choice == 1)
        {
            cout << "Enter specialization , name and his statis:  \n";
            while (true)
            {
                cin >> ThePatient.specialization >> ThePatient.name >> ThePatient.statis;
                if ((ThePatient.specialization <= 20 and ThePatient.specialization >= 1) and (ThePatient.statis == 0 or ThePatient.statis == 1))
                {
                    break;
                }
                else
                {
                    if ((ThePatient.specialization > 20 or ThePatient.specialization < 1) and (ThePatient.statis < 0 or ThePatient.statis > 1))
                    {
                        cout << "Status is out of the range [1,0] and Specialization is out of the range [1,20]\n"
                             << "Please enter correct specialization and correct status:  \n";
                    }
                    else
                    {
                        if (ThePatient.statis < 0 or ThePatient.statis > 1)
                        {
                            cout << "Status is out of the range [1,0]!\n"
                                 << "Please enter correct inputs:  \n";
                        }
                        else
                        {
                            cout << "Specialization is out of the range [1,20]!\n"
                                 << "Please enter correct inputs:  \n";
                        }
                    }
                }
            }
            if (!AddPatient(ThePatient.specialization, ThePatient.name, ThePatient.statis, count))
            {
                cout << "This Specialization is full!!\n"
                     << "Please enter another Specialization: \n"
                     << endl;
            }
        }

        else if (choice == 2)
            PrintAllPatients(count);
        else if (choice == 3)
        {
            int spec;
            cout << "Enter specialization: \n";
            while (true)
            {
                cin >> spec;
                if (spec >= 1 and spec <= 20)
                    break;
                else
                    cout << "Enter correct specialization to get the next patient: \n";
            }
            GetNextPatients(spec, count);
        }

        else if (choice == 4)
        {
            string PatientName;
            cout << "Enter patient name: \n";
            cin >> PatientName;
            PrintOnePatient(PatientName, count);
        }
        else
            return 0;
    }
}
