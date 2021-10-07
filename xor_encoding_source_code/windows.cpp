#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_ask.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <shellapi.h>
#include "header.h"
void Btn01_cb(Fl_Widget* w, void* data) {//点击加密按钮后进行加密
	((Fl_Button*)w)->label((char*)data);
	strcpy(filename, filePath->value());
	strcpy(passwd, filePassWd->value());
	if (strcmp(filename, "") == 0) {
		fl_alert("请放入加密文件~");
		return;
	}
	if (strcmp(passwd, "") == 0) {
		fl_alert("密码不能为空~");
		return;
	}
	encode(filename, passwd);
	strcpy(filename, "");//把文件名置空，防止重复操作
	strcpy(passwd, "");//把密码置空，防止重复操作
	fl_alert("加密成功,已放至相同目录下~");
}
void Btn02_cb(Fl_Widget* w, void* data) {//点击解密按钮后进行解密
	((Fl_Button*)w)->label((char*)data);
	strcpy(filename, filePath->value());
	strcpy(passwd, filePassWd->value());
	if (strcmp(filename, "") == 0) {
		fl_alert("请放入解密文件~");
		return;
	}
	if (strcmp(passwd, "") == 0) {
		fl_alert("密码不能为空~");
		return;
	}
	int len = strlen(filename);
	if (filename[len - 1] != 'd' || filename[len - 2] != 't' || filename[len - 3] != 'a' || filename[len - 4] != 'b') {
		/*解密文件应以batd为后缀*/
		fl_alert("请放入已加密文件~");
		return;
	}
	decode(filename, passwd);
	strcpy(filename, "");//把文件名置空，防止重复操作
	strcpy(passwd, "");//把密码置空，防止重复操作
	fl_alert("解密成功,已放至相同目录下~");
}
void setWindows() {
	window = new Fl_Window(300, 256);
	//DragAcceptFiles((HWND )window,true);
	filePath = new Fl_Input(140, 90, 150, 30, "Enter your filePath");
	filePath->align(FL_ALIGN_LEFT);//指定标签在文本框左侧
	filePassWd = new Fl_Input(140, 190, 150, 30, "Enter your password");
	filePassWd->align(FL_ALIGN_LEFT);//指定标签在文本框左侧

	char buff1[] = "&加密";
	Fl_Button* Btn01 = new Fl_Button(45, 50, 65, 25, "&加密");
	Btn01->callback((Fl_Callback*)Btn01_cb, buff1);//按钮执行函数,点击按钮后显示的文字(加密)替换成buff1
	Btn01->when(FL_WHEN_RELEASE_ALWAYS);//点击按钮后释放鼠标就会执行。

	char buff2[] = "&解密";
	Fl_Button* Btn02 = new Fl_Button(205, 50, 65, 25, "&解密");
	Btn02->callback((Fl_Callback*)Btn02_cb, buff2);//按钮执行函数,点击按钮后显示的文字(解密)替换成buff2
	Btn02->when(FL_WHEN_RELEASE_ALWAYS);//点击按钮后释放鼠标就会执行。

	window->end();
	window->show();
	Fl::run();
}
