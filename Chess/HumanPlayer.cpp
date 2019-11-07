#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(Side white, RenderWindow* renderWindow) : Player(white){
	m_renderWindow = renderWindow;
	m_clicked = false;
	m_availableMovesShapes = std::list<Shape*>();
}

HumanPlayer::~HumanPlayer() {
}

Move* HumanPlayer::requestMove(GameState* state) {
	Move* result = 0;
	std::list<Piece*> pieces = state->getPieces();
	while (!result) {
		//Is mouse is not pressed, do not do anything
		if (!Mouse::isButtonPressed(Mouse::Button::Left)) {
			m_clicked = false;
		}
		//If mouse clicked
		else if (Mouse::isButtonPressed(Mouse::Button::Left) && !m_clicked) {
			m_clicked = true;
			bool selected = false;
			Vector2i mousePosition = Mouse::getPosition(*m_renderWindow);
			Field field = FieldUtils::coordToField(mousePosition);
			for (std::list<Piece*>::iterator it = pieces.begin(); it != pieces.end(); ++it) {
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
				m_availableMoves = m_selectedPiece->getAvailableFields(state);
				m_availableMovesShapes.clear();
				if (m_availableMoves.size() != 0) {
					for (std::list<Field>::iterator it = m_availableMoves.begin(); it != m_availableMoves.end(); ++it) {
						if (!state->occupied(*it)) {
							CircleShape* shape = new CircleShape();
							shape->setFillColor(Color(100, 100, 100, 100));
							shape->setRadius(5);
							shape->setPosition(FieldUtils::fieldToCoord((*it)) + Vector2f(Piece::PIECE_SIZE / 2 - shape->getRadius(), Piece::PIECE_SIZE / 2 - shape->getRadius()));
							m_availableMovesShapes.push_back(shape);
						}
						else {
							RectangleShape* shape = new RectangleShape();
							shape->setFillColor(Color(0, 0, 0, 0));
							shape->setSize(Vector2f(Piece::PIECE_SIZE, Piece::PIECE_SIZE));
							shape->setOutlineColor(Color(100, 100, 100, 100));
							shape->setOutlineThickness(5.0f);
							shape->setPosition(FieldUtils::fieldToCoord((*it)));
							m_availableMovesShapes.push_back(shape);
						}
					}
				}
			}
			else {
				for (std::list<Field>::iterator it = m_availableMoves.begin(); it != m_availableMoves.end(); ++it) {
					if ((*it).x == field.x && (*it).y == field.y) {
						result = new Move(m_selectedPiece, (*it));
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
		m_selectedPieceShape->setPosition(FieldUtils::fieldToCoord(m_selectedPiece->getField()));
		m_renderWindow->draw(*m_selectedPieceShape);
		if (m_availableMoves.size() != 0) {
			for (std::list<Shape*>::iterator it = m_availableMovesShapes.begin(); it != m_availableMovesShapes.end(); ++it) {
				m_renderWindow->draw(**it);
			}
		}
	}
}