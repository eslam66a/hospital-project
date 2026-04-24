#include <bits/stdc++.h>
using namespace std;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
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
            cout << "There are " << count[i] << " patients in specialization " << i << endl;
            for (int j = 0; j <= count[i]; j++)
            {
                cout << PatientsData[i][j] << endl;
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
        cout << "No Patients in specialization " << HisSpec << endl;
    else
    {
        cout << "Mr " << GetName(PatientsData[HisSpec][1]) << " Please go with the Dr" << endl;
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
                cout << PatientsData[i][j] << endl;
                break;
            }
        }
    }
}

int main()
{
    fastIO();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int choice;
    Patient ThePatient;
    int count[21] = {};
    while (true)
    {
        cout << "Enter Your Choice:" << endl
             << "1) Add New Patient" << endl
             << "2) Print All Patients" << endl
             << "3) Get Next Patient" << endl
             << "4) Print Specific Patients" << endl
             << "5) Exit" << endl;

        while (true)
        {
            cin >> choice;
            if (choice <= 5 and choice >= 1)
                break;
            else
                cout << "Enter Correct Choice!: " << endl;
        }

        if (choice == 1)
        {
            cout << "Enter specialization , name and his statis:  " << endl;
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
                        cout << "Status is out of the range [1,0] and Specialization is out of the range [1,20]" << endl
                             << "Please enter correct specialization and correct status:  " << endl;
                    }
                    else
                    {
                        if (ThePatient.statis < 0 or ThePatient.statis > 1)
                        {
                            cout << "Status is out of the range [1,0]!" << endl
                                 << "Please enter correct inputs:  " << endl;
                        }
                        else
                        {
                            cout << "Specialization is out of the range [1,20]!" << endl
                                 << "Please enter correct inputs:  " << endl;
                        }
                    }
                }
            }
            if (!AddPatient(ThePatient.specialization, ThePatient.name, ThePatient.statis, count))
            {
                cout << "This Specialization is full!!" << endl
                     << "Please enter another Specialization: " << endl
                     << endl;
            }
        }

        else if (choice == 2)
            PrintAllPatients(count);
        else if (choice == 3)
        {
            int spec;
            cout << "Enter specialization: " << endl;
            while (true)
            {
                cin >> spec;
                if (spec >= 1 and spec <= 20)
                    break;
                else
                    cout << "Enter correct specialization to get the next patient: " << endl;
            }
            GetNextPatients(spec, count);
        }

        else if (choice == 4)
        {
            string PatientName;
            cout << "Enter patient name: " << endl;
            cin >> PatientName;
            PrintOnePatient(PatientName, count);
        }
        else
            return 0;
    }
}