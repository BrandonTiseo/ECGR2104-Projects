#include <stdio.h>
#include <iostream>
#include <math.h>

#define RADIUS 3958.8
#define JETSPD 500

using namespace std;

//Calculates the Distance Between Two Points on Earth Via the Haversine Formula
double haversine(double lat1, double long1, double lat2, double long2, double radius){
    double d = 2.0 * radius * asin( sqrt( pow(sin((lat2 - lat1)/2.0),2.0) + cos(lat1) * cos(lat2) * pow(sin((long2 - long1)/2.0),2.0)));
    return d;
}


//Calcultes Flight Time In Hours
double getFlightTime(double lat1, double long1, double lat2, double long2){
    double distance = haversine(lat1, long1, lat2, long2, RADIUS);
    return distance / JETSPD;
}


//Main Program
int main(){
    //Section: Data Initalization
    string location[] = {"Miami Beach, FL, USA", "Fargo, ND, USA", "Idaho City, ID, USA","Evergaldes City, FL, USA", "Grand Haven, MI, USA",
                         "Medford, MA, USA","Newton, KS, USA", "Aurora, TX, USA", "Vernal, UT, USA", "Monroe, LA, USA"
                        };
    double latitude[] = {25.793449,46.877186,43.828850, 25.857803, 43.062244, 42.419331, 38.047016, 33.061062, 40.454086, 32.509930};
    double longitude[] = {-80.139198,-96.789803,-115.87860, -81.386658, -86.230759, -71.119720, -97.350304, -97.511391, -109.538246, -92.121742};
    int num_locations = sizeof(location) / sizeof(location[0]);

    //Section: Collecting Departure Location Data
    cout << "Please select a departure location: (input a number value)" << endl;
    for(int i = 0; i < num_locations; i++)
        cout << i+1 << ". " << location[i] << " " << latitude[i] << " " << longitude[i] << endl;

    bool valid_input = false;
    string user_input;

    int departure_index;
    while(!valid_input){
        cin >> user_input;
        departure_index = atoi(user_input.c_str());
        if(departure_index <= 0 || departure_index > num_locations){
            cout << "INVALID INPUT. TRY AGAIN" << endl;
            continue;
        }
        departure_index -= 1;
        valid_input = true;
    }

    //Section: Collecting Arrival Location Data
    valid_input = false;
    cout << "Please select an arrival location: (input a number value)" << endl;
    for(int i = 0; i < num_locations; i++){
        if(i == departure_index)
            continue;
        else if(i > departure_index)
            cout << i << ". " << location[i] << " " << latitude[i] << " " << longitude[i] << endl;
        else
            cout << i+1 << ". " << location[i] << " " << latitude[i] << " " << longitude[i] << endl;
    }

    int arrival_index;
    while(!valid_input){
        cin >> user_input;
        arrival_index = atoi(user_input.c_str());
        if(arrival_index <= 0 || arrival_index > num_locations){
            cout << "INVALID INPUT. TRY AGAIN" << endl;
            continue;
        }
        else if(arrival_index <= departure_index)
            arrival_index -= 1;
        valid_input = true;
    }
        
    //Section: Calculating Distance & Flight Time
    double flight_time = getFlightTime(latitude[departure_index], longitude[departure_index], latitude[arrival_index], longitude[arrival_index]);
    cout << "A flight from " << location[departure_index] << " to " << location[arrival_index] << " will take: " << flight_time << " hours." << endl;

    return 0;
}