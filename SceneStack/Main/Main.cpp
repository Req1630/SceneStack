#include "..\Scene\SceneManager\SceneManager.h"
#include "..\Scene\TItleScene\TitleScene.h"

int main()
{
	clsSceneManager* pSceneManager;
	pSceneManager = new clsSceneManager();
	pSceneManager->Push( new clsTitleScene( *pSceneManager ) );

	while(1)
	{
		pSceneManager->Update();
		pSceneManager->Draw();
	}

	delete pSceneManager;
	return 0;
}