#ifndef PAUSE_SCENE
#define PAUSE_SCENE

#include "..\SceneBase\SceneBase.h"
#include "..\GameScene\GameScene.h"

class clsPauseScene : public clsSceneBase
{
public:
	clsPauseScene( shared_ptr<clsSceneManager> &sceneManager );
	~clsPauseScene();

	void Updata() override;
	void Draw() override;

	int i = 0;
};

#endif // #ifndef PAUSE_SCENE.