/*
 *  lab1exe_A.cpp
 *  ENSF 694 Lab 1, exercise A
 *  Created by Mahmood Moussavi
 *  Completed by: Jaskirat Singh
 *  Submission date: July 3
 */

//Lines starting with # are a pre-processor directive
#include <iostream>
#include <cmath>
using namespace std;

const double G = 9.8;   /* gravitation acceleration 9.8 m/s^2 */
const double PI = 3.141592654;

void create_table(double v);
double Projectile_travel_time(double a, double v);
double Projectile_travel_distance(double a, double v);
double degree_to_radian(double d);

int main(void)
{
    double velocity;
    
    cout << "Please enter the velocity at which the projectile is launched (m/sec): ";
    cin >> velocity;
    
    if(!cin)  // means if cin failed to read
    {
        cout << "Invlid input. Bye...\n";
        exit(1);
    }
    
    while (velocity < 0 )
    {
        cout << "\nplease enter a positive number for velocity: ";
        cin >> velocity;
        if(!cin)
        {
            cout << "Invlid input. Bye...";
            exit(1);
        }
    }
    
    create_table(velocity);
    
    
    return 0;
}

void create_table(double v) {
    //Print header elements and units
    cout << "Angle \t t \t d" << endl;
    cout << "(deg) \t (sec) \t (m)" << endl;
    
    //Calculate and print variable values
    for(double deg = 0; deg <= 90; deg += 5) {
        cout << deg;
        cout << " \t ";
        cout << Projectile_travel_time(deg, v);
        cout << " \t ";
        cout << Projectile_travel_distance(deg, v) << endl;
    }
}

double Projectile_travel_time(double a, double v) {
    return 2 * v * sin(degree_to_radian(a)) / G;
}

double Projectile_travel_distance(double a, double v) {
    return v * v * sin(2 * degree_to_radian(a)) / G;
}

double degree_to_radian(double d) {
    return d * PI / 180;
}
