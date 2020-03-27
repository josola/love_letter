/*
 * Determines player information.
 * This software uses the MIT license.
 * Written by Jordan Sola 2020
 */

#include <string>
#include <vector>
#include "player.h"

using std::string;
using std::vector;

Player::Player(string name, int value) : name(name), value(value){};
PlayerController::PlayerController(Player &player) : player(player){};

string Player::GetName() { return name; }
int Player::GetValue() { return value; }
bool Player::GetCurrentStatus() { return current_player; }
vector<Card> Player::GetHand() { return hand; }
void Player::SetCurrent()
{
    initial_log.push_back("current_player before setter: " + current_player);
    if (current_player)
    {
        current_player = false;
    }
    else
    {
        current_player = true;
    }
}