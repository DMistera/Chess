#include "Game.h"


Game::Game() {
	m_animationState = false;

	//Initialize chessboard
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++) {
			RectangleShape square;
			square.setPosition(x*Piece::PIECE_SIZE, y*Piece::PIECE_SIZE);
			square.setSize(Vector2f(Piece::PIECE_SIZE, Piece::PIECE_SIZE));
			if ((x + y) % 2 == 0) {
				square.setFillColor(Color(74, 165, 74));
			}
			else {
				square.setFillColor(Color(231, 231, 198));
			}
			m_chessBoard.push_back(square);
		}
	}

	//Initalize exit button
	m_exitButton = new Button(Vector2f(100.0f, 50.0f), Vector2f(AppConsts::getScreenWidth() - 75.0f, AppConsts::getScreenHeight() - 50.0f), "Exit");
	m_exitButton->setCallback([&]() {
		if (m_onExit) {
			m_onExit();
		}
	});

	//Initialize error text
	m_text.setFont(*FontManager::getDefaultFont());
	m_text.setCharacterSize(20);
	m_text.setPosition(Vector2f(AppConsts::getScreenWidth()/2.0f - 100.0f, AppConsts::getScreenHeight() - 50.0f));
	SpriteUtils::centerOrigin(&m_text);
}

void Game::turnLoop() {
	Move* move;
	while (true) {
		showMessage(whitePlayerMessage());
		m_state.setActiveSide(Side::WHITE);
		move = m_white->requestMove(m_state);
		if (!move) {
			break;
		}
		m_state.applyMove(move);
		afterPlayerTurn(Side::WHITE);
		if (m_state.checkMate(Side::BLACK)) {
			showMessage("White won!");
			m_exitable = true;
			break;
		}
		showMessage(blackPlayerMessage());
		m_state.setActiveSide(Side::BLACK);
		move = m_black->requestMove(m_state);
		if (!move) {
			break;
		}
		m_state.applyMove(move);
		afterPlayerTurn(Side::BLACK);
		if (m_state.checkMate(Side::WHITE)) {
			showMessage("Black won!");
			m_exitable = true;
			break;
		}
	}
}

Player * Game::getActivePlayer() const
{
	Side activeSide = m_state.getActiveSide();
	return activeSide == Side::WHITE ? m_white : m_black;
}

void Game::update(float deltaTime) {
	m_text.setFillColor(m_textColor);
	m_text.setString(m_textString);
	SpriteUtils::centerOrigin(&m_text);
	if (m_exitable) {
		m_exitButton->update(deltaTime);
	}
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

void Game::drawFrame(RenderTarget & target, RenderStates states) const {

	//Draw chessboard
	for (RectangleShape rect : m_chessBoard) {
		target.draw(rect);
	}

	//Draw player objects
	Player* activePlayer = getActivePlayer();
	if (instanceof<HumanPlayer>(activePlayer)) {
		HumanPlayer* human = dynamic_cast<HumanPlayer*>(activePlayer);
		target.draw(*human);
	}

	//Draw pieces
	std::list<Piece*> pieces = m_state.getPieces();
	for (Piece* piece : pieces) {
		Sprite* sprite = piece->getSprite();
		if (!m_animationState) {
			Field f = piece->getField();
			if (m_reversed) {
				f.reverse();
			}
			sprite->setPosition(f.x*Piece::PIECE_SIZE, (7 - f.y)*Piece::PIECE_SIZE);
		}
		target.draw(*sprite);
	}

	//Draw side panel
	target.draw(m_text);
	if (m_exitable) {
		target.draw(*m_exitButton);
	}
}

void Game::initPlayers()
{
	m_white = createWhitePlayer();
	m_black = createBlackPlayer();
	m_turnsThread = new std::thread(&Game::turnLoop, this);
}

void Game::onExit(std::function<void()> f)
{
	m_onExit = f;
}

void Game::showError(String message)
{
	m_textColor = Color::Red;
	m_textString = message;
	m_exitable = true;
}

void Game::showMessage(String message)
{
	m_textColor = Color::White;
	m_textString = message;
}

bool Game::checkmate(Side side) {
	return false;
}

