#include <iostream>
#include "src/css_parser.h"

void printList(CSSBlockList& cssBlockList) {

    for (auto cssBlock : cssBlockList) {
        std::cout<< cssBlock.selector  <<std::endl;
        for (auto cssProp : cssBlock.cssPropList) {
            std::cout<< cssProp.name << cssProp.value  <<std::endl;
        }
    }
}

int main() {

    CSSParser cssParser = CSSParser();
    string cssTxt = "   .mod_mask {display: none; position: fixed; z-index: 100; width: 100%; height: 100%; left: 0; top: 0; background: #000; filter: alpha(opacity=40); opacity: 0.4; } .mod_mask {display: none; position: fixed; z-index: 100; width: 100%; height: 100%; left: 0; top: 0; background: #000; filter: alpha(opacity=40); opacity: 0.4; }";
    CSSBlockList cssBlockList = cssParser.parse(cssTxt);

    std::cout << "打印解析结果------" << std::endl;
    printList(cssBlockList);

    return 0;
}