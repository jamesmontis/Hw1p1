// James Montis
// This is the first homework for DS 2437
// This program uses class Measure for accounting for yards, feet and inches
// via objects and operator overloading.  Several of the operators are tested below using cout

#include <iostream>
#include "Measure.h"
#include <cmath>

using namespace std;

int main() {
    Measure m1(1,33,33), m2(1,33,33);  // tests Measure class outputs

    cout << "******* Before simplify is called *****\n";
    cout << "m1 yards, feet, inches are: " << m1.getYards() << ", " << m1.getFeet() << ", "<<m1.getInch() << endl;
    cout << "m2 yards, feet, inches are: " << m2.getYards() << ", " << m2.getFeet() << ", "<<m2.getInch() << endl;
    cout << "\n Does m1!=m2? should be 0, because they are == >" << (m1!=m2);

    m1.simplify();
    m2.simplify();
    cout << "\n***************\nm1.yard " << m1.getYards() << " | m1.ft " << m1.getFeet() << " | m1.inch " << m1.getInch() << endl;
    cout << "\nm2.yd " << m2.getYards() << " | m2.ft " << m2.getFeet() << " | m2.inch " << m2.getInch() << endl;
    cout << "***************... calling simplify()...\n";

    cout << "\nm1.getYards is > " << m1.getYards() << " and m2.getYards is >" << m2.getYards();
    m2.setYards(2);
    cout <<"\nDid m1=m2 correctly? > " << (m1=m2);
    cout <<"\nm1 yards should be 2 ->" << m1.getYards();


    cout << "\n*************************\n";
    cout << "Measure 1 yds= " << m1.getYards() << " ft=" << m1.getFeet() << " inches= "<< m1.getInch() << endl;
    cout << "Measure 2 yds= " << m2.getYards() << " ft=" << m2.getFeet() << " inches= "<< m2.getInch() << endl;
    cout << "*************************\n";

    cout << "\n\nMeasure 1 + Measure 2 = ";
    cout << m1+m2; //overloaded << and + here for Measure objects
    cout << endl;
    cout << "Measure 2 - Measure 1 = ";
    cout << m2-m1;
    cout << "\n0 for false, 1 for true\nIs M1 == M2? > ";
    cout << (m1==m2);
    cout << "\nIs M1 < M2? > ";
    cout << (m1<m2);
    cout << "\nIs m2 > m1 > ";
    cout << (m2 > m1) << endl << endl;

    cout << "Does m1+=m2? > " << (m1+=m2); // overloaded += appears to work

    cout << "\n************************************\n";
    cout << "Now testing operator<< ";
    cout << m1 << endl;
    cout << "**************************\n";
    cout << "Finally, test +8 inches\n";
    cout << "m1 inches before: " << m1.getInch() << endl;
    m1+=8;
    cout << endl << "m1 inches after : " << m1.getInch() << endl;

}
