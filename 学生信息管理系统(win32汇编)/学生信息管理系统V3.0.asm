.586
.model flat,stdcall
option casemap:none
;����������������������������������������������������������������������������������
;��Ҫ��ͷ�ļ�
;����������������������������������������������������������������������������������
include 		 windows.inc
include 		 user32.inc
include 		 kernel32.inc
include          Comdlg32.inc
include          msvcrt.inc
includelib   	 user32.lib
includelib 	 kernel32.lib
includelib      Comdlg32.lib;װ��ͨ�öԻ����
includelib msvcrt.lib;��ϱ�̵���C����atio����Ŀ��ļ�
atoi proto C:dword,:vararg;����һ��atoi��һ��C���Ժ���
;itoa proto C:dword,:vararg;����һ��itoa��һ��C���Ժ���
;����������������������������������������������������������������������������������
;ѧ���ṹ��Ķ���
;����������������������������������������������������������������������������������
BIRTHDAY STRUCT
		 YEAR dword 2 dup(?)
		 MONTH DWORD ?
		 DAY DWORD ?
BIRTHDAY ENDS
SCORCE STRUCT
		 ENGLISH DWORD ?
		 CLANGUAGE DWORD ?
		 MATH DWORD ?
		 TOTAL DWORD ?
SCORCE ENDS
STUDENT STRUCT
		 ID DWORD 4 dup(?)
		 SNAME DWORD 4 dup(?)
		 SEXY DWORD 1 dup(?)
		 BIRTH BIRTHDAY <>
		 SCOR SCORCE <>
STUDENT ENDS
;������������������������������������������������������������������������������������
;��Դ�Ķ���
;������������������������������������������������������������������������������������
DLG_MAIN EQU 1H
ICO_MAIN EQU 1300H
IDST_STATE EQU 1014H
IDED_STUID EQU 1100H
IDED_NAME EQU 1101H
IDED_SEXY EQU 1102H
IDED_YEAR EQU 1103H
IDED_MONTH EQU 1104H
IDED_DAY EQU 1105H
IDED_ENGLISH EQU 1106H
IDED_CLANGUAGE EQU 1107H
IDED_MATH EQU 1108H
IDED_TOTAL EQU 1109H
IDED_OUTTEXT EQU 110AH
IDBU_READ EQU 1200H
IDBU_SAVE EQU 1201H
IDBU_NAMEPLUSORDER EQU 1202H
IDBU_TOTALPLUSORDER EQU 1203H
IDBU_IDFIND EQU 1204H
IDBU_NAMEFIND EQU 1205H
IDBU_AVERAGE EQU 1206H
IDBU_EVERYNUMBER EQU 1207H
IDBU_SHOWINFORMATION EQU 1208H
IDBU_CLEARSTRUCT EQU 1209H
IDBU_CLEARUI EQU 120AH
;����������������������������������������������������������������������������������
;��Ҫ�����Ķ���
;����������������������������������������������������������������������������������
MAX_STUDENTNUMBER EQU 30;�������ѧ������
.data?
STU STUDENT MAX_STUDENTNUMBER dup(<>);STUDENT�ṹ������
hInstance dd ?;ģ��ʵ�����
hWinMain dd ?;�����ھ��
hIcon dd ?;ͼ����
hFile dd ?;�򿪵��ļ����
hNewFile dd ?;�½��ļ����
SizeStructStudent dd ?;STUDENT�ṹ��Ĵ�С
TotalStudentNumber dd ?;ѧ��������ͳ��
STRUCTReadFileName OPENFILENAME <>;
TotalPathFileName db MAX_PATH DUP(?);ȫ·���ļ�����
FileContainBuffer db 8000 dup(?);��Ӳ�̴򿪵��ļ����ݻ��嵽�ĵط�
HaveReadByte dd ?;��Ӳ�̴򿪵��ļ����ݸ�FileContainBuffer���ֽ���
ToTextBuffer db 8000 dup(?);ת���õ��ļ�׼���ŵ�Ӳ�̵Ļ�����
NewFileName db MAX_PATH DUP (?)
NewFileHaveWriteByte dd ?
BufferToIDED_OUTTEXT db 8000 dup (?)

test1 db 18 dup(?)
.data
ZeroItem db ' ',0
SexMan db '��',0
SexWoman db 'Ů',0
FileCharacter db '�ı��ļ���*.txt��',0,'*.txt',0,'�����ļ���*.*��',0,'*.*',0,0
NoFileHandle db '���ļ����ʧ�ܣ�',0
ReadToFlieContainBufferFalse db '��ȡ�ļ����ڴ滺����ʧ�ܣ�',0
ReadToFileContainBufferTrue db '��ȡ�ļ����ڴ滺�����ɹ���',0
CaptionNotice db 'С��ʾ��',0
CaptionError db '��������',0
SucceedRead db '�ı��ļ��ѳɹ��洢���ṹ�����飡',0
NewFileNameSuffix db 'NEW.txt',0
CanNotFindStudent db 'û���ҵ���ѧ����',0
HaveFindStudent db '�Ѿ��ҵ���ѧ����',0

NoStudentCanStatistic db 'û��ѧ�����޷�ͳ����Ů������',0
NoStudentCanCalculate db 'û��ѧ�����޷��������ƽ��������',0
NoStudentInformation db 'û��ѧ�����޷���ѯ��Ϣ��',0
NoStudentCanSave db 'û��ѧ���������ᱣ�浽Ӳ���ļ���',0
NoStudentCanOrder db 'û��ѧ������ѧ������С��2������������',0


AllStudentInformation db '����ѧ������Ϣ��',0dh,0ah,0
HaveFindStudentInformation db '�Ѿ���ѯ����ѧ����Ϣ��',0dh,0ah,0
ThreeCourseAverageInformation db '���ſγ̵�ƽ���ɼ���',0dh,0ah,0
ManWomanTotalNumberInformation db '��Ů����ͳ����Ϣ��',0dh,0ah,0
szID db                            'ѧ�ţ�                                 ',0
szName db        '������                                 ',0
szSexy db          '�Ա�                                 ',0
szBirthYear db    '������ݣ�                         ',0
szBirthMonth db '�����·ݣ�                         ',0
szBirthDay   db   '�������ڣ�                         ',0
szEnglish   db     'Ӣ��ɼ���                         ',0
szCLanguage  db 'C���Գɼ���                       ',0
szMath  db          '��ѧ�ɼ���                         ',0
szTotal db           '�ܳɼ���                             ',0
szSingleAverage db 'ƽ���ɼ���                           ',0
szAverageEnglish db         'Ӣ��ƽ���ɼ���                    ',0
szAverageCLanguage db   'C����ƽ���ɼ���                  ',0
szAverageMath db            '��ѧƽ���ɼ���                    ',0
szTotalMan db    '������������                       ',0
szTotalWoman db'Ů����������                       ',0
szTotalAllSexy db '��Ů��������                       ',0
FormatToD db '%u',0

