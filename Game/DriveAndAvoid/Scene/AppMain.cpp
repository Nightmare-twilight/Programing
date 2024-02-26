/******************************
*�Ԕ�����Q�[��������Ă݂悤�I
***********************************/

#include "DxLib.h"
#include "Scene/ScneManager.h"

//���C���֐��i�v���O�����͂�������n�܂�܂��B�j
int WINAPI WinMain(_In_HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_LPSTR lpCmdLine, _In_int nCmdShow)

{
	//��O�����i�ُ킪����������Acatch���ɔ�т܂��B�j
	try
	{
		//�V�[���}�l�[�W���[�@�\�̐���
		SceneManager manager;

		//�V�[���}�l�[�W���[�@�\�̏���������
		manager.Initialize();

		//�V�[���}�l�[�W���[�@�\�̍X�V����
		manager.Update();

		//�V�[���}�l�[�W���[�@�\�̏I������
		manager.Finalize();

	}
	catch (const char* err_log)
	{
		//�G���[�������e�̏o��
		outputDebugstring(err_kog);

		//�G���[�I����ʒm
		return -1;

	}

	//����I����ʒm
	return 0;
}