#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "Piece.h"

enum class GameState
{
    Title,
    Ready,
    Playing,
    GameOver
};

// forward declarations
class Character;
class Piece;
enum class Side;

class MainScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init() override;

    // implement the "static create()" method manually
    CREATE_FUNC(MainScene);
    
private:
    void onEnter() override;
    void update(float dt) override;
    
    void setupTouchHandling();
    void resetGameState();
    
    void triggerTitle();
    void triggerReady();
    void triggerPlaying();
    void triggerGameOver();
    
    void stepTower();
    void animateHitPiece(Side obstacleSide);
    void setTimeLeft(float timeLeft);
    void setScore(int score);
    Side getSideForObstacle(Side lastSide) const;
    bool isGameOver() const;
    
    float timeLeft;
    int score;
    int pieceIndex;
    cocos2d::Vec2 flyingPiecePosition;
    Side lastObstacleSide;
    GameState gameState;
    
    cocos2d::Sprite* timeBar;
    cocos2d::ui::Text* scoreLabel;
    Character* character;
    cocos2d::Node* pieceNode;
    
    cocos2d::Vector<Piece*> pieces;
};

#endif // __MAIN_SCENE_H__
