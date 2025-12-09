#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <windows.h>

DWORD WINAPI cheat_thread (LPVOID instance) {

	MessageBox(nullptr, L"H", L"W", MB_ICONHAND);
	
	while (!GetAsyncKeyState(VK_END) & 1){
		Sleep(100);
	}

	FreeLibraryAndExitThread(reinterpret_cast<HMODULE>(instance),0);
	return 0;
}


DWORD APIENTRY DllMain (HINSTANCE instance, DWORD reason, LPVOID){
	if (reason = DLL_PROCESS_ATTACH) {
		DisableThreadLibraryCalls(instance);

		HANDLE thread = CreateThread( nullptr, 0, cheat_thread, instance,0, nullptr);
		if (thread != INVALID_HANDLE_VALUE) {
			CloseHandle(thread);
		}
	}

	return false;
}