StatesHaveSaveToStruct db '�Ѿ����浽�ṹ�壡',0
StatesHaveClearRAM db '�ڴ��Ѿ������',0
StatesHaveClearUI db '�ı�������Ѿ������',0
StatesHaveSaveToFile db '�Ѿ����浽Ӳ���ı��ļ���',0
StatesHaveReadFile db '�ļ��Ѿ���ȡ������Լ�����ȡһ���ļ���',0
StatesHaveOrderNamePlus db '��Ӣ����ĸ��˳�������Ѿ���ɣ�����ʾ��Ϣ�鿴��',0
StatesHaveOrderTotalScorceSub db '���ֵܷݼ������Ѿ���ɣ�����ʾ��Ϣ�鿴��',0
StatesHaveShowFindInformation db '���ҵ������Ѿ���ʾ��',0
StatesHaveCalculateAverage db '���ſγ̵�ƽ�������Ѿ�������ɣ�������ʾ��',0
StatesHaveShowSexyStatistic db '�Ա���Ϣ�Ѿ�ͳ����ɣ�������ʾ��',0
StatesHaveShowAllInformation db '������Ϣ�Ѿ���ʾ��',0
StatesHaveSaveFromUI db '�������Ϣ�Ѿ����棡',0

formatd db '%d',0
formats db '%s',0
a db 'A',0
b db 'B',0
.code
;����������������������������������������������������������������������������������
;���ؽ���ʱ���һϵ�г�ʼ������
;����������������������������������������������������������������������������������
_InitialWork proc
pushad
		 		 mov TotalStudentNumber,0
		 		 mov SizeStructStudent,sizeof STUDENT
		 		 invoke LoadIcon,hInstance,ICO_MAIN
		 		 mov hIcon,eax
		 		 invoke RtlZeroMemory,addr STU,sizeof STU
		 		 invoke SendMessage,hWinMain,WM_SETICON,ICON_BIG,eax
		 		 invoke SendDlgItemMessage,hWinMain,IDED_SEXY,CB_ADDSTRING,NULL,ADDR SexMan;��ʼ����Ͽ�
		 		 invoke SendDlgItemMessage,hWinMain,IDED_SEXY,CB_ADDSTRING,NULL,ADDR SexWoman
		 		 invoke SendDlgItemMessage,hWinMain,IDED_STUID,EM_LIMITTEXT,8,0;���·ֱ��޶��ַ�������
		 		 invoke SendDlgItemMessage,hWinMain,IDED_NAME,EM_LIMITTEXT,8,0
		 		 invoke SendDlgItemMessage,hWinMain,IDED_YEAR,EM_LIMITTEXT,4,0
		 		 invoke SendDlgItemMessage,hWinMain,IDED_MONTH,EM_LIMITTEXT,2,0
		 		 invoke SendDlgItemMessage,hWinMain,IDED_DAY,EM_LIMITTEXT,2,0
		 		 invoke SendDlgItemMessage,hWinMain,IDED_ENGLISH,EM_LIMITTEXT,3,0
		 		 invoke SendDlgItemMessage,hWinMain,IDED_CLANGUAGE,EM_LIMITTEXT,3,0
		 		 invoke SendDlgItemMessage,hWinMain,IDED_MATH,EM_LIMITTEXT,3,0
		 		 invoke SendDlgItemMessage,hWinMain,IDED_TOTAL,EM_LIMITTEXT,3,0
popad
		 		 ret
_InitialWork endp
;����������������������������������������������������������������������������������
;���û������UI��������ݱ��浽�ṹ������
;����������������������������������������������������������������������������������
_SaveToStructFromUI proc
pushad
		 assume ebx :ptr STUDENT
		 lea ebx,STU
		 mov edx,0
		 mov eax,TotalStudentNumber
		 mul SizeStructStudent
		 add ebx,eax
		 
		 invoke GetDlgItemText,hWinMain,IDED_STUID,addr [ebx].ID,16;��ȡid�Ÿ�ֵ
		 invoke GetDlgItemText,hWinMain,IDED_NAME,addr [ebx].SNAME,16
		 invoke	SendDlgItemMessage,hWinMain,IDED_SEXY,CB_GETCURSEL,0,0
		 .if eax==0
		 		 invoke lstrcpy,addr [ebx].SEXY,addr SexMan
		 .else
		 		 invoke lstrcpy,addr [ebx].SEXY,addr SexWoman
		 .endif
		 invoke GetDlgItemText,hWinMain,IDED_YEAR,addr [ebx].BIRTH.YEAR,8
		 invoke GetDlgItemText,hWinMain,IDED_MONTH,addr [ebx].BIRTH.MONTH,4
		 invoke GetDlgItemText,hWinMain,IDED_DAY,ADDR [ebx].BIRTH.DAY,4
		 invoke GetDlgItemText,hWinMain,IDED_ENGLISH,ADDR [ebx].SCOR.ENGLISH,4
		 invoke GetDlgItemText,hWinMain,IDED_CLANGUAGE,ADDR [ebx].SCOR.CLANGUAGE,4
		 invoke GetDlgItemText,hWinMain,IDED_MATH,ADDR [ebx].SCOR.MATH,4
		 ;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
		 ;ת�����Ʒ���������Ϊ�����������ٰѿ�������ת����ASCII�ַ��������õ��ִܷ���
		 ;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
		 ;invoke atoi,addr [ebx].SCOR.ENGLISH
		 ;add @TotalScorce,eax
		 ;invoke wsprintf,addr @AsciiTotalScorce,addr FormatToD,@TotalScorce
		 ;invoke SetDlgItemText,hWinMain,IDED_TOTAL,addr @AsciiTotalScorce
		 
		 
		 ;invoke atoi,addr [ebx].SCOR.CLANGUAGE
		 ;add @TotalScorce,eax
		 ;invoke wsprintf,addr @AsciiTotalScorce,addr FormatToD,@TotalScorce
		 ;invoke SetDlgItemText,hWinMain,IDED_TOTAL,addr @AsciiTotalScorce
		 
		 
		 ;invoke atoi,addr [ebx].SCOR.MATH
		 ;add @TotalScorce,eax
		 ;invoke wsprintf,addr @AsciiTotalScorce,addr FormatToD,@TotalScorce
		 ;invoke SetDlgItemText,hWinMain,IDED_TOTAL,addr @AsciiTotalScorce
		 
		 invoke GetDlgItemText,hWinMain,IDED_TOTAL,ADDR [ebx].SCOR.TOTAL,4
		 assume ebx:nothing
		 inc TotalStudentNumber
popad
ret
_SaveToStructFromUI endp
;����������������������������������������������������������������������������������
;�����нṹ���е����ݱ��浽Ӳ��TEXT�ļ�
;����������������������������������������������������������������������������������
_SaveToBufferFromStruct proc
		 local @TotalStudentNumber:dword;ѧ��������
		 local @SpaceBuffer[2]:byte;�ո�ASCII�ַ�
		 local @EnterBuffer1[1]:dword;����ASCII�ַ�
		 local @EnterBuffer2[1]:dword;�س�ASCII�ַ�
