//////////////////////////////////////////////////////////////////////////////////////////////////
//
// �����̸�: key.cpp
//
// ����: Ű�� �Է� ó��
//
//////////////////////////////////////////////////////////////////////////////////////////////////

#include "const.h"
#include "display.h"
#include "key.h"
#include "replay.h"
#include <conio.h>
#include <windows.h> 


extern HWND hwnd;

bool game_over= false;
bool shift_check = false;
bool ctrl_check = false;
int replay_speed = 1;


bool isKeyinput()
{
	MSG msg;
	return PeekMessage(&msg,NULL,0,0,PM_REMOVE);
}

int waitkeyinput_inter(bool direction_, bool immedity_)
{
	if(immedity_)
	{
		if(isKeyinput())
			return 1;
		else
			return 0;
	}


	MSG msg;
	if(game_over)
		throw 0;
	while(GetMessage(&msg,0,0,0))
	{
		if(msg.message == WM_CHAR)
		{
			if(msg.wParam == 1) //A+��Ʈ��
			{
				//if(shift_check)
					return 0x8B; //0x8B�� ��Ʈ��A
			}
			if(msg.wParam == 16) //p+��Ʈ��
			{
				//if(shift_check)
					return 0x88; //0x88�� ��Ʈ��p
			}
			else if(msg.wParam == 17 ) //Q+��Ʈ��
			{
				//if(shift_check)
					return 0x89; //0x89�� ��Ʈ��Q
			}
			else if(msg.wParam == 19) //S+��Ʈ��
			{
				//if(shift_check)
					return 0x8A; //0x8A�� ��Ʈ��S
			}
			return msg.wParam; //����13 esc 27
		}
		else if(msg.message == WM_KEYDOWN)
		{
			switch(msg.wParam)
			{
			case '8':
				if(direction_ || shift_check) break; //������ if(direction_)���־��µ� ���� ����
				return (shift_check)?'*':'k';
			case VK_UP:
			case VK_NUMPAD8:
				if(direction_) return VK_UP;
				return 'k';
				break;
			case '4':
				if(direction_ || shift_check) break;
				return (shift_check)?'$':'h';
			case VK_LEFT:
			case VK_NUMPAD4:	
				if(direction_) return VK_LEFT;
				return 'h';
				break;
			case '6':
				if(direction_ || shift_check) break;
				return (shift_check)?'^':'l';
			case VK_RIGHT:
			case VK_NUMPAD6:	
				if(direction_) return VK_RIGHT;
				return 'l';
				break;
			case '2':
				if(direction_ || shift_check) break;
				return (shift_check)?'@':'j';
			case VK_DOWN:
			case VK_NUMPAD2:	
				if(direction_) return VK_DOWN;
				return 'j';
				break;			
			case '1':		
				if(direction_ || shift_check) break;
				return (shift_check)?'!':'b';
			case VK_NUMPAD1:	
			case 35:
				return 'b';
			case '3':		
				if(direction_ || shift_check) break;
				return (shift_check)?'#':'n';
			case 34:
				if(direction_) return 34;
			case VK_NUMPAD3:	
				return 'n';
			case '7':	
				if(direction_ || shift_check) break;
				return (shift_check)?'&':'y';
			case VK_NUMPAD7:	
			case 36:
				return 'y';
			case '9':	
				if(direction_ || shift_check) break;
				return (shift_check)?'(':'u';	
			case 33:
				if(direction_) return 33;
			case VK_NUMPAD9:	
				return 'u';
			default:
				break;
			}			
			if(msg.wParam == VK_SHIFT)
				shift_check = true;
			if(msg.wParam == VK_CONTROL)
				ctrl_check = true;

		}
		else if(msg.message == WM_KEYUP)
		{
			if(msg.wParam == VK_SHIFT)
				shift_check = false;
			if(msg.wParam == VK_CONTROL)
				ctrl_check = false;
		}
	}
	if(msg.message == WM_QUIT)
	{
		throw 0;
	}
	return 0;
}



int waitkeyinput(bool direction_, bool immedity_)
{

	if(ReplayClass.auto_key == false)
	{
		DWORD time_ = timeGetTime();

		int return_ = waitkeyinput_inter(direction_,immedity_);
	
		DWORD time2_ = timeGetTime();

		ReplayClass.SaveReplayInput(immedity_?0:(time2_-time_), return_);

		return return_;
	}
	else
	{
		DWORD delay_;
		int return_;
		MSG msg;
		bool end_ = false;
		PeekMessage(&msg,NULL,0,0,PM_REMOVE);
		if(msg.message == WM_CHAR)
		{
			switch(msg.wParam)
			{
			case 'x':
				replay_speed = 1;
				break;
			case 'c':
				replay_speed = 0;
				break;
			case 'z':
				while(1)
				{
					GetMessage(&msg,0,0,0);

					if(msg.message == WM_CHAR)
					{
						if(msg.wParam == 'z' || msg.wParam == 'x' || msg.wParam == 'c')
						{
							if (msg.wParam == 'x')
								replay_speed = 1;
							else if (msg.wParam == 'c')
								replay_speed = 0;
							break;
						}
					}
					if (msg.message == WM_QUIT) {
						end_ = true;
						break;
					}
				}
				break;
			}
		}

		if(game_over || end_)
		{
			throw 0;
		}
		if(ReplayClass.LoadReplayInput(&delay_,&return_))
		{		
			if(delay_>0)
			{
				for(int i = 0; i <(replay_speed==1?min(1000,delay_):0); i++)
					Sleep(1);
			}

			return return_;
		}
		else
			return 0;
	}
}



int MoreWait()
{
	printlog("----------������----------",true,false,true,CL_normal);
	while(1)
	{
		int select = waitkeyinput();
		if(select==VK_RETURN)
		{
			break;
		}
	}
	deletelog();
	return true;
}