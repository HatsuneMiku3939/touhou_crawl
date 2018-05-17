//////////////////////////////////////////////////////////////////////////////////////////////////
//
// �����̸�: help.cpp
//
// ����: ����
//
//////////////////////////////////////////////////////////////////////////////////////////////////


#include "environment.h"
#include "display.h"
#include "key.h"
#include "note.h"


extern HANDLE mutx;
extern display_manager DisplayManager;


void Help_Show()
{
	deletesub();

	bool loop_ = true;
	int input_;
	WaitForSingleObject(mutx, INFINITE);
	printsub("<���� ũ�� ���� ���>",true,CL_normal);
	printsub("",true,CL_normal);
	printsub("?. Ŀ�ǵ�",true,CL_normal);
	printsub(":. ���� ��Ʈ",true,CL_normal);
	printsub("0. ���丮",true,CL_normal);
	changedisplay(DT_SUB_TEXT);
	ReleaseMutex(mutx);
	while(loop_)
	{
		input_ = waitkeyinput(true);
		switch(input_)
		{
		case '?':
			WaitForSingleObject(mutx, INFINITE);
			deletesub();
			printsub("                                   --- Ŀ�ǵ� ��� ---",true,CL_normal);
			printsub("",true,CL_normal);
			printsub("<�̵�>                                             <����>",true,CL_normal);
			printsub("����Ű - ������ Ű�� ���� �����ϴ�                 M - ���� ���",true,CL_normal);
			printsub("�ء��    7 8 9    y k u                           z,Z - ���� ���",true,CL_normal);
			printsub("�硤�� <> 4 5 6 <> h . l                           I - ����ϰ��ִ� ���� Ȯ��",true,CL_normal);
			printsub("�ס��    1 2 3    b j n                           ",true,CL_normal);
			printsub("o   - �ڵ�Ž��                                     <ĳ���� ���� ���>",true,CL_normal);
			printsub("                                                   @ - ������ ĳ���� ����",true,CL_normal);
			printsub("<������ Ž��>                                      % - �ڼ��� ĳ���� ����",true,CL_normal);
			printsub("5      - 100�� �޽�                                ^ - �ž� ����",true,CL_normal);
			printsub("x      - ��ó ����                                 \\ - �ĺ��� ������ ����",true,CL_normal);
			printsub("s�Ǵ�. - 1�� �ѱ��                                A - ĳ���� Ư�� Ȯ��",true,CL_normal);
			printsub("X      - ���� ����                                 [ - �԰��ִ� ��� ǥ��",true,CL_normal);
			printsub("<,>    - ��� ������/��������                      } - ���� ���� ǥ��",true,CL_normal);
			printsub("O,C    - �� ����/�ݱ�                              \" - ���� ��ű� ǥ��",true,CL_normal);
			printsub("                                                   E - ����ġ ǥ��",true,CL_normal);
			printsub("                                                   m - ��ųâ ǥ��",true,CL_normal);
			printsub("<�����۰���>                                       ] - ȹ���� �� ǥ��",true,CL_normal);
			printsub("i      - ������ �ִ� ������                        ctrl-O - ���� ���൵ ǥ��",true,CL_normal);
			printsub("g�Ǵ�, - �������ִ� �������ݱ�                     ",true,CL_normal);
			printsub("d      - �����۹�����                              ",true,CL_normal);
			printsub("D      - ���� �ֱٿ� ���� �����۹�����             <����� Ŀ�ǵ�>",true,CL_normal);
			printsub("e      - �Ա�(����)                                ctrl-P - ���� �޼��� ����",true,CL_normal);
			printsub("r      - �б�(�η縶��,å)                         S - ���̺��� ����",true,CL_normal);
			printsub("q      - ���ñ�(����)                              ctrl-S - ���̺��� ����(������)",true,CL_normal);
			printsub("f/F    - ����/���� ������                          ctrl-Q - ���̺���� ����",true,CL_normal);
			printsub("v,V    - ����ī�� ���                             # - ���� �����ϱ�",true,CL_normal);
			printsub("w      - ��������( - Ű�� �Ǽ�)                    +/- - ���� ON/OFF (�ʱ⼳���� �ִ� ���)",true,CL_normal);
			printsub("W/T    - �� ����/����                          ",true,CL_normal);
			printsub("P/R    - ��ű� ����/����                          ",true,CL_normal);
			printsub("ctrl-A - �ڵ��ݱ� Ȱ��/����                        <ġƮ���>",true,CL_normal);
			printsub("\'      - a, b����Ű ���� �ٲٱ�                    & - ���ڵ���", true, CL_normal);
			printsub("                                                   _ - ���̺꺸�����",true,CL_normal);
			printsub("                                                   ",true,CL_normal);
			printsub("<�ɷ� ����>                                        ",true,CL_normal);
			printsub("p - �⵵                                           ",true,CL_normal);
			printsub("a - �Ǵ� Ȥ�� �ߵ��ɷ»��                         ",true,CL_normal);
			changedisplay(DT_SUB_TEXT);
			ReleaseMutex(mutx);
			break;
		case ':':
			{	
				WaitForSingleObject(mutx, INFINITE);
				deletesub();
				char temp[300];
				sprintf_s(temp,300,"%8s|%-18s|%s\n","��","���","����");
				printsub(temp,true,CL_normal);
				for(list<note_dummy>::iterator it = save_note.note_list.begin(); it != save_note.note_list.end(); it++)
				{
					sprintf_s(temp,300,"%8d|%-18s|%s",it->turn,it->place.c_str(),it->text.c_str());
					printsub(temp,true,it->color);
				}
				changedisplay(DT_SUB_TEXT);
				ReleaseMutex(mutx);	
				while(1)
				{
					switch(waitkeyinput(true))
					{
					case VK_UP:
						changemove(1);  //��
						continue;
					case VK_DOWN:
						changemove(-1); //�Ʒ�
						continue;
					case VK_PRIOR:
						changemove(DisplayManager.log_length);
						continue;
					case VK_NEXT:
						changemove(-DisplayManager.log_length);
						continue;
					case VK_ESCAPE:
						loop_ = false;
						break;
					default:
						continue;
					}
					break;
				}
			}
			break;
		case '0':
			WaitForSingleObject(mutx, INFINITE);
			deletesub();
			printsub("                                    --- ���丮 ---",true,CL_normal);
			printsub("ȯ������ ����ȭ�Ǿ���ȴ�!",true,CL_normal);
			printsub("",true,CL_normal);
			printsub("ȯ������ �ο���� �������� ��Ȳ��ȭ�� �޾Ƶ����� ���ϰ� �������� ���� ������ ������. ",true,CL_normal);
			printsub("",true,CL_normal);
			printsub("����� ȯ������ ������� �ǵ����������� ������ Ž���ϵ��� �����ߴ�. ",true,CL_normal);
			changedisplay(DT_SUB_TEXT);
			ReleaseMutex(mutx);
			break;
		//case '1':
		//	WaitForSingleObject(mutx, INFINITE);
		//	deletesub();
		//	printsub("                                   --- ������ ��� ---",true,CL_normal);
		//	printsub("�������� ����ũ��(�������)�� ����������Ʈ�� ���� �����Դϴ�.",true,CL_normal);
		//	printsub("",true,CL_normal);
		//	printsub("������ - joy1999",true,CL_normal);
		//	printsub("",true,CL_normal);
		//	printsub("������ - Visual C++ 2008 Express Edition",true,CL_normal);
		//	printsub("",true,CL_normal);
		//	printsub("���۾�� - C++(���̷�ƮX 9.0)",true,CL_normal);
		//	printsub("",true,CL_normal);
		//	printsub("���۱Ⱓ - ��",true,CL_normal);
		//	printsub("",true,CL_normal);
		//	printsub("",true,CL_normal);
		//	printsub("���: �̹� ������ ������ �ʾ����� ���ڴ�.",true,CL_normal);
		//	printsub("",true,CL_normal);
		//	printsub("Ȥ�� ���ӿ� ���õ� ���ǻ���, ����, ���׵���ؼ� ���Ͻð� �����Ű� �ִٸ� ������ ��α� �ּҷ� ���ּ���.",true,CL_normal);
		//	printsub("",true,CL_normal);
		//	printsub("http://joy1999.egloos.com/",true,CL_normal);
		//	printsub("",true,CL_normal);
		//	printsub("",true,CL_normal);
		//	printsub("�����մϴ�.",true,CL_normal);
		//	printsub("",true,CL_normal);
		//	changedisplay(DT_SUB_TEXT);
		//	ReleaseMutex(mutx);
		//	break;
		//case '2':
		//	WaitForSingleObject(mutx, INFINITE);
		//	deletesub();
		//	printsub("                                   --- �����ֽ� �е� ---",true,CL_normal);
		//	printsub("������ ����µ� ���� ������ �ֽ� ������ �е鿡�� ��� ����帳�ϴ�.",true,CL_normal);
		//	printsub("",true,CL_normal);
		//	printsub("",true,CL_normal);
		//	printsub("<�׽���>",true,CL_normal);
		//	printsub("�̼Ҹ���ũ, ����, ����̽�, Rian��iku, ����, Minacle, Zeroize, ī����",true,CL_normal); 
		//	printsub("TachibanaMiya, �̿�, Dhin, ������, ������, mystery, �ع�, �",true,CL_normal);
		//	printsub("",true,CL_normal);
		//	printsub("",true,CL_normal);
		//	printsub("<Ư�� ���� ������ �ֽźе�>",true,CL_normal);
		//	printsub("",true,CL_help);
		//	printsub("�̼Ҹ���ũ - ���� ��ȹ�� �����ֽ�.",true,CL_normal);
		//	printsub("",true,CL_help);
		//	printsub("���δ� - ���� ��ȹ�����ε� ���� �����ֽ�. ��Ʈ�� � ����ֽ�.",true,CL_normal);
		//	printsub("",true,CL_help);
		//	printsub("Rian��iku - ���� ���� ��ȣ��.",true,CL_normal);
		//	printsub("",true,CL_help);
		//	printsub("�̿�, ����̽� - �̹��� ũ�� ��ʸ�Ʈ ���� ����.",true,CL_normal);
		//	printsub("",true,CL_help);
		//	printsub("�׿��� #������õĢ, #����ũ�� ä�� �е� ��� �߰������� ����帲.",true,CL_normal);
		//	printsub("",true,CL_normal);
		//	printsub("�׸��� ���� �ٿ�޾Ƽ� �÷����Ͻ� �е� ��� �����.",true,CL_normal);
		//	printsub("",true,CL_normal);
		//	printsub("�׽����Ͻð������ �е��� ��α׿� ���⼼��. ũ�ѷ� ���, ���� �� ã�º� ���.",true,CL_normal);
		//	changedisplay(DT_SUB_TEXT);
		//	ReleaseMutex(mutx);
		//	break;
	/*	case '3':
			WaitForSingleObject(mutx, INFINITE);
			deletesub();
			changedisplay(DT_SUB_TEXT);
			printsub("                                   --- ��ü F A Q ---",true,CL_normal);
			printsub("Q. �� �� �ִ� �Ű� �žӽ��� ��� �����?",true,CL_help);
			printsub("   A. ī����, ���̸�, �������Դϴ�.",true,CL_normal);
			printsub("      ī����- ���� ���δ�. P�������� �⵵�Ѵ�.",true,CL_normal);
			printsub("      ���̸�- �͹��� ������ ������ ���Ŵ�. ���������� �⵵�Ѵ�. P�������� �⵵�Ѵ�.",true,CL_normal);
			printsub("      ����- ���� ��ų ����ġ�� ������ų�� �����Ѵ�.",true,CL_normal);
			printsub("",true,CL_normal);
			printsub("Q. �� �ΰ��� ���ฦ �Ȱ�� ���̹���?",true,CL_help);
			printsub("   A. ��Ʈ ����Դٺ��ϱ� �׷����ϴ�. ���� �������� ������ �°� ��Ʈ�� �ٲ�ϴ�.",true,CL_normal);
			printsub("",true,CL_normal);
			printsub("Q. ����ĳ���ʹ� �÷��̾�ĳ���ͷ� �÷����� �� ���Ե� ����?",true,CL_help);
			printsub("   A. �ƴմϴ�.",true,CL_normal);
			printsub("",true,CL_normal);
			printsub("Q. ��ũ�ΰ� ����. ctrl-G�� ����. �����ʿ� �κ�â�� ����. ���",true,CL_help);
			printsub("   A. ���� ũ�ѿ� ���ؼ� ������ ���� ���� �߰��س��� �����Դϴ�.",true,CL_normal);
			printsub("",true,CL_help);
			printsub("Q. ������������ �ʹ� ��Ȯ�ϰ� ���´�.",true,CL_help);
			printsub("   A. �Ŀ� �������� ����, ����, ���배�� �������� �ٲ� �����Դϴ�.",true,CL_normal);
			printsub("",true,CL_help);
			printsub("Q. �����װڴµ� ������ ����!",true,CL_help);
			printsub("   A. ����� ���¿��� c�� ������ p�� ��ĭ �Ҹ��Ͽ� ��⸦ ä�� �� �ֽ��ϴ�.",true,CL_normal);
			printsub("",true,CL_help);
			printsub("Q. ��ų ����ġ�� ���� �ʹ�.",true,CL_help);
			printsub("   A. ��α׿� �������Դϴ�. ���ӻ󿡼��� mŰ�� ��ų����ġ�� ���� ȭ�鿡�� !�� ������ ����ġ�� �ٲ�ϴ�.",true,CL_normal);
			printsub("",true,CL_help);
			printsub("Q. �� ���ӿ� ��ǥ�� ����?",true,CL_help);
			printsub("   A. ���� �̿ϼ��̶� ���ٸ� ��ǥ�� ������ �̹� �������� �䱫�ǻ� ������ ������ �����;��մϴ�.",true,CL_normal);
			printsub("",true,CL_help);
			printsub("Q. ��������� ����� �ٸ���ܰ� �����ϱ� �����.",true,CL_help);
			printsub("   A. �Ŀ� ��Ʈ�� �ٲ� �����Դϴ�. ����� ������ �������� ����� 4�� �̻��϶�",true,CL_normal);
			printsub("      �� �� �ϳ��� ������� ����̶�� ���ø�˴ϴ�.",true,CL_normal);
			printsub("      ���� �ƹ��� ã�Ƶ� ������ ���״� �Ű����ּ���.",true,CL_normal);
			printsub("",true,CL_help);
			printsub("Q. Ÿ��Ʋ �̹����� 2�� �̻� ������ ��� �Ұ���?",true,CL_help);
			printsub("   A. Ÿ��Ʋ �̹����� ������������ �����Ҷ����� ������ Ÿ��Ʋ�� ����Ұ̴ϴ�.",true,CL_normal);
			printsub("",true,CL_help);
			printsub("Q. Ÿ��Ʋ�� ������ְ� �ʹ�. ��Ʈ�� ����ְ� �ʹ�. �׽�Ʈ�� ���ְ� �ʹ�.",true,CL_help);
			printsub("   A. �ƾ⾾ #����ũ�� ä�η� ������.",true,CL_normal);
			printsub("",true,CL_help);
			changedisplay(DT_SUB_TEXT);
			ReleaseMutex(mutx);
			break;*/
		case VK_ESCAPE:
			loop_ = false;
			break;
		default:
			break;
		}

	}
		

	changedisplay(DT_GAME);
}

