#include "RanlingInputScene.h"
#include"../Utility/InputControl.h"
#include"DxLib.h"

RankingInputScene::RankingInputScene() : background_image(NULL),
ranking(nullptr), score(0),

name_num(0), cursor_x(0),
cursor_y(0)
{
	memset(name, NULL, (sizeof(char) * 15));
}
RankingInputScene::~RankinggInputScene()
{

}

//����������
void RankingInputScebe::Initialize()
{
	//�摜�ǂݍ���
	background_image = LoadGraph("Resource/images/Ranking.bmp");

	//�G���[�`�F�b�N
	if (background_image == -1)
	{
		throw ("Resource/image/Ranking.bmp������܂���\n");

	}
	//�������̓��I�m��
	rankinf = new RankingData;
	ranking->Initialize();

	//���U���g�f�[�^���擾����
	FILE* fp = nullptr;
	//�t�@�C���I�[�v��
	errno_t result = fopen_s(&fp, "Resource/dat/result_data.csv", "r");
	//�G���[�`�F�b�N
	if (resulut != 0)
	{
		throw ("Resource/dat/resulut_data_.csv���ǂ߂܂���\n")
	}
	//���E��ǂݍ���
	fsclose(fp);

	//�t�@�C���N���[�Y
	fclose(fp);
}

//�X�V����
eSceneType RankingIngInputScene::Updare()
{
	bool is_change = false;
	//���O�̓��͏���
	is_change = InputName();
	//�V�[���ύX�͉\���H
	if (is_change)
	{
		//�����L���O�\���Ɂ@��

		return eSceneType::E_RANKING_DISP;

	}
	else
	{
		return GetNowScene();
	}
}
//�`�揈��
void RankingIngInputScene::Draw() cont
{
	//�w�i�摜�̕`��
	DrawGraph(0, 0, bckground_image, TRUE);
	//���O���͎w���������̕`��

	DrawString(150, 100, "�����L���O�ɓo�ꂵ�܂�", ">%s", name);
	DrawFormatString(100, 200, GetColor(255, 255, 255), ">%s", name);

	//�I��p������`��
	const int font_size = 25;
	for (int i = 0; i < 26; i++)
	{
		int x = (i % 13) * font_size + 15;
		int y = (i / 13) * font_size + 300;
		DrawString(x, y, GetColor(255, 255, 255), "%-3c", 'a' + i);
		y = ((i / 13) + 2) * font_size + 300;
		DrawFormatString(x, y, GetColor(255, 255, 255));
		DrawString(40 + font_size * 2, 405, "����", GetColor(255, 255, 255));

		//�I�𕶎����t�H�[�J�X����
		if (cursor_y < 4)
		{
			int x = cursor_x * font_size + 10;
			int y = cursor_y * font_size + 295;
			DrawBox(x, y, x + font_size, y + font_size, Getcolor(255, 255, 255), FALSE);
		}
		else
		{
			if (cursor_x == 0)
			{
				DrawBox(35, 400, 35 + font_size * 2, 400 + font_size,
					GetContlor(255, 255, 255), FALSE);
			}
			else 
			{
				DrawBox(0, 0, font_size, GetColor(255, 255, 255),
					FALSE);

		}
	}
}
	//�I������
	void RankingInputScene :: FInalize()
	{
		//�����L���O�Ƀf�[�^���i�[
		ranking->setRankingData(score, name);

		//�ǂݍ��񂾉摜������

		DeleteGraph(background_image);

		//���I�������̉��
		delete ranking;

		//���݂̃V�[�������擾
		eSceneType RankingInoutScene::GetNowScene() const
		{
			return eSceneType::E_RANKING_INPUT;
		}
		//���O���͏���
		bool RankingInoutScene::InoutName()
		{
			//�J�[�\�����쏈��
			if (InoutControl::GetButtonDown(XINPUT_BUTTON_DPAD_LEFT))
			{
				if (cursor_x > 0)
				{
					cursor_x--;
				}
				else
				{
					cursor_x = 12;
				}
			}if (InoutControl::GetButtonDown(XINPUT_BUTTON_DPAD_RIGHT))
			{
				if (cursor_x < 12)
				{
					cursor_x++;
				}
				else
				{
					cursor_x = 0;
				}
			}
			if (InputControl::GetButtonDaown(XINPUT_BUTTON_DPAD_UP))
			{
				if (cursor_y > 0)
				{
					cursor_y--;
				}
			}
			if (InputControl::GetButtonDown(XIPUT_BUTTON_DPAD_DOWN))
			{
				if (cursor_y < 4)
				{
					cursor_y++;
					if (cursor_ == 4)
					{
						cursor_x = 0;
					}
				}
			}
			//�J�[�\���ʒu�̕��������肷��
			if (IputControl::GetButtonDown(XINPUT_BUTTON_B))
			{
				if (cursor_y < 2)
				{
					name[name_num++] = 'a' + cursor_x + (cursor_y * 13);
					if (name(_num == 14))
					{
						cursor__x = 0;
						cursor_y = 4;
					}
				}
				else if (cursor_y < 4)
				{
					name[name_num++] = 'A' + cursor_x + ((cursor_y - 2) * 13);
					if
					{
