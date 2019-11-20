#include "Furniture.h"

class Chair : public Furniture
{
    std::string model;

public:
    Chair() {
        model = "Chair";
    }

    virtual std::string getFullInfo() override
    { return "Chair"; }
};

class  MetalChair : public Chair
{
    std::string material;
public:
    MetalChair() {
        material = "metal";
    }

    std::string getFullInfo() override
    { return "Metal Chair"; }
};

class  WoodenChair : public Chair
{
    std::string material;
public:
    WoodenChair() {
        material  = "wood";
    }

    std::string getFullInfo() override
    { return "Wooden Chair"; }
};

class  PlasticChair : public Chair
{
    std::string material;
public:
    PlasticChair() {
        material = "plastic";
    }

    std::string getFullInfo() override
    { return "Plastic Chair"; }
};

class  RussianMetalChair : public MetalChair
{
    std::string manufacturer_country;
public:
    RussianMetalChair() {
        manufacturer_country = "Russia";
    }

    std::string getFullInfo() override
    { return "Russian Metal Chair"; }
};

class  RussianWoodenChair : public Chair
{
    std::string manufacturer_country;
public:
    RussianWoodenChair() {
        manufacturer_country = "Russia";
    }

    std::string getFullInfo() override
    { return "Russian Wooden Chair"; }
};

class  RussianPlasticChair : public Chair
{
    std::string manufacturer_country;
public:
    RussianPlasticChair() {
        std::cout << "Create russian plastic Chair" << std::endl;
        manufacturer_country = "Russia";
    }

    std::string getFullInfo() override
    { return "Russian Plastic Chair"; }
};

class  ItalianMetalChair : public MetalChair
{
    std::string manufacturer_country;
public:
    ItalianMetalChair() {
        manufacturer_country = "Italy";
    }

    std::string getFullInfo() override
    { return "Italian Metal Chair"; }
};

class  ItalianWoodenChair : public Chair
{
    std::string manufacturer_country;
public:
    ItalianWoodenChair() {
        manufacturer_country = "Italy";
    }

    std::string getFullInfo() override
    { return "Italian Wooden Chair"; }
};

class  ItalianPlasticChair : public Chair
{
    std::string manufacturer_country;
public:
    ItalianPlasticChair() {
        manufacturer_country = "Italy";
    }

    std::string getFullInfo() override
    { return "Italian Plastic Chair"; }
};

class  ChineseMetalChair : public MetalChair
{
    std::string manufacturer_country;
public:
    ChineseMetalChair() {
        manufacturer_country = "China";
    }

    std::string getFullInfo() override
    { return "Chinese Metal Chair"; }
};

class  ChineseWoodenChair : public Chair
{
    std::string manufacturer_country;
public:
    ChineseWoodenChair() {
        manufacturer_country = "China";
    }

    std::string getFullInfo() override
    { return "Chinese Wooden Chair"; }
};

class  ChinesePlasticChair : public Chair
{
    std::string manufacturer_country;
public:
    ChinesePlasticChair() {
        manufacturer_country = "China";
    }

    std::string getFullInfo() override
    { return "Chinese Plastic Chair"; }
};
