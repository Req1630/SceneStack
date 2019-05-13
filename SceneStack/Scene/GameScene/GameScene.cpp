#include "GameScene.h"

clsGameScene::clsGameScene( shared_ptr<clsSceneManager> &sceneManager )
	: clsSceneBase ( sceneManager )
{
}
clsGameScene::~clsGameScene()
{
	printf( "ゲームのデストラクタが呼ばれました。\n" );
}

void clsGameScene::Updata()
{
	if( GetAsyncKeyState( VK_RETURN ) &0x01 ){
		m_pSceneManager->Change( make_shared<clsTitleScene>( m_pSceneManager ) );
	}
	if( GetAsyncKeyState( VK_SHIFT ) & 0x01 ){
		m_pSceneManager->Push( make_shared<clsPauseScene>( m_pSceneManager ) );
	}
}

void clsGameScene::Draw()
{
	if( i == 0 ){
		printf( "ゲーム\n" );
		i++;
	}

}