//
// Created by cybartist on 13/2/2022.
//

#ifndef JSONPARSER_JSON_AST_STRUCT_H
#define JSONPARSER_JSON_AST_STRUCT_H

#include <vector>

namespace JSON_AST_STRUCT {
    enum ItemTypeEnum {
        Null, Boolean, Integer, Float, String, Dict, List
    };

    typedef const char*             StringType;
    typedef bool                    BooleanType;
    typedef long long               IntegerType;
    typedef double                  FloatType;
    struct                          DictRow;
    struct                          ItemRoot;
    typedef std::vector<DictRow>    DictRoot;
    typedef std::vector<ItemRoot>   ListRoot;

    union ItemType {
        BooleanType                 boolean;
        IntegerType                 integerNumber;
        FloatType                   floatNumber;
        StringType                  string;
        DictRoot                    dict;
        ListRoot                    list;
    };

    struct ItemRoot {
        ItemTypeEnum                itemType;
        ItemType*                   item;
    };

    struct DictRow {
        StringType                  key;
        ItemRoot                    value;
    };

}

#endif //JSONPARSER_JSON_AST_STRUCT_H
