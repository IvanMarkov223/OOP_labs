#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int maxlen = 255;

#pragma pack(push, 1)
struct sworker {
    char fio[maxlen];
    char specialty[maxlen];
    int workExperience;
    int phoneNumber;
    int age;
};
#pragma pack(pop)

sworker arr[maxlen];
int workerIndex = 0;

int menu();
void readFromFile(const char* fileName);
void saveToFile(const char* fileName);
void addNew();
void del();

int main()
{
    while (1) {
        switch (menu()) {
        case 1:
            readFromFile("file.dat");
            break;
        case 2:
            saveToFile("file.dat");
            break;
        case 3:
            addNew();
            break;
        case 4:
            del();
            break;
        case 5:
            return 0;
        default:
            cout << "Wrong choice" << endl;
        }
    }
}

int menu()
{
    cout << "\n";
    int ans;
    cout << "Choose\n";
    cout << "1 - for reading from a file\n";
    cout << "2 - for writing to a file\n";
    cout << "3 - to add to the file\n";
    cout << "4 - to delete an entry from the file\n";
    cout << "5 - for exit\n";
    cout << "\n";
    cout << "your choice  ";
    cin >> ans;
    return ans;
}

void saveToFile(const char* fileName)
{
    ofstream f;
    f.open(fileName, ios::binary);
    f.write((char*)arr, sizeof(sworker) * workerIndex);
    f.close();
    cout << "The entered data is saved to a file\n";
}

void readFromFile(const char* fileName)
{
    ifstream f;
    f.open(fileName, ios::binary);
    if (!f) {
        cout << "File does not exist";
    }
    else {
        sworker worker;
        workerIndex = 0;
        while (1) {
            f.read((char*)&worker, sizeof(worker));
            if (f.eof())
                break;
            arr[workerIndex] = worker;
            workerIndex++;
        }
        f.close();
        cout << "Data has been read from file\n";
        for (int i = 0; i < workerIndex; i++) {
            cout << arr[i].fio << "\t" << arr[i].age << "\t" << arr[i].specialty << "\t" << arr[i].phoneNumber << "\t";

            cout << endl;
        }
    }
}

void addNew()
{
    cout << "Adding a new file record\n\n";
    cout << "Record number " << workerIndex + 1 << "\n";
    cin.ignore();
    cout << "Enter surname, name, and father's name ";
    cin.getline(arr[workerIndex].fio, maxlen);

    cout << "Enter specialty  ";
    cin.getline(arr[workerIndex].specialty, maxlen);

    cout << "Enter work experience (years) ";
    cin >> arr[workerIndex].workExperience;

    cout << "Enter phone number ";
    cin >> arr[workerIndex].phoneNumber;

    cout << "Enter age ";
    cin >> arr[workerIndex].age;

    workerIndex++;

    cout << "\nAdded record:\n";
    cout << "\t" << workerIndex << "\t " << arr[workerIndex - 1].fio << "\t" << arr[workerIndex - 1].age << "\t" << arr[workerIndex - 1].specialty << "\t" << arr[workerIndex - 1].phoneNumber << "\t";

    cout << endl;
}


void del()
{
    int d;
    cout << "Choose number of record than needs to be deleted ";
    cin >> d;
    for (int i = d - 1; i < workerIndex; i++)
    {
        arr[i] = arr[i + 1];
    }
    workerIndex--;

    cout << "\n";
    for (int i = 0; i < workerIndex; i++) {
        cout << i + 1 << "\t" << arr[i].fio << "\t" << arr[i].age << endl;
    }
    cout << "\n";
}
