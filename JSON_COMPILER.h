//
// Created by cybartist on 13/2/2022.
//

#ifndef JSONPARSER_JSON_COMPILER_H
#define JSONPARSER_JSON_COMPILER_H

#include <string>
#include "JSON_AST_STRUCT.h"

std::string compile(JSON_AST_STRUCT::ItemRoot *root);
std::string human_readable_compile(JSON_AST_STRUCT::ItemRoot *root);


#endif //JSONPARSER_JSON_COMPILER_H
