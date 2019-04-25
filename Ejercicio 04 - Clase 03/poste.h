#pragma once

class Poste
{    
public:
    Poste(int altura=10) : altura(altura) {}

private:
    int altura;

public:
    Poste operator+ (Poste otro);
    Poste operator+ (int altura);
    Poste operator++(int);
    int getAltura() const { return this->altura; }
    void setAltura(int altura) { this->altura = altura; }

};

Poste Poste::operator+(Poste otro)
{
    Poste res;
    res.setAltura(this->getAltura() + otro.getAltura());
    return res;
}

Poste Poste::operator+(int altura)
{
    Poste res;
    res.setAltura(this->getAltura() + altura);
    return res;
}

Poste Poste::operator++(int)
{
    this->setAltura(this->getAltura()*2);
    return *this;
}


