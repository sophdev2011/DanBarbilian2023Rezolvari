#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int digit, interval, no_zerouri, count_interval, counter, no_digits, count_aux;
    unsigned long int no, c_no;
    cin >> no >> interval >> no_zerouri;
    c_no = no;
    counter = 0;
    no_digits = 0;

    //Determinam numarul de cifre ale numarului citit, pentru a putea sa il parcurgem pe acesta de la stanga la dreapta
    while(no>0)
    {
        digit = no%10;
        no_digits++;
        no = no/10;
    }
    no = c_no;

    // parcurcem numarul citit de la stanga la dreapta(de la ordinul cel mai mare la ordinul cel mai mic)
    while(no_digits > 0)
    {
        no_digits--;
        digit = no/pow(10, no_digits);
        no = fmod(no,pow(10, no_digits));

        //afisam fiecare cifra
        cout << digit;
        count_interval++;
        counter ++;

        //conditia ca sa inseram zerouri intre cifrele numarului
        //   (1) sa ne aflam in intervalul de inserare dorit
        //   (2) nu inseram dupa ultima cifra a numarului
        //   (3) cifra curenta sa nu fie zero
        if(count_interval == interval && no_digits >=1 && digit !=0)
        {
            // determinam cate zerouri trebuie sa inseram
            count_aux=0;
            while(count_aux<no_zerouri)
            {
                cout << 0;
                count_aux++;
            }
            count_interval = 0;
        }
    }
    return 0;
}
