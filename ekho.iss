; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!
; online help: http://www.jrsoftware.org/ishelp/

[Setup]
AppName=Ekho
AppVerName=Ekho 8.6
AppPublisher=Cameron Wong
AppPublisherURL=https://eguidedog.net
AppSupportURL=https://eguidedog.net
AppUpdatesURL=https://eguidedog.net
DefaultDirName={pf}\Ekho
DefaultGroupName=Ekho
LicenseFile=COPYING
;InfoBeforeFile=install.txt
InfoAfterFile=README
OutputDir=./
OutputBaseFilename=ekho-mandarin-spanish-8.6
;SetupIconFile=C:\lab\e-guidedog\eGuideDog_TTS\eguidedog.ico
Compression=lzma
SolidCompression=yes

[Languages]
Name: "english"; MessagesFile: "compiler:Languages\English.isl"
Name: "spanish"; MessagesFile: "compiler:Languages\Spanish.isl"
Name: "chinesesimp"; MessagesFile: "compiler:Languages\ChineseSimp.isl"
Name: "chinesetrad"; MessagesFile: "compiler:Languages\ChineseTrad.isl"

;[Tasks]
;Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]
Source: "sapi5\TTSApp\Debug\ttsapp.exe"; DestDir: "{app}";
Source: "sapi5\Debug_x86\ekho_sapi5.dll"; DestDir: "{app}"; Flags: regserver promptifolder replacesameversion
Source: "sapi5\dll\libsndfile-1.dll"; DestDir: "{app}";
Source: "README"; DestDir: "{app}";
Source: "COPYING"; DestDir: "{app}";

Source: "ekho-data\COPYING-Festival"; DestDir: "{app}";
Source: "ekho-data\festival\*"; DestDir: "{app}\ekho-data\Festival\"; Flags: recursesubdirs;

;Source: "ekho-data\COPYING-jyutping-wong"; DestDir: "{app}\ekho-data\";
;Source: "ekho-data\zhy.dict"; DestDir: "{app}\ekho-data\";
;Source: "ekho-data\zhy_list"; DestDir: "{app}\ekho-data\";
;Source: "ekho-data\jyutping\*"; DestDir: "{app}\ekho-data\jyutping\";
;Source: "ekho-data\jyutping.index"; DestDir: "{app}\ekho-data\";
;Source: "ekho-data\jyutping.voice"; DestDir: "{app}\ekho-data\";

Source: "ekho-data\COPYING-pinyin-yali"; DestDir: "{app}\ekho-data\";
Source: "ekho-data\zh.dict"; DestDir: "{app}\ekho-data\";
;Source: "ekho-data\zh_list"; DestDir: "{app}\ekho-data\";
;Source: "ekho-data\zh_listx"; DestDir: "{app}\ekho-data\";
Source: "ekho-data\pinyin\*"; DestDir: "{app}\ekho-data\pinyin\";
;Source: "ekho-data\pinyin.index"; DestDir: "{app}\ekho-data\";
;Source: "ekho-data\pinyin.voice"; DestDir: "{app}\ekho-data\";

;Source: "ekho-data\COPYING-hakka-weicheng"; DestDir: "{app}\ekho-data\";
;Source: "ekho-data\ka_list"; DestDir: "{app}\ekho-data\";
;Source: "ekho-data\hakka\*"; DestDir: "{app}\ekho-data\hakka\";

;Source: "ekho-data\COPYING-tibetan-trinley"; DestDir: "{app}\ekho-data\";
;Source: "ekho-data\bo_list"; DestDir: "{app}\ekho-data\";
;Source: "ekho-data\tibetan\*"; DestDir: "{app}\ekho-data\tibetan\";

;Source: "ekho-data\COPYING-hangul-haesung"; DestDir: "{app}\ekho-data\";
;Source: "ekho-data\ko_list"; DestDir: "{app}\ekho-data\";
;Source: "ekho-data\hangul\*"; DestDir: "{app}\ekho-data\hangul\";

;Source: "ekho-data\COPYING-ngangien-qianshan"; DestDir: "{app}\ekho-data\";
;Source: "ekho-data\ngangien_list"; DestDir: "{app}\ekho-data\";
;Source: "ekho-data\ngangien\*"; DestDir: "{app}\ekho-data\ngangien\";

