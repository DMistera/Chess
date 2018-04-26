#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(Side white, RenderWindow* renderWindow) : Player(white){
	m_renderWindow = renderWindow;
	m_clicked = false;
	m_availableMovesShapes = std::list<CircleShape*>();
}

HumanPlayer::~HumanPlayer() {
}

bool HumanPlayer::move(std::list<Piece*>* pieces) {
	bool result = false;
	//Is mouse is not pressed, do not do anything
	if (!Mouse::isButtonPressed(Mouse::Button::Left)) {
		m_clicked = false;
	}
	//If mouse clicked
	if (Mouse::isButtonPressed(Mouse::Button::Left) && !m_clicked) {
		m_clicked = true;
		bool selected = false;
		Vector2i mousePosition = Mouse::getPosition(*m_renderWindow);
		Field field = coordToField(mousePosition);
		for (std::list<Piece*>::iterator it = pieces->begin(); it != pieces->end(); ++it) {
			if ((*it)->getSide() == m_side) {
				Field f = (*it)->getField();
				if (f.x == field.x && f.y == field.y) {
					m_selectedPiece = (*it);
					selected = true;
					break;
				}
			}
		}
		if (selected) {
			m_availableMoves = m_selectedPiece->getAvailableFields(pieces);
			m_availableMovesShapes.clear();
			if (m_availableMoves.size() != 0) {
				for (std::list<Field>::iterator it = m_availableMoves.begin(); it != m_availableMoves.end(); ++it) {
					CircleShape* shape = new CircleShape();
					shape->setFillColor(Color(100, 100, 100, 100));
					shape->setRadius(5);
					shape->setPosition(fieldToCoord((*it)) + Vector2f(Piece::PIECE_SIZE / 2 - shape->getRadius(), Piece::PIECE_SIZE / 2 - shape->getRadius()));
					m_availableMovesShapes.push_back(shape);
				}
			}
		}
		else {
			for (std::list<Field>::iterator it = m_availableMoves.begin(); it != m_availableMoves.end(); ++it) {
				if ((*it).x == field.x && (*it).y == field.y) {
					makeMove(m_selectedPiece, (*it));
					result = true;
					break;
				}
			}
			delete m_selectedPieceShape;
			m_selectedPieceShape = 0;
			m_selectedPiece = 0;
			m_availableMoves.clear();
			m_availableMovesShapes.clear();
		}
	}
	return result;
}

void HumanPlayer::draw() {
	if (m_selectedPiece != 0 && m_selectedPieceShape == 0) {
		m_selectedPieceShape = new CircleShape();
		m_selectedPieceShape->setRadius(Piece::PIECE_SIZE / 2);
		m_selectedPieceShape->setFillColor(Color(100, 100, 100, 100));
	}
	if (m_selectedPieceShape != 0) {
		m_selectedPieceShape->setPosition(fieldToCoord(m_selectedPiece->getField()));
		m_renderWindow->draw(*m_selectedPieceShape);
		if (m_availableMoves.size() != 0) {
			for (std::list<CircleShape*>::iterator it = m_availableMovesShapes.begin(); it != m_availableMovesShapes.end(); ++it) {
				m_renderWindow->draw(**it);
			}
		}
	}
}

Field HumanPlayer::coordToField(Vector2i coords) {
	int x = coords.x / Piece::PIECE_SIZE;
	int y = coords.y / Piece::PIECE_SIZE;
	y = 7 - y;
	return Field(x, y);
}

Vector2f HumanPlayer::fieldToCoord(Field field) {
	float x = field.x*Piece::PIECE_SIZE;
	float y = (7 - field.y)*Piece::PIECE_SIZE;
	return Vector2f(x, y);
}
