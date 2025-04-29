#include "foodItem.h"
#include <vector>


int main(){
    //Populating menu vector and dailyValue tracker variable.
    FoodItem dailyValue = FoodItem("DailyValue",0.0,0.0,0.0,0.0,0.0);
    std::vector<FoodItem> menu = {
        FoodItem("Apple", 95.0, 0.3, 19.0, 0.5, 0.0),
        FoodItem("French Fries", 312.0, 15.0, 0.3, 3.4, 210.0),
        FoodItem("Burger", 295.0, 12.0, 5.1, 13.0, 396.0),
        FoodItem("Instant Ramen", 380.0, 14.0, 2.0, 8.0, 1820.0),
        FoodItem("Protein Bar", 190.0, 8.0, 1.0, 20.0, 330.0),
        FoodItem("Orange", 62.0, 0.2, 12.0, 1.2, 0.0),
        FoodItem("Ceasar Salad", 190.0, 15.0, 1.0, 5.0, 400.0),
        FoodItem("Pasta", 158.0, 1.0, 0.5, 6.0, 1.0),
        FoodItem("Ham&Cheese Sandwich", 350.0, 15.0, 4.0, 20.0, 1000.0),
        FoodItem("Beef Taco", 250.0, 13.0, 2.0, 12.0, 420.0)
    };

    //User input section.
    int userInput = -1;
    while(userInput != menu.size()){
        //Displaying menu items.
        std::cout << "Choose a food item from the menu: " << std::endl;
        for(int i = 0; i <= menu.size(); i++){
            if(i == menu.size()){
                std::cout << i+1 << ": " << "Finished" << std::endl;
                break;
            }else{
                std::cout << i+1 << ": " << menu[i].getName() << std::endl;
            }
        }

        //Collecting user input and adjusting its value to match array positions (subtract 1).
        std::cin >> userInput;
        userInput -= 1;
        if(userInput < 0 or userInput > menu.size()){
            std::cout<<"IMPROPER INPUT"<<std::endl;
        }else if(userInput == menu.size()){
            break;
        }else{
            dailyValue = dailyValue + menu[userInput];
        }
    }

    //Displaying daily intake and any exceeded values.
    std::cout << "--------------------------" << std::endl;
    dailyValue.print();
    std::cout << "--------------------------" << std::endl;
    if(dailyValue.getCalories() > 2000.0){
        std::cout<<"Calorie intake exceeded." <<std::endl;
    }
    if(dailyValue.getFat() > 70.0){
        std::cout<<"Fat intake exceeded." <<std::endl;
    }
    if (dailyValue.getSugar() > 30.0){
        std::cout<<"Sugar intake exceeded." <<std::endl;
    }
    if(dailyValue.getProtein() > 50.0){
        std::cout<<"Protein intake exceeded." <<std::endl;
    }
    if(dailyValue.getSodium() > 2300.0){
        std::cout<<"Sodium intake exceeded." <<std::endl;
    }

    return 0;
}