;Source: "ekho-data\tmp"; DestDir: "{app}\ekho-data\tmp"; Flags: createallsubdirs recursesubdirs;
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Registry]
;Root: HKLM; Subkey: "Software\Microsoft\Speech\Voices\Tokens\EkhoCantonese"; Flags: deletekey uninsdeletekey
Root: HKLM; Subkey: "Software\Microsoft\Speech\Voices\Tokens\EkhoMandarin"; Flags: deletekey uninsdeletekey
;Root: HKLM; Subkey: "Software\Microsoft\Speech\Voices\Tokens\EkhoHakka"; Flags: deletekey uninsdeletekey
;Root: HKLM; Subkey: "Software\Microsoft\Speech\Voices\Tokens\EkhoKorean"; Flags: deletekey uninsdeletekey
;Root: HKLM; Subkey: "Software\Microsoft\Speech\Voices\Tokens\EkhoTibetan"; Flags: deletekey uninsdeletekey
;Root: HKLM; Subkey: "Software\Microsoft\Speech\Voices\Tokens\EkhoNgangien"; Flags: deletekey uninsdeletekey
;Root: HKLM; Subkey: "Software\Microsoft\Speech\Voices\Tokens\EkhoEnglish"; Flags: deletekey uninsdeletekey

[Icons]
Name: "{group}\TTSApp"; Filename: "{app}\ttsapp.exe"; WorkingDir: "{app}"
Name: "{group}\Uninstall Ekho"; Filename: "{uninstallexe}"
;Name: "{commondesktop}\Ekho"; Filename: "{app}\ekho.bat"; WorkingDir: "{app}"; Tasks: desktopicon

[Run]
Filename: "{app}\ttsapp.exe"; Description: "{cm:LaunchProgram,Ekho}"; Flags: nowait postinstall skipifsilent

[Code]

procedure SetupVoice(RegVoice, VoiceName, Voice, Gender, Language: String);
begin
  RegWriteStringValue(HKEY_LOCAL_MACHINE,RegVoice,'',VoiceName);
  RegWriteStringValue(HKEY_LOCAL_MACHINE,RegVoice,'CLSID','{BD4AC8AD-7365-47b3-9FDB-923E70C5E40D}');
  RegWriteStringValue(HKEY_LOCAL_MACHINE,RegVoice,'EKHO_DATA_PATH',ExpandConstant('{app}') + '\ekho-data');
  RegWriteStringValue(HKEY_LOCAL_MACHINE,RegVoice,'Voice',Voice);

  RegWriteStringValue(HKEY_LOCAL_MACHINE,RegVoice + '\Attributes','Name',VoiceName);
  RegWriteStringValue(HKEY_LOCAL_MACHINE,RegVoice + '\Attributes','Gender',Gender);
  RegWriteStringValue(HKEY_LOCAL_MACHINE,RegVoice + '\Attributes','Age','Adult');
  RegWriteStringValue(HKEY_LOCAL_MACHINE,RegVoice + '\Attributes','Language',Language); // 409 for US, 404 for Taiwan, 408 for China
  RegWriteStringValue(HKEY_LOCAL_MACHINE,RegVoice + '\Attributes','Vendor','http://www.eguidedog.net');
end;



procedure CurStepChanged(CurStep: TSetupStep);
begin
  if CurStep = ssPostInstall then
  begin
;    SetupVoice('Software\Microsoft\Speech\Voices\Tokens\EkhoCantonese', 'Ekho Cantonese', 'jyutping', 'Male', '804'); // 0c04 for HongKong, but it doesn't work
    SetupVoice('Software\Microsoft\Speech\Voices\Tokens\EkhoMandarin', 'Ekho Mandarin', 'pinyin', 'Female', '804');
;    SetupVoice('Software\Microsoft\Speech\Voices\Tokens\EkhoHakka', 'Ekho Hakka', 'hakka', 'Male', '804');
;    SetupVoice('Software\Microsoft\Speech\Voices\Tokens\EkhoNgangien', 'Ekho Ngangien', 'ngangien', 'Male', '804');
;    SetupVoice('Software\Microsoft\Speech\Voices\Tokens\EkhoTibetan', 'Ekho Tibetan', 'tibetan', 'Female', '804');
;    SetupVoice('Software\Microsoft\Speech\Voices\Tokens\EkhoKorean', 'Ekho Korean', 'hangul', 'Female', '409'); // should be 412, but it doesn't work.
;    SetupVoice('Software\Microsoft\Speech\Voices\Tokens\EkhoEnglish', 'Ekho English', 'English', 'Male', '409');
  end;
end;
