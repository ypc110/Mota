#include"头.cpp"
struct Rect1 {
	int x;
	int y;
	int w;
	int h;
};
bool isMouseDown;
int mouseX;						//鼠标位置坐标X
int mouseY;						//鼠标位置坐标Y
int GamePhase = 0;
bool flag_boss;
int floor1;
int flag;
bool IsInRect(int x, int y, Rect1 r)
{
	return ((x >= r.x && x <= r.w) && (y >= r.y && y <= r.h));
};
int map_[6][13][13] = {
	{{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
		{ 1, 1, 1, 9, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
		{ 1, 1, 1, 1, 1, 1, 18, 1, 1, 1, 1, 1, 0 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }},//
	{{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 9, 1, 2, 3, 2, 1, 1, 1, 1, 1, 1, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
		{ 0, 8, 1, 1, 16, 1, 0, 5, 6, 1, 0, 1, 0 },
		{ 0, 1, 12, 1, 0, 1, 0, 4, 8, 1, 0, 1, 0 },
		{ 0, 0, 16, 0, 0, 1, 0, 0, 0, 16, 0, 1, 0 },
		{ 0, 6, 1, 1, 0, 1, 16, 10, 11, 10, 0, 1, 0 },
		{ 0, 1, 13, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0 },
		{ 0, 0, 16, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0 },
		{ 0, 1, 1, 1, 0, 0, 16, 0, 0, 0, 16, 0, 0 },
		{ 0, 8, 1, 6, 0, 6, 1, 6, 0, 1, 10, 1, 0 },
		{ 0, 8, 1, 6, 0, 1, 18, 1, 0, 2, 14, 2, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }},//
	{{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 7, 4, 0, 7, 14, 7, 0, 1, 0, 1, 8, 0 },
		{ 0, 1 ,8,0,14,7,14,0,1,17,10,1, 0 },
		{ 0, 11,1,0,7,6,7,0,1,0,0,0, 0 },
		{ 0, 17,0,0,0,1,0,0,1,0,1,1, 0 },
		{ 0, 1,1,10,1,1,1,2,1,1,1,1, 0 },
		{ 0, 17,0,0,1,1,1,0,1,0,0,0, 0 },
		{ 0, 12,1,0,0,1,0,0,1,0,1,8, 0 },
		{ 0, 1,7,0,1,1,1,0,1,17,11,7, 0 },
		{ 0, 8,5,0,1,1,1,0,1,0,0,0, 0 },
		{ 0, 0,0,0,0,1,0,0,3,0,1,1, 0 },
		{ 0, 15,18,1,1,1,1,0,1,17,1,9, 0 },

		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }},//
	{{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 19,3,7,0,8,8,8,0,0,0,0, 0 },
		{ 0, 3,7,1,0,1,1,1,0,1,10,1, 0 },
		{ 0, 7,12,1,0,0,17,0,0,1,0,1, 0 },
		{ 0, 0,17,0,0,1,12,1,0,7,0,3, 0 },
		{ 0, 1,1,1,0,0,0,1,0,7,0,10, 0 },
		{ 0, 2,0,1,10,3,10,1,0,7,0,3, 0 },
		{ 0, 2,0,0,10,1,0,1,1,1,0,1, 0 },
		{ 0, 1,1,1,1,1,0,0,17,0,0,1, 0 },
		{ 0, 0,0,0,0,10,0,3,1,3,0,1, 0 },
		{ 0, 0,1,1,1,1,0,4,10,7,0,1, 0 },
		{ 0, 15,18,0,0,0,0,5,14,7,0,9, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }},//
	{{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0,1,1,12,17,1,15,1,17,2,1,8, 0 },
		{ 0, 1,7,1,0,1,18,1,0,1,2,1, 0 },
		{ 0, 13,0,0,0,0,16,0,0,0,0,1, 0 },
		{ 0,1,7,1,0,7,1,7,17,17,1,1, 0 },
		{ 0, 4,1,10,17,1,5,1,0,0,0,0, 0 },
		{ 0, 0,0,0,0,0,0,3,0,1,1,13, 0 },
		{ 0, 7,0,17,13,7,0,1,0,20,0,1, 0 },
		{ 0, 13,1,0,1,1,0,1,0,0,0,17, 0 },
		{ 0, 17,0,0,0,17,0,1,0,7,1,11, 0 },
		{ 0, 1,8,0,1,12,0,10,0,1,12,1, 0 },
		{ 0, 9,1,16,1,1,17,1,17,11,1,8, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }},//
	{{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 14, 1, 14, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 8, 19, 22, 20, 8, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 8, 1, 21, 1, 8, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 18, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 15, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }}
};

int map[13][13];
IMAGE img0[23];
IMAGE roleInfo;
struct gamerole
{
	char name[20];
	int xueliang;

	int fangyuli;
	int gongji;
	int lanyaoshi;
	int huangyaoshi;
	int hongyaoshi;
	int dengji;
	int jinyan;

}role;
struct monster
{

	int xueliang;
	int gongji;
	int fangyuli;
	int jinyan;
};
struct monster bats = { 20, 10, 9, 450 };
struct monster 绿史莱姆 = { 10,10,10,50 };
struct monster 红史莱姆 = { 15,10,12,60 };
struct monster wizerd = { 100, 250, 10, 750 };
struct monster 骷髅 = { 50,20,23,20 };
struct monster 骷髅2 = { 70,20,23,20 };
struct monster 魔王 = { 500,20,23,20 };
HWND hwnd = NULL;
void inputrole()
{

	role.hongyaoshi = 0;
	role.huangyaoshi = 0;
	role.dengji = 0;
	role.fangyuli = 0;
	role.jinyan = 0;

	role.lanyaoshi = 2;
	role.xueliang = 200;
	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 13; j++) {
			map[i][j] = map_[0][i][j];
		}
	}
}
void up_down()
{
	if (floor1 >= 0 && floor1 < 7)
	{
		if (flag == 1)
		{
			for (int i = 0; i < 13; i++)
			{
				for (int j = 0; j < 13; j++)
				{
					map_[floor1 - 1][i][j] = map[i][j];
					map[i][j] = map_[floor1][i][j];
				}
			}
		}
		else {
			if (flag == 0) {
				for (int i = 0; i < 13; i++)
				{
					for (int j = 0; j < 13; j++)
					{
						map_[floor1 + 1][i][j] = map[i][j];
						map[i][j] = map_[floor1][i][j];
					}
				}
			}
		}
	}

}
void loadresource()
{
	loadimage(&roleInfo, _T("info.png"));//加载图片&roleinfo表示保存图片的对象指针

	for (int i = 0; i < 24; i++)
	{
		wchar_t filename[24] = L"";
		wsprintf(filename, L"%d.jpg", i);

		loadimage(img0 + i, filename, 60, 60);


	}
}

