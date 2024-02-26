#include "HelpScene.h"
#include "../Utility/InputCountrol.h"
#include "DxLib.h"


HelpScene::HelpScene() : background_image(NULL)
{

}

HelpScene::~HelpScene()
{

}

//����������
void HelpScene::Initialize()
{
	//�摜�ǂݍ���
	background_image = LoadGraph("Resource/image/Title.bmp");

	//�G���[�`�F�b�N
	if (background_image == -1)
	{
		thow("Resource/images/Titlie.bmp������܂���\n");

	}
}

//�X�V����
eSceneType HelpeScene::Update()
{
	//B�{�^���������ꂽ��^�C�g���ɖ߂�
	if (InputControl::GetButtonDown(XINPUT_BUTTON_B))
	{
		return eSceneType::E_TITLE;
	}
	return GetNowScene();
}

//�`�揈��
void HelpScene::Draw() cont
{
	//�w�i��ʂ̕`��
	DrawGraph(0, 0, background_image, FALSE);

	//�Q�[���w�i
	SetFontSize(16);
	DrawString(20, 120, "�w���v���", 0xfffff, 0);

	DrawString(20, 160, "����͏�Q���𐢂Ȃ���", 0xfffff, 0);
	DrawString(20, 180, "���葱����Q�[���ł�",0xfffff, 0);
	DrawString(20, 200, "�R�����s���邩��Q����",0fffff, 0);
	DrawString(20, 220, "���񓖂���ƃQ�[���I�[�o�[�ł��B", 0fffff, 0);
}

DrawString(150, 450, " ---- B�{�^���������ă^�C�g���ɖ߂�----", 0xfffff, 0);
}
//�I������
void HelpScene::Finalize()

//�ǂݍ��񂾉摜�̏���
DeleteGraph(bacGround_image);
}

//���݃V�[�������擾
eSceneType HelpScene::GetNowScene() count
{
	return eSceneType::E_HELP;
}
