#include <iostream>
#include<cstring>
using namespace std;
class Ingredient
{
                char* nume;
                float pret;
                int cantitate;
            public:
                Ingredient();
                Ingredient(char* n, float p, int c);
                Ingredient(const Ingredient&);
                ~Ingredient();
                void citire();
                void afisare() const;
                friend ostream& operator<<(ostream&, Ingredient&);
                friend istream& operator>>(istream&, Ingredient&);
                Ingredient& operator=(const Ingredient&);
                const Ingredient operator+(int);
                Ingredient operator+=(int);
};
class Pizza
{
            char* denumire;
            int nringrediente;
            Ingredient *Ingr;
    public:
            Pizza();
            Pizza(char s[50]);
            ~Pizza();
            void citire();
            void afisare()const;
            Pizza& operator=(const Pizza&);
            friend const Pizza operator+(const Ingredient&,const Pizza&);
            friend istream& operator>>(istream&, Pizza&);
            friend ostream& operator<<(ostream&, Pizza&);
            friend int operator>(Pizza&, Pizza&);
            friend int operator<(Pizza&, Pizza&);
            };
int main()
{Ingredient i1("Piper" , 0.5 , 10), i2("Nimic" ,0.0 , 0);
cout<<i1<<i2;
cin>>i2;
i1+=500;
cout<<i1;
Ingredient i3=i1,i4,i5(i1);
i4=i1;
Pizza pizza1("Clasic"), pizza2;
cout<<pizza1;
pizza1=i1+pizza1;
cin>>pizza2;
cout<<pizza1<<pizza2;
if(pizza1>pizza2)cout<<"pizza1 are mai multe ingrediente decat pizza2";
    else if(pizza1<pizza2)cout<<"pizza2 are mai multe ingrediente decat pizza1";
            else cout<<"pizza1 si pizza2 au la fel de multe ingrediente";
}
Ingredient::Ingredient()
{
    nume=NULL;
    pret=0.0;
    cantitate=0;
}

Ingredient::Ingredient(char* n, float p, int c)
{
    nume= new char[255];
    strcpy(nume,n);
    pret=p;
    cantitate=c;
}
Ingredient::~Ingredient()
{
    delete[] nume;
    pret = 0;
    cantitate = 0;
}

Ingredient::Ingredient(const Ingredient& ob)
{
    nume = new char[strlen(ob.nume) + 1];
    strcpy(nume,ob.nume);
    pret=ob.pret;
    cantitate=ob.cantitate;

}
void Ingredient::citire()
{
    nume=new char[255];
    cout<<"Ingredient:";
    cin>>nume;
    cout<<"Pret:";
    cin>>pret;
    cout<<"Cantitate:";
    cin>>cantitate;
    cout<<endl;
}
void Ingredient::afisare() const
{
    cout<<"Ingredient:"<<nume<<endl;
    cout<<"Pret:"<<pret<<endl;
    cout<<"Cantitate:"<<cantitate<<endl;
    cout<<endl;

}
ostream& operator<<(ostream& out, Ingredient& ob)
{
    out<<"Ingredient:"<<ob.nume<<endl;
    out<<"Pret:"<<ob.pret<<endl;
    out<<"Cantitate:"<<ob.cantitate<<endl;
    out<<endl;
    return out;
}
istream& operator>>(istream& in, Ingredient& ob)
{
    ob.nume=new char[255];
    cout<<"Ingredient:";
    in>>ob.nume;
    cout<<"Pret:";
    in>>ob.pret;
    cout<<"Cantitate:";
    in>>ob.cantitate;
    cout<<endl;
    return in;
}
Ingredient Ingredient::operator+=(int x)
{
    cantitate += x;
    return *this;
}
const Ingredient Ingredient::operator+(int x)
{
    Ingredient ob(*this);
    ob.cantitate = ob.cantitate + x;
    return ob;
}
Ingredient& Ingredient::operator=(const Ingredient& ob)
{
    if (this != &ob)
    {
        nume = new char[strlen(ob.nume) + 1];
        strcpy(nume, ob.nume);
        pret=ob.pret;
        cantitate=ob.cantitate;
    }
    return *this;
}
Pizza::Pizza()
{
    denumire="";
    nringrediente=0;
    Ingr=new Ingredient[100];
}
Pizza::Pizza(char s[50])
{
    denumire=s;
    nringrediente=0;
    Ingr=new Ingredient[100];
}
Pizza::~Pizza()
{
    if(denumire!=NULL)
        delete[] denumire;
    if(Ingr!=NULL)
        delete[] Ingr;
    denumire=NULL;
    Ingr=NULL;
    if(nringrediente!=0)nringrediente=0;
}
Pizza& Pizza::operator=(const Pizza& ob)
{
    this->denumire=ob.denumire;
    this->nringrediente=ob.nringrediente;
    for(int i=0;i<nringrediente;i++)
        this->Ingr[i]=ob.Ingr[i];
    return *this;
}
const Pizza operator+(const Ingredient& i,const Pizza& ob)
{
    Pizza p;
    p.denumire=new char[255];
    strcpy(p.denumire,ob.denumire);
    p.nringrediente=ob.nringrediente+1;
    p.Ingr=new Ingredient[100];
    for(int j=0;j<ob.nringrediente-1;j++)
        p.Ingr[j]=ob.Ingr[j];
    p.Ingr[ob.nringrediente]=i;
    return p;
}
istream& operator>>(istream& in, Pizza& p)
{
    p.denumire=new char[255];
    cout<<"Pizza ";
    in>>p.denumire;
    cout<<"Numarul de ingrediente:";
    in>>p.nringrediente;
    cout<<"Ingredientele:"<<endl;
    p.Ingr=new Ingredient[100];
    for(int i=0;i<p.nringrediente;i++)
        in>>p.Ingr[i];
    return in;
}
ostream& operator<<(ostream& out, Pizza& p)
{
    out<<"Pizza "<<p.denumire<<" contine "<<p.nringrediente<<" ingrediente:"<<endl;
    cout<<endl;
    for(int i=0;i<p.nringrediente;i++)
        out<<p.Ingr[i]<<endl;
    out<<endl;
    return out;
}
 int operator>(Pizza& X, Pizza& Y)
 {
     return X.nringrediente>Y.nringrediente;
 }
  int operator<(Pizza& X, Pizza& Y)
 {
     return X.nringrediente<Y.nringrediente;
 }
void Pizza::citire()
{
    denumire=new char[255];
    cout<<"Pizza ";
    cin>>denumire;
    cout<<"Numarul de ingrediente:";
    cin>>nringrediente;
    cout<<"Ingredientele:"<<endl;
    Ingr=new Ingredient[100];
    for(int i=0;i<nringrediente;i++)
        cin>>Ingr[i];
}
void Pizza::afisare() const
{
    cout<<"Pizza "<<denumire<<" contine "<<nringrediente<<" ingrediente:"<<endl;
    cout<<endl;
    for(int i=0;i<nringrediente;i++)
        cout<<Ingr[i]<<endl;
    cout<<endl;
}