void outtextxy_int(int x, int y, int num)
{
	//wchar_t str[200] = {};

	//outtextxy(x, y, L"str");

	//sprintf(str, "%d", num);//将整形a转换成字符
	//swprintf_s(str, _T("%d"), num);
	//outtextxy(x, y, str);//将字符串输出到界面上
	TCHAR str[20] = {};
	//_sntprintf(str, _T("%d"), num);
	_itot(num, str, 10);
	outtextxy(x, y, str);
}

void outtextxy_char(int x, int y, char l[20])
{
	TCHAR Name[100];
#ifdef UNICODE
	MultiByteToWideChar(CP_ACP, 0, l, -1, Name, 100);
#else
	strcpy(Name, l);
#endif
	outtextxy(x, y, Name);

}

void drawmap()
{

	//int j;//遍历二维数组
	int x, y;//贴图坐标
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			x = 60 * j;
			y = 60 * i;
			putimage(x, y, &img0[map[i][j]]);//绘制图片，&roleinfo表示要绘制的图片指针
		}
	}
	//outtextxy(213, 1532, 6);
	//图形窗口不能打印数字类-----》把数字转换为字符串
	putimage(60 * 13, 0, &roleInfo);//绘制图片，&roleinfo表示要绘制的图片指针
	//setlocale(LC_ALL, "zh_CN.UTF-8");
	//settextcolor(WHITE);
	outtextxy(60 * 13 + 12, 100, L"王子");
	settextcolor(RED);
	settextstyle(15, 0, L"黑体");
	outtextxy_char(60 * 13 + 12, 100, role.name);

	outtextxy_int(60 * 13 + 12, 188, role.dengji);
	outtextxy_int(60 * 13 + 12, 235, role.jinyan);
	outtextxy_int(60 * 13 + 12, 362, role.xueliang);
	outtextxy_int(60 * 13 + 12, 517, role.gongji);
	outtextxy_int(60 * 13 + 12, 567, role.fangyuli);
	outtextxy_int(60 * 13 + 12, 689, role.huangyaoshi);
	outtextxy_int(60 * 13 + 12, 759, role.lanyaoshi);
	
}
bool bloodpk(struct monster guaiwu)
{
	guaiwu.xueliang -= role.gongji;
	guaiwu.xueliang -= role.fangyuli;
	role.xueliang -= guaiwu.xueliang;
	if (role.xueliang <= 0)
	{
		return false;
	}
	else
	{

		role.jinyan += guaiwu.jinyan;
		return true;
	}
}
void saved()
{
	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 13; j++) {
			map_[floor1 - 1][i][j] = map[i][j];
		}
	}
	ofstream outFile;
	outFile.open("baocun.txt");
	outFile.clear();
	outFile << 'Y' << endl;
	for (int k = 0; k < 6; k++) {

		for (int i = 0; i < 13; i++) {
			for (int j = 0; j < 13; j++) {
				outFile << map_[k][i][j] << ' ';
			}
			outFile << endl;
		}
	}
	outFile << role.name << endl;

	outFile << role.dengji << ' ' << role.fangyuli << '\n';
	outFile << role.gongji << ' ' << role.huangyaoshi << '\n';
	outFile << role.jinyan << ' ' << role.hongyaoshi << '\n';
	outFile << role.lanyaoshi << ' ' << role.xueliang << endl;
	outFile << floor1;
	outFile.close();
}
void open_file()
{
	HWND hWnd = GetHWnd();
	ifstream Infile;
	ofstream outFile;

	Infile.open("baocun.txt");
	if (!Infile.is_open())
	{
		int ret = MessageBox(hWnd, TEXT("读取存档失败，是否忽略继续游戏？"), TEXT("选择"), MB_YESNO | MB_ICONQUESTION);
		if (ret == IDYES)
		{
			return;
		}
		else {
			exit(EXIT_FAILURE);
		}
	}
	char ch;
	Infile >> ch;
	if (ch == 'Y')
	{
		int ret = MessageBox(hWnd, TEXT("读取存档成功 ，是否从存档处继续？"), TEXT("选择"), MB_YESNO | MB_ICONQUESTION);
		if (ret == IDYES)
		{
			for (int k = 0; k < 6; k++)
			{
				for (int i = 0; i < 13; i++)
				{
					for (int j = 0; j < 13; j++)
					{
						int a;
						Infile >> a;
						map_[k][i][j] = a;
					}
				}
			}
		}
		Infile>> role.name ;

		Infile >> role.dengji >>role.fangyuli ;
		Infile >> role.gongji >>role.huangyaoshi ;
		Infile >> role.jinyan >>role.hongyaoshi ;
		Infile >> role.lanyaoshi >> role.xueliang ;
		int f;
		Infile >> f;
		floor1 = 0;
		flag_boss = false;
		for (int i = 0; i < 13; i++)
		{
			for (int j = 0; j < 13; j++)
			{
				map[i][j] = map_[floor1+1][i][j];
			}
		}
	}

	outFile.open("baocun.txt");
	outFile.clear();
	outFile.close();
	Infile.close();

}
void keydown()
{
	char userkey = '\0';
	int i = 0, j = 0;
	for (i = 0; i < 13; i++) {
		for (j = 0; j < 13; j++) {
			if (map[i][j] == 18)
			{
				break;
			}

		}

		if (map[i][j] == 18)
		{
			break;
		}
	}
	fflush(stdin);
	userkey = _getch();
	switch (userkey)
	{
	case  'a':
	case  'A':
	case  75:
		//空地情况
		if (map[i][j - 1] == 1)
		{
			map[i][j] = 1;
			map[i][j - 1] = 18;
		}
		if (map[i][j - 1] == 4)
		{
			map[i][j] = 1;
			map[i][j - 1] = 18;
			role.gongji++;
		}
		if (map[i][j - 1] == 5)
		{
			map[i][j] = 1;
			map[i][j - 1] = 18;
			role.fangyuli++;
		}
		if (map[i][j - 1] == 7)
		{
			map[i][j] = 1;
			map[i][j - 1] = 18;
			role.huangyaoshi++;
		}
		if (map[i][j - 1] == 8)
		{
			map[i][j] = 1;
			map[i][j - 1] = 18;
			role.xueliang += 20;
		}
		if (map[i][j - 1] == 14)
		{
			map[i][j] = 1;
			map[i][j - 1] = 18;
			role.xueliang += 60;
		}
		else if (map[i][j - 1] == 6)
		{

			map[i][j] = 1;
			map[i][j - 1] = 18;//数据记录
			mciSendString(L"open 1.3.mp3 ", 0, 0, 0);
			role.lanyaoshi++;
		}
		else if (map[i][j - 1] ==16 && role.lanyaoshi > 0)
		{
			map[i][j] = 1;
			map[i][j - 1] = 18;//数据记录
			role.lanyaoshi--;
		}
		else if (map[i][j - 1] == 17 && role.huangyaoshi > 0)
		{
			map[i][j] = 1;
			map[i][j - 1] = 18;//数据记录
			role.huangyaoshi--;
		}

		else if (map[i][j - 1] == 9)
		{
			flag = 1;
			floor1++;
			up_down();
			drawmap();
		}
		else if (map[i][j - 1] == 22)
		{
			exit(0);
		}
		else if (map[i][j - 1] == 15)
		{
			flag = 0;
			floor1--;
			up_down();
			drawmap();
		}
		else if (map[i][j - 1] == 10)
		{

			int ID = MessageBox(hwnd, L"是否攻击小蝙蝠！", L"遇到小蝙蝠", MB_YESNO);
			if (ID == IDYES)
			{
				if (bloodpk(bats))
				{
					map[i][j] = 1;
					map[i][j - 1] = 18;//数据记录

				}
				else
				{

					int ID = MessageBox(hwnd, L"血量不足", L"无法攻击", MB_YESNO);
				}
			}
		}
		else if (map[i][j - 1] == 2)
		{

			int ID = MessageBox(hwnd, L"是否攻击绿史莱姆！", L"遇到绿史莱姆", MB_YESNO);
			if (ID == IDYES)
			{
				if (bloodpk(绿史莱姆))
				{
					map[i][j] = 1;
					map[i][j - 1] = 18;//数据记录

				}
				else
				{

					int ID = MessageBox(hwnd, L"血量不足", L"无法攻击", MB_YESNO);
				}
			}
		}
		else if (map[i][j - 1] == 3)
		{

			int ID = MessageBox(hwnd, L"是否攻击红史莱姆！", L"遇到红史莱姆", MB_YESNO);
			if (ID == IDYES)
			{
				if (bloodpk(红史莱姆))
				{
					map[i][j] = 1;
					map[i][j - 1] = 18;//数据记录

				}
				else
				{

					int ID = MessageBox(hwnd, L"血量不足", L"无法攻击", MB_YESNO);
				}
			}
		}
		else if (map[i][j - 1] == 13)
		{

			int ID = MessageBox(hwnd, L"是否攻击骷髅！", L"遇到骷髅", MB_YESNO);
			if (ID == IDYES)
			{
				if (bloodpk(骷髅2))
				{
					map[i][j] = 1;
					map[i][j - 1] = 18;//数据记录

				}
				else
				{

					int ID = MessageBox(hwnd, L"血量不足", L"无法攻击", MB_YESNO);
				}
			}
		}
		else if (map[i][j - 1] == 12)
		{

		int ID = MessageBox(hwnd, L"是否攻击小骷髅！", L"遇到小骷髅", MB_YESNO);
		if (ID == IDYES)
		{
			if (bloodpk(骷髅))
			{
				map[i][j] = 1;
				map[i][j - 1] = 18;//数据记录

			}
			else
			{

				int ID = MessageBox(hwnd, L"血量不足", L"无法攻击", MB_YESNO);
			}
		}
		}
		else if (map[i][j - 1] == 21)
		{

		int ID = MessageBox(hwnd, L"是否攻击大魔王！", L"遇到大魔王", MB_YESNO);
		if (ID == IDYES)
		{
			if (bloodpk(魔王))
			{
				map[i][j] = 1;
				map[i][j - 1] = 18;//数据记录

			}
			else
			{

				int ID = MessageBox(hwnd, L"血量不足", L"无法攻击", MB_YESNO);
			}
		}
		}
		break;
	case  'd':
	case  'D':
	case   77:
		if (map[i][j + 1] == 1)
		{
			map[i][j] = 1;
			map[i][j + 1] = 18;
		}
		if (map[i][j + 1] == 4)
		{
			map[i][j] = 1;
			map[i][j + 1] = 18;
			role.gongji++;
		}
		if (map[i][j + 1] == 5)
		{
			map[i][j] = 1;
			map[i][j+ 1] = 18;
			role.fangyuli++;
		}
		if (map[i][j + 1] == 7)
		{
			map[i][j] = 1;
			map[i][j + 1] = 18;
			role.huangyaoshi++;
		}
		if (map[i][j + 1] == 8)
		{
			map[i][j] = 1;
			map[i][j + 1] = 18;
			role.xueliang += 20;
		}
		if (map[i][j + 1] == 14)
		{
			map[i][j] = 1;
			map[i][j + 1] = 18;
			role.xueliang += 60;
		}
		else if (map[i][j + 1] == 22)
		{
			exit(0);
		}
		else if (map[i][j + 1] == 6)
		{

			map[i][j] = 1;
			map[i][j + 1] = 18;//数据记录
			//mciSendString(L"open 1.3.mp3 ", 0, 0, 0);
			role.lanyaoshi++;
		}
		else if (map[i][j + 1] == 16 && role.lanyaoshi > 0)
		{
			map[i][j] = 1;
			map[i][j + 1] = 18;//数据记录
			role.lanyaoshi--;
		}
		else if (map[i][j + 1] == 17 && role.huangyaoshi > 0)
		{
			map[i][j] = 1;
			map[i][j + 1] = 18;//数据记录
			role.huangyaoshi--;
		}

		else if (map[i][j + 1] == 9)
		{
			flag = 1;
			floor1++;
			up_down();
			drawmap();
		}
		else if (map[i][j + 1] == 15)
		{
			flag = 0;
			floor1--;
			up_down();
			drawmap();
		}
		else if (map[i][j + 1] == 10)
		{

			int ID = MessageBox(hwnd, L"遇到小蝙蝠", L"是否攻击小蝙蝠！", MB_YESNO);
			if (ID == IDYES)
			{
				if (bloodpk(bats))
				{
					map[i][j] = 1;
					map[i][j + 1] = 18;//数据记录

				}
				else
				{

					int ID = MessageBox(hwnd, L"血量不足", L"无法攻击", MB_YESNO);
				}
			}
		}
		else if (map[i][j +1] == 2)
		{

			int ID = MessageBox(hwnd, L"是否攻击绿史莱姆！", L"遇到绿史莱姆", MB_YESNO);
			if (ID == IDYES)
			{
				if (bloodpk(绿史莱姆))
				{
					map[i][j] = 1;
					map[i][j +1] = 18;//数据记录

				}
				else
				{

					int ID = MessageBox(hwnd, L"血量不足", L"无法攻击", MB_YESNO);
				}
			}
		}
		else if (map[i][j + 1] == 3)
		{

			int ID = MessageBox(hwnd, L"是否攻击红史莱姆！", L"遇到红史莱姆", MB_YESNO);
			if (ID == IDYES)
			{
				if (bloodpk(红史莱姆))
				{
					map[i][j] = 1;
					map[i][j + 1] = 18;//数据记录

				}
				else
				{

					int ID = MessageBox(hwnd, L"血量不足", L"无法攻击", MB_YESNO);
				}
			}
		}
		else if (map[i][j + 1] == 12)
		{

			int ID = MessageBox(hwnd, L"遇到小骷髅", L"是否攻击小骷髅！", MB_YESNO);
			if (ID == IDYES)
			{
				if (bloodpk(bats))
				{
					map[i][j] = 1;
					map[i][j + 1] = 18;//数据记录

				}
				else
				{

					int ID = MessageBox(hwnd, L"血量不足", L"无法攻击", MB_YESNO);
				}
			}
		}
		else if (map[i][j + 1] == 13)
		{

		int ID = MessageBox(hwnd, L"遇到骷髅", L"是否攻击小骷髅！", MB_YESNO);
		if (ID == IDYES)
		{
			if (bloodpk(bats))
			{
				map[i][j] = 1;
				map[i][j + 1] = 18;//数据记录

			}
			else
			{

				int ID = MessageBox(hwnd, L"血量不足", L"无法攻击", MB_YESNO);
			}
		}
		}
		else if (map[i][j + 1] == 21)
		{

		int ID = MessageBox(hwnd, L"遇到大魔王", L"是否攻击大魔王！", MB_YESNO);
		if (ID == IDYES)
		{
			if (bloodpk(bats))
			{
				map[i][j] = 1;
				map[i][j + 1] = 18;//数据记录

			}
			else
			{

				int ID = MessageBox(hwnd, L"血量不足", L"无法攻击", MB_YESNO);
			}
		}
		}
		break;
	case  'w':
	case  'W':
	case   72:
		if (map[i - 1][j]==1)
		{
			map[i][j] = 1;
			map[i - 1][j] = 18;
		}
		if (map[i-1][j ] == 4)
		{
			map[i][j] = 1;
			map[i-1][j ] = 18;
			role.gongji++;
		}
		if (map[i-1][j ] == 5)
		{
			map[i][j] = 1;
			map[i-1][j ] = 18;
			role.fangyuli++;
		}
		if (map[i-1][j] == 7)
		{
			map[i][j] = 1;
			map[i-1][j ] = 18;
			role.huangyaoshi++;
		}
		else if (map[i-1][j ] == 22)
		{
			exit(0);
		}
		if (map[i-1][j ] == 8)
		{
			map[i][j] = 1;
			map[i-1][j ] = 18;
			role.xueliang += 20;
		}
		if (map[i-1][j] == 14)
		{
			map[i][j] = 1;
			map[i-1][j] = 18;
			role.xueliang += 60;
		}
		else if (map[i - 1][j] == 6)
		{

			map[i][j] = 1;
			map[i - 1][j] = 18;//数据记录
			mciSendString(L"open 1.3.mp3 ", 0, 0, 0);
			role.lanyaoshi++;
		}
		else if (map[i - 1][j] == 16 && role.lanyaoshi > 0)
		{
			map[i][j] = 1;
			map[i - 1][j] = 18;//数据记录
			role.lanyaoshi--;
		}
		else if (map[i - 1][j] == 17 && role.huangyaoshi > 0)
		{
			map[i][j] = 1;
			map[i - 1][j] = 18;//数据记录
			role.huangyaoshi--;
		}
		else if (map[i - 1][j] == 9)
		{
			
			flag = 1;
			floor1++;
			up_down();
			drawmap();
		}
		else if (map[i - 1][j] == 15)
		{

			flag = 0;
			floor1--;
			up_down();
			drawmap();
		}
		else if (map[i - 1][j] == 10)
		{

			int ID = MessageBox(hwnd, L"遇到小蝙蝠", L"是否攻击小蝙蝠！", MB_YESNO);
			if (ID == IDYES)
			{
				if (bloodpk(bats))
				{
					map[i][j] = 1;
					map[i - 1][j] =18;//数据记录

				}
				else
				{

					int ID = MessageBox(hwnd, L"血量不足", L"无法攻击", MB_YESNO);
				}
			}
		}
		else if (map[i-1][j] == 2)
		{

			int ID = MessageBox(hwnd, L"是否攻击绿史莱姆！", L"遇到绿史莱姆", MB_YESNO);
			if (ID == IDYES)
			{
				if (bloodpk(绿史莱姆))
				{
					map[i][j] = 1;
					map[i-1][j] = 18;//数据记录

				}
				else
				{

					int ID = MessageBox(hwnd, L"血量不足", L"无法攻击", MB_YESNO);
				}
			}
		}
		else if (map[i-1][j] == 3)
		{

			int ID = MessageBox(hwnd, L"是否攻击红史莱姆！", L"遇到红史莱姆", MB_YESNO);
			if (ID == IDYES)
			{
				if (bloodpk(红史莱姆))
				{
					map[i][j] = 1;
					map[i-1][j] = 18;//数据记录

				}
				else
				{

					int ID = MessageBox(hwnd, L"血量不足", L"无法攻击", MB_YESNO);
				}
			}
		}
		else if (map[i - 1][j] == 12)
		{

			int ID = MessageBox(hwnd, L"是否攻击骷髅！", L"遇到骷髅", MB_YESNO);
			if (ID == IDYES)
			{
				if (bloodpk(骷髅))
				{
					map[i][j] = 1;
					map[i - 1][j] = 18;//数据记录

				}
				else
				{

					int ID = MessageBox(hwnd, L"血量不足", L"无法攻击", MB_YESNO);
				}
			}
		}
		else if (map[i - 1][j] == 2)
		{

		int ID = MessageBox(hwnd, L"是否攻击大骷髅！", L"遇到大骷髅", MB_YESNO);
		if (ID == IDYES)
		{
			if (bloodpk(骷髅2))
			{
				map[i][j] = 1;
				map[i - 1][j] = 18;//数据记录

			}
			else
			{

				int ID = MessageBox(hwnd, L"血量不足", L"无法攻击", MB_YESNO);
			}
		}
		}
		else if (map[i - 1][j] == 21)
		{

		int ID = MessageBox(hwnd, L"是否攻击大魔王！", L"遇到大魔王", MB_YESNO);
		if (ID == IDYES)
		{
			if (bloodpk(魔王))
			{
				map[i][j] = 1;
				map[i - 1][j] = 18;//数据记录

			}
			else
			{

				int ID = MessageBox(hwnd, L"血量不足", L"无法攻击", MB_YESNO);
			}
		}
		}
		break;
	case  's':
	case  'S':
	case  80:
		if (map[i + 1][j] == 1)
		{
			map[i][j] = 1;
			map[i+1][j] = 18;
		}
		if (map[i + 1][j] == 1)
		{
			map[i][j] = 1;
			map[i + 1][j] = 18;
		}
		if (map[i + 1][j] == 4)
		{
			map[i][j] = 1;
			map[i + 1][j] = 18;
			role.gongji++;
		}
		else if (map[i+1][j] == 22)
		{
			exit(0);
		}
		if (map[i + 1][j] == 5)
		{
			map[i][j] = 1;
			map[i + 1][j] = 18;
			role.fangyuli++;
		}
		if (map[i + 1][j] == 7)
		{
			map[i][j] = 1;
			map[i +1][j] = 18;
			role.huangyaoshi++;
		}
		if (map[i + 1][j] == 8)
		{
			map[i][j] = 1;
			map[i + 1][j] = 18;
			role.xueliang += 20;
		}
		if (map[i + 1][j] == 14)
		{
			map[i][j] = 1;
			map[i + 1][j] = 18;
			role.xueliang += 60;
		}
		else if (map[i + 1][j] == 6)
		{

			map[i][j] = 1;
			map[i + 1][j] = 18;//数据记录
			mciSendString(L"open 1.3.mp3 ", 0, 0, 0);
			role.lanyaoshi++;
		}
		else if (map[i + 1][j] == 16 && role.lanyaoshi > 0)
		{
			map[i][j] = 1;
			map[i + 1][j] = 18;//数据记录
			role.lanyaoshi--;
		}
		else if (map[i + 1][j] == 17 && role.huangyaoshi > 0)
		{
			map[i][j] = 1;
			map[i + 1][j] = 18;//数据记录
			role.huangyaoshi--;
		}

		else if (map[i + 1][j] == 9)
		{
		
			flag = 1;
			floor1++;
			up_down();
			drawmap();
		}

		else if (map[i + 1][j] == 15)
		{

			flag = 0;
			floor1--;
			up_down();
			drawmap();
		}
		else if (map[i + 1][j] == 10)
		{

			int ID = MessageBox(hwnd, L"遇到小蝙蝠", L"是否攻击小蝙蝠！", MB_YESNO);
			if (ID == IDYES)
			{
				if (bloodpk(bats))
				{
					map[i][j] = 1;
					map[i + 1][j] = 18;//数据记录

				}
				else
				{

					int ID = MessageBox(hwnd, L"血量不足", L"无法攻击", MB_YESNO);
				}
			}
		}
		else if (map[i + 1][j] == 2)
		{

			int ID = MessageBox(hwnd, L"是否攻击绿史莱姆！", L"遇到绿史莱姆", MB_YESNO);
			if (ID == IDYES)
			{
				if (bloodpk(绿史莱姆))
				{
					map[i][j] = 1;
					map[i + 1][j] = 18;//数据记录

				}
				else
				{

					int ID = MessageBox(hwnd, L"血量不足", L"无法攻击", MB_YESNO);
				}
			}
		}
		else if (map[i + 1][j] == 3)
		{

			int ID = MessageBox(hwnd, L"是否攻击红史莱姆！", L"遇到红史莱姆", MB_YESNO);
			if (ID == IDYES)
			{
				if (bloodpk(红史莱姆))
				{
					map[i][j] = 1;
					map[i + 1][j] = 18;//数据记录

				}
				else
				{

					int ID = MessageBox(hwnd, L"血量不足", L"无法攻击", MB_YESNO);
				}
			}
		}
		else if (map[i + 1][j] == 12)
		{

		int ID = MessageBox(hwnd, L"是否攻击骷髅！", L"遇到骷髅", MB_YESNO);
		if (ID == IDYES)
		{
			if (bloodpk(骷髅))
			{
				map[i][j] = 1;
				map[i + 1][j] = 18;//数据记录

			}
			else
			{

				int ID = MessageBox(hwnd, L"血量不足", L"无法攻击", MB_YESNO);
			}
		}
		}
		else if (map[i + 1][j] == 2)
		{

		int ID = MessageBox(hwnd, L"是否攻击骷髅！", L"遇到骷髅", MB_YESNO);
		if (ID == IDYES)
		{
			if (bloodpk(骷髅2))
			{
				map[i][j] = 1;
				map[i + 1][j] = 18;//数据记录

			}
			else
			{

				int ID = MessageBox(hwnd, L"血量不足", L"无法攻击", MB_YESNO);
			}
		}
		}
		else if (map[i + 1][j] == 21)
		{

		int ID = MessageBox(hwnd, L"是否攻击大魔王！", L"遇到大魔王", MB_YESNO);
		if (ID == IDYES)
		{
			if (bloodpk(魔王))
			{
				map[i][j] = 1;
				map[i + 1][j] = 18;//数据记录

			}
			else
			{

				int ID = MessageBox(hwnd, L"血量不足", L"无法攻击", MB_YESNO);
			}
		}
		}
		break;
		case 'n':
		case 'N':
			saved();
			break;
		case'o':
		case'O':
			mciSendString(L"open 1.2.mp3 alias a", 0, 0, 0);
			mciSendString(L"play a repeat", 0, 0, 0);
			break;
		case'I':
		case'i':
			mciSendString(L"close a", 0, 0, 0);
			break;
		

	}
}



