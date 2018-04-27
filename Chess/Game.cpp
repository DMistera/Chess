#include "Game.h"


Game::Game(RenderWindow * renderwindow) {
	m_renderWindow = renderwindow;
	m_white = new HumanPlayer(Side::WHITE, m_renderWindow);
	m_black = new HumanPlayer(Side::BLACK, m_renderWindow);
	m_currentPlayer = m_white;
	m_pieces = std::list<Piece*>();
	m_animationState = false;

	//Set up a starting board
	//Pawns
	for (int i = 0; i < 8; i++) {
		Pawn* whitePawn = new Pawn(Side::WHITE);
		whitePawn->initializeSprite();
		whitePawn->setField(Field(i, 1));
		m_pieces.push_back(whitePawn);

		Pawn* blackPawn = new Pawn(Side::BLACK);
		blackPawn->initializeSprite();
		blackPawn->setField(Field(i, 6));
		m_pieces.push_back(blackPawn);
	}

	//Kings
	for (int i = 0; i < 2; i++) {
		int y = i == 0 ? 0 : 7;
		Side side = i == 0 ? Side::WHITE : Side::BLACK;
		King* king = new King(side);
		king->initializeSprite();
		king->setField(Field(4, y));
		m_pieces.push_back(king);
	}
}

void Game::update(double deltaTime) {
	if (!m_animationState) {
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
	}
}

template<typename Base, typename T>
inline bool instanceof(const T *ptr) {
	return dynamic_cast<const Base*>(ptr) != nullptr;
}

void Game::draw() {

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
			m_renderWindow->draw(*square);
			delete square;
		}
	}

	//Draw player objects
	if (instanceof<HumanPlayer>(m_currentPlayer)) {
		HumanPlayer* human = dynamic_cast<HumanPlayer*>(m_currentPlayer);
		human->draw();
	}

	//Draw pieces
	std::list<Piece*>::iterator it;
	for (it = m_pieces.begin(); it != m_pieces.end(); ++it) {
		Sprite* sprite = (*it)->getSprite();
		if (!m_animationState) {
			sprite->setPosition((*it)->getField().x*Piece::PIECE_SIZE, (7 - (*it)->getField().y)*Piece::PIECE_SIZE);
		}
		m_renderWindow->draw(*sprite);
	}
}

bool Game::checkmate() {
	return false;
}

