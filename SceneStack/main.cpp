#include "Scene/Scenes/Scenes.h"

int main()
{
	scene::CSceneBase::sceneManager_s m_pSceneManager;
	m_pSceneManager = std::make_shared<scene::CSceneManager>();
	m_pSceneManager->Push( std::make_shared<CGameScene>(m_pSceneManager) );

	m_pSceneManager->Update();
	m_pSceneManager->Render();

	m_pSceneManager->StackRelease();

	return 0;
}