#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Ucenik
{
    char imePrezime[30];
    float prosjek;
};

int main()
{
    Ucenik ucenici[100];
    int brUcenika = 0;
    fstream imenik("C:/Users/Ga-gama/Documents/AiP2/dokument.txt", ios::binary | ios::in);
    while (imenik.read((char *)&ucenici[brUcenika], sizeof(Ucenik)))
    {
        cout << ucenici[brUcenika].imePrezime << " " << ucenici[brUcenika].prosjek << endl;
        brUcenika++;
    }
    // komentar
    imenik.close();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin.getline(ucenici[brUcenika + i].imePrezime, 30);
        cin >> ucenici[brUcenika + i].prosjek;
    }
    // sort
    /*
    imenik.open("C:/Users/Ga-gama/Documents/AiP2/dokument.txt", ios::binary | ios::out | ios::app);
    imenik.write((char *)&ucenik, sizeof(Ucenik));
    imenik.close();
    */
    return 0;
}