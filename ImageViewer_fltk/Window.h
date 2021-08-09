#ifndef WINDOW_H
#define WINDOW_H
#define _UNICODE
#define UNICODE

#include <FL/Fl.H>
#include <FL/Fl_Window.h>
#include <FL/Fl_Box.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_Button.H> // For the button class
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_File_Chooser.H>
#include <FL/fl_utf8.h>
#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include "Button.h"
#include <stdexcept>
#include <limits>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <locale.h>
#include <codecvt>
#include <locale>

using namespace std;

class Window: public Fl_Window
{
    public:

        Window(int width, int height, char* title=0);
        Window(int x,int y,int width, int height, char* title=0);
        virtual ~Window();
        //=============================================================================
        char* ToStr(std::string strData)
        {
            char* temp = new char[strData.length() +1];
            strcpy(temp, strData.c_str());
            return temp;
        }
        //=============================================================================
        string lastN(string input)
        {
             return input.substr(input.size() - 4);
        }

        //=============================================================================
        int handle_key(int event, int key);
        int handle(int event);
        static void butn_calb(Fl_Widget *w, void* v)
        {
         Window* win = (Window*)v;
         win->Button_Callback((Button*)w,win);
        }
        //=============================================================================
        void Button_Callback(Button* w,Window* win)
        {
         if(win->origimg!=NULL)
          {
              delete win->origimg;
              win->origimg=NULL;

          }
          if(win->img!=NULL)
          {
              delete win->img;
              win->img=NULL;
          }
         if(Fl::event_button()==FL_MIDDLE_MOUSE)
         {
          files.clear();
           char*val=NULL;
           val=fl_dir_chooser("Pick a directory","");
             if(val==NULL)
             {
                fl_alert("canceled!");
                return ;
             }
             else
             {
                d=val;
                files=get_all_files_names_within_folder(d);
             }
         }//end if
          //static int x=0;
          x+=w->n;
          if(files.size()==0)
          {
              fl_alert("No photos");
              rbut->value(0);
              lbut->value(0);
              return;
          }
          string fname=files[x%files.size()];
          //cout<<fname<<endl;
          char* name= ToStr(fname);
          if(lastN(fname)==".png")
          {
           Fl_PNG_Image  *png=new Fl_PNG_Image(name);
          int pw=png->w();
          int ph=png->h();
          cout<<"pw="<<pw<<" ph="<<ph<<endl;
          float ar=(float)pw/(float)ph;
          if(ph>1000)
          {
              ph=800;
              pw=ar*ph;
          }

          int buth=ph;
          int ww=pw+(2*50);
          pw*=1;
          //if(ar!=0)
           buth=pw/ar;
           //cout<<buth<<endl;
           win->resize(win->Fl_Window::x(),win->Fl_Window::y(),ww,buth);
           //
           win->img = png->copy(pw, buth);
           delete png;
           win->picbox->image(win->img);
           win->redraw();
          }
          else if(lastN(fname)==".jpg")
          {
           Fl_JPEG_Image  *jpg=new Fl_JPEG_Image(name);
          int pw=jpg->w();//
          int ph=jpg->h();//
          float ar=(float)pw/(float)ph;
          //cout<<ar<<endl;
          if(ph>1000)
          {
              ph=800;
              pw=ar*ph;
          }
          int buth=ph;
          int ww=pw+(2*50);
           buth=pw/ar;

           win->resize(win->Fl_Window::x(),win->Fl_Window::y(),ww,buth);
           //
           win->img = jpg->copy(pw, buth);
           delete jpg;
           win->picbox->image(win->img);
           win->redraw();
          }
        win->origimg=win->img;
        }
//=============================================================================
std::string ws2s(const std::wstring& wstr)//c++11
{
    using convert_typeX = std::codecvt_utf8<wchar_t>;
    std::wstring_convert<convert_typeX, wchar_t> converterX;

    return converterX.to_bytes(wstr);
}
//=============================================================================
std::string get_string_from_wsz(std::wstring pwsz )
{

	int size = WideCharToMultiByte( CP_UTF8, 0, pwsz.c_str(), -1, NULL, 0, NULL, NULL );
	char *buffer = new char[ size+1];
	WideCharToMultiByte( CP_UTF8, 0, pwsz.c_str(), -1, buffer, size, NULL, NULL );
	std::string str( buffer);
	delete []buffer;
	return str;
}
//=============================================================================
        vector<string> get_all_files_names_within_folder(string filePath)
        {

          system("chcp 65001  > nul");
        // _setmode(_fileno(stdout), 0x00020000);//print wcout
    std::wstring filePathW;
    filePathW.resize(filePath.size());
    int newSize = MultiByteToWideChar(CP_UTF8, 0, filePath.c_str(), filePath.length(),
                                      const_cast<wchar_t *>(filePathW.c_str()), filePath.length());
    filePathW.resize(newSize);
            vector<string> names;
            std::wstring search_path1 = filePathW + L"/*.PNG*";
            std::wstring search_path2 = filePathW + L"/*.jpg*";

            WIN32_FIND_DATA fd;
            HANDLE hFind = ::FindFirstFile(search_path1.c_str(), &fd);
            HANDLE hFind2 = ::FindFirstFile(search_path2.c_str(), &fd);
            //WIN32 API message box
            //MessageBox(NULL, search_path1.c_str(), L"This program is:", MB_OK );
            if(hFind != INVALID_HANDLE_VALUE||hFind2 != INVALID_HANDLE_VALUE) {
                    //wcout<<search_path1<<endl;
                do {
                    // read all (real) files in current folder
                    // , delete '!' read other 2 default folder . and ..
                    if(! (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) ) {

                        //cout << get_string_from_wsz(filePathW) << '\n';
                        names.push_back(get_string_from_wsz(filePathW + L"/" + std::wstring(fd.cFileName)));

                    }
                }while(::FindNextFile(hFind, &fd)||::FindNextFile(hFind2, &fd));
                ::FindClose(hFind);
                ::FindClose(hFind2);
            }

            return names;
        }
//****************************************************
void draw()
{
 Fl_Window::draw();
  if(origimg!=NULL)
  {

     if(cimg!=NULL)delete cimg;
     cimg = origimg->copy(picbox->w(), picbox->h());
     picbox->image(cimg);
     picbox->redraw();
  }else cout<<"NULL"<<endl;
}
    Fl_Box *picbox;

    Button*rbut;
    Button*lbut;
    Fl_Image* img=NULL;
    Fl_Image* cimg=NULL;
    Fl_Image *origimg=NULL;
    vector<string>files;
     string d;
     int x=0;
};

#endif // WINDOW_H
