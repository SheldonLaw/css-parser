//
// Created by sheldonluo on 2018/5/24.
//

#ifndef CSS_PARSER_CSS_BLOCK_H
#define CSS_PARSER_CSS_BLOCK_H

#include <list>

using namespace std;

class CSSProp {
public:
    string name;
    string value;
};

typedef list<CSSProp> CSSPropList;

class CSSBlock {

public:
    string selector;
    CSSPropList cssPropList;
    void addCSSProp(CSSProp& cssProp) {
        this->cssPropList.push_back(cssProp);
    }

};


#endif //CSS_PARSER_CSS_BLOCK_H
