#include "..\Scene\SceneManager\SceneManager.h"
#include "..\Scene\TItleScene\TitleScene.h"

int main()
{
	// ���������[�N���o
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );

	// "shared_ptr" �̏������� "make_shared" ���g��.
	shared_ptr<clsSceneManager> pSeneManager = make_shared<clsSceneManager>();
	// TitleScene�� "make_shared" �ō쐬���ăv�b�V��.
	pSeneManager->Push( make_shared<clsTitleScene>( pSeneManager ) );

	while(1)
	{
		pSeneManager->Update();
		pSeneManager->Draw();
		if( GetAsyncKeyState( VK_ESCAPE ) & 0x01 ){
			break;
		}
	}
	// ���C�����[�v���I�������X�^�b�N�̒��g�����.
	pSeneManager->StackRelease();

	return 0;
}