#define WIDDOW_WIDTH    14*60
//窗口高
#define WINDOW_HEIGHT  14*60
void outputchinese(wchar_t* c, int l, int n)
{
	for (unsigned int j = 0; j < wcslen(c); j++)
	{
		outtextxy(20 + (j * 20), l, c[j]);

		int x = 20 + 20 * j;
		x += textwidth(c[j]);
		Sleep(n);
	}

}





void StartDraw()
{
	settextstyle(52, 30, _T("Impact"));
	//标题
	settextcolor(RGB(0, 0, 139));
	outtextxy(349, 93, _T("RPG"));
	settextcolor(RGB(0, 0, 255));
	outtextxy(343, 90, _T("RPG"));
	settextstyle(22, 10, _T("Verdana"));
	settextcolor(RGB(255, 51, 68));
	outtextxy(340, 153, _T("1.5 "));
	Rect1 r;
	r.x = 340;
	r.y = 220;
	r.w = r.x + 125;
	r.h = r.y + 35;
	setlinecolor(RGB(0, 229, 238));
	if (IsInRect(mouseX, mouseY, r))
	{
		setfillcolor(RGB(255, 187, 119));

		if (isMouseDown)
		{
			GamePhase = 4;
		};
	}
	else
		setfillcolor(RGB(205, 0, 0));
	fillrectangle(r.x, r.y, r.w, r.h);
	settextstyle(25, 10, _T("Verdana"));
	settextcolor(RGB(105, 105, 105));
	outtextxy(r.x + 5, r.y + 5, _T("剧情简介"));


	//开始游戏按钮


	r.x = 340;
	r.y = 270;
	r.w = r.x + 125;
	r.h = r.y + 35;
	setlinecolor(RGB(0, 229, 238));
	if (IsInRect(mouseX, mouseY, r))
	{
		setfillcolor(RGB(255, 187, 119));
		//开始游戏按键响应
		if (isMouseDown)
		{
			//Init();
			GamePhase = 1;

		}
	}
	else
		setfillcolor(RGB(205, 0, 0));
	fillrectangle(r.x, r.y, r.w, r.h);
	settextstyle(25, 10, _T("Verdana"));
	settextcolor(RGB(105, 105, 105));
	outtextxy(r.x + 5, r.y + 5, _T("开始游戏"));
	//音乐按键

	r.x = 700;
	r.y = 10;
	r.w = r.x + 46;
	r.h = r.y + 35;
	setlinecolor(RGB(0, 255, 0));
	if (IsInRect(mouseX, mouseY, r))
	{
		setfillcolor(RGB(0, 0, 255));
		//帮助按键响应

		if (isMouseDown) {


			mciSendString(L"open 1.2.mp3 alias a", 0, 0, 0);
			mciSendString(L"play a repeat", 0, 0, 0);




		}



	}
	else
		setfillcolor(RGB(144, 238, 144));
	fillrectangle(r.x, r.y, r.w, r.h);
	settextstyle(25, 10, _T("Verdana"));
	settextcolor(RGB(255, 51, 68));
	outtextxy(r.x + 5, r.y + 5, _T("音效"));

	r.x = 700;
	r.y = 50;
	r.w = r.x + 46;
	r.h = r.y + 35;
	setlinecolor(RGB(0, 255, 0));
	if (IsInRect(mouseX, mouseY, r))
	{
		setfillcolor(RGB(0, 0, 255));
		//帮助按键响应

		if (isMouseDown) {


			mciSendString(L"close a", 0, 0, 0);




		}



	}
	else
		setfillcolor(RGB(144, 238, 144));
	fillrectangle(r.x, r.y, r.w, r.h);
	settextstyle(25, 10, _T("Verdana"));
	settextcolor(RGB(255, 51, 68));
	outtextxy(r.x + 5, r.y + 5, _T("关闭"));
	//帮助游戏按钮
	r.x = 340;
	r.y = 320;
	r.w = r.x + 125;
	r.h = r.y + 35;
	setlinecolor(RGB(0, 229, 238));
	if (IsInRect(mouseX, mouseY, r))
	{
		setfillcolor(RGB(255, 187, 119));
		//帮助按键响应
		if (isMouseDown)
		{
			GamePhase = 3;
		};
	}
	else
		setfillcolor(RGB(205, 0, 0));
	fillrectangle(r.x, r.y, r.w, r.h);
	settextstyle(25, 10, _T("Verdana"));
	settextcolor(RGB(105, 105, 105));
	outtextxy(r.x + 5, r.y + 5, _T("游戏帮助"));
	//退出游戏按钮
	r.x = 340;
	r.y = 420;
	r.w = r.x + 125;
	r.h = r.y + 35;
	setlinecolor(RGB(0, 229, 238));
	if (IsInRect(mouseX, mouseY, r))
	{
		setfillcolor(RGB(255, 187, 119));
		//退出按键响应
		if (isMouseDown) exit(0);
	}
	else
		setfillcolor(RGB(205, 0, 0));
	fillrectangle(r.x, r.y, r.w, r.h);
	settextstyle(25, 10, _T("Verdana"));
	settextcolor(RGB(105, 105, 105));
	outtextxy(r.x + 5, r.y + 5, _T("退出游戏"));
	r.x = 340;
	r.y = 370;
	r.w = r.x + 125;
	r.h = r.y + 35;
	setlinecolor(RGB(0, 229, 238));
	if (IsInRect(mouseX, mouseY, r))
	{
		setfillcolor(RGB(255, 187, 119));
		//退出按键响应
		if (isMouseDown) GamePhase=5;
	}
	else
		setfillcolor(RGB(205, 0, 0));
	fillrectangle(r.x, r.y, r.w, r.h);
	settextstyle(25, 10, _T("Verdana"));
	settextcolor(RGB(105, 105, 105));
	outtextxy(r.x + 5, r.y + 5, _T("打开存档"));
	//说明
	settextstyle(16, 5, _T("Verdana"));
	settextcolor(RGB(255, 51, 68));
	outtextxy(175, 400, _T("Programing By  ypc    2020.06.22"));
}
void welcome()
{ 

	settextstyle(52, 30, _T("Impact"));
	settextcolor(RGB(255, 17, 152));
	outtextxy(233, 33, _T("剧情"));




	settextstyle(18, 10, _T("黑体"));
	settextcolor(RGB(245, 126, 92));
	outtextxy(110, 110, _T("很久很久以前，在一个繁荣昌盛的王国里生活着一位十分美丽的公主。"));
	outtextxy(110, 145, _T("她在王国里十分幸福的生活着，享受着荣华富贵，众人的追捧，无忧无虑的生活"));
	outtextxy(110, 170, _T("直到有一天，恶龙突然来了，他不由分说的俘获了公主，将它带到了自己的城堡里"));
	outtextxy(110, 195, _T("这天有个英勇的骑士来到了这个王国"));
	outtextxy(110, 220, _T("勇士听说国王的女儿被一群怪物抓走了，那群怪物就位于一座魔塔当中，"));
	outtextxy(110, 245, _T("很多人去营救公主，但都没人能够回来。"));
	outtextxy(110, 280, _T("勇士决定去营救公主，于是来到了魔塔，可刚进入魔塔，就被魔塔的首领红衣魔王暗算"));
	outtextxy(110, 300, _T("勇士的剑和盾都被夺走了，还被关入了监牢。"));
	outtextxy(110, 325, _T("勇士展开了反击，在塔里不停的打怪升级，变得越来越强"));
	outtextxy(110, 345, _T("在经历了一番磨难之后，勇士终于打败了红衣魔王，并成功找到了被囚禁的公主"));
	outtextxy(110, 365, _T("但让人震惊的是，公主居然只是个假人！"));
	outtextxy(110, 385, _T("原来，之前打败的红衣魔王并非真身，也根本没什么小偷和公主……"));
	//返回
	Rect1 r;
	r.x = 240;
	r.y = 560;
	r.w = r.x + 125;
	r.h = r.y + 35;
	setlinecolor(RGB(255, 17, 102));
	if (IsInRect(mouseX, mouseY, r))
	{
		setfillcolor(RGB(255, 187, 119));
		//返回按键响应
		if (isMouseDown) GamePhase = 0;
	}
	else
		setfillcolor(RGB(255, 255, 204));
	fillrectangle(r.x, r.y, r.w, r.h);
	settextstyle(25, 9, _T("Verdana"));
	settextcolor(RGB(255, 51, 68));
	outtextxy(r.x + 5, r.y + 5, _T("返回菜单"));




}
void HelpDraw()
{
	//标题
	settextstyle(52, 30, _T("Impact"));
	settextcolor(RGB(255, 17, 152));
	outtextxy(233, 33, _T("帮助"));
	settextcolor(RGB(215, 193, 238));
	outtextxy(230, 30, _T("帮助"));

	//底板
	setlinecolor(RGB(0, 255, 0));
	setfillcolor(RGB(0, 255, 0));
	fillrectangle(100, 100, 700, 380);

	//版本
	settextstyle(18, 10, _T("黑体"));
	settextcolor(RGB(245, 126, 92));
	outtextxy(200, 110, _T("这是一款经典RPG类小游戏。"));
	outtextxy(200, 145, _T("【玩法】"));
	outtextxy(210, 170, _T("1.使用w a s d来控制角色移动。"));
	outtextxy(210, 195, _T("2.这是一款类魔塔的游戏，你需要一定策略."));
	outtextxy(210, 220, _T("3.你的每一步策略都决定你是否可以拯救公主."));
	outtextxy(210, 245, _T("4.勇士，一定要小心，否则你会永远被困在这里"));
	outtextxy(210, 270, _T("5.n来保存游戏，o打开音乐，i关闭音乐"));
	//返回
	Rect1 r;
	r.x = 240;
	r.y = 560;
	r.w = r.x + 125;
	r.h = r.y + 35;
	setlinecolor(RGB(255, 17, 102));
	if (IsInRect(mouseX, mouseY, r))
	{
		setfillcolor(RGB(255, 187, 119));
		//返回按键响应
		if (isMouseDown) GamePhase = 0;
	}
	else
		setfillcolor(RGB(255, 255, 204));
	fillrectangle(r.x, r.y, r.w, r.h);
	settextstyle(25, 9, _T("Verdana"));
	settextcolor(RGB(255, 51, 68));
	outtextxy(r.x + 5, r.y + 5, _T("返回菜单"));
}


