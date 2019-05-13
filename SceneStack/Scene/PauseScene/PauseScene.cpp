#include "PauseScene.h"

clsPauseScene::clsPauseScene( shared_ptr<clsSceneManager> &sceneManager )
	: clsSceneBase( sceneManager )
{
}
clsPauseScene::~clsPauseScene()
{
	printf( "�|�[�Y�̃f�X�g���N�^���Ă΂�܂����B\n" );
}

void clsPauseScene::Updata()
{
	if( GetAsyncKeyState( VK_RETURN ) & 0x01 ){
		m_pSceneManager->Pop();
	}
}

void clsPauseScene::Draw()
{
	if( i == 0 ){
		printf( "�|�[�Y\n" );
		i++;
	}
}