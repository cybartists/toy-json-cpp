//
// Created by cybartist on 13/2/2022.
//

#ifndef JSONPARSER_JSON_PARSER_EXCEPTION_H
#define JSONPARSER_JSON_PARSER_EXCEPTION_H

#include <exception>

struct ItemTypeIllegalException : public std::exception {};
struct BracketMismatchingException : public std::exception {};

#endif //JSONPARSER_JSON_PARSER_EXCEPTION_H
