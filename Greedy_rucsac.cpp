/**Problema rucsacului (cazul continuu)
O persoana are un rucsac cu care
poate transporta o greutate maxima g.
Persoana are la dispozitie n obiecte
pentru care stie greutatea si castigul
obtinut daca transporta obiectul.
Fiecare obiect poate fi transportat
integral sau taiat.
Sa se precizeze ce obiecte alege
persoana si in ce proportie le ia
astfel incat castigul total sa fie maxim
si sa nu se depaseasca greutatea maxima a rucsacului.
Exemplu:
g=3 n=3
obiectele(greutate,castig):
2 2
1 4
3 6
Solutie(greutate, castig, raport taiere):
1,4,1
3,6,0.6667 (al doilea obiect se ia in raport de 2/3)
castig maxim=8 */
#include<fstream>

using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");

struct obiect
{
    float g,c,r;///greutate, castig, raportul cat se ia din obiect
}a[101];
float g;
int n,k;
void citire()
{
    fin>>g>>n;
    for(int i=1;i<=n;i++)
        { fin>>a[i].g>>a[i].c;
          a[i].r=0;///initial nu se foloseste obiectul
        }
}

void ordonare()///ordonare dupa castig/greutate
{
    int i,j;
    obiect aux;
    for(i=1;i<n;i++)
        for(j=i+1;j<=n;j++)
            if(a[i].c/a[i].g<a[j].c/a[j].g)
            {
                aux=a[i]; a[i]=a[j]; a[j]=aux;
            }
}

void afisare(int n, obiect a[101])
{
    float c=0;
    for(int i=1;i<=n;i++)
        { fout<<a[i].g<<" , "<<a[i].c<<" , "<<a[i].r<<"\n";
          c=c+a[i].c*a[i].r;
        }
    fout<<"castig maxim="<<c;
}

void greedy()
{
    obiect s[101];
    int i,k;
    float sp=0;
    k=0; i=1;
    while(sp<g)
    {
        if(sp+a[i].g<=g)
        { sp=sp+a[i].g;
          s[++k]=a[i];
          s[k].r=1;///obiect intreg
        }
        else
        {
          s[++k]=a[i];
          s[k].r=(g-sp)/a[i].g;///obiect fractionat
          sp=g;
        }
        i++;
    }
    afisare(k,s);
}

int main()
{

    obiect a[100];

    citire();
    ordonare();
    greedy();
    fin.close();
    fout.close();

    return 0;
}
