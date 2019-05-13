#ifndef TITLE_SCENE_H
#define TITLE_SCENE_H

#include "..\SceneBase\SceneBase.h"
#include "..\GameScene\GameScene.h"
#include "..\PauseScene\PauseScene.h"

class clsTitleScene : public clsSceneBase
{
public:
	clsTitleScene( shared_ptr<clsSceneManager> sceneManager );
	~clsTitleScene();

	void Updata() override;
	void Draw() override;

	int i = 0;
};

#endif // #ifndef TITLE_SCENE_H.