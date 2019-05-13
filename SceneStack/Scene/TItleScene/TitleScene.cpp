#include "TitleScene.h"

clsTitleScene::clsTitleScene( shared_ptr<clsSceneManager> sceneManager )
	: clsSceneBase ( sceneManager )
{
}

clsTitleScene::~clsTitleScene()
{
	printf( "�^�C�g���̃f�X�g���N�^���Ă΂�܂���\n" );
}

void clsTitleScene::Updata()
{
	if( GetAsyncKeyState( VK_RETURN ) &0x01 ){
		m_pSceneManager->Change( make_shared<clsGameScene>( m_pSceneManager ) );

	}
}
void clsTitleScene::Draw()
{
	if( i == 0 ){
		printf( "�^�C�g��\n" );
		i++;
	}
}