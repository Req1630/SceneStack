#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include "..\SceneBase\SceneBase.h"
#include "..\TItleScene\TitleScene.h"

class clsGameScene : public clsSceneBase
{
public:
	clsGameScene( clsSceneManager& sceneManager );
	~clsGameScene();

	void Updata() override;
	void Draw() override;
};

#endif // #ifndef GAME_SCENE_H.