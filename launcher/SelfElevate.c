#include "SelfElevate.h"
#include <windows.h>
#include "Exec.h"
#include "VersionInfo.h"

HRESULT SelfElevate(LPWSTR args, LPDWORD code) {
	LPWSTR fileName = NULL;
	HRESULT hr = GetOwnFileName(&fileName);
	CHECK_HR_OR_RETURN(L"GetOwnFileName");
	hr = Exec(L"runas", fileName, args, NULL, SW_SHOWDEFAULT, TRUE, code);
	LocalFree(fileName);
	CHECK_HR_OR_RETURN(L"Exec");
	return hr;
}
