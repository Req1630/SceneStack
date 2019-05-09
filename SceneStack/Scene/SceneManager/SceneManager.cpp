#include "SceneManager.h"

void clsSceneManager::Update()
{
	m_pScene.top()->Updata();
}
void clsSceneManager::Draw()
{
	m_pScene.top()->Draw();
}
void clsSceneManager::Push( clsSceneBase* pScenebase )
{
	m_pScene.emplace( pScenebase );
}
void clsSceneManager::Change( clsSceneBase* pScenebase )
{
	clsSceneManager::Pop();
	clsSceneManager::Push( pScenebase );
}
void clsSceneManager::Pop()
{
	m_pScene.pop();
}