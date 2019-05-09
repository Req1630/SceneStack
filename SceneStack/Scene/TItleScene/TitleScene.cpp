#include "TitleScene.h"

clsTitleScene::clsTitleScene( clsSceneManager& sceneManager )
	: clsSceneBase ( sceneManager )
{}

clsTitleScene::~clsTitleScene()
{}

void clsTitleScene::Updata()
{
	if( GetAsyncKeyState( VK_RETURN ) &0x01 ){
		m_SceneManager.Change( new clsGameScene( m_SceneManager ) );
		g_clsConsole.Clear( 10, 2, "　　　　" );
	}
}
void clsTitleScene::Draw()
{
	g_clsConsole.SetColor( 
		static_cast<int>(clsConsole::enColor::L_YELLOW),
		static_cast<int>(clsConsole::enColor::L_BLUE) );
	g_clsConsole.Draw( 10, 2, "タイトル" );
}