pushad
		 invoke RtlZeroMemory,addr ToTextBuffer,sizeof ToTextBuffer
		 push TotalStudentNumber
		 pop @TotalStudentNumber
		 mov @SpaceBuffer,' '
		 mov eax,0dh
		 mov @EnterBuffer1,eax
		 mov eax,0ah
		 mov @EnterBuffer2,eax
		 assume ebx:ptr STUDENT
		 lea ebx,STU
		 .while @TotalStudentNumber >0
		 		 invoke lstrcat,addr ToTextBuffer,addr [ebx].ID
		 		 invoke lstrcat,addr ToTextBuffer,addr @SpaceBuffer
		 		 invoke lstrcat,addr ToTextBuffer,addr [ebx].SNAME
		 		 invoke lstrcat,addr ToTextBuffer,addr @SpaceBuffer
		 		 invoke lstrcat,addr ToTextBuffer,addr [ebx].SEXY
		 		 invoke lstrcat,addr ToTextBuffer,addr @SpaceBuffer
		 		 invoke lstrcat,addr ToTextBuffer,addr [ebx].BIRTH.YEAR
		 		 invoke lstrcat,addr ToTextBuffer,addr @SpaceBuffer
		 		 invoke lstrcat,addr ToTextBuffer,addr [ebx].BIRTH.MONTH
		 		 invoke lstrcat,addr ToTextBuffer,addr @SpaceBuffer
		 		 invoke lstrcat,addr ToTextBuffer,addr [ebx].BIRTH.DAY
		 		 invoke lstrcat,addr ToTextBuffer,addr @SpaceBuffer
		 		 invoke lstrcat,addr ToTextBuffer,addr [ebx].SCOR.ENGLISH
		 		 invoke lstrcat,addr ToTextBuffer,addr @SpaceBuffer
		 		 invoke lstrcat,addr ToTextBuffer,addr [ebx].SCOR.CLANGUAGE
		 		 invoke lstrcat,addr ToTextBuffer,addr @SpaceBuffer
		 		 invoke lstrcat,addr ToTextBuffer,addr [ebx].SCOR.MATH
		 		 invoke lstrcat,addr ToTextBuffer,addr @SpaceBuffer
		 		 invoke lstrcat,addr ToTextBuffer,addr [ebx].SCOR.TOTAL
		 		 invoke lstrcat,addr ToTextBuffer,addr @EnterBuffer1
		 		 invoke lstrcat,addr ToTextBuffer,addr @EnterBuffer2
		 		 add ebx,SizeStructStudent;ָ����һ��ṹ��
		 		 dec @TotalStudentNumber
		 .endw
popad
ret
_SaveToBufferFromStruct endp


__WriteToFileFromBuffer proc
pushad
		 assume ebx:nothing
		 invoke lstrcpy,addr NewFileName,addr TotalPathFileName
		 invoke lstrcat,addr NewFileName,addr NewFileNameSuffix
		 invoke CreateFile,addr NewFileName,GENERIC_WRITE,FILE_SHARE_READ,0,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,0
		 .if eax== INVALID_HANDLE_VALUE
		 		 invoke MessageBox,hWinMain,addr NoFileHandle,addr CaptionError,MB_OK OR MB_ICONWARNING
		 .else
		 		 mov hNewFile,eax
		 		 invoke WriteFile,hNewFile,addr ToTextBuffer,length ToTextBuffer,addr NewFileHaveWriteByte,NULL
		 		 invoke SetDlgItemText,hWinMain,IDST_STATE,addr StatesHaveSaveToFile
		 .endif
		 invoke CloseHandle,hNewFile
popad
		 ret
__WriteToFileFromBuffer endp
;����������������������������������������������������������������������������������
;�ѻ������е����ݱ��浽�ṹ������
;����������������������������������������������������������������������������������
__SaveToStructFromFileContainBuffer proc @IStructCount
		 local @HaveReadByte:dword;FileContainBuffer����������ƫ����
		 local @Flags:dword;��Ϊ��ȡ���ṹ��ı�ǣ�=1�ʹ浽�꣬=4�ʹ浽��ѧ�ɼ�
		 local @Buffer[4]:dword
pushad
		 ;invoke RtlZeroMemory,addr STU,sizeof STU
		 assume esi:ptr STUDENT
		 lea esi,STU
		 mov edx,0
		 mov eax,@IStructCount
		 mul SizeStructStudent
		 add esi,eax
		 lea ebx,FileContainBuffer
		 push HaveReadByte
		 pop @HaveReadByte;
		 mov @Flags,0
		 .while @HaveReadByte
		 		 invoke RtlZeroMemory,addr @Buffer,sizeof @Buffer
		 		 lea edi,@Buffer
		 		 mov ax,[ebx]
		 		 mov ah,0
		 		 ;.if al==NULL;��ȡ���ļ������������1
		 		 ;		 inc TotalStudentNumber
		 		 ;.endif
		 		 .break .if al==NULL
		 		 .if al<= 57 && al >= 48;��������
		 		 		 mov [edi],al
		 		 		 inc edi
		 		 		 .while TRUE
		 		 		 		 inc ebx
		 		 		 		 dec @HaveReadByte
		 		 		 		 mov al,[ebx]
		 		 		 		 .break .if al==32||al==13||al==10||al==NULL;�����ֺ��пո��з���س������ļ��������ʱ����
		 		 		 		 mov [edi],al
		 		 		 		 inc edi
		 		 		 .endw
		 		 		 .if @Flags==0
		 		 		 		 invoke lstrcpy,addr [esi].ID,addr @Buffer
		 		 		 .elseif @Flags==1
		 		 		 		 invoke lstrcpy,addr [esi].BIRTH.YEAR,addr @Buffer
		 		 		 .elseif @Flags==2
		 		 		 		 invoke lstrcpy,addr [esi].BIRTH.MONTH,addr @Buffer
		 		 		 .elseif @Flags==3
		 		 		 		 invoke lstrcpy,addr [esi].BIRTH.DAY,addr @Buffer
		 		 		 .elseif @Flags==4
		 		 		 		 invoke lstrcpy,addr [esi].SCOR.ENGLISH,addr @Buffer
		 		 		 .elseif @Flags==5
		 		 		 		 invoke lstrcpy,addr [esi].SCOR.CLANGUAGE,addr @Buffer
		 		 		 .elseif @Flags==6
		 		 		 		 invoke lstrcpy,addr [esi].SCOR.MATH,addr @Buffer
		 		 		 .elseif @Flags==7
		 		 		 		 invoke lstrcpy,addr [esi].SCOR.TOTAL,addr @Buffer
		 		 		 .endif
		 		 		 inc @Flags
		 		 .elseif al>=65 && al<=90 || al>=97 && al <=122;��д��Сд��ĸ�Ĵ���
		 		 		 mov [edi],al
		 		 		 inc edi
		 		 		 .while TRUE;�͵����ػ���������һ������
		 		 		 		 inc ebx
		 		 		 		 dec @HaveReadByte
		 		 		 		 mov al,[ebx]
		 		 		 		 .break .if al==32
		 		 		 		 mov [edi],al
		 		 		 		 inc edi
		 		 		 .endw
		 		 		 invoke lstrcpy,addr [esi].SNAME,addr @Buffer
		 		 .elseif al==13||al==10;||al ==32;�س����пո񲻴���
		 		 		 add esi,SizeStructStudent;���д��������������һ�д���
		 		 		 mov @Flags,0
		 		 		 inc TotalStudentNumber;ѧ����������1
		 		 .elseif al>=0A0h && al <= 0FEh;������
		 		 		 mov [edi],al
		 		 		 inc edi
		 		 		 .while TRUE;���͵����ػ���������һ������
		 		 		 		 inc ebx
		 		 		 		 dec @HaveReadByte
		 		 		 		 mov al,[ebx]
		 		 		 		 .break .if al==32
		 		 		 		 mov [edi],al
		 		 		 		 inc edi
		 		 		 .endw
		 		 		 mov eax,@Buffer [2];�ж�@Buffer�ĵ�3�ֽ��ж���Ů
		 		 		 .if eax==0;���ַ�����Ůʱ�ֱ��Ӧ�洢���ṹ��
		 		 		 		 invoke lstrcpy,addr [esi].SEXY,addr @Buffer
		 		 		 .else
		 		 		 		 invoke lstrcpy,addr [esi].SNAME,addr @Buffer
		 		 		 .endif
		 		 .endif
		 		 dec @HaveReadByte
		 		 inc ebx;������һ���������ֽ�
		 .endw
		 assume esi:nothing
