#pragma once

#include <stdbool.h>
#include <stddef.h>

typedef struct String *String;

String String_createFromBuffer(const char *buffer, size_t bufferSize);
String String_createFromLiteral(const char *literal);
void String_destroy(String s);

bool String_equals(String s1, String s2);

void String_print(String s);
void String_printLine(String s);
