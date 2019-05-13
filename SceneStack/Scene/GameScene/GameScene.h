#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include "..\SceneBase\SceneBase.h"
#include "..\TItleScene\TitleScene.h"

class clsGameScene : public clsSceneBase
{
public:
	clsGameScene( shared_ptr<clsSceneManager> &sceneManager );
	~clsGameScene();

	void Updata() override;
	void Draw() override;

	int i = 0;
};

#endif // #ifndef GAME_SCENE_H.