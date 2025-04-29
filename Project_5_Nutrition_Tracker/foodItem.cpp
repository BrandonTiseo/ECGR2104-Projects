#include "foodItem.h"

FoodItem::FoodItem(std::string nName, double nCal, double nFat, double nSugar, double nProtein, double nSodium){
    setName(nName);
    setCalories(nCal);
    setFat(nFat);
    setSugar(nSugar);
    setProtein(nProtein);
    setSodium(nSodium);
}

void FoodItem::setName(std::string nName){
    name = nName;
}

std::string FoodItem::getName() const{
    return name;
}

void FoodItem::setCalories(double nCal){
    if(nCal < 0.0)
        std:: cout << "Invalid Calories Input, must be atleast 0.0" << std::endl;
    else
        calories = nCal;
}

double FoodItem::getCalories() const{
    return calories;
}

void FoodItem::setFat(double nFat){
    if(nFat < 0.0)
        std:: cout << "Invalid Fat Input, must be atleast 0.0" << std::endl;
    else
        fat = nFat;
}

double FoodItem::getFat() const{
    return fat;
}

void FoodItem::setSugar(double nSugar){
    if(nSugar < 0.0)
        std:: cout << "Invalid Sugar Input, must be atleast 0.0" << std::endl;
    else
        sugar = nSugar;
}

double FoodItem::getSugar() const{
    return sugar;
}

void FoodItem::setProtein(double nProtein){
    if(nProtein < 0.0)
        std:: cout << "Invalid Protein Input, must be atleast 0.0" << std::endl;
    else
        protein = nProtein;
}
double FoodItem::getProtein() const{
    return protein;
}

void FoodItem::setSodium(double nSodium){
    if(nSodium < 0.0)
        std:: cout << "Invalid Sodium Input, must be atleast 0.0" << std::endl;
    else
        sodium = nSodium;
}

double FoodItem::getSodium() const{
    return sodium;
}

FoodItem FoodItem::operator+(const FoodItem rhs){
    //Determine name of the new FoodItem object.
    std::string nName;
    if(name == "DailyValue" or rhs.getName() == "DailyValue"){
        nName = "DailyValue";
    }else{
        nName = name + "&" + rhs.getName();
    }
    double nCalories = this->calories + rhs.getCalories();
    double nFat = this->fat + rhs.getFat();
    double nSugar = this->sugar + rhs.getSugar();
    double nProtein = this->protein + rhs.getProtein();
    double nSodium = this->sodium + rhs.getSodium();

    return FoodItem(nName, nCalories, nFat, nSugar, nProtein, nSodium);
}

void FoodItem::print(){
    std::cout 
    << name << ":" 
    << "\nCalories: " << calories  << " cal"
    << "\nFat: " << fat << "g"
    << "\nSugar: " << sugar << "g"
    << "\nProtein: " << protein << "g"
    << "\nSodium: " << sodium << "mg"
    << std::endl;
}
