.586
.model flat,stdcall
option casemap:none
;》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》
;需要的头文件
;》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》
include 		 windows.inc
include 		 user32.inc
include 		 kernel32.inc
include          Comdlg32.inc
include          msvcrt.inc
includelib   	 user32.lib
includelib 	 kernel32.lib
includelib      Comdlg32.lib;装入通用对话框库
includelib msvcrt.lib;混合编程调用C语言atio所需的库文件
atoi proto C:dword,:vararg;声明一下atoi是一个C语言函数
;itoa proto C:dword,:vararg;声明一下itoa是一个C语言函数
;》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》
;学生结构体的定义
;》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》
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
;》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》
;资源的定义
;》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》
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
;》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》
;必要变量的定义
;》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》
MAX_STUDENTNUMBER EQU 30;定义最大学生人数
.data?
STU STUDENT MAX_STUDENTNUMBER dup(<>);STUDENT结构体数组
hInstance dd ?;模块实例句柄
hWinMain dd ?;主窗口句柄
hIcon dd ?;图标句柄
hFile dd ?;打开的文件句柄
hNewFile dd ?;新建文件句柄
SizeStructStudent dd ?;STUDENT结构体的大小
TotalStudentNumber dd ?;学生总人数统计
STRUCTReadFileName OPENFILENAME <>;
TotalPathFileName db MAX_PATH DUP(?);全路径文件名字
FileContainBuffer db 8000 dup(?);从硬盘打开的文件内容缓冲到的地方
HaveReadByte dd ?;从硬盘打开的文件内容给FileContainBuffer的字节数
ToTextBuffer db 8000 dup(?);转换好的文件准备放到硬盘的缓冲区
NewFileName db MAX_PATH DUP (?)
NewFileHaveWriteByte dd ?
BufferToIDED_OUTTEXT db 8000 dup (?)

test1 db 18 dup(?)
.data
ZeroItem db ' ',0
SexMan db '男',0
SexWoman db '女',0
FileCharacter db '文本文件（*.txt）',0,'*.txt',0,'所有文件（*.*）',0,'*.*',0,0
NoFileHandle db '打开文件句柄失败！',0
ReadToFlieContainBufferFalse db '读取文件到内存缓冲区失败！',0
ReadToFileContainBufferTrue db '读取文件到内存缓冲区成功！',0
CaptionNotice db '小提示：',0
CaptionError db '出错啦！',0
SucceedRead db '文本文件已成功存储到结构体数组！',0
NewFileNameSuffix db 'NEW.txt',0
CanNotFindStudent db '没有找到该学生！',0
HaveFindStudent db '已经找到该学生！',0

NoStudentCanStatistic db '没有学生，无法统计男女人数！',0
NoStudentCanCalculate db '没有学生，无法计算各科平均分数！',0
NoStudentInformation db '没有学生，无法查询信息！',0
NoStudentCanSave db '没有学生，将不会保存到硬盘文件！',0
NoStudentCanOrder db '没有学生或者学生人数小于2，将不会排序！',0


AllStudentInformation db '所有学生的信息：',0dh,0ah,0
HaveFindStudentInformation db '已经查询到的学生信息：',0dh,0ah,0
ThreeCourseAverageInformation db '三门课程的平均成绩：',0dh,0ah,0
ManWomanTotalNumberInformation db '男女人数统计信息：',0dh,0ah,0
szID db                            '学号：                                 ',0
szName db        '姓名：                                 ',0
szSexy db          '性别：                                 ',0
szBirthYear db    '出生年份：                         ',0
szBirthMonth db '出生月份：                         ',0
szBirthDay   db   '出生日期：                         ',0
szEnglish   db     '英语成绩：                         ',0
szCLanguage  db 'C语言成绩：                       ',0
szMath  db          '数学成绩：                         ',0
szTotal db           '总成绩：                             ',0
szSingleAverage db '平均成绩：                           ',0
szAverageEnglish db         '英语平均成绩：                    ',0
szAverageCLanguage db   'C语言平均成绩：                  ',0
szAverageMath db            '数学平均成绩：                    ',0
szTotalMan db    '男生总人数：                       ',0
szTotalWoman db'女生总人数：                       ',0
szTotalAllSexy db '男女总人数：                       ',0
FormatToD db '%u',0

