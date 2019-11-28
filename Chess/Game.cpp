#include "Game.h"


Game::Game() {
	m_white = new HumanPlayer(Side::WHITE);
	m_black = new HumanPlayer(Side::BLACK);
	m_animationState = false;
	m_state = new GameState();

	m_turnsThread = new std::thread(&Game::turnLoop, this);
}

void Game::turnLoop() {
	Move* move;
	while (true) {
		m_state->setActiveSide(Side::WHITE);
		move = m_white->requestMove(m_state);
		m_state->applyMove(move);
		m_state->setActiveSide(Side::BLACK);
		move = m_black->requestMove(m_state);
		m_state->applyMove(move);
	}
}

Player * Game::getActivePlayer() const
{
	Side activeSide = m_state->getActiveSide();
	return activeSide == Side::WHITE ? m_white : m_black;
}

void Game::update(float deltaTime) {
	/*if (!m_animationState) {
		Move* move = m_currentPlayer->requestMove(m_pieces);
		if (move != nullptr) {
			Vector2f startPosition = FieldUtils::fieldToCoord(move->getPiece()->getField());
			move->execute(&m_pieces);
			Vector2f endPosition = FieldUtils::fieldToCoord(move->getPiece()->getField());
			Sprite* s = move->getPiece()->getSprite();
			m_animation = new Animation(s, startPosition, endPosition);
			m_animationState = true;
			if (m_currentPlayer == m_white) {
				m_currentPlayer = m_black;
			}
			else {
				m_currentPlayer = m_white;
			}
		}
	}
	else {
		m_animation->update(deltaTime);
		if (m_animation->hasFinished()) {
			m_animationState = false;
		}
	}*/
}

template<typename Base, typename T>
inline bool instanceof(const T *ptr) {
	return dynamic_cast<const Base*>(ptr) != nullptr;
}

void Game::draw(RenderTarget & target, RenderStates states) const {

	//Draw chessboard
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++) {
			RectangleShape* square = new RectangleShape();
			square->setPosition(x*Piece::PIECE_SIZE, y*Piece::PIECE_SIZE);
			square->setSize(Vector2f(Piece::PIECE_SIZE, Piece::PIECE_SIZE));
			if ((x + y) % 2 == 0) {
				square->setFillColor(Color(74, 165, 74));
			}
			else {
				square->setFillColor(Color(231, 231, 198));
			}
			target.draw(*square);
			delete square;
		}
	}

	//Draw player objects
	Player* activePlayer = getActivePlayer();
	if (instanceof<HumanPlayer>(activePlayer)) {
		HumanPlayer* human = dynamic_cast<HumanPlayer*>(activePlayer);
		target.draw(*human);
	}

	//Draw pieces
	std::list<Piece*> pieces = m_state->getPieces();
	std::list<Piece*>::iterator it;
	for (it = pieces.begin(); it != pieces.end(); ++it) {
		Sprite* sprite = (*it)->getSprite();
		if (!m_animationState) {
			sprite->setPosition((*it)->getField().x*Piece::PIECE_SIZE, (7 - (*it)->getField().y)*Piece::PIECE_SIZE);
		}
		target.draw(*sprite);
	}
}

bool Game::checkmate() {
	return false;
}

