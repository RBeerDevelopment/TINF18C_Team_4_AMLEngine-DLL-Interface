# Microsoft Developer Studio Project File - Name="CAEX_ClassModel" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102


CFG=CAEX_ClassModel - Win32 Unicode Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "CAEX_ClassModel.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "CAEX_ClassModel.mak" CFG="CAEX_ClassModel - Win32 Unicode Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "CAEX_ClassModel - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "CAEX_ClassModel - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "CAEX_ClassModel - Win32 Unicode Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "CAEX_ClassModel - Win32 Unicode Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "CAEX_ClassModel - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /D "CAEX_ClassModel_EXPORTS" /D "_USRDLL" /MD /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /c /Zm500
# ADD CPP /D "CAEX_ClassModel_EXPORTS" /D "_USRDLL" /MD /nologo /W3 /GR /GX /O2 /I "..\Altova" /I "..\AltovaXML" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c /Zm500

# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32

# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo

LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /incremental:yes /machine:I386
# Begin Special Build Tool
TargetPath=.\Release\CAEX_ClassModel.dll
SOURCE="$(InputPath)"
PostBuild_Cmds=@mkdir ..\CAEX_ClassModelTest\Release >nul	@copy $(TargetPath) ..\CAEX_ClassModelTest\Release\ >nul
# End Special Build Tool


!ELSEIF  "$(CFG)" == "CAEX_ClassModel - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /D "CAEX_ClassModel_EXPORTS" /D "_USRDLL" /MDd /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /GZ /c /Zm500
# ADD CPP /D "CAEX_ClassModel_EXPORTS" /D "_USRDLL" /MDd /nologo /W3 /Gm /GR /GX /ZI /Od /I "..\Altova" /I "..\AltovaXML" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c /Zm500

# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32

# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo

LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# Begin Special Build Tool
TargetPath=.\Debug\CAEX_ClassModel.dll
SOURCE="$(InputPath)"
PostBuild_Cmds=@mkdir ..\CAEX_ClassModelTest\Debug >nul	@copy $(TargetPath) ..\CAEX_ClassModelTest\Debug\ >nul
# End Special Build Tool


!ELSEIF  "$(CFG)" == "CAEX_ClassModel - Win32 Unicode Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "UnicodeRelease"
# PROP BASE Intermediate_Dir "UnicodeRelease"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "UnicodeRelease"
# PROP Intermediate_Dir "UnicodeRelease"
# PROP Target_Dir ""
# ADD BASE CPP /D "CAEX_ClassModel_EXPORTS" /D "_USRDLL" /MD /nologo /W3 /GR /GX /O2 /I "..\Altova" /I "..\AltovaXML" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c /Zm500
# ADD CPP /D "CAEX_ClassModel_EXPORTS" /D "_USRDLL" /MD /nologo /W3 /GR /GX /O2 /I "..\Altova" /I "..\AltovaXML" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_UNICODE" /D "UNICODE" /Yu"stdafx.h" /FD /c /Zm500

# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32

# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo

LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /incremental:yes /machine:I386
# Begin Special Build Tool
TargetPath=.\UnicodeRelease\CAEX_ClassModel.dll
SOURCE="$(InputPath)"
PostBuild_Cmds=@mkdir ..\CAEX_ClassModelTest\UnicodeRelease >nul	@copy $(TargetPath) ..\CAEX_ClassModelTest\UnicodeRelease\ >nul
# End Special Build Tool


!ELSEIF  "$(CFG)" == "CAEX_ClassModel - Win32 Unicode Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "UnicodeDebug"
# PROP BASE Intermediate_Dir "UnicodeDebug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "UnicodeDebug"
# PROP Intermediate_Dir "UnicodeDebug"
# PROP Target_Dir ""
# ADD BASE CPP /D "CAEX_ClassModel_EXPORTS" /D "_USRDLL" /MDd /nologo /W3 /Gm /GR /GX /ZI /Od /I "..\Altova" /I "..\AltovaXML" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c /Zm500
# ADD CPP /D "CAEX_ClassModel_EXPORTS" /D "_USRDLL" /MDd /nologo /W3 /Gm /GR /GX /ZI /Od /I "..\Altova" /I "..\AltovaXML" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_UNICODE" /D "UNICODE" /FR /Yu"stdafx.h" /FD /GZ /c /Zm500

# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32

# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo

LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# Begin Special Build Tool
TargetPath=.\UnicodeDebug\CAEX_ClassModel.dll
SOURCE="$(InputPath)"
PostBuild_Cmds=@mkdir ..\CAEX_ClassModelTest\UnicodeDebug >nul	@copy $(TargetPath) ..\CAEX_ClassModelTest\UnicodeDebug\ >nul
# End Special Build Tool


!ENDIF 

# Begin Target

# Name "CAEX_ClassModel - Win32 Release"
# Name "CAEX_ClassModel - Win32 Debug"
# Name "CAEX_ClassModel - Win32 Unicode Release"
# Name "CAEX_ClassModel - Win32 Unicode Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\CAEX_ClassModel.cpp
# End Source File
# Begin Source File

SOURCE=.\CAEX_ClassModel-TypeInfo.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\CAEX_ClassModel.h
# End Source File
# Begin Source File

SOURCE=.\CAEX_ClassModel-TypeInfo.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Group "Type Headers"
# Begin Source File

SOURCE=.\type_.CAttributeType.h
#End Source File
# Begin Source File

SOURCE=.\type_.CAttributeValueRequirementType.h
#End Source File
# Begin Source File

SOURCE=.\type_.CCAEXBasicObject.h
#End Source File
# Begin Source File

SOURCE=.\type_.CCAEXObject.h
#End Source File
# Begin Source File

SOURCE=.\type_.CChangeMode.h
#End Source File
# Begin Source File

SOURCE=.\type_.CInterfaceClassType.h
#End Source File
# Begin Source File

SOURCE=.\type_.CInterfaceFamilyType.h
#End Source File
# Begin Source File

SOURCE=.\type_.CInternalElementType.h
#End Source File
# Begin Source File

SOURCE=.\type_.CMappingType.h
#End Source File
# Begin Source File

SOURCE=.\type_.CRoleClassType.h
#End Source File
# Begin Source File

SOURCE=.\type_.CRoleFamilyType.h
#End Source File
# Begin Source File

SOURCE=.\type_.CSystemUnitClassType.h
#End Source File
# Begin Source File

SOURCE=.\type_.CSystemUnitFamilyType.h
#End Source File
# Begin Source File

SOURCE=.\type_.CCAEX_ClassModel.h
#End Source File
# Begin Source File

SOURCE=.\type_.CCAEXFileType.h
#End Source File
# Begin Source File

SOURCE=.\type_.CDescriptionType.h
#End Source File
# Begin Source File

SOURCE=.\type_.CVersionType.h
#End Source File
# Begin Source File

SOURCE=.\type_.CRevisionType.h
#End Source File
# Begin Source File

SOURCE=.\type_.CCopyrightType.h
#End Source File
# Begin Source File

SOURCE=.\type_.CExternalReferenceType.h
#End Source File
# Begin Source File

SOURCE=.\type_.CInstanceHierarchyType.h
#End Source File
# Begin Source File

SOURCE=.\type_.CInterfaceClassLibType.h
#End Source File
# Begin Source File

SOURCE=.\type_.CRoleClassLibType.h
#End Source File
# Begin Source File

SOURCE=.\type_.CSystemUnitClassLibType.h
#End Source File
# Begin Source File

SOURCE=.\type_.CAttributeDataTypeType.h
#End Source File
# Begin Source File

SOURCE=.\type_.CRefSemanticType.h
#End Source File
# Begin Source File

SOURCE=.\type_.COrdinalScaledTypeType.h
#End Source File
# Begin Source File

SOURCE=.\type_.CNominalScaledTypeType.h
#End Source File
# Begin Source File

SOURCE=.\type_.CUnknownTypeType.h
#End Source File
# Begin Source File

SOURCE=.\type_.CSupportedRoleClassType.h
#End Source File
# Begin Source File

SOURCE=.\type_.CInternalLinkType.h
#End Source File
# Begin Source File

SOURCE=.\type_.CRoleRequirementsType.h
#End Source File
# Begin Source File

SOURCE=.\type_.CAttributeNameMappingType.h
#End Source File
# Begin Source File

SOURCE=.\type_.CInterfaceNameMappingType.h
#End Source File
# Begin Source File

SOURCE=.\type_.CExternalInterfaceType.h
#End Source File
# Begin Source File

