//
// Created by sheldonluo on 2018/5/24.
//

#ifndef CSS_PARSER_CSS_PARSER_H_H
#define CSS_PARSER_CSS_PARSER_H_H

#include "css_block.h"

string& trim(string &s);

typedef list<CSSBlock> CSSBlockList;
enum ParseStatus {
    PARSE_SELECTOR,
    PARSE_PROP_NAME,
    PARSE_PROP_VALUE
};

class CSSParser {

private:
    CSSBlockList cssBlockList;

public:
    CSSBlockList parse(string cssTxt) {

        int txtLength = cssTxt.length();
        CSSBlock* cssBlock;
        CSSProp* cssProp;
        ParseStatus status = PARSE_SELECTOR;
        string str = "";

        for (int i = 0; i < txtLength; ++i) {
            char cur = cssTxt[i];

            switch (cur) {
                case ' ': // 空格 - 在selector匹配和在css属性值匹配中有效
                    cout << "空格" << endl;
                    if (status == PARSE_SELECTOR || status == PARSE_PROP_VALUE) {
                        str += cur;
                    }
                    break;
                case EOF: // 换行符 - 忽略
                    cout << "换行" << endl;
                    break;
                case '{': // 左大括号 - css block开始
                    cout << "左大括号" << endl;
                    cssBlock = new CSSBlock();
                    trim(str);
                    cssBlock->selector = str;
                    cout << "selector: " << str << endl;
                    str = "";
                    status = PARSE_PROP_NAME;
                    break;
                case '}': // 右大括号 - css block结束
                    cout << "右大括号" << endl;
                    this->cssBlockList.push_back(*cssBlock);
                    status = PARSE_SELECTOR;
                    break;
                case ':': // 冒号 - css属性名结束
                    cout << "冒号" << endl;
                    trim(str);
                    cssProp = new CSSProp();
                    cssProp->name = str;
                    cout << "css prop name: " << str << endl;
                    str = "";
                    status = PARSE_PROP_VALUE;
                    break;
                case ';': // 分号 - css属性值结束
                    cout << "分号" << endl;
                    trim(str);
                    cssProp->value = str;
                    cout << "css prop value: " << str << endl;
                    str = "";
                    status = PARSE_PROP_NAME;
                    cssBlock->addCSSProp(*cssProp);
                    break;
                default:
                    str += cur;
                    break;
            }
        }
        return this->cssBlockList;
    }

};


// 辅助函数
string& trim(string &s)
{
    if (s.empty()) {
        return s;
    }
    s.erase(0,s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);
    return s;
}

#endif //CSS_PARSER_CSS_PARSER_H_H
