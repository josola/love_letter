/*
 * Helper utility for card.
 * This software uses the MIT license.
 * Written by Jordan Sola 2019-2020
 */

#include "card.h"

const string Card::GetName() {
    return name_;
}
const int Card::GetValue() {
    return value_;
}

void Card::SetName(const string name) {
    name_ = name;
}
void Card::SetValue(const int value) {
    value_ = value;
}