popad
ret
__SaveToStructFromFileContainBuffer endp
;����������������������������������������������������������������������������������
;��Ӳ�̼���TEXT�ļ���Ӧ���ص����������ҵ����ӳ���ѻ��������ݱ��浽�ṹ������
;����������������������������������������������������������������������������������
_LoadFile proc
pushad
		 invoke RtlZeroMemory,addr STRUCTReadFileName,sizeof STRUCTReadFileName;��ʼ��READFILILENAME
		 mov STRUCTReadFileName.lStructSize,sizeof STRUCTReadFileName;ָ���ṹ�峤��
		 push hWinMain
		 pop STRUCTReadFileName.hWndOwner;ָ���ļ�����������
		 mov STRUCTReadFileName.lpstrFilter,offset FileCharacter;�����ļ�����
		 mov STRUCTReadFileName.lpstrFile,offset TotalPathFileName;����ȫ·���ļ�������
		 mov STRUCTReadFileName.nMaxFile,sizeof TotalPathFileName;�����ļ���ȫ·������������
		 mov STRUCTReadFileName.Flags,OFN_FILEMUSTEXIST or OFN_PATHMUSTEXIST;�趨�û�ֻ�ܴ��Ѿ����ڵ��ļ�
		 invoke GetOpenFileName,offset STRUCTReadFileName;���ļ�ͨ�öԻ���
		 invoke CreateFile,addr TotalPathFileName,GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL
		 .if eax==INVALID_HANDLE_VALUE;�жϷ��صľ������û�л�ȡ��ȷ���ļ�ָ��
		 		 invoke MessageBox,hWinMain,addr NoFileHandle,addr CaptionError,MB_OK OR MB_ICONWARNING
		 .else;�ɹ���
		 		 mov hFile,eax
		 		 invoke ReadFile,hFile,addr FileContainBuffer,sizeof FileContainBuffer,addr HaveReadByte,NULL;��ȡ�ļ����ڴ滺����
		 		 .if eax==0
		 		 		 invoke MessageBox,hWinMain,addr ReadToFlieContainBufferFalse,addr CaptionError,MB_OK OR MB_ICONWARNING;��ȡʱ���ִ���
		 		 .else;��ȡ��ȷ�Ĵ���
		 		 		 invoke SetDlgItemText,hWinMain,IDST_STATE,addr StatesHaveReadFile
		 		 		 invoke __SaveToStructFromFileContainBuffer,TotalStudentNumber;�ѻ������еĵ������浽����
		 		 .endif
		 		 invoke CloseHandle,hFile
		 .endif
popad
ret
_LoadFile endp
;����������������������������������������������������������������������������������
;��ѧ�Ų���ѧ����Ϣ��eax�Ƿ���ֵ��0û�ҵ��������ʾ���ҵĵڼ���ѧ�����ӽ���ѧ�ų���ȡҪ���ҵ�ѧ����ѧ��
;����������������������������������������������������������������������������������
_IDFind proc
		 local @WillFindID[4]:dword
		 local @Buffer[4]:dword
		 local @ICountStudent:dword
		 local @TotalStudent:dword
		 local @HaveFindFlags:dword
		 local @RealAverageScorce:dword
		 local @ASCIIAverageScorce:dword
		 local @EnterBuffer1[1]:dword;����ASCII�ַ�
		 local @EnterBuffer2[1]:dword;�س�ASCII�ַ�
pushad
		 push TotalStudentNumber
		 pop @TotalStudent
		 .if @TotalStudent==0
		 		 invoke MessageBox,hWinMain,addr NoStudentInformation,addr CaptionNotice,MB_OK OR MB_ICONWARNING
		 .else
		 assume esi:ptr STUDENT
		 lea esi,STU
		 mov @HaveFindFlags,0
		 mov @ICountStudent,0
		 invoke GetDlgItemText,hWinMain,IDED_STUID,addr @WillFindID,16
		 .while @TotalStudent>0
		 		 invoke lstrcpy,addr @Buffer,addr [esi].ID
		 		 invoke lstrcmp,addr @WillFindID,addr @Buffer
		 		 .if eax==0
		 		 		 mov eax,1
		 		 		 mov @HaveFindFlags,eax
		 		 		 .break
		 		 .endif
		 		 add esi,SizeStructStudent
		 inc @ICountStudent
		 dec @TotalStudent
		 .endw
		 mov eax,TotalStudentNumber
		 .if @HaveFindFlags==1 && @ICountStudent<eax
		 		 mov @EnterBuffer1,0dh
		 		 mov @EnterBuffer2,0ah
		 		 lea esi,STU
		 		 mov eax,@ICountStudent
		 		 mov edx,0
		 		 mul SizeStructStudent
		 		 add esi,eax
		 		 invoke lstrcpy,addr BufferToIDED_OUTTEXT,addr HaveFindStudentInformation
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr szID
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr [esi].ID
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @EnterBuffer1
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @EnterBuffer2
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr szName
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr [esi].SNAME
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @EnterBuffer1
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @EnterBuffer2
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr szSexy
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr [esi].SEXY
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @EnterBuffer1
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @EnterBuffer2
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr szBirthYear
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr [esi].BIRTH.YEAR
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @EnterBuffer1
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @EnterBuffer2
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr szBirthMonth
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr [esi].BIRTH.MONTH
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @EnterBuffer1
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @EnterBuffer2
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr szBirthDay
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr [esi].BIRTH.DAY
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @EnterBuffer1
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @EnterBuffer2
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr szEnglish
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr [esi].SCOR.ENGLISH
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @EnterBuffer1
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @EnterBuffer2
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr szCLanguage
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr [esi].SCOR.CLANGUAGE
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @EnterBuffer1
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @EnterBuffer2
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr szMath
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr [esi].SCOR.MATH
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @EnterBuffer1
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @EnterBuffer2
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr szTotal
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr [esi].SCOR.TOTAL
		 		 
		 		 ;������������������������������������������������������������������������
		 		 ;����ѧ�����˵�ƽ������
		 		 ;������������������������������������������������������������������������
		 		 mov ebx,3
		 		 invoke atoi,addr [esi].SCOR.TOTAL
		 		 mov edx,0
		 		 div ebx
		 		 mov @RealAverageScorce,eax
		 		 invoke wsprintf,addr @ASCIIAverageScorce,addr FormatToD,@RealAverageScorce
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @EnterBuffer1
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @EnterBuffer2
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr szSingleAverage
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @ASCIIAverageScorce
		 		 
		 		 
		 		 invoke SetDlgItemText,hWinMain,IDST_STATE,addr StatesHaveShowFindInformation
		 		 invoke SetDlgItemText,hWinMain,IDED_OUTTEXT,addr BufferToIDED_OUTTEXT
		 		 invoke RtlZeroMemory,addr BufferToIDED_OUTTEXT,sizeof BufferToIDED_OUTTEXT
		 .else
		 		 invoke MessageBox,hWinMain,addr CanNotFindStudent,addr CaptionNotice,MB_OK OR MB_ICONWARNING
		 .endif
		 assume esi:nothing
		 .endif