void Draw()
{
	
	setlinecolor(RGB(28, 28, 28));
	setfillcolor(RGB(28, 28, 28));
	fillrectangle(0, 0, WIDDOW_WIDTH, WINDOW_HEIGHT);
	switch (GamePhase)
	{
	case 0:	StartDraw();	break;
	case 1:


		while (true)
		{



			drawmap();
			keydown();
		};


		break;
	case 2:	break;
	case 3: HelpDraw();	break;
	case 4: welcome();break;
	case 5: open_file(); while (true) {  drawmap(); keydown(); } break;
	}

}

int main()
{
	inputrole();
	loadresource();
	MOUSEMSG mmsg;
	hwnd = initgraph(WIDDOW_WIDTH, WINDOW_HEIGHT);
	SetWindowText(GetHWnd(), _T("RPG By:ypc"));
	//cleardevice();
	//设置黑色背景
	setbkmode(BLACK);
	settextcolor(BLACK);
	
	
	//BeginBatchDraw();
	while (true)
	{
		//处理鼠标消息
		while (MouseHit())
		{
			mmsg = GetMouseMsg();
			switch (mmsg.uMsg)
			{
			case WM_MOUSEMOVE:		mouseX = mmsg.x; mouseY = mmsg.y;	break;
			case WM_LBUTTONDOWN:	isMouseDown = true;					break;
			case WM_LBUTTONUP:		isMouseDown = false;				break;
			}
		}
		//绘图处理
		Draw();
		//显示缓存的绘制内容
		FlushBatchDraw();
		//HpSleep(30);
	}
	EndBatchDraw();

	closegraph();
	return 0;


}