StatesHaveSaveToStruct db '已经保存到结构体！',0
StatesHaveClearRAM db '内存已经清除！',0
StatesHaveClearUI db '文本输入框已经清除！',0
StatesHaveSaveToFile db '已经保存到硬盘文本文件！',0
StatesHaveReadFile db '文件已经读取！你可以继续读取一个文件！',0
StatesHaveOrderNamePlus db '按英文字母表顺序排序已经完成！请显示信息查看！',0
StatesHaveOrderTotalScorceSub db '按总分递减排序已经完成！请显示信息查看！',0
StatesHaveShowFindInformation db '查找的内容已经显示！',0
StatesHaveCalculateAverage db '三门课程的平均分数已经计算完成！并且显示。',0
StatesHaveShowSexyStatistic db '性别信息已经统计完成！并且显示。',0
StatesHaveShowAllInformation db '所有信息已经显示！',0
StatesHaveSaveFromUI db '输入的信息已经保存！',0

formatd db '%d',0
formats db '%s',0
a db 'A',0
b db 'B',0
.code
;》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》
;加载界面时完成一系列初始化工作
;》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》
_InitialWork proc
pushad
		 		 mov TotalStudentNumber,0
		 		 mov SizeStructStudent,sizeof STUDENT
		 		 invoke LoadIcon,hInstance,ICO_MAIN
		 		 mov hIcon,eax
		 		 invoke RtlZeroMemory,addr STU,sizeof STU
		 		 invoke SendMessage,hWinMain,WM_SETICON,ICON_BIG,eax
		 		 invoke SendDlgItemMessage,hWinMain,IDED_SEXY,CB_ADDSTRING,NULL,ADDR SexMan;初始化组合框
		 		 invoke SendDlgItemMessage,hWinMain,IDED_SEXY,CB_ADDSTRING,NULL,ADDR SexWoman
		 		 invoke SendDlgItemMessage,hWinMain,IDED_STUID,EM_LIMITTEXT,8,0;以下分别限定字符串长度
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
;》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》
;把用户输入的UI界面的数据保存到结构体数组
;》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》
_SaveToStructFromUI proc
pushad
		 assume ebx :ptr STUDENT
		 lea ebx,STU
		 mov edx,0
		 mov eax,TotalStudentNumber
		 mul SizeStructStudent
		 add ebx,eax
		 
		 invoke GetDlgItemText,hWinMain,IDED_STUID,addr [ebx].ID,16;获取id号赋值
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
		 ;转换三科分数的输入为可运算数，再把可运算数转换成ASCII字符，并设置到总分窗口
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
;》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》
;把所有结构体中的数据保存到硬盘TEXT文件
;》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》
_SaveToBufferFromStruct proc
		 local @TotalStudentNumber:dword;学生总人数
		 local @SpaceBuffer[2]:byte;空格ASCII字符
		 local @EnterBuffer1[1]:dword;换行ASCII字符
		 local @EnterBuffer2[1]:dword;回车ASCII字符
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
		 		 add ebx,SizeStructStudent;指向下一组结构体
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
;》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》
;把缓冲区中的数据保存到结构体数组
;》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》
__SaveToStructFromFileContainBuffer proc @IStructCount
		 local @HaveReadByte:dword;FileContainBuffer缓冲区的总偏移量
		 local @Flags:dword;作为存取到结构体的标记，=1就存到年，=4就存到数学成绩
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
		 		 ;.if al==NULL;读取到文件最后总人数加1
		 		 ;		 inc TotalStudentNumber
		 		 ;.endif
		 		 .break .if al==NULL
		 		 .if al<= 57 && al >= 48;处理数字
		 		 		 mov [edi],al
		 		 		 inc edi
		 		 		 .while TRUE
		 		 		 		 inc ebx
		 		 		 		 dec @HaveReadByte
		 		 		 		 mov al,[ebx]
		 		 		 		 .break .if al==32||al==13||al==10||al==NULL;当数字后有空格换行符或回车或者文件到了最后时跳出
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
		 		 .elseif al>=65 && al<=90 || al>=97 && al <=122;大写和小写字母的处理
		 		 		 mov [edi],al
		 		 		 inc edi
		 		 		 .while TRUE;送到本地缓冲区做进一步处理
		 		 		 		 inc ebx
		 		 		 		 dec @HaveReadByte
		 		 		 		 mov al,[ebx]
		 		 		 		 .break .if al==32
		 		 		 		 mov [edi],al
		 		 		 		 inc edi
		 		 		 .endw
		 		 		 invoke lstrcpy,addr [esi].SNAME,addr @Buffer
		 		 .elseif al==13||al==10;||al ==32;回车换行空格不处理
		 		 		 add esi,SizeStructStudent;本行处理结束，跳到下一行处理
		 		 		 mov @Flags,0
		 		 		 inc TotalStudentNumber;学生总人数加1
		 		 .elseif al>=0A0h && al <= 0FEh;处理汉字
		 		 		 mov [edi],al
		 		 		 inc edi
		 		 		 .while TRUE;传送到本地缓冲区做进一步处理
		 		 		 		 inc ebx
		 		 		 		 dec @HaveReadByte
		 		 		 		 mov al,[ebx]
		 		 		 		 .break .if al==32
		 		 		 		 mov [edi],al
		 		 		 		 inc edi
		 		 		 .endw
		 		 		 mov eax,@Buffer [2];判断@Buffer的第3字节判断男女
		 		 		 .if eax==0;当字符是男女时分别对应存储到结构体
		 		 		 		 invoke lstrcpy,addr [esi].SEXY,addr @Buffer
		 		 		 .else
		 		 		 		 invoke lstrcpy,addr [esi].SNAME,addr @Buffer
		 		 		 .endif
		 		 .endif
		 		 dec @HaveReadByte
		 		 inc ebx;处理下一个缓冲区字节
		 .endw
		 assume esi:nothing
