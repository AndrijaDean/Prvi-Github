#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct Ucenik
{
    char imePrezime[50];
    float prosjek;
};
bool cmpp(Ucenik &a, Ucenik &b)
{
    return a.prosjek > b.prosjek;
}

int main()
{
    struct Ucenik ucenici[100];
    int brUcenika = 0;
    fstream datoteka("C:/Users/Ga-gama/Documents/GitHub/Prvi-Github/data.bin", ios::binary | ios::in);
    while (datoteka.read((char *)&ucenici[brUcenika], sizeof(Ucenik)))
    {
        cout << ucenici[brUcenika].imePrezime << " " << ucenici[brUcenika].prosjek << endl;
        brUcenika++;
    }

    datoteka.close();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin.ignore();
        cin.getline(ucenici[brUcenika + i].imePrezime, 50);
        cin >> ucenici[brUcenika + i].prosjek;
    }
    sort(ucenici, ucenici + brUcenika + n, cmpp);
    fstream datoteka1("C:/Users/Ga-gama/Documents/GitHub/Prvi-Github/data.bin", ios::binary | ios::out | ios::trunc);
    datoteka1.write((char *)ucenici, sizeof(Ucenik) * (brUcenika + n));
    datoteka1.close();
    return 0;
}