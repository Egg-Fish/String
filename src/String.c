#include "String.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct String {
    size_t length;
    char *buffer;
};

String String_createFromBuffer(const char *buffer, size_t bufferSize) {
    String s = malloc(sizeof(struct String));

    s->length = bufferSize;
    s->buffer = malloc(bufferSize);

    for (size_t i = 0; i < bufferSize; i++) {
        s->buffer[i] = buffer[i];
    }

    return s;
}

String String_createFromLiteral(const char *literal) {
    const char *buffer = literal;
    size_t bufferSize = 0;

    char *c = (char *)literal;
    while (*c != '\0') {
        bufferSize++;
        c++;
    }

    return String_createFromBuffer(buffer, bufferSize);
}

void String_destroy(String s) {
    if (s == NULL) {
        return;
    }

    free(s->buffer);
    free(s);

    return;
}

size_t String_getLength(String s) { return s->length; }

bool String_equals(String s1, String s2) {
    size_t s1Length = s1->length;
    size_t s2Length = s2->length;

    if (s1Length != s2Length) {
        return false;
    }

    bool isEqual = true;

    for (size_t i = 0; i < s1Length; i++) {
        if (s1->buffer[i] != s2->buffer[i]) {
            isEqual = false;
            break;
        }
    }

    return isEqual;
}

bool String_startsWith(String s1, String s2) {
    size_t s1Length = s1->length;
    size_t s2Length = s2->length;

    if (s1Length < s2Length) {
        return false;
    }

    bool startsWith = true;

    for (size_t i = 0; i < s2Length; i++) {
        if (s1->buffer[i] != s2->buffer[i]) {
            startsWith = false;
            break;
        }
    }

    return startsWith;
}

bool String_endsWith(String s1, String s2) {
    size_t s1Length = s1->length;
    size_t s2Length = s2->length;

    if (s1Length < s2Length) {
        return false;
    }

    bool endsWith = true;

    for (size_t i = 0; i < s2Length; i++) {
        if (s1->buffer[s1Length - i - 1] != s2->buffer[s2Length - i - 1]) {
            endsWith = false;
            break;
        }
    }

    return endsWith;
}

void String_print(String s) {
    // TODO check for null
    // TODO add check for super long string
    unsigned length = (unsigned)s->length;
    char *c = s->buffer;

    printf("%.*s", length, c);

    return;
}
void String_printLine(String s) {
    String_print(s);
    printf("\n");
}
