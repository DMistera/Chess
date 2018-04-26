#pragma once

#include "Player.h"
#include "Side.h"

class ComputerPlayer : public Player {
public:
	ComputerPlayer(Side white);
	~ComputerPlayer();
};

