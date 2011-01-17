#include <Updater/Updater.h>

GUI_APP_MAIN
{
/*
typedef struct _SHELLEXECUTEINFO {
  DWORD     cbSize;
  ULONG     fMask;
  HWND      hwnd;
  LPCTSTR   lpVerb;
  LPCTSTR   lpFile;
  LPCTSTR   lpParameters;
  LPCTSTR   lpDirectory;
  int       nShow;
  HINSTANCE hInstApp;
  LPVOID    lpIDList;
  LPCTSTR   lpClass;
  HKEY      hkeyClass;
  DWORD     dwHotKey;
  union {
    HANDLE hIcon;
    HANDLE hMonitor;
  } DUMMYUNIONNAME;
  HANDLE    hProcess;
} SHELLEXECUTEINFO, *LPSHELLEXECUTEINFO;
*/
/*
::ShellExecute(0,							// owner window
               "runas",						// operation
               "C:\\Windows\\Notepad.exe",	// file
               0, // params					// 
               0, // directory
               SW_SHOWNORMAL);
*/
SHELLEXECUTEINFO info =
{
	sizeof(SHELLEXECUTEINFO),
	SEE_MASK_NOASYNC,// 0,//SEE_MASK_ASYNCOK,
	0,
	"runas",
	"C:\\Windows\\Notepad.exe",
	0, // parameters
	0, // directory
	SW_SHOW,
	0, // hHinsApp -- result handle or error code
	// REST AS DEFAULT -- NOT NEEDED
};

BOOL res = ShellExecuteEx(&info);
PromptOK("DONE, result is" + String(res ? "TRUE" : "FALSE"));
               return;


	Updater updater;
	updater
		.SetMaxVersion(1.6)
		.SetWebRoot("www.timberstruct.com/webupdater/updatertest")
		.UpdateManual()
		.SetCathegory("Office")
		.SetComment("A sample test program")
		.SetExtensions(Vector<String>() << "*.xxx" << "*.yyy")
		.SetIcon(updater.DefaultIcon())
		.DesktopIcon();
	
	// run updater -- DON'T change this !
	if(!updater.Run())
		return;
	
	// run the default prompts -- see Updater source code
	// if you need some fine-grained control
	if(!updater.DefaultPrompts())
		return;
	
	PromptOK("App version is 1.0");

}

