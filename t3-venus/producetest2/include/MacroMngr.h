class CMacroMngr : public IMacroMngr, public tmplContainer< String, u32 >
{
public:
	virtual bool Translate( const String strMarco, u32 &dwMacro );
	virtual bool RegMacro( const String strMacro, const u32 dwMacro );
};
