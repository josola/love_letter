/*
 * Holds information about the game state.
 * This software uses the MIT license.
 * Written by Jordan Sola 2020
 */

#include <iostream>
#include "game_manager.h"
#include "player.h"

using std::cin;

GameController::GameController(GameState &state, Console &console) : state(state), console(console){};

int GameState::GetRoundCount() { return round_count; }
int GameState::GetPlayerCount() { return player_count; }
int GameState::GetStartingPlayerCount() { return starting_player_count; }
int GameState::GetWinningTokenCount() { return winning_token_count; }
vector<Player> GameState::GetPlayerContainer() { return player_container; }

void GameState::SetPlayerCount(int value)
{
    initial_log.push_back("player_count before setter: " + player_count);
    player_count = value;
}

void GameState::SetStartingPlayerCount(int value)
{
    initial_log.push_back("starting_player_count before setter: " + starting_player_count);
    starting_player_count = value;
}

void GameState::SetPlayerContainer(vector<Player> input)
{
    player_container = input;
}

void GameState::SetWinningTokenCount(int value)
{
    initial_log.push_back("winning_token_count before setter: " + winning_token_count);
    winning_token_count = value;
}

int GameController::SetPlayerCount(int output)
{
    bool correct_input = false;
    //check that input is within bounds
    while (!correct_input)
    {
        if (output >= 2 && output <= 6 && cin)
        {
            correct_input = true;
        }
        else
        {
            //reset cin fail, clear input buffer
            cin.clear();
            cin.ignore();
            console.PrintInvalidInput(1);
            output = console.ReceiveNumInput();
        }
    }
    return output;
}

vector<Player> GameController::SetPlayerContainer(int count)
{
    if (count == 2)
    {
        vector<Player> output{Player("PLAYER[1]", 1), Player("PLAYER[2]", 2)};
        return output;
    }
    else if (count == 3)
    {
        vector<Player> output{Player("PLAYER[1]", 1), Player("PLAYER[2]", 2), Player("PLAYER[3]", 3)};
        return output;
    }
    else if (count == 4)
    {
        vector<Player> output{Player("PLAYER[1]", 1), Player("PLAYER[2]", 2), Player("PLAYER[3]", 3), Player("PLAYER[4]", 4)};
        return output;
    }
    else if (count == 5)
    {
        vector<Player> output{Player("PLAYER[1]", 1), Player("PLAYER[2]", 2), Player("PLAYER[3]", 3), Player("PLAYER[4]", 4), Player("PLAYER[5]", 5)};
        return output;
    }
    else if (count == 6)
    {
        vector<Player> output{Player("PLAYER[1]", 1), Player("PLAYER[2]", 2), Player("PLAYER[3]", 3), Player("PLAYER[4]", 4), Player("PLAYER[5]", 5), Player("PLAYER[6]", 6)};
        return output;
    }
    else
    {
        vector<Player> output;
        return output;
    }
    
}

int GameController::SetWinningTokenCount(int count)
{
    int output = 0;
    switch (count)
    {
    case 2:
        output = 6;
        break;
    case 3:
        output = 5;
        break;
    case 4:
        output = 4;
        break;
    case 5:
        output = 3;
        break;
    case 6:
        output = 3;
        break;
    }
    return output;
}