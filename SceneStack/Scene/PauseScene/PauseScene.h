#ifndef PAUSE_SCENE
#define PAUSE_SCENE

#include "..\SceneBase\SceneBase.h"
#include "..\GameScene\GameScene.h"

class clsPauseScene : public clsSceneBase
{
public:
	clsPauseScene( clsSceneManager& sceneManager );
	~clsPauseScene();

	void Updata() override;
	void Draw() override;
};

#endif // #ifndef PAUSE_SCENE.