SOURCE=.\type_xs.CENTITIES.h
#End Source File
# Begin Source File

SOURCE=.\type_xs.CENTITY.h
#End Source File
# Begin Source File

SOURCE=.\type_xs.CID.h
#End Source File
# Begin Source File

SOURCE=.\type_xs.CIDREF.h
#End Source File
# Begin Source File

SOURCE=.\type_xs.CIDREFS.h
#End Source File
# Begin Source File

SOURCE=.\type_xs.CNCName.h
#End Source File
# Begin Source File

SOURCE=.\type_xs.CNMTOKEN.h
#End Source File
# Begin Source File

SOURCE=.\type_xs.CNMTOKENS.h
#End Source File
# Begin Source File

SOURCE=.\type_xs.CNOTATION.h
#End Source File
# Begin Source File

SOURCE=.\type_xs.CName.h
#End Source File
# Begin Source File

SOURCE=.\type_xs.CQName.h
#End Source File
# Begin Source File

SOURCE=.\type_xs.CanySimpleType.h
#End Source File
# Begin Source File

SOURCE=.\type_xs.CanyType.h
#End Source File
# Begin Source File

SOURCE=.\type_xs.CanyURI.h
#End Source File
# Begin Source File

SOURCE=.\type_xs.Cbase64Binary.h
#End Source File
# Begin Source File

SOURCE=.\type_xs.Cboolean.h
#End Source File
# Begin Source File

SOURCE=.\type_xs.Cbyte.h
#End Source File
# Begin Source File

SOURCE=.\type_xs.Cdate.h
#End Source File
# Begin Source File

SOURCE=.\type_xs.CdateTime.h
#End Source File
# Begin Source File

SOURCE=.\type_xs.Cdecimal.h
#End Source File
# Begin Source File

SOURCE=.\type_xs.Cdouble.h
#End Source File
# Begin Source File

SOURCE=.\type_xs.Cduration.h
#End Source File
# Begin Source File

SOURCE=.\type_xs.Cfloat.h
#End Source File
# Begin Source File

SOURCE=.\type_xs.CgDay.h
#End Source File
# Begin Source File

SOURCE=.\type_xs.CgMonth.h
#End Source File
# Begin Source File

SOURCE=.\type_xs.CgMonthDay.h
#End Source File
# Begin Source File

SOURCE=.\type_xs.CgYear.h
#End Source File
# Begin Source File

SOURCE=.\type_xs.CgYearMonth.h
#End Source File
# Begin Source File

SOURCE=.\type_xs.ChexBinary.h
#End Source File
# Begin Source File

SOURCE=.\type_xs.Cint.h
#End Source File
# Begin Source File

SOURCE=.\type_xs.Cinteger.h
#End Source File
# Begin Source File

SOURCE=.\type_xs.Clanguage.h
#End Source File
# Begin Source File

SOURCE=.\type_xs.Clong.h
#End Source File
# Begin Source File

SOURCE=.\type_xs.CnegativeInteger.h
#End Source File
# Begin Source File

SOURCE=.\type_xs.CnonNegativeInteger.h
#End Source File
# Begin Source File

SOURCE=.\type_xs.CnonPositiveInteger.h
#End Source File
# Begin Source File

SOURCE=.\type_xs.CnormalizedString.h
#End Source File
# Begin Source File

SOURCE=.\type_xs.CpositiveInteger.h
#End Source File
# Begin Source File

SOURCE=.\type_xs.Cshort.h
#End Source File
# Begin Source File

SOURCE=.\type_xs.Cstring.h
#End Source File
# Begin Source File

SOURCE=.\type_xs.Ctime.h
#End Source File
# Begin Source File

SOURCE=.\type_xs.Ctoken.h
#End Source File
# Begin Source File

SOURCE=.\type_xs.CunsignedByte.h
#End Source File
# Begin Source File

SOURCE=.\type_xs.CunsignedInt.h
#End Source File
# Begin Source File

SOURCE=.\type_xs.CunsignedLong.h
#End Source File
# Begin Source File

SOURCE=.\type_xs.CunsignedShort.h
#End Source File
# Begin Source File

SOURCE=.\type_xs.CstringType.h
#End Source File
# Begin Source File

SOURCE=.\type_xs.CdateTimeType.h
#End Source File
# End Group
# End Group
# End Target
# End Project
