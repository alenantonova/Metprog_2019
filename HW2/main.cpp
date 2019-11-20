#include "ChairModels.h"
#include "TableModels.h"
#include "SofaModels.h"
#include "FactoryUtils.h"

int main() {

    using AbstractFactory = GetAbstractFactory<3, 5,  TypeList<Chair, Table, Sofa>, TypeList< WoodenChair, WoodenTable, WoodenSofa>,
            TypeList< MetalChair, MetalTable, MetalSofa>, TypeList< ChineseMetalChair, ChineseMetalTable,
                    ChineseMetalSofa>, TypeList< RussianWoodenChair, RussianWoodenTable, RussianWoodenSofa>>;

    auto TestAbstractFactory = AbstractFactory();
    auto RussianWoodenFactory = TestAbstractFactory.GetConcreteFactory<RussianWoodenSofa>();
    assert(RussianWoodenFactory->Get<Table>()->getFullInfo() == "Russian Wooden Table");

    auto ChineseMetalFactory = TestAbstractFactory.GetConcreteFactory<ChineseMetalTable>();
    assert(ChineseMetalFactory->Get<Chair>()->getFullInfo() == "Chinese Metal Chair");

    auto WoodenFactory = TestAbstractFactory.GetConcreteFactory<WoodenChair>();
    assert(WoodenFactory->Get<Sofa>()->getFullInfo() == "Wooden Sofa");

    return 0;
}