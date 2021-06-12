/******************************************************************************
������� ����� ��������� 4 �������. ���������� � ��� �����������, ����������, �����������
�����������. ����������� �������� �+�,�-�,�+=�,�-=�,�*�,�/�,�=�(��������� � ������� ���
������������ �����).����������� �������� ����� � ������. �������� ��������� ������������,
������� �������� ������������ ����������� �������������� �������� (+,-) � ��������� ������� ������.

******************************************************************************/

#include <stdio.h>
#include <iostream>

using namespace std;

class Polinom {
private:
    double a, b, c, d, e; //������������ �������� 4-� �������
public:
    Polinom(double na = 0.0, double nb = 0.0, double nc = 0.0, double nd = 0.0, double ne = 0.0) : a(na), b(nb), c(nc), d(nd), e(ne) {} //�����������
    ~Polinom();  //����������
    Polinom(const Polinom& p); //����������� �����������
    Polinom operator-(const Polinom& t);
    Polinom operator+(const Polinom& t);
    friend Polinom operator*(const Polinom& t, double d);
    friend Polinom operator/(const Polinom& t, double d);
    friend Polinom operator+=(const Polinom& t, double d);
    friend Polinom operator-=(const Polinom& t, double d);
    Polinom operator=(const Polinom& p) { a = p.a; b = p.b; c = p.c; d = p.d; e = p.e; return *this; }
    friend ostream& operator<< (std::ostream& out, const Polinom& p);
    friend istream& operator>> (std::istream& in, Polinom& p);
};

Polinom::~Polinom()
{

} 

Polinom::Polinom(const Polinom& p)
{
    a = p.a;
    b = p.b;
    c = p.c;
    d = p.d;
    e = p.e;
}

Polinom Polinom::operator-(const Polinom& p)
{
    Polinom tmp = *this;
    tmp.a = a - p.a;
    tmp.b = b - p.b;
    tmp.c = c - p.c;
    tmp.d = d - p.d;
    tmp.e = e - p.e;
    return tmp;
}

Polinom Polinom::operator+(const Polinom& p)
{
    Polinom tmp = *this;
    tmp.a = a + p.a;
    tmp.b = b + p.b;
    tmp.c = c + p.c;
    tmp.d = d + p.d;
    tmp.e = e + p.e;
    return tmp;
}

Polinom operator*(const Polinom& t, double d)
{
    Polinom tmp;
    tmp.a = t.a * d;
    tmp.b = t.b * d;
    tmp.c = t.c * d;
    tmp.d = t.d * d;
    tmp.e = t.e * d;
    return tmp;
}

Polinom operator/(const Polinom& t, double d)
{
    Polinom tmp;
    tmp.a = t.a / d;
    tmp.b = t.b / d;
    tmp.c = t.c / d;
    tmp.d = t.d / d;
    tmp.e = t.e / d;
    return tmp;
}

Polinom operator+=(const Polinom& t, double d)
{
    Polinom tmp;
    tmp.a = t.a + d;
    tmp.b = t.b + d;
    tmp.c = t.c + d;
    tmp.d = t.d + d;
    tmp.e = t.e + d;
    return tmp;
}

Polinom operator-=(const Polinom& t, double d)
{
    Polinom tmp;
    tmp.a = t.a - d;
    tmp.b = t.b - d;
    tmp.c = t.c - d;
    tmp.d = t.d - d;
    tmp.e = t.e - d;
    return tmp;
}

std::ostream& operator<< (std::ostream& out, const Polinom& p)
{
    if ((p.a == 0) || (p.b == 0)) { std::cerr << "Error b"; }
    else
    {
        out << p.a << "X^4";
        if (p.b > 0) out << "+";
        out << p.b << "X^3";
        
        if (p.c != 0)
        {
            if (p.c > 0) out << "+";
            out << p.c << "X^2";
        }
       
        if (p.d > 0) out << "+";
        if (p.d == 0) { out << "X"; }
        else out << p.d << "X";

        if (p.e != 0)
        {
            if (p.e > 0) 
            { 
                out << "+";
            }
            out << p.e;
        } 
        
         
    }
    return out;
}

std::istream& operator>> (std::istream& in, Polinom& p)
{
    std::cout << "����������� ��� �^4 (����� ����� �� ������ 0):";
    in >> p.a;
    if (!in) std::cerr << "Error a";
    std::cout << "����������� ��� �^3 (����� ����� �� ������ 0):";
    in >> p.b;
    if (!in) std::cerr << "Error b";
    std::cout << "����������� ��� �^2 (����� �����):";
    in >> p.c;
    if (!in) std::cerr << "Error c";
    std::cout << "����������� ��� � (����� �����):";
    in >> p.d;
    if (!in) std::cerr << "Error d";
    std::cout << "����� �����:";
    in >> p.e;
    if (!in) std::cerr << "Error e";
    return in;
}

void main()
{
    char op;
    Polinom A, B, C;
    setlocale(LC_CTYPE, "rus");
    std::cout << "����������� ��� ��������� 4-� �������: \n" << endl << flush;
    std::cout << "������� ������������ 1-�� ��������: \n" << endl << flush;
    std::cin >> A;
    std::cout << A << '\n';
    std::cout << "������� ������������ 2-�� ��������: \n" << endl << flush;
    std::cin >> B;
    std::cout << B << '\n';
    cout << "������� ��������: " << endl << flush;
    cin >> op;
    cout << "�������: \n";

    switch (op)
    {
        case'+': C = A + B; break;
        case'-': C = A - B; break;      
        default:cerr << "Error!" << flush;
            return; 
    }
    
    cout << A << '\n' << op << '\n' << B << '\n' << "=" << '\n' << C << '\n' << flush;
    system("pause");
}
