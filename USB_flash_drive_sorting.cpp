#include <iostream>

using namespace std;

void quick_sort_tab(int* tab, int* tab2, int lewy,  int prawy) {

    if (prawy <= lewy) return;

    int pivot = tab2[(prawy + lewy) / 2];
    int i = lewy - 1;
    int j = prawy + 1;
    int zapas1 = 0;
    int zapas2 = 0;

    while (1)
    {
        while (pivot > tab2[++i]);
        while (pivot < tab2[--j]);
        if (i <= j) {
            zapas2 = tab2[i];
            tab2[i] = tab2[j];
            tab2[j] = zapas2;
            zapas1 = tab[i];
            tab[i] = tab[j];
            tab[j] = zapas1;
        }
        else
            break;
    }
    if (j > lewy)
        quick_sort_tab(tab, tab2, lewy, j);
    if (i < prawy)
        quick_sort_tab(tab, tab2, i, prawy);

}
void quick_sort(int* tab, int lewy,  int prawy) {

    if (prawy <= lewy) return;

     int pivot = tab[(prawy + lewy) / 2];
     int i = lewy - 1;
     int j = prawy + 1;
     int zapas = 0;
     

    while (1)
    {
        while (pivot < tab[++i]);
        while (pivot > tab[--j]);
        if (i <= j) {
            zapas = tab[i];
            tab[i] = tab[j];
            tab[j] = zapas;
        }
        else
            break;
    }
    if (j > lewy)
        quick_sort(tab, lewy, j);
    if (i < prawy)
        quick_sort(tab, i, prawy);

}

int main()
{
    int liczba_wierszy = 0;
    int pamiec_pendriva = 0;

    cin >> liczba_wierszy >> pamiec_pendriva;

    int** tablica = new int* [2];
    tablica[0] = new int[liczba_wierszy];
    tablica[1] = new int[liczba_wierszy];
    int** pendrive = new int* [2];
    pendrive[0] = new int[liczba_wierszy];
    pendrive[1] = new int[liczba_wierszy];
    int* pamiec_wewnetrzena_pendriva = new int[2];
    pamiec_wewnetrzena_pendriva[0] = 0;
    pamiec_wewnetrzena_pendriva[1] = 0;
    int* licznik = new int[2];
    licznik[0] = 0;
    licznik[1] = 0;

    for (int i = 0; i < liczba_wierszy; i++) {
        scanf("%i", &tablica[0][i]);
        scanf("%i", &tablica[1][i]);

    }

    quick_sort_tab(tablica[0], tablica[1], 0, liczba_wierszy - 1);

    for (int i = 0; i < liczba_wierszy; i++) {
        if (pamiec_wewnetrzena_pendriva[1] + tablica[1][i] > pamiec_pendriva)
        {
            break;
        }
        for (int j = 0; j < 2; j++) {
            if (pamiec_wewnetrzena_pendriva[j] + tablica[1][i] <= pamiec_pendriva)
            {
                pendrive[j][licznik[j]] = tablica[0][i];
                pamiec_wewnetrzena_pendriva[j] += tablica[1][i];
                licznik[j]++;
                j++;

            }

        }


    }


    cout << licznik[0] + licznik[1] << endl;

    for (int i = 0; i < 2; i++) {
        quick_sort(pendrive[i], 0, licznik[i] - 1);
    }

    for (int i = 0; i < 2; i++) {
        cout << i + 1 << ": ";
        for (int j = 0; j < licznik[i]; j++) {

            if (j == licznik[i] - 1) cout << pendrive[i][j] << endl;
            else cout << pendrive[i][j] << " ";
        }

    }
    delete[] tablica[0];
    delete[] tablica[1];
    delete[] tablica;
    delete[] pendrive[0];
    delete[] pendrive[1];
    delete[] pendrive;
    delete[] pamiec_wewnetrzena_pendriva;
    delete[] licznik;
    return 0;
}
