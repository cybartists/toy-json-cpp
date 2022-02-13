//
// Created by cybartist on 13/2/2022.
//

#include <cstdio>
#include <vector>
#include <string>
#include "JSON_AST_STRUCT.h"
#include "JSON_COMPILER.h"
#define SIZE 1024 * 1024
using namespace std;
using namespace JSON_AST_STRUCT;

ItemRoot* init_ast() {
    /*
     * {
     *     "hello": "world",
     *     "test_bool": false,
     *     "test_dict": {
     *         "test_list": [
     *             1,
     *             2.000000
     *         ]
     *     }
     * }
     *
     * */
    return new ItemRoot { ItemTypeEnum::Dict, new ItemType {
        .dict = DictRoot {
            DictRow {
                .key = "hello",
                .value = ItemRoot { ItemTypeEnum::String, new ItemType {
                    .string = "world"}}},
            DictRow{
                .key = "test_bool",
                .value = ItemRoot { ItemTypeEnum::Boolean, new ItemType {
                    .boolean = false}}},
            DictRow{
                .key = "test_dict",
                .value = ItemRoot { ItemTypeEnum::Dict, new ItemType {
                    .dict = DictRoot {
                        DictRow {
                            .key = "test_list",
                            .value = ItemRoot { ItemTypeEnum::List, new ItemType {
                                .list = ListRoot {
                                    ItemRoot { ItemTypeEnum::Integer, new ItemType {
                                        .integerNumber = 1
                                    }},
                                    ItemRoot { ItemTypeEnum::Float, new ItemType {
                                        .floatNumber = 2
                                    }}
                                }
                            }}
                        }
                    }}
                }
            }
        }
    }};
}



void input_test() {
    wchar_t s[SIZE] = {};
    int c = getchar();
    int count = 0;
    while (c != EOF && count < SIZE) {
        s[count++] = char(c);
        c = getchar();
    }
    s[count] = u'\0';
    printf("%ls", s);
}


int main() {
    auto ast = init_ast();
    auto json = R"({"hello":world,"test_bool":false,"test_dict":{"test_list":[1,2.000000]}})";
    string res = compile(ast);
    assert(strcmp(res.c_str(), json) == 0);
    return 0;
}