popad
ret
__SaveToStructFromFileContainBuffer endp
;》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》
;从硬盘加载TEXT文件对应加载到缓冲区并且调用子程序把缓冲区数据保存到结构体数组
;》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》
_LoadFile proc
pushad
		 invoke RtlZeroMemory,addr STRUCTReadFileName,sizeof STRUCTReadFileName;初始化READFILILENAME
		 mov STRUCTReadFileName.lStructSize,sizeof STRUCTReadFileName;指定结构体长度
		 push hWinMain
		 pop STRUCTReadFileName.hWndOwner;指定文件所属主窗口
		 mov STRUCTReadFileName.lpstrFilter,offset FileCharacter;设置文件特征
		 mov STRUCTReadFileName.lpstrFile,offset TotalPathFileName;设置全路径文件缓冲区
		 mov STRUCTReadFileName.nMaxFile,sizeof TotalPathFileName;设置文件的全路径缓冲区长度
		 mov STRUCTReadFileName.Flags,OFN_FILEMUSTEXIST or OFN_PATHMUSTEXIST;设定用户只能打开已经存在的文件
		 invoke GetOpenFileName,offset STRUCTReadFileName;打开文件通用对话框
		 invoke CreateFile,addr TotalPathFileName,GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL
		 .if eax==INVALID_HANDLE_VALUE;判断返回的句柄看有没有获取正确打开文件指针
		 		 invoke MessageBox,hWinMain,addr NoFileHandle,addr CaptionError,MB_OK OR MB_ICONWARNING
		 .else;成功打开
		 		 mov hFile,eax
		 		 invoke ReadFile,hFile,addr FileContainBuffer,sizeof FileContainBuffer,addr HaveReadByte,NULL;读取文件到内存缓冲区
		 		 .if eax==0
		 		 		 invoke MessageBox,hWinMain,addr ReadToFlieContainBufferFalse,addr CaptionError,MB_OK OR MB_ICONWARNING;读取时出现错误
		 		 .else;读取正确的处理
		 		 		 invoke SetDlgItemText,hWinMain,IDST_STATE,addr StatesHaveReadFile
		 		 		 invoke __SaveToStructFromFileContainBuffer,TotalStudentNumber;把缓冲区中的档案保存到数组
		 		 .endif
		 		 invoke CloseHandle,hFile
		 .endif
popad
ret
_LoadFile endp
;》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》
;按学号查找学生信息，eax是返回值，0没找到，非零表示查找的第几个学生，从界面学号出读取要查找的学生的学号
;》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》
_IDFind proc
		 local @WillFindID[4]:dword
		 local @Buffer[4]:dword
		 local @ICountStudent:dword
		 local @TotalStudent:dword
		 local @HaveFindFlags:dword
		 local @RealAverageScorce:dword
		 local @ASCIIAverageScorce:dword
		 local @EnterBuffer1[1]:dword;换行ASCII字符
		 local @EnterBuffer2[1]:dword;回车ASCII字符
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
		 		 
		 		 ;》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》
		 		 ;计算学生个人的平均分数
		 		 ;》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》
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
;》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》
;使用前提是：被查找的数组中的姓名必须按照英文字母表的顺序排列好，否则查找不会成功，按姓名查找：（折半算法查找）
;》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》
_NameFind proc
		 local @WillFindName[4]:dword;将要查找的名字
		 local @Buffer[4]:dword;结构体中的名字缓冲，为对比做准备
		 local @ICountStudent:dword;已经查找到的名字的引导数
		 local @HaveFindFlags:dword;已经查找到的标记，1表示查找到，0表示没有查找到
		 local @EnterBuffer1[1]:dword;换行ASCII字符
		 local @EnterBuffer2[1]:dword;回车ASCII字符
		 local @ASCIIAverageScorce:dword;已经计算完成的ASCII型平均数
		 local @RealAverageScorce:dword;已经计算的实数型平均数
		 local @IHalf:dword;折半查找的中位引导数
		 local @End:dword;折半查找的末位引导数
		 local @Begin:dword;折半查找的首位引导数