popad
ret
_IDFind endp
;����������������������������������������������������������������������������������
;ʹ��ǰ���ǣ������ҵ������е��������밴��Ӣ����ĸ���˳�����кã�������Ҳ���ɹ������������ң����۰��㷨���ң�
;����������������������������������������������������������������������������������
_NameFind proc
		 local @WillFindName[4]:dword;��Ҫ���ҵ�����
		 local @Buffer[4]:dword;�ṹ���е����ֻ��壬Ϊ�Ա���׼��
		 local @ICountStudent:dword;�Ѿ����ҵ������ֵ�������
		 local @HaveFindFlags:dword;�Ѿ����ҵ��ı�ǣ�1��ʾ���ҵ���0��ʾû�в��ҵ�
		 local @EnterBuffer1[1]:dword;����ASCII�ַ�
		 local @EnterBuffer2[1]:dword;�س�ASCII�ַ�
		 local @ASCIIAverageScorce:dword;�Ѿ�������ɵ�ASCII��ƽ����
		 local @RealAverageScorce:dword;�Ѿ������ʵ����ƽ����
		 local @IHalf:dword;�۰���ҵ���λ������
		 local @End:dword;�۰���ҵ�ĩλ������
		 local @Begin:dword;�۰���ҵ���λ������
pushad
		 invoke GetDlgItemText,hWinMain,IDED_NAME,addr @WillFindName,16;������������ȡ��Ҫ���ҵ�����
		 .if TotalStudentNumber==0||@WillFindName==0;���û��ѧ���򲻻����
		 		 invoke MessageBox,hWinMain,addr NoStudentInformation,addr CaptionNotice,MB_OK OR MB_ICONWARNING;������ʱ���ֵ���ʾ��Ϣ
		 .else;��ѧ�������
		 assume esi:ptr STUDENT;һЩ��ʼ������
		 lea esi,STU
		 mov @HaveFindFlags,0;����Ѱ�ұ��Ϊ0���ڳ������ҵ���������Ϊ1
		 mov @Begin,0
		 push TotalStudentNumber
		 pop @End;��ʼ���������
		 ;����������������������������������������������������������������������������
		 ;����ѭ�������۰��㷨��
		 ;����������������������������������������������������������������������������
		 .while @Begin<=eax
		 		 lea esi,STU;ȡ��λƫ����
		 		 
		 		 mov eax,@End;��ȡ��λ������
		 		 sub eax,@Begin
		 		 mov edx,0
		 		 mov ebx,2
		 		 div ebx
		 		 add eax,@Begin
		 		 mov @IHalf,eax;��λ����ȡ���
		 		 
		 		 mov eax,@IHalf;����λ�����������������ֵ�ƫ����
		 		 mov edx,0
		 		 mul SizeStructStudent
		 		 add esi,eax;����ƫ�������
		 		 
		 		 invoke lstrcpy,addr @Buffer,addr [esi].SNAME	
		 		 invoke lstrcmp,addr @WillFindName,addr @Buffer;�Ƚ���λ����������������ҵ�����
		 		 .if eax==0;ǡ�����
		 		 		 mov @HaveFindFlags,1
		 		 		 push @IHalf
		 		 		 pop @ICountStudent
		 		 		 .break
		 		 .elseif eax==1;��Ҫ���ҵ����ִ�����λ������������
		 		 		 inc @IHalf
		 		 		 push @IHalf
		 		 		 pop @Begin
		 		 .elseif eax==-1;��Ҫ���ҵ�����С����λ������������
		 		 		 dec @IHalf
		 		 		 push @IHalf
		 		 		 pop @End
		 		 .endif
		 		 
		 		 mov eax,@End;ѭ����������@Begin<=@End
		 .endw
		 ;������������������������������������������������������������������������������
		 ;@ICountStudent���Ѿ����ҵ���ѧ��������������@HaveFindFlags���Ѿ����ҵ��ı�ǣ���ʾ���ҵ�����Ϣ
		 ;������������������������������������������������������������������������������
		 mov eax,TotalStudentNumber
		 .if @HaveFindFlags==1 && @ICountStudent <eax
		 		 mov @EnterBuffer1,0dh
		 		 mov @EnterBuffer2,0ah
		 		 lea esi,STU
		 		 mov eax,@ICountStudent
		 		 mov edx,0
		 		 mul SizeStructStudent
		 		 add esi,eax
		 		 invoke lstrcpy,addr BufferToIDED_OUTTEXT,addr HaveFindStudentInformation
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr szID
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr [esi].ID
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @EnterBuffer1
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @EnterBuffer2
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr szName
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr [esi].SNAME
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @EnterBuffer1
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @EnterBuffer2
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr szSexy
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr [esi].SEXY
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @EnterBuffer1
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @EnterBuffer2
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr szBirthYear
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr [esi].BIRTH.YEAR
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @EnterBuffer1
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @EnterBuffer2
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr szBirthMonth
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr [esi].BIRTH.MONTH
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @EnterBuffer1
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @EnterBuffer2
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr szBirthDay
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr [esi].BIRTH.DAY
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @EnterBuffer1
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @EnterBuffer2
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr szEnglish
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr [esi].SCOR.ENGLISH
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @EnterBuffer1
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @EnterBuffer2
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr szCLanguage
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr [esi].SCOR.CLANGUAGE
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @EnterBuffer1
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @EnterBuffer2
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr szMath
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr [esi].SCOR.MATH
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @EnterBuffer1
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @EnterBuffer2
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr szTotal
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr [esi].SCOR.TOTAL
		 		 ;������������������������������������������������������������������������
		 		 ;����ƽ���ɼ�
		 		 ;������������������������������������������������������������������������
		 		 mov ebx,3
		 		 invoke atoi,addr [esi].SCOR.TOTAL
		 		 mov edx,0
		 		 div ebx
		 		 mov @RealAverageScorce,eax
		 		 invoke wsprintf,addr @ASCIIAverageScorce,addr FormatToD,@RealAverageScorce
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @EnterBuffer1
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @EnterBuffer2
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr szSingleAverage
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @ASCIIAverageScorce
		 		 
		 		 invoke SetDlgItemText,hWinMain,IDST_STATE,addr StatesHaveShowFindInformation
		 		 invoke SetDlgItemText,hWinMain,IDED_OUTTEXT,addr BufferToIDED_OUTTEXT
		 		 invoke RtlZeroMemory,addr BufferToIDED_OUTTEXT,sizeof BufferToIDED_OUTTEXT
		 .else
		 		 invoke MessageBox,hWinMain,addr CanNotFindStudent,addr CaptionNotice,MB_OK OR MB_ICONWARNING
		 .endif
		 assume esi:nothing
		 .endif
popad
ret
_NameFind endp
;����������������������������������������������������������������������������������
;����ƽ������
;����������������������������������������������������������������������������������
_CalculateAverage proc
		 local @TotalStudentNumber:dword
		 local @TotalEnglishScorce:dword
		 local @TotalClanguageScorce:dword
		 local @TotalMathScorce:dword
		 local @AverageEnglishScorce:dword
		 local @AverageClanguageScorce:dword
		 local @AverageMathScorce:dword
		 local @EnterBuffer1[1]:dword;����ASCII�ַ�
		 local @EnterBuffer2[1]:dword;�س�ASCII�ַ�
		 local @RealToAscii:dword;��ʵ��ת����ASCII�뻺����
pushad
		 
		 push TotalStudentNumber
		 pop @TotalStudentNumber
		 .if @TotalStudentNumber==0
		 		 invoke MessageBox,hWinMain,addr NoStudentCanCalculate,addr CaptionNotice,MB_OK OR MB_ICONWARNING
		 .else
		 mov @TotalEnglishScorce,0
		 mov @TotalClanguageScorce,0
		 mov @TotalMathScorce,0
		 mov @AverageEnglishScorce,0
		 mov @AverageClanguageScorce,0
		 mov @AverageMathScorce,0
		 dec @TotalStudentNumber
		 .repeat;�������ſε��ܷ���
		 		 lea esi,STU;����ƫ����
		 		 assume esi:ptr STUDENT
		 		 mov eax,@TotalStudentNumber
		 		 mov edx,0
		 		 mul SizeStructStudent
		 		 add esi,eax
		 		 
		 		 invoke atoi,addr [esi].SCOR.ENGLISH
		 		 add @TotalEnglishScorce,eax		 		 
		 		 invoke atoi,addr [esi].SCOR.CLANGUAGE
		 		 add @TotalClanguageScorce,eax
		 		 invoke atoi,addr [esi].SCOR.MATH
		 		 add @TotalMathScorce,eax		 		 
		 		 dec @TotalStudentNumber		 		 
		 .until @TotalStudentNumber ==-1
		 mov edx,0
		 mov eax,@TotalEnglishScorce
		 div TotalStudentNumber		 
		 mov @AverageEnglishScorce,eax
		 mov edx,0
		 mov eax,@TotalClanguageScorce
		 div TotalStudentNumber
		 mov @AverageClanguageScorce,eax
		 mov edx,0
		 mov eax,@TotalMathScorce
		 div TotalStudentNumber
		 mov @AverageMathScorce,eax
		 
		 mov @EnterBuffer1,0dh
		 mov @EnterBuffer2,0ah
		 
		 		 invoke lstrcpy,addr BufferToIDED_OUTTEXT,addr ThreeCourseAverageInformation
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr szAverageEnglish
		 		 mov @RealToAscii,0
		 		 invoke wsprintf,addr @RealToAscii,addr FormatToD,@AverageEnglishScorce
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @RealToAscii
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @EnterBuffer1
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @EnterBuffer2
		 		 mov @RealToAscii,0
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr szAverageCLanguage
		 		 invoke wsprintf,addr @RealToAscii,addr FormatToD,@AverageClanguageScorce
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @RealToAscii
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @EnterBuffer1
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @EnterBuffer2
		 		 mov @RealToAscii,0
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr szAverageMath
		 		 invoke wsprintf,addr @RealToAscii,addr FormatToD,@AverageMathScorce
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @RealToAscii
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @EnterBuffer1
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @EnterBuffer2
		 invoke SetDlgItemText,hWinMain,IDST_STATE,addr StatesHaveCalculateAverage
		 invoke SetDlgItemText,hWinMain,IDED_OUTTEXT,addr BufferToIDED_OUTTEXT
		 invoke RtlZeroMemory,addr BufferToIDED_OUTTEXT,sizeof BufferToIDED_OUTTEXT
		 .endif
popad
ret
_CalculateAverage endp
;����������������������������������������������������������������������������������
;ͳ���Ա����
;����������������������������������������������������������������������������������
_StasticSexy proc
		 local @TotalStudentNumber:dword
		 local @ICountStudent:dword
		 local @SexyManNumber:dword
		 local @SexyWomanNumber:dword
		 local @RealToAscii:dword
		 local @EnterBuffer1[1]:dword;����ASCII�ַ�
		 local @EnterBuffer2[1]:dword;�س�ASCII�ַ�
pushad
		 push TotalStudentNumber
		 pop @TotalStudentNumber
		 .if @TotalStudentNumber==0
		 		 invoke MessageBox,hWinMain,addr NoStudentCanStatistic,addr CaptionNotice,MB_OK OR MB_ICONWARNING
		 .else
		 push TotalStudentNumber
		 pop @ICountStudent
		 dec @ICountStudent
		 mov @SexyManNumber,0
		 mov @SexyWomanNumber,0
		 lea esi,STU
		 assume esi:ptr STUDENT
		 .repeat
		 		 invoke lstrcmp,addr [esi].SEXY,addr SexMan
		 		 .if eax==0
		 		 		 inc @SexyManNumber
		 		 .endif
		 		 invoke lstrcmp,addr [esi].SEXY,addr SexWoman
		 		 .if eax==0
		 		 		 inc @SexyWomanNumber
		 		 .endif
		 		 add esi,SizeStructStudent
		 		 dec @ICountStudent
		 .until @ICountStudent == -1
		 mov @EnterBuffer1,0dh
		 mov @EnterBuffer2,0ah
		 		 invoke lstrcpy,addr BufferToIDED_OUTTEXT,addr ManWomanTotalNumberInformation
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr szTotalMan
		 		 mov @RealToAscii,0
		 		 invoke wsprintf,addr @RealToAscii,addr FormatToD,@SexyManNumber
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @RealToAscii
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @EnterBuffer1
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @EnterBuffer2
		 		 mov @RealToAscii,0
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr szTotalWoman
		 		 invoke wsprintf,addr @RealToAscii,addr FormatToD,@SexyWomanNumber
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @RealToAscii
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @EnterBuffer1
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @EnterBuffer2
		 		 mov @RealToAscii,0
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr szTotalAllSexy
		 		 invoke wsprintf,addr @RealToAscii,addr FormatToD,@TotalStudentNumber
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @RealToAscii
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @EnterBuffer1
		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr @EnterBuffer2
		 invoke SetDlgItemText,hWinMain,IDST_STATE,addr StatesHaveShowSexyStatistic
		 invoke SetDlgItemText,hWinMain,IDED_OUTTEXT,addr BufferToIDED_OUTTEXT
		 invoke RtlZeroMemory,addr BufferToIDED_OUTTEXT,sizeof BufferToIDED_OUTTEXT
		 .endif
popad
ret
_StasticSexy endp


__ChangeFunction proc @address1,@address2
		 local @ChangBuffer[4]:dword
pushad
		 mov edi,@address2
		 mov esi,@address1
		 assume edi:ptr STUDENT
		 assume esi:ptr STUDENT
		 
		 invoke lstrcpy,addr @ChangBuffer,addr [edi].ID;ID���ֽ����Ƚ��ر������16���ֽڣ����Բ�����ѹջ�ķ�ʽ��ֵ
		 invoke RtlZeroMemory,addr [edi].ID,16
		 invoke lstrcpy,addr [edi].ID,addr [esi].ID
	 	 invoke RtlZeroMemory,addr [esi].ID,16
		 invoke lstrcpy,addr [esi].ID,addr @ChangBuffer
		 invoke RtlZeroMemory,addr @ChangBuffer,16
		 invoke lstrcpy,addr @ChangBuffer,addr [edi].SNAME;SNAME���ֽ����Ƚ��ر������4���ֽڣ����Բ�����ѹջ�ķ�ʽ��ֵ
		 invoke RtlZeroMemory,addr [edi].SNAME,16
		 invoke lstrcpy,addr [edi].SNAME,addr [esi].SNAME
		 invoke RtlZeroMemory,addr [esi].SNAME,16
		 invoke lstrcpy,addr [esi].SNAME,addr @ChangBuffer
		 invoke RtlZeroMemory,addr @ChangBuffer,16
		 push [edi].SEXY
		 push [esi].SEXY
		 pop [edi].SEXY
		 pop [esi].SEXY
		 push [edi].BIRTH.YEAR
		 push [esi].BIRTH.YEAR
		 pop [edi].BIRTH.YEAR
		 pop [esi].BIRTH.YEAR
		 push [edi].BIRTH.MONTH
		 push [esi].BIRTH.MONTH
		 pop [edi].BIRTH.MONTH
		 pop [esi].BIRTH.MONTH
		 push [edi].BIRTH.DAY
		 push [esi].BIRTH.DAY
		 pop [edi].BIRTH.DAY
		 pop [esi].BIRTH.DAY
		 push [edi].SCOR.ENGLISH
		 push [esi].SCOR.ENGLISH
		 pop [edi].SCOR.ENGLISH
		 pop [esi].SCOR.ENGLISH
		 push [edi].SCOR.CLANGUAGE
		 push [esi].SCOR.CLANGUAGE
		 pop [edi].SCOR.CLANGUAGE
		 pop [esi].SCOR.CLANGUAGE
		 push [edi].SCOR.MATH
		 push [esi].SCOR.MATH
		 pop [edi].SCOR.MATH
		 pop [esi].SCOR.MATH
		 push [edi].SCOR.TOTAL
		 push [esi].SCOR.TOTAL
		 pop [edi].SCOR.TOTAL
		 pop [esi].SCOR.TOTAL
		 
		 assume edi:nothing
		 assume esi:nothing
