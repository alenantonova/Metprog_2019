class Sofa : public Furniture
{
    std::string model;

public:
    Sofa() {
        model = "Sofa";
    }

    virtual std::string getFullInfo() override
    { return "Sofa"; }
};

class  MetalSofa : public Sofa
{
    std::string material;
public:
    MetalSofa() {
        material = "metal";
    }

    std::string getFullInfo() override
    { return "Metal Sofa"; }
};

class  WoodenSofa : public Sofa
{
    std::string material;
public:
    WoodenSofa() {
        material  = "wood";
    }

    std::string getFullInfo() override
    { return "Wooden Sofa"; }
};

class  PlasticSofa : public Sofa
{
    std::string material;
public:
    PlasticSofa() {
        material = "plastic";
    }

    std::string getFullInfo() override
    { return "Plastic Sofa"; }
};

class  RussianMetalSofa : public MetalSofa
{
    std::string manufacturer_country;
public:
    RussianMetalSofa() {
        manufacturer_country = "Russia";
    }

    std::string getFullInfo() override
    { return "Russian Metal Sofa"; }
};

class  RussianWoodenSofa : public Sofa
{
    std::string manufacturer_country;
public:
    RussianWoodenSofa() {
        manufacturer_country = "Russia";
    }

    std::string getFullInfo() override
    { return "Russian Wooden Sofa"; }
};

class  RussianPlasticSofa : public Sofa
{
    std::string manufacturer_country;
public:
    RussianPlasticSofa() {
        std::cout << "Create russian plastic Sofa" << std::endl;
        manufacturer_country = "Russia";
    }

    std::string getFullInfo() override
    { return "Russian Plastic Sofa"; }
};

class  ItalianMetalSofa : public MetalSofa
{
    std::string manufacturer_country;
public:
    ItalianMetalSofa() {
        manufacturer_country = "Italy";
    }

    std::string getFullInfo() override
    { return "Italian Metal Sofa"; }
};

class  ItalianWoodenSofa : public Sofa
{
    std::string manufacturer_country;
public:
    ItalianWoodenSofa() {
        manufacturer_country = "Italy";
    }

    std::string getFullInfo() override
    { return "Italian Wooden Sofa"; }
};

class  ItalianPlasticSofa : public Sofa
{
    std::string manufacturer_country;
public:
    ItalianPlasticSofa() {
        manufacturer_country = "Italy";
    }

    std::string getFullInfo() override
    { return "Italian Plastic Sofa"; }
};

class  ChineseMetalSofa : public MetalSofa
{
    std::string manufacturer_country;
public:
    ChineseMetalSofa() {
        manufacturer_country = "China";
    }

    std::string getFullInfo() override
    { return "Chinese Metal Sofa"; }
};

class  ChineseWoodenSofa : public Sofa
{
    std::string manufacturer_country;
public:
    ChineseWoodenSofa() {
        manufacturer_country = "China";
    }

    std::string getFullInfo() override
    { return "Chinese Wooden Sofa"; }
};

class  ChinesePlasticSofa : public Sofa
{
    std::string manufacturer_country;
public:
    ChinesePlasticSofa() {
        manufacturer_country = "China";
    }

    std::string getFullInfo() override
    { return "Chinese Plastic Sofa"; }
};
