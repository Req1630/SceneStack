#include "GameScene.h"

clsGameScene::clsGameScene( clsSceneManager& sceneManager )
	: clsSceneBase ( sceneManager )
{
}
clsGameScene::~clsGameScene()
{}

void clsGameScene::Updata()
{
	if( GetAsyncKeyState( VK_RETURN ) &0x01 ){
		m_SceneManager.Change( new clsTitleScene( m_SceneManager ) );
	}
	if( GetAsyncKeyState( VK_SHIFT ) & 0x01 ){
		m_SceneManager.Push( new clsPauseScene( m_SceneManager ) );
	}
}

void clsGameScene::Draw()
{
	g_clsConsole.SetColor( 
		static_cast<int>(clsConsole::enColor::L_GREEN),
		static_cast<int>(clsConsole::enColor::L_RED) );
	g_clsConsole.Draw( 10, 2, "ÉQÅ[ÉÄ" );
}