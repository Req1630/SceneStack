#include "PauseScene.h"

clsPauseScene::clsPauseScene( clsSceneManager& sceneManager )
	: clsSceneBase( sceneManager )
{
}
clsPauseScene::~clsPauseScene()
{}

void clsPauseScene::Updata()
{
	if( GetAsyncKeyState( VK_RETURN ) & 0x01 ){
		m_SceneManager.Pop();
		g_clsConsole.Clear( 10, 2, "　　　　" );
	}
}

void clsPauseScene::Draw()
{
	g_clsConsole.SetColor(
		static_cast<int>( clsConsole::enColor::L_RED ),
		static_cast<int>( clsConsole::enColor::L_BLUE ) );
	g_clsConsole.Draw( 10, 2, "ポーズ" );
}