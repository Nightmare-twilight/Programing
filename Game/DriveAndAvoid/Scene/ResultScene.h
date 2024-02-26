


#include"ResultScene.h"
#include"../Object/RankingData.h"
#include"../Utility/InputControl.h"
#include"DxLib.h"
ResultScene::ResultScene() :back_ground(NULL), score(0)
{
	for (int i = 0; i < 3; i++)
	{
		enemy_image[i] = NULL;
		enemy_count[i] = NULL;
	}
}
ResultScene::~ResultScene()
{
}
//����������
void ResultScene::Initialize()
{
	//�摜�̓Ǎ�
	back_ground = LoadGraph("Resource/images/back.bmp");
	int result = LoadDivGraph("Resource/images/car.bmp", 3, 3, 1, 63, 120,
		enemy_image);
	//�G���[�`�F�b�N
	if (back_ground == -1)
	{
		throw("Resource/images/back.bmp������܂���\n");
	}
	if (result == -1)
	{
		throw("Resource/images/car.bmp������܂���\n");
	}
	//�Q�[�����ʂ̓Ǎ�
	ReadResultData();
}

//�X�V����

eSceneType ResultScene::Update()
{
	//B�{�^���Ń����L���O�ɑJ�ڂ���
	if (InputControl::GetButton(XINPUT_BUTTON_B))
	{
		return eSceneType::E_RANKING_INPUT;
	}
	return GetNowScene();
}
//�`�揈��
void ResultScene::Draw() const
{
	//�w�i�摜��`��
	DrawGraph(0, 0, back_ground, TRUE);
	//�X�R�A���\���̈�
	DrawBox(150, 150, 490, 330, GetColor(0, 153, 0), TRUE);
	DrawBox(150, 150, 490, 330, GetColor(0, 0, 0), FALSE);
	DrawBox(500, 0, 640, 480, GetColor(0, 153, 0), TRUE);
	SetFontSize(20);
	DrawString(220, 170, "�Q�[���I�[�o�[", GetColor(204, 0, 0));
	SetFontSize(16);
	DrawString(180, 200, "���s����", GetColor(0, 0, 0));
	for (int i = 0; i < 3; i++)
	{
		DrawRotaGraph(230, 230 + (i * 20), 0.3f, DX_PI_F / 2, enemy_count[i], TRUE);
		DrawFormatString(260, 222 + (i * 21), GetColor(255, 255, 255), " %6d x %4d = %6d",
			enemy_count[i], (i + 1) * 50, (i + 1) * 50 * enemy_count[i]);
	}
	DrawString(180, 290, "�X�R�A", GetColor(0, 0, 0));
	DrawFormatString(180, 290, 0xFFFFFF, "		=%6d", score);
}
//�I��������
void ResultScene::Finalize()
{
	//�ǂݍ��񂾉摜�̍폜
	DeleteGraph(back_ground);
	for (int i = 0; i < 3; i++)
	{