#include "MyForm.h"
#include <Windows.h>
#include <tchar.h>
using namespace Project1;
// ������� ������� WinMain (����� �����)
[STAThread]
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles(); // �������� ������� ����
	// ³��������� ������
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm); // ������ �����
	return 0;
}
