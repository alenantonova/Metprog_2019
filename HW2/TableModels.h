#ifndef FURNITURE_H
#define FURNITURE_H

class Table : public Furniture
{
    std::string model;

public:
    Table() {
        model = "Table";
    }

    virtual std::string getFullInfo() override
    { return "Table"; }
};

class  MetalTable : public Table
{
    std::string material;
public:
    MetalTable() {
        material = "metal";
    }

    std::string getFullInfo() override
    { return "Metal Table"; }
};

class  WoodenTable : public Table
{
    std::string material;
public:
    WoodenTable() {
        material  = "wood";
    }

    std::string getFullInfo() override
    { return "Wooden Table"; }
};

class  PlasticTable : public Table
{
    std::string material;
public:
    PlasticTable() {
        material = "plastic";
    }

    std::string getFullInfo() override
    { return "Plastic Table"; }
};

class  RussianMetalTable : public MetalTable
{
    std::string manufacturer_country;
public:
    RussianMetalTable() {
        manufacturer_country = "Russia";
    }

    std::string getFullInfo() override
    { return "Russian Metal Table"; }
};

class  RussianWoodenTable : public Table
{
    std::string manufacturer_country;
public:
    RussianWoodenTable() {
        manufacturer_country = "Russia";
    }

    std::string getFullInfo() override
    { return "Russian Wooden Table"; }
};

class  RussianPlasticTable : public Table
{
    std::string manufacturer_country;
public:
    RussianPlasticTable() {
        std::cout << "Create russian plastic Table" << std::endl;
        manufacturer_country = "Russia";
    }

    std::string getFullInfo() override
    { return "Russian Plastic Table"; }
};

class  ItalianMetalTable : public MetalTable
{
    std::string manufacturer_country;
public:
    ItalianMetalTable() {
        manufacturer_country = "Italy";
    }

    std::string getFullInfo() override
    { return "Italian Metal Table"; }
};

class  ItalianWoodenTable : public Table
{
    std::string manufacturer_country;
public:
    ItalianWoodenTable() {
        manufacturer_country = "Italy";
    }

    std::string getFullInfo() override
    { return "Italian Wooden Table"; }
};

class  ItalianPlasticTable : public Table
{
    std::string manufacturer_country;
public:
    ItalianPlasticTable() {
        manufacturer_country = "Italy";
    }

    std::string getFullInfo() override
    { return "Italian Plastic Table"; }
};

class  ChineseMetalTable : public MetalTable
{
    std::string manufacturer_country;
public:
    ChineseMetalTable() {
        manufacturer_country = "China";
    }

    std::string getFullInfo() override
    { return "Chinese Metal Table"; }
};

class  ChineseWoodenTable : public Table
{
    std::string manufacturer_country;
public:
    ChineseWoodenTable() {
        manufacturer_country = "China";
    }

    std::string getFullInfo() override
    { return "Chinese Wooden Table"; }
};

class  ChinesePlasticTable : public Table
{
    std::string manufacturer_country;
public:
    ChinesePlasticTable() {
        manufacturer_country = "China";
    }

    std::string getFullInfo() override
    { return "Chinese Plastic Table"; }
};

#endif
