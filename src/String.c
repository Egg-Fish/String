#include "String.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct String {
    size_t length;
    size_t offset;
    char *buffer;
};

String String_createFromBuffer(const char *buffer, size_t bufferSize) {
    String s = malloc(sizeof(struct String));

    s->length = bufferSize;
    s->offset = 0;
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
void String_setLength(String s, size_t length) {
    s->length = length;
    return;
}

const char *String_getBuffer(String s) { return s->buffer + s->offset; }
void String_setBuffer(String s, char *buffer) {
    s->buffer = buffer;
    return;
}

size_t String_getOffset(String s) { return s->offset; }
void String_setOffset(String s, size_t offset) {
    s->offset = offset;
    return;
}

void String_append(String s, String suffix) {
    size_t sLength = String_getLength(s);
    size_t suffixLength = String_getLength(suffix);

    size_t newLength = sLength + suffixLength;
    char *newBuffer = malloc(newLength);

    const char *sBuffer = String_getBuffer(s);
    const char *suffixBuffer = String_getBuffer(suffix);

    for (size_t i = 0; i < newLength; i++) {
        if (i < sLength) {
            newBuffer[i] = sBuffer[i];
        } else {
            newBuffer[i] = suffixBuffer[i - sLength];
        }
    }

    free((char *)sBuffer);
    String_setLength(s, newLength);
    String_setOffset(s, 0);
    String_setBuffer(s, newBuffer);

    return;
}

void String_prepend(String s, String prefix) {
    size_t sLength = String_getLength(s);
    size_t prefixLength = String_getLength(prefix);

    size_t newLength = sLength + prefixLength;
    char *newBuffer = malloc(newLength);

    const char *sBuffer = String_getBuffer(s);
    const char *prefixBuffer = String_getBuffer(prefix);

    for (size_t i = 0; i < newLength; i++) {
        if (i < prefixLength) {
            newBuffer[i] = prefixBuffer[i];
        } else {
            newBuffer[i] = sBuffer[i - prefixLength];
        }
    }

    free((char *)sBuffer);
    String_setLength(s, newLength);
    String_setOffset(s, 0);
    String_setBuffer(s, newBuffer);
    
    return;
}

bool String_equals(String s1, String s2) {
    size_t s1Length = s1->length;
    size_t s2Length = s2->length;

    if (s1Length != s2Length) {
        return false;
    }

    bool isEqual = true;

    const char *s1Buffer = String_getBuffer(s1);
    const char *s2Buffer = String_getBuffer(s2);

    for (size_t i = 0; i < s1Length; i++) {
        if (s1Buffer[i] != s2Buffer[i]) {
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

    const char *s1Buffer = String_getBuffer(s1);
    const char *s2Buffer = String_getBuffer(s2);

    for (size_t i = 0; i < s2Length; i++) {
        if (s1Buffer[i] != s2Buffer[i]) {
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

    const char *s1Buffer = String_getBuffer(s1);
    const char *s2Buffer = String_getBuffer(s2);

    for (size_t i = 0; i < s2Length; i++) {
        if (s1Buffer[s1Length - i - 1] != s2Buffer[s2Length - i - 1]) {
            endsWith = false;
            break;
        }
    }

    return endsWith;
}

void String_print(String s) {
    // TODO check for null
    // TODO add check for super long string
    unsigned length = (unsigned)String_getLength(s);
    const char *c = String_getBuffer(s);

    printf("%.*s", length, c);

    return;
}
void String_printLine(String s) {
    String_print(s);
    printf("\n");
}
