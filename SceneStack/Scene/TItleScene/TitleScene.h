#ifndef TITLE_SCENE_H
#define TITLE_SCENE_H

#include "..\SceneBase\SceneBase.h"
#include "..\GameScene\GameScene.h"

class clsTitleScene : public clsSceneBase
{
public:
	clsTitleScene( clsSceneManager& sceneManager );
	~clsTitleScene();

	void Updata() override;
	void Draw() override;
};

#endif // #ifndef TITLE_SCENE_H.