popad
ret
__ChangeFunction endp


;����������������������������������������������������������������������������������
;���ֵܷݼ�����
;����������������������������������������������������������������������������������
_TotalSubOrder proc
		 local @Index:dword;��һ��ѭ���������������������ͼ���ƫ����
		 local @NextIndex:dword;���ڵ�һ��ѭ���ĵڶ���ѭ������������
		 local @HaveFindMaxNumber:dword;�Ѿ����ҵ����������������
		 local @ConstTotalStudent:dword;���ӳ���̶��������
		 local @StudentScorce1:dword;
		 local @StudentScorce2:dword;��Ҫ�Ƚϵ�������������
		 local @MaxTotal:dword;ÿ�αȽϼ�¼������������
		 local @ChangeFlags:dword;������־
pushad
		 mov eax,TotalStudentNumber
		 mov @ConstTotalStudent,eax;��ʼ������
		 .if TotalStudentNumber==0||TotalStudentNumber==1
		 		 invoke MessageBox,hWinMain,addr NoStudentCanOrder,addr CaptionNotice,MB_OK OR MB_ICONWARNING
		 .else
		 mov @Index,0
		 lea esi,STU;��һ��ѭ������ʼ��ַ
		 mov edi,esi;�ڶ���ѭ������ʼ��ַ
		 assume edi: ptr STUDENT;������ʼ��ַ����ṹ����أ��Ա�����ܷ�ƫ����
		 assume esi: ptr STUDENT
		 
		 .repeat
		 		 push @Index
		 		 pop @NextIndex
		 		 		 		 
		 		 mov @MaxTotal,0
		 		 mov @ChangeFlags,0
		 		 mov eax,@ConstTotalStudent
		 		 dec eax
		 		 .while @NextIndex < eax
		 		 		 inc @NextIndex

		 		 		 lea esi,STU
		 		 		 lea edi,STU

		 		 		 mov eax,@Index
		 		 		 mov edx,0
		 		 		 mul SizeStructStudent
		 		 		 add esi,eax		 		 		 
		 		 		 invoke atoi,addr [esi].SCOR.TOTAL
		 		 		 mov @StudentScorce1,eax
		 		 		 
		 		 		 ;pushad
		 		 		 ;invoke wsprintf,addr test1,addr formatd,@StudentScorce1
		 		 		 ;invoke MessageBox,NULL,addr test1,NULL,MB_OK
		 		 		 ;popad
		 		 		 
		 		 		 mov eax,@NextIndex
		 		 		 mov edx,0
		 		 		 mul SizeStructStudent
		 		 		 add edi,eax
		 		 		 invoke atoi,addr [edi].SCOR.TOTAL
		 		 		 mov @StudentScorce2,eax
		 		 		 
		 		 		 ;pushad
		 		 		 ;invoke wsprintf,addr test1,addr formatd,@StudentScorce2
		 		 		 ;invoke MessageBox,NULL,addr test1,NULL,MB_OK
		 		 		 ;popad
		 		 		 
		 		 		 .if eax>@StudentScorce1 && eax>@MaxTotal
		 		 		 		 mov @MaxTotal,eax
		 		 		 		 mov eax,@NextIndex
		 		 		 		 mov @HaveFindMaxNumber,eax
		 		 		 		 mov @ChangeFlags,1
		 		 		 		 ;pushad
		 		 		 		 ;invoke wsprintf,addr test1,addr formatd,@HaveFindMaxNumber
		 		 		 		 ;invoke MessageBox,NULL,addr test1,NULL,MB_OK
		 		 		 		 ;popad
		 		 		 .endif
		 		 		 
		 		 		 mov eax,@ConstTotalStudent
		 		 		 dec eax
		 		 .endw
		 		 ;��������������������������������������������������������������������������
		 		 ;������Ϣ
		 		 ;��������������������������������������������������������������������������
		 		 mov eax,@HaveFindMaxNumber
		 		 .if eax!=@Index && @ChangeFlags==1
		 		 		 
		 		 		 lea esi,STU
		 		 		 lea edi,STU
		 		 		 mov eax,@Index
		 		 		 mov edx,0
		 		 		 mul SizeStructStudent
		 		 		 add esi,eax		 		 		 
		 		 		 mov eax,@HaveFindMaxNumber
		 		 		 mov edx,0
		 		 		 mul SizeStructStudent
		 		 		 add edi,eax
		 		 		 
		 		 		 
		 		 		 invoke __ChangeFunction,esi,edi
		 		 .endif
		 		 ;pushad
		 		 ;invoke MessageBox,NULL,addr b,NULL,MB_OK
		 		 ;popad
		 		 inc @Index
		 		 mov eax,@ConstTotalStudent
		 		 dec eax
		 .until @Index == eax
		 invoke SetDlgItemText,hWinMain,IDST_STATE,addr StatesHaveOrderTotalScorceSub
		 .endif
popad
ret
_TotalSubOrder endp


;����������������������������������������������������������������������������������
;��ð�������㷨������������
;����������������������������������������������������������������������������������
_NamePlusOrder proc
		 local @Index:dword;��һ��ѭ����������
		 local @NextIndex:dword;�ڶ���ѭ����������
		 local @ConstStudentTotal:dword;ѧ����������
		 local @ChangeFlags:dword;������־��Ϊ1��ʾ�н���������Ϊ0��ʾû�н���������ֱ���˳�����ѭ��
		 local @ChangeBuffer[4]:dword;��Ϣ����������
