#ifndef FOODITEM_H
#define FOODITEM_H

#include <iostream>
#include <string>


class FoodItem{
    public:
    FoodItem(std::string nName, double nCal, double nFat, double nSugar, double nProtein, double nSodium);

    void setName(std::string nName);
    std::string getName() const;

    void setCalories(double nCal);
    double getCalories() const;

    void setFat(double nFat);
    double getFat() const;

    void setSugar(double nSugar);
    double getSugar() const;

    void setProtein(double nProtein);
    double getProtein() const;

    void setSodium(double nSodium);
    double getSodium() const;

    FoodItem operator+(const FoodItem rhs);

    void print();

    private:
    std::string name;
    double calories;
    double fat;
    double sugar;
    double protein;
    double sodium;

};

#endif