pushad
		 invoke GetDlgItemText,hWinMain,IDED_NAME,addr @WillFindName,16;在名字输入框获取需要查找的名字
		 .if TotalStudentNumber==0||@WillFindName==0;如果没有学生则不会查找
		 		 invoke MessageBox,hWinMain,addr NoStudentInformation,addr CaptionNotice,MB_OK OR MB_ICONWARNING;不查找时出现的提示信息
		 .else;有学生则查找
		 assume esi:ptr STUDENT;一些初始化操作
		 lea esi,STU
		 mov @HaveFindFlags,0;设置寻找标记为0，在程序中找到将会设置为1
		 mov @Begin,0
		 push TotalStudentNumber
		 pop @End;初始化操作完成
		 ;》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》
		 ;查找循环，（折半算法）
		 ;》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》
		 .while @Begin<=eax
		 		 lea esi,STU;取零位偏移量
		 		 
		 		 mov eax,@End;求取中位引导数
		 		 sub eax,@Begin
		 		 mov edx,0
		 		 mov ebx,2
		 		 div ebx
		 		 add eax,@Begin
		 		 mov @IHalf,eax;中位数求取完成
		 		 
		 		 mov eax,@IHalf;用中位数做引导数计算名字的偏移量
		 		 mov edx,0
		 		 mul SizeStructStudent
		 		 add esi,eax;计算偏移量完成
		 		 
		 		 invoke lstrcpy,addr @Buffer,addr [esi].SNAME	
		 		 invoke lstrcmp,addr @WillFindName,addr @Buffer;比较中位数引导的名字与差找的名字
		 		 .if eax==0;恰好相等
		 		 		 mov @HaveFindFlags,1
		 		 		 push @IHalf
		 		 		 pop @ICountStudent
		 		 		 .break
		 		 .elseif eax==1;将要查找的名字大于中位数引导的名字
		 		 		 inc @IHalf
		 		 		 push @IHalf
		 		 		 pop @Begin
		 		 .elseif eax==-1;将要查找的名字小于中位数引导的名字
		 		 		 dec @IHalf
		 		 		 push @IHalf
		 		 		 pop @End
		 		 .endif
		 		 
		 		 mov eax,@End;循环控制条件@Begin<=@End
		 .endw
		 ;》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》
		 ;@ICountStudent是已经查找到的学生的引导数，用@HaveFindFlags作已经超找到的标记，显示查找到的信息
		 ;》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》
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
		 		 ;》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》
		 		 ;计算平均成绩
		 		 ;》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》
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
;》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》
;计算平均分数
;》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》
_CalculateAverage proc
		 local @TotalStudentNumber:dword
		 local @TotalEnglishScorce:dword
		 local @TotalClanguageScorce:dword
		 local @TotalMathScorce:dword
		 local @AverageEnglishScorce:dword
		 local @AverageClanguageScorce:dword
		 local @AverageMathScorce:dword
		 local @EnterBuffer1[1]:dword;换行ASCII字符
		 local @EnterBuffer2[1]:dword;回车ASCII字符
		 local @RealToAscii:dword;把实数转换成ASCII码缓冲区
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
		 .repeat;计算三门课的总分数
		 		 lea esi,STU;计算偏移量
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
;》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》
;统计性别个数
;》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》
_StasticSexy proc
		 local @TotalStudentNumber:dword
		 local @ICountStudent:dword
		 local @SexyManNumber:dword
		 local @SexyWomanNumber:dword
		 local @RealToAscii:dword
		 local @EnterBuffer1[1]:dword;换行ASCII字符
		 local @EnterBuffer2[1]:dword;回车ASCII字符
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
		 
		 invoke lstrcpy,addr @ChangBuffer,addr [edi].ID;ID的字节数比较特别可能有16个字节，所以不能用压栈的方式传值
		 invoke RtlZeroMemory,addr [edi].ID,16
		 invoke lstrcpy,addr [edi].ID,addr [esi].ID
	 	 invoke RtlZeroMemory,addr [esi].ID,16
		 invoke lstrcpy,addr [esi].ID,addr @ChangBuffer
		 invoke RtlZeroMemory,addr @ChangBuffer,16
		 invoke lstrcpy,addr @ChangBuffer,addr [edi].SNAME;SNAME的字节数比较特别可能有4个字节，所以不能用压栈的方式传值
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


