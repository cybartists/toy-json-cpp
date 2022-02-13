//
// Created by cybartist on 13/2/2022.
//

#include "JSON_COMPILER.h"

using namespace std;
using namespace JSON_AST_STRUCT;

string compile(ItemRoot *root) {
    string s;
    bool head = true;
    switch (root->itemType) {
        case ItemTypeEnum::Dict:
            s.append("{");
            for (auto&& row: root->item->dict) {
                if (head) {
                    head = false;
                } else {
                    s.append(",");
                }
                s.append("\"");
                s.append(row.key);
                s.append("\":");
                s.append(compile(&row.value));
            }
            s.append("}");
            return s;
        case ItemTypeEnum::Null:
            s.append("null");
            return s;
        case ItemTypeEnum::Boolean:
            if (root->item->boolean) {
                s.append("true");
            } else {
                s.append("false");
            }
            return s;
        case ItemTypeEnum::Integer:
            s.append(to_string(root->item->integerNumber));
            return s;
        case ItemTypeEnum::Float:
            s.append(to_string(root->item->floatNumber));
            return s;
        case ItemTypeEnum::String:
            s.append(root->item->string);
            return s;
        case ItemTypeEnum::List:
            s.append("[");
            for (auto &&item: root->item->list) {
                if (head) {
                    head = false;
                } else {
                    s.append(",");
                }
                s.append(compile(&item));
            }
            s.append("]");
            return s;
    }
}