pushad
		 push TotalStudentNumber
		 pop @ConstStudentTotal
		 .if TotalStudentNumber==0||TotalStudentNumber==1
		 		 invoke MessageBox,hWinMain,addr NoStudentCanOrder,addr CaptionNotice,MB_OK OR MB_ICONWARNING
		 .else
		 lea esi,STU
		 mov edi,esi
		 assume esi:ptr STUDENT
		 assume edi:ptr STUDENT
		 
		 mov @Index,0;��ʼ����������һ��ѭ��Ϊ0
		 .while @Index<eax
		 		 mov @ChangeFlags,0
		 		 
		 		 mov eax,@ConstStudentTotal
		 		 dec eax
				 mov @NextIndex,eax;ÿ�εڶ���ѭ���ӣ�@ConstStudentTotal-1����ʼ
				 
		 		 .while eax>@Index
		 		 		 lea esi,STU
		 		 		 
		 		 		 mov eax,@NextIndex;����������������ʵ��ַ,��[esi].SNAME
		 		 		 mov edx,0
		 		 		 mul SizeStructStudent
		 		 		 add esi,eax
		 		 		 
		 		 		 mov edi,esi;[edi].SNAME��[esi].SNAME��ǰһ���Ƚ���������Ҫ��ȥһ���ṹ���С��ƫ����
		 		 		 sub edi,SizeStructStudent
		 		 ;pushad
		 		 ;invoke MessageBox,NULL,addr [esi].SNAME,NULL,MB_OK
		 		 ;invoke MessageBox,NULL,addr [edi].SNAME,NULL,MB_OK
		 		 ;popad
		 		 		 
		 		 		 invoke lstrcmp,addr [edi].SNAME,addr [esi].SNAME
		 		 		 .if EAX==1;ǰ������ִ��򽻻���Ϣ��ʹ���ǰ�Ӣ����ĸ���˳����������
		 		 		 		 ;pushad
		 		 		 		 ;invoke MessageBox,NULL,addr a,NULL,MB_OK
		 		 		 		 ;popad
		 		 		 		 
		 		 		 		 invoke __ChangeFunction,esi,edi
		 		 		 		 mov @ChangeFlags,1;���Ľ�����־
		 		 		 .endif
		 		 		 
		 		 		 dec @NextIndex
		 		 		 mov eax,@NextIndex
		 		 .endw
		 		 		 		 
		 		 .if @ChangeFlags==0;�����ǰû����Ϣ�������ʾ�Ѿ�������ˣ�ֹͣ����ѭ��
		 		 		 .break
		 		 .endif
		 		 ;pushad
		 		 ;invoke MessageBox,NULL,addr b,NULL,MB_OK
		 		 ;popad
		 		 inc @Index
		 		 mov eax,@ConstStudentTotal
		 		 dec eax
		 .endw
		 
		 invoke SetDlgItemText,hWinMain,IDST_STATE,addr StatesHaveOrderNamePlus
		 .endif
popad
ret
_NamePlusOrder endp

;����������������������������������������������������������������������������������
;�����򴰿ڹ���
;����������������������������������������������������������������������������������
_ProcDlgMain proc uses ebx esi edi hWnd,wMsg,wParam,lParam
		 mov eax,hWnd
		 mov hWinMain,eax
		 mov eax,wMsg
		 .if eax==WM_CLOSE
		 		 invoke EndDialog,hWnd,NULL
		 .elseif eax==WM_INITDIALOG
		 		 invoke _InitialWork
		 .elseif eax==WM_COMMAND
		 		 mov eax,wParam
		 		 .if ax<=IDED_STUID && ax>=IDED_OUTTEXT
		 		 		 mov eax,TRUE
		 		 		 ret
		 		 .elseif ax==IDOK
		 		 		 invoke _SaveToStructFromUI
		 		 		 invoke SetDlgItemText,hWinMain,IDST_STATE,addr StatesHaveSaveFromUI
		 		 .elseif ax==IDBU_CLEARSTRUCT
		 		 		 mov TotalStudentNumber,0
		 		 		 mov eax,MAX_STUDENTNUMBER
		 		 		 mov edx,0
		 		 		 mul SizeStructStudent
		 		 		 invoke RtlZeroMemory,addr STU,eax
		 		 		 invoke SetDlgItemText,hWinMain,IDED_OUTTEXT,NULL
		 		 		 invoke SetDlgItemText,hWinMain,IDST_STATE,addr StatesHaveClearRAM
		 		 .elseif ax==IDBU_CLEARUI
		 		 		 invoke SetDlgItemText,hWinMain,IDED_STUID,NULL
		 		 		 invoke SetDlgItemText,hWinMain,IDED_NAME,NULL
		 		 		 invoke SetDlgItemText,hWinMain,IDED_SEXY,NULL
		 		 		 invoke SetDlgItemText,hWinMain,IDED_YEAR,NULL
		 		 		 invoke SetDlgItemText,hWinMain,IDED_MONTH,NULL
		 		 		 invoke SetDlgItemText,hWinMain,IDED_DAY,NULL
		 		 		 invoke SetDlgItemText,hWinMain,IDED_ENGLISH,NULL
		 		 		 invoke SetDlgItemText,hWinMain,IDED_MATH,NULL
		 		 		 invoke SetDlgItemText,hWinMain,IDED_CLANGUAGE,NULL
		 		 		 invoke SetDlgItemText,hWinMain,IDED_TOTAL,NULL
		 		 		 invoke SetDlgItemText,hWinMain,IDST_STATE,addr StatesHaveClearUI
		 		 .elseif ax==IDCANCEL
		 		 		 invoke EndDialog,hWnd,NULL;����ESC�����˳�
		 		 .elseif ax==IDBU_READ
		 		 		 invoke _LoadFile;װ���ļ�		 		 		 
		 		 .elseif ax==IDBU_SAVE
		 		 		 .if TotalStudentNumber==0
		 		 		 		 invoke MessageBox,hWinMain,addr NoStudentCanSave,addr CaptionNotice,MB_OK OR MB_ICONWARNING
		 		 		 .else
		 				 		 invoke _SaveToBufferFromStruct
		 				 		 invoke __WriteToFileFromBuffer
		 				 .endif
		 		 .elseif ax==IDBU_NAMEPLUSORDER
		 		 		 invoke _NamePlusOrder
		 		 .elseif ax==IDBU_TOTALPLUSORDER
		 		 		 invoke _TotalSubOrder
		 		 .elseif ax==IDBU_IDFIND
		 		 		 invoke _IDFind
		 		 .elseif ax==IDBU_NAMEFIND
		 		 		invoke _NamePlusOrder
		 		 		 invoke _NameFind
		 		 .elseif ax==IDBU_AVERAGE
		 		 		 invoke _CalculateAverage
		 		 .elseif ax==IDBU_EVERYNUMBER
		 		 		 invoke _StasticSexy
		 		 .elseif ax==IDBU_SHOWINFORMATION
		 		 		 .if TotalStudentNumber==0
		 		 		 invoke MessageBox,hWinMain,addr NoStudentInformation,addr CaptionNotice,MB_OK OR MB_ICONWARNING
		 		 		 .else
		 		 		 invoke _SaveToBufferFromStruct
		 		 		 invoke lstrcpy,addr BufferToIDED_OUTTEXT,addr AllStudentInformation
		 		 		 invoke lstrcat,addr BufferToIDED_OUTTEXT,addr ToTextBuffer
		 		 		 invoke SetDlgItemText,hWinMain,IDED_OUTTEXT,ADDR BufferToIDED_OUTTEXT
		 		 		 invoke SetDlgItemText,hWinMain,IDST_STATE,addr StatesHaveShowAllInformation
		 		 		 .endif
		 		 .endif
		 .else
		 		 mov eax,FALSE
		 		 ret
		 .endif
		 mov eax,TRUE
		 ret
_ProcDlgMain endp
;����������������������������������������������������������������������������������
;������������ʼ��
;����������������������������������������������������������������������������������
START:
		 invoke GetModuleHandle,NULL
		 mov hInstance,eax
		 invoke DialogBoxParam,hInstance,DLG_MAIN,NULL,addr _ProcDlgMain,NULL
		 invoke ExitProcess,NULL
END START