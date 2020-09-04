// James Montis
//

#ifndef MONTISJ_MEASURE_H
#define MONTISJ_MEASURE_H
#include <iostream>
using namespace std;

class Measure {
private:
    int yards;
    int feet;
    int inches;
public:
    Measure(int yds, int ft, int in){
        yards = yds;
        feet = ft;
        inches = in;
    }

    Measure(){
        yards = 0;
        feet = 0;
        inches = 0;
    }
    void setYards(int y){ yards = y;}
    void setFeet(int f) { feet = f;}
    void setInch(int i) { inches = i;}
    const int getYards() { return yards ;}
    const int getFeet() {return feet;}
    int getInch() {return inches;}
    void simplify();
    Measure operator+(const Measure&);
    Measure operator-(const Measure&);
    bool operator<(const Measure&);
    bool operator>(const Measure&);
    bool operator!=(const Measure&);
    bool operator==(const Measure&);
    const Measure operator=(const Measure&right);
    friend ostream &operator<<(ostream &strm, const Measure &);
    friend istream& operator>>(istream& is, Measure& right);

    Measure &operator+=(const Measure &);
    Measure &operator+=(const int&);
};

void Measure::simplify() {

    if (inches >=12){
        feet+=(inches/12);
        inches=inches%12;
    } else if (inches < 0){
        feet-=((abs(inches)/12)+1);
        inches=12-(abs(inches) % 12);
    }

    if (feet>=3){
        yards+=(feet/3);
        feet=feet%3;
    } else if (feet<0) {
        yards-=((abs(feet)/3)+1);
        feet=3-(abs(feet)%3);
    }
}

Measure Measure::operator+(const Measure &right){
    Measure temp;
    temp.yards=yards+right.yards;
    temp.inches=inches+right.inches;
    temp.feet=feet+right.feet;
    temp.simplify();
    return temp;
}

Measure Measure::operator-(const Measure&right){
    Measure temp;
    temp.yards=yards-right.yards;
    temp.inches=inches - right.inches;
    temp.feet=feet - right.feet;
    temp.simplify();
    return temp;
}

const Measure Measure::operator=(const Measure&right){
    if (this != &right)
    {
        yards = right.yards;
        feet = right.feet;
        inches = right.inches;
    }
    return *this;
}

bool Measure::operator<(const Measure&right){
    bool status;
    if (yards < right.yards){
        status = true;
    } else if ( feet == right.feet && inches < right.inches){
    status = true;
} else {
        status = false;
    }
    return status;
}

bool Measure::operator>(const Measure&right){
    bool status;
    if (yards > right.yards){
        status = true;
    } else if (feet == right.feet && inches < right.inches){
            status = true;
        } else {
        status = false;
    }
    return status;
}

bool Measure::operator==(const Measure&right){
    return (yards==right.yards && feet == right.feet && inches == right.inches) ? true : false;
}

ostream &operator << (ostream &strm, const Measure&obj){
    strm << obj.yards << " yards, " << obj.feet << " feet, " << obj.inches << " inches ";
    return strm;
}

istream& operator>>(istream& is, Measure& right){
    is>> right.yards >> right.feet>>right.inches;
    return is;
}


Measure &Measure::operator+=(const Measure &right){
    yards+=right.yards;
    feet=right.feet;
    inches+=right.inches;

    if (inches >=12){
        feet+=(inches/12);
        inches=inches%12;
    } else if (inches < 0){
        feet-=((abs(inches)/12)+1);
        inches=12-(abs(inches) % 12);
    }

    if (feet>=3){
        yards+=(feet/3);
        feet=feet%3;
    } else if (feet<0) {
        yards-=((abs(feet)/3)+1);
        feet=3-(abs(feet)%3);
    }
    return *this;
}

bool Measure::operator!=(const Measure &right) {
    return (yards==right.yards && feet==right.feet && inches==right.inches) ? false : true;
}

Measure &Measure::operator+=(const int &num) {
    this->inches=inches+num;
    this->simplify();
    return *this;
}

#endif
