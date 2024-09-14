#include "MyForm.h"
#include <Windows.h>
#include <tchar.h>
using namespace Project1;
// Головна функція WinMain (точка входу)
[STAThread]
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles(); // включаємо візуальні стилі
	// Візуалізація тексту
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm); // запуск форми
	return 0;
}
