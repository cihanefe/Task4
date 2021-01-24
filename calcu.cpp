#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
    char v[10];
    int isaret, n, i, rem, y, a = 1;
    int sonuc, sayi, aux, x, u, c;
    while (1)
	//heheh
    {
        cout << "islemi giriniz: " << endl;
        scanf("%s", v); //5+3*2-4 þeklinde bitiþik giriniz!
        n = strlen(v);
        sonuc = 0, sayi = 0, aux = 0,u = 0, c = 0, a = 1, rem = 0, y = 0;
        isaret = 1, n, i = 0;
        while (i<n)
        {
            while (v[i] >= '0'&&v[i] <= '9')//sayý mý
            {
                sayi = sayi * 10 + (v[i] - '0');
                i++;
            }
            switch (v[i])//iþlem
            {
            case '+': {											//TOPLAMA	

                if (c == 1)//daha önceden çarpma yapýldý mý
                {
                    sonuc += aux*sayi*isaret;// sonuca ekle
                    aux = 0;//aux i sýfýrla
                }
                else if (c == 2)//daha önceden bölme yapýldý mý
                {
                    sonuc += aux / sayi*isaret;
                	aux = 0;
                }
                else if (c == 3)//daha önce üs alýndý mý
                {
                    sonuc += pow (aux, sayi);
                    aux = 0;
				}
                else
                {
                    sonuc += sayi*isaret;
                }
                sayi = 0;
                c = 0;
				isaret = 1;
                break;
            }
            
            case '-': {								// EKSÝ/ÇIKARMA 
                if (c == 1)
                {
                    sonuc += aux*sayi*isaret;
                    aux = 0;
                }
                else if (c == 2)
                {
                    sonuc += aux / sayi*isaret;
                    aux = 0;
                }
                else if (c == 3)
                {
                    sonuc += pow (aux, sayi);
                    aux = 0;
				}
                else
                {
                    sonuc += sayi*isaret;
                }
                c = 0;
                sayi = 0;
                isaret = -1;
                break;
            }
            
            case '*': {								//ÇARPMA
                if (!aux)
                {
                    aux = sayi*isaret; // aux in içinde bölmenin ya da çarpmanýn sonucu var
                }
                else if (c == 2)
                {
                    aux /= sayi*isaret;
                }
                else if (c == 3)
                {
                    aux = pow(aux, sayi);
                }
                else if (u == 2)// üslü ifade yapýldý mý
                {
                	x = pow (x,sayi);
					aux= aux * x;
				}
				else if (u == 1)
                {
                	x = pow (x,sayi);
					aux= aux / x;
				}
                else
                {
                    aux *= sayi*isaret;
                }
                c = 1;
                sayi = 0;
                isaret = 1;
                break;
            }
            case '/': {								//BÖLME 
                if (!aux)
                {
                    aux = sayi*isaret;
                }
                else if (c == 1)
                {
                    aux *= sayi*isaret;
                }
                else if (c == 3)
                {
                    aux = pow(aux, sayi);
                }
                else if (u == 2)
                {
                	x = pow (x,sayi);
					aux= aux * x;
				}
				else if (u == 1)
                {
                	x = pow (x,sayi);
					aux= aux / x;
				}
                else
                {
                    aux /= sayi*isaret;
                }
                c = 2;
                sayi = 0;
                isaret = 1;
                break;
            }
            case '^':{										//ÜSLÜ ÝFADE
            	if (!aux)
				{
					aux = sayi*isaret;
					c = 3;
				}
				else if (c == 1)
				{
					x = sayi*isaret; //önceden çarpma vardý
					u = 2;
					c = 0;
				}
				else if (c == 2)
				{
					x = sayi*isaret; //önceden bölme vardý
					u = 1;
					c = 0;
				}
				else
				{
					aux = pow(aux, sayi);
					c = 0;
				}
				sayi = 0;
				isaret = 1;
				break;
			}
			case '%':{											//MOD ALMA
				if (c == 1)
                {
                    sonuc += aux * sayi * isaret;
                }
                else if (c == 2)
                {
                    sonuc += aux / sayi * isaret;
                }
                else if (c == 3)
				{
					sonuc += pow (aux, sayi);
				}
                else if (u == 2)
				{
					x = pow (x,sayi);
					sonuc += aux * x;
				}
				else if (u == 1)
				{
					x = pow (x,sayi);
					sonuc += aux / x;
				}
                else
                {
                    sonuc += sayi*isaret;
                }
				c = 4;
				sayi = 0;
				isaret = 1;
				break;
			}
			case 'B' :{											//Base alma
				if (c == 1)
                {
                    sonuc += aux * sayi * isaret;
                }
                else if (c == 2)
                {
                    sonuc += aux / sayi * isaret;
                }
                else if (c == 3)
				{
					sonuc += pow (aux, sayi);
				}
                else if (u == 2)
				{
					x = pow (x,sayi);
					sonuc += aux * x;
				}
				else if (u == 1)
				{
					x = pow (x,sayi);
					sonuc += aux / x;
				}
                else
                {
                    sonuc += sayi*isaret;
                }
				c = 5;
				sayi = 0;
				isaret = 1;
				i=i+3;
				break;
			}
            
            default:;
            }
            if (i >= (n - 1))// en sonda sonucu güncelle
            {
                if (c == 1)
                {
                    sonuc += aux * sayi * isaret;
                }
                else if (c == 2)
                {
                    sonuc += aux / sayi * isaret;
                }
                else if (c == 3)
				{
					sonuc += pow (aux, sayi);
				}
				else if (c == 4)
				{
					sonuc = sonuc % sayi;
				}
				else if (c == 5)
				{
					while (sonuc != 0){
						rem = sonuc % sayi;
						sonuc = sonuc / sayi;
						y = rem * a + y;
						a *= 10;
					}
					sonuc = y;
				}
                else if (u == 2)
				{
					x = pow (x,sayi);
					sonuc += aux * x;
				}
				else if (u == 1)
				{
					x = pow (x,sayi);
					sonuc += aux / x;
				}
                else
                {
                    sonuc += sayi*isaret;
                }
            }
            i++;
        }
        cout << "=" << sonuc << endl;
        system("pause");
        system("cls");
    }

}