;》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》
;按总分递减排序
;》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》
_TotalSubOrder proc
		 local @Index:dword;第一层循环的引导数，用来引导和计算偏移量
		 local @NextIndex:dword;基于第一层循环的第二层循环的引导数，
		 local @HaveFindMaxNumber:dword;已经查找到的最大数的引导数
		 local @ConstTotalStudent:dword;本子程序固定不变的量
		 local @StudentScorce1:dword;
		 local @StudentScorce2:dword;需要比较的两个分数缓冲
		 local @MaxTotal:dword;每次比较记录的最大分数缓冲
		 local @ChangeFlags:dword;交换标志
pushad
		 mov eax,TotalStudentNumber
		 mov @ConstTotalStudent,eax;初始化常量
		 .if TotalStudentNumber==0||TotalStudentNumber==1
		 		 invoke MessageBox,hWinMain,addr NoStudentCanOrder,addr CaptionNotice,MB_OK OR MB_ICONWARNING
		 .else
		 mov @Index,0
		 lea esi,STU;第一层循环的起始地址
		 mov edi,esi;第二层循环的起始地址
		 assume edi: ptr STUDENT;设置起始地址的与结构体相关，以便计算总分偏移量
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
		 		 ;》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》
		 		 ;交换信息
		 		 ;》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》
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


;》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》
;用冒泡排序算法递增排序姓名
;》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》
_NamePlusOrder proc
		 local @Index:dword;第一层循环的引导数
		 local @NextIndex:dword;第二层循环的引导数
		 local @ConstStudentTotal:dword;学生总量常量
		 local @ChangeFlags:dword;交换标志，为1表示有交换发生，为0表示没有交换发生，直接退出所有循环
		 local @ChangeBuffer[4]:dword;信息交换缓冲区
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
		 
		 mov @Index,0;初始化引导数第一层循环为0
		 .while @Index<eax
		 		 mov @ChangeFlags,0
		 		 
		 		 mov eax,@ConstStudentTotal
		 		 dec eax
				 mov @NextIndex,eax;每次第二层循环从（@ConstStudentTotal-1）开始
				 
		 		 .while eax>@Index
		 		 		 lea esi,STU
		 		 		 
		 		 		 mov eax,@NextIndex;根据引导数计算真实地址,即[esi].SNAME
		 		 		 mov edx,0
		 		 		 mul SizeStructStudent
		 		 		 add esi,eax
		 		 		 
		 		 		 mov edi,esi;[edi].SNAME是[esi].SNAME的前一个比较量，所以要减去一个结构体大小的偏移量
		 		 		 sub edi,SizeStructStudent
		 		 ;pushad
		 		 ;invoke MessageBox,NULL,addr [esi].SNAME,NULL,MB_OK
		 		 ;invoke MessageBox,NULL,addr [edi].SNAME,NULL,MB_OK
		 		 ;popad
		 		 		 
		 		 		 invoke lstrcmp,addr [edi].SNAME,addr [esi].SNAME
		 		 		 .if EAX==1;前面的名字大则交换信息，使他们按英文字母表的顺序向下排列
		 		 		 		 ;pushad
		 		 		 		 ;invoke MessageBox,NULL,addr a,NULL,MB_OK
		 		 		 		 ;popad
		 		 		 		 
		 		 		 		 invoke __ChangeFunction,esi,edi
		 		 		 		 mov @ChangeFlags,1;更改交换标志
		 		 		 .endif
		 		 		 
		 		 		 dec @NextIndex
		 		 		 mov eax,@NextIndex
		 		 .endw
		 		 		 		 
		 		 .if @ChangeFlags==0;如果提前没有信息交换则表示已经排序好了，停止所有循环
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

;》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》
;主程序窗口过程
;》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》
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
		 		 		 invoke EndDialog,hWnd,NULL;按下ESC将会退出
		 		 .elseif ax==IDBU_READ
		 		 		 invoke _LoadFile;装载文件		 		 		 
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
;》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》
;主程序引导起始点
;》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》》
START:
		 invoke GetModuleHandle,NULL
		 mov hInstance,eax
		 invoke DialogBoxParam,hInstance,DLG_MAIN,NULL,addr _ProcDlgMain,NULL
		 invoke ExitProcess,NULL
END START