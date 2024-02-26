#include "RankingDispScene.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"

RankingDispScene::RankingDispScene() : background_image(NULL), ranking(nullptr)
{

}
RankingDispScene::~RankingDispScene()
{

}
//�摜�̓ǂݍ���
background_image = LoadGraph("Resource/images/Ranking.bmp");

//�G���[�`�F�b�N

if(background_image == -1)
{
	throw("Resource/images/Ranking.bmp������܂���\n");

}
//�����L���O�����擾
ranking = new RankingData;
ranking->Initialize();
}

//�X�V����
eSceneType RankingDispScene::Update()
{
	//B�{�^���������ꂽ��A�^�C�g���ɖ߂ǂ�
	if (InputControl::GetButtonDown(XINPUT_BUTTON_B))
	{
		return eSceneTyoe::E_TITLE;
	}
	//�`�揈��
	void RankingDispScene::Draw() const
	{
		//�w�i�摜�̕`��
		DrawGraoh(0, 0, bacground_image, FALSE);

		//�擾���������L���O�f�[�^��`�悷��
		for (int i = 0; i < 5; i++)

		{
			DrawFormatString(50, 170 + i * 25, 0fffff, "%2d %-15s %6d",
				ranking->GetRank(i), ranking->GetName(i), ranking->GetScore(i));
		}
	}

	//�I��������
	void RankingDipScene::Finalize()
	{
		//�ǂ񂾉摜�̏���
		DeleteGraph(bacground_image);

		//���I�������̊J��
		ranking->Finalize();
		delete ranking;
	}
	//���݂̃V�[�������擾
	cSceneType RankingDispScene::GetNowScene() const
	{
		return eSceneType::E_RANKING_DISP;
	}