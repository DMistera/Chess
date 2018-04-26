#include "Player.h"
#include "Side.h"


Player::Player(Side white) {
	m_side = white;
}

Player::~Player() {
}

void Player::makeMove(Piece * piece, Field field) {
	piece->setField(field);
}
