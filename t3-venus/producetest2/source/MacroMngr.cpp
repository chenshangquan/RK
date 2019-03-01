#include "stdafx.h"
#include "MacroMngr.h"
bool CMacroMngr::Translate( const String strMacro, u32 &dwMacro )
{
	u32 *pValue = Find( strMacro );
	if(	pValue == NULL )
	{	
		LOGEVENT("Î´Öª×Ö·û´®:%s \n", strMacro.c_str() );
		return false;
	}
	dwMacro = *pValue;
	return true;
}

bool CMacroMngr::RegMacro( const String strMacro, const u32 dwMacro )
{
	u32 *pValue = Find( strMacro );
	if(	pValue != NULL )
	{	
		return false;
	}
	u32 *dwValue = new u32;
	*dwValue = dwMacro;
	Add( strMacro, dwValue );